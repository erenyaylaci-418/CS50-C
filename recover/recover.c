#include <stdio.h>
#include <stdlib.h>

#define SIRA 512 

int main(int argc, char *argv[])
{
    if (argc != 1 )
    {
        printf("Usage: ./recover image");
        return 1;
    }
    else 
    {
        FILE *file = fopen(argv[1], "r");
        
        if (file == NULL)
        {
            printf("Could not open card.raw.\n");
            return 2;
        }
        unsigned char sira[SIRA_BOYUT];

        FILE* resim = NULL;

        int jpg_bulucu = 0; //false
        int filecounter = 0;

        while(fread(sira,SIRA_BOYUT,1,file) == 1)
        {
            if(sira[0] == 0xff && sira[1] == 0xd8 && sira[2] == 0xff && (sira[3] & 0xe0) == 0xe0)
            {
                if(jpg_bulucu == 1)
                {
                    fclose(resim);
                }
                else
                {
                    jpg_bulucu = 1;
                }
                char filename;
                sprintf(filename, "%03d.jpg", filecounter);
                resim = fopen(filename, "a");
                filecounter++;
            }
            if(jpg_bulucu == 1)
            {
                fwrite(&sira ,SIRA_BOYUT,1,resim);
            }

        }
        fclose(file);
        fclose(resim);




    }
    
}
