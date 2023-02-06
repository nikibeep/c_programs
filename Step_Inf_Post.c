#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define MAX_EXPR_SIZE 100

char stack[MAX_EXPR_SIZE];
int top = -1;

void push(char c) {
    stack[++top] = c;
}

char pop() {
    if (top == -1)
        return -1;
    else
        return stack[top--];
}

int priority(char c) {
    if (c == '^')
        return 3;
    else if (c == '*' || c == '/')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}

void infixToPostfix(char *infix, char *postfix) {
    int i, j = 0;
    char c;
    for (i = 0; i < strlen(infix); i++) {
        c = infix[i];
        if (isalnum(c)) {
            postfix[j++] = c;
            
        } else if (c == '(') {
            push(c);
            
        } else if (c == ')') {
            while ((c = pop()) != '(') {
                postfix[j++] = c;
               
            }
        } else {
            while (priority(stack[top]) >= priority(c) && top != -1) {
                postfix[j++] = pop();
                
            }
            push(c);
        }
        postfix[j] = '\0';
        puts(postfix);
    }
    while (top != -1) {
        postfix[j++] = pop();
    }
    postfix[j] = '\0';
}

int main() {
    char infix[MAX_EXPR_SIZE], postfix[MAX_EXPR_SIZE];
    printf("Enter an infix expression: ");
    scanf("%s", infix);
    infixToPostfix(infix, postfix);
    printf("Postfix expression: %s\n", postfix);
    return 0;
}
