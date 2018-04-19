/*
** myftp.c for  in /home/jaunet_n/Rendu/PSU_2016_myftp
** 
** Made by Jaunet Nathan
** Login   <jaunet_n@epitech.eu>
** 
** Started on  Wed May 10 17:50:59 2017 Jaunet Nathan
** Last update Sun May 21 13:20:21 2017 Jaunet Nathan
*/

#include "global.h"
#include "myftp.h"
#include "ptr.h"

char		*cutCMD(char *buf)
{
  if (strlen(buf) > 0 && buf[strlen(buf) - 1] == '\n')
    buf[strlen(buf) - 1] = '\0';
  if (strlen(buf) > 0 && buf[strlen(buf) - 1] == '\r')
    buf[strlen(buf) - 1] = '\0';
  return (buf);
}

void		parseCMD(char *buf)
{
  char		*str;
  int		i;
  bool		exist;
  char		*cmd;

  i = 0;
  exist = false;
  buf = cutCMD(buf);
  cmd = strdup(buf);
  str = strtok(buf, " ");
  while (ptr_list[i].ptr)
    {
      if (str != NULL && strcmp(str, ptr_list[i].name) == 0)
	{
	  if (ptr_list[i].logged == 1 && user != 2)
	    dprintf(client_fd, "530 Not logged in.\r\n");
	  else
	    ptr_list[i].ptr(cmd);
	  exist = true;
	}
      i++;
    }
  if (exist == false)
    dprintf(client_fd, "500 Unknow command\r\n");
  free(cmd);
}

int		myftp(void)
{
  char		*buf;
  FILE		*tmp;
  size_t	n;

  dprintf(client_fd, "220 Welcome\r\n");
  tmp = fdopen(dup(client_fd), "r");
  buf = NULL;
  while (1)
    {
      if (getline(&buf, &n, tmp) == -1)
	{
	  fclose(tmp);
	  free(buf);
	  exerror("getline", 1);
	}
      fprintf(stderr, "! -> %s", buf);
      parseCMD(buf);
      if (strcmp(buf, "QUIT") == 0)
	break;
    }
  free(buf);
  fclose(tmp);
  if (fcntl(client_fd, F_GETFD) != -1)
    close(client_fd);
  exit(0);
}

