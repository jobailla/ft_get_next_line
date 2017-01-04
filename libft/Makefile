# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jobailla <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/23 19:27:01 by jobailla          #+#    #+#              #
#    Updated: 2017/01/03 18:04:13 by jobailla         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := libft.a

INCS := includes
SRCS := libft
OBJS := objs


SHELL := /bin/bash

INCLUDES := -I$(INCS)

# Search source files
C_FILES 		:= $(shell find $(SRCS) -type f)
C_DIRS			:= $(shell find $(SRCS) -type d)
C_FLAGS			+= -Wall -Wextra -Werror -MMD -g -O2 -ggdb

# Build .o list
O_DIRS			:= $(addprefix $(OBJS)/,$(C_DIRS))
O_FILES			:= $(C_FILES:%.c=$(OBJS)/%.o)
O_FILES_UNIT	:= $(C_FILES_UNIT:%.c=$(OBJS)/%.o)

DEPS := $(O_FILES:.o=.d)

# Create OBJS and childs
$(shell mkdir -p $(O_DIRS) $(OBJS))

# Print
ACTUAL = $(words $(COUNT))
TOTAL  = $(words $(filter %.c,$(C_FILES)))
CALCUL = $(shell echo $(ACTUAL)\*100\/$(TOTAL) | bc)
PYTHON = $(shell python -c "print '%-10s' % ('I'*($(CALCUL)/10))")

PRINT_RED   = printf " [\033[31;1m%s\033[0m]\033[31;1m\t%3s%%\033[0m\t-->>\t\033[31;1m%-65s\033[0m\r" "$(PYTHON)" "$(CALCUL)"
PRINT_GREEN = printf " [\033[32;1m%s\033[0m]\033[32;1m\t%3s%%\033[0m\t-->>\t\033[32;1m%-65s\033[0m\r" "    Ok!   " "100"

all:
	make -j $(NAME)

$(NAME): $(O_FILES)
	$(PRINT_GREEN) $(SRCS) && echo || exit;
	ar rc $(NAME) $(O_FILES)
	ranlib $(NAME)

$(OBJS)/%.o: %.c
	clang $(C_FLAGS) $(INCLUDES) -o $@ -c $< && $(eval COUNT+=1) $(PRINT_RED) $< || exit

clean:
	rm -rf $(O_FILES) $(OBJS) 2> /dev/null

fclean: clean
	rm -f $(NAME) 2> /dev/null

re: fclean all

-include $(DEPS)

.PHONY: all clean fclean re
.SILENT:
