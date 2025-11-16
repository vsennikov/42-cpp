NAME		= megaphone
CXX			= c++
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98
RM			= rm -f

SRC			= megaphone.cpp
OBJ			= $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJ)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re test

test: $(NAME)
	@echo 'Running sample tests...'
	@echo 'input: ./megaphone shhhhh... I think the students are asleep...'
	@echo 'output:'
	@./$(NAME) "shhhhh... I think the students are asleep..."
	@echo 'input: ./megaphone Damnit"!" "Sorry students, I thought this thing was off."'
	@echo 'output:'
	@./$(NAME) Damnit"!" "Sorry students, I thought this thing was off."
	@echo 'input: ./megaphone'
	@echo 'output:'
	@./$(NAME)


