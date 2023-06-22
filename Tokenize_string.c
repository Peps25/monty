#include <stdlib.h>


char **strtow(char *str, char *delims);
int is_delim(char ch, char *delims);
int get_word_length(char *str, char *delims);
int get_word_count(char *str, char *delims);
char *get_next_word(char *str, char *delims);


/**
 * strtow - will take a string and seperate its words
 *
 * @str: str to seperate into words
 * @delims: delimitors to use to delimit words
 *
 * Return: 2D array of pointers to each word
 */


char **strtow(char *str, char *delims)
{
    char **words = NULL;
    int wc, wordLen, n, ui = 0;


    if (str == NULL || !*str)
        return (NULL);
    wc = get_word_count(str, delims);




    if (wc == 0)
        return (NULL);
    words = malloc((wc + 1) * sizeof(char *));
    if (words == NULL)
        return (NULL);
    while (ui < wc)
    {
        wordLen = get_word_length(str, delims);
        if (is_delim(*str, delims))
        {
            str = get_next_word(str, delims);
        }
        words[ui] = malloc((wordLen + 1) * sizeof(char));
        if (words[ui] == NULL)
        {
            while (ui >= 0)
            {
                ui--;
                free(words[ui]);
            }
            free(words);
            return (NULL);
        }
        n = 0;
        while (n < wordLen)
        {
            words[ui][n] = *(str + n);
            n++;
        }
        words[ui][n] = '\0'; /* set end of str */
        str = get_next_word(str, delims);
        ui++;
    }
    words[ui] = NULL; /* last element is null for iteration */
    return (words);
}


/**
 * is_delim - will check if stream has delimitor char
 *
 * @ch: char in stream
 *
 * @delims: Pointer to null terminated array of delimitors
 *
 * Return: 1 (success) 0 (failure)
 */


int is_delim(char ch, char *delims)
{
    int ui = 0;


    while (delims[ui])
    {
        if (delims[ui] == ch)
            return (1);
        ui++;
    }
    return (0);
}


/**
 * get_word_length - will get the word length of cur word in str
 *
 * @str: str to get word length from current word
 * @delims: delimiters to use to delimit words
 *
 * Return: word len of current word
 */


int get_word_length(char *str, char *delims)
{
    int wLen = 0, pending = 1, ui = 0;


    while (*(str + ui))
    {
        if (is_delim(str[ui], delims))
            pending = 1;
        else if (pending)
        {
            wLen++;
        }
        if (wLen > 0 && is_delim(str[ui], delims))
            break;
        ui++;
    }
    return (wLen);
}


/**
 * get_word_count - will get the word count of a str
 *
 * @str: str to get word count from
 * @delims: delimiters to use to delimit words
 *
 * Return: word count of the str
 */


int get_word_count(char *str, char *delims)
{
    int wc = 0, pending = 1, ui = 0;


    while (*(str + ui))
    {
        if (is_delim(str[ui], delims))
            pending = 1;
        else if (pending)
        {
            pending = 0;
            wc++;
        }
        ui++;
    }
    return (wc);
}


/**
 * get_next_word - will get the next word in a str
 *
 * @str: str to get next word from
 * @delims: Delimiters to use to delimit words
 *
 * Return: Pointer to first character of next word
 */


char *get_next_word(char *str, char *delims)
{
    int pending = 0;
    int ui = 0;


    while (*(str + ui))
    {
        if (is_delim(str[ui], delims))
            pending = 1;
        else if (pending)
            break;
        ui++;
    }
    return (str + ui);
}
