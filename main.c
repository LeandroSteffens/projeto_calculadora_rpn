#include <stdio.h>
#include <stdlib.h>
#define MAX 100


float *livre;    //Aponta para regiao de memoria livre
int topo;   // Ponteiro para o topo da pilha 
int *base;  //Ponteiro para a base da pilha
void push (float i);
float pop (void);
 
main()
{
  float a,b;
  char s[80];

  livre = (int ) malloc (MAX*sizeof (int)); /* Aloca memoria para pilha */

    if(!livre) {
        printf("Erro de alocacao de memoria\n"); exit (1);
        exit(1);
    }

    topo = livre;
    base = (livre + MAX-1);
    printf("Calculadora RPN\n");

    do {
        printf(": ");
        gets(s);

        switch (*s) {
            case '+':
                a = pop();
                b = pop();
                //printf("%d\n", b+a);
                push(b+a);
                break;

            case '-':
                a = pop();
                b = pop();
                //printf("%d\n", b-a);
                push(b-a);
            break;

            case '*':
                a = pop();
                b = pop();
                //printf("%d\n", b*a);
                push(b*a);
                break;

            case '/':
                if (a==0) {
                    printf("Divisao por 0\n");
                    exit(0);
                }

              a = pop();
              b = pop();
              //printf("%d\n", b/a);
              push(b/a);
              break; 

            case '.': /*Mostra o resultado*/
                a = pop();
                push(a);
                printf("Resultado: %f\n", a); 
            break;

            default:
                push(atoi (s)); //conversao de string para inteiro
            }
    } while (*s!='q');

return 0;
}

// Armazena um elemento na Pilha void push (int i) = empilha 
void push (float i)
{
  if (livre>base) {
    printf("Pilha Cheia\n");
    return;
  } 
  *livre = i;
  livre++;
}

// Recupera um elemento da Pilha desempilha
float pop (void) 
{
  livre--;
  if (livre<(topo-1)) {
    printf("Pilha Vazia\n");
    return 0;
  }
  return *livre;
}