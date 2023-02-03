#include "Periodicos.h"

//Inicializando o número de páginas no construtor:
Periodicos::Periodicos(){
	this->numeroPaginas = 0;
}

//Destrutor:
Periodicos::~Periodicos(){
}

//Métodos GET e SET:
char Periodicos::getTipo(){
	return tipo;
}

int Periodicos::getNumeroPaginas(){
	return numeroPaginas;
}
		
void Periodicos::setTipo(char tipo){
	this->tipo = tipo;
}

void Periodicos::setNumeroPaginas(int numeroPaginas){
	this->numeroPaginas = numeroPaginas;
}

//Imprimindo o tipo do periódico e o número de páginas que ele tem:
void Periodicos::imprimirInformacoes(){
	Acervo::imprimirInformacoes();
	cout << "Tipo.....................: " << tipo << endl;
	cout << "Número de páginas........: " << numeroPaginas << endl << endl;
}
