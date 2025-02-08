#include "header.h"

extern int modified_input[];
extern int nBits;
extern int dec;

void signMethod(){
    int arr[100];                            //Create a temp array to modify
    arrayTempCopy(arr);                      //Copy the modified array content into our temp array

    arr[nBits - 1] = 1;                      //Negate the array by Sign-method by flipping the last bit arr(nBit) into 1

    printf("\nTo negate the number ");       //Print To Negate the number 0bxxxxxx (The entered binary number) by Sign-Method :
    for(int i = nBits - 1; i >= 0; i--){
        printf("%d", modified_input[i]);
    }
    printf(" by Sign-Method : \n");

    for(int i = nBits - 1; i >= 0; i--){     //Print the original binary number with its decimal representation
        printf("%d", modified_input[i]);
    }
    printf("  ==>   %d\n", dec);

    for(int i = nBits - 1; i >= 0; i--){     //Print the negated binary number with the negative decimal representation in Sign-Method
        printf("%d", arr[i]);
    }
    printf("  ==>  -%d\n", dec);
}
