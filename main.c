/*
** main.c for MiniShell1 in /home/benaro_k/rendu/PSU_2013_minishell1
** 
** Made by Kevin BENAROCHE
** Login   <benaro_k@epitech.net>
** 
** Started on  Mon Jan  6 18:19:46 2014 Kevin BENAROCHE
** Last update Tue May 20 14:15:51 2014 Kevin BENAROCHE
*/

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "my_sh.h"

char    *get_exe(char *exe, char **env)
{
  char  *fullpath;
  char  *path;

  if ((path = get_paths(env)) == NULL)
    return (NULL);
  if ((fullpath = malloc(strlen(exe) + strlen(path) + 2)) == NULL)
    my_putstr_error("[ERROR] : Can't allocate memory.\n");
  fullpath[0] = '\0';
  strcat(fullpath, path);
  strcat(fullpath, "/");
  strcat(fullpath, exe);
  free(path);
  return (fullpath);
}

void	launch_exe(char *exe, char **args, char **env)
{
  pid_t	pid;
  int	status;
  char	*fullpath;

  if ((pid = fork()) == -1)
    my_putstr_error("[ERROR] : Fork problem\n");
  if (pid == 0)
    {
      if ((execve(exe, args, env)) != -1)
	exit(0);
      while ((fullpath = get_exe(exe, env)) != NULL)
	{
	  if ((execve(fullpath, args, env)) != -1)
	    {
	      free(fullpath);
	      exit(0);
	    }
	  free(fullpath);
	}
      my_putstr_error(exe);
      my_putstr_error(" : Command not found\n");
    }
  else
    wait(&status);
}

int	check_cmd(char **args, char *cmd, char *buffer, char ***env)
{
  //tab de func sur ptr
  if (my_strstr(args[0], "cd") == 0)
    return (cd(args[1], args[1], env));
  if (my_strstr(args[0], "setenv") == 0)
    return (my_setenv(args[1], args[2], env));
  if (my_strstr(args[0], "unsetenv") == 0)
    return (my_unsetenv(args[1], env));
  if (my_strstr(args[0], "env") == 0)
    return (get_env(*env));
  if (my_strstr(args[0], "exit") == 0)
    good_bye(args, cmd, buffer, *env);
  if (my_strstr(args[0], "echo") == 0)
    return (my_echo(args));
  return (1);
}

void    get_cmd(char *buffer, char ***env)
{
  char  *cmd;
  char  **args;
  int   lencmd;

  lencmd = 0;
  while (buffer[lencmd] != ' ' && buffer[lencmd] != '\0')
    lencmd++;
  if (lencmd != 0)
    {
      if ((cmd = malloc(sizeof(char) * lencmd + 1)) == NULL)
	my_putstr_error("[ERROR] : Can't allocate memory.\n");
      cmd[lencmd] = '\0';
      while (lencmd-- > 0)
	cmd[lencmd] = buffer[lencmd];
      args = put_args(cmd, buffer);
      if (check_cmd(args, cmd, buffer, env) == 1)
	launch_exe(args[0], args, *env);
      free_tab(args);
      free(cmd);
    }
}

int     main(int argc, char *argv[], char **envp)
{
  char	*buf;
  char	*cmd;
  char	**env;

  if (envp == NULL)
    my_putstr_error("Can't find environement variables.\n");
  env = envcpy(envp);
  while (42)
    {
      //buf = get_prompt();
      write(1, "$>", 2);
      if ((buf = get_next_line(0)) != NULL)
	{
	  buf = pure_str(buf);
	  if (strlen(buf) > 0)
	    while ((cmd = parse_dotcoma(buf)) != NULL)
	      {
		get_cmd(cmd, &env);
		free(cmd);
	      }
	}
      free(buf);
    }
}
