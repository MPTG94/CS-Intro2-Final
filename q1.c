#include <stdio.h>

// Time: O(n)
// Space: O(1)

int isKSuccessful(int *a, int n);

int absolute(int n);

int main() {
    //int a[] = {2, 3 ,3 ,1 ,5 ,2 ,4 ,5 ,5 ,9};
    //int a[] = {2, 7, 3, 1, 5, 2, 4, 5, 5, 9};
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 2, 2};
    printf("one of the duplicates is: %d\n", isKSuccessful(a, 10));
    return 0;
}

/**
 * Array has values between 1 and n-1, the function will find a number that appears more than once
 * @param a The array of numbers (contains integers between 1 and n-1
 * @param n The size of the array
 * @return A number that appears more than once in the array
 */
int isKSuccessful(int *a, int n) {
    /**
     * Since the array is of size n and the numbers are between 1 and n-1, due to the Pigeonhole principle, at least one
     * number appears more than once.
     * We will "mark" every number we come across, by setting a[number] (a[a[i]] foreach i in n) to -a[number]
     * If at any point we reach a[number] that is already negative, that means a previous "number" pointed to it, so number (a[i]) is a duplicate.
     */
    for (int i = 0; i < n; ++i) {
        int absVal = absolute(a[i]);
        if (a[absVal] > 0) {
            a[absVal] = -1 * a[absVal];
        } else {
            return absVal;
        }
    }
    return -1;
}

/**
 * Returns the absolute value of a number
 * @param n The number to return the abs of
 * @return The absolute value of the input number
 */
int absolute(int n) {
    if (n < 0) {
        return -1 * n;
    }
    return n;
}