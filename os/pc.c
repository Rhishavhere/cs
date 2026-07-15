#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>
#include<unistd.h>

#define SIZE 5

int buffer[SIZE];
int in =0, out=0;
int item =0;

sem_t empty,full;
pthread_mutex_t mutex;

void* producer(void* arg){
    sem_wait(&empty);
    pthread_mutex_lock(&mutex);

    item++;
    buffer[in]=item;
    printf("Producer Produced Item %d at position %d\n",item,in);
    in = (in+1)%SIZE;

    pthread_mutex_unlock(&mutex);
    sem_post(&full);
    return NULL;
}
void* consumer(void* arg){
    sem_wait(&full);
    pthread_mutex_lock(&mutex);

    int consumed = buffer[out];
    printf("Producer Consumed Item %d at position %d\n",consumed,out);
    out = (out+1)%SIZE;

    pthread_mutex_unlock(&mutex);
    sem_post(&empty);
    return NULL;
}

int main(){
    int ch;
    pthread_t p,c;

    sem_init(&empty,0,SIZE);
    sem_init(&full,0,0);
    pthread_mutex_init(&mutex,NULL);

    while(1){
        printf("1. Producer");
        printf("2. Consumer");
        printf("3. Exit");
        printf("Enter Choice : ");
        scanf("%d",&ch);

        switch(ch){
            case 1:
                pthread_create(&p,NULL,producer,NULL);
                pthread_join(p,NULL);
                break;
            case 2:
                pthread_create(&c,NULL, consumer,NULL);
                pthread_join(c,NULL);
                break;
            case 3:
                sem_destroy(&empty);
                sem_destroy(&full);
                pthread_mutex_destroy(&mutex);
                printf("Exiting..\n");
                return 0;
            default:
                printf("Invalid");
        }
        sleep(1);
    }
}
