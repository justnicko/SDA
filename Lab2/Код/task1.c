#include <stdio.h>

int main()
{
    int n, sign = 1, op_counter = 0;
    double S = 0, P;
    op_counter += 2; // sign = 1, S = 0

    scanf("%d", &n);

    op_counter++; // i = 0
    for (int i = 0; i <= n; i++) {
        P = 1;
        op_counter += 2; // i <= n, P = 1

        op_counter++; // j = 1
        for (int j = 1; j <= 2 * i + 1; j++) {
            op_counter += 3; // j <= 2 * i + 1
            P *= 0.5 / j;
            op_counter += 3; // P = P * 0.5 / j
        }

        S += sign * P;
        op_counter += 3; // S = S + sign * P
        sign = -sign;
        op_counter += 3; // sign = -sign, i++
    }

    printf("Result: %.7f\n", S);
    printf("Total operations: %d\n", op_counter);


    return 0;
}
