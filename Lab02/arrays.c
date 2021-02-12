#include <stdio.h>

int main(int argc, char const *argv[])
{
   int a[100];
   size_t s = sizeof(a);
   printf("%zu bytes\n", s);
    
    size_t num = s/sizeof(int);
    printf("space for storing %zu elements\n", num);

    return 0;
}
