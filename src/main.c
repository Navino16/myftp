/*
** main.c for  in /home/jaunet_n/Rendu/PSU_2016_myftp
** 
** Made by Jaunet Nathan
** Login   <jaunet_n@epitech.eu>
** 
** Started on  Tue May 16 16:18:03 2017 Jaunet Nathan
** Last update Wed May 17 09:01:47 2017 Jaunet Nathan
*/

#include "myftp.h"
#include "global.h"

int	errorClient(char *str, int ret)
{
  dprintf(client_fd, "%s\r\n", str);
  return (ret);
}

void    exerror(char *str, int ex)
{
  if (fcntl(client_fd, F_GETFD) != -1)
    close(client_fd);
  if (fcntl(server_fd, F_GETFD) != -1)
    close(server_fd);
  if (fcntl(data_fd, F_GETFD) != -1)
    close(data_fd);
  perror(str);
  fprintf(stderr, "Error with %s\n", str);
  exit(ex);
}

void    sig_handler(int sig)
{
  if (sig == SIGINT)
    {
      if (fcntl(client_fd, F_GETFD) != -1)
	close(client_fd);
      if (fcntl(server_fd, F_GETFD) != -1)
	close(server_fd);
      if (fcntl(data_fd, F_GETFD) != -1)
	close(data_fd);
      exit(0);
    }
}

int                     main(int ac, char **av)
{
  if (ac != 3)
    exerror("arguments", 1);
  if (signal(SIGINT, sig_handler) == SIG_ERR)
    exerror("signal", 1);
  if (chdir(av[2]) != 0)
    exerror("chdir", 1);
  start_ftp(atoi(av[1]));
  if (close(server_fd) == -1)
    exerror("close", 1);
  return (0);
}
