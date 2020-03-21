#include <iostream>
#include <cstring>

using namespace std;

typedef struct node {
    string url;
    struct node * next;
}node;

node * stack_push (node* pilha, string url);
node * stack_cur (node* pilha);
node * stack_delete (node* pilha);
node * stack_deletePAN (node* pilha);
node * enqueue(node* head, node* tail, string url);
node * dequeue (node* head, node* tail);
node * list_delete (node * head); 

node * inicializar (string url){
    
    node * aux = new node();
    aux->url = url;
    aux->next = NULL;

    return aux;
}

int stackSize = 0;
int queueSize = 0;


int main() {
    
    string comando, url;
    int aux = 1;
    
    node * pilha;
    node * tail;
    node * head;

    pilha = inicializar("a");
    tail = inicializar("a");
    head = inicializar("a");

    while(aux == 1){
        cin >> comando;
        if(comando == "OPN") {
            cin >> url;
            stack_push(pilha, url);
            cout << stackSize << endl;
        }
        if(comando == "CUR") {
            stack_cur (pilha);
        }
        if(comando == "BCK") {
            stack_delete (pilha);
            stackSize--;
        }
        if(comando == "PAN") {
            cout << stackSize << endl;
            stack_deletePAN(pilha);
            stackSize = 0;
        }
        if(comando == "SAV") {
            tail = enqueue(head, tail, pilha->next->url);
            cout << queueSize << endl;
        }
        if(comando == "REA") {
            head = dequeue(head, tail);
			if(head->next == NULL) {
				tail = head;
			}
        }
        if(comando == "END") {
            aux = 0;
        }
    }
    return 0;
}

node * stack_push (node* pilha, string url) {
    node * cur = pilha;
    node * novo = new node();
    novo->url = url;
    novo->next = cur->next;
    cur->next = novo;
    stackSize++;
    return cur;
}

node * stack_cur (node* pilha) {
  if(pilha->next != NULL) {
    cout << pilha->next->url << endl;
  }else {
    cout << "NULL" << endl;
  }
    return pilha; 

}

node * stack_delete (node* pilha) {
    node * bye = pilha->next;
    pilha->next = bye->next;
    stack_cur(pilha);
    if(bye != NULL){
        delete bye; 
    }
    return pilha; 

}

node * stack_deletePAN (node* pilha) {
    while(pilha->next != NULL){
        node * bye = pilha->next;
        pilha->next = bye->next;
        if(bye != NULL){
        delete bye; 
        } 
    }
    return pilha;
}

node * enqueue(node* head, node* tail, string url) {
    node * novo = new node();
    novo->url = url;
    novo->next = tail->next;
    if(head->next == NULL){
        head->next = novo;
        tail = head->next;
    }else {
        tail->next = novo;
        tail = novo;
    }
    queueSize++;
    return tail;
}

node * dequeue (node* head, node* tail) {
    node * aux;

    aux = head->next;
    head->next = aux->next;
    cout << aux->url << endl;
    delete aux;
    queueSize--;
    return head;
    
}