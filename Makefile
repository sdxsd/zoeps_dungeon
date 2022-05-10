CC = gcc
CFLAGS = -g -lraylib
NAME = system-killer
CFILES = \
		src/files.c \
		src/split.c \
		src/main.c
OFILES = $(CFILES:.c=.o)

all: $(NAME)

$(NAME): $(OFILES)
	$(CC) $(CFLAGS) $(OFILES) $(LINKEN) -o $(NAME)

%.o: %.c
	@$(CC) -g $(CFLAGS) -c $< -o $@
	@echo "COMPILED:" $<

re: fclean all

clean:
	rm -f $(NAME)

fclean: clean
	@rm -rfv system-killer.dSYM
	@rm -rfv $(OFILES)

.PHONY: all clean fclean re
