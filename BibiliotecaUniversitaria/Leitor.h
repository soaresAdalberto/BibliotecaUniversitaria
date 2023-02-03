#ifndef LEITOR_H
#define LEITOR_H

#include <string>

using namespace std;

class Leitor{
	private:
		int id;
		string nome;
		string cpf;
		
	protected:
		
	public:
		Leitor();
		~Leitor();
		
		int getID();
		string getNome();
		string getCPF();
		
		void setID(int id);
		void setNome(string nome);
		void setCPF(string cpf);
		
		void imprimirInformacoes();
};

#endif
