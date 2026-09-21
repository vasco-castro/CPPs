
# ------------------- Variables -------------------

NAME		:= megaphone

CXX			:= c++
CXXFLAGS	:= -Wall -Wextra -Werror -std=c++98

SRCS		:= $(addsuffix .cpp, $(NAME))
OBJS		:= $(SRCS:.cpp=.o)

# ------------------ Compilation ------------------

%.o: %.cpp
	@$(CXX) $(CXXFLAGS) -c $< -o $@

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

run: $(NAME)
	@./$(NAME) test " " 123wow!

.DEFAULT_GOAL := all
.PHONY: all clean fclean re run
