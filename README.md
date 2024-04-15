# Análise de Algoritmos de Ordenação

Este repositório contém implementações de diversos algoritmos de ordenação e scripts para analisar e visualizar o desempenho de cada um.
Os códigos dos algaritmos de ordenação foram usados a partir do repositório do professor Mateus Goldbarg contido neste link: https://github.com/mateusArnaudGoldbarg/ED/blob/main/ed.cpp

## Algoritmos Implementados

### Bubble Sort

O Bubble Sort é um algoritmo simples de ordenação que percorre o vetor diversas vezes, comparando elementos adjacentes e trocando-os se estiverem na ordem errada.

```cpp
void bubbleSort(vector<int>& v) {
    int n = v.size();
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (v[j] > v[j+1]) {
                swap(v[j], v[j+1]);
            }
        }
    }
}
```

### Selection Sort

O Selection Sort divide o vetor em duas partes: uma ordenada e outra não ordenada. Ele encontra o menor elemento da parte não ordenada e o coloca na parte ordenada.

```cpp
void selectionSort(vector<int>& v) {
    int n = v.size();
    for (int i = 0; i < n-1; i++) {
        int min_idx = i;
        for (int j = i+1; j < n; j++) {
            if (v[j] < v[min_idx]) {
                min_idx = j;
            }
        }
        swap(v[i], v[min_idx]);
    }
}
```

### Insertion Sort

O Insertion Sort constrói uma lista ordenada um elemento de cada vez, movendo elementos não ordenados para sua posição correta.

```cpp
void insertionSort(vector<int>& v) {
    int n = v.size();
    for (int i = 1; i < n; i++) {
        int key = v[i];
        int j = i - 1;
        while (j >= 0 && v[j] > key) {
            v[j+1] = v[j];
            j = j - 1;
        }
        v[j+1] = key;
    }
}
```
### Shell Sort

O Shell Sort é uma extensão do Insertion Sort que compara elementos distantes antes de realizar trocas, melhorando o desempenho do algoritmo.

```cpp
void shellSort(vector<int>& v) {
    int n = v.size();
    for (int gap = n/2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int temp = v[i];
            int j;
            for (j = i; j >= gap && v[j - gap] > temp; j -= gap) {
                v[j] = v[j - gap];
            }
            v[j] = temp;
        }
    }
}
```
 ### Quick Sort
 
O Quick Sort utiliza a estratégia de divisão e conquista para ordenar elementos. Ele escolhe um elemento como pivô e divide o vetor em duas partes, ordenando-as separadamente.

```cpp
int partition(vector<int>& v, int low, int high) {
    int pivot = v[high];
    int i = low - 1;
    for (int j = low; j <= high - 1; j++) {
        if (v[j] < pivot) {
            i++;
            swap(v[i], v[j]);
        }
    }
    swap(v[i + 1], v[high]);
    return i + 1;
}

void quickSort(vector<int>& v, int low, int high) {
    if (low < high) {
        int pi = partition(v, low, high);
        quickSort(v, low, pi - 1);
        quickSort(v, pi + 1, high);
    }
}
```

### Merge Sort

O Merge Sort também utiliza a estratégia de divisão e conquista, mas de uma forma diferente. Ele divide o vetor ao meio e ordena cada metade recursivamente, depois mescla as duas metades ordenadas.

```cpp
void merge(vector<int>& v, int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;
    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++) {
        L[i] = v[l + i];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = v[m + 1 + j];
    }

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            v[k] = L[i];
            i++;
        } else {
            v[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        v[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        v[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(vector<int>& v, int l, int r) {
    if (l >= r) {
        return;
    }
    int m = l + (r - l) / 2;
    mergeSort(v, l, m);
    mergeSort(v, m + 1, r);
    merge(v, l, m, r);
}
```

## Compilação e Execução

### Compilação

Para compilar os algoritmos, execute o seguinte comando:
```bash
g++ algorithms.cpp -o algorithms.exe
```

### Execução

Para executar os algoritmos e coletar dados de desempenho, execute:

```bash
./algorithms.exe
```
Este comando irá gerar um conjunto de dados que pode ser usado para gerar gráficos de desempenho.

OBS.: Dependendo do desempenho do seu computador, essa etapa pode demorar para compilar.

## Visualização de Desempenho

Para visualizar os dados coletados, execute:

```bash
python plot.py
```
Este script irá gerar gráficos de desempenho para cada algoritmo e um gráfico comparativo.

## Estrutura dos Arquivos

algorithms.cpp: Implementações dos algoritmos de ordenação.
- **algorithms.exe**: Executável gerado após a compilação do algorithms.cpp.
- **plot.py**: Script para coletar dados de desempenho e gerar gráficos.
- **Bubble Sort_plot.png**: Gráfico de desempenho para o Bubble Sort.
- **Selection Sort_plot.png**: Gráfico de desempenho para o Selection Sort.
- **Insertion Sort_plot.png**: Gráfico de desempenho para o Insertion Sort.
- **Shell Sort_plot.png**: Gráfico de desempenho para o Shell Sort_plot.
- **Quick Sort_plot.png**: Gráfico de desempenho para o Quick Sort_plot.
- **Merge Sort_plot.png**: Gráfico de desempenho para o Merge Sort_plot.
- **comparison_plot.png**: Gráfico comparativo de desempenho para todos os algoritmos.
- **execution_times.txt**: Este arquivo contém os tempos de execução medidos para cada algoritmo de ordenação para diferentes tamanhos de vetor.
- Cada linha representa um teste de execução com o seguinte formato:
  
  <algoritmo> <tamanho_do_vetor> <tempo_de_execução_em_microssegundos>
```mathematica
  O tempo de execução é medido em microssegundos para fornecer uma precisão adequada na comparação dos algoritmos. Os algoritmos incluídos são: Bubble Sort, Selection Sort, Insertion Sort, Shell Sort, Quick Sort e Merge Sort.
```

## Autores
- ADAIANE DA SILVA BRITO
- ALESANGELA BEZERRA DA FONSECA

