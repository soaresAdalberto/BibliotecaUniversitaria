#include "Acervo.h"

//Inicializando as variáveis no construtor:
Acervo::Acervo(){
	this->id = 0;
	this->cdu = "";
	this->isbn = "";
	this->titulo = "";
	this->assunto = "";
	this->local = "";
	this->editoraProdutora = "";
	this->edicaoVolume = 0;
	this->ano = 0;
	this->quantidadeTotal = 0;
	this->quantidadeDisponivel = 0;
	this->espessura = 0;
	
	for(int i=0;i<NUM_AUTOR;i++)
	{
		this->autor[i] = "";
	}
	for(int i=0;i<NUM_PALCHAVE;i++)
	{
		this->palavraChave[i] = "";
	}
}

//Destrutor:
Acervo::~Acervo(){
}

//Métodos GET e SET:
int Acervo::getID(){
	return id;
}

string Acervo::getCDU(){
	return cdu;
}

string Acervo::getISBN(){
	return isbn;
}

string Acervo::getTitulo(){
	return titulo;
}

string Acervo::getAutor(){
	for(int i=0;i<NUM_AUTOR;i++)
	{
		autor[i] = this->autor[i];
	}
}

string Acervo::getAssunto(){
	return assunto;
}

string Acervo::getPalavraChave(){
	for(int i=0;i<NUM_PALCHAVE;i++){
		palavraChave[i] = this->palavraChave[i];
	}
}

string Acervo::getLocal(){
	return local;
}

string Acervo::getEditoraProdutora(){
	return editoraProdutora;
}

int Acervo::getEdicaoVolume(){
	return edicaoVolume;
}

int Acervo::getAno(){
	return ano;
}

int Acervo::getQuantidadeTotal(){
	return quantidadeTotal;
}

int Acervo::getQuantidadeDisponivel(){
	return quantidadeDisponivel;
}

float Acervo::getEspessura(){
	return espessura;
}
		
void Acervo::setID(int id){
	this->id = id;
}

void Acervo::setCDU(string cdu){
	this->cdu = cdu;
}

void Acervo::setISBN(string isbn){
	this->isbn = isbn;
}

void Acervo::setTitulo(string titulo){
	this->titulo = titulo;
}

void Acervo::setAutor(string autor[NUM_AUTOR]){
	for(int i=0;i<NUM_AUTOR;i++)
	{
		this->autor[i] = autor[i];
	}
}

void Acervo::setAssunto(string assunto){
	this->assunto = assunto;
}

void Acervo::setPalavraChave(string palavraChave[NUM_PALCHAVE]){
	for(int i=0;i<NUM_PALCHAVE;i++)
	{
		this->palavraChave[i] = palavraChave[i];
	}
}

void Acervo::setLocal(string local){
	this->local = local;
}

void Acervo::setEditoraProdutora(string editoraProdutora){
	this->editoraProdutora = editoraProdutora;
}

void Acervo::setEdicaoVolume(int edicaoVolume){
	this->edicaoVolume = edicaoVolume;
}

void Acervo::setAno(int ano){
	this->ano = ano;
}

void Acervo::setQuantidadeTotal(int quantidadeTotal){
	this->quantidadeTotal = quantidadeTotal;
}

void Acervo::setQuantidadeDisponivel(int quantidadeDisponivel){
	this->quantidadeDisponivel = quantidadeDisponivel;
}

void Acervo::setEspessura(float espessura){
	this->espessura = espessura;
}

//Método para imprimir as informações:		
void Acervo::imprimirInformacoes(){
	cout << "ID......................: " << id << endl;
	cout << "CDU.....................: " << cdu << endl;
	cout << "ISBN....................: " << isbn << endl;
	cout << "Título..................: " << titulo << endl;
	cout << "Autores.................: ";
	
	//Percorrendo e encontrando os autores:
	for(int i=0;i<NUM_AUTOR-1;i++)
	{
		if(autor[i] != "")
		{
			if(autor[i+1] != "")
			{
				cout << autor[i] << "; ";
			}
			else
			{
				cout << autor[i] << endl;
			}
		}
	}
	
	cout << "Assunto..................: " << assunto << endl;
	cout << "Palavras chave...........:";
	
	//Percorrendo e encontrando as palavras-chave:
	for(int i=0;i<NUM_PALCHAVE;i++)
	{
		if(palavraChave[i] != "")
		{
			if(palavraChave[i+1] != "")
			{
				cout << palavraChave[i] << "; ";
			}
			else
			{
				cout << palavraChave[i] << endl;
			}
		}
	}
	
	cout << "Local....................: " << local << endl;
	cout << "Edição/Volume............: " << edicaoVolume << endl;
	cout << "Editora/Produtora........: " << editoraProdutora << endl;
	cout << "Ano......................: " << ano << endl;
	cout << "Espessura................: " << espessura << endl;
	cout << "Quantidade total.........: " << quantidadeTotal << endl;
	cout << "Quantidade disponível....: " << quantidadeDisponivel << endl;
}

//Método para imprimir a ficha catalografica:
void Acervo::imprimirFichaCatalografica(){
	
	//Imprimindo os autores:
	cout << endl << "----------------------------------------------------------------------------------------------------" << endl;
	for(int i=0;i<NUM_AUTOR;i++)
	{
		if(autor[i] != "")
		{
			cout << autor[i] << ". ";
		}
	}
	
	//Imprimindo as informações adicionais:
	cout << endl << endl;
	cout << titulo << " - " << edicaoVolume << " - " << local << ": " << editoraProdutora << ", " << ano << "." << endl;
	cout << espessura << " cm." << endl << endl;
	
	cout << "ISBN: " << isbn << endl << endl;
	cout << "1. " << assunto << ". ";
	
	//Imprimindo as palavras-chave:
	for(int i=0;i<NUM_PALCHAVE;i++)
	{
		if(palavraChave[i] != "")
		{
			switch(i)
			{
				case 0:
					cout << "I. " << palavraChave[i] << ". ";
					break;
				case 1:
					cout << "II. " << palavraChave[i] << ". ";
					break;
				case 2:
					cout << "III. " << palavraChave[i] << ". ";
					break;
			}
		}
	}
	cout << endl << endl << "\t\t\t\tCDU: " << cdu << endl;
	cout << endl << "----------------------------------------------------------------------------------------------------" << endl << endl;
}
