/*
** mysh.c for minishell1 in /home/benaro_k/rendu/PSU_2013_minishell1
** 
** Made by Kevin BENAROCHE
** Login   <benaro_k@epitech.net>
** 
** Started on  Thu Dec 12 16:53:27 2013 Kevin BENAROCHE
** Last update Tue May 13 16:15:31 2014 Kevin BENAROCHE
*/

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "my_sh.h"

int	infos_args(char *buffer, int *nbargs, int *lenarg)
{
  int	tmplen;
  int	i;

  i = 0;
  tmplen = 0;
  *nbargs = 0;
  *lenarg = 0;
  while (buffer[i] != '\0')
    {
      if (buffer[i] == ' ' || buffer[i] == '\0')
	{
	  if (tmplen < arg_len(buffer, i))
	    {
	      tmplen = arg_len(buffer, i);
	      *lenarg = tmplen;
	    }
	  *nbargs += 1;
	}
      i++;
    }
  return (0);
}

char	**put_args(char *cmd, char *buffer)
{
  char	**args;
  int	nbargs;
  int	lenarg;
  int	i;

  i = 0;
  infos_args(buffer, &nbargs, &lenarg);
  if (strlen(cmd) > lenarg)
    lenarg = strlen(cmd);
  if ((args = malloc(sizeof(char *) * (nbargs + 2))) == NULL)
    my_putstr_error(ERR_MALLOC);
  while (i < nbargs + 1)
    {
      if ((args[i] = malloc(sizeof(char) * lenarg + 2)) == NULL)
	my_putstr_error("[ERROR] : Can't allocate memory.\n");
      args[i] = get_args(buffer, args[i]);
      i++;
    }
  args[i] = get_args(NULL, NULL);
  return (args);
}

char	*get_prompt()
{
  char	*buffer;
  int	ret;

  if ((buffer = malloc(sizeof(char) * 1024)) == NULL)
    my_putstr_error("[ERROR] : Can't allocate memory.\n");
  write(1, "$>", 2);
  if ((ret = read(0, buffer, 1023)) == -1)
    my_putstr_error("[ERROR] : Can't read from stdin.\n");
  buffer[ret - 1] = '\0';
  buffer = pure_str(buffer);
  return (buffer);
}

char	*get_paths(char **env)
{
  char	*paths;
  char	*path;

  if ((paths = getenv_value("PATH", env)) == NULL)
    my_putstr_error("Can't find paths from environnement\n");
  path = get_path(paths);
  free(paths);
  return (path);
}

char	*get_path(char *paths)
{
  static int	i = 5;
  char		*path;
  int		j;
  int		len;

  len = 0;
  j = 0;
  if (paths[i] == '\0')
    {
      i = 5;
      return (NULL);
    }
  while (paths[i] != '\0')
    {
      while (paths[len + i] != '\0' && paths[len + i] != ':')
	len++;
      if ((path = malloc(len + 1)) == NULL)
	my_putstr_error("[ERROR] : Can't allocate memory.\n");
      while (paths[i] != '\0' && paths[i] != ':')
	path[j++] = paths[i++];
      path[j] = '\0';
      if (paths[i] == ':')
	i++;
      return (path);
    }
}
