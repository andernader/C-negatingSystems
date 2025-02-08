#include "header.h"

extern int modified_input[];
extern int nBits;
extern int dec;

void twosCompliment(){
    int arr[100];                           //Create a temp array to modify and store the content of out int modified_input array inside it
    arrayTempCopy(arr);

    for(int i = nBits - 1; i >= 0; i--){    //Flip every bit or item in our array from 0 to 1 and from 1 to 0
        if(arr[i] == 1)                     //here we have noting the whole number which is equal to not(x) = -(x+1);
            arr[i] = 0;                     //so we are going to add 1 in the next segment of our code.
        else if(arr[i] == 0)
            arr[i] = 1;
    }

    int c = 1;                              //Add with 1 where variable C represent adding with 1 and carry bit at the same time
    for(int i = 0; i <= nBits; i++){
        if(arr[i] == 1 && c == 1){          //1 + 1 = 0 & carry = 1
            arr[i] = 0;
            c = 1;
        }
        else if(arr[i] == 0 && c == 1){     //0 + 1 = 1 & carry = 0 & adding operation is finished
            arr[i] = 1;
            c = 0;
            break;
        }
    }

    printf("\nTo negate the number ");      //Print To negate the number 0bxxxxxx (the entered binary number) using 2's compliment
    for(int i = nBits - 1; i >= 0; i--)
        printf("%d", modified_input[i]);
    printf(" using 2's Compliment : \n");

    for(int i = nBits - 1; i >= 0; i--)     //The original binary number with decimal representation
        printf("%d", modified_input[i]);
    printf("  ==>   %d\n", dec);

    for(int i = nBits - 1; i >= 0; i--){    //The negated binary number with decimal representation
        printf("%d", arr[i]);
    }
    if(dec == 0)
        printf("  ==>   %d\n", -dec);       //if the number is 0 add one space because there is no -0 in 2's compliment
    else
        printf("  ==>  %d\n", -dec);
}
