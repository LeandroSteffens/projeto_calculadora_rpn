#include <stdio.h>
#include <stdlib.h>
#define MAX 100


int *p;    //Aponta para regiao de memoria livre
int tos;   // Ponteiro para o topo da pilha 
int *bos;  //Ponteiro para a base da pilha
void push (int i);
int pop (void);
 
main()
{
  int a,b;
  char s[80];

  p = (int ) malloc (MAX*sizeof (int)); /* Aloca memoria para pilha */

    if(!p) {
        printf("Erro de alocacao de memoria\n"); exit (1);
        exit(1);
    }

    tos = p;
    bos = (p + MAX-1);
    printf("Calculadora RPN");

    do {
        printf(": ");
        gets(s);

        switch (*s) {
            case '+':
                a = pop();
                b = pop();
                printf("%d\n", b+a);
                push(b+a);
                break;

            case '-':
                a = pop();
                b = pop();
                printf("%d\n", b-a);
                push(b-a);
            break;

            case '*':
                a = pop();
                b = pop();
                printf("%d\n", b*a);
                break;

            case '/':
                a = pop();
                b = pop();
                if (a==0) {
                    printf("Divisao por 0\n");
                break;
                }

            printf("%d\n", b/a);
            push(b/a);
            break; 

            case '.': /*Mostra conteudo do topo da Pilha*/
                a = pop();
                push(a);
                printf("Valor corrente no topo da pilha: %d\n", a); 
            break;

            default:
                push(atoi (s));
            }
    } while (*s!='q');

return 0;
}

// Armazena um elemento na Pilha void push (int i) = empilha 
void push (int i)
{
  if (p>bos) {
    printf("Pilha Cheia\n");
    return;
  } 
  *p = i;
  p++;
}

// Recupera um elemento da Pilha desempilha
pop (void) 
{
  p--;
  if (p<tos) {
    printf("Pilha Vazia\n");
    return 0;
  }
  return *p;
}