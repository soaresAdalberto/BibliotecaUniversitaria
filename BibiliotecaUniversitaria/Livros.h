#ifndef LIVROS_H
#define LIVROS_H

#include "Acervo.h"

class Livros : public Acervo{
	private:
		string genero;
		int numeroPaginas;
	protected:
	
	public:
		Livros();
		~Livros();
		
		string getGenero();
		int getNumeroPaginas();
		float getEspessura();
		
		void setGenero(string genero);
		void setNumeroPaginas(int numeroPaginas);
		
		void imprimirInformacoes();
};

#endif
