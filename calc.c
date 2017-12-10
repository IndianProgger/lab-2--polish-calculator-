#include <stdio.h>

 int sp = 0;
 int stack[1000];
 int pop(void) { /*initialising stack function pop*/
     if (sp > 0) {
          return stack[--sp];
     } else { 
          printf("unable to use stack function POP, because stack is empty.\n");
          return 0;
     }
 };
 void push(int a) { /*initialising stack function push*/
     stack[sp++] = a;
 };

 
 int main() { /*initialising main function*/
     while (!feof(stdin)) {
         int c = getchar(); /*reading values from string*/
         int x;
         switch (c) {
             case '\n':
             case ' ' : break;
             case '=' : printf("Result = %d\n", pop()); break; /*writing result of calculation*/
             case '+' : push(pop() + pop()); break;
             case '-' : push(-pop() + pop()); break;
             case '*' : push(pop() * pop()); break;
             default:
                 ungetc(c, stdin);
                 if (scanf("%d", &x) != 1) { /*cheching if value is usable in calculations(is in integer type)*/
                     printf("Can't read integer\n");
                     return -1;
                 } else {
                     push(x); /*pushing value from entered string to stack*/
                 }
                 break;
          }
    }
    return 0;
 }