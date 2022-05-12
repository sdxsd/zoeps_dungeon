CC = gcc
CFLAGS = -g -lraylib
NAME = dungeons_of_wajoo
CFILES = \
		src/files.cpp \
		src/split.cpp \
		src/mapgen.cpp \
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
	@rm -rfv system-killer.dSYM
	@rm -rfv $(OFILES)

.PHONY: all clean fclean re
