#include <time.h>
#include <stdlib.h>
#include <stdio.h>

int bubbleSort(int vet[], int n)
{
   int i, j, cont, troca;
   
   cont = 0;
   
   for (i = 0; i < n-1; i++)     
	   
       for (j = 0; j < n-i-1; j++) 
	       
           if (vet[j] > vet[j+1]){
		   
	      cont++;
		   
             troca = vet [j];
	     vet [j] = vet [j+1];
	     vet [j+1] = troca;
	   }
	   
	   return cont;
}
 