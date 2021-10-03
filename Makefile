# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dteixeir <dteixeir@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/28 00:32:35 by dteixeir          #+#    #+#              #
#    Updated: 2021/10/03 17:41:09 by dteixeir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_SERVER = server
NAME_CLIENT = client

CC = clang
CFLAGS = -Werror -Wall -Wextra
INCLUDE = ./include/minitalk.h

SRC = ./src/

SERVER = $(SRC)server.c
CLIENT = $(SRC)client.c

SERVER_OBJ = $(SERVER:.c=.o)
CLIENT_OBJ = $(CLIENT:.c=.o)

all: $(NAME_SERVER) $(NAME_CLIENT) $(INCLUDE)

$(NAME_SERVER): $(SERVER_OBJ)
	@$(CC) $(CFLAGS) -o $(NAME_SERVER) $(SERVER_OBJ)
	@echo "Compiling server............................\033[92m ✔\033[0m\n"
$(NAME_CLIENT): $(CLIENT_OBJ)
	@$(CC) $(CFLAGS) -o $(NAME_CLIENT) $(CLIENT_OBJ)
	@echo "Compiling client............................\033[92m ✔ \033[0m\n"
	
	@echo "\033[35m                Hello!                   \033[0m"
	@echo "\033[35m          Welcome to Minitalk!           \033[0m\n"
	@echo "\033[36m In this terminal, please run ./server    \033[0m"
	@echo "\033[36m Then, in another terminal, run ./client  \033[0m\n"
	@echo "\033[35m       ٩(^‿^)۶ HAVE FUN! ٩(^‿^)۶       \033[0m\n"

clean:
	@rm -f $(SERVER_OBJ) $(CLIENT_OBJ) 

fclean: clean
	@rm -f $(NAME_SERVER) $(NAME_CLIENT) 

re: fclean all

.PHONY: all clean fclean re bonus rebonus
