#include "main.h"
int _atoi(char *s)
{
    int i = 0;
    int sign = 1;
    unsigned int res = 0;
    int found_num = 0;
    while (s[i] != '\0')
    {
        if (s[i] == '-')
            sign *= -1;
        if (s[i] >= '0' && s[i] <= '9')
        {
            res = res * 10 + (s[i] - '0');
            found_num = 1;
        }
        else if (found_num)
        {
            break;
        }
        i++;
    }
    return (res * sign);
}
