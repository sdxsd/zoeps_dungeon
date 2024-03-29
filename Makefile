CC = g++
CFLAGS = -g
LIBVECTOR = libvector.a
LINKEN = -lraylib -lGL -lm -lpthread -ldl -lrt -lX11
NAME = zoeps_dungeon
CFILES = \
		src/player.cpp \
		src/entity.cpp \
		src/split.cpp \
		src/map.cpp \
		src/movement.cpp \
		src/main.cpp
OFILES = $(CFILES:.cpp=.o)

all: $(NAME)

$(NAME): $(OFILES) $(LIBVECTOR)
	$(CC) $(CFLAGS) $(OFILES) $(LINKEN) libvector/$(LIBVECTOR) -o $(NAME)

%.o: %.cpp
	@$(CC) -g $(CFLAGS) -c $< -o $@
	@echo "COMPILED:" $<

$(LIBVECTOR):
	make -C libvector/

re: fclean all

clean:
	@rm -f $(NAME)

fclean: clean
	make -C libvector/ fclean
	@rm -rf zoeps_dungeon.dSYM
	@rm -rf $(OFILES)

.PHONY: all clean fclean re
