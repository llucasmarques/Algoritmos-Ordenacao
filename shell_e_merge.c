void ordena_shell_sort(tipoLista* ls)
{
    int i, trocas, aux, gap;

    for (gap = 5; gap > 0; gap -= 2){

        trocas = 1;
        while (trocas != 0){
            trocas = 0;

            for (i = 0 + gap; i < ls->quant; i += gap){

                if (ls->dado[i] < ls->dado[i - gap]){
                    aux = ls->dado[i - gap];
                    ls->dado[i - gap] = ls->dado[i];
                    ls->dado[i] = aux;
                    trocas = 1;
                }
            }
        }
    }

}


//Merge sort
void ordena_merge_sort(tipoLista* ls, int ini, int fim)
{
    int meio;

    //Se o tamanho do vetor for maior que 1
    if (ini < fim - 1){

        meio = (ini + fim + 1) / 2;

        //Chamada para a 1a metade
        ordena_merge_sort(ls, ini, meio);

        //Chamada para a 2a metade
        ordena_merge_sort(ls, meio, fim);

        //Unindo as metades
        mergee2(ls, ini, meio, fim);

    }


}



void mergee2(tipoLista* ls, int ini, int meio, int fim)
{
    int i, j, k;
    int* vet_aux;

    vet_aux = (int*) malloc(((meio - ini) + (fim - meio)) * sizeof(int));

    i = ini;
    j = meio;
    k = 0;

    while (i < meio && j < fim){

        if (ls->dado[i] < ls->dado[j]){
            vet_aux[k] = ls->dado[i];
            k++;
            i++;
        }

        else {
            vet_aux[k] = ls->dado[j];
            k++;
            j++;
        }

    }

    while (i < meio){
        vet_aux[k] = ls->dado[i];
        k++;
        i++;
    }

    while (j < fim){
        vet_aux[k] = ls->dado[j];
        k++;
        j++;
    }


    for (i = ini, k = 0; i < fim; i++, k++){
        ls->dado[i] = vet_aux[k];
    }

    free(vet_aux);
}