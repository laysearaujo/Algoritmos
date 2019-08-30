#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int valor;
	struct node * next;
} node;

node * inicializar(int valor) {
	node *aux = (node*)malloc(sizeof(node));
	aux->valor = valor;
	aux->next = NULL;
	return aux;
}

node * inserir(node * head, int valor) {
	node * cur =  head;
	node * novo = (node *)malloc(sizeof(node));
	novo->valor = valor;
	novo->next = cur->next;
	cur->next = novo;
	return cur;
}

node * remove_pilha(node * head) {
	node * bye = head->next;
	head->next = bye->next;
	free(bye);
	return head;
}

void show (node * head) {
	while (head->next != NULL) {
		head = head->next;
		print("%d", head->valor);
	}
	puts(" \n");
}

int main () {
	node * head;
	head = inicializar (-1);
	int i;
	for(i=0; i<10; i++) {
		head = inserir(head, i);
	}
	show(head);
	remove_pilha(head);
	show(head);
	return 0;
}