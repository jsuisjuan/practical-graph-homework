#include <iostream>
#include <stdio.h>
#include <fstream>
#include <string>
#include <string.h> 
#define LOWER 1024
#define UPPER 65536
int main(int argc,char *argv[]){
    FILE *arquivo;
    char dado[20];
    int numero = 0, i = 0, valores[3];
    arquivo=fopen("teste.txt","r");
    if(arquivo==NULL){
        std::cout<<"arquivo nao abriu!"<<std::endl;
        return 1;
    }
    size_t incremento=LOWER;
    size_t alocado=incremento;
    char *memoria = (char*)malloc(alocado);
    size_t total=0;
    while(!feof(arquivo)&&!ferror(arquivo)){
        memoria[total] = fgetc(arquivo);
        total++;
        if(total >= alocado){
            if(incremento>=UPPER) incremento=UPPER;
            alocado+=incremento;
            memoria = (char*)realloc(memoria,alocado);
            incremento*=2;
        }
    }
    if(ferror(arquivo)){
        std::cout<<"houve um erro lendo o arquivo"<<std::endl;
        return 1;
    }
    memoria = (char*)realloc(memoria,total);
    memoria[total-1]='\0';
    fclose(arquivo);
    std::cout<<"File contents:\n\n";
    std::cout<<memoria;
    free(memoria);
    return 0;
}
