#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int is_prime(unsigned long long num) {
    if (num < 2) return 0;
    if (num == 2 || num == 3) return 1;
    if (num % 2 == 0 || num % 3 == 0) return 0;
    for (unsigned long long i = 5; i * i <= num; i += 6) {
        if (num % i == 0 || num % (i + 2) == 0) return 0;
    }
    return 1;
}

void rsa_factorize(unsigned long long n) {
    unsigned long long p = 1, q = n;

    for (p = 2; p * p <= n; p++) {
        if (n % p == 0) {
            q = n / p;
            if (is_prime(p) && is_prime(q)) {
                break;
            }
        }
    }

    if (p < q) {
        unsigned long long temp = p;
        p = q;
        q = temp;
    }
    printf("%llu=%llu*%llu\n", n, p, q);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <file>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (!file) {
        perror("Error opening file");
        return 1;
    }

    unsigned long long num;
    fscanf(file, "%llu", &num);

    rsa_factorize(num);

    fclose(file);
    return 0;
}
