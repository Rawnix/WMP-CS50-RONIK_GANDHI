#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>

typedef uint8_t byte;

#define B 512

int main(int argc, char** argv)
{
    if(argc!=2)
    {
        fprintf(stderr, "Usage: ./recovery rawfile.raw");
        return 1;
    }

    char* raw = argv[1];
    // opening input file stream
    FILE* instream = fopen(raw, "r");

    // checking if the stream is opened
    if(instream == NULL)
    {
        fprintf(stderr, "Unable to open file %s.\n", raw);
        return 2;
    }

    byte header[4];
    byte block[B];
    int picsRecovered = 0;
    char jpegName[8];
    jpegName[7] = '\0';

    while(picsRecovered<50)
    {

        // renaming jpg name, if change is required
        sprintf(jpegName, "%03d.jpg", picsRecovered);

        // read the first 4 bytes
        int temp = fread(header, 4, 1, instream);
        if(feof(instream) || temp!=1)
        {
            break;
        }

        // checking for jpeg signature      240 and 224 are the decimal representations of 1111 0000 and 1110 0000
        if(header[0]!=0xff || header[1]!=0xd8 || header[2]!=0xff || (header[3] & 240)!=224)
        {
            // this is not the start of jpeg so skip the current B and repeat
            fseek(instream, 508, SEEK_CUR);
        }
        else
        {
            // open stream for a new jpeg file
            FILE* outs = fopen(jpegName, "w");

            // checking for the end of current file
            do
            {
                // go back to the start of current B in the raw file
                fseek(instream, -4, SEEK_CUR);

                // read a whole B from raw and store it in a variable
                int blocksRead = fread(block, B, 1, instream);

                // check if a block is succesfully read
                if(blocksRead == 1)
                {

                    // write whole B from block variable into output jpeg
                    fwrite(block, B, 1, outs);

                }
                else if(feof(instream))
                {
                    break;
                }

                // read the first 4 bytes of the next B from raw and store them in header
                fread(header, 4, 1, instream);

            }while(header[0]!=0xff || header[1]!=0xd8 || header[2]!=0xff || (header[3] & 240)!=224);

            // close the stream
            fclose(outs);

            // increase the number of pics recovered
            picsRecovered++;

            // go back to the start of current B in the raw file
            fseek(instream, -4, SEEK_CUR);
        }

    }

    // close the input stream
    fclose(instream);

    return 0;
}