## BUSCA LINEAR EM VETORES E LISTA ENCADEADA

#### BUSCA LINEAR

Uma busca feita em linha, em sequência.

A Lista pode estar toda bagunçada que não tem problema.

#### BUSCA LINEAR EM LISTA ESTÁTICA (VETOR)

```c
// ---- A SUA FUNÇÂO ----
// Descrição: Procura por um 'valor' em um array 'lista' de um determinado 'tamanho'.
// Retorno:
// - O índice (posíção) da primeira ocorrência do valor, se encontrado.
// - -1, se o valor não estiver na lista.
int buscaLinear(int lista[], int tamanho, int valor){
    // Começamos um loop do início (índice 0) até o fim da lista
    for(int i = 0; i < tamanho; i++){
        if(lista[i] == valor){
            // Se encontrarmos, retornamos a posição (índice) onde ele está!
            return i;
        }
    }

    // Se o loop terminar e não encontrarmos nada, retornamos -1
    return -1
}
```
#### BUSCA LINEAR EM LISTA ENCADEADA (PONTEIRO)

A busca funciona da mesma forma, pulando de nó em nó até encontrar o item.

```c
// ---- A SUA FUNÇÂO ---
// Descrição: Procura por um 'valor' em uma lista ligada a partid do 'inicio'.
// Retorno:
// - A posição (índice baseado em zero) do valor, se encontrado.
// - -1, se o valor não estiver na lista;
int buscaLinearLista(struct No* inicio, int valor){
    int pos = 0; // Um contador para sabermos a posição (ínidice 0, 1, 2, ...)
    struct No* atual = inicio; // Nosso "ponteiro viajante"

    // Enquanto não chegarmos ao fim da lista (NULL) ...
    while(atual != NULL){
        // Verificamos se o dado do nó atual é o que procuramos
        if(atual->dado == valor){
            return pos;
        }
        // Se não for, pulamos para o próximo nó...
        atual = atual->proximo;
        // ...e incrementamos nosso contador de posição.
        pos++;
    }
    // se o while acabar, significa que percorremos toda a lista e não encontramos.
    return -1;
}
```
#### BUSCA LINEAR = DESEMPENHO

- Melhor caso
    - Quando achamos o elemento na primeira posição
- Caso médio
    - É mais provavel que o elemento esteja no meio da lista, então precisamos percorrer metada da lista para encontralo.
- Pior caso
    - O elemete estiver na ultima posição ou pior ainda, percorrer toda a lista e não acharmos os elementos.

#### RESUMO

 - Busca Linear
    - Busca Linear é uma técnica essencial, em especial quando lidamos com listas ***não ordenadas.***
    - [x] Vantagem - simplicidade
    - [x] Característica - funciona em lista não ordenadas
    - [x] Desvantagem - Desempenho: No pior caso é diretamente proporcional ao tamanho da lista. O que a torna ineficiente para conjuto de dados muito grande.


