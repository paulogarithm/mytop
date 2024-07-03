##
## EPITECH PROJECT, 2024
## c_vectors_2
## File description:
## Makefile
##

BIN = ../../libvec.a
CC ?= gcc
AR ?= ar
RM ?= rm -rf

ARFLAGS ?= rcv
CFLAGS += -Wall -Wextra -Wpedantic
CPPFLAGS += -iquote.
DEBUG ?= non

SRC = 	vnew.c \
		vclose.c \
		vpush.c \
		vnmemb.c \
		vconvert.c \

OBJS = $(SRC:.c=.o)

TESTBIN = 	unit_tests
TESTWHERE =
TESTS = 	test_vec.c \

ifneq ($(DEBUG),non)
	CFLAGS+=-g3 -DMDEBUG
endif

all: $(BIN)

$(BIN): $(OBJS)
	$(AR) $(ARFLAGS) $(BIN) $(OBJS)

clean:
	$(RM) $(OBJS)
	$(RM) *.gc*

fclean: clean
	$(RM) $(BIN)
	$(RM) $(TESTBIN)

re: fclean all

tests_run: clean
	@echo tests
	# $(CC) -o $(TESTBIN) $(addprefix $(TESTWHERE),$(TESTS)) $(SRC) \
	# 	 $(CPPFLAGS) --coverage -lcriterion -lgcov $(LDFLAGS) $(LDLIBS)
	# -./$(TESTBIN)

.PHONY: re fclean clean all tests_run
