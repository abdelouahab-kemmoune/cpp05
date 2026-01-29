NAME = No!!
CC = c++
FLAGS = -Wall -Wextra -Werror -g -std=c++98

SRCS = AForm.cpp Bureaucrat.cpp Intern.cpp main.cpp PresidentialPardonForm.cpp RobotomyRequestForm.cpp ShrubberyCreationForm.cpp

OBJS = $(SRCS:.cpp=.o)

all: $(NAME) clean
	@./$(NAME)

%.o: %.cpp
	$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS) && clear

fclean: clean
	rm -f $(NAME) *_shrubbery

re: fclean all