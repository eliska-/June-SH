/*
** get_next_line.c for colle1 in /home/benaro_k/rendu/colle1
** 
** Made by Kevin BENAROCHE
** Login   <benaro_k@epitech.net>
** 
** Started on  Wed Apr 30 19:03:48 2014 Kevin BENAROCHE
** Last update Tue May 13 16:46:42 2014 Kevin BENAROCHE
*/

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "my_sh.h"

char	*add_and_cpy(char *buff, char *tmp, int i)
{
  char	*newbuff;

  if ((newbuff = malloc(BSIZE * i + 1)) == NULL)
    {
      my_putstr_error("Can't allocate memory\n");
      exit(1);
    }
  strcpy(newbuff, buff);
  strcat(newbuff, tmp);
  free(buff);
  return (newbuff);
}

char	*get_next_line(const int fd)
{
  char	tmp[2];
  char	*buff;
  int	i;

  i = 1;
  tmp[1] = '\0';
  if ((buff = malloc(BSIZE + 1)) == NULL)
    {
      my_putstr_error("Can't allocate memory\n");
      exit(1);
    }
  buff[0] = '\0';
  while (read(fd, tmp, 1) > 0)
    {
      if (tmp[0] != '\n')
	{
	  if (strlen(buff) < BSIZE * i)
	    strcat(buff, tmp);
	  else
	    buff = add_and_cpy(buff, tmp, ++i);
	}
      else
	return (buff);
    }
  return (NULL);
}
