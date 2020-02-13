

int partition (int vet[], int a, int b, int *cont){
	
    int x; 
    int troca, j;
    int i = (a - 1); 
    
    x = vet[b];
 
    for (j = a; j <= b - 1; j++){
       
        if (vet[j] <= x){
		
            i++;    
	    
           troca = vet[j];
	   vet[j] = vet[i];
	   vet[i] = troca;
	   *cont ++;
        }
    }
    
	   troca = vet[b];
	   vet[b] = vet[i+1];
	   vet[i+1] = troca;
	   *cont ++;
    
    return (i + 1);
}
 

void quickSort(int arr[], int a, int b){
	
    int cont, p;
    cont = 0;
    
    if (a < b)
    {
        p = partition(vet, a, b, &cont); 
        quickSort(vet, a, p - 1);
        quickSort(vet, p + 1, h);
    }
    
    return cont;
}