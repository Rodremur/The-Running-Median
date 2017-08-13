/*-------------------------------------------------------
 * Actividad de Programación Avanzada: kata 8 - Find the Running Median
 * Fecha: 17-11-2016
 * Autor:
 *      A01064215 Rodrigo Reyes Murillo
 */
#include <stdio.h>
#include <stdlib.h>
int n, nelem;

float getMedian(int * a, int n) 
{
    float res;
    if (n % 2 != 0) 
    {
        res = a[n/2];
    } 
    else {
        res = ((float)(a[n/2]) + (float)(a[(n/2)-1]))/2;
    }
    return res;
}

void insertValue(int * a, int val, int low, int high) {
    int mid = (high + low)/2;
    if (high == low) {
        if (a[mid] > val) {
            int b[n], i;
            int aux = a[mid];
            b[mid] = val;
            b[mid+1] = a[mid];
            for (i = 0; i < mid; i++) {
                    b[i] = a[i];
            }
            if (mid+2 < n) {
                for (i = mid+2; i < n; i++) {
                    b[i] = a[i-1];
                }
            }
            for (i = 0; i < n; i++) {
                a[i] = b[i];
            }
        } else {
            int b[n], i;
            int aux = a[mid];
            b[mid+1] = val;
            for (i = 0; i < mid+1; i++) {
                    b[i] = a[i];
            }
            if (mid+2 < n) {
                for (i = mid+2; i < n; i++) {
                    b[i] = a[i-1];
                }
            }
            for (i = 0; i < n; i++) {
                a[i] = b[i];
            }
        }
    } else {
        if (a[mid] > val)
            insertValue(a, val, low, mid);
        else
            insertValue(a, val, mid+1, high);
    }
}

int main()
{
    int aux, i;
    float median; 
    scanf("%d",&n);
    nelem = 0;
    int *a = malloc(sizeof(int) * n);
    for(int i = 0; i < n; i++)
    {
       scanf("%d",&aux);
       if (nelem == 0) {
        a[0] = aux;
        nelem++;
       } else {
            insertValue(a, aux, 0, nelem-1);
            nelem++;
       }
       median = getMedian(a, nelem);
       printf("%.1f\n", median);
    }
    return 0;
}