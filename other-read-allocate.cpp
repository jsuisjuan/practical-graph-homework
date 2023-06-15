#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
int main(int argc,char *argv[]){
    std::string word;
    unsigned int count=0;
    char letter;
    std::ifstream infile;
    infile.open("./entradas/grafo_2.txt");
    if(!infile){
        std::cout<<"Error. Could not open file."<<std::endl;
        return 1;
    }
    std::cout<<"File opened for input."<<std::endl;
    infile>>word;
    while(!infile.eof()){
        count++;
        std::cout<<std::setw(4)<<word;
        if(count%3==0) std::cout<<std::endl;
        infile>>word;
    }
    std::cout<<std::endl<<std::endl;
    std::cout<<"There are "<<count<<" words in the dictionary."<<std::endl;
    std::cout<<std::endl<<std::endl;
    infile.close();
    return 0;
}