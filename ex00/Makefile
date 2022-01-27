CXXFLAGS= -std=c++98 -pedantic -Wall -Werror -Wextra
CXX		= c++
NAME	= convert
OBJS_PATH = objs/
DEPS_PATH = deps/
DEPS	= $(patsubst %, $(DEPS_PATH)%, $(SRCS:.cpp=.d))
OBJS	= $(patsubst %, $(OBJS_PATH)%, $(SRCS:.cpp=.o))
RM		= rm -f
SRCS	= main.cpp \
		  Convert.cpp

all: $(NAME)

$(OBJS_PATH)%.o: %.cpp
	$(CXX) $(CXXFLAGS) -MMD -MP -c $< -o $@

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS) $(DEPS)

fclean: clean
	$(RM) $(NAME)

re: fclean $(NAME)

-include $(DEPS)

.PHONY: all clean fclean re
