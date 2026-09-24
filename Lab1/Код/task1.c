#include <stdio.h>

int main(int argc, char *argv[]) {
  double x;
  double y;

  scanf("%lf", &x);

  if (x < -49) {
    printf("function is undefined for this value\n");
  } else if (x < -10) {
    y = 10 * x * x * x + 7 * x / 5 + 2;
    printf("%lf\n", y);
  } else if (x <= 0) {
     printf("function is undefined for this value\n");
  } else if (x <= 10) {
    y = 10 * x * x * x + 7 * x / 5 + 2;
    printf("%lf\n", y);
  } else if ( x <= 20) {
    printf("function is undefined for this value\n");
  } else {
    y = -x + 9;
    printf("%lf\n", y);
  }

  return 0;
}