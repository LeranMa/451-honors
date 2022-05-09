#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "fetch-line.h"

static char *trim_line(char *s)
{
    int ct = 0;
    while (1)
    {
        if (isspace(s[ct]))
        {
            ct++;
        }
        else
        {
            break;
        }
    }

    int ct2 = ct;
    while (1)
    {
        if (s[ct2] != '\0' && s[ct2] != '#')
        {
            ct2++;
        }
        else
        {
            if (ct2 == ct)
            {
                s[ct2] = '\0';
                return s + ct;
            }
            s[ct2] = ' ';
            break;
        }
    }

    while (ct2 != ct - 1 && isspace(s[ct2]))
    {
        s[ct2] = '\0';
        ct2--;
    }

    return s + ct;
}

char *fetch_line(char *buf, int buflen, FILE *stream, int *lineno)
{
    char *s;
    if (fgets(buf, buflen, stream) == NULL)
        return NULL;
    ++*lineno;
    if (buf[strlen(buf) - 1] != '\n') {
        fprintf(stderr, "*** reading error: input line %d too "
                        "long for %s's buf[%d]\n",
                        *lineno, __func__, buflen);
        exit(EXIT_FAILURE);
    }
    s = trim_line(buf);
    if (*s != '\0')
        return s;
    else
        return fetch_line(buf, buflen, stream, lineno);
}
