// Simple factorial calculator  - without error checking

#include <stdio.h>

int main (void) {
    int n;
    printf("n  = ");
    scanf("%d", &n);
cat
    int fac = 1;
    for (int i = 1; i <= n; i++) {
        fac *= i;
    }

    printf ("n! = %d\n", fac);
    return 0;
}

///////// using goto
#include <stdio.h>

int main (void) {
    int n;
    printf("n  = ");
    scanf("%d", &n);

    int fac = 1;
    int i = 1;

    loop:
    if (i > n) goto end;
        fac *= i;   // fac = fac * i
        i++;
    goto loop;

    end:   
    printf ("n! = %d\n", fac);
    return 0; 
}