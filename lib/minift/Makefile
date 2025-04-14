NAME		= libminift.a
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror -Iinclude
RM			= rm -rf
LIBC		= ar -rcs


SRC_DIR		= src/
OBJ_DIR 	= obj/
HEADER		= include/minift.h

SRC			= 	ft_atoi.c \
				ft_bzero.c \
				ft_da.c \
				ft_get_next_line.c \
				ft_isspace.c \
				ft_memcpy.c \
				ft_strdup.c \
				ft_strlen.c \
				ft_strnstr.c \
				ft_strtof.c \
				ft_strtrim.c 

OBJ			= $(addprefix $(OBJ_DIR), $(SRC:.c=.o))


$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@


$(NAME): $(OBJ)
	@echo ""${BLUE}$(NAME)""${NC} Archiving... "\c"
	@$(LIBC) $(NAME) $(OBJ)
	@echo ""${GREEN}OK""$(NC)""
	
all: $(NAME)

clean:
	@$(RM) $(OBJ_DIR)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus

WHITE	=	'\033[0;37m'
YELLOW	=	'\033[0;33m'
BLUE	=	'\033[0;34m'
GREEN	=	'\033[0;32m'
RED		=	'\033[0;31m'
NC		=	'\033[0m'