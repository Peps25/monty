#include <stdlib.h>


char *get_int(int num);
unsigned int _abs(int);
int get_numbase_len(unsigned int num, unsigned int base);
void fill_numbase_buff(unsigned int num, unsigned int base,
               char *buff, int buff_size);


/**
 * get_int - will get a char pointer to new str that has int
 * @num: no. to be converted to str
 *
 * Return: char pointer to newly created string. NULL if malloc fails
 */
char *get_int(int num)
{
    unsigned int temp;
    int length = 0;
    long num_l = 0;
    char *ret;


    temp = _abs(num);
    length = get_numbase_len(temp, 10);


    if (num < 0 || num_l < 0)
        length++; /* negative sign */
    ret = malloc(length + 1); /* create new string */
    if (!ret)
        return (NULL);


    fill_numbase_buff(temp, 10, ret, length);
    if (num < 0 || num_l < 0)
        ret[0] = '-';


    return (ret);
}


/**
 * _abs - will get absolute value of an int
 * @ui: int to get absolute value of
 *
 * Return: unsigned int abs rep of ui
 */
unsigned int _abs(int ui)
{
    if (ui < 0)
        return (-(unsigned int)ui);
    return ((unsigned int)ui);
}


/**
 * get_numbase_len - will get len of buffer needed for an unsigned int
 * @num: no. to get len needed for
 * @base: base of no. representation used by buffer
 *
 * Return: int that has len of buffer needed
 */
int get_numbase_len(unsigned int num, unsigned int base)
{
    int len = 1; /* all numbers contain atleast one digit */


    while (num > base - 1)
    {
        len++;
        num /= base;
    }
    return (len);
}


/**
 * fill_numbase_buff - will fill buffer with correct numbers up to base 36
 * @num: no. to be converted to string given base
 * @base: base of no. used in conversion, only works up to base 36
 * @buff: buffer to be filled with result of conversion
 * @buff_size: size of buffer in bytes
 *
 * Return: void always
 */
void fill_numbase_buff(unsigned int num, unsigned int base,
            char *buff, int buff_size)
{
    int rem, ui = buff_size - 1;


    buff[buff_size] = '\0';
    while (ui >= 0)
    {
        rem = num % base;
        if (rem > 9) /* return lowercase ascii val representation */
            buff[ui] = rem + 87; /* 10 will be a, 11 = b, ... */
        else
            buff[ui] = rem + '0';
        num /= base;
        ui--;
    }
}
