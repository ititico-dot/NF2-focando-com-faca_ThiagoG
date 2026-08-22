# Respostas comentadas — Lista NF2 (Estruturas de Dados em C)

Material de estudo: cada exercício traz **o que o enunciado pede**, **como pensar** e **a resposta / código**.  
Os programas completos estão nas pastas `exercicio01_alunos/` … e nos arquivos `ex08`–`ex23` em `solucoes/`.

---

## Como estudar com este arquivo

1. Tente resolver sozinho antes de olhar a resposta.  
2. Compare sua ideia com a seção **Como chegou**.  
3. Compile o `.c` correspondente e teste casos de borda (lista vazia, pilha cheia, busca que não acha).

---

# Exercício 01 — Cadastro de Alunos

**Pedido:** `struct Aluno` + vetor; cadastrar, listar, buscar por matrícula, maior nota.

**Como chegou:** um aluno é um *registro* (vários campos de tipos diferentes) → `struct`. Vários alunos de tamanho limitado → vetor de structs e um contador `n`. Busca e “maior nota” são laços `O(n)` percorrendo o vetor.

**Resposta (ideia das operações):**

- Cadastrar: preenche `alunos[n]` e faz `n++` (se `n < MAX`).  
- Listar: `for (i = 0; i < n; i++)` imprime os campos.  
- Buscar: compara `alunos[i].matricula` com o valor pedido.  
- Maior nota: guarda o índice do maior `alunos[i].nota`.

Código: `exercicio01_alunos/main.c`.

---

# Exercício 02 — Sistema de Produtos

**Pedido:** cadastro, listagem, busca por código, valor total do estoque.

**Como chegou:** mesmo padrão do exercício 1. Valor total = soma de `preco * quantidade` de cada produto.

**Fórmula:**  
`totalEstoque = Σ preco[i] * quantidade[i]`

Código: `exercicio02_produtos/main.c`.

---

# Exercício 03 — Lista de compras (lista encadeada)

**Pedido:** `inserir`, `remover`, `buscar`, `listar` com nós dinâmicos.

**Como chegou:** cada item aponta para o próximo (`prox`). Inserir no início é `O(1)`: novo nó aponta para a cabeça antiga e vira a nova cabeça. Remover exige achar o nó e religar o anterior. Sem vetor de tamanho fixo.

Estrutura:

```
[Arroz|2|*] → [Leite|1|*] → NULL
```

Código: `exercicio03_lista_encadeada/main.c`.

---

# Exercício 04 — Pilha de livros (LIFO)

**Pedido:** `push`, `pop`, `top`, `isEmpty` com vetor.

**Como chegou:** “último que entra é o primeiro que sai”. `topo` começa em `-1` (vazia).  
`push`: `topo++` e grava no índice.  
`pop`: lê `livros[topo]` e `topo--`.  
`top`: só olha `livros[topo]`.  
`isEmpty`: `topo == -1`.

Exemplo do enunciado: A, B, C → remove C, B, A.

Código: `exercicio04_pilha/main.c`.

---

# Exercício 05 — Fila de atendimento (FIFO)

**Pedido:** `enfileirar`, `desenfileirar`, `frente`, `listar`.

**Como chegou:** “primeiro que chega é o primeiro atendido”. Dois índices: `inicio` (quem sai) e `fim` (próxima posição livre).  
Ana, João, Maria → atende Ana, depois João, depois Maria.

Código: `exercicio05_fila/main.c`.

---

# Exercício 06 — Agenda de contatos

**Pedido:** cadastrar, buscar por nome, ordenar alfabeticamente, remover.

**Como chegou:**

- Busca: percorre comparando `strcmp(nome, contatos[i].nome)`.  
- Ordenação: bubble/selection com `strcmp` (ordem lexicográfica).  
- Remoção: acha o índice e “puxa” os elementos seguintes (`contatos[j] = contatos[j+1]`), decrementa `n`.

Código: `solucoes/ex06_agenda.c`.

---

# Exercício 07 — Controle de notas

**Pedido:** média, maior, menor, quantidade de aprovados.

**Como chegou:** um único laço:

- `soma += nota[i]` → média = `soma / n`  
- se `nota[i] > maior` atualiza  
- se `nota[i] < menor` atualiza  
- se `nota[i] >= 7` (critério usual) incrementa aprovados  

Complexidade: `O(n)`.

Código: `solucoes/ex07_notas.c`.

---

# Exercício 08 (primeira lista) — Comparação de algoritmos

### Busca linear

Percorre do índice 0 até `n-1`. Pior caso: elemento no fim ou ausente → **O(n)**.  
Não exige vetor ordenado.

### Busca binária

Vetor **ordenado**. Compara com o meio: descarta metade a cada passo → **O(log n)**.

**Como chegou:** se a cada passo o espaço de busca vira metade, depois de k passos resta 1 elemento: `n / 2^k ≈ 1` ⇒ `k ≈ log₂ n`.

Código: `solucoes/ex08_buscas.c`.

---

# Exercício 8 (recapitulação) — Struct Filme

**Resposta:**

```c
typedef struct {
    char titulo[100];
    int ano;
    int duracao; /* minutos */
} Filme;
```

**Como chegou:** título é texto → `char[]`; ano e duração são inteiros. `typedef` cria o nome `Filme` para não repetir `struct`.

---

# Exercício 9 — Maior elemento de um vetor

```c
int maior(int v[], int n) {
    int m = v[0];
    for (int i = 1; i < n; i++)
        if (v[i] > m) m = v[i];
    return m;
}
```

**Como chegou:** assume o primeiro como campeão e desafia os demais. Precisa de pelo menos 1 elemento.

---

# Exercício 10 — Teste de mesa

Código: `v = {2,4,6,8,10}`, `soma = 0`, `soma += v[i]` para `i = 0..4`.

A tabela do enunciado tem um **erro de preenchimento** na linha `i=1` (colocaram `v[i]=6` e `soma=4`). O correto é:

| i | v[i] | soma (após somar) |
|---|------|-------------------|
| 0 | 2    | 0+2 = **2**       |
| 1 | 4    | 2+4 = **6**       |
| 2 | 6    | 6+6 = **12**      |
| 3 | 8    | 12+8 = **20**     |
| 4 | 10   | 20+10 = **30**    |

**Saída final da soma:** `30` (é a soma de uma PA: `5 * (2+10)/2 = 30`).

---

# Exercício 11 — Identificação de erros

```c
int v[4] = {8,5,3,9};
for (int i = 0; i <= 4; i++)  /* ERRO */
    printf("%d ", v[i]);
```

**Erro:** vetor de 4 posições tem índices **0, 1, 2, 3**. O laço com `i <= 4` acessa `v[4]` → **estouro de índice** (comportamento indefinido).

**Correção:** `for (int i = 0; i < 4; i++)`

Regra: em C, laço em vetor de tamanho `n` é quase sempre `i < n`, nunca `i <= n`.

---

# Exercício 12 — Complexidade linear

```c
for (int i = 0; i < n; i++)
    printf("%d", i);
```

**Resposta:** **O(n)** (linear).

**Como chegou:** o corpo executa exatamente `n` vezes. Se `n` dobra, o tempo dobra. Constantes (o `printf`) não mudam a classe assintótica.

---

# Exercício 13 — Complexidade quadrática

```c
for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
        printf("*");
```

**Resposta:** **O(n²)**.

**Como chegou:** para cada um dos `n` valores de `i`, o laço interno roda `n` vezes → `n * n = n²` impressões. Laços **aninhados independentes** de `0..n-1` geram produto das iterações.

---

# Exercício 14 — Inserção no início da lista

Lista: `12 → 18 → 25 → NULL`  
Inserir `8` no início.

**Passos (ponteiros):**

1. Alocar nó `novo` com valor 8.  
2. `novo->prox = inicio` (aponta para o 12).  
3. `inicio = novo`.

**Resultado:** `8 → 12 → 18 → 25 → NULL`

Complexidade: **O(1)** — não percorre a lista.

---

# Exercício 15 — Inserção no final

Lista: `5 → 10 → 15 → NULL`  
Inserir `20` no fim.

**Passos:**

1. Percorrer até o nó cujo `prox == NULL` (o 15).  
2. `ultimo->prox = novo` (20), `novo->prox = NULL`.

**Resultado:** `5 → 10 → 15 → 20 → NULL`

Complexidade: **O(n)** sem ponteiro para o fim; **O(1)** se a lista guardar `fim`.

---

# Exercício 16 — Operações com pilha

Início: `[]` (topo à direita)

| operação | pilha     | topo |
|----------|-----------|------|
| push(2)  | [2]       | 2    |
| push(7)  | [2, 7]    | 7    |
| push(9)  | [2, 7, 9] | 9    |
| pop()    | [2, 7]    | 7    |
| push(15) | [2, 7, 15]| 15   |

1. **Estado final:** `2` no fundo, depois `7`, **15 no topo**.  
2. **Topo:** **15**

Lembrete LIFO: o `9` saiu no `pop`; o `15` entrou por cima do `7`.

---

# Exercício 17 — Implementação de `push`

```c
int pilha[100];
int topo = -1;

void push(int x) {
    if (topo == 99) { /* cheia */
        printf("Overflow\n");
        return;
    }
    topo++;
    pilha[topo] = x;
}
```

**Como chegou:** `topo` aponta para o último ocupado. Incrementa primeiro, depois grava. Checar overflow evita escrever fora do vetor.

---

# Exercício 18 — Implementação de `pop`

```c
int pop(void) {
    if (topo == -1) {
        printf("Underflow\n");
        return -1; /* sentinela; em TAD real use código de erro */
    }
    int valor = pilha[topo];
    topo--;
    return valor;
}
```

**Como chegou:** o valor a remover está em `pilha[topo]`. Decrementar `topo` “libera” a posição (não precisa apagar o dado).

---

# Exercício 19 — Operações com fila

FIFO; frente à esquerda:

| operação          | fila                    |
|-------------------|-------------------------|
| enqueue(Ana)      | Ana                     |
| enqueue(Carlos)   | Ana, Carlos             |
| enqueue(Pedro)    | Ana, Carlos, Pedro      |
| dequeue()         | Carlos, Pedro           |
| enqueue(Lucas)    | Carlos, Pedro, Lucas    |

**Estado final:** **Carlos → Pedro → Lucas** (frente = Carlos).

Ana saiu porque chegou primeiro.

---

# Exercício 20 — Debug em vetores

```c
int soma = 0;
for (int i = 1; i < 5; i++)
    soma += v[i];
```

**Problemas:**

1. O laço começa em `i = 1` → **ignora `v[0]`**.  
2. Se `v` tem tamanho 5, `i < 5` está ok; se tem tamanho 4, `i` chega a 4 e estoura. O padrão correto depende de `n`.

**Correção usual** (vetor de `n` elementos, somar todos):

```c
int soma = 0;
for (int i = 0; i < n; i++)
    soma += v[i];
```

---

# Exercício 21 — Busca sequencial

```c
for (int i = 0; i < n; i++)
    if (v[i] == x)
        return i;
```

1. **Algoritmo:** busca sequencial (linear).  
2. **Complexidade:** melhor caso **O(1)** (está na posição 0); pior / médio **O(n)**. Em notação grande-O padrão da disciplina: **O(n)**.

Não precisa de vetor ordenado.

---

# Exercício 22 — Lista ligada × vetor

**Duas vantagens da lista ligada (e por quê):**

1. **Tamanho dinâmico:** aloca nó a nó com `malloc`; não precisa declarar `MAX` antecipadamente. Vetor tem capacidade fixa (ou precisa realocar e copiar tudo).  
2. **Inserção/remoção no meio sem deslocar elementos:** só ajusta ponteiros **O(1)** depois de achar o ponto. No vetor, inserir no meio desloca `O(n)` itens.

Outras válidas: não exige memória **contígua**; inserir no início é **O(1)**.

**Desvantagem** (para não errar na prova): acesso ao k-ésimo é **O(k)**, não `v[k]` em O(1); gasta memória extra no ponteiro.

---

# Exercício 23 — TAD Série (Leibniz / π)

**Ideia do TAD:** separar *dados* (`quantidade`, `soma`, `termos[]`) das *operações* (`inicializar`, `calcularLeibniz`, `calcularPi`, `imprimirSerie`).

**Termo k (k = 0,1,2,…):**  
`termos[k] = (-1)^k / (2k + 1)`  
`soma = Σ termos[k]`  
`π ≈ 4 * soma`

Exemplo 5 termos: `1`, `-1/3`, `1/5`, `-1/7`, `1/9`.

### Análise de complexidade (do enunciado)

1. **Geração dos termos:** um laço de `quantidade` iterações → **O(n)**, com `n` = número de termos.  
2. **100 vs 1 milhão:** mesma classe **O(n)**; o tempo cresce **linearmente** (1 milhão ≈ 10⁴ vezes 100). A constante é pequena (soma e divisão).  
3. **Vetor `termos[1000]`:** **não** serve para 1 milhão de termos (estouro). Para n grande: alocar `double *termos = malloc(n * sizeof(double))` ou **não guardar** todos os termos, só ir somando (mais econômico).

**Taylor de eˣ (desafio):**  
`termo_0 = 1`, `termo_{k} = termo_{k-1} * x / k`  
`e^x ≈ Σ x^k / k!`

Código: `solucoes/ex23_serie.c`.

---

# Mapa mental rápido (prova)

| Estrutura | Ordem     | Inserir início | Acesso i-ésimo | Uso típico        |
|-----------|-----------|----------------|----------------|-------------------|
| Vetor     | índice    | O(n)           | O(1)           | busca, notas      |
| Lista     | ponteiros | O(1)           | O(n)           | tamanho variável  |
| Pilha     | LIFO      | push O(1)      | só o topo      | desfazer, ()      |
| Fila      | FIFO      | fim O(1)       | só a frente    | atendimento       |

Índices de vetor: **0 … n-1**. Laço: **`i < n`**.

Complexidade: 1 laço → O(n); 2 laços aninhados n×n → O(n²); dividir ao meio → O(log n).
