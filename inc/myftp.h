/*
** myftp.h for  in /home/jaunet_n/Rendu/PSU_2016_myftp
** 
** Made by Jaunet Nathan
** Login   <jaunet_n@epitech.eu>
** 
** Started on  Mon May  8 19:51:15 2017 Jaunet Nathan
** Last update Sun May 21 15:38:49 2017 Jaunet Nathan
*/

#ifndef MYFTP_H_
#define MYFTP_H_

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <signal.h>
#include <stdio.h>
#include <stdbool.h>
#include <fcntl.h>

typedef struct	s_ptr
{
  char		*name;
  void		(*ptr)(char *cmd);
  int		logged;
}		t_ptr;

void	start_ftp(int port);
void	init_data(int port);
void	exerror(char *str, int ex);
int	errorClient(char *str, int ret);
int	myftp(void);

/* cmd_auth.c */
void	cmd_user(char *cmd);
void	cmd_pass(char *cmd);
void	cmd_quit(char *cmd);
/* cmd_info.c */
void	cmd_syst(char *cmd);
void	cmd_help(char *cmd);
void	cmd_noop(char *cmd);
void	cmd_type(char *cmd);
/* cmd_files.c */
void	cmd_cwd(char *cmd);
void	cmd_cdup(char *cmd);
void	cmd_dele(char *cmd);
void	cmd_pwd(char *cmd);
void	cmd_list(char *cmd);
/* cmd_files2.c */
void	cmd_nlst(char *cmd);
/* cmd_transfer.c */
void	cmd_pasv(char *cmd);
void	cmd_port(char *cmd);
void	cmd_retr(char *cmd);
void	cmd_stor(char *cmd);
/* utils_files.c */
void	accept_data(void);
int	isValid(char *file);
char	*createCmd(char *buf, char *ls);
char	*makeIp(char *cmd);
int	makePort(char *cmd);
/* init_data2 */
void	init_data2(void);
void	printIp(char *ip);
/* cmd_dir */
void	cmd_mkd(char *cmd);
void	cmd_rmd(char *cmd);

#endif /* MYFTP_H_ */
