#include <stdio.h>
#include <stdlib.h>

void factorize(unsigned long long n) {
unsigned long long p = 1, q = n;
for (p = 2; p * p <= n; p++) {
if (n % p == 0) {
q = n / p;
break;
}
}
printf("%llu=%llu*%llu\n", n, p, q);
}

int main(int argc, char *argv[]) {
if (argc != 2) {
fprintf(stderr, "Usage: %s <file>\n", argv[0]);
return (1);
}

FILE *file = fopen(argv[1], "r");
if (!file) {
perror("Error opening file");
return (1);
}

unsigned long long num;
while (fscanf(file, "%llu", &num) != EOF) {
factorize(num);
}

fclose(file);
return (0);
}
