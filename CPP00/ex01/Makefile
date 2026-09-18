
# ------------------- Variables -------------------

NAME		:= PhoneBook

INCS_DIR	:= includes/
SRCS_DIR	:= srcs/
OBJS_DIR	:= objs/

CXX			?= c++
CXXFLAGS	:= -Wall -Wextra -Werror -std=c++98 -I$(INCS_DIR) -MMD -MP

SRCS		:= $(NAME).cpp Contact.cpp
OBJS		:= $(SRCS:.cpp=.o)

# ------------------ Compilation ------------------

$(OBJS): $(SRCS)
	$(info Compiling sources into objects.)
	@$(CXX) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(info Compiling exercise.)
	@$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

# --------------------- Rules ---------------------

all: $(NAME)

clean:
	$(info Cleaning objects.)
	@rm -f $(OBJS)

fclean: clean
	$(info Cleaning exercise.)
	@rm -f $(NAME)

re: fclean all

.DEFAULT_GOAL := all
.PHONY: all clean fclean re test

test: $(NAME)
	@./$(NAME)