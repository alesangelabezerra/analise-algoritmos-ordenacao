import matplotlib.pyplot as plt

sizes = [10, 100, 1000, 10000, 100000, 1000000]
algorithms = ['Bubble Sort', 'Selection Sort', 'Insertion Sort',
              'Shell Sort', 'Quick Sort', 'Merge Sort']

times = {}
with open('execution_times.txt', 'r') as file:
    for line in file:
        algo, values_str = line.strip().split(':')
        values = [int(val) / 1000 for val in values_str.split(',')]
        times[algo] = values

# Gráficos individuais
for algo, values in times.items():
    plt.figure()
    plt.plot(sizes, values, marker='o', label=algo)
    plt.xlabel('Tamanho do Vetor (n) - Notação de Milhão')
    plt.ylabel('Tempo de Execução (milissegundos)')
    plt.title(f'Tempo de Execução - {algo}')
    plt.grid(True)
    plt.xscale('log')
    plt.yscale('log')
    plt.xticks(sizes, [str(size) for size in sizes])
    plt.yticks([0.1, 1, 10, 100, 1000, 10000], ['0.1', '1', '10', '100', '1000', '10000'])
    plt.legend()
    plt.savefig(f'{algo}_plot.png')
    plt.close()

# Gráfico comparando o tempo de execução de todos os algoritmos de ordenação
plt.figure()
for algo, values in times.items():
    plt.plot(sizes, values, marker='o', label=algo)

plt.xlabel('Tamanho do Vetor (n) - Notação de Milhão')
plt.ylabel('Tempo de Execução (milissegundos)')
plt.title('Comparação de Desempenho - Algoritmos de Ordenação')
plt.grid(True)
plt.xscale('log')
plt.yscale('log')
plt.xticks(sizes, [str(size) for size in sizes])
plt.yticks([0.1, 1, 10, 100, 1000, 10000], ['0.1', '1', '10', '100', '1000', '10000'])
plt.legend()
plt.savefig('comparison_plot.png')
plt.close()
