/*
Following C/C++ code is about takes a decimal input and converts into octal, hexadecima, and binary representation.
*/

#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <iostream>
using namespace std;

int PromptUserInput(const char *display)
{
    int result;
    printf(display);
    scanf("%d", &result);
    return result;
}

char *decimalToOctal(int inPut)
{
    char *result;
    result = (char *)malloc(sizeof(char) * (int)(log10(inPut) * (log10(8) + 1)));
    sprintf(result, "%o", inPut);
    return result;
}

char *decimalToHex(int inPut)
{
    char *result;
    result = (char *)malloc(sizeof(char) * (int)(log10(inPut) / log10(16) + 1));
    sprintf(result, "%x", inPut);
    return result;
}

int CharToInt(int inPut)
{
    if (inPut == 0)
        return 0;
    else
        return (inPut % 2 + 10 * CharToInt(inPut / 2));
}

char *decimalToBinary(int inPut)
{
    char *result;
    int num1 = CharToInt(inPut);
    result = (char *)malloc(sizeof(char) * (int)(log10(num1) / log10(2) + 1));
    sprintf(result, "%d", num1);
    return result;
}

void PrintResult(int inPut)
{
    char *Octal;
    char *Hex;
    char *Binary;

    Octal = decimalToOctal(inPut);
    Hex = decimalToHex(inPut);
    Binary = decimalToBinary(inPut);

    printf("The decimal %d in Octal is: %s \n", inPut, Octal);
    printf("The decimal %d in Hex is: %s \n", inPut, Hex);
    printf("The decimal %d in Binary is: %s \n", inPut, Binary);

    free(Octal);
    free(Hex);
    free(Binary);
}

int main(int argc, char *argv[])
{

    int inPut;

    if (argc < 2)
    {
        inPut = PromptUserInput("Please input value: ");
    }
    else
    {
        inPut = (int)strtol(argv[1], NULL, 10);
    }

    PrintResult(inPut);

    return 0;
}