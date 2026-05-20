#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR_LEN 50

#define TAM_MAX 10

typedef struct {
    char dados[TAM_MAX][MAX_STR_LEN];
    int quantidade;
} ListaEstatica;

void inicializarListaEstatica(ListaEstatica *lista);

void inserirListaEstatica(ListaEstatica *lista, const char *texto);
void removerListaEstatica(ListaEstatica *lista, const char *texto);
void listarListaEstatica(const ListaEstatica *lista);

typedef struct No {
    char* dado;         // Ponteiro para armazenar a string (alocada dinamicamente)
    struct No* proximo;
} No;

typedef No* ListaEncadeada;

void inicializarListaEncadeada(ListaEncadeada *lista);

void inserirListaEncadeada(ListaEncadeada *lista, const char *texto);
void removerListaEncadeada(ListaEncadeada *lista, const char *texto);
void listarListaEncadeada(const ListaEncadeada lista);
void liberarListaEncadeada(ListaEncadeada *lista); // Função para liberar a memória alocada para a lista encadeada

void menuListaEstatica();
void menuListaEncadeada();

int main() {
    int opcao;

    do {
        printf("\n--- MANIPULAÇÂO DE LISTAS (TEXTO) ---\n");
        printf("1. Lista Estatica\n");
        printf("2. Lista Encadeada\n");
        printf("0. Sair do Programa\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                menuListaEstatica();
                break;
            case 2:
                menuListaEncadeada();
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida! Tente novamente.\n");
        }
    } while (opcao != 0);

    return 0;
}
void menuListaEstatica() {
    ListaEstatica lista;
    inicializarListaEstatica(&lista);
    
    int opcao;
    char texto[MAX_STR_LEN];

    do {
        printf("\n--- MENU LISTA ESTATICA ---\n");
        printf("1. Inserir Texto\n");
        printf("2. Remover Texto\n");
        printf("3. Listar Textos\n");
        printf("0. Voltar ao Menu Principal\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        getchar(); // Limpa o buffer de entrada

        switch (opcao) {
            case 1:
                printf("Digite o texto para inserir: ");
                fgets(texto, MAX_STR_LEN, stdin);
                texto[strcspn(texto, "\n")] = '\0'; // Remove a nova linha
                inserirListaEstatica(&lista, texto);
                break;
            case 2:
                printf("Digite o texto para remover: ");
                fgets(texto, MAX_STR_LEN, stdin);
                texto[strcspn(texto, "\n")] = '\0'; // Remove a nova linha
                removerListaEstatica(&lista, texto);
                break;
            case 3:
                listarListaEstatica(&lista);
                break;
            case 0:
                printf("Voltando ao menu principal...\n");
                break;
            default:
                printf("Opcao invalida! Tente novamente.\n");
        }
    } while (opcao != 0);
}

void menuListaEncadeada() {
    ListaEncadeada lista;
    inicializarListaEncadeada(&lista);
    
    int opcao;
    char texto[MAX_STR_LEN];

    do {
        printf("\n--- MENU LISTA ENCADEADA ---\n");
        printf("1. Inserir Texto\n");
        printf("2. Remover Texto\n");
        printf("3. Listar Textos\n");
        printf("0. Voltar ao Menu Principal\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        getchar(); // Limpa o buffer de entrada

        switch (opcao) {
            case 1:
                printf("Digite o texto para inserir: ");
                fgets(texto, MAX_STR_LEN, stdin);
                texto[strcspn(texto, "\n")] = '\0'; // Remove a nova linha
                inserirListaEncadeada(&lista, texto);
                break;
            case 2:
                printf("Digite o texto para remover: ");
                fgets(texto, MAX_STR_LEN, stdin);
                texto[strcspn(texto, "\n")] = '\0'; // Remove a nova linha
                removerListaEncadeada(&lista, texto);
                break;
            case 3:
                listarListaEncadeada(lista);
                break;
            case 0:
                liberarListaEncadeada(&lista); // Libera a memória alocada para a lista encadeada antes de sair
                printf("Voltando ao menu principal...\n");
                break;
            default:
                printf("Opcao invalida! Tente novamente.\n");
        }
    } while (opcao != 0);
}   
// ------------------------------------------------------------------------------
// Implementação das funções para Lista Estática
// ------------------------------------------------------------------------------

void inicializarListaEstatica(ListaEstatica *lista) {
    lista->quantidade = 0;
}

void inserirListaEstatica(ListaEstatica *lista, const char *texto) {
    if (lista->quantidade == TAM_MAX) {
        printf("Error: Lista cheia! Nao e possivel inserir.\n");
        return;
    }
    
    strcpy(lista->dados[lista->quantidade], texto);
        
    lista->quantidade++; 
    printf("Texto \"%s\" inserido com suceosso.\n", texto);
    
}

void removerListaEstatica(ListaEstatica *lista, const char *texto) {
    int i, pos = -1;

    for (i = 0; i < lista->quantidade; i++) {
        if (strcmp(lista->dados[i], texto) == 0) {
            pos = i;
            break;
        }
    }

    if (pos == -1) {
        printf("Erro: Texto \"%s\" nao encontrado na lista.\n", texto);
        return;
    }

    for (i = pos; i < lista->quantidade - 1; i++) {
        strcpy(lista->dados[i], lista->dados[i + 1]);
    }

    lista->quantidade--;
    printf("Texto \"%s\" removido com sucesso.\n", texto);
}

void listarListaEstatica(const ListaEstatica *lista) {
    if (lista->quantidade == 0) {
        printf("A lista estatica esta vazia.\n");
        return;
    }

    printf("Itens da lista estatica: [ ");
    for (int i = 0; i < lista->quantidade; i++) {
        printf("\"%s\" ", lista->dados[i]);
    }
    printf("]\n");
}

// ------------------------------------------------------------------------------
// Implementação das funções para Lista Encadeada
// ------------------------------------------------------------------------------

void inicializarListaEncadeada(ListaEncadeada *lista) {
    *lista = NULL;
}

void inserirListaEncadeada(ListaEncadeada *lista, const char *texto) {
    No* novoNo = (No*)malloc(sizeof(No));
    if (novoNo == NULL) {
        printf("Erro: Falha na alocacao de memoria para o no!\n");
        return;
    }
    novoNo->dado = (char*)malloc(strlen(texto) + 1);

    if (novoNo->dado == NULL) {
        printf("Erro: Falha na alocacao de memoria para o dado!\n");
        free(novoNo); // Libera o nó alocado que ja foi alocado
        return;
    }

    strcpy(novoNo->dado, texto); 

    novoNo->proximo = *lista; // O novo nó aponta para o início da lista
    *lista = novoNo; // O início da lista agora é o novo nó
    printf("Texto \"%s\" inserido com sucesso.\n", texto);
}

void removerListaEncadeada(ListaEncadeada *lista, const char *texto) {
    No* atual = *lista;
    No* anterior = NULL;

    while (atual != NULL && strcmp(atual->dado, texto) != 0) {
        anterior = atual;
        atual = atual->proximo;
    }

    if (atual == NULL) {
        printf("Erro: Texto \"%s\" nao encontrado na lista.\n", texto);
        return;
    }

    if (anterior == NULL) {
        *lista = atual->proximo; // O nó a ser removido é o primeiro
    } else {
        anterior->proximo = atual->proximo; // O nó anterior aponta para o próximo  
    }

    free(atual->dado); // Libera a memória alocada para a string
    free(atual); // Libera a memória alocada para o nó
    printf("Texto \"%s\" removido com sucesso.\n", texto);
}

void listarListaEncadeada(const ListaEncadeada lista) {
    No* temp = lista;

    if (temp == NULL) {
        printf("A lista encadeada esta vazia.\n");
        return;
    }

    printf("Itens da lista encadeada: [ ");
    
    while (temp != NULL) {
        printf("\"%s\" ", temp->dado);
        temp = temp->proximo;
    }
    printf("]\n");
}

void liberarListaEncadeada(ListaEncadeada *lista) {
    No* atual = *lista;
    No* proximo;

    while (atual != NULL) {
        proximo = atual->proximo; // Armazena o próximo nó
        free(atual->dado); // Libera a memória alocada para a string
        free(atual); // Libera a memória alocada para o nó
        atual = proximo; // Move para o próximo nó
    }

    *lista = NULL; // Define a lista como vazia
}