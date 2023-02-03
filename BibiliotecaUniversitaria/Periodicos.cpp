#include "Periodicos.h"

//Inicializando o n�mero de p�ginas no construtor:
Periodicos::Periodicos(){
	this->numeroPaginas = 0;
}

//Destrutor:
Periodicos::~Periodicos(){
}

//M�todos GET e SET:
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

//Imprimindo o tipo do peri�dico e o n�mero de p�ginas que ele tem:
void Periodicos::imprimirInformacoes(){
	Acervo::imprimirInformacoes();
	cout << "Tipo.....................: " << tipo << endl;
	cout << "N�mero de p�ginas........: " << numeroPaginas << endl << endl;
}
