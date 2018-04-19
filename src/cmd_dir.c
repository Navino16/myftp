/*
** cmd_dir.c for  in /home/jaunet_n/Rendu/PSU_2016_myftp
** 
** Made by Jaunet Nathan
** Login   <jaunet_n@epitech.eu>
** 
** Started on  Sun May 21 14:56:29 2017 Jaunet Nathan
** Last update Sun May 21 15:20:37 2017 Jaunet Nathan
*/

#include "global.h"
#include "myftp.h"

void	cmd_mkd(char *cmd)
{
  char	*buf;
  struct stat st;

  buf = strtok(cmd, " ");
  buf = strtok(NULL, " ");
  if (stat(buf, &st) == -1)
    {
      if (mkdir(buf, 0755) == -1)
	dprintf(client_fd, "550 Error can't create directory\r\n");
      else
	dprintf(client_fd, "257 Directory sucessfuly created\r\n");
    }
  else
    dprintf(client_fd, "550 Directory already exist\r\n");
}

void	cmd_rmd(char *cmd)
{
  char	*buf;

  buf = strtok(cmd, " ");
  buf = strtok(NULL, " ");

  if (rmdir(buf) == -1)
    dprintf(client_fd, "550 Invalid directory (or not empty)\r\n");
  dprintf(client_fd, "250 Directory sucessfuly deleted\r\n");
}
