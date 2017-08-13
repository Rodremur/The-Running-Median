/* 
 * File:   vector.h
 * Author: vagrant
 *
 * Created on February 12, 2015, 10:22 PM
 */

#ifndef VECTOR_H
#define	VECTOR_H



/**
 * Type: VectorCompareFunction
 * ---------------------------
 * VectorCompareFunction es un apuntador a una funcion del cliente
 * que el vector usa para ordenar sus elementos.
 * La funcion toma dos argumentos void * y regresa un entero.
 * Si elemAddr1 es menor que elemAddr2, regresa un valor negativo.
 * Si elemAddr1 es mayor que elemAddr2, regresa un valor positivo.
 * Si los dos elemenots son iguales, regresa 0.  
 */

typedef int (*VectorCompareFunction)(const void *elemAddr1, const void *elemAddr2);

/** 
 * Type: VectorMapFunction
 * -----------------------
 * VectorMapFunction es un apuntador a una funcion que toma como argumentos la direccion del vector 
 * y la direccion correspondiente a los parametros.
 */
typedef void (*VectorMapFunction)(void *elemAddr, void *auxData);

/**
 * Type: vector
 * ------------
 * 
 */

typedef struct {
	size_t nelem;
	void * elems;
	size_t elemSize;
	size_t capacity;
} Vector;

/** 
 * Funcion: VectorNew
 * Uso: vector myFriends;
 *        VectorNew(&myFriends, sizeof(char *), StringFree, 10);
 * -------------------
 * elemSize especifica el numbero de bytes un un elemento del vector
 * Un assert se debe lanzar si el tamanno es menor o igual a 0
 * 
 * initialAllocation es el tamanno inicial del vector, 
 * tambien indica en cuanto debe crecer el vector cada vez que se llene
 * 
 * 
 */

void VectorNew(Vector *v, size_t elemSize, size_t initialAllocation);

/**
 * Funcion: VectorDispose
 * Uso:     VectorDispose(&studentsDroppingTheCourse);
 * -----------------------
 * Libera la memoria usada por el vector.
 */

void VectorDispose(Vector *v);

/**
 * Funcion: VectorLength
 * ----------------------
 * Regresa la longitud del vector, es decir, el numero de elementos almacenados en el 
 */

int VectorLength(const Vector *v);
	   
/**
 * Funcion: VectorNth
 * -----------------
 * Copia a la direccion elemaddr el elemento en la posicion indicada.
 * La numeracion comienza con 0. Un asser se lanza si n es menor que 0 o mayor
 * que la longitud del vector menos 1. 
 *
 */ 

void VectorNth(const Vector *v, void *elemaddr, int position);
					  
/**
 * Funcion: VectorInsert
 * ----------------------
 * Inserta un nuevo elemento en la posicion especificada. 
 * Un assert se lanza si n es menor que 0 o mayor que la longitu del vector.
 * Los elementos despues de la posicion deben recorrerse para hacer espacio. 
 * Esta funcion debe trabajar en tiempo lineal, es decir no se debe utilizar for para implementarla
 */

void VectorInsert(Vector *v, const void *elemAddr, int position);

/**
 * Funcion: VectorAppend
 * ----------------------
 * Agrega un elemento al final del vector.
 *
 */

void VectorAppend(Vector *v, const void *elemAddr);
  
/**
 * Funcion: VectorReplace
 * -----------------------
 * Sobrescribe el valor de un elemento en la posicion determinada.
 * Un assert se debe lanzar si n es menor que 0 o mayor que la longitud del vector menos uno
 *
 */

void VectorReplace(Vector *v, const void *elemAddr, int position);

/**
 * Funcion: VectorDelete
 * ----------------------
 * Borra el elemento en la posicion determinada. 
 * Un assert se debe lanzar si n es menor que 0 o mayor que la longitud del vector menos uno
 * Los elementos con una posicion mayor deben recorrerse para ocupar el espacio liberado 
 */

void VectorDelete(Vector *v, int position);
  
/* 
 * Funcion: VectorSearch
 * ----------------------
 * Busca a un elemento dentro del vector, debe regresar la posicion donde se encuentra al elemento.
 * Internamente, si el vector esta ordenado (isSorted == true 1) debe usar bsearch
 * si el vector no esta ordenado debe utilizar lfind (isSorted == false 0) 
 * startIndex, es la posicion desde donde se quiere iniciar a buscar, debe ser igual a 0 para buscar
 * en el vector completo
 * si no se encuentra al elemento se debe regresar -1.
 * Un assert se debe lanzar si startIndex es menor que 0 o mayor que la longintud del vector.
 * Un assert se debe lanzar si key o la funcion de comparacion son NULL
 */  

int VectorSearch(const Vector *v, const void *key, VectorCompareFunction searchfn, int startIndex, bool isSorted);

/**
 * Funcion: VectorSort
 * --------------------
 * Ordena a el vector, internamente debe utilizar qsort.
 */

void VectorSort(Vector *v, VectorCompareFunction comparefn);

/**
 * Method: VectorMap
 * -----------------
 * Itera sobre los elementos del vector y llama a la funcion mpafn en cada uno de ellos
 *
 */

void VectorMap(Vector *v, VectorMapFunction mapfn, void *auxData);


#endif	/* VECTOR_H */