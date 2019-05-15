# **************************************************************************** #
#                                                                              #
#                                                        				       #
#    Makefile                                           				       #
#                                                    					       #
#    By: Exyos <augeardw@gmail.com>                    				           #
#                                                 					           #
#    Created: 2019/05/15 18:24:02 by Exyos            				           #
#    Updated: 2019/05/15 18:37:03 by Exyos           					       #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = prog

SRC_PATH = ./src/
OBJ_PATH = ./obj/
INC_PATH = ./include

SRC_FILES = main.c 

#INC_FILES = ft_ssl.h 


OBJ_FILES = $(SRC_FILES:.c=.o)

OBJ_EXEC = $(addprefix $(OBJ_PATH),$(OBJ_FILES))


all: $(NAME)

$(OBJ_PATH) :
	mkdir $(OBJ_PATH) 2> /dev/null || true

$(OBJ_PATH)%.o : $(SRC_PATH)%.c
	$(CC) $(CFLAGS) -c $< -o $@ -I $(INC_PATH) 
	@echo "\033[1;32mCompilation of $(notdir $<) done.\033[0m"

$(NAME) : $(OBJ_PATH) $(OBJ_EXEC)
	$(CC) $(CFLAGS) $(OBJ_EXEC) -o $@ -I $(INC_PATH) 
	@echo "\nBinary \033[1;32m$(NAME)\033[1;0m created."

clean:
	rm -rf $(OBJ_PATH)
	@echo "\033[31mObjects files \033[1;31m$(OBJ_FILES)\033[1;0m\033[31m removed.\033[0m"
	

fclean: clean
	rm -f $(NAME)
	@echo "\033[31mExecutable \033[1;31m$(NAME)\033[1;0m\033[31m removed.\033[0m"

re: fclean all 

.PHONY: clean fclean