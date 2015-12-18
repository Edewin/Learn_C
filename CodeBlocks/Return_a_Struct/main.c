// Author:	Eduard.Soltuzu
// Date:	18.12.2015

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct myStruct
{
    int n, m;
    char sArray[60];
    int matrix[4][3];
}StructMatrix;

void modifyStructMatrix(StructMatrix* mx);
void printMemsStructMatrix(StructMatrix* sMx);
void allocMemToStructMatrix(StructMatrix** mMx);

int main()
{
    printf("hello World!\n\n");


    StructMatrix* ptrM = NULL;

    // allocMemory inside a function
    allocMemToStructMatrix( &ptrM );

    // init vars
    ptrM->m = 5;
    ptrM->n = 2;
    strcpy(ptrM->sArray, "TO DO\n");

    int i, j;
    for(i = 0; i<4;i++)
    {
    	for(j = 0; j<3;j++)
    	{
    		ptrM->matrix[i][j] = 0;
    	}
    }

    // print them
    printMemsStructMatrix(ptrM);

    // change values
    modifyStructMatrix(ptrM);

    // print them again
    printMemsStructMatrix(ptrM);

    return 0;
}

void modifyStructMatrix(StructMatrix* mx)
{
    (mx)->m++;
    (mx)->n += 50;
    int buf = 0;
    strcpy((mx)->sArray, "The string has just been modified");

    int i,j;
    for(i = 0; i<4;i++)
        {
        	for(j = 0; j<3;j++)
			{
        		mx->matrix[i][j] = buf++;
			}
        }

}

void printMemsStructMatrix(StructMatrix* sMx)
{
    printf("m = %d\n", sMx->m);
    printf("n = %d\n", sMx->n);
    printf("sArray = %s\n", sMx->sArray);

    int i, j;
    for(i = 0; i<4;i++)
        {
        	for(j = 0; j<3;j++)
        	{
        		printf(" %d, ", sMx->matrix[i][j]);
        	}
        	printf("\n");
        }


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

 0,  0,  0,
 0,  0,  0,
 0,  0,  0,
 0,  0,  0,
m = 6
n = 52
sArray = The string has just been modified
 0,  1,  2,
 3,  4,  5,
 6,  7,  8,
 9,  10,  11,

 */
