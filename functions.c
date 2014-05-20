/*
** functions.c for Minishell1 in /home/benaro_k/rendu/PSU_2013_minishell1
** 
** Made by Kevin BENAROCHE
** Login   <benaro_k@epitech.net>
** 
** Started on  Mon Dec 23 14:39:13 2013 Kevin BENAROCHE
** Last update Mon May 19 16:43:34 2014 Kevin BENAROCHE
*/

#include <stdlib.h>
#include <string.h>
#include "my_sh.h"

int     my_putstr_error(char *str)
{
  write(2, str, strlen(str));
  if (str[strlen(str) - 1] == '\n')
    exit(1);
}

int     arg_len(char *buffer, int start)
{
  int   i;

  i = 0;
  start = start + 1;
  while (buffer[start + i] != ' ' && buffer[start + i] != '\0')
    i++;
  return (i);
}

char    *get_args(char *buffer, char *args)
{
  static int    i;
  int           j;

  if (buffer == NULL && args == NULL)
    {
      i = 0;
      return (NULL);
    }
  while (buffer[i] != '\0')
    {
      j = 0;
      while (buffer[i] != ' ' && buffer[i] != '\0')
        args[j++] = buffer[i++];
      args[j] = '\0';
      i++;
      return (args);
    }
}

int	my_getnbr(char *str)
{
  int	i;
  int	nb;
  int	neg;

  i = 0;
  nb = 0;
  neg = 1;
  while (str[i] < 48 || str[i] > 57)
    {
      if (str[i] == '-')
        neg = neg * -1;
      else
        return (0);
      i = i + 1;
    }
  while (str[i] > 47 && str[i] < 58)
    {
      nb = nb * 10;
      nb = nb + (str[i] - '0');
      i = i + 1;
    }
  nb = nb * neg;
  return (nb);
}

int	my_strstr(char *s1, char *s2)
{
  int	i;

  i = 0;
  if (strlen(s1) != strlen(s2))
    return (-1);
  while (s1[i] != '\0')
    {
      if (s1[i] == s2[i])
        i++;
      else
        return (-1);
    }
  return (0);
}
