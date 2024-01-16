// lab1exG.c
// ENCM 369 Winter 2024 Lab 1 Exercise G

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_ABS_F (5.0e-9)
#define POLY_DEGREE 4

double polyval(const double *a, int n, double x);
/* Return a[0] + a[1] * x + ... + a[n] * pow(x, n). */

int main(void)
{
    double f[] = {1.47, 0.73, -2.97, -1.15, 1.00};
    double dfdx[POLY_DEGREE];

    double guess;
    int max_updates;
    int update_count;
    int n_scanned;
    int i;
    int flag;

    double current_x, current_f, current_dfdx;

    printf("This program demonstrates use of Newton's Method to find\n"
           "approximate roots of the polynomial\nf(x) = ");
    printf("%.2f", f[0]);
    
    // for (i = 1; i <= POLY_DEGREE; i++) translation
    i = 1;
    for1_beginning:
    if(i > POLY_DEGREE) goto for1_end;
        if (f[i] < 0) goto else_code;
            printf(" + %.2f*pow(x,%d)", f[i], i);
            goto end_if1;
        else_code:
            printf(" - %.2f*pow(x,%d)", -f[i], i);
        end_if1:
    i++;
    goto for1_beginning;
    for1_end:

    printf("\nPlease enter a guess at a root, and a maximum number of\n"
           "updates to do, separated by a space.\n");
    n_scanned = scanf("%lf%d", &guess, &max_updates);
    if (n_scanned == 2) goto end_if2; 
        printf("Sorry, I couldn't understand the input.\n");
        exit(1);
    end_if2:
  
    if (max_updates >= 1) goto end_if3;
        printf("Sorry, I must be allowed do at least one update.\n");
        exit(1);
    end_if3:
    printf("Running with initial guess %f.\n", guess);

    // for (i = POLY_DEGREE - 1; i >= 0; i--) translation
    i = POLY_DEGREE - 1;
    for2_beginning:
    if(i < 0) goto for2_end;
        dfdx[i] = (i + 1) * f[i + 1]; // Calculus!
        i--; 
        goto for2_beginning;
    for2_end:
    current_x = guess;
    update_count = 0;
    flag = 0;
    // while (flag == 0) { translation
    while1_start:
    if(flag != 0) goto while1_end;
        current_f = polyval(f, POLY_DEGREE, current_x);
        printf("%d update(s) done; x is %.15f; f(x) is %.15e\n",
               update_count, current_x, current_f);
        if (fabs(current_f) >= MAX_ABS_F) goto else_if1;
            flag = 1;
            goto end_if4;
        else_if1:
        if (update_count != max_updates) goto end_if4;
            flag = 2;
        end_if4:
        if (flag) goto end_if5; 
          current_dfdx = polyval(dfdx, POLY_DEGREE - 1, current_x);
          current_x -= current_f / current_dfdx;
          update_count++;
        end_if5:
    goto while1_start;
    while1_end:

    if (flag != 2) goto else1;
        printf("%d updates performed, |f(x)| still >= %g.\n", 
               update_count, MAX_ABS_F);
        goto end_if6;
    else1:
        printf("Stopped with approximate solution of %.10f.\n", 
               current_x);
    end_if6:
    return 0;
}

double polyval(const double *a, int n, double x)
{
    double result = a[n];
    int i;
    // for (i = n - 1; i >= 0; i--) translation
    i = n - 1; 
    poly_for1_start:
    if(i < 0) goto poly_for1_end;
        result *= x;
        result += a[i];
        i--;
    goto poly_for1_start;
    poly_for1_end:
    return result;
}
