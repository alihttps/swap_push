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
    while (av1[i] != '\0' && av2[j] != '\0' && av1[i] == av2[j]) {
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

char* arg_join(char** av) {
    int i = 1;
    char *result = malloc(1);
    result[0] = '\0';

    while (av[i] != NULL) 
    {
        size_t result_len = strlen(result);
        size_t av_len = strlen(av[i]);
        char *new_result = malloc(result_len + av_len + 1);
        strcpy(new_result, result);
        strcat(new_result, av[i]);
        strcat(new_result, " ");
        free(result);
        result = new_result;
        i++;
    }
    return result;
}

// Function to count the number of words in the input string
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

// Function to allocate memory for each word
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

// Function to free the allocated memory if an error occurs
static void free_split(char **splitted, size_t n) {
    for (size_t i = 0; i < n; i++)
        free(splitted[i]);
    free(splitted);
}

// Main function to split the input string based on the separator
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
            free_split(splitted, i);
            return NULL;
        }
        i++;
    }
    splitted[i] = NULL;
    return splitted;
}

// int main(int ac , char **av) 
// {
// 	int i = 0;
//     char *joined = arg_join(av);
//     char **splitted = ft_split(joined, ' ');
// 	if (!check_double(splitted))
// 		printf ("error");
// 	else  
// 		printf ("dayza");
//     free(joined);
// 	free (splitted);

//     return 0;
// }

