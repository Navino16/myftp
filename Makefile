##
## Makefile for  in /home/jaunet_n/Rendu/PSU_2016_myftp
## 
## Made by Jaunet Nathan
## Login   <jaunet_n@epitech.eu>
## 
## Started on  Mon May  8 19:43:24 2017 Jaunet Nathan
## Last update Sun May 21 15:38:00 2017 Jaunet Nathan
##

NAME	=	server

SRCS	=	src/main.c		\
		src/init.c		\
		src/myftp.c		\
		src/cmd_info.c		\
		src/cmd_auth.c		\
		src/cmd_files.c		\
		src/cmd_files2.c	\
		src/cmd_transfer.c	\
		src/cmd_dir.c		\
		src/init_data.c		\
		src/init_data2.c	\
		src/utils_files.c

OBJS	=	$(SRCS:.c=.o)

INC	=	-I./inc

CFLAGS	=	-W -Wall -Werror -Wextra $(INC)

CC	=	gcc -g

RM	=	rm -rf

all	:	$(NAME)

$(NAME)	:	$(OBJS)
		$(CC) -o $(NAME) $(OBJS)

clean	:
		$(RM) $(OBJS)

fclean	:	clean
		$(RM) $(NAME)

re	:	fclean all
