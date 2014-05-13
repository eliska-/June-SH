/*
** get_env.c for minishell2 in /home/benaro_k/rendu/PSU_2013_minishell2
** 
** Made by Kevin BENAROCHE
** Login   <benaro_k@epitech.net>
** 
** Started on  Sun Mar  9 15:59:37 2014 Kevin BENAROCHE
** Last update Tue May 13 16:10:34 2014 Kevin BENAROCHE
*/

#include <stdlib.h>
#include <string.h>
#include "my_sh.h"

int	search_env(char *str, char *env)
{
  int   i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] == env[i])
        i++;
      else
        return (-1);
    }
  return (0);
}

char	*getenv_value(char *str, char **env)
{
  char	*value;
  int	i;
  int	j;
  int	c;

  i = 0;
  c = 0;
  j = strlen(str) + 1;
  while (env[i] != NULL)
    {
      if (search_env(str, env[i]) == 0)
        {
          if ((value = malloc(strlen(env[i]) - strlen(str))) == NULL)
            my_putstr_error(ERR_MALLOC);
          while (env[i][j] != '\0')
            value[c++] = env[i][j++];
          value[c++] = '\0';
          return (value);
        }
      i++;
    }
  return (NULL);
}
