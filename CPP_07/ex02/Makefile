NAME = array

PURPLE = \033[35m
CYAN = \033[36m
BLUE = \033[34m
PINK = \033[95m
GREEN = \033[1;32m
RESET = \033[0m

COMP = c++
FLAGS = -Wall -Wextra -Werror -std=c++20 
SRC_DIR = ./
OBJ_DIR = obj/

HEADER_FILES = Array.hpp
SRC_FILES = main.cpp 
INTRA_MAIN = intra_main.cpp

OBJ = $(addprefix $(OBJ_DIR), $(SRC_FILES:.cpp=.o))
INTRA_OBJ = $(addprefix $(OBJ_DIR), $(INTRA_MAIN:.cpp=.o))

all: $(NAME)

$(NAME): $(OBJ)
	@$(COMP) $(FLAGS) $(OBJ) -o $(NAME)
	@echo "$(GREEN)Compilation successful! Run program with:$(RESET) $(CYAN)./$(NAME) $(RESET)"

$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp $(HEADER_FILES)
	@mkdir -p $(OBJ_DIR)
	@echo "$(PURPLE)Compiling $<... $(RESET)"
	@$(COMP) $(FLAGS) -c $< -o $@

intra: $(INTRA_OBJ)
	@$(COMP) $(FLAGS) $(INTRA_OBJ) -o intra
	@echo "$(GREEN)Intra test compilation successful! Run with:$(RESET) $(CYAN)./intra $(RESET)"

clean:
	@$(RM) -rf $(OBJ_DIR)
	@echo "$(BLUE)Object files removed $(RESET)"

fclean: clean
	@$(RM) -f $(NAME)
	@$(RM) -f intra
	@echo "$(BLUE)Executable file removed $(RESET)"

re: fclean all
	@echo "$(PINK)Object and executable files rebuilt $(RESET)"

.PHONY: all re clean fclean intra