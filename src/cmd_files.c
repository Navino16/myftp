/*
** cmd_files.c for  in /home/jaunet_n/Rendu/PSU_2016_myftp
** 
** Made by Jaunet Nathan
** Login   <jaunet_n@epitech.eu>
** 
** Started on  Wed May 10 22:37:04 2017 Jaunet Nathan
** Last update Sun May 21 15:32:47 2017 Jaunet Nathan
*/

#include "myftp.h"
#include "global.h"

void	cmd_cwd(char *cmd)
{
  char	*dir;

  dir = strtok(cmd, " ");
  dir = strtok(NULL, " ");
  if (chdir(dir) == 0)
    dprintf(client_fd, "250 Sucess\r\n");
  else
    dprintf(client_fd, "550 Invalid directory\r\n");
}

void	cmd_cdup(char *cmd)
{
  (void)cmd;
  if (chdir("..") == -1)
    dprintf(client_fd, "550 Can't change directory\r\n");
  else
    dprintf(client_fd, "200 Sucess\r\n");
}

void	cmd_dele(char *cmd)
{
  char	*buf;

  buf = strtok(cmd, " ");
  buf = strtok(NULL, " ");
  if (unlink(buf) == 0)
    dprintf(client_fd, "250 Sucess\r\n");
  else
    dprintf(client_fd, "450 Error Bad file\r\n");
}

void	cmd_pwd(char *cmd)
{
  char	*buf;

  (void)cmd;
  buf = NULL;
  buf = getcwd(buf, 1024);
  dprintf(client_fd, "257 %s\r\n", buf);
  free(buf);
}

void	cmd_list(char *cmd)
{
  int	oldfd;
  char	*command;

  command = createCmd(cmd, "ls -l ");
  mode == 1 ? accept_data() : 0;
  oldfd = dup(1);
  if (dup2(data_fd, 1) != -1)
    {
      dprintf(client_fd, "150\r\n");
      if (system(command) != 0)
	dprintf(client_fd, "550 Bad file for ls\r\n");
      else
	dprintf(client_fd, "226 End of list\r\n");
      dup2(oldfd, 1);
      close(data_fd);
    }
  else
    dprintf(client_fd, "450\r\n");
  free(command);
}
