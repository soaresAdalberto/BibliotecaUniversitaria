#ifndef MIDIAS_H
#define MIDIAS_H

#include "Acervo.h"

class Midias : public Acervo{
	private:
		char tipo;
		string tempoDuracao;
	protected:
	
	public:
		Midias();
		~Midias();
		
		char getTipo();
		string getTempoDuracao();
		
		void setTipo(char tipo);
		void setTempoDuracao(string tempoDuracao);
		
		void imprimirInformacoes();
};

#endif
