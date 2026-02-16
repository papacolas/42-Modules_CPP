# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ncrivell <ncrivell@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/28 20:52:17 by ncrivell          #+#    #+#              #
#    Updated: 2025/11/28 20:52:46 by ncrivell         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Form

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

BLUE = \033[34m
GREEN = \033[32m
RED = \033[31m
RESET = \033[0m

SRC =	main.cpp \
		Bureaucrat.cpp \
		Form.cpp

OBJDIR = obj
OBJS = $(addprefix $(OBJDIR)/,$(SRC:.cpp=.o))

RM = rm -rf
all: $(NAME)

$(NAME): $(OBJS)
	@$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME) || (echo "$(RED)Compilation error !$(RESET)" && exit 1)
	@echo "$(GREEN)--------------------------------------------------$(RESET)"
	@echo "$(GREEN)The program has successfully compiled! Now Enjoy !$(RESET)"
	@echo "$(GREEN)--------------------------------------------------$(RESET)"

$(OBJDIR)/%.o: %.cpp | $(OBJDIR)
	@echo "$(BLUE)compiling$(RESET)  :  $<"
	@$(CXX) $(CXXFLAGS) -c $< -o $@ || (echo "$(RED)--------------------------------\n    /!\ Error compiling /!\ \n-------------------------------- $<$(RESET)" && exit 1)

$(OBJDIR):
	@mkdir -p $(OBJDIR)

clean:
	@echo "$(BLUE)~~~~~~~~Cleaning object files...~~~~~~~~$(RESET)"
	@$(RM) $(OBJDIR)

fclean: clean
	@echo "$(BLUE)~~~~~~~~Cleaning executable...~~~~~~~~$(RESET)"
	@$(RM) $(NAME)
	@echo "$(GREEN)---------------------------$(RESET)"
	@echo "$(GREEN)Project completely cleaned!$(RESET)"
	@echo "$(GREEN)---------------------------$(RESET)"

re: fclean all

.PHONY: all clean fclean re


