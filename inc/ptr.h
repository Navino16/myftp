/*
** ptr.h for  in /home/jaunet_n/Rendu/PSU_2016_myftp
** 
** Made by Jaunet Nathan
** Login   <jaunet_n@epitech.eu>
** 
** Started on  Wed May 10 23:05:29 2017 Jaunet Nathan
** Last update Sun May 21 15:39:22 2017 Jaunet Nathan
*/

#ifndef PTR_H_
#define PTR_H_

static t_ptr  ptr_list[] = {
  {"USER", &cmd_user, 0}, {"PASS", &cmd_pass, 0},
  {"CWD", &cmd_cwd, 1}, {"CDUP", &cmd_cdup, 1},
  {"QUIT", &cmd_quit, 0}, {"DELE", cmd_dele, 1},
  {"PWD", &cmd_pwd, 1}, {"PASV", &cmd_pasv, 1},
  {"PORT", &cmd_port, 1}, {"HELP", &cmd_help, 0},
  {"NOOP", &cmd_noop, 0}, {"RETR", &cmd_retr, 1},
  {"STOR", &cmd_stor, 1}, {"LIST", &cmd_list, 1},
  {"SYST", &cmd_syst, 0}, {"TYPE", &cmd_type, 1},
  {"MKD", &cmd_mkd, 1}, {"RMD", &cmd_rmd, 1},
  {"NLST", &cmd_nlst, 1}, {NULL, NULL, 0}};

#endif /* PTR_H_ */
