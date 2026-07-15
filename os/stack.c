#include <stdio.h>
#define MAX 10

int top = -1;
int s[MAX];

void push(int elem) {
    if (top == MAX - 1) {
        printf("\nStack Overflow!");
    } else {
        s[++top] = elem;
    }
}

int pop() {
    if (top == -1) {
        printf("\nStack Underflow!");
        return -1;
    } else {
        return s[top--];
    }
}

void palindrome() {
    int n, i, p[10], flag = 0;

    printf("\nEnter the number of digits (max 10): ");
    scanf("%d", &n);

    if (n > 10 || n < 1) {
        printf("\nInvalid number of digits!");
        return;
    }

    printf("Enter the digits: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &p[i]);
    }
    
    for (i = 0; i < n; i++)
        push(p[i]);

    for (i = 0; i < n; i++) {
        if (p[i] != pop()) {
            flag = 1;
            break;
        }
    }

    if (flag == 0)
        printf("\nPALINDROME!\n");
    else
        printf("\nNOT PALINDROME!\n");
}

void display() {
    int i;
    if (top == -1)
        printf("\nStack is Empty!");
    else {
        printf("\nStack elements: ");
        for (i = top; i >= 0; i--)
            printf("%d ", s[i]);
        printf("\n");
    }
}

int main() {
    int ch, elem, del_elem;

    while (1) {
        printf("\n\n--- STACK OPERATIONS ---");
        printf("\n1. Push");
        printf("\n2. Pop");
        printf("\n3. Check Palindrome");
        printf("\n4. Display");
        printf("\n5. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("\nEnter element to push: ");
                scanf("%d", &elem);
                push(elem);
                break;

            case 2:
                del_elem = pop();
                if (del_elem != -1)
                    printf("\nPopped element: %d", del_elem);
                break;

            case 3:
                palindrome();
                break;

            case 4:
                display();
                break;
            case 5:
                return 0;

            default:
                printf("\nInvalid choice!");
        }
    }

    return 0;
}

