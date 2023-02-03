#ifndef ACERVO_H
#define ACERVO_H

#define NUM_AUTOR 5
#define NUM_PALCHAVE 5

#include <iostream>
#include <string>

using namespace std;

class Acervo{
	private:
		int id;
		string cdu;
		string isbn;
		string titulo;
		string autor[NUM_AUTOR];
		string assunto;
		string palavraChave[NUM_PALCHAVE];
		string local;
		string editoraProdutora;
		int edicaoVolume;
		int ano;
		int quantidadeTotal;
		int quantidadeDisponivel;
		float espessura;

	protected:
		
	public:
		Acervo();
		~Acervo();
		
		int getID();
		string getCDU();
		string getISBN();
		string getTitulo();
		string getAutor();
		string getAssunto();
		string getPalavraChave();
		string getLocal();
		string getEditoraProdutora();
		int getEdicaoVolume();
		int getAno();
		int getQuantidadeTotal();
		int getQuantidadeDisponivel();
		float getEspessura();
		
		void setID(int id);
		void setCDU(string cdu);
		void setISBN(string isbn);
		void setTitulo(string titulo);
		void setAutor(string autor[NUM_AUTOR]);
		void setAssunto(string assunto);
		void setPalavraChave(string palavraChave[NUM_PALCHAVE]);
		void setLocal(string local);
		void setEditoraProdutora(string editoraProdutora);
		void setEdicaoVolume(int edicaoVolume);
		void setAno(int ano);
		void setQuantidadeTotal(int quantidadeTotal);
		void setQuantidadeDisponivel(int quantidadeDisponivel);
		void setEspessura(float espessura);
	
		virtual void imprimirInformacoes();
		virtual void imprimirFichaCatalografica();
};

#endif
