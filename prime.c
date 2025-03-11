#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main()
{
    int x;
    scanf("%d", &x);
    
    bool is_prime = true;
    for(int i = 2; i <= x / 2; i++)
    {
        if(x % i == 0)
        {
            is_prime = false;
        }
    }
    if(is_prime)
    {
        printf ("the number is prime");
    }
    else{
        printf ("the number is not prime");
    }

    return EXIT_SUCCESS;

}

