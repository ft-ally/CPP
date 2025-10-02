NAME = phonebook

RED = \033[1;31m
GREEN   = \033[1;32m
YELLOW = \033[1;33m
RESET = \033[0m

COMP = g++
FLAGS = -Wall -Wextra -Werror -std=c++98
SRC_DIR = ./
OBJ_DIR = obj/

SRC_FILES = phonebook.cpp
OBJ = $(addprefix $(OBJ_DIR), $(SRC_FILES:.cpp=.o))

all: $(NAME)

$(NAME): $(OBJ)
	@$(COMP) $(FLAGS) $(OBJ) -o $(NAME)
	@echo "$(GREEN)Compilation successful $(RESET)"

$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp
	@mkdir -p $(OBJ_DIR)
	@echo "$(YELLOW)Compiling $<... $(RESET)"
	@$(COMP) $(FLAGS) -c $< -o $@

clean:
	@$(RM) -rf $(OBJ_DIR)
	@echo "$(RED)Object files successfully removed $(RESET)"

fclean: clean
	@$(RM) -f $(NAME)
	@echo "$(RED)Executable file successfully removed $(RESET)"

re: fclean all
	@echo "$(GREEN)Object and executable files successfully rebuilt $(RESET)"

.PHONY: all re clean fclean