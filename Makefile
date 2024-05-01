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
		m_src/algo1.c
CC = cc
CFLAGS = -Wall -Werror -Wextra

OBJ = $(SRC:.c=.o)
NAME = push_swap
CFLAGS = -Wall -Wextra -Werror
CC = cc

all : $(NAME)

$(NAME) : $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
clean :
	@rm -f $(OBJ)

fclean : clean
	@rm -f $(NAME)

re : fclean all

$(OBJ) : %.o : %.c
	@$(CC) $(CFLAGS) -c $< -o $@
.SECONDARY: $(OBJ)