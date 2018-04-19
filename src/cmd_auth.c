/*
** cmd_auth.c for  in /home/jaunet_n/Rendu/PSU_2016_myftp
** 
** Made by Jaunet Nathan
** Login   <jaunet_n@epitech.eu>
** 
** Started on  Wed May 10 21:54:14 2017 Jaunet Nathan
** Last update Thu May 18 18:34:45 2017 Jaunet Nathan
*/

#include "myftp.h"
#include "global.h"

void	cmd_user(char *cmd)
{
  char	*buf;

  buf = strtok(cmd, " ");
  buf = strtok(NULL, " ");
  user = 1;
  if (strcmp(buf, "Anonymous") == 0)
    user = 0;
  dprintf(client_fd, "331 Need password.\r\n");
}

void	cmd_pass(char *cmd)
{
  (void)cmd;
  if (user == 0)
    {
      user = 2;
      dprintf(client_fd, "230 User logged in, proceed.\r\n");
    }
  else
    dprintf(client_fd, "530 Login incorrect.\r\n");
}

void	cmd_quit(char *cmd)
{
  (void)cmd;
  printf("--> QUIT: 221\n");
  dprintf(client_fd, "221 End of conection\r\n");
}
