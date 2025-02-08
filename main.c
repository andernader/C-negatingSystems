#include "header.h"

char user_input[100];
int modified_input[100];
int nBits;
int nDigits;
int dec;

int main()
{
    userInput:
    printf("Enter the number in Binary format : ");
    scanf("%s%*[^\n]", user_input);                         //Input stored in string array which will be converted into int array

    for(int i = 0; user_input[i] != '\0'; i++){             //Check whether the input is binary or not!
        if(user_input[i] != '1' && user_input[i] != '0'){
            printf("Enter a valid binary number!\n");
            goto userInput;
        }
    }

    nDigits = strlen(user_input);                           //Number of digits = the length of the string array

    noOfBits:
    printf("Enter bits number : ");
    scanf("%d%*[^\n]", &nBits);                             //Number of bits 2^nBits

    if(nBits <= nDigits){                                   //Check bits number must not be less or equal to digits number!
        printf("The bits number must be bigger than the digits number!\n");
        goto noOfBits;
    }

    arrayCopyMain();                                        //Copy the string array into int array
    dec = binToDec(modified_input);                         //Store the the decimal forum of our binary number in dec variable

    printf("\nThe binary number you entered is : ");
    for(int i = nBits-1; i >= 0; i--){
        printf("%d", modified_input[i]);
    }
    printf("\nThe decimal format is : %d\n", dec);
    printf("The digits number of the binary number you entered : %d\n", nDigits);
    printf("The bits number is : %d\n", nBits);

    printf("\nWhich Negation method you wanna apply?\n 1. Sign-Method\n 2. 1's Compliment\n 3. 2's Compliment\nFunction no : ");
    int functionNumber;
    scanf("%d%*[^\n]", &functionNumber);

    switch(functionNumber){
        case 1 : signMethod(); break;
        case 2 : onesCompliment(); break;
        case 3 : twosCompliment(); break;
    }

    printf("\n%s - %s", "Ammar Mullaoglu", __DATE__);
}
