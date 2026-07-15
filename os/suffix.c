#include <stdio.h>
#include <math.h>
#include <ctype.h> 
#define MAX 100

int top = -1; 
int s[MAX];


void push(int elem) {
    if (top == MAX - 1) {
        printf("\nStack Overflow!!!");
    } else {
        top = top + 1; 
        s[top] = elem; 
    }
}

int  pop() {
    if (top == -1) {
        printf("\nStack Underflow!!!");
        return 0;
    } else {
        int del = s[top]; 
        top = top - 1;   
        return del;
    }
}

int evaluate(char op, int op1, int op2) {
    switch (op) {
        case '+': return (op1 + op2);
        case '-': return (op1 - op2);
        case '*': return (op1 * op2);
        case '/': return (op1 / op2);
        case '%': return (fmod(op1, op2));
        case '^': return (pow(op1, op2));
        default:
            printf("\nInvalid Operator!!!");
            return 0;
    }
}

int main() {
    char suffix[50];
    int i;
    double  val, op1, op2, res;

    printf("\nEnter the Suffix Expression: ");
    scanf("%s", suffix);

    for (i = 0; suffix[i] != '\0'; i++) {
        if (isdigit(suffix[i]))  { 
            push(suffix[i] - '0');
        } 
        else if (isalpha(suffix[i])) {
            printf("\nEnter the value of %c: ", suffix[i]);
            scanf("%lf", &val);
            push(val);
        } 
        else {
            op2 = pop();
            op1 = pop();
            res = evaluate(suffix[i], op1, op2);
            push(res); 
        }
    }

    res = pop();
    printf("\nThe result is %lf\n", res);
    return 0;
}
