#include "Leitor.h"

#include <iostream>

//Construtor:
Leitor::Leitor(){
}

//Destrutor:
Leitor::~Leitor(){
}

//Imprimindo os dados do leitor:
void Leitor::imprimirInformacoes(){
	cout << "----------------------------------------" << endl;
	cout << "ID.......................: " << id << endl;
	cout << "Nome.....................: " << nome << endl;
	cout << "CPF......................: " << cpf << endl;
	cout << "----------------------------------------" << endl << endl;
}

//Métodos GET e SET:
int Leitor::getID(){
	return id;
}

string Leitor::getNome(){
	return nome;
}

string Leitor::getCPF(){
	return cpf;
}
		
void Leitor::setID(int id){
	this->id = id;
}

void Leitor::setNome(string nome){
	this->nome = nome;
}

void Leitor::setCPF(string cpf){
	this->cpf = cpf;
}
