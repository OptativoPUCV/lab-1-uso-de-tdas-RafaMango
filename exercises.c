#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "arraylist.h"
#include "stack.h"

//#include "exercises.h"

//Funciones auxiliares que puedes utilizar para debuggear tus ejercicios
//NO MODIFICAR
void imprime_lista(List *L) {
   int *dato;
   dato = (int*)first(L);
   printf("[");
   while(dato != NULL) {
      printf("%d ", *dato);
      dato = (int*)next(L);
   }
   printf("]\n");

}

//Ojo que la pila se vacía al imprimir y se imprime en orden inverso
//NO MODIFICAR
void imprime_y_vacia_pila(Stack *P) {
   void *dato;
   printf("[");
   while((dato = pop(P)) != NULL) {
      printf("%d ", *(int*)dato);
   }
   printf("]\n");
}

/* 
Ejercicio 1.
Crea una Lista y agrega punteros a elementos del 1 al 10.
Recuerda que la lista almacena punteros, por lo que
debes reservar memoria para cada elemento que agregues.
Al finalizar retorna la lista creada.
*/

List* crea_lista() 
{
   List* L = create_list();
   for(int i = 1; i <= 10; i++)
   {
      int * dato = (int*)malloc(sizeof(int));
      *dato = i;
      pushBack(L, dato);
   }   
   return L;
}

/*
Ejercicio 2.
Crea una función que reciba una lista de enteros (int*) y 
retorne la suma de sus elementos.
*/
int sumaLista(List *L)
{
   int suma = 0; //contador
   int *dato = (int*)first(L); //tomar el primer dato de la lista
   while(dato != NULL)
   {
      suma += *dato;
      dato = (int*)next(L); //pasar al siguiente dato
   }
   
   return suma;
}

/*
Ejercicio 3.
Crea una función que reciba una lista de punteros a int (int*) y
un entero elem. La función debe eliminar todos los elementos 
de la lista que sean iguales a elem.
Asume que popCurrent luego de eliminar un elemento se
posiciona en el elemento anterior.
*/ 
// 1 , 2 , 3, 4

void eliminaElementos(List*L, int elem)
{
   int *numero = (int*)first(L);
   while(numero != NULL)
   {
      if(*numero == elem)
      {
         free(popCurrent(L));
         
      }
      numero = (int*)next(L);
   }
}

/*
Ejercicio 4.
La función copia los punteros de la pila P1 en la pila P2.
El orden de ambas pilas se debe mantener.
Puedes usar una pila auxiliar.
*/

void copia_pila(Stack* P1, Stack* P2) 
{
   Stack* auxiliar = create_stack();
   void* dato; //
   
   while((dato = popFront(P1)) != NULL)
   {
      pushFront(auxiliar, dato);
   }
   while((dato = popFront(auxiliar)) != NULL)
   {
      pushFront(P1,dato);
      pushFront(P2, dato);
   }
   
}

/*
Ejercicio 5.
La función verifica si la cadena de entrada tiene sus 
paraéntesis balanceados. Retorna 1 si están balanceados,
0 en caso contrario.
*/

int parentesisBalanceados(char *cadena)
{
   Stack* nuevaPila = create_stack();

   for(int i = 0; cadena[i] != '\0'; i++)
   {
      char dato = cadena[i];
      if(dato == '(' || dato == '[' || dato == '{')
      {
         push(nuevaPila, &cadena[i]); 
      }
      else if(dato == ')' || dato == ']' || dato == '}')
      {
         if(get_size(nuevaPila) == 0)return 0;
         char* topeP = (char*)pop(nuevaPila);
         if((dato == ')' && *topeP != '(') || 
            (dato == ']' && *topeP != '[') || 
            (dato == '}' && *topeP != '{'))
         {
            return 0;
         }
      }
      
   }
   
   return get_size(nuevaPila) == 0 ? 1 : 0; 
   // get_size cantidad de elementos en la pila
   // == 0 verifica si hay elementos
   //pila vacia == balanceada y si != vacia desBalanceada
}

