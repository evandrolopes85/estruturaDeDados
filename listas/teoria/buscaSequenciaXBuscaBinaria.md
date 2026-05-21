### BUSCA SEQUENCIAL X BUSCA BINÁRIA

#### Busca Sequencial

Detetive Osbtinado
- Para encontrar algo, vou olhar tudo, um de cada vez, do começo ao fim.

Ponto forte: **Simplicidade**

#### Busca Binária
Estrategista Genial
- Porque olhar tudo se eu posso eliminar metade do problema a cada passo?

Ponto forte: **Velocidade**

### Requisito de Ordenação

> **Busca Sequencial**
> "Não me importo! Traga seus dados bagunçados, eu dou um jeito."

> **Busca Binária**
> "Sem ordem, sem conversa. Se os dados não estiverem organizados, eu não posso usar minha estratégia e vou dar a resposta errada."

#### Facilidade de Implementação

> **Busca Sequencial**
> Um simples laço for.
É um dos primeiros algoritmos que aprendemos. Super fácil.

> **Busca Binária**
>Exige um pouco mais de lógica, com o controle das variáveis inicio, fim e meio. É facil de errar se você não prestar atenção.

#### Desempenho em Listas Grandes

> **Busca Sequencial (Pior caso)**: Pode precisar fazer 1 milhão de comparações.

> **Busca Binária (Pior caso)**: Precisa de no máximo... 20 comparações

#### Aplicabilidade em Listas Encadeadas

> **Busca Sequencial**: Sem problemas! Ela pode "pular" de nó em nó, seguindo os ponteiros, do início ao fim.

> **Busca Binária**: Aqui ela tropeça. A busca binária precisa de acesso instantâneo ao elemento do "meio"

#### RESUMO
**Use a Busca Sequencial (O Detetive Obstinado) quando:**
- [x] Seus dados estão desordenados e você não pode ou não quer ordená-los.
- [x] A lista é pequena. A simplicidade dela compensa, e a diferença de velocidade não será notada.
- [x] Você está usando uma lista encadeada.

**Use a Busca Binária (A Estragegista Genial) quando:**
- [x] Seus dados estão (ou podem ser) ordenados
- [x] A lista é grande e o desempenho é crítico
- [x] Você está usando um vetor

