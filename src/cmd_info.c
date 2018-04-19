/*
** cmd_info.c for  in /home/jaunet_n/Rendu/PSU_2016_myftp
** 
** Made by Jaunet Nathan
** Login   <jaunet_n@epitech.eu>
** 
** Started on  Wed May 10 21:58:45 2017 Jaunet Nathan
** Last update Sun May 21 15:20:19 2017 Jaunet Nathan
*/

#include "myftp.h"
#include "global.h"

void	cmd_syst(char *cmd)
{
  (void)cmd;
  dprintf(client_fd, "215 UNIX\r\n");
}

void	help2(void)
{
  dprintf(client_fd, "PASV <CRLF>\t\t\t: Enable \"passive\" mode for\
 data transfer\r\n");
  dprintf(client_fd, "PORT <SP> <host-port> <CRLF>\t: Enable \"active\"\
 mode for data transfer\r\n");
  dprintf(client_fd, "RETR <SP> <pathname> <CRLF>\t: Download file from\
 server to client\r\n");
  dprintf(client_fd, "STOR <SP> <pathname> <CRLF>\t: Upload file from client\
 to server\r\n");
  dprintf(client_fd, "MKD <SP> <pathname> <CRLF>\t: Create directory\r\n");
  dprintf(client_fd, "RMD <SP> <pathname> <CRLF>\t: Delete directory\r\n");
}

void	cmd_help(char *cmd)
{
  (void)cmd;
  dprintf(client_fd, "214- This is list of available commande :\r\n");
  dprintf(client_fd, "USER <SP> <username> <CRLF>\t: Specify user for\
 authentication\r\n");
  dprintf(client_fd, "PASS <SP> <password> <CRLF>\t: Specify password\
for authentication\r\n");
  dprintf(client_fd, "QUIT <CRLF>\t\t\t: Disconnection\r\n");
  dprintf(client_fd, "SYST <CRLF>\t\t\t: Print information system\r\n");
  dprintf(client_fd, "HELP <CRLF>\t\t\t: Print this help\r\n");
  dprintf(client_fd, "NOOP <CRLF>\t\t\t: Do nothing\r\n");
  dprintf(client_fd, "CWD  <SP> <pathname> <CRLF>\t: Change working\
 directory\r\n");
  dprintf(client_fd, "CDUP <CRLF>\t\t\t: Change working directory\
 to parent directory\r\n");
  dprintf(client_fd, "DELE <SP> <pathname> <CRLF>\t: Delete file\
 on the server\r\n");
  dprintf(client_fd, "PWD  <CRLF>\t\t\t: Print working directory\r\n");
  dprintf(client_fd, "LIST [<SP> <pathname>] <CRLF>\t: List files in\
 the current working directory\r\n");
  help2();
  dprintf(client_fd, "214 End of help\r\n");
}

void	cmd_noop(char *cmd)
{
  (void)cmd;
  printf("--> NOOP: 200\n");
  dprintf(client_fd, "200 Ok\r\n");
}

void	cmd_type(char *cmd)
{
  (void)cmd;
  if (user != 2)
    dprintf(client_fd, "530 Not logged in.\r\n");
  else
    dprintf(client_fd, "200 Ok\r\n");
}
