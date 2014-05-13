/*
** unsetenv.c for minishell2 in /home/benaro_k/rendu/PSU_2013_minishell2
** 
** Made by Kevin BENAROCHE
** Login   <benaro_k@epitech.net>
** 
** Started on  Sun Mar 16 13:58:15 2014 Kevin BENAROCHE
** Last update Tue May 13 16:09:25 2014 Kevin BENAROCHE
*/

#include <stdlib.h>
#include "my_sh.h"

int	my_unsetenv(char *name, char ***env)
{
  int	i;

  i = 0;
  while (env[0][i] != NULL)
    {
      if (search_env(name, env[0][i]) == 0)
	{
	  free(env[0][i]);
	  while (env[0][i + 1] != NULL)
	    {
	      (*env)[i] = (*env)[i + 1];
	      i++;
	    }
	  env[0][i] = NULL;
	  return (0);
	}
      i++;
    }
  return (-1);
}
