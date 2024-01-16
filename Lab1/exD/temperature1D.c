// temperature1D.c
// ENCM 369 Winter 2024 Lab 1 Exercise D

#include <stdio.h>

void report(int celsius_temp);

int main(void)
{
  report(-10);
  report(0);
  report(5);
  report(14);
  report(20);
  report(26);
  report(30);
  return 0;
}

void report(int celsius_temp)
{
  if (celsius_temp > 0) goto else_if_1;
    printf("The temperature is a chilly %d degrees.\n", celsius_temp);
    printf("Don't slip on the ice.\n");
  goto end_if;
  else_if_1: 
  if (celsius_temp > 14) goto else_if_2;
    printf("The temperature is a cool %d degrees.\n", celsius_temp);
    printf("Wear a jacket.\n");
  goto end_if;
  else_if_2:
  if (celsius_temp > 26) goto else_code;
    printf("The temperature is a pleasant %d degrees.\n", celsius_temp);
    printf("Have a nice day.\n");
  goto end_if;
  else_code:
    printf("The temperature is a warm %d degrees.\n", celsius_temp);
    printf("Have a glass of water.\n");
  end_if:
  ;
}
