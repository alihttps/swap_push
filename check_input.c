#include "push_swap.h"

int is_digit(int av)
{
   return (av >= '0' && av <= '9');
}

int is_sign(int av)
{
   return (av == '+' || av == '-');
}
int is_space (int av)
{
    return (av == ' ' || av == '\t' || av == '\n' 
        || av == '\r' || av == '\f' || av == '\v');
}

int is_number (char *av)
{
    int i = 0;
    while(is_space(av[i]))
        i++;
    if (is_sign(av[i]) && av[i + 1] != '\0')
        i++;
    while (is_digit(av[i]) && av[i] != '\0')
        i++;
    if (!is_digit (av[i]) && av[i] != '\0')
        return 0;
    else 
        return 1;
}

static int nums_cmp(char* av1, char* av2) 
{
    int i = 0;
    int j = 0;
    if (av1[i] == '+')
        i++;
    if (av2[j] == '+')
        j++;
    while (av1[i] == '0')
        i++;
    while (av2[j] == '0')
        j++;
    while (av1[i] != '\0' && av2[j] != '\0' && av1[i] == av2[j]) 
    {
        i++;
        j++;
    }
    if (av1[i] == '\0' && av2[j] == '\0')
        return 0;
    if (av1[i] == '\0' || av2[j] == '\0')
        return 1;
    return av1[i] - av2[j];
}

static int check_double(char **av) 
{
    int i = 0;
    while (av[i] != NULL) 
    {
        int j = i + 1; 
        while (av[j] != NULL) 
        {
            if (nums_cmp(av[i], av[j]) == 0)
                return 0;
            j++;
        }
        i++;
    }
    return 1;
}

static int check_zeros (char *av)
{
    int i = 0;
    if (is_sign(av[i]))
        i++;
    while (av[i] && av[i] == '0')
        i++;
    if (av[i])
        return 0;
    return 1;
}

char* arg_join(int ac, char** av) 
{
    int i = 1;
    size_t total_len = 0;

    for (i = 1; i < ac; i++) {
        total_len += strlen(av[i]) + 1;
    }

    char *result = malloc(total_len + 1);
    if (!result)
        return NULL;

    result[0] = '\0';

    for (i = 1; i < ac; i++) {
        strcat(result, av[i]);
        strcat(result, " ");
    }

    return result;
}

static size_t count_words(char const *s, char sep) {
    size_t count = 0;
    int in_word = 0;

    while (*s) {
        if (*s == sep) {
            in_word = 0;
        } else if (!in_word) {
            in_word = 1;
            count++;
        }
        s++;
    }
    return count;
}

static char *allocate(char const **s, char sep) {
    char *word;
    int i = 0;

    while ((*s)[i] && (*s)[i] != sep)
        i++;
    word = (char *)malloc(sizeof(char) * (i + 1));
    if (!word)
        return NULL;
    i = 0;
    while (**s && **s != sep) {
        word[i++] = **s;
        (*s)++;
    }
    word[i] = '\0';
    while (**s && **s == sep)
        (*s)++;
    return word;
}

void free_split(char **splitted) 
{
    int i = 0;
    while (splitted[i])
        free(splitted[i++]);
    free(splitted);
}

char **ft_split(char const *s, char sep) 
{
    if (!s)
        return NULL;

    size_t words = count_words(s, sep);
    char **splitted = (char **)malloc(sizeof(char *) * (words + 1));
    if (!splitted)
        return NULL;

    size_t i = 0;
    while (*s && *s == sep)
        s++;
    while (i < words) {
        splitted[i] = allocate(&s, sep);
        if (!splitted[i]) {
            free_split(splitted);
            return NULL;
        }
        i++;
    }
    splitted[i] = NULL;
    return splitted;
}

int correct_input (char **av)
{
    int i = 1;
    int zeros = 0;

    while (av[i])
    {
        if (!(is_number(av[i])))
            return 0;
        zeros += check_zeros(av[i]);
        i++;
    }
    if (zeros > 1)
        return 0;
    if (!(check_double(av)))
        return 0;
    return 1;
}

