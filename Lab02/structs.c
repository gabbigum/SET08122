#include <stdio.h>


typedef struct
{
    int id;
    char name[30];
} employee;

int main(int argc, char const *argv[])
{
    employee emp1 = {1, "Gabriel"};
    printf("ID: %d\nName %s\n", emp1.id, emp1.name);
    printf("Name has %zu bytes\nId has %zu bytes\nSize of employee %zu bytes.", sizeof(emp1.id), sizeof(emp1.name), sizeof(emp1));
    return 0;
}
