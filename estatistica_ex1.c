//#########################################
// estatistica_ex1.c: Estatística básica
// Autor: Leticia Sayuri Ato Faria
// Data: 05/09/2023
//######################################### 

//Inclusão das bibliotecas necessárias
#include <stdio.h>
#include <math.h>

int main() {
    //declaração das variáveis globais, sendo que...
    int n; //n armazenará a quantidade de valores que serão inseridos
    float num; //num armazenará o valor de cada número que será inserido
    float soma = 0; //soma armazenará um local para a soma de todos os num, iniciando em 0
    float media = 0; //media armazenará um local para a média dos valores, iniciando em 0

     //Atribuição da quantidade de valores inseridos pelo usuário no endereço de memória de n
    printf("Quantos números em sua série? "); 
    scanf("%d", &n);

    float vetor[n]; //declaração de um vetor float com n indíces 

    printf("Entre com %d valores:\n", n);  //input dos valores a serem analisados dentro do valor informado anteriormente
    for (int i = 0; i < n; i++) { 
        printf("--> ", i + 1); 
        scanf("%f", &num);
        vetor[i] = num;
        soma += num; //Soma um a um de todos os valores nos índices do vetor 
    }
    printf("\n");
    
    // Ordenando os números do input de forma crescente com o algoritmo de bubble sort
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (vetor[j] > vetor[j + 1]) { //se o elemento no índice j do vetor for maior que o elemento seguinte...
                float temp = vetor[j]; //ele terá seu valor atribuído a variável local temp
                vetor[j] = vetor[j + 1]; //há a troca de lugar do elemento j com o próximo elemento e isso se repete até que não haja mais elementos de valor menor depois de elementos de valor maior
                vetor[j + 1] = temp; 
            }
        }
    }

    printf("O menor valor é %0.2f.\n\n", vetor[0]); 
    printf("O maior valor é %0.2f.\n\n", vetor[n - 1]); 
    
    // Calculando a mediana
    if (n % 2 == 0) { //e n for par será feita a média dos dois números no meio do vetor
        float mediana = (vetor[(n / 2) - 1] + vetor[(n / 2)]) / 2; 
        printf("A mediana é %0.2f.\n\n", mediana);
    } else { //se n for ímpar a mediana será simplesmente o valor no meio do vetor
        printf("A mediana é %0.2f.\n\n", vetor[n / 2]);
    }
 // Calculando a média
    media = soma / n;
    printf("A média é %0.2f.\n\n", media);

    // Calculando o desvio padrão populacional 
    soma = 0;
    for (int i=0; i<n; i++){
        soma += pow(vetor[i] - media, 2);  //cálculo da variância
    }
    float desvio_padrao = sqrt( soma / n );  //cálculo do desvio padrão em si
    printf("O desvio padrão populacional é %f.\n\n", desvio_padrao);

    return 0;
}