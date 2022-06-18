// Simple factorial calculator  - without error checking

#include <stdio.h>

int main (void) {
    int n;
    printf("n  = ");
    scanf("%d", &n);

    int fac = 1;
    for (int i = 1; i <= n; i++) {
        fac *= i;
    }

    printf ("n! = %d\n", fac);
    return 0;
}

// int i = 0;
// while (i < 10) {
//         printf("hi");
//         i++;
// }

// for (int i = 0; i < 10; i++) {
//         printf("hi");
// }

//     int i = 1;
//     while (i <= n) {
//             fac *= i;
//             i++;
//     }