#include <cs50.h>
#include <stdio.h>

int main(void)
{
    //prompt for input
    int height;
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);

    //pyramid
    //print pyramid row
    for (int i = 0; i < height; i++)
    {
        //left side of the pyramid
        //print spaces
        for (int space = 0; space < height - i - 1; space++)
        {
            printf(" ");
        }
        //print left pyramid col
        for (int j = 0; j <= i; j++)
        {
            printf("#");
        }

        //print spaces in btwn
        printf("  ");

        //print right pyramid col
        for (int z = 0; z <= i; z++)
        {
            printf("#");
        }
        printf("\n");
    }
}