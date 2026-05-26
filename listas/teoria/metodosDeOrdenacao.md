### MÉTODOS DE ORDENAÇÃO

- **Bubble Sort** Ordenação por Bolha
    Facilita a implementação, mas faz muitas trocas desnecessárias

- **Insertion Sort** Ordenação por Inserção
    É ideal para listas quase ordenadas

- **Selection Sort** Ordenação por Seleção
    Faz menos trocas, mas mitas comparações

Não são os mais rapidos para grandes volumes de dados.

```C
void trocar(int* a, int* b){
    // 1. Guarda o valor apontado por 'a' em uma variável temporária.
    // O asterisco (*) é o operador de "desreferência", que acessa o valor no endereco.
    int temp = *a;

    // 2. O valor apontado por 'b' é copiado para o local apontado por 'a'.
    *a = *b;

    // 3. O valor que guardamos (original de 'a') é copiado para o local apontado por 'b'.
    *b = temp
}
```

### Bubble Sort 

A lógica dele é comparar elementos vizinho e troco-los se estiverem na ordem errada.
  Inicio                                   Final
| 5 | 3 | 1 | -> | 3 | 5 | 1| -> | 3 | 1 | 5 |

Aqui ele comparou o primeiro elemento com o segundo. Como o primeiro é maior que o segundo ele faz a troca.
Esse processo se repete varias e varias vezes.

Pense em 5 bolas com esses valores.

5 - 1 - 4 - 2 - 8

Se compararmos a primeira bola com a segunda, o valor da primeira é maior então realizamos a troca

1 - 5 - 4 - 2 - 8

Proxima comparação 5 com 4. E como 5 é maior ficamos assim 

1 - 4 - 5 - 2 - 8

Continua 5 com 2

1 - 4 - 2 - 5 - 8

Agora 5 com 8. E como 5 é menor não fazemos nada. Isso foi a primeira passada. 
Note que 8 já está na sua posição final.

Agora famos repetir o processo. Só que agora eu não preciso ir até o final. 

Então a segunda passada fica.

1 - 4 - 2 - 5 - 8
1 - 2 - 4 - 5 - 8 - Acabomos aqui porque 4 não é maior que 5. E 5 agora está no seu lugar, no final.

A lista já esta ordenada, então a lista iria dar mais algumas passadas sem fazer nada

```C
// FUNÇÃO BOBBLE SORT
void bubbleSort(int vetor[], int tamanho){
    // Laço exeterno: controla o número de passadas pelo vetor.
    // A cada passada 'i', o-i-esimo maior elemento "borbulha" para o lugar certo.
    for(int i = 0; i < tamanho; i++){
        
        // Laço interno: percorre o vetor comparando pares de vizinhos.
        // O limite (tamanho - 1 - i) é uma otimização: ele diminui a cada
        // passada, pois os maiores elementos já estão fixos no final
        for(int j = 0; j < tamanho - 1 - i; j++){

            // a condição de comparação: se o elemento for maior que o da direita...
            if(vetor[j] > vetor[j + 1]){
                // ...troca! Passamos os endereõs dos elementos para a função 'trocar'
                trocar(&vetor[j], &vetir[j + 1]);
            }
        }
    }
}
```

#### RESUMO

**BUBBLE SORT** - Pinto forte: simplicidade

Mas e sua eficiência?
Infelizmente, aqui ele não brilha tanto.
Para listas grandes ele se torna muito, muito lento.
Mas Por que?
Porque ele pode fazer muitas trocas.


