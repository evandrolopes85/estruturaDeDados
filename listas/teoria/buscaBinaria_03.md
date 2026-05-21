### Busca Binária 

Em vetores ordenados
- Ela usa uma abordagem de divisão e conquista

Vamos ver como essa técnica é utilizada para fazer uma busca que duraria minutos ser feita em segundos.

Regra   
- SÓ funciona se os dados estiverem ordenados.

Como funciona:
- O elemento do meio é o que estou procurando?
    Se sim Bingo! Acabou a busca.
- O elemento que eu procuro é maior que o do meio?
    Se sim, eu posso com 100% de certeza ignora a primeira metada da lista. (O elemento não pode estar lá)
- O elemento que eu procuro pe menor que o do meio?
    Se sim, eu posso com 100% de certeza ignora a segunda metada da lista. (O elemento não pode estar lá)

E assim repetimos o mesmo processo com a metáde que sobrou. Até achar o elemento.

Passos:
> INICIO - Marca o começo da seção que ainda estamos considerando.

> FIM - marca o final dessa mesma seção

> MEIO - É calculado a cada passo, sendo o ponto central entre inicio e fim.

```C
// Descrição: Procura por um 'valor' em um 'vetor' ORDENADO de um 'tamanho específico.
// Pré-requisito: o 'vetor' DEVE estar em ordem crescente
// Retorno: - o índice do valor, se encontrado. -1, se o valor não estiver no vetor.
int buscaBinaria(int vetor[], int tamanho, int valor){
    int inicio = 0;
    int fim = tamanho -1;

    // O loop continua enquanto a "fatia" de busca for válida (inicio <= fim).
    while(inicio <= fim){
        // int meio = (inicio + fim) / 2; Forma comum, mas pode dar overflow com números muito grandes.

        // Forma mais segura para calcular o meio, evitando overflow:
        int meio = inicio + (fim - inicio) / 2;

        // 1. Se i vakir estuver exatamente no meio, encontramos!
        if(vetor[meio] == valor){
            return meio; // Retorna o índice onde o valor foi encontrado.
        }

        // 2. Se o valor no meio for menor que o valor buscado,
        // significa que o nosso alvo só pode estar na metade direita (maior)
        else if(vetor[meio] < valor){
            inicio = meio + 1; // Descatamos a metade esquerda.
        }
        // 3. Se o valor no meio for maior que o valor buscado,
        // significa que o nosso alvo só pode estar a metade esquesda (menor).
        else {
            fim = meio - 1; // Descatamos a metade direita
        }
    }

    // Se o loop terminar, significa que 'inicio' ultrapassa 'fim',
    // e o valor não foi encontrado no vetor
    return -1;
}
```

### O que torna a busca binária tão especial é o:

#### Desempenho

Se eu tenho uma lista de 16 ELEMENTOS, no pior caso, quantas vezes eu preciso dividir ao meio?

- [x] 1 comparação: sobram 8
- [x] 2 comparação: sobram 4
- [x] 3 comparação: sobram 2
- [x] 4 comparação: sobra 1

Então no máximo 4 passos, eu entro o número!

Se e tenho uma lista de 1000 ELEMENTOS?
- Busca Linear: até 1000 passos;
- Busca Binária: 10 comparações
    -   2^10^ da em torno de 1024. Isso significa que no máximo 10 comparações a busca resolve o problema

Se e tenho uma lista de 1 milhão ELEMENTOS?
- Busca Linear: até 1 milhão passos;
- Busca Binária: 20 comparações
    -   2^20^ da em torno de 1 Milhão. Isso significa que no máximo 20 comparações a busca resolve o problema

### RESUMO

#### Busca Binária
- **O que é?** Um algoritmo de busca que funciona em dados ordenados
- **Como funciona?** Pelo princípio de divisão e conquista: compara com o elemento do meio e descarta metade da lista a cada passo
- **Por que é incrível** Seu desempenho é o que a torna absurdamente rápida para listas grandes, transformando um problema que poderia ser intratável em algo trivial para o computador.
