#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int valor;
  struct node * prox;
} node;

node * inicilaizar (int valor){
  node * aux = (node *)malloc(sizeof(node));
  aux->valor = valor;
  aux->prox = NULL;
  return aux;
}

node * inserir_fila (node * head, node * tail, int valor) {
  node * novo = (node *)malloc(sizeof(node));
  novo->valor = valor;
  novo->prox = tail->prox;
  if(head->prox == NULL) {
  	head->prox = novo;
  	tail = novo;
  }
  return tail;
}

void show_fila(node * head) {
	while(head->prox != NULL) {
		printf("%d", head->prox->valor);
		head = head->prox;
	}
	puts("\n");
}

node * remover_fila (node * head) {
	node * aux;
	aux = head->prox;
	head->prox = aux->prox;
	free(aux);
	return head;
}

int main (){
	node * head;
	node * tail;
	int i;
	head = inicilaizar (-1);
	tail = inicilaizar (-1);
	for(i=0; i<15; i++){
		tail = inserir-fila(head, tail, i);
	}
	show_fila(head);
	return 0;
}