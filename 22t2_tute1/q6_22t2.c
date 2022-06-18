#include <stdio.h>

void print_array(int nums[], int len, int i) {
    if (i == len) {
        return;
    }
    printf("%d \n", nums[i]);
    print_array(nums, len, i + 1);

    /*
    // for loop
    for (int i = 0; i < len; i++) {
        printf("%d\n", nums[i]);
    }

    //while loop
    int i = 0;
    while(i < len) {
        printf("%d\n", nums[i]);
        i++;
    }

    */
}

int main(void)
{
    int nums[] = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3};
    //print_array(nums, 10);
    print_array(nums, 10, 0);

    return 0;
}