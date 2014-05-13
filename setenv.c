/*
** get_env.c for minishell1 in /home/benaro_k/rendu/PSU_2013_minishell1
** 
** Made by Kevin BENAROCHE
** Login   <benaro_k@epitech.net>
** 
** Started on  Mon Jan 20 15:21:01 2014 Kevin BENAROCHE
** Last update Tue May 13 16:09:39 2014 Kevin BENAROCHE
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "my_sh.h"

int	setenv_value(char *str, char *value, char ***env)
{
  int	i;

  i = 0;
  while (env[0][i] != NULL)
    {
      if (search_env(str, env[0][i]) == 0)
	{
	  free(env[0][i]);
	  if ((env[0][i] = malloc(strlen(str) + strlen(value) + 2)) == NULL)
	    my_putstr_error(ERR_MALLOC);
	  strcpy(env[0][i], str);
	  strcat(env[0][i], "=");
	  strcat(env[0][i], value);
          return (0);
	}
      i++;
    }
  return (addenv_value(str, value, env));
}

int	getenv_nb(char **env)
{
  int	i;

  i = 0;
  if (env != NULL)
    {
      while (env[i] != NULL)
	i++;
      return (i);
    }
  return (-1);
}

int	addenv_value(char *name, char *value, char ***env)
{
  char	**newenv;
  int	nb;
  int	i;

  i = -1;
  nb = getenv_nb(*env);
  if ((newenv = malloc(sizeof(char *) * (nb + 2))) == NULL)
    my_putstr_error(ERR_MALLOC);
  while (++i < nb)
    if ((newenv[i] = malloc(strlen(env[0][i]) + 1)) != NULL)
      strcpy(newenv[i], env[0][i]);
    else
      my_putstr_error(ERR_MALLOC);
  if ((newenv[i] = malloc(strlen(name) + strlen(value) + 2)) != NULL)
    {
      strcpy(newenv[i], name);
      strcat(newenv[i], "=");
      strcat(newenv[i], value);
    }
  else
    my_putstr_error(ERR_MALLOC);
  newenv[i + 1] = NULL;
  free_tab(*env);
  *env = newenv;
  return (0);
}

int	get_env(char **env)
{
  int	i;

  i = 0;
  while (env[i] != NULL)
    printf("%s\n", env[i++]);
  return (0);
}

char	**envcpy(char **env)
{
  char	**newenv;
  int	nb;
  int	i;

  i = 0;
  nb = getenv_nb(env);
  if ((newenv = malloc(sizeof(char *) * (nb + 1))) != NULL)
    {
      while (env[i] != NULL)
        if ((newenv[i] = malloc(sizeof(char) * strlen(env[i]) + 1)) != NULL)
	  {
	    strcpy(newenv[i], env[i]);
	    i++;
	  }
        else
          my_putstr_error(ERR_MALLOC);
      newenv[i] = NULL;
      return (newenv);
    }
  else
    my_putstr_error(ERR_MALLOC);
}
