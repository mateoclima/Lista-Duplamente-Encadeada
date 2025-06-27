#ifndef LISTA_DUPLA_H
#define LISTA_DUPLA_H

#define MAX_TITULO 100
#define MAX_AUTOR 100
#define MAX_ISBN 14
#define MAX_USUARIO 100
#define MAX_DATA 11

// Define os estados possíveis para um livro (se está na prateleira ou com um leitor)
typedef enum {
    DISPONIVEL,
    EMPRESTADO
} StatusLivro;

//rmazena todas as informações pertinentes a um livro
typedef struct {
    char titulo[MAX_TITULO];
    char autor[MAX_AUTOR];
    int ano;
    char isbn[MAX_ISBN];
    StatusLivro status;
    char usuario[MAX_USUARIO];
    char dataEmprestimo[MAX_DATA];
} Livro;

// Representa nó da lista. Contém o livro em si e os ponteiros
// que o conectam ao livro anterior e ao próximo.
typedef struct NoLivro {
    Livro livro;
    struct NoLivro* proximo;
    struct NoLivro* anterior;
} NoLivro;

// Serve como o ponto de entrada e controle da lista. Armazena ponteiros
// para o início e o fim da lista, facilitando operações, e mantém a contagem total de livros.
typedef struct {
    NoLivro* primeiro;
    NoLivro* ultimo;
    int totalLivros;
} Biblioteca;

// Protótipos Funções

// Prepara variável do tipo Biblioteca para uso
void inicializarBiblioteca(Biblioteca* b);

// Adiciona novo livro ao acervo da biblioteca
int cadastrarLivro(Biblioteca* b, char* titulo, char* autor, int ano, char* isbn);

// Exibe na tela uma lista de todos os livros cadastrados
void listarLivros(Biblioteca* b);

// Marca livro como "Emprestado", registrando o usuário e a data
int emprestarLivro(Biblioteca* b, char* isbn, char* usuario, char* data);

// Marca livro como "Disponível" após sua devolução
int devolverLivro(Biblioteca* b, char* isbn);

// Busca um livro específico pelo seu código ISBN
NoLivro* consultarPorISBN(Biblioteca* b, char* isbn);

// Libera memória alocada para os nós , evitando vazamentos de memória
void destruirBiblioteca(Biblioteca* b);

// Imprime lista de livros partindo do primeiro até o último
void exibirFrente(Biblioteca* b);

// Imprime lista de livros partindo do último até o primeiro
void exibirTras(Biblioteca* b);

// Remove um livro específico, buscando-o pelo ISBN
int removerPorISBN(Biblioteca* b, char* isbn);

// Remove primeiro livro da lista
int removerInicio(Biblioteca* b);

// Remove o último livro da lista
int removerFim(Biblioteca* b);

#endif
