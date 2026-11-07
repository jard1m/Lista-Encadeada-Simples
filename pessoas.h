#include <iostream>
using namespace std;

typedef struct nodo {
	string nome;
	float valor;
	struct nodo *prox;
} listapessoas;

int menu();

void executar(int opcao, listapessoas *&prim);

void lerlista(listapessoas* &prim);

void calcularmedia (listapessoas* prim);

float somarpesos (listapessoas *prim);

int contarpessoas(listapessoas *prim);

void abaixo50(listapessoas *prim);

void procurar(listapessoas *prim);