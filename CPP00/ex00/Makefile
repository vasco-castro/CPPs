
# ------------------- Variables -------------------

NAME		= megaphone

CXX			?= c++
CXXFLAGS	:= -Wall -Wextra -Werror -std=c++98

SRCS		:= $(NAME).cpp

# ------------------ Compilation ------------------

$(NAME): $(SRCS)
	$(info Compiling exercise.)
	@$(CXX) $(CXXFLAGS) $(SRCS) -o $(NAME)

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
	@./$(NAME) test " " 123wow!