##
## EPITECH PROJECT, 2024
## top
## File description:
## Makefile
##

BIN = my_top
CC ?= gcc

CFLAGS += -Wall -Wextra -Wpedantic
CPPFLAGS += -iquote./src
LDLIBS += -lncurses
DEBUG ?= non
BONUS ?= non

SRC = src/tbase.c src/tloop.c src/tupdate.c src/tinput.c src/header/line0.c
MAIN = src/main.c

BONUSSRC =

OBJS = $(SRC:.c=.o)
MAINOBJ = $(MAIN:.c=.o)

ifneq ($(DEBUG),non)
	CFLAGS+=-g3 -DMDEBUG
endif

ifneq ($(BONUS),non)
	CFLAGS += -DBONUS
	SRC += $(BONUSSRC)
endif

all: $(BIN)

$(BIN): $(OBJS) $(MAINOBJ)
	$(CC) $(CPPFLAGS) $(MAINOBJ) $(OBJS) $(LDLIBS) -o $(BIN)

clean:
	$(RM) $(OBJS)
	$(RM) $(MAINOBJ)

fclean: clean
	$(RM) $(BIN)

re: fclean all

.PHONY: re fclean clean all
