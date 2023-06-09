/*
** EPITECH PROJECT, 2023
** Minishell1
** File description:
** my_splitstr
*/

#include <stddef.h>
#include <stdlib.h>

int my_strlen(char const *str);

static char *malloc_and_create_str(char const *str, int i, int j)
{
    char *word = malloc(sizeof(char) * (j + 1));
    if (str == NULL || word == NULL)
        return NULL;
    word[j] = '\0';
    for (int count = 0; count != j; count += 1)
        word[count] = str[i + count];
    return word;
}

static char **malloc_tab(char const *str, int separator, int len_word)
{
    if (str == NULL)
        return NULL;
    int count_word = 0;
    int j = 0;
    char **tab;
    for (int i = 0; str[i] != '\0' && i < len_word;  i += 1){
        if (str[i] == separator)
            continue;
        count_word += 1;
        for (j = i; str[j] != '\0' && str[j] != separator; j += 1);
        i = j;
    }
    tab = malloc(sizeof(char *) * (count_word + 1));
    if (tab == NULL)
        return NULL;
    tab[count_word] = NULL;
    return tab;
}

char **my_splitstr(char const *str, int separator)
{
    if (str == NULL)
        return NULL;
    int j = 0;
    int k = 0;
    int len_word = my_strlen(str);
    if (len_word == -1)
        return NULL;
    char **tab = malloc_tab(str, separator, len_word);
    for (int i = 0; str[i] != '\0' && i < len_word; i += 1){
        if (str[i] == separator)
            continue;
        for (j = 0; str[j + i] != '\0' && str[j + i] != separator; j += 1);
        tab[k] = malloc_and_create_str(str, i, j);
        k += 1;
        i += j;
    }
    return tab;
}
