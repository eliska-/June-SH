/*
** aggreg.c for minishell2 in /home/benaro_k/rendu/PSU_2013_minishell2
** 
** Made by Kevin BENAROCHE
** Login   <benaro_k@epitech.net>
** 
** Started on  Thu Feb 27 17:17:49 2014 Kevin BENAROCHE
** Last update Tue May 13 16:20:44 2014 Kevin BENAROCHE
*/

#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

char		*parse_dotcoma(char *buffer)
{
  static int	i;
  int		j;
  char		*cmd;
  int		cmdlen;

  j = i;
  cmdlen = 0;
  if (buffer[i] == '\0')
    {
      i = 0;
      return (NULL);
    }
  while (buffer[i] != '\0' && buffer[i++] != ';')
    cmdlen++;
  if ((cmd = malloc(cmdlen + 1)) == NULL)
    my_putstr_error("[ERROR] : Can't allocate memory.\n");
  i = j;
  j = 0;
  while (buffer[i] != '\0' && buffer[i] != ';')
    cmd[j++] = buffer[i++];
  cmd[j] = '\0';
  if (buffer[i] == ';')
    i++;
  return (cmd);
}

/*char	*get_file(char *cmd)
{
  char	*file;
  int	eof;
  int	i;

  eof = strlen(cmd) - 1;
  i = 0;
  while (cmd[eof] != ' ' && cmd[eof] != '>' && cmd[eof] != '<')
    eof--;
  if ((file = malloc(strlen(cmd) - eof + 1)) == NULL)
    my_putstr_error("[ERROR] : Can't allocate memory.\n");
  eof++;
  while (cmd[eof] != '\0')
    file[i++] = cmd[eof++];
  file[i] != '\0';
  return (file);
}

void	redirect_to(char *cmd, int redirect)
{
  char	*file;
  int	fd;

  file = get_file(cmd);
  if ((fd = open(file, O_WRONLY | O_CREAT, 0644)) == -1)
    my_putstr_error("[ERROR] : Can't open file.\n");
  if (dup2(fd, 1) == -1)
    my_putstr_error("[ERROR] : Can't copy file descriptor.\n");
  close(fd);
  while (*cmd)
    {
      if (*cmd == '>' || *cmd == '<')
	*cmd = '\0';
      *cmd++;
    }
}

int	check_redirect(char *cmd)
{
  int	i;

  i = 0;
  while (cmd[i] != '\0')
    {
      if (cmd[i] == '>')
	if (cmd[i + 1] == '>')
	  redirect_to(cmd, 2);
	else
	  redirect_to(cmd, 1);
      else if (cmd[i] == '<')
	if (cmd[i + 1] == '<')
	  redirect_to(cmd, 4);
	else
	  redirect_to(cmd, 3);
      i++;
    }
  return (0);
}
*/
