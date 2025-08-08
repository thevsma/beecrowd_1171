#include <stdio.h>

void trocar(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int particionar(int arr[], int ini, int fim) {
    int pivo = arr[fim], i = (ini - 1);

    for (int j = ini; j < fim; j++) {
        if (arr[j] <= pivo) {
            i++;
            trocar(&arr[i], &arr[j]);
        }
    }

    trocar(&arr[i + 1], &arr[fim]);
    return i + 1;
}

void quicksort(int arr[], int ini, int fim) {
    if (ini < fim) {
        int indice_pivo = particionar(arr, ini, fim);
        quicksort(arr, ini, indice_pivo - 1);
        quicksort(arr, indice_pivo + 1, fim);
    }
}

int main() {
    int N = 0, aux = 0, buffer[20];
    scanf("%d", &N);

    int arr[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }

    quicksort(arr, 0, N - 1);
    int pos = 0;
    while (1) {
        if (pos == N) break;
        while (arr[pos] == arr[pos - 1]) pos++;
        int count = 0;
        aux = arr[pos];
        for (int i = 0; i < N; i++) {
            if (arr[i] == aux) {
                count++;
            }
        }
        printf("%d aparece %d vez(es)\n", aux, count);
        pos++;
    }

    return 0;
}