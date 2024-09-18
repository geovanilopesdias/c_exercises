#include <stdio.h>

int calculate_factorial_by_loop(int n) {
  int factorial = 1;
  for (int i = 1; i <= n; i++) {
    factorial *= i;
    printf("Multiplicating by %d: %d\n", i, factorial);
    printf("The actual address of the assistent variable: %d\n", &factorial);
  }
  return factorial;
}

int calculate_factorial_by_recursion(int n) {
  if (n == 0) {
    return 1;
  }
  printf("The actual value of n: %d\n", n);
  printf("The actual address of n: %d\n", &n);
  return n * calculate_factorial_by_recursion(n - 1);
}

void compare_factorials() {
  printf("Comparing loop and recursion:\n");
  int n = 10;
  printf("Calculating factorial by loop\n");
  printf("\t(Please, note as the same memory address is always used.)\n");
  int fact_loop = calculate_factorial_by_loop(n);
  printf("\nCalculating factorial by recursion:\n");
  printf("\t(Please, note as a different memory address is always needed.)\n");
  int fact_recu = calculate_factorial_by_recursion(n);

  printf("\nFactorial of %d by loop %d\n", n, fact_loop);
  printf("\nFactorial of %d by recursion %d\n", n, fact_recu);
}
