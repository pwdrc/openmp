# Introdução ao openmp (minicurso Santos Dumont)

* OBS.: remover mv\*.exec $(SCRATCH)

## História

Até 2004 -> single core

A partir de 2005 -> diminuir a frequência e aumentar a quantidade de cores


## Por que programação paralela?

* Reduzir o tempo para a solução do problema
* Resolver problemas mais complexos e de maior dimensão

**Outros**
* recursos computacionais subaproveitados
* ultrapassar limitações de memória e físicos (de aumento de frequência do processador)

## Alternativas

* linguagem para programas paralelos
* hardware para extrair paralelismo
* compilador com suporte a paralelização (automática x anotações no código sequencial)
* recursos do sistema operacional (memória compartilhada - threads; memória distribuída - SPMD)
* estrutura de dados para definir o paralelismo
* abstração de alto nível - objetos, funções etc.

## Principais modelos

### Memória Compartilhada (OpenMP, Cilk, CUDA)

* processos ou threads
* comunicação por memória compartilhada

**Funcionamento**

* um processo e muitas threads
* as threads interagem através de i/o com o espaço de endereçamento compartilhado
* a sincronização garante a consistência dos resultados

### Memória Distribuída (MPI)

* processos distribuídos
* decomposição do domínio em granularidade grossa
* comunicação e sincronização por troca de mensagens

## Fatores de limitação de desempenho

* código sequencial
* concorrência/paralelismo
* comunicação - há sempre um custo associado à troca de informação
* sincronização
* granularidade - o número e o tamanho das tarefas
* balanceamento de cargo - ter os processadores majoritariamente ocupadas durante toda a execução é decisivo para o desempenho global do sistema


## OpenMP

### Sintaxe básica

```
#include <omp.h>

#pragma omp construct [clause [clause]...]

// exemplo

#pragma omp parallel private(var1, var2) shared(var3, var4)
```

**Notas de compilação**

gcc ou icc:

```
gcc -fopenmp foo.c
icc -qopenmp foo.c
export OMP_NUM_THREADS=<num> // por padrão é o nro de processadores virtuais do sistema
./out
```
