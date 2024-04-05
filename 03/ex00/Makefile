CPP = c++
FLAGS = -Wall -Wextra -Werror -std=c++98 -g3

NAME = claptrap

SRCS = ClapTrap.cpp main.cpp
OBJS = $(addprefix objs/,$(SRCS:.cpp=.o))
DEPS = $(OBJS:.o=.d)

all: $(NAME)

$(NAME): $(OBJS)
	$(CPP) $(FLAGS) $(OBJS) -o $(NAME)

objs/%.o: srcs/%.cpp
	@mkdir -p objs/
	$(CPP) $(FLAGS) -MMD -c $< -o $@

clean:
	rm -f $(OBJS)
	rm -f $(DEPS)
	rm -rf objs/

fclean: clean
	rm -f $(NAME)

re: fclean all

-include $(DEPS)
