# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ncrivell <ncrivell@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/10 17:42:35 by ncrivell          #+#    #+#              #
#    Updated: 2025/11/10 17:43:04 by ncrivell         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = SED_IS_FOR_LOSERS

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

BLUE = \033[34m
GREEN = \033[32m
RED = \033[31m
RESET = \033[0m

SRC = 	main.cpp


OBJS = $(SRC:.cpp=.o)

RM = rm -f
all: $(NAME)

$(NAME): $(OBJS)
		@$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME) || (echo "$(RED)Compilation error !$(RESET)" && exit 1)
		@echo "$(GREEN)--------------------------------------------------$(RESET)"
		@echo "$(GREEN)The program has successfully compiled! Now Enjoy !$(RESET)"
		@echo "$(GREEN)--------------------------------------------------$(RESET)"

%.o: %.cpp
		@echo "$(BLUE)compiling$(RESET)  :  $<"
		@$(CXX) $(CXXFLAGS) -c $< -o $@ || (echo "$(RED)--------------------------------\n    /!\ Error compiling /!\ \n-------------------------------- $<$(RESET)" && exit 1)

clean:
	@echo "$(BLUE)~~~~~~~~Cleaning object files...~~~~~~~~$(RESET)"
	@$(RM) $(OBJS)

fclean: clean
	@echo "$(BLUE)~~~~~~~~Cleaning executable...~~~~~~~~$(RESET)"
	@$(RM) $(NAME)
	@echo "$(GREEN)---------------------------$(RESET)"
	@echo "$(GREEN)Project completely cleaned!$(RESET)"
	@echo "$(GREEN)---------------------------$(RESET)"

re: fclean all

.PHONY: all clean fclean re
