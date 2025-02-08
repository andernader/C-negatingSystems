#include "header.h"

extern int modified_input[];
extern int nBits;
extern int dec;

void onesCompliment(){
    int arr[100];                           //Create a temp array to modify and store the content of out int modified_input array inside it
    arrayTempCopy(arr);

    for(int i = nBits - 1; i >= 0; i--){    //Flip every bit or item in our array from 0 to 1 and from 1 to 0
        if(arr[i] == 1)
            arr[i] = 0;
        else if(arr[i] == 0)
            arr[i] = 1;
    }

    printf("\nTo negate the number ");      //Print the transformation
    for(int i = nBits - 1; i >= 0; i--)
        printf("%d", modified_input[i]);
    printf(" by 1's Compliment : \n");

    for(int i = nBits - 1; i >= 0; i--)
        printf("%d", modified_input[i]);
    printf("  ==>   %d\n", dec);

    for(int i = nBits - 1; i >= 0; i--)
        printf("%d", arr[i]);
    printf("  ==>  -%d\n", dec);
}
