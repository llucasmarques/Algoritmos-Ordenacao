#include<stdlib.h>
#include<stdio.h>
 
int merge(int vet[], int l, int m, int r){
	
    int n1, n2, i, j, k, cont,L;
    
    n1 = m - l + 1;
    n2 =  r - m;
    cont = 0;
 
 
    int E[n1], D[n2];
 

    for(i = 0; i < n1; i++)
	    
        E[i] = vet[l + i];
    
    for(j = 0; j < n2; j++)
	    
        D[j] = vet[m + 1+ j];
 
   
    i = 0;
    j = 0;
    k = l;
    
    while (i < n1 && j < n2){
	    
        if (L[i] <= D[j])
        {
            vet[k] = E[i];
            i++;
        }
        else{
		
           vet[k] = D[j];
	   
            j++;
        }
        
        k++;
    }
 
   
    while (i < n1){
	    
        vet[k] = E[i];
	
        i++;
        k++;
	cont ++;
    }
 
   
    while (j < n2){
	    
       vet[k] = D[j];
       
        j++;
        k++;
	cont ++;
    }
    
    return cont;
}
  
int mergeSort(int vet[], int e, int d){
    int cont;
    
    cont = 0;
    
    if (e < d){
	    
        int m = e + (d-e)/2; 
	
        mergeSort(vet, e, m);
        mergeSort(vet, m+1, d);
        cont += merge(vet, e, m, d);
    }
    
    return cont;
}