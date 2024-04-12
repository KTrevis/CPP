CPP = c++
FLAGS = -Wall -Wextra -Werror -std=c++98 -g3

NAME = animal

SRCS = main.cpp Animal.cpp Dog.cpp Cat.cpp WrongAnimal.cpp WrongCat.cpp
OBJS = $(addprefix objs/,$(SRCS:.cpp=.o))
DEPS = $(OBJS:.o=.d)

all: $(NAME)

$(NAME): $(OBJS)
	$(CPP) $(FLAGS) $(OBJS) -o $(NAME)

objs/%.o: srcs/%.cpp
	@mkdir -p objs/
	$(CPP) $(FLAGS) -MMD -c $< -o $@ -I includes/

clean:
	rm -f $(OBJS)
	rm -f $(DEPS)
	rmdir objs/

fclean: clean
	rm -f $(NAME)

re: fclean all

-include $(DEPS)
