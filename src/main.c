/*-------------------------------------------------------
 * Actividad de Programación Avanzada: kata 8 - Find the Running Median
 * Fecha: 17-11-2016
 * Autor:
 *      A01064215 Rodrigo Reyes Murillo
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "vector.h"

float getMedian(Vector * a, int n) 
{
    float res;
    if (n % 2 != 0) 
    {
    	int aux;
        VectorNth(a, &aux, n/2);
        res = (float)aux;
    } 
    else {
    	int aux, aux2;
    	VectorNth(a, &aux, n/2);
    	VectorNth(a, &aux2, (n/2)-1);
        res = ((float)(aux) + (float)(aux2))/2;
    }
    return res;
}

void insertValue(Vector * a, int * val, int low, int high) {
    int mid = (high + low)/2;
    if (high == low) {
        int aux;
        VectorNth(a, &aux, mid);
        printf("%d\n", aux);
        if (aux > *val) {
            VectorInsert(a, val, mid);
        } else {
            VectorInsert(a, val, mid+1);
        }
    } else {
        int aux;
        VectorNth(a, &aux, mid);
        if (aux > *val) {
            insertValue(a, val, low, mid);
        }
        else {
            insertValue(a, val, mid+1, high);
        }
    }
}

int main()
{
    int aux, i, n, m;
    float median; 
    scanf("%d",&n);
    Vector a;
    m = 0;
    VectorNew(&a, sizeof(int), n);
    for(int i = 0; i < n; i++)
    {
       scanf("%d",&aux);
       if (m == 0) {
        VectorAppend(&a, &aux);
        m++;
       } else {
            insertValue(&a, &aux, 0, m-1);
            m++;
       }
       median = getMedian(&a, m);
       printf("%.1f\n", median);
    }
    return 0;
}