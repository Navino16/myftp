/*
** utils_files.c for  in /home/jaunet_n/Rendu/PSU_2016_myftp
** 
** Made by Jaunet Nathan
** Login   <jaunet_n@epitech.eu>
** 
** Started on  Tue May 16 16:36:27 2017 Jaunet Nathan
** Last update Sun May 21 15:33:12 2017 Jaunet Nathan
*/

#include "myftp.h"
#include "global.h"

void	accept_data(void)
{
  socklen_t             s_in_size;
  struct sockaddr_in    s_in_client;
  int			tmp;

  s_in_size = sizeof(s_in_client);
  tmp = data_fd;
  if ((data_fd = accept(tmp, (struct sockaddr *)&s_in_client,
                        &s_in_size)) == -1)
    {
      if (close(server_fd) == -1)
       exerror("close", 1);
      exerror("accept", 1);
    }
  close(tmp);
}

int		isValid(char *file)
{
  struct stat	st;

  if (!stat(file, &st) && S_ISREG(st.st_mode))
    return (0);
  else
    return (-1);
}

char	*createCmd(char *cmd, char *ls)
{
  char	*command;
  char	*buf;

  buf = strtok(cmd, " ");
  buf = strtok(NULL, " ");
  if (buf != NULL)
    {
      if ((command = malloc(sizeof(char *) *
                            (1 + strlen(buf) + strlen(ls)))) == NULL)
        exerror("malloc", 1);
      command = strcpy(command, ls);
      command = strcat(command, buf);
    }
  else
    command = strdup(ls);
  return (command);
}

char	*makeIp(char *cmd)
{
  char	*ip[4];
  char	*buf;
  char	*ipaddr;

  buf = strtok(cmd, " ");
  buf = strtok(NULL, " ");
  ip[0] = strtok(buf, ",");
  ip[1] = strtok(NULL, ",");
  ip[2] = strtok(NULL, ",");
  ip[3] = strtok(NULL, ",");
  if ((ipaddr = malloc(sizeof(char *) * (strlen(ip[0]) + strlen(ip[1])
					 + strlen(ip[2]) + strlen(ip[3])
					 + 4))) == NULL)
    exerror("malloc", 1);
  ipaddr = strcpy(ipaddr, ip[0]);
  ipaddr = strcat(ipaddr, ".");
  ipaddr = strcat(ipaddr, ip[1]);
  ipaddr = strcat(ipaddr, ".");
  ipaddr = strcat(ipaddr, ip[2]);
  ipaddr = strcat(ipaddr, ".");
  ipaddr = strcat(ipaddr, ip[3]);
  free(cmd);
  return (ipaddr);
}

int	makePort(char *cmd)
{
  char	*buf;
  int	port1;
  int	port2;

  buf = strtok(cmd, " ");
  buf = strtok(NULL, " ");
  buf = strtok(buf, ",");
  buf = strtok(NULL, ",");
  buf = strtok(NULL, ",");
  buf = strtok(NULL, ",");
  port1 = atoi(strtok(NULL, ","));
  port2 = atoi(strtok(NULL, ","));
  free(cmd);
  return ((port1 * 256) + port2);
}
