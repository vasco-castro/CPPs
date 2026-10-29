
# ------------------- Variables -------------------

NAME		:= execform

# Directories
SRCS_DIR	:= srcs/
OBJS_DIR	:= objs/
INCS_DIR	:= includes/

CXX			:= c++
CXXFLAGS	:= -std=c++98 -Wall -Wextra -Werror -I$(INCS_DIR)

FILES		:= main Bureaucrat AForm ShrubberyCreationForm RobotomyRequestForm PresidentialPardonForm
SRCS		:= $(addprefix $(SRCS_DIR), $(addsuffix .cpp, $(FILES)))
OBJS		:= $(SRCS:$(SRCS_DIR)%.cpp=$(OBJS_DIR)%.o)
DEPS		:= $(OBJS:$(OBJS_DIR)%.o=$(OBJS_DIR)%.d)

# ------------------ Compilation ------------------

$(OBJS_DIR)%.o: $(SRCS_DIR)%.cpp
	@mkdir -p $(dir $@)
	@$(CXX) $(CXXFLAGS) -c $< -o $@ -MMD -MP

-include $(DEPS)

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

run: $(NAME)
	@./$(NAME)

val: $(NAME)
	@valgrind --leak-check=full ./$(NAME)

.DEFAULT_GOAL := all
.PHONY: all clean fclean re run val
