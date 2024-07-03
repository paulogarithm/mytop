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
LDLIBS += -L. -lncurses -lvec
DEBUG ?= non
BONUS ?= non

LIBPATHS = src/vec

SRC = src/tbase.c src/tloop.c src/tupdate.c src/tinput.c src/tparser.c \
	src/header/line0.c \
	src/header/line1.c

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

define dolibs
	for l in $(LIBPATHS); do \
		DEBUG=$(DEBUG) BONUS=$(BONUS) make -C $$l $1; \
	done
endef

all: $(BIN)

$(BIN): $(OBJS) $(MAINOBJ)
	$(call dolibs, all)
	$(CC) $(CPPFLAGS) $(MAINOBJ) $(OBJS) $(LDLIBS) -o $(BIN)

clean:
	$(call dolibs, clean)
	$(RM) $(OBJS)
	$(RM) $(MAINOBJ)

fclean: clean
	$(call dolibs, fclean)
	$(RM) $(BIN)

re: fclean all

.PHONY: re fclean clean all
