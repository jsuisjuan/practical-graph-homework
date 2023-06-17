#include <iostream>
#include <stdio.h>
#include <fstream>
#include <string>
#include <string.h> 
#include <array>
#include <bits/stdc++.h>
#include <typeinfo>
#include <malloc.h>
#define LOWER 1024
#define UPPER 65536
double concatenar_array(char arr[]){
    const char *dest="";
    std::string::size_type sz; 
    return std::stod(std::strcat(arr, dest),&sz);
}
int main(int argc,char *argv[]){
    FILE *arquivo;
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
    for(int i=0;i<_msize(memoria);i++) {
        char numero[10];
        int quantidade_decimais=0;
        while(memoria[i]!=' ' && memoria[i]!='\n') {
            numero[quantidade_decimais] = memoria[i];
            quantidade_decimais++;
            i++;
        }
        std::cout<<concatenar_array(numero)<<std::endl;
        std::fill(std::begin(numero), std::end(numero), '\0');
    }
    free(memoria);
    return 0;
}
