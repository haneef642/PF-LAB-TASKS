#include <stdio.h>
#include <stdlib.h>

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        int N;
        scanf("%d", &N);
        
        int *arr = (int *)malloc(N * sizeof(int));
        int freq[10002] = {0};

        for (int i = 0; i < N; i++) {
            scanf("%d", &arr[i]);
            freq[arr[i]]++;
        }

        int max_freq = 0, result = 10002;
        for (int i = 1; i <= 10001; i++) {
            if (freq[i] > max_freq || (freq[i] == max_freq && i < result)) {
                max_freq = freq[i];
                result = i;
            }
        }

        printf("%d\n", result);
        free(arr);
    }

    return 0;
}
