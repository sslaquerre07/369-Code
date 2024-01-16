// lab1exH.c
// ENCM 369 Winter 2024 Lab 1 Exercise H

#include <stdio.h>

void print_array(const char *str, const int *a, int n);
// Prints the string given by str on stdout, then
// prints a[0], a[1], ..., a[n - 1] on stdout on a single line.

void sort_array(int *x, int n);
// Sorts x[0], x[1], ..., x[n - 1] from smallest to largest.

int main(void)
{
  int test_array[] = { 4000, 5000, 7000, 1000, 3000, 4000, 2000, 6000 };

  print_array("before sorting ...", test_array, 8);
  sort_array(test_array, 8);
  print_array("after sorting ...", test_array, 8);
  return 0;
}

void print_array(const char *str, const int *a, int n)
{
  int i;
  puts(str);
  //for (i = 0; i < n; i++) translation
  i = 0;
  print_for_start:
  if(i >= n) goto print_for_end;
    printf("    %d", a[i]);
  i++;
  goto print_for_start;
  print_for_end:
  printf("\n");
}

void sort_array(int *x, int n)
{
  // This is an implementation of an algorithm called selection sort.

  int outer, inner, max, i_of_max;
  // for (outer = n - 1; outer > 0; outer--) translation
  outer = n-1;
  sort_outer_start:
  if(outer <= 0) goto sort_outer_end;
    i_of_max = outer;
    max = x[outer];
    // for (inner = 0; inner < outer; inner++) translation
    inner = 0;
    sort_inner_start:
    if(inner >= outer) goto sort_inner_end;
      if (x[inner] <= max) goto endif;
        i_of_max = inner;
        max = x[inner];
      endif:
    inner++;
    goto sort_inner_start;
    sort_inner_end:
    x[i_of_max] = x[outer];
    x[outer] = max;
  
  outer--;
  goto sort_outer_start;
  sort_outer_end:
  ;
}
