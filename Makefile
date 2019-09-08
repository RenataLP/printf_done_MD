# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lgeorgia <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/10 14:44:36 by lgeorgia          #+#    #+#              #
#    Updated: 2019/04/10 15:21:38 by lgeorgia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

C = clang

NAME = libftprintf.a

FLAGS = -Wall -Wextra -Werror

LIBFT = sources/libft

DIR_S = sources

DIR_O = temporary

HEADER = include

SOURCES = flagsets.c \
		  d.c \
		  o.c \
		  s.c \
		  longarifmetika.c \
		  longarifmetikaanother.c \
		  floatconc.c \
		  printf.c \
		  read_arg.c \
		  x.c \
		  proc.c \
		  c.c \
		  newint.c \
		  u.c \
		  p.c \
		  d2.c \
		  flagsetspart2.c \
		  norm.c \
		  norm2.c \
		  check_beats.c \
		  float_other.c \
		  mantisa_calc.c \
		  calc_summ.c \
		  infinity.c \
          nan.c \
          f.c \
          o2.c \

SRCS = $(addprefix $(DIR_S)/,$(SOURCES))

OBJS = $(addprefix $(DIR_O)/,$(SOURCES:.c=.o))

all: $(NAME)

$(NAME): $(OBJS)
	@make -C $(LIBFT)
	@cp sources/libft/libft.a ./$(NAME)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)

$(DIR_O)/%.o: $(DIR_S)/%.c
	@mkdir -p temporary
	@$(CC) $(FLAGS) -I $(HEADER) -o $@ -c $<

clean:
	@rm -rf $(DIR_O)
	@rm -f $(OBJS)
	@make clean -C $(LIBFT)

fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(LIBFT)


re: fclean all