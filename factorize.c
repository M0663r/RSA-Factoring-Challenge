#include "factor.h"
#include <math.h>  // For sqrt()

/**
 * is_prime - check if a number is prime
 * @num: the number to check
 *
 * Return: 1 if prime, 0 otherwise
 */
int is_prime(unsigned long long num)
{
    if (num < 2)
        return 0;
    if (num == 2 || num == 3)
        return 1;
    if (num % 2 == 0 || num % 3 == 0)
        return 0;
    for (unsigned long long i = 5; i * i <= num; i += 6)
    {
        if (num % i == 0 || num % (i + 2) == 0)
            return 0;
    }
    return 1;
}

/**
 * factorize - factorize a number into two prime factors
 * @buffer: pointer to the number in string format
 *
 * Return: 0 on success
 */
int factorize(char *buffer)
{
    unsigned long long num = strtoull(buffer, NULL, 10);
    unsigned long long p, q;
    unsigned long long limit = (unsigned long long)sqrt(num);

    if (num < 4)
    {
        printf("%llu=1*%llu\n", num, num);
        return 0;
    }

    for (p = 2; p <= limit; p++)
    {
        if (num % p == 0)
        {
            q = num / p;
            if (is_prime(p) && is_prime(q))
            {
                printf("%llu=%llu*%llu\n", num, q, p);
                return 0;
            }
        }
    }

    printf("%llu=1*%llu\n", num, num);
    return 0;
}
