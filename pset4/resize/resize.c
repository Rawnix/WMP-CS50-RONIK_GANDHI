/**
 * Copies a BMP piece by piece, just because.
 */

#include <stdio.h>
#include <stdlib.h>

#include "bmp.h"

int main(int argc, char *argv[])
{
    // ensure proper usage
    if (argc != 4)
    {
        fprintf(stderr, "Usage: ./copy resize_factor original_pic resized_pic\n");
        return 1;
    }

    // remember filenames
    int n = atoi(argv[1]);
    char *infile = argv[2];
    char *outfile = argv[3];

    // open input file
    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 2;
    }

    // check n
    if(n<=0 || n>100)
    {
        fprintf(stderr, "resize_factor should be a positive integer less than or equal to 100.\n");
        return 5;
    }

    // open output file
    FILE *outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", outfile);
        return 3;
    }

    // read infile's BITMAPFILEHEADER
    BITMAPFILEHEADER bf;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);

    // read infile's BITMAPINFOHEADER
    BITMAPINFOHEADER bi;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);

    // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 ||
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 4;
    }

    // determine padding for scanlines of the input pic
    int padding = (int)((4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4);

    // setting the new header info for new resized bmp file
    bi.biWidth *= n;
    bi.biHeight *= n;

    // determine padding for scanlines of the output pic
    int outpadding = (int)((4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4);

    // I don't understand this formula got it from GDG WMP student
    // bi.biSizeImage = ((((bi.biWidth * bi.biBitCount) + 31) & ~31) / 8) * abs(bi.biHeight);

    bi.biSizeImage = abs(bi.biHeight) * bi.biWidth * sizeof(RGBTRIPLE) + abs(bi.biHeight) * outpadding;

    bf.bfSize = bi.biSizeImage + 54;


    // write outfile's BITMAPFILEHEADER
    fwrite(&bf, sizeof(BITMAPFILEHEADER), 1, outptr);

    // write outfile's BITMAPINFOHEADER
    fwrite(&bi, sizeof(BITMAPINFOHEADER), 1, outptr);



    // // creating an array in which each row of pic will be saved
    // RGBTRIPLE row[bi.biWidth + 3];
    // int l=0;

    // iterate over infile's scanlines
    for (int i = 0, biHeight = abs(bi.biHeight/n); i < biHeight; i++)
    {
        // printing each scanline n times
        for(int l=0; l<n; l++)
        {

            if(l!=0) fseek(inptr, -(bi.biWidth/n*3 + padding), SEEK_CUR);

            // iterate over pixels in scanline
            // this loop write the whole image row of output file without padding
            for (int j = 0, biWidth = abs(bi.biWidth/n); j < biWidth; j++)
            {
                // temporary storage
                RGBTRIPLE triple;

                // read RGB triple from infile
                fread(&triple, sizeof(RGBTRIPLE), 1, inptr);

                // writing each pixel n times
                for(int k=0; k<n; k++)
                {
                    fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
                }

                // for(int k=0; k<n; k++)
                // {
                //     // write RGB triple to outfile
                //     fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
                // }
            }

            // skip the input padding of the row
            fseek(inptr, padding, SEEK_CUR);

            // then add it back (to demonstrate how)
            for (int k = 0; k < outpadding; k++)
            {
                fputc(0x00, outptr);
            }

        }

        // // writing the row in new bmp file n times
        // for(int j=0; j<n; j++)
        // {

        //     fwrite(row, sizeof(RGBTRIPLE), bi.biWidth, outptr);

        //     // skip over padding, if any
        //     fseek(inptr, padding, SEEK_CUR);

        //     // then add it back (to demonstrate how)
        //     for (int k = 0; k < outpadding; k++)
        //     {
        //         fputc(0x00, outptr);
        //     }
        // }

    }

    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    // success
    return 0;
}
