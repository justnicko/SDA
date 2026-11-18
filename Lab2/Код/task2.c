#include <stdio.h>

int main()
{
    int n, j = 2, sign = 1, op_counter = 0;;
    double x = 0.5, x_multiplier = x * x, S = 0, P = x;
    op_counter += 6; //  j = 2, sign = 1, x = 0.5, x_multiplier = x * x, P = x

    scanf("%d", &n);

    op_counter++; // i = 0
    for (int i = 0; i <= n; i++) {
        op_counter++; // i <= n
        S += sign * P;
        op_counter += 3; // S = S + sign * P
        P *= x_multiplier /  (j * (j + 1));
        op_counter += 5; // P = P * x_multiplier / (j * (j + 1))
        sign = -sign;
        j += 2;
        op_counter += 3; // sign = -sign, j = j + 2
    }

    printf("Result: %.7f\n", S);
    printf("Total operations: %d\n", op_counter);

    return 0;
}