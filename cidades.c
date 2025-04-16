#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "cidades.h"

Estrada *getEstrada(const char *nomeArquivo){

    FILE *arquivo = fopen(nomeArquivo, "r");
    if (arquivo == NULL) {
        printf("ERRO! Falha ao abrir o arquivo.\n");
        return NULL;
    }

    Estrada *E = (Estrada *)malloc(sizeof(Estrada));
    if (E == NULL){
        printf("Erro ao criar E\n");
        return NULL;
    }


    fscanf(arquivo, " %d", &E->T);
    if(E->T < 3 || E->T > pow(10,6)){
        printf("ERRO! Valor de T invalido.\n");
        return NULL;
    }

    fscanf(arquivo, " %d", &E->N);
    if(E->T < 2 || E->T > pow(10,4)){
        printf("ERRO! Valor de N invalido.\n");
        return NULL;
    }
      

    E->C = (Cidade *)malloc(E->N * sizeof(Cidade));
    if (E->C == NULL){
        printf("Erro: não foi possível alocar memória para a lista\n");
        free(arquivo);
        return NULL;
    }


    int i = 0;
    while (fscanf(arquivo, " %d %[^\n]\n", &E->C[i].Posicao, E->C[i].Nome) == 2){
   
        if(E->C[i].Posicao <= 0 || E->C[i].Posicao >= E->T){
            printf("ERRO! Posicao %d invalida.\n", E->C[i].Posicao);
            return NULL;
        }
        i++;
    }

    int j;
    for(i = 0; i < E->N; i++){
        for(j = 0; j < i; j++){
            if(E->C[i].Posicao == E->C[j].Posicao){
                printf("ERRO! Ja ha uma cidade na posicao %d.\n", E->C[i].Posicao);
                return NULL;
            }
        }
    }


    fclose(arquivo);
    return E;
}

double calcularMenorVizinhanca(const char *nomeArquivo){

    Estrada *T = getEstrada(nomeArquivo);

    double vizinhanca[T->N];

    vizinhanca[0] = ((double)T->C[1].Posicao - T->C[0].Posicao) / 2;
    vizinhanca[0] += T->C[0].Posicao;

    int i;
    for(i = 1; i < T->N; i++){
        if(i != T->N - 1){
            vizinhanca[i] = ((double)T->C[i + 1].Posicao - T->C[i].Posicao) / 2;
            vizinhanca[i] += ((double)T->C[i].Posicao - T->C[i - 1].Posicao) / 2;
        }
        else{
            vizinhanca[i] = ((double)T->C[i].Posicao - T->C [i - 1].Posicao) / 2;
            vizinhanca[i] += ((double)T->T - T->C[i].Posicao);
        }
    }

    int j;
    double menor;
    for(i = 0; i < T->N; i++){
        for(j = 0; j < i; j++){
            if(vizinhanca[i] < vizinhanca[j]){
                menor = vizinhanca[i];
            }
        }
    }

    return menor;
}




