/*
** init_data.c for  in /home/jaunet_n/Rendu/PSU_2016_myftp
** 
** Made by Jaunet Nathan
** Login   <jaunet_n@epitech.eu>
** 
** Started on  Thu May 11 00:34:53 2017 Jaunet Nathan
** Last update Thu May 18 15:17:12 2017 Jaunet Nathan
*/

#include "myftp.h"
#include "global.h"

static int		get_same_ip(int fd)
{
  struct sockaddr_in	addr;
  socklen_t		addr_len;

  if (fd == -1)
    return (htons(INADDR_ANY));
  addr_len = sizeof(addr);
  getsockname(fd, (struct sockaddr*)&addr, &addr_len);
  return (addr.sin_addr.s_addr);
}

void			init_socketd(void)
{
  struct protoent       *pe;
  int			opt;

  if ((pe = getprotobyname("TCP")) == NULL)
    exerror("getprotobyname", 1);
  if ((data_fd = socket(AF_INET, SOCK_STREAM, pe->p_proto)) == -1)
    exerror("socket", 1);
  opt = 1;
  if (setsockopt(data_fd, SOL_SOCKET, SO_REUSEADDR,
		 (char *)&opt, sizeof(opt)) == -1)
    exerror("setsockopt", 1);
}

void			init_bindd(int port)
{
  struct sockaddr_in    s_in;

  s_in.sin_family = AF_INET;
  s_in.sin_port = htons(port);
  s_in.sin_addr.s_addr = get_same_ip(client_fd);
  if (bind(data_fd, (const struct sockaddr *)&s_in, sizeof(s_in)) == -1)
    {
      if (close(server_fd) == -1)
        exerror("close", 1);
      if (close(client_fd) == -1)
        exerror("close", 1);
      if (close(data_fd) == -1)
        exerror("close", 1);
      exerror("bind", 1);
    }
}

void			init_listend(void)
{
  if (listen(data_fd, 42) == -1)
    {
      if (close(server_fd) == -1)
        exerror("close", 1);
      if (close(client_fd) == -1)
        exerror("close", 1);
      if (close(data_fd) == -1)
        exerror("close", 1);
      exerror("listen", 1);
    }
}

void		init_data(int port)
{
  init_socketd();
  init_bindd(port);
  init_listend();
}

