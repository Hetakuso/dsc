
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int jackofalltrades(int r, int c){
    float val;
    int j, i;
    float* arr[r];
    /*'r' é o número de avaliações, 'c' é o número de alunos
    'val' é a nota a ser entrada
    'i' e 'j' são inteiros para interações*/

    for ( i = 0; i < r; i++){
        arr[i] = (float*)malloc(c * sizeof(float));
    } /* Criando um array/vetor de ponteiros e usando 
    malloc para alocar memória para cada linha*/
    
    /* Ficaria mais ou menos assim
     ________         __________
    |_[i][j]_|  --   |_[i+1][j]_| --[...]
        |               |
    ___________    _____________
    |_[i][j+1]_|   |_[i+1][j+1]_| --[...] 
    
         |              |
      [...]           [...]

    Praticamente uma matriz, onde o número de linhas é a quantidade de avaliações
    As colunas são os alunos
    
    De acordo com o material de estudos a fora
    Veja que arr[i][j] é igual a *(*arr+i)+j)*/
    for ( i = 0; i < r; i++){
        for ( j = 0; j < c; j++){
            printf("\n---\nAvaliação %d\nAluno %d Entre o valor \n >", i+1, j+1);
            scanf("%f", &val);
            arr[i][j] = val; // Iteração para colocar os valores no array 
        }
    }
    for (i = 0; i < r; i++){
        printf("\n---\nAvaliação %d\n", i+1);
        for (j = 0; j < c; j++){
            
            printf("\nAluno %d\nNota> %.2f\n", j+1, arr[i][j]);
        }// Impressão dos arrays e seus dados armazenados 
    }
    printf("\n---Resultado final---\n");
    
    int nr = c;
    float* narr;
    narr = malloc( nr* sizeof(float));
        /* Criação de um array 1D para amazenara média dos alunos
        O array tem o tamanho da quantidade de alunos*/

    float  sum;
    printf("\n---\nMédia aritmética das notas dos alunos\n");
    
    // Pecorre as colunas
    for (j=0; j<c; j++){
        sum= 0;//Acumulador de notas do aluno/coluna
        for (i = 0; i<r; i++){
            
            sum+= arr[i][j];
            narr[j]= sum/r; //Insere a média no array 1D, narr
        }
        
        printf("\nAluno %d\nMédia > %.2f\n",j+1 ,narr[j]);
        printf("\nMédia arredondada > %.2f\n////////\n", roundf(narr[j]));
        //Da math.h, função para arredondar float
    }
    
    float av;
    float d;
    float dpa, dpp;
    /*Variáveis para auxiliarem nos cálculos
    av é a média
    d é o quadrado da diferença da nota com a média
    dpa e dpp são respectivamente desvio padrão amostral 
    e desvio padrão populacional*/
    
    printf("\n---\nDados estatísticos das avaliações\n\n");
    printf("\t\tMédia\tDesvio padrão amostral\tDesvio padrão populacional\n");
    
    for (i = 0; i < r; i++){
        sum = 0;
        for (j = 0; j < c; j++){
            sum+= arr[i][j];
           
        }
        av = sum/c;
        
        
        d=0;
        for(j = 0; j < c; j++){ 
            d+= pow(arr[i][j]-av,2);// Elevar ao quadrado, função da math.h
        }
        dpa = sqrt(d/(c-1));// Raiz quadrada, função da math.h
        dpp = sqrt(d/c);
        
        
        printf("\nAvaliação %d:\t> %.2f",i+1,av);
        printf("\t\t> %.2f",dpa);
        printf("\t\t\t> %.2f\n",dpp);
    }



    /* Liberar a memória
    que foi dinamicamente alocada*/

    for ( i = 0; i < r; i++){
        free(arr[i]);
    }
    free(narr);
    
    return 0;
} 


int main()
{
    int r, c; 
    
    printf("Número de avaliação \n >");
    scanf("%d", &r);
    printf("Número de alunos \n >");
    scanf("%d", &c);
    if (r == 0 || c== 0){
        printf("\n\tOperação cancelada\n");
        return 1;
    }
    return jackofalltrades(r,c);


}
