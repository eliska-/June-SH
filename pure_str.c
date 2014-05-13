/*
** pure_str.c for minishell2 in /home/benaro_k/rendu/PSU_2013_minishell2
** 
** Made by Kevin BENAROCHE
** Login   <benaro_k@epitech.net>
** 
** Started on  Wed Feb 26 15:02:39 2014 Kevin BENAROCHE
** Last update Tue May 13 15:59:35 2014 Kevin BENAROCHE
*/

#include <string.h>

char	*del_begin_spaces(char *str)
{
  int	i;

  i = 0;
  while (str[i] == ' ' || str[i] == '\t')
    {
      while (str[i] != '\0')
	str[i] = str[++i];
      str[i] = '\0';
      i = 0;
    }
  return (str);
}

char	*del_end_spaces(char *str)
{
  int	i;

  i = strlen(str) - 1;
  while (i >= 0 && (str[i] == ' ' || str[i] == '\t'))
    str[i--] = '\0';
  return (str);
}

char	*tab_to_space(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] == '\t')
	str[i] = ' ';
      i++;
    }
  return (str);
}

char	*pure_str(char *str)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  str = tab_to_space(str);
  str = del_begin_spaces(str);
  str = del_end_spaces(str);
  while (str[i] != '\0')
    {
      while (str[i] == ' ' && str[i + 1] == ' ')
	{
	  j = i + 1;
	  while (str[j] != '\0')
	    str[j] = str[++j];
	  str[j] = '\0';
	}
      i++;
    }
  return (str);
}
