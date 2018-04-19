/*
** init_data2.c for  in /home/jaunet_n/Rendu/PSU_2016_myftp
** 
** Made by Jaunet Nathan
** Login   <jaunet_n@epitech.eu>
** 
** Started on  Sun May 21 13:37:26 2017 Jaunet Nathan
** Last update Sun May 21 14:25:21 2017 Jaunet Nathan
*/

#include "global.h"
#include "myftp.h"

void	init_data2(void)
{
  struct protoent       *pe;

  (pe = getprotobyname("TCP")) == NULL ? exerror("getprotobyname", 1) : 0;
  if ((data_fd = socket(AF_INET, SOCK_STREAM, pe->p_proto)) == -1)
    exerror("socket", 1);
}

void	printIp(char *ip)
{
  int	i;

  i = 0;
  while (ip[i] != '\0')
    {
      ip[i] == '.' ? dprintf(client_fd, ",")
	: dprintf(client_fd, "%c", ip[i]);
      i++;
    }
}
