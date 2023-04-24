#include <cs50.h>
#include <stdio.h>
#include <string.h>

string validate_key(string argv[1]);

int main(int argc, string argv[])
{
    if (argc == 2)
    {
        validate_key(argv[1]);
        printf("%s\n", argv[1]);
    }
    else
    {
        printf("Usage: ./substitution key\n");
    }
}

//validate the key
string validate_key(string argv[1])
{
    //check key length (26 letters only)
    int n = strlen(argv[1]);
    printf("%i\n", n);
}