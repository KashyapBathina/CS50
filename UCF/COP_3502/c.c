/*
stack:
    abstract data type; last in first out; anything added goes on top; anything removed must be on top; ie stack of plates; basic operations: push, pop, isempty, isfull, peek
    push: when maxSize = 6; stack[maxSize]; top=-1 -> push(char x) {stack[++top] = x}(remember ++i increments first (why ++ front) and returns incremented val; also ++top
        inside [] still icrements top and is the same as ++top; stack[top]); what push does is set increase index and set index = x
    pop: return stack[top--]; returns value before -- and sets top--; note doesn't remove element at past top, just changes refrnce point so can be overwritten by push
    peek: return stack[top]; returns top item in the stack
    many ways to implement:
        array with global variables:
            push: if (top >= maxSize -1) {printf(stack overflow)}  else {stack[++top]=x}
            pop: if (top<0) {printf(stack overflow)} else {return stack[top--]}
            isempty: if (stack<0) {printf(stack empty)} else {printf(! empty)}
            isfull: if (top>=maxSize-1) {printf(full)}
        linked list: insert at the head while pushing, and remove from the head while popping
    many uses for this data type:
        balance of parenthesis: ie whether "(([))) makes sense: solution=read string char left to right, if (,[,{, then push on stack -> if ),],}, pop and check if get corres-
            ponding closer -> when reach end, check if stack empty:
        infix/postfix expression evaluation: infix = a + b *c or (a + b) * c - d * e; postfix


*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define maxSize 100
char stack[maxSize];
int top = -1;


void push(char x) {
    if (top>= maxSize-1) {
        printf("stack overflow");
    }
    else {
        stack[++top] = x;
    }
}

int pop() {
    if (top<0) {
        return -999;
    }
    else
        return stack[top--];
}

int isempty() {
    if (top<0)
        return 1;
    else
        return 0;
}

int isbalanced (char* str) {
    int result = 1;

    for (int i=0; i<strlen(str);i++) {
        // note "(" double quotes is a string literal with null \0, '(' is single char
        if (str[i] == '(' || str[i] == '[' || str[i] == '{' ) {
            push(str[i]);
        }
        else {
            char x = pop();

            if (str[i] == ')') {
                if (x != '(')
                    return 0;
            }
            if (str[i] == ']') {
                if (x != '[')
                    return 0;
            }
            if (str[i] == '}') {
                if (x != '{')
                    return 0;
            }
        }
    }

    if (isempty()==0)
        return 0;
    else
        return 1;
}

int main() {
    char str[100];

    printf("Enter parenthesis expression: ");
    scanf("%s", str);
    printf("Input: %s\n", str);
    int result = isbalanced(str);

    if (result == 0) {
        printf("not balanced!\n");
    }
    else
        printf("balanced!\n");
}
