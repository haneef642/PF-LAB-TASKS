#include <stdio.h>
#include <stdlib.h>

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        int N;
        scanf("%d", &N);
        
        int *arr = (int *)malloc(N * sizeof(int));
        for (int i = 0; i < N; i++) {
            scanf("%d", &arr[i]);
        }

        int choice, pos, value;
        while (1) {
            printf("1. Insert\n2. Delete\n3. Exit\n");
            scanf("%d", &choice);

            if (choice == 1) {
                scanf("%d %d", &pos, &value);
                if (N == pos) {
                    arr = (int *)realloc(arr, (N + 1) * sizeof(int));
                    arr[N] = value;
                    N++;
                } else {
                    arr = (int *)realloc(arr, (N + 1) * sizeof(int));
                    for (int i = N; i > pos; i--) {
                        arr[i] = arr[i - 1];
                    }
                    arr[pos] = value;
                    N++;
                }
            } else if (choice == 2) {
                scanf("%d", &pos);
                for (int i = pos; i < N - 1; i++) {
                    arr[i] = arr[i + 1];
                }
                N--;
                arr = (int *)realloc(arr, N * sizeof(int));
            } else {
                break;
            }

            for (int i = 0; i < N; i++) {
                printf("%d ", arr[i]);
            }
            printf("\n");
        }

        free(arr);
    }

    return 0;
}
