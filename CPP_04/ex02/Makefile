NAME = abstract

PURPLE = \033[1;35m
CYAN = \033[1;36m
BLUE = \033[1;34m
PINK = \033[1;95m
RESET = \033[0m

COMP = c++
FLAGS = -Wall -Wextra -Werror -std=c++20 
SRC_DIR = ./
OBJ_DIR = obj/

HEADER_FILES = AAnimal.hpp Dog.hpp Cat.hpp WrongAAnimal.cpp WrongCat.cpp Brain.hpp
SRC_FILES = main.cpp AAnimal.cpp Dog.cpp Cat.cpp WrongAAnimal.cpp WrongCat.cpp Brain.cpp
OBJ = $(addprefix $(OBJ_DIR), $(SRC_FILES:.cpp=.o))

all: $(NAME)

$(NAME): $(OBJ)
	@$(COMP) $(FLAGS) $(OBJ) -o $(NAME)
	@echo "$(PINK)Compilation successful $(RESET)"

$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp $(HEADER_FILES)
	@mkdir -p $(OBJ_DIR)
	@echo "$(PURPLE)Compiling $<... $(RESET)"
	@$(COMP) $(FLAGS) -c $< -o $@

clean:
	@$(RM) -rf $(OBJ_DIR)
	@echo "$(BLUE)Object files removed $(RESET)"

fclean: clean
	@$(RM) -f $(NAME)
	@echo "$(BLUE)Executable file removed $(RESET)"

re: fclean all
	@echo "$(PINK)Object and executable files successfully rebuilt $(RESET)"

.PHONY: all re clean fclean