#include <stdio.h>


int main(int argc, char const *argv[])
{
    int integerVar = 5;
    size_t size;

    size = sizeof(integerVar);

    printf("Size of int is %zu bytes", integerVar);
    return 0;
}
