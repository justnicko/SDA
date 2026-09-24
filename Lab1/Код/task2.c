#include <stdio.h>

int main(int argc, char *argv[]) {
  double x;
  double y;

  scanf("%lf", &x);
  
  if ((x >= -49 && x < -10) || (x > 0 && x <= 10)) {
    y = 10 * x * x * x + 7 * x / 5 + 2;
    printf("%lf\n", y);
  } else if (x > 20) {
    y = -x + 9;
    printf("%lf\n", y);
  } else {
    printf("function is undefined for this value\n");
  }

  return 0;
}