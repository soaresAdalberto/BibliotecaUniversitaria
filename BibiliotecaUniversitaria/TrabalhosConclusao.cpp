#include "TrabalhosConclusao.h"

//Inicializando o n�mero de p�ginas do TCC no construtor:
TrabalhosConclusao::TrabalhosConclusao(){
	this->numeroPaginas = 0;
}

//Destrutor:
TrabalhosConclusao::~TrabalhosConclusao(){
}

//M�todos GET e SET:
char TrabalhosConclusao::getTipo(){
	return tipo;
}

int TrabalhosConclusao::getNumeroPaginas(){
	return numeroPaginas;
}
		
void TrabalhosConclusao::setTipo(char tipo){
	this->tipo = tipo;
}

void TrabalhosConclusao::setNumeroPaginas(int numeroPaginas){
	this->numeroPaginas = numeroPaginas;
}

//Imprimindo o tipo de TCC e o n�mero de p�ginas:	
void TrabalhosConclusao::imprimirInformacoes(){
	Acervo::imprimirInformacoes();
	cout << "Tipo.....................: " << tipo << endl;
	cout << "N�mero de p�ginas........: " << numeroPaginas << endl << endl;
}
