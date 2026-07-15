#include<stdio.h>
#include<string.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>

int main(){
    char *fifo = "/tmp/myfifo";
    char msg[80],recv[80];

    mkfifo(fifo, 0666);

    while(1){
        int f = open(fifo, O_WRONLY);
        printf("You: ");
        fgets(msg, sizeof(msg), stdin);
        write(f,msg,strlen(msg)+1);
        close(f);

        f = open(fifo, O_RDONLY);
        read(f,recv, sizeof(recv));
        printf("User 2: %s",recv);
        close(f);
    }
    return 0;
}
