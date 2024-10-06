#include "factor.h"

/**
 * main - main function to read a file and factorize numbers
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: 0 on success, 1 on failure
 */
int main(int argc, char *argv[])
{
    FILE *fptr;
    size_t count = 0;
    ssize_t line;
    char *buffer = NULL;

    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    fptr = fopen(argv[1], "r");
    if (fptr == NULL)
    {
        fprintf(stderr, "Error: can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    while ((line = getline(&buffer, &count, fptr)) != -1)
    {
        if (buffer[line - 1] == '\n')
        {
            buffer[line - 1] = '\0';
        }

        factorize(buffer);
    }

    free(buffer);
    fclose(fptr);
    return 0;
}
