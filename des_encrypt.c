#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/des.h>
#define KEY_SIZE 8
#define MAXN 1000

int main()
{
    unsigned char key[KEY_SIZE] = "banichka";
    unsigned char input[MAXN];
    scanf("%s", input);

    unsigned int lenght = strlen(input);
    int padded_length = ((lenght+7)/8)*8;
    unsigned char padded_input[padded_length];
    unsigned char output[padded_length];

    memcpy (padded_input, input, lenght);
    int difference_length = padded_length - lenght;
    memset (padded_input + lenght, difference_length, difference_length );

    DES_key_schedule key_schedule;
    DES_set_key ((DES_cblock*)key, &key_schedule);

    for(int i = 0; i<lenght; i+=8)
    {
        DES_ecb_encrypt ((DES_cblock*)(padded_input +1),
            (DES_cblock*) (output + i ),&key_schedule, DES_ENCRYPT);
        
    }
for(int i=0; i<lenght; i++)
{
    printf("%02x", output[i]);
}
return EXIT_SUCCESS;
}