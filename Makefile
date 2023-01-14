CC = gcc
CFLAGS = -g
LINKEN = -lraylib -lGL -lm -lpthread -ldl -lrt -lX11
NAME = zoeps_dungeon
CFILES = \
		src/files.cpp \
		src/entity.cpp \
		src/split.cpp \
		src/map.cpp \
		src/render.cpp \
		src/main.cpp
OFILES = $(CFILES:.cpp=.o)

all: $(NAME)

$(NAME): $(OFILES)
	$(CC) $(CFLAGS) $(OFILES) $(LINKEN) -o $(NAME)

%.o: %.cpp
	@$(CC) -g $(CFLAGS) -c $< -o $@
	@echo "COMPILED:" $<

re: fclean all

clean:
	rm -f $(NAME)

fclean: clean
	@rm -rfv zoeps_dungeon.dSYM
	@rm -rfv $(OFILES)

.PHONY: all clean fclean re
