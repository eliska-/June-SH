/*
** builtins.c for minishell1 in /home/benaro_k/rendu/PSU_2013_minishell1
** 
** Made by Kevin BENAROCHE
** Login   <benaro_k@epitech.net>
** 
** Started on  Thu Dec 19 16:55:38 2013 Kevin BENAROCHE
** Last update Mon May 19 16:13:14 2014 Kevin BENAROCHE
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "my_sh.h"

int	cd_back(char ***environ)
{
  char	*path;
  char	*oldpwd;

  oldpwd = getcwd(NULL, 0);
  if ((path = getenv_value("OLDPWD", *environ)) == NULL)
    fprintf(stderr, "cd: OLDPWD not set\n");
  else if (chdir(path) == -1)
    fprintf(stderr, "cd: %s : No such file or directory\n", path);
  else
    {
      setenv_value("OLDPWD", oldpwd, environ);
      setenv_value("PWD", getcwd(NULL, 0), environ);
      printf("%s\n", getcwd(NULL, 0));
    }
  return (0);
}

int	cd(char *path, char *option, char ***environ)
{
  char	*home;

  if (option != NULL && strcmp(option, "-") == 0)
    return (cd_back(environ));
  if (path == NULL)
    {
      if ((home = getenv_value("HOME", *environ)) == NULL)
	{
	  fprintf(stderr, "cd: HOME not set\n");
	  return (-1);
	}
      else
	path = home;
    }
  setenv_value("OLDPWD", getcwd(NULL, 0), environ);
  if (chdir(path) == -1)
    {
      fprintf(stderr, "cd: %s : No such file or directory\n", path);
      my_unsetenv("OLDPWD", environ);
    }
  else
    return (setenv_value("PWD", getcwd(NULL, 0), environ));
}

int	my_setenv(char *name, char *value, char ***env)
{
  if (name == NULL)
    return (-1);
  if (value == NULL)
    {
      if ((value = malloc(2)) == NULL)
	my_putstr_error(ERR_MALLOC);
      value[0] = '\0';
    }
  return (setenv_value(name, value, env));
}

int	good_bye(char **args, char *cmd, char *buffer, char **env)
{
  int	bye;

  bye = (args[1] != NULL) ? my_getnbr(args[1]) : 0;
  bye %= 256;
  if (bye < 0)
    bye += 256;
  free_tab(args);
  free_tab(env);
  free(cmd);
  free(buffer);
  exit(bye);
}

int	free_tab(char **args)
{
  int	i;

  i = 0;
  while (args[i] != NULL)
    free(args[i++]);
  free(args);
  return (0);
}
