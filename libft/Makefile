# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aernie <aernie@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/10 12:10:20 by aernie            #+#    #+#              #
#    Updated: 2019/07/25 16:19:36 by aernie           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a 

SRC = ft_isdigit.c ft_isalpha.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_tolower.c ft_toupper.c ft_atoi.c ft_strcmp.c ft_strncmp.c\
ft_memcmp.c ft_strdup.c ft_strstr.c ft_strnstr.c ft_strchr.c ft_strrchr.c ft_strcpy.c ft_strncpy.c ft_strcat.c ft_strncat.c ft_memcpy.c\
ft_memccpy.c ft_memchr.c ft_memmove.c ft_memset.c ft_putstr.c ft_putchar.c ft_bzero.c ft_strlen.c ft_strlcat.c ft_strequ.c ft_strnequ.c\
ft_strmap.c ft_strmapi.c ft_strsub.c ft_strjoin.c ft_strtrim.c ft_strsplit.c ft_itoa.c ft_strnew.c ft_memalloc.c ft_memdel.c ft_strdel.c\
ft_strclr.c ft_striter.c ft_striteri.c ft_putchar.c ft_putstr.c ft_putendl.c ft_putnbr.c ft_putnbr_fd.c ft_putchar_fd.c ft_putstr_fd.c\
ft_putendl_fd.c ft_lstadd.c ft_lstnew.c ft_lstmap.c ft_lstdel.c ft_lstdelone.c ft_lstiter.c ft_sqrt.c

OBJECTS = $(SRC: .c=.o)

HEADERS = libft.h 

all: $(NAME)

$(NAME):
	gcc -c -I $(HEADERS) -Wall -Wextra -Werror $(SRC)
	ar rc $(NAME) *.o
	ranlib libft.a

clean:
	rm -f *.o

fclean: clean 
	rm -f libft.a

re: fclean all
