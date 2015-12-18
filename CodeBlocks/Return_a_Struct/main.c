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

void modifyToStructMatrix(StructMatrix* mx);
void printMemsStructMatrix(StructMatrix* sMx);
void allocMemToStructMatrix(StructMatrix** mMx);

int main()
{
    printf("hello World!\n\n");


    StructMatrix* ptrM = NULL;
   // StructMatrix simpleM;
    //ptrM = &simpleM;

    // allocMemory inside a function
    allocMemToStructMatrix( &ptrM );

    // init vars
    ptrM->m = 5;
    ptrM->n = 2;
    strcpy(ptrM->sArray, "TO DO\n");

    // print them
    printMemsStructMatrix(ptrM);

    // change values
    modifyToStructMatrix(ptrM);

    // print them again
    printMemsStructMatrix(ptrM);

    return 0;
}

void modifyToStructMatrix(StructMatrix* mx)
{
    (mx)->m++;
    (mx)->n += 50;
    strcpy((mx)->sArray, "The string has just been modified");
}

void printMemsStructMatrix(StructMatrix* sMx)
{
    printf("m = %d\n", sMx->m);
    printf("n = %d\n", sMx->n);
    printf("sArray = %s\n", sMx->sArray);
}
void allocMemToStructMatrix(StructMatrix** mMx)
{
    StructMatrix* bMx = (StructMatrix*)malloc(sizeof(StructMatrix));
    *mMx = bMx;
}

/* Output:

hello World!

m = 5
n = 2
sArray = TO DO

m = 6
n = 52
sArray = The string has just been modified

 */
