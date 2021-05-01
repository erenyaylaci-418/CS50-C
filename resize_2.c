// Copies a BMP file

#include <stdio.h>
#include <stdlib.h>

#include "bmp.h"

int main(int argc, char *argv[])
{
    // ensure proper usage
    if (argc != 4)
    {
        fprintf(stderr, "Usage: resize n infile outfile\n");//ilk revize argv de
        return 1;
    }

    // remember filenames
    int boyut = atoi(argv[1]);//ikinci revize
    char *infile = argv[2];
    char *outfile = argv[3];

    // giriş dosyası açılıyor
    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 2;
    }

    // çıkış dosyası açılıyor
    FILE *outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", outfile);
        return 3;
    }

    //giriş bitmap dosyası okunuyor
    BITMAPFILEHEADER bf;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);

    // giriş bitmap bilgilari okunuyor
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
    int eskisatir = bi.biWidth;
    int eskiyükseklik = bi.biHeight;
    int yenisatir = bi.biWidth * boyut;
    int yeniyükseklik =bi.biHeight * boyut
   

    //Dolgu(padding) boyutu hesaplanıyor
    int inpadding = (4 - (eskisatir * sizeof(RGBTRIPLE)) % 4) % 4;
    int outpadding = (4 - (yenisatir * sizeof(RGBTRIPLE)) % 4) % 4;

    bi.biHeight = yeniyükseklik;
    bi.biWidth = yenisatir;
    bi.biSizeImage = ((sizeof(RGBTRIPLE) * yenisatir) + outPadding) * abs(yenisatir);//abs mutlak değer döndürür.
    bf.bfSize = bi.biSizeImage + sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER);

    // çıkış bitmap dosyası yazılıyor
    fwrite(&bf, sizeof(BITMAPFILEHEADER), 1, outptr);

    // çıkış bitmap bilgileri yazdırılıyor
    fwrite(&bi, sizeof(BITMAPINFOHEADER), 1, outptr);
    RGBTRIPLE tarama[yenisatir * sizeof(RGBTRIPLE)] //Yer ihtiyaca göre açılır
    // iterate over infile's scanlines
    for (int i = 0, biHeight = abs(eskiyükseklik); i < biHeight; i++)
    {
        // iterate over pixels in scanline
        for (int j = 0; j < eskisatir; j++)
        {
            // temporary storage
            RGBTRIPLE triple;

            // read RGB triple from infile
            fread(&triple, sizeof(RGBTRIPLE), 1, inptr);

            for(int r = 0; r < boyut;r++){//boyut kadar yazdır dedik
               tarama[(j * boyut) + k] = triple;
            }
            
        }

        // skip over padding, if any
        fseek(inptr, inpadding, SEEK_CUR);

       for (int j = 0; j < boyut; j++)
       {
           fwrite(tarama ,sizeof(RGBTRIPLE), yenisatir, outptr)
           
           for (int k = 0; k < outpadding; k++ )
           {
               fputc(0x00, outptr);
           }
       }
    }

    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    // success
    return 0;
}
