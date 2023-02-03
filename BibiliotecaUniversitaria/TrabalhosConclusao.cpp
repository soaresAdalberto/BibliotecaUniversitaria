#include "TrabalhosConclusao.h"

//Inicializando o número de páginas do TCC no construtor:
TrabalhosConclusao::TrabalhosConclusao(){
	this->numeroPaginas = 0;
}

//Destrutor:
TrabalhosConclusao::~TrabalhosConclusao(){
}

//Métodos GET e SET:
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

//Imprimindo o tipo de TCC e o número de páginas:	
void TrabalhosConclusao::imprimirInformacoes(){
	Acervo::imprimirInformacoes();
	cout << "Tipo.....................: " << tipo << endl;
	cout << "Número de páginas........: " << numeroPaginas << endl << endl;
}
