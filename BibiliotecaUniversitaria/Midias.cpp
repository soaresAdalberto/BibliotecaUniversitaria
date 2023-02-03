#include "Midias.h"

//Inicializando a variável tempo de duração no construtor:
Midias::Midias(){
	this->tempoDuracao = "";
}

//Destrutor:
Midias::~Midias(){
}

//Métodos GET e SET:
char Midias::getTipo(){
	return tipo;
}

string Midias::getTempoDuracao(){
	return tempoDuracao;
}
	
void Midias::setTipo(char tipo){
	this->tipo = tipo;
}

void Midias::setTempoDuracao(string tempoDuracao){
	this->tempoDuracao = tempoDuracao;
}

//Imprimindo o tipo da mídia e o tempo de duração:
void Midias::imprimirInformacoes(){
	Acervo::imprimirInformacoes();
	cout << "Tipo.....................: " << tipo << endl;
	cout << "Tempo de duração.........: " << tempoDuracao << endl << endl;
}
