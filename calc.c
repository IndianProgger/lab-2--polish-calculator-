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
printf("To end work of this calculator enter '@'.\n");
    while (!feof(stdin)) {
        int c = getchar(); /*reading values from string*/
     	int t,t2;
        int x;
        switch (c) {
        	case '@': 
			return 0; 
            case '\n':
            case ' ' : break;
            case '=' : printf("Result = %d\n", pop()); break; /*writing result of calculation*/
            case '+' : push(pop() + pop()); break;
            case '-' : 
            scanf("%d", &t);
            if (t==' ') {
            t=pop(); push(pop()-t); t=0;
        	printf("%d", t);}
            else{
             	t=-t;
             	push(t);
            }
            t=0;
            break;
            case '*' : push(pop() * pop()); break;
            case '^' :
            t=pop(); t2=pop();
            if (t2>=0){
            	for ( t2=t2; t2>1; t2=t2-1 )
            	{
            		t=t*t;
            	} 
            }
            else{
            	t=1/t;
            	for ( t2=t2; t2<(-1); t2=t2+1 )
            	{
             		t=t/t;
             	} 
            }
            push(t); t=0; t2=0;
            break;
            case '/' : t=pop(); push(pop()/ t); t=0; break;
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
