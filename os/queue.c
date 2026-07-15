#include <stdio.h>
#define MAX 5

int f =-1, r=-1;

void insert(char q[MAX]){
    char elem;
    printf("Enter Element : ");
    scanf(" %c",&elem);
    
    if(f==0 && r == MAX-1 || (f==r+1)){
        printf("Queue Overflow!");
        return;
    }
    else{
        if(f==-1) f=0;
        r = (r + 1) % MAX;
        q[r] = elem;
    }
}

void delete(char q[MAX]){
    if(f==-1){
        printf("Stack Undeflow!");
        return;
    }
    printf("The Deleted Element : %c", q[f]);
    if(f==r){
        f=-1;
        r=-1;
    }
    else{
        f = (f+1) % MAX;
    }
}

void display(char q[MAX]){
    int i;
    if(f==-1) {
        printf("Empty Queue");
        return;
    }
    else{
        printf("The Elements of Queue : ");
        int i = f;
        while (1) {
            printf("%c ", q[i]);
            if (i == r) break;
            i = (i + 1) % MAX;
        }
    }
}

int main(){
    int ch;
    char q[ MAX ];
    for ( ;; ){
        printf ( "\n	" ); 
        printf ( "\nCIRCULAR QUEUE OPERATIONS" );
        printf ( "\n1: Insert \n2: Delete \n3: Display \n4: Exit" ); 
        printf ( "\n	" );
        printf ( "\nEnter your choice: " ); 
        scanf ( "%d", &ch );
        switch ( ch ){
            case 1: insert ( q ); break;
            case 2: delete ( q ); break;
            case 3: display ( q ); break;
            case 4: return ( 0 );
            default: printf ( "\nInvalid Choice!!!\n" );
        }
    }
}

