# Biblioteca Universitária

##### 1. Sobre o trabalho:
	Esse projeto foi desenvolvido com o intuito de aperfeiçoar as habilidades em programação orientada a objetos na linguagem de alto nível C++. Foram utilizados alguns recursos, como encapsulamento, abstração, herança e polimorfismo. 
	
##### 2. Explicação do código fonte:
	Com a criação do sistema de biblioteca universitária foi possível organizar um acervo composto por livros, periódicos, trabalhos de conclusão, relatórios, mapas, mídias e cartazes. 
	Para cada item deste, foi criado um CRUD (Create, Remove, Update e Delete) e mantido em um vetor, possibilitando que, além das funcionalidades apresentadas, o usuário da aplicação possa emprestar, pesquisar e fornecer fichas catalográficas do seu acervo.
	
##### 3. Organização das classes:
	Sendo a tarefa mais importante na criação deste programa, a organização das classes se deu da seguinte forma: 

 - No programa principal, popularmente conhecido como "main", foram declarados os métodos de manipulação das classes;
 - Acervo foi definida como classe mãe, ou seja, contém os atributos comuns entre "Livros.h", "Mapas.h", "Cartazes.h", "Midias.h", "Periodicos.h", "Relatorios.h" e "TrabalhosConclusao.h";
 - As classes "Leitor.h" e "Emprestimo.h" são independentes. Enquanto a primeira foi criada para armazenar os dados pessoais leitor (como nome e CPF), a segunda é utilizada para o emprestar os materiais que estão disponíveis.  
