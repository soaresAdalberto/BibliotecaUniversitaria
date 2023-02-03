#include "Livros.h"

//Inicializando o g�nero e o n�mero de p�ginas no construtor:
Livros::Livros(){
	this->genero = "";
	this->numeroPaginas = 0;
}

//Destrutor:
Livros::~Livros(){
}

//M�todos GET e SET:
string Livros::getGenero(){
	return genero;
}

int Livros::getNumeroPaginas(){
	return numeroPaginas;
}
void Livros::setGenero(string genero){
	this->genero = genero;
}

void Livros::setNumeroPaginas(int numeroPaginas){
	this->numeroPaginas = numeroPaginas;
}

//Imprimindo as informa��es do g�nero e n�mero de p�ginas:	
void Livros::imprimirInformacoes(){
	Acervo::imprimirInformacoes();
	cout << "G�nero..................: " << genero << endl;
	cout << "N�mero de p�ginas.......: " << numeroPaginas << endl << endl;
}
