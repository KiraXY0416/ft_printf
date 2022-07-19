NAME	= libftprintf.a
INCLUDE	= include
LIBFT	= libft
SRC_DIR	= src/
OBJ_DIR	= obj/
CC		= gcc
CFLAGS	= -Wall -Werror -Wextra -I
RM		= rm -f
AR		= ar rcs

SRC_FILES	=	ft_printf ft_printf_utils ft_printf_ptr ft_printf_unsigned ft_printf_hex

SRC			= 	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ			=	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))

all:		$(NAME)

$(NAME):	$(OBJ)
				@make -C $(LIBFT)
				@cp libft/libft.a
				@mv libft.a $(NAME)
				@$(AR) $(NAME) $(OBJ)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJF)
				@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(OBJF):
				@mkdir -p $(OBJ_DIR)

clean:
				@$(RM) -rf $(OBJ_DIR)
				@make clean -C $(LIBFT)

fclean: 	clean
				@$(RM) -f $(NAME)
				@$(RM) -f $(LIBFT)/libft.a

re:				fclean all

norm:
				@norminette $(SRC) $(INCLUDE) $(LIBFT) | grep -v Norme -B1 || true
