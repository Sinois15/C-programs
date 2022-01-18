#include <stdio.h>

int main()
{
    int binary, rem, counter, total = 0;
    
    printf("Enter binary: ");
    scanf("%d", &binary);
    
    counter = 1;
    while(binary != 0)
    {
        rem = binary % 10;
        binary /= 10;
        total += rem * counter;
        printf("%d\n", total);
        counter *= 2;
    }
    
    printf("Decimal value: %d\n", total);

    return 0;
}
