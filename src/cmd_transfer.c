/*
** cmd_transfer.c for  in /home/jaunet_n/Rendu/PSU_2016_myftp
** 
** Made by Jaunet Nathan
** Login   <jaunet_n@epitech.eu>
** 
** Started on  Wed May 10 22:47:14 2017 Jaunet Nathan
** Last update Sun May 21 14:36:25 2017 Jaunet Nathan
*/

#include "myftp.h"
#include "global.h"

void	cmd_pasv(char *cmd)
{
  struct sockaddr_in    addr;
  socklen_t		addr_len;
  char			*ip;

  (void)cmd;
  init_data(0);
  if (data_fd != -1)
    {
      addr_len = sizeof(addr);
      getsockname(data_fd, (struct sockaddr*)&addr, &addr_len);
      ip = inet_ntoa(addr.sin_addr);
      dprintf(client_fd, "227 Passiv mode activated (");
      printIp(ip);
      dprintf(client_fd, ",%d,%d)\r\n", ntohs(addr.sin_port) / 256,
	      ntohs(addr.sin_port) % 256);
      mode = 1;
    }
  else
    dprintf(client_fd, "421 Service not available.\r\n");
}

void			cmd_port(char *cmd)
{
  char			*ip;
  int			port;
  struct sockaddr_in	s_in;

  ip = makeIp(strdup(cmd));
  port = makePort(strdup(cmd));
  init_data2();
  if (data_fd != -1)
    {
      s_in.sin_family = AF_INET;
      s_in.sin_port = htons(port);
      s_in.sin_addr.s_addr = inet_addr(ip);
      if (connect(data_fd, (struct sockaddr *)&s_in, sizeof(s_in)) == -1)
	exerror("connect", 1);
      else
	{
	  free(ip);
	  mode = 0;
	  dprintf(client_fd, "200 Connection ok\r\n");
	  return;
	}
    }
  dprintf(client_fd, "421 Service not available\r\n");
  free(ip);
}

void	cmd_retr(char *cmd)
{
  char	*file;
  int	fd;
  char	buf[1024];
  int	rd;

  mode == 1 ? accept_data() : 0;
  if (data_fd != -1)
    {
      file = strtok(cmd, " ");
      file = strtok(NULL, " ");
      if ((fd = open(file, O_RDONLY)) == -1 || isValid(file) == -1)
	errorClient("550 This file doesn't exist\r\n", 1);
      else
	{
	  dprintf(client_fd, "150 Connexion ready\r\n");
	  buf[0] = '\0';
	  while ((rd = read(fd, buf, 1024)) > 0)
	    write(data_fd, buf, rd);
	  dprintf(client_fd, "226 End of transmission\r\n");
	  close(fd);
	}
      close(data_fd);
    }
}

void	cmd_stor(char *cmd)
{
  char	*file;
  int	fd;
  char	buf[1024];
  int	rd;

  mode == 1 ? accept_data() : 0;
  if (data_fd != -1)
    {
      file = strtok(cmd, " ");
      file = strtok(NULL, " ");
      if ((fd = open(file, O_WRONLY | O_CREAT, 0644)) == -1)
	errorClient("550 Impossible to creat file\r\n", 1);
      else
	{
	  dprintf(client_fd, "150 Connexion ready\r\n");
	  buf[0] = '\0';
	  while ((rd = read(data_fd, buf, 1024)) > 0)
	    write(fd, buf, rd);
	  dprintf(client_fd, "226 End of transmission\r\n");
	  close(fd);
	}
      close(data_fd);
    }
}
