#include<stdio.h>

void tower_hanoi ( int n, char src, char dest, char temp ){
    if ( n == 1 ){
        printf ( "\nMove disk %d from peg %c to peg %c", n, src, dest ); 
        return;
    }

    tower_hanoi ( n - 1, src, temp, dest );

    printf ( "\nMove disk %d from peg %c to peg %c", n, src, dest );

    tower_hanoi ( n - 1, temp, dest, src );
}
int main()
{
    int n;
    printf ( "\nEnter the number of disks: " );
    scanf ( "%d", &n ); 
    tower_hanoi ( n, 'A', 'B', 'C' ); 
    return ( 0 );
}
