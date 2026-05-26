#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 1. Busca Sequencial
int buscaSequencialIterativa(const char * lista[], int tamanho, const char* item);
int buscaSequencialRecursiva(const char * lista[], int tamanho, const char* item);
int buscaSequencialRecursiva_aux(const char* lista[], int tamanho, const char* item, int indice);

// 2. Busca Binária
int buscaBinariaIterativa(const char * lista[], int tamanho, const char* item);
int buscaBinariaRecursiva(const char * lista[], int tamanho, const char* item);
int buscaBinariaRecursiva_aux(const char* lista[], const* item, int inicio, int fim);

// Função para imprimir os resultados de forma organizada
int imprimeResultado(const char* nomeDaBusca, const char* item, int resultado);

// --- FUNÇÂO PRINCIPAL (main) ---
// O programa começa a ser executado aqui
int main(){

    const char * listaDeCompras[] = {
        "arroz",
        "batata",
        "cebola",
        "detergente",
        "feijão",
        "leite",
        "macarrao",
        "oleo",
        "sal",
        "tomate"
    };

    int tamanhoDaLista = sizeof(listaDeCompras) / sizeof(listaDeCompras[0]);

    const char* itemExistente = "leite";
    const char* itemInexistente = "queijo";

    printf("--- DEMONSTRACAO DE ALGORITMOS DE BUSCA EM LISTA DE TEXTOS ---\n");
    printf("Lista utilizada: [arroz, batata, cebola, detergente, feijão, leite, macarrao, oleo, sal, tomate]\n");
    printf("-----------------------------------------------------------------\n\n");

    // Testando a busca sequencial
    printf("--- 1. BUSCA SEQUENCIAL ---\n");
    // a) Versão Iterativa
    int res1 = buscaSequencialIterativa(listaDeCompras, tamanhoDaLista, itemExistente);
    imprimeResultado("Sequencial Iterativa", itemExistente, res1);

    int res2 = buscaSequencialIterativa(listaDeCompras, tamanhoDaLista, itemInexistente);
    imprimeResultado("Sequencial Iterativa", itemInexistente, res2);    
    printf("\n");

    // b) Versão Recursiva
    int res3 = buscaSequencialRecursiva(listaDeCompras, tamanhoDaLista, itemExistente);
    imprimeResultado("Sequencial Recursiva", itemExistente, res3);

    int res4 = buscaSequencialRecursiva(listaDeCompras, tamanhoDaLista, itemInexistente);
    imprimeResultado("Sequencial Recursiva", itemInexistente, res4);    
    printf("------------------------------------------------------------------\n\n");

    // Testando a busca binária
    printf("--- 2. BUSCA BINÁRIA (requer lista ordenada) ---\n");
    // a) Versão Iterativa
    int res5 = buscaBinariaIterativa(listaDeCompras, tamanhoDaLista, itemExistente);
    imprimeResultado("Binária Iterativa", itemExistente, res5);

    int res6 = buscaBinariaIterativa(listaDeCompras, tamanhoDaLista, itemInexistente);
    imprimeResultado("Binária Iterativa", itemInexistente, res6);   
    printf("\n");

    // b) Versão Recursiva
    int res7 = buscaBinariaRecursiva(listaDeCompras, tamanhoDaLista, itemExistente);
    imprimeResultado("Binária Recursiva", itemExistente, res7); 

    int res8 = buscaBinariaRecursiva(listaDeCompras, tamanhoDaLista, itemInexistente);
    imprimeResultado("Binária Recursiva", itemInexistente, res8);   
    printf("------------------------------------------------------------------\n\n");

    return 0; // Indica que o programa terminou com sucesso
}

/**
* @brief Busca sequencial usando laço (iteração)
* @param lista: array de strings onde a busca será feita.
* @param tamanho: número de elementos na lista.
* @param item: string que esta sendo procurada.
* @return índice do item encontrado ou -1 se não encontrado.    
 */
int buscaSequencialIterativa(const char * lista[], int tamanho, const char* item){
    for(int i = 0; i < tamanho; i++){
        if(strcmp(lista[i], item) == 0){
            return i; // Item encontrado, retorna o índice
        }
    }
    // Se o loop terminar sem encontrar o item, retorna -1 para indicar que não foi encontrado
    return -1;
}

/**
* @brief Função "invólucro" (wrapper) para a busca sequencial recursiva.
*        Ela esconde a complexidade do parâmetro 'indice' do usuário.
 */
int buscaSequencialRecursiva(const char * lista[], int tamanho, const char* item){
    // A lógica recursa real está na função auxiliar.
    // Começamos a busca a partir do índice 0.
    return buscaSequencialRecursiva_aux(lista, tamanho, item, 0);
}

/**
* @brief Busca auxiliar que implementa a lógica recursiva da busca sequencial
* @param inidice O índice do elemento atual a ser verificado.
* @return índice do item encontrado ou -1 se não encontrado.    
 */
int buscaSequencialRecursiva_aux(const char* lista[], int tamanho, const char* item, int indice){
    // CASO BASE 1:  FALHA (Fim da lista)
    // Se o índice atual for igual ou maior que o tamanho da lista,
    // significa que já percorremos todos os elemeto sem sucesso.
    if(indice >= tamanho){
        return -1; // Item não encontrado
    }

    // CASO BASE 2: SUCESSO (Item encontrado)
    // Comparamos o item na posição 'indice' atual com o item procurando.
    if(strcmp(lista[indice], item) == 0){
        return indice; // Item encontrado, retorna o índice
    }

    // CASO RECURSIVO: Avançar para o próximo índice
    // Se não for nenhum dos casos base, o item ainda pode estar no resto da lista.
    // Chamamos a função recursivamente, mas agora para o próximo indice (indice + 1)
    // O retorno desta chamada será propagado para a chamanda anterior.
    return buscaSequencialRecursiva_aux(lista, tamanho, item, indice + 1);
}

// 2. Busca Binária

/**
* @brief Busca binária usando laço (iteração)
* @return O índice do item encontrado ou -1 se não encontrado.    
 */
int buscaBinariaIterativa(const char * lista[], int tamanho, const char* item){
    int inicio = 0;
    int fim = tamanho - 1;
    int meio;

    while(inicio <= fim){
        meio = inicio + (fim - inicio) / 2; // Evita overflow

        int comparacao = strcmp(lista[meio], item);
        
        if(comparacao == 0){
            return meio; // Item encontrado
        } else if(comparacao > 0){
            fim = meio - 1; // Item está na metade inferior
        } else {
            inicio = meio + 1; // Item está na metade superior
        }
    }

    return -1;
}


/**
* @brief Função "invólucro" (wrapper) para a busca binária recursiva. 
 */
int buscaBinariaRecursiva(const char * lista[], int tamanho, const char* item){
    return buscaBinariaRecursiva_aux(lista, item, 0, tamanho - 1);
}

/**
* @brief Busca auxiliar que implementa a lógica recursiva da busca binária  
* @param inicio O índice do início da sub-lista atual.
* @param fim O índice final da sub-lista atual.    
* @return O índice do item encontrado ou -1 se não encontrado.    
 */ 

int buscaBinariaRecursiva_aux(const char* lista[], const* item, int inicio, int fim){
    // CASO BASE 1: FALHA (Espaço de busca inválido)
    // Se o 'ínicio' ultrapassar o 'fim', a sub-lista é vazia, o item não está aqui.
    if(inicio > fim){
        return -1; // Item não encontrado
    }   

    // PASSO RECURSIVO E CASO BASE DE SUCESSO
    int meio = inicio + (fim - inicio) / 2; // Evita overflow
    int comparacao = strcmp(lista[meio], item);

    if(comparacao == 0){
        // CASO BASE 2: SUCESSO
        return meio; // Item encontrado
    } else if(comparacao > 0){
        // O item procurado é menor que o item no meio, então deve estar na metade inferior
        return buscaBinariaRecursiva_aux(lista, item, inicio, meio - 1);
    } else {
        // O item procurado é maior que o item no meio, então deve estar na metade superior
        return buscaBinariaRecursiva_aux(lista, item, meio + 1, fim);
    }
}

// ==================================================================
// FUNÇÂO AUXILIAR PARA IMPRESSÃO
// ==================================================================

/**
* @brief Formata e imprime o resultado de uma busca.  
* @param nomeDaBusca O nome do algoritmo utilizado.
* @param item O item que foi procurado.
* @return resultado O resultado da busca (índice ou -1).
 */ 
int imprimeResultado(const char* nomeDaBusca, const char* item, int resultado){
    printf("[%s] Busca por \"%s\"...: \n", nomeDaBusca, item);
    if(resultado != -1){
        printf("    -> Resultado: Item encontrado no índice %d.\n", resultado);
    } else {
        printf("    -> Resultado: Item não encontrado na lista.\n");
    }

    return 0;
}