# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oipadeol <oipadeol@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/25 16:08:38 by oipadeol          #+#    #+#              #
#    Updated: 2021/09/25 19:20:33 by oipadeol         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = get_next_line.a

FLAGS = -Wall -Wextra -Werror

SRC = get_next_line.c get_next_line_utils.c

all: lib
	gcc -o a *.o
	
objects:
	gcc -c $(FLAGS) -D BUFFER_SIZE=42 $(SRC)

lib: objects
	ar -cr $(NAME) *.o

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)
	
re: clean all