// simple_loops1E.c
// ENCM 369 Winter 2024 Lab 1 Exercise E

// INSTRUCTIONS:
//   Recode the definition of main in Goto-C
//   Make sure your modified program produces exactly the same
//   output as the original.

#include <stdio.h>

int main(void)
{
  int a[4] = {1200, 3400, 5600, 7800};
  int *p;
  int i;
  p = a;
  start_loop:
  if (p>=a+4) goto end_loop;
    printf("%d\n", *p);
    p++;
    goto start_loop;
  end_loop:
  i = 234567;
  start_while:
  if(i <= 1) goto end_while;
    printf("%d\n", i);
    i /= 16;
  goto start_while;
  end_while:
  return 0;
}
