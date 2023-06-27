#include<ctime>
#include<cstdlib>
#include<fstream>
#include<iostream>

typedef unsigned long long u64;

int buffering_size=8*1024; // 8KB

//int file_size = 10*(1024*1024);//10MB
//
u64 file_size = 2147483648 //2GB

unsigned short max_num_size = 65535; //max possible size of a u16
unsigned short genrnum(unsigned short max){return rand()%max;}

void unbuffered_test(){
    std::ofstream out_file("grafo_1.txt",std::ios::binary);
    for(u64 i=0;i<file_size;i+=2){
        unsigned short val=genrnum(max_num_size);
        unsigned char bytes[2];
        bytes[0]=(val)&0xFF;
        bytes[1]=(val>>8)&0xFF;
        out_file.write((char*)bytes,2);
    }
    out_file.close();
    std::cout<<"finished unbuffered write"<<std::endl;
}

void buffered_test(){
    std::ofstream out_file(".bin",std::ios::binary);
    unsigned char* buffer=new unsigned char[buffering_size];
    int buffer_index=0;
    for(u64 i=0;i<file_size;i+=2){
        unsigned short val=genrnum(max_num_size);
        buffer[buffer_index]=(val)&0xFF;
        buffer[buffer_index+1]=(val>>8)&0xFF;
        buffer_index+=2;
        if(buffer_index>=buffering_size){
            out_file.write((char*)buffer,buffering_size);
            delete[] buffer;
            buffer=new unsigned char[buffering_size];
            buffer_index=0;
        }
    }
    out_file.write((char*)buffer,(file_size%buffering_size));
    delete[] buffer;
    out_file.close();
}

int main(int argc,char *argv[]){
    srand(time(NULL));
    std::clock_t timer;
    double time;
    timer=std::clock();
    unbuffered_test();
    time=(std::clock()-timer)/(double)(CLOCKS_PER_SEC);
    std::cout<<"unbuffered time: "<<time<<" secs"<<std::endl;
    timer=std::clock();
    buffered_test();
    time=(std::clock()-timer)/(double)(CLOCKS_PER_SEC);
    std::cout<<"buffered time: "<<time<<" secs"<<std::endl;
}
