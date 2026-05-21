### Round 1: A Organização na Memória

Vetor - Estrutura Sequencial
- Palavra-chave: contíguo

Quando declaro um vetor em C tipo

```C
int v[5] = {10,20,30,40,50}
```

Estamos dizendo para o computador. "Ei, reserva para mim cinco espaços de memória, um colado no outro, para guardar números inteiros"

Lista Encadeada
 - Palavra-chave: disperso ou fragmentado

Estão conectados de forma logica (Ponteiro)

> Vetor
> ganha em organização e previsibilidade na memória.

> Lista Encadeada
ganha em flexibilidade de alocação, pois não precisa de um grande bloco contíguo de memória.

### Round 2: Acesso aos Elementos

Vetor
- Se eu preciso pegar alguma coisa na posição três. Eu vou direto a esta posição e pego.

Lista Encadeadas
- Lenta: Se eu precisar pegar ao, por exemplo, no décimo elo, eu preciso percorrer todos os elos até chegar no décimo.

> Vetor
> Vitória esmagadora para o Vetor!
> Se sua aplicação precisa de acesso rápido a elementos por usa posição, o vetor é o campeão indiscutível.

### Round 3: Inserção e Remoção no meio da Estrutura

Vetor
- A rigidez se torna uma grande fraqueza. A operação é lenta. Para inserir um elemento no meio do vetor ele precisa copiar e deslocar todos os elementos. O que é muito custoso. 
O mesmo vale para remoção

Lista Encadeada
 - Operação é rapida e elegante
 Para inserir um novo elo entre eles, eu simplesmente abro o ele e encaixo o novo e refaço as conexões.

> Vetor
> operação é lenta

> Lista Encadeada
> Vitória clara para a Lista Encadeada!
> Se seu programa envolve muitas inserções e remoções no meio da coleção, a lista encadeada é a sua melhor amiga.

### Decisão final: Quem venceu a Batalha?

Responsta: Depende.

| Operação           | Vetor (Sequencial)    | Lista (Encadeada)       |
| ------------------ | --------------------- | ----------------------- |
| Acesso por Posição | Rápido                | Lento                   |
| Inserção/Remoção   | Lento                 | Rápida                  |
| Crescimento        | Limitado / Rígido     | Flexível / Dinâmico     |
| Uso de Memória     | Contíguo / Previsível | Fragmentado / Ponteiros |


