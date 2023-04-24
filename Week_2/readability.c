#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    int letters, words, sentences;
    float index, L, S;

    //prompt user for text input
    string text = get_string("Text: ");

    letters = count_letters(text);
    words = count_words(text);
    sentences = count_sentences(text);

    //Coleman-Liau index
    //index = 0.0588 * L - 0.296 * S - 15.8

    //divde should hv() due to precedence to indicate to divide first and then only multiplication
    //the result of 2 int's division is always an int, that's why we have to add "(float)" to change its data type, so that its precision would be accurate
    L = ((float)letters / words) * 100;
    S = ((float)sentences / words) * 100;
    index = 0.0588 * L - 0.296 * S - 15.8;

    if (index < 1)
    {
        printf("Before Grade 1\n");
        return 0;
    }
    if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", (int) round(index));
    }
    return 0;
}

//letters
int count_letters(string text)
{
    int alpha_count = 0;

    for (int i = 0, n = strlen(text); i < n; i++)
    {
        //if they are alphabtes
        if ((text[i] >= 65 && text[i] <= 90) || (text[i] >= 97 && text[i] <= 122))
        {
            alpha_count += 1;
        }
    }
    return alpha_count;
}

//words
int count_words(string text)
{
    int word_count = 0;

    for (int i = 0, n = strlen(text); i < n; i++)
    {
        //if the first array is a space, return
        if (text[0] == 32)
        {
            printf("Opps, you shouldn't start with a space!\n");
            return 0;
        }

        // to prevent multiple spaces in a row
        if (text[i] == 32 && text[i + 1] == 32)
        {
            printf("Opps, check your space(s)!\n");
            return 0;
        }

        //if it is a space
        if (text[i] == 32)
        {
            word_count += 1;
        }

    }
    //+1 for the final word since it won't end with a sp
    return word_count + 1;
}

//sentences
int count_sentences(string text)
{
    int sentence_count = 0;

    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (text[i] == 46 || text[i] == 63 || text[i] == 33)
        {
            sentence_count += 1;
        }
    }
    return sentence_count;
}

/*dummy.c*/
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int main(void)
{
    int letters, words, sentences;
    float index, L, S;

    //prompt user for text input
    string text = get_string("Text: ");

    letters = 65;
    words = 14;
    sentences = 4;

    //Coleman-Liau index
    //index = 0.0588 * L - 0.296 * S - 15.8
    L = ((float)letters / words) * 100;
    printf("%f\n", L);
    S = ((float)sentences / words) * 100;
    printf("%f\n", S);
    index = 0.0588 * L - 0.296 * S - 15.8;

    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", (int) round(index));
    }
}

/*draft*/
#include <cs50.h>
#include <stdio.h>
#include <string.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    //prompt user for text input
    string text = get_string("Text: ");
    printf("\n");
    printf("Copy of the text: %s\n", text);
    printf("\n");

    //number of letters
    printf("Letters  : %i\n", count_letters(text));
    printf("\n");

    //number of words
    printf("Words    : %i\n", count_words(text));
    printf("\n");

    //number of sentences
    printf("Sentences: %i\n", count_sentences(text));
}

//letters
int count_letters(string text)
{
    int alpha_count = 0;

    for (int i = 0, n = strlen(text); i < n; i++)
    {
        //if they are alphabtes
        if ((text[i] >= 65 && text[i] <= 90) || (text[i] >= 97 && text[i] <= 122))
        {
            alpha_count += 1;
        }
    }
    return alpha_count;
}

//words
int count_words(string text)
{
    int word_count = 0;

    for (int i = 0, n = strlen(text); i < n; i++)
    {
        //if the first array is a space, return
        if (text[0] == 32)
        {
            printf("Opps, you shouldn't start with a space!\n");
            return 0;
        }

        // to prevent multiple spaces in a row
         if (text[i] == 32 && text[i + 1] ==32)
        {
            printf("Opps, check your space(s)!\n");
            return 0;
        }

        //if it is a space
        if (text[i] == 32)
        {
            word_count += 1;
        }

    }
    //+1 for the final word since it won't end with a sp
    return word_count + 1;
}

//sentences
int count_sentences(string text)
{
    int sentence_count = 0;

    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (text[i] == 46 || text[i] == 63 || text[i] ==33)
        {
            sentence_count += 1;
        }
    }
    return sentence_count;
}