# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rchester <rchester@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/05/22 15:58:36 by rchester          #+#    #+#              #
#    Updated: 2026/06/02 11:17:45 by rchester         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re

CC = cc
CFLAGS = -Wall -Wextra -Werror
MAKE = make -C

TESTS = test_specifiers\
		test_write_fail

PRINTF_PATH = printf

PRINTF = ${PRINTF_PATH}/libftprintf.a

SOURCES = $(PRINTF_PATH)/*.c $(PRINTF_PATH)/ft_printf.h

LDFLAGS = -L$(PRINTF_PATH)
LDLIBS = -lftprintf

all: $(TESTS)
	clear
	@printf "%b\n" "Testers created, call using ./ and tester name:" "\ttest_specifier\n\ttest_write_fail"

test_%: test_%.c $(PRINTF)
	$(CC) $(CFLAGS) -o $@ $< $(LDFLAGS) $(LDLIBS)

$(PRINTF): $(SOURCES)
	${MAKE} ${PRINTF_PATH}
	 
clean:
	${MAKE} ${PRINTF_PATH} clean
	rm -f $(TESTS)
	clear
	@printf "cleaned"

fclean: clean
	${MAKE} ${PRINTF_PATH} fclean
	rm -f $(TESTS)
	clear
	@printf "cleaned"

re: fclean all