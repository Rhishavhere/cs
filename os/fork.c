#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(){
    int pid = fork();
    if(pid==0){
        printf("Child Process . PID = %d\n",getpid());
        exit(0);
    }
    else{
        printf("Parent Process. PID = %d\n",getpid());
    }
    return 0;
}
