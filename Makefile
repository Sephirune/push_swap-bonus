SRC_DIR = src
LIBFT_DIR = libft
PRINTF_DIR = printf
LIBFT = $(LIBFT_DIR)/libft.a
PRINTF = $(PRINTF_DIR)/libftprintf.a

SRCS			=	$(SRC_DIR)/operations/ft_push_a.c\
					$(SRC_DIR)/operations/ft_push_b.c\
					$(SRC_DIR)/operations/ft_reverse_a.c\
					$(SRC_DIR)/operations/ft_reverse_b.c\
					$(SRC_DIR)/operations/ft_rotate_a.c\
					$(SRC_DIR)/operations/ft_rotate_b.c\
					$(SRC_DIR)/operations/ft_rr.c\
					$(SRC_DIR)/operations/ft_rrr.c\
					$(SRC_DIR)/operations/ft_swap_a.c\
					$(SRC_DIR)/operations/ft_swap_b.c\
					$(SRC_DIR)/operations/ft_swap_ab.c\
					$(SRC_DIR)/operations/ft_lstsize.c\
					$(SRC_DIR)/operations/ft_lstadd_back.c\
					$(SRC_DIR)/operations/ft_lstlast.c\
					$(SRC_DIR)/operations/ft_lstnew.c\
					$(SRC_DIR)/algorithm/ft_atoi.c\
					$(SRC_DIR)/algorithm/utils.c\
					$(SRC_DIR)/algorithm/utils2.c\
					$(SRC_DIR)/algorithm/utils3.c\

PUSH_SWAP_SRCS	=	$(SRC_DIR)/algorithm/push_swap.c\
					$(SRC_DIR)/algorithm/sorting.c

CHECKER_SRCS	=	$(SRC_DIR)/algorithm/checker.c\
					$(SRC_DIR)/algorithm/get_next_line_bonus.c\
					$(SRC_DIR)/algorithm/get_next_line_utils_bonus.c

OBJS			=	$(SRCS:.c=.o)
PUSH_SWAP_OBJS	=	$(PUSH_SWAP_SRCS:.c=.o)
CHECKER_OBJS	=	$(CHECKER_SRCS:.c=.o)

CC			=	cc
RM			=	rm -f
CFLAGS			=	-Wall -Wextra -Werror -I includes -I $(LIBFT_DIR) -I $(PRINTF_DIR)

NAME			=	push_swap
BONUS_NAME		=	checker

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all:			$(NAME)

$(NAME):	$(OBJS) $(PUSH_SWAP_OBJS)
	make -C $(LIBFT_DIR)
	make -C $(PRINTF_DIR)
	$(CC) $(CFLAGS) $(OBJS) $(PUSH_SWAP_OBJS) $(LIBFT) $(PRINTF) -o $(NAME)

bonus:	$(BONUS_NAME)

$(BONUS_NAME): $(OBJS) $(CHECKER_OBJS)
	make -C $(LIBFT_DIR)
	make -C $(PRINTF_DIR)
	$(CC) $(CFLAGS) $(OBJS) $(CHECKER_OBJS) $(LIBFT) $(PRINTF) -o $(BONUS_NAME)

clean:
	$(RM) $(OBJS) $(PUSH_SWAP_OBJS) $(CHECKER_OBJS)
	make -C $(LIBFT_DIR) clean
	make -C $(PRINTF_DIR) clean

fclean:	clean
	$(RM) $(NAME) $(BONUS_NAME)
	make -C $(LIBFT_DIR) fclean
	make -C $(PRINTF_DIR) fclean

re:			fclean 
			$(NAME) all

.PHONY:			all clean fclean re
