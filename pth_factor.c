#include <stdio.h>
#include <math.h>

/**
 * Finds the p-th smallest factor of n.
 * Returns the factor if found, otherwise returns 0.
 */
long pthFactor(long n, long p) {
    long count = 0;
    long root = (long)sqrt(n);

    // First step: Check for factors from 1 to sqrt(n)
    for (long i = 1; i <= root; i++) {
        if (n % i == 0) {
            count++;
            if (count == p) {
                return i;
            }
        }
    }

    // Second step: Check for partner factors > sqrt(n) in reverse
    for (long i = root; i >= 1; i--) {
        if (n % i == 0) {
            // Skip the middle factor if n is a perfect square
            if (i * i == n) {
                continue;
            }

            count++;
            if (count == p) {
                return n / i;
            }
        }
    }

    return 0;
}

int main() {
    // Test case: n=10, p=3. Expected output: 5
    long n = 10;
    long p = 3;

    long result = pthFactor(n, p);
    printf("%ld\n", result);

    return 0;
}