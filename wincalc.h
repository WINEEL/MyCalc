#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define PI 3.14159265358979323846  // Precise value of π

// Convert degrees to radians
double deg_to_rad(double degrees) {
    return degrees * (PI / 180.0);
}

// Trigonometric functions that accept degrees
double sin_deg(double degrees) {
    return sin(deg_to_rad(degrees));
}

double cos_deg(double degrees) {
    return cos(deg_to_rad(degrees));
}

double tan_deg(double degrees) {
    return tan(deg_to_rad(degrees));
}

// Sum of first n numbers
long int sum_n(long int n) {
    return (n * (n + 1)) / 2;
}

// Sum of numbers from [m,n]
long int sum_mn(long int m, long int n) {
    return ((n - m + 1) * (m + n)) / 2;
}

// Sum of first n odd numbers
long int sum_odd(long int n) {
    return n * n;
}

// Sum of first n even numbers
long int sum_even(long int n) {
    return n * (n + 1);
}

// Sum of first n square numbers
long int sum_square(long int n) {
    return (n * (n + 1) * (2 * n + 1)) / 6;
}

// Sum of first n cube numbers
long int sum_cube(long int n) {
    long int sum = (n * (n + 1)) / 2;
    return sum * sum;
}

// Factorial of n (up to 20!)
long long int fact(int n) {
    if (n < 0 || n > 20) {
        printf("Factorial out of range (0-20)!\n");
        return -1;
    }
    long long int pro = 1;
    for (int i = 1; i <= n; i++) {
        pro *= i;
    }
    return pro;
}

// Checking if a number is prime
int isprime(int n) {
    if (n < 2) return 0;
    for (int i = 2; i * i <= n; i++) {  // Optimized loop
        if (n % i == 0)
            return 0;
    }
    return 1;
}

// Finding the nth prime number
long int nth_prime(int n) {
    long int count = 0, i = 2;
    while (count < n) {
        if (isprime(i)) count++;
        i++;
    }
    return i - 1;
}

// Printing first n prime numbers
void prime_n(int n) {
    int count = 0, i = 2;
    while (count < n) {
        if (isprime(i)) {
            printf("%d ", i);
            count++;
        }
        i++;
    }
    printf("\n");
}

// Printing prime numbers up to nth prime
void prime_nth(int n) {
    for (int i = 2, count = 0; count < n; i++) {
        if (isprime(i)) {
            printf("%d ", i);
            count++;
        }
    }
    printf("\n");
}

// Reversing a number
long int reverse(long int n) {
    long int sum = 0;
    while (n > 0) {
        sum = (sum * 10) + (n % 10);
        n /= 10;
    }
    return sum;
}

// Finding factors of a number
void factors(long int n) {
    for (long int i = 1; i <= n; i++) {
        if (n % i == 0)
            printf("%ld ", i);
    }
    printf("\n");
}

// Finding even factors
void factors_even(long int n) {
    for (long int i = 1; i <= n; i++) {
        if (i % 2 == 0 && n % i == 0)
            printf("%ld ", i);
    }
    printf("\n");
}

// Finding odd factors
void factors_odd(long int n) {
    for (long int i = 1; i <= n; i++) {
        if (i % 2 == 1 && n % i == 0)
            printf("%ld ", i);
    }
    printf("\n");
}