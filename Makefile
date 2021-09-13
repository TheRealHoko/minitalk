NAME = minitalk

CC = gcc

CFLAGS = -Wall -Werror -Wextra

SERVER = src/server.c

CLIENT = src/client.c

INC = -I./inc

SRC =	src/utils.c \
		src/utils2.c

OBJ = $(SRC:.c=.o)

$(NAME) : server client

all : $(NAME)

server : $(OBJ)
	$(CC) $(CFLAGS) $(INC) -o server $(SERVER) $(OBJ)

client : $(OBJ)
	$(CC) $(CFLAGS) $(INC) -o client $(CLIENT) $(OBJ)

.c.o :
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f client
	rm -f server

re : fclean $(NAME)

.PHONY : all server client clean fclean re
