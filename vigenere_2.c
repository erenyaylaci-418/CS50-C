#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <cs50.h>

#define Büyük_Harf  97 
#define Kücük_Harf  65 
#define Mod_deger  26 


bool dogrulama(string k)
{
    for (int i = 0; i < strlen(k); i++)
    {
        if (!isalpha(k[i]))
        {
            return false;
        }
    }

    return true;
}

int main(int argc, string args[])
{
    if (argc != 2 || !dogrulama(args[1]))
    {
        printf("Usage: ./vigenere k\n");
        return 1;
    }

    string key = args[1];
    string text = get_string("plaintext: ");
    int key_len = strlen(key);

    printf("ciphertext: ");

    for (int i = 0, j = 0, n = strlen(text); i < n; i++)
    {
         if (!isalpha(text[i]))
        {
            printf("%c", plaintext[i]);
            continue;
        }
        
        int hassasiyet = isupper(text[i]) ? Büyük_Harf : Kücük_Harf ;
        
        int ceviri = text[i] - hassasiyet ;
        int keyj = toupper(key[j % key_len]) - Kücük_Harf ;
        int sonuc = (ceviri + keyj) % Büyük_Harf ;
        j++;

        printf("%c", sonuc + hassasiyet);
    }
    printf("\n");
    return 0;

}