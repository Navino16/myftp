/*
** cmd_files2.c for  in /home/jaunet_n/Rendu/PSU_2016_myftp
** 
** Made by Jaunet Nathan
** Login   <jaunet_n@epitech.eu>
** 
** Started on  Sun May 21 15:34:33 2017 Jaunet Nathan
** Last update Sun May 21 22:06:15 2017 Jaunet Nathan
*/

#include "global.h"
#include "myftp.h"

void	cmd_nlst(char *cmd)
{
    int   oldfd;
  char  *command;

  command = createCmd(cmd, "ls -1a");
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
