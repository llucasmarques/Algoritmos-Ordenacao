#include <stdlib.h>
#include <stdio.h>

int shellSort(int vet[], int x){
	
    int esp, i, cont;
    cont = 0;
 
    for ( esp = x/2; esp > 0; esp /= 2){
     
        for ( i = esp; i < n; i += 1){
           
            int temp = vet[i];
            int j;   
	    
            for (j = i; j >= esp && vet[j - esp] > temp; j -= esp) {
		    
                vet[j] = vet[j - esp];
		
		cont ++;
		    
	    }
	    
            vet[j] = temp;
        }
    }
    
    return cont;
}