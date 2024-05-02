SRC =	m_src/ft_atoi.c\
		m_src/ft_memcpy.c\
		m_src/ft_split.c\
		m_src/ft_strjoin.c\
		m_src/list.c\
		m_src/moves.c\
		m_src/moves1.c\
		m_src/moves2.c\
		m_src/push_swap.c\
		m_src/swap.c\
		m_src/utils.c\
		m_src/utils1.c\
		m_src/utils2.c\
		m_src/algo1.c

B_SRC =	b_src/checker.c\
		b_src/ft_split.c\
		b_src/get_next_line.c\
		b_src/get_next_line_utils.c\
		b_src/moves.c\
		b_src/moves1.c\
		b_src/moves2.c\
		b_src/utils.c\
		b_src/utils1.c\
		b_src/list.c\
		b_src/ft_atoi.c\
		b_src/get_moves.c

CC = cc
CFLAGS = -Wall -Werror -Wextra

OBJ = $(SRC:.c=.o)
OBJ_B = $(B_SRC:.c=.o)
NAME = push_swap
B_NAME = checker
CFLAGS = -Wall -Wextra -Werror
CC = cc

all : $(NAME)

bonus : $(B_NAME)

$(B_NAME) : $(OBJ_B)
	@$(CC) $(CFLAGS) $(OBJ_B) -o $(B_NAME)
$(NAME) : $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
clean :
	@rm -f $(OBJ) $(OBJ_B)

fclean : clean
	@rm -f $(NAME) $(B_NAME)

re : fclean all

$(OBJ_B) : %.o : %.c
	@$(CC) $(CFLAGS) -c $< -o $@
$(OBJ) : %.o : %.c
	@$(CC) $(CFLAGS) -c $< -o $@
.SECONDARY: $(OBJ) $(OBJ_B)