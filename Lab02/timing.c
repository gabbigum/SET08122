#include <stdio.h>
#include <time.h>

void code()
{
    for(int i = 0; i < 10000; i++)
    {
        printf(".");
    }
    printf("\n");
}


int main(int argc, char const *argv[])
{
    clock_t t;
    printf("Start: %d \n", (int) (t=clock()));

    code();

    printf("Stop: %d \n", (int) (t=clock() - t));
    printf("Elapsed : %f seconds\n", (double) t / CLOCKS_PER_SEC);

    return 0;
}
