/*
** init.c for  in /home/jaunet_n/Rendu/PSU_2016_myftp
** 
** Made by Jaunet Nathan
** Login   <jaunet_n@epitech.eu>
** 
** Started on  Wed May 10 16:49:31 2017 Jaunet Nathan
** Last update Sun May 21 13:20:06 2017 Jaunet Nathan
*/

#include "myftp.h"
#include "global.h"

void			init_socket(void)
{
  struct protoent       *pe;
  int			opt;

  if ((pe = getprotobyname("TCP")) == NULL)
    exerror("getprotobyname", 1);
  if ((server_fd = socket(AF_INET, SOCK_STREAM, pe->p_proto)) == -1)
    exerror("socket", 1);
  opt = 1;
  if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR,
		 (char *)&opt, sizeof(opt)) == -1)
    exerror("setsockopt", 1);
}

void			init_bind(int port)
{
  struct sockaddr_in    s_in;

  s_in.sin_family = AF_INET;
  s_in.sin_port = htons(port);
  s_in.sin_addr.s_addr = INADDR_ANY;
  if (bind(server_fd, (const struct sockaddr *)&s_in, sizeof(s_in)) == -1)
    {
      if (close(server_fd) == -1)
        exerror("close", 1);
      exerror("bind", 1);
    }
}

void			init_listen(void)
{
  if (listen(server_fd, 42) == -1)
    {
      if (close(server_fd) == -1)
        exerror("close", 1);
      exerror("listen", 1);
    }
}

void	start_co_client(void)
{
  socklen_t             s_in_size;
  struct sockaddr_in    s_in_client;

  s_in_size = sizeof(s_in_client);
  while (1)
    {
      if ((client_fd = accept(server_fd, (struct sockaddr *)&s_in_client,
			      &s_in_size)) == -1)
        {
          if (close(server_fd) == -1)
	    exerror("close", 1);
	  exerror("accept", 1);
        }
      else
        {
          if (fork() == 0)
	    myftp();
	  else
            if (close(client_fd) == -1)
              exerror("close", 1);
        }
    }
}

void		start_ftp(int port)
{
  init_socket();
  init_bind(port);
  init_listen();
  start_co_client();
}

