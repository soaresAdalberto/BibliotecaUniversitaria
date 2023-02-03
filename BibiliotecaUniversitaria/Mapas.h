#ifndef MAPAS_H
#define MAPAS_H

#include "Acervo.h"

class Mapas : public Acervo{
	private:
		int numeroPaginas;
	protected:
	
	public:
		Mapas();
		~Mapas();
	
		int getNumeroPaginas();
		
		void setNumeroPaginas(int numeroPaginas);
		
		void imprimirInformacoes();
};

#endif
