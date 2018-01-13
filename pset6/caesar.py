import sys

if len(sys.argv)==2:
    key = int(sys.argv[1])
    if key>=0:
        a = input("plain text: ")
        n = len(a)
        b = ""
        for i in range(n):
            if a[i].isalpha:
                if ord(a[i])<91:
                    b += chr((ord(a[i])-65+key)%26+65)
                else:
                    b += chr((ord(a[i])-97+key)%26+97)
        print("ciphertext: " + b)
        exit(0)