// Author:	Eduard.Soltuzu
// Date:	18.12.2015

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct myStruct
{
    int n, m;
    char sArray[60];
}StructMatrix;

void modifyToStructMatrix(StructMatrix** mx);
void printMemsStructMatrix(StructMatrix* sMx);

int main()
{
    printf("hello World!\n\n");

    StructMatrix* ptrM;
    StructMatrix simpleM;

    ptrM = &simpleM;
    // init vars
    simpleM.m=0;
    simpleM.n=0;
    strcpy(simpleM.sArray, "TO DO\n");

    // print them
    printMemsStructMatrix(&simpleM);

    // change values
    modifyToStructMatrix(&ptrM);

    // print them again
    printMemsStructMatrix(ptrM);

    return 0;
}

void modifyToStructMatrix(StructMatrix** mx)
{
    (*mx)->m++;
    (*mx)->n = 50;
    strcpy((*mx)->sArray, "The string has just been modified");
}

void printMemsStructMatrix(StructMatrix* sMx)
{
    printf("m = %d\n", sMx->m);
    printf("n = %d\n", sMx->n);
    printf("sArray = %s\n", sMx->sArray);
}
