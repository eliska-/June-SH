/*
** my_sh.h for Minishell1 in /home/benaro_k/rendu/PSU_2013_minishell1
** 
** Made by Kevin BENAROCHE
** Login   <benaro_k@epitech.net>
** 
** Started on  Mon Jan  6 18:23:36 2014 Kevin BENAROCHE
** Last update Tue May 13 16:43:17 2014 Kevin BENAROCHE
*/

#ifndef MY_SH_
# define MY_SH_

# define ERR_MALLOC "[ERROR] : Can't allocate memory.\n"
# define BSIZE 20

char	*get_next_line(const int fd);
char	*my_get_current_dir(char **env);
char    *getenv_value(char *str, char **env);
char	*get_args(char *buffer, char *args);
char	**put_args(char *cmd, char *buffer);
char	**envcpy(char **env);
char	**put_args(char *cmd, char *buffer);
char	*del_begin_spaces(char *str);
char	*del_end_spaces(char *str);
char	*tab_to_space(char *str);
char	*parse_dotcoma(char *buffer);
char	*pure_str(char *str);
int	addenv_value(char *name, char *value, char ***env);
char	*get_prompt();
char	*pure_str(char *str);
char	*parse_dotcoma(char *buffer);
char	*get_paths();
char	*get_path(char *path);
char	*get_exe(char *exe, char **env);
char	*get_args(char *buffer, char *args);
void	get_cmd(char *buffer, char ***env);
void	launch_exe(char *exe, char **args, char **env);
int	get_env(char **env);
int     search_env(char *str, char *env);
int	check_cmd(char **args, char *cmd, char *buffer, char ***env);
int	my_putstr_error(char *str);
int	arg_len(char *buffer, int start);
int	infos_args(char *buffer, int *nbargs, int *lenarg);
int	cd(char *path, char *option, char ***env);
int	free_tab(char **args);
int     getenv_nb(char **env);
int	setenv_value(char *str, char *value, char ***env);
int	good_bye(char **args, char *cmd, char *buffer, char **env);

#endif /*MY_SH_*/
