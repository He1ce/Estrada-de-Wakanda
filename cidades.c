#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "cidades.h"

void ordenarCidadesPorPosicao(Estrada *E) {
    int i, j;
    for (i = 0; i < E->N - 1; i++) {
        for (j = 0; j < E->N - i - 1; j++) {
            if (E->C[j].Posicao > E->C[j + 1].Posicao) {
                Cidade temp = E->C[j];
                E->C[j] = E->C[j + 1];
                E->C[j + 1] = temp;
            }
        }
    }
}

Estrada *getEstrada(const char *nomeArquivo){

    FILE *arquivo = fopen(nomeArquivo, "r");
    if (arquivo == NULL) {
        printf("ERRO! Falha ao abrir o arquivo.\n");
        fclose(arquivo);
        return NULL;
    }

    Estrada *E = (Estrada *)malloc(sizeof(Estrada));
    if (E == NULL){
        printf("Erro ao criar E\n");
        fclose(arquivo);
        return NULL;
    }


    fscanf(arquivo, " %d", &E->T);
    if(E->T < 3 || E->T > pow(10,6)){
        printf("ERRO! Valor de E invalido.\n");
        fclose(arquivo);
        return NULL;
    }

    fscanf(arquivo, " %d", &E->N);
    if(E->T < 2 || E->T > pow(10,4)){
        printf("ERRO! Valor de N invalido.\n");
        fclose(arquivo);
        return NULL;
    }
      

    E->C = (Cidade *)malloc(E->N * sizeof(Cidade));
    if (E->C == NULL){
        printf("Erro: nao foi possi­vel alocar memoria para a lista\n");
        fclose(arquivo);
        return NULL;
    }


    int i = 0;
    while (fscanf(arquivo, " %d %[^\n]\n", &E->C[i].Posicao, E->C[i].Nome) == 2){
        if(E->C[i].Posicao <= 0 || E->C[i].Posicao >= E->T){
            printf("ERRO! Posicao %d invalida.\n", E->C[i].Posicao);
            fclose(arquivo);
            return NULL;
        }
        i++;
    }

    int j;
    for(i = 0; i < E->N; i++){
        for(j = 0; j < i; j++){
            if(E->C[i].Posicao == E->C[j].Posicao){
                printf("ERRO! Ja ha uma cidade na posicao %d.\n", E->C[i].Posicao);
                fclose(arquivo);
                return NULL;
            }
        }
    }

    ordenarCidadesPorPosicao(E);

    fclose(arquivo);
    return E;
}

double calcularMenorVizinhanca(const char *nomeArquivo){

    Estrada *E = getEstrada(nomeArquivo);

    double vizinhanca[E->N];

    vizinhanca[0] = ((double)E->C[1].Posicao - E->C[0].Posicao) / 2;
    vizinhanca[0] += (double)E->C[0].Posicao;

    int i;
    for(i = 1; i < E->N; i++){
        if(i != E->N - 1){
            vizinhanca[i] = ((double)E->C[i + 1].Posicao - E->C[i].Posicao) / 2;
            vizinhanca[i] += ((double)E->C[i].Posicao - E->C[i - 1].Posicao) / 2;
        }
        else{
            vizinhanca[i] = ((double)E->C[i].Posicao - E->C [i - 1].Posicao) / 2;
            vizinhanca[i] += ((double)E->T - E->C[i].Posicao);
        }
    }

    int j;
    double menor;
    for(i = 0; i < E->N; i++){
        for(j = 0; j < i; j++){
            if(vizinhanca[i] < vizinhanca[j]){
                menor = vizinhanca[i];
            }
        }
    }

    return menor;
}

char *cidadeMenorVizinhanca(const char *nomeArquivo){
    Estrada *E = getEstrada(nomeArquivo);
    
    double vizinhanca[E->N];

    vizinhanca[0] = ((double)E->C[1].Posicao - E->C[0].Posicao) / 2;
    vizinhanca[0] += (double)E->C[0].Posicao;

    int i;
    for(i = 1; i < E->N; i++){
        if(i != E->N - 1){
            vizinhanca[i] = ((double)E->C[i + 1].Posicao - E->C[i].Posicao) / 2;
            vizinhanca[i] += ((double)E->C[i].Posicao - E->C[i - 1].Posicao) / 2;
        }
        else{
            vizinhanca[i] = ((double)E->C[i].Posicao - E->C [i - 1].Posicao) / 2;
            vizinhanca[i] += ((double)E->T - E->C[i].Posicao);
        }
    }

    double v = calcularMenorVizinhanca(nomeArquivo);
    
    for(i = 0; i < E->N; i++){
        if(v == vizinhanca[i]){
            return E->C[i].Nome;
        }
    }
}

