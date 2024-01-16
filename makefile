SRCS = 	
OBJS	= ${SRCS:.c=.o} ${PRT_SRCS:.c=.o} ${GNL_SRCS:.c=.o}
LIBFTNAME = libft.a
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
LIB = $(LIBFT)

NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

### COLORS ###
DEFAULT    	:= \033[0m
BLACK    	:= \033[0;30m
RED        	:= \033[0;31m
GREEN    	:= \033[0;32m
UGREEN    	:= \033[4;32m
YELLOW    	:= \033[;33m
BLUE    	:= \033[0;34m
PURPLE    	:= \033[0;35m
CYAN    	:= \033[0;36m
BWHITE    	:= \033[1;37m
NEW			:= \r\033[K

all: $(NAME)

$(NAME): $(LIB) $(OBJS)
	@ar rcs $(NAME) $(OBJS) $(LIB) -o $(NAME)
	@echo "$(RED)††††† Compilated ††††††$(DEFAULT)"

%.o: %.c
	@echo "$(CYAN)- Compiling $<$(DEFAULT)"
	@${CC} ${CFLAGS} -c $< -o $@

$(LIBFT):
	@echo '* Making libft'
	@make -C $(LIBFT_DIR)

relib:
	@echo '* Remaking libft'
	@make re -C $(LIBFT_DIR)

cleanlib:
	@echo '* Cleaning libft'
	@make clean -C $(LIBFT_DIR)

fcleanlib:
	@echo '* Cleaning libft'
	@make fclean -C $(LIBFT_DIR)

clean:
	@$(RM) $(OBJS) 

fclean: clean 
	@$(RM) $(NAME)

re : fclean $(NAME)

norm : 
	norminette ${SRCS} ${INCLDS}

.PHONY : all clean fclean re norm 