#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

int main(){
    int pid = fork();
    int status;

    if(pid==0){
        printf("Child Process\n");
        exit(5);
    }
    else{
        printf("Parent Process");
        wait(&status);
        if(WIFEXITED(status)){
            printf("Child Exited with status : %d\n", WEXITSTATUS(status));
        }
    }
}
