#include <stdio.h>
#include <stdlib.h>

int main() {
    int num_points;
    scanf("%d", &num_points);

    float *fees = (float *)malloc(num_points * sizeof(float));

    for (int i = 0; i < num_points; i++) {
        scanf("%f", &fees[i]);
        if (fees[i] < 0) {
            printf("Error: Fee cannot be negative\n");
            free(fees);
            return 1;
        }
    }

    float total_profit = 0;
    for (int i = 0; i < num_points; i++) {
        total_profit += fees[i];
    }

    printf("%.2f\n", total_profit);

    free(fees);

    return 0;
}
