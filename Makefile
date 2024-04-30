# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hfazaz <hfazaz@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/28 08:17:19 by hfazaz            #+#    #+#              #
#    Updated: 2024/04/30 08:41:58 by hfazaz           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCC=client.c utils.c
SRCCB=client_bonus.c utils.c

OBJC = $(SRCC:.c=.o)
OBJCB = $(SRCCB:.c=.o)

SRCS=server.c
SRCSB=server_bonus.c

OBJS = $(SRCS:.c=.o)
OBJSB = $(SRCSB:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror

SERVER = server
CLIENT = client

SERVER_BONUS = server_bonus
CLIENT_BONUS = client_bonus

all:$(SERVER) $(CLIENT)

$(SERVER): $(SRCS)
			$(CC) $(CFLAGS) $(SRCS) -o server

$(SERVER_BONUS): $(SRCSB)
			$(CC) $(CFLAGS) $(SRCSB) -o server_bonus

$(CLIENT): $(SRCC)
			$(CC) $(CFLAGS) $(SRCC) -o client

$(CLIENT_BONUS): $(SRCCB)
			$(CC) $(CFLAGS) $(SRCCB) -o client_bonus
clean: 
		rm -rf $(OBJC) $(OBJS)
		rm -rf $(OBJCB) $(OBJSB) 

fclean: clean
		rm -rf $(SERVER) $(CLIENT)
		rm -rf $(SERVER_BONUS) $(CLIENT_BONUS)

re :fclean all
bonus:$(SERVER_BONUS) $(CLIENT_BONUS)