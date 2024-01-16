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
SILENT_FLAG 	:= --no-print-directory --silent

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
	@printf "$(NEW)$(PURPLE)[$(JP)] $(UGREEN)Building:$(DEFAULT)$(BWHITE) $@$(DEFAULT)"
	@$(CC) $(CFLAGS) $(OBJS) $(LIB) $(INCLD_FLAG) -o $@
	@printf "\n"

%.o: %.c
	@echo "$(CYAN)- Compiling $<$(DEFAULT)"
	@${CC} ${CFLAGS} -c $< -o $@

$(LIBFT):
	@echo '𓃰  Making libft 𓃰'
	@make -C $(LIBFT_DIR)

relib:
	@echo '𓃰   Remaking libft 𓃰'
	@make re -C $(LIBFT_DIR) $(SILENT_FLAG)

cleanlib:
	@echo '𓃰  Cleaning libft 𓃰'
	@make clean -C $(LIBFT_DIR) $(SILENT_FLAG)

fcleanlib:
	@echo '𓃰  Cleaning libft 𓃰'
	@make fclean -C $(LIBFT_DIR) $(SILENT_FLAG)

clean:
	@$(RM) $(OBJS) 

fclean: clean 
	@$(RM) $(NAME)

re : fclean $(NAME)

norm : 
	norminette ${SRCS} ${INCLDS}

.PHONY : all clean fclean re norm 