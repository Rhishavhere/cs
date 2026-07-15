#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(){
    if(fork()==0){
        printf("Child Process");
        execl("/bin/ls","ls","/home/rhishh",NULL);
        exit(1);
    }
    else{
        printf("Parent Process %d",getpid());
    }
}
