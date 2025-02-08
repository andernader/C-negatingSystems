#include "header.h"

extern char user_input[];
extern int modified_input[];
extern int nDigits;
extern int nBits;

void arrayCopyMain(){
    for(int i = 0; i < nBits; i++){                              //Copy the value of string array into int array
        if(i < nDigits)                                          //with storing the intArray[firstBit] = strArray[lastBit] and so on
            modified_input[i] = user_input[nDigits-1-i] - '0';   //with converting the '1' or '0' string into int 1 or 0
        else
            modified_input[i] = 0;
    }
    modified_input[nBits] = 9;                                   //Make the last array item equal to 9 to mark the end of the int binary array
}

int binToDec(int myArray[]){
    int result = 0;
    for(int i = 0; myArray[i] != 9; i++){                        //Add the int array items until reaching the end of int binary array with item 9
        result = result + (myArray[i] * pow(2, i));
    }
    return result;
}

void arrayTempCopy(int arr[]){                                   //Copy our modified array into temp array so we can adjust it for our negation methods
    for(int i = 0; modified_input[i] != 9; i++){
        arr[i] = modified_input[i];
    }
    arr[nBits] = modified_input[nBits];
}
