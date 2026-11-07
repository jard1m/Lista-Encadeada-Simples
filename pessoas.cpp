#include <iostream>
#include "pessoas.h"
using namespace std;

void lerlista(listapessoas* &prim) {
	listapessoas *aux, *ultimo = NULL;
	float n;
	char resp;
	string nome;

	do {
	    cout<<endl;
		cout<<"Digite o nome da pessoa: "<<endl;
		cin.ignore();
		getline(cin, nome);
		cout<<endl;
		cout<<"Digite o peso da pessoa: "<<endl;
		cin>>n;
		aux=new nodo;
		aux->valor=n;
		aux->nome=nome;
		aux->prox=NULL;
		if (prim==NULL) {
			prim=aux;
		} else {
			ultimo->prox=aux;
		}
		ultimo=aux;
		cout<<endl;
		cout<<"adicionar mais 1? (S/N)"<<endl;
		cin>>resp;
		resp=toupper(resp);
	} while (resp=='S');
}

float somarpesos (listapessoas *prim) {
	float total=0;
	while (prim!=NULL) {
		total+=prim->valor;
		prim=prim->prox;
	}
	return total;
}

int contarpessoas(listapessoas *prim) {
	int n=0;
	while (prim!=NULL) {
		n++;
		prim=prim->prox;
	}
	return n;
}

void calcularmedia(listapessoas *prim) {
	int n;
	float soma, media;
	soma=somarpesos(prim);
	n=contarpessoas(prim);
	if (n==0) {
	    cout<<endl;
		cout<<"Nenhuma pessoa cadastrada."<<endl;
		cout<<endl;
	} else {
		media=soma/n;
		cout<<endl;
		cout<<"Media: "<<media<<endl;
		cout<<endl;
	}
}

void abaixo50(listapessoas *prim) {
    cout<<endl;
	cout<<"pessoas que pesam menos de 50 kg: "<<endl;
	while (prim!=NULL) {
		if (prim->valor < 50) {
			cout<<prim->nome<<endl;
		}
		prim=prim->prox;
	}
	cout<<endl;
}

void procurar(listapessoas *prim) {
	string nome;
	bool achou=false;
	cout<<endl;
	cout<<"digite o nome de quem deseja procurar: "<<endl;
	cin.ignore();
	getline(cin, nome);
	cout<<endl;
	while (prim!=NULL) {
		if (prim->nome == nome) {
		    cout<<endl;
			cout<<"Pessoa encontrada!"<<endl;
			cout<<endl;
			achou=true;
		}
		prim=prim->prox;
	}
	if(achou==false) {
	    cout<<endl;
		cout<<"Pessoa não encontrada..."<<endl;
		cout<<endl;
	}
}

int menu() {
	int opcao;
	cout<<"Escolha a opção desejada: "<<endl;
	cout<<endl;
	cout<<"1. Cadastrar pessoa"<<endl;
	cout<<"2. Calcular média de pesos cadastrados"<<endl;
	cout<<"3. Listar pessoas abaixo de 50Kg"<<endl;
	cout<<"4. Procurar cadastro"<<endl;
	cout<<"0. Sair"<<endl;
	cout<<endl;
	cin>>opcao;

	return opcao;
}

void executar(int opcao, listapessoas *&prim) {
	float soma;
	int n;
	switch (opcao) {
	case 1:
		lerlista(prim);
		break;
	case 2:
		calcularmedia(prim);
		break;
	case 3:
		abaixo50(prim);
		break;
	case 4:
		procurar(prim);
		break;
	case 0:
	cout<<endl;
		cout<<"Encerrando..."<<endl;
		break;
	default:
		cout<<"Opção inválida."<<endl;
		break;
	}
}