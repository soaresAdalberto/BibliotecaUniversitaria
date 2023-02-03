#include "Livros.h"

//Inicializando o gênero e o número de páginas no construtor:
Livros::Livros(){
	this->genero = "";
	this->numeroPaginas = 0;
}

//Destrutor:
Livros::~Livros(){
}

//Métodos GET e SET:
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

//Imprimindo as informações do gênero e número de páginas:	
void Livros::imprimirInformacoes(){
	Acervo::imprimirInformacoes();
	cout << "Gênero..................: " << genero << endl;
	cout << "Número de páginas.......: " << numeroPaginas << endl << endl;
}
