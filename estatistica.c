//EP1 - Estatística Básica
 
//Autor: Felipe Chen
//Data: 04/06/2021
           


#include <stdio.h>
#include <math.h>
#include <stdlib.h>


 // Referência para a função "sort" compararar os itens e ordená-los. 
int compare (const void *a,const void *b) {
//Ponteiros a e b pecorrem no vetor
    
//Transformar o tipo void em float pois é uma função que vai comparar pontos flutuantes
    
    float *x = (float *) a;
    // Pega os valores no endereço de um ponteiro para outro ponteiro
    float *y = (float *) b;

    if (*x < *y){
    
        return -1;
// Returna falso quando o valor em y for maior que x

    }
    
    else if (*x > *y){
        //Retorna verdadeiro quando o valor apontado de x é maior que y 
        
        return 1; return 0;
    }
}

int statistics (int a){
    //Função que vai receber os números e devolver resultados 
    //Tem argumento, "a", como o número de elementos que serão inseridos no vetor
    
    
    float *array;
    // Ponteiro que vai participar da alocação dinâmica
    
    float number;
    // Variável dos números entrados
    
    int q;
    // Variável que vai peccorrer o vetor na iteração

    
    array = malloc (a * sizeof (float));
    // Alocação dinâmica pela função malloc para elementos tipo float

    
    for (q=0; q<a; q++){
        //Iteração para pecorrer no vetor
        
        printf("Escreva os números que deseja inserir \n");
        scanf("%f", &number);
        //Entrada dos números

        array[q]=number;
        //Preenchimento do vetor

    }

    printf("Foram amazanados %d números \n",a);
    
    qsort (array,a, sizeof(float), compare);
    //função para ordenar os elementos em ordem crescente

    
    for (q=0; q<a; q++){
        printf("Esse número foi entrado ->");
        printf("%f\n", array[q]);
    }// Comando para imprimir os elementos que foram encontrados no vetor
    
    //Comandos para o cálculo da média
    
    float sum, mean;
    // sum é um acumulador que é a soma dos elementos do vetor
    //mean é a média obtida depois da divisão do sum
        
    for (q=0; q<a; q++){
        sum+=array[q];
    }//Pecorrer-se o vetor para o "sum" ser calculado
    
    mean= sum/a;
    // Média aritmética é a soma dos elementos divido pela quantidade de elementos
    
    printf("Média: %f\n", mean);
    
    
    
    //Mediana
    
    float c;
    //Variável para expressar a mediana
    
    if (a%2==0){
        //Se o tamanho do vetor entrado for par
        //Pegar os dois elementos centrais, somá-los e dividí-los por dois
        
        c= (array[a/2] + array[a/2 + 1]) / 2;

    }
    else{
        //Caso o número de elementos for ímpar
        c= array[a/2];

    }
    printf("Mediana: %f\n",c);
    
    // Desvio padrão populacional
    
    float d,dp;
    float e;
    //Variáveis que participam no cálculo do desvio padrão
    
    for (q=0; q<a; q++){
        //Desvio padrão é a raiz quadrada somatória de cada "valor - média" ao quadrado
        //dividido pelo número de termos
       
        
        d+= pow(array[q] - mean, 2);
        //função pow(base, exponent) para fazer a potência da base
    }
    dp = sqrt(d/a);
    
    printf("Desvio padrão (populacional):%f\n", dp);
    
    
    // Valor máximo e valor mínimo
    float valmin,valmax;

    valmin= array[0];
    // Valor mínimo está na primeira posição
    // já que os elementos do vetor já estão em rol
    
    valmax = array[a-1];
    //Como a contagem do index começa por zero,
    // a posição do valor máximo é o tamanhho do vetor - 1
    
    if (array[0] == array[a-1]){
        printf("Não existe valores máximo e mínimo numa lista de números homogênea\n"
               "Todos números são iguais\n");
    }

    else{
    
        printf("Valor mínimo: %f\nValor máximo: %f\n", valmin,valmax);
    }
    
    free(array);
    //liberar o espaço de memória alocado dinamicamente 
    //no caso, o ponteiro que foi alocado pela função malloc é liberada
    
    return 0;
}



int main(){
    
    int l;
    int n = 5;
    
    l= statistics (n);
    

    
    return 0;
}