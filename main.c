//Cesar Augusto de Araujo Filho RGA:202021901009
//Leandro Steffens de Oliveira RGA:202021901032
//https://github.com/LeandroSteffens/projeto_calculadora_rpn

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100


float *livre;    //Aponta para regiao de memoria livre
int topo;   // Ponteiro para o topo da pilha 
int *base;  //Ponteiro para a base da pilha
void push (float i);
float pop (void);
 
int main()
{
  float a,b;
  char s[80];
  int cont = 0; //cadeia de inteiros

  livre = (int ) malloc (MAX*sizeof (int)); /* Aloca memoria para pilha */

    if(!livre) {
        printf("Erro de alocacao de memoria\n"); exit (1);
        exit(1);
    }

    topo = livre;
    base = (livre + MAX-1);
    printf("Calculadora RPN\n");
  
    //
    gets(s);
    int tam = strlen(s)-1;
    //    

    for (int i = 0; i <= tam; i++){
        switch (s[i]) {
            case '+':
                a = pop();
                b = pop();
                push(b+a);
                break;

            case '-':
                a = pop();
                b = pop();    
                push(b-a);
            break;

            case '*':
                a = pop();
                b = pop();    
                push(b*a);
                break;

            case '/':
                if (a==0) {
                    printf("Divisao por 0\n");
                    exit(0);
                }

              a = pop();
              b = pop();  
              push(b/a);
              break; 

            case '.': /*Mostra o resultado*/
                a = pop();
                push(a);
                printf("Resultado: %f\n", a); 
            break;

            default:
              a = s[i];
                if (a == 32)
                    cont = 0;
                else{
                    a -= '0'; //conversao de string para inteiro
                    if (cont == 1){
                        b = pop();
                        a = (b*10) + a;
                    }                
                    push(a);
                    cont = 1;
                } 
            }
    }

    //resultado
    a = pop();
    push(a);
    printf("\nResultado: %f\n", a);

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