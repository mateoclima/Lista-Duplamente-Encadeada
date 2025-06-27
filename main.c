#include <stdio.h>
#include "lista_dupla.h"

int main() {
    
    Biblioteca minhaBiblioteca;
    inicializarBiblioteca(&minhaBiblioteca);
    printf("Biblioteca inicializada com sucesso.\n");

    printf("\n--- Cadastrando Livros ---\n");
    cadastrarLivro(&minhaBiblioteca, "O Senhor dos Aneis", "J.R.R. Tolkien", 1954, "978-0-618-0532");
    cadastrarLivro(&minhaBiblioteca, "1984", "George Orwell", 1949, "978-0-451-5249");
    cadastrarLivro(&minhaBiblioteca, "O Guia do Mochileiro das Galaxias", "Douglas Adams", 1979, "978-0-345-3918");
    cadastrarLivro(&minhaBiblioteca, "Fahrenheit 451", "Ray Bradbury", 1953, "978-1-451-6733");
    
    printf("4 livros foram cadastrados.\n");

    printf("\n--- Acervo Completo ---\n");
    listarLivros(&minhaBiblioteca);

    printf("\n--- Listando do Inicio ao Fim (exibirFrente) ---\n");
    exibirFrente(&minhaBiblioteca);

    printf("\n--- Listando do Fim ao Inicio (exibirTras) ---\n");
    exibirTras(&minhaBiblioteca);

    printf("\n--- Testando Emprestimo e Devolucao ---\n");
    printf("Emprestando o livro com ISBN '978-0-451-5249' para 'Joao Silva'...\n");
    emprestarLivro(&minhaBiblioteca, "978-0-451-5249", "Joao Silva", "27/06/2025");
    
    printf("\n--- Acervo Apos Emprestimo ---\n");
    listarLivros(&minhaBiblioteca);

    printf("Devolvendo o livro com ISBN '978-0-451-5249'...\n");
    devolverLivro(&minhaBiblioteca, "978-0-451-5249");
    
    printf("\n--- Acervo Apos Devolucao ---\n");
    listarLivros(&minhaBiblioteca);

    printf("\n--- Testando Remocoes ---\n");

    printf("\nRemovendo livro do meio (por ISBN '978-0-345-3918')...\n");
    removerPorISBN(&minhaBiblioteca, "978-0-345-3918");
    exibirFrente(&minhaBiblioteca);

    printf("\nRemovendo primeiro livro da lista (removerInicio)...\n");
    removerInicio(&minhaBiblioteca);
    exibirFrente(&minhaBiblioteca);

    printf("\nRemovendo ultimo livro da lista (removerFim)...\n");
    removerFim(&minhaBiblioteca);
    exibirFrente(&minhaBiblioteca);
    
    printf("\n--- Destruindo a Biblioteca ---\n");
    destruirBiblioteca(&minhaBiblioteca);
    printf("Memoria liberada. Biblioteca foi Destruida!\n");

    return 0;
}