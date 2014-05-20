/*
** echo.c for 42sh in /home/benaro_k/rendu/June-SH
** 
** Made by Kevin BENAROCHE
** Login   <benaro_k@epitech.net>
** 
** Started on  Tue May 20 14:16:07 2014 Kevin BENAROCHE
** Last update Tue May 20 15:59:46 2014 Kevin BENAROCHE
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int	search_in_array_backward(char *str, char **array, int *pos)
{
  int	i;

  i = 0;
  while (array[i] != NULL)
    i++;
  while (--i >= 0)
    if (my_strstr(str, array[i]) == 0)
      {
	*pos = i;
	return (1);
      }
  *pos = -1;
  return (0);
}

void	write_args(char **args, int n, int start, int escape)
{
  while (args[++start] != NULL)
    if (escape == 1 || escape == 0) // je sais pas cmt faire pour pas interpreter les caracteres speciaux tels que \n
      write(1, args[start], strlen(args[start]));
  if (n == 0)
    putchar('\n');
}

int	get_last_pos(int *pos)
{
  int	lastpos;

  lastpos = 0;
  if (pos[0] > lastpos)
    lastpos = pos[0];
  if (pos[1] > lastpos)
    lastpos = pos[1];
  if (pos[2] > lastpos)
    lastpos = pos[2];
  return (lastpos);
}

int	my_echo(char **args)
{
  int	e;
  int	E;
  int	n;
  int	pos[3];
  int	lastpos;

  e = search_in_array_backward("-e", args, &pos[0]);
  E = search_in_array_backward("-E", args, &pos[1]);
  n = search_in_array_backward("-n", args, &pos[2]);
  lastpos = get_last_pos(pos);
  if (e == 1 && pos[0] > pos[1])
    write_args(args, n, lastpos, 0);
  else
    write_args(args, n, lastpos, 1);
  return (0);
  
}
