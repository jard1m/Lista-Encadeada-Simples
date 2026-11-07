#include <iostream>
#include "pessoas.h"
using namespace std;

int main()
{
	listapessoas *prim=NULL;
	int opcao;
	do {
		opcao=menu();
		executar(opcao, prim);
	} while(opcao!=0);

	return 0;
}