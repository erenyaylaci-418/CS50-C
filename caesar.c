#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <cs50.h>

#define Büyük_Harf  97 
#define Kücük_Harf  65 
#define Mod_deger  26 

int main(int argc , string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./caesar k");
        return 1;
    }
    int key = atoi(argv[1]) % Mod_deger ;
    string text = get_string("plaintext:");
    printf("ciphertext: ");
    
    for (int i = 0; i < strlen(text); i++)
    {
        if (!isalpha(text[i]))
        {
            printf("%c", text[i]);
            continue;
        }
        int hassasiyet = isupper(text[i]) ? Büyük_Harf : Kücük_Harf ;

        int ceviri = text[i] - hassasiyet ;
        int sonuc = (ceviri + key) % Mod_deger ;

        printf("%c", sonuc + hassasiyet);


    }

    printf("\n");
    return 0;

}

