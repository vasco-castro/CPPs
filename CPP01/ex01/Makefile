
# ------------------- Variables -------------------

NAME		= Zombie

# Directories
SRCS_DIR	:= srcs/
OBJS_DIR	:= objs/
INCS_DIR	:= includes/

CXX			:= c++
CXXFLAGS	:= -Wall -Wextra -Werror -std=c++98 -I$(INCS_DIR)

SRCS		:= $(addprefix $(SRCS_DIR), $(addsuffix .cpp, $(NAME) main zombieHorde))
OBJS		:= $(SRCS:$(SRCS_DIR)%.cpp=$(OBJS_DIR)%.o)
INCS		:= $(INCS_DIR)$(NAME).hpp

# ------------------ Compilation ------------------

$(OBJS_DIR)%.o: $(SRCS_DIR)%.cpp $(INCS)
	@mkdir -p $(dir $@)
	@$(CXX) $(CXXFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(info Compiling exercise.)
	@$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

# --------------------- Rules ---------------------

all: $(NAME)

clean:
	$(info Cleaning objects.)
	@rm -rf $(OBJS_DIR)

fclean: clean
	$(info Cleaning exercise.)
	@rm -f $(NAME)

re: fclean all

run: re
	@valgrind --leak-check=full ./$(NAME)

.DEFAULT_GOAL := all
.PHONY: all clean fclean re run
