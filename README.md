# Análise de Algoritmos de Ordenação

Este repositório contém implementações de diversos algoritmos de ordenação e scripts para analisar e visualizar o desempenho de cada um.
Os códigos dos algaritmos de ordenação foram usados a partir do repositório do professor Mateus Goldbarg no repósitorio https://github.com/mateusArnaudGoldbarg/ED/blob/main/ed.cpp

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
