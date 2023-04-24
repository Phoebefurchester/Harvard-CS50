#include <cs50.h>
#include <stdio.h>

int main(void)
{
    //prompt user for name
    string name = get_string("What is your name?\n");

    //say hello to user
    printf("hello, %s\n", name);
}