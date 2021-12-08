#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int stringCompare(const void *p1, const void *p2)
{
    return strcmp(* (char * const *) p1, * (char * const *) p2);
}

void printStrings(char *arr[], size_t size)
{
    for (size_t i = 0; i < size; i++)
        printf("%10s | ", arr[i]);
    printf("\n");
}

int main(int argc, char *argv[]) {
    char *arr[] = {"jelloa",
                   "helloaa",
                   "mello",
                   "zell",
                   "aelloaaa"};

    printStrings(arr, 5);
    qsort(arr, 5, sizeof(char *), stringCompare);
    printStrings(arr, 5);

    exit(EXIT_SUCCESS);
}
