# Roadagain's calculator

CC = gcc
CFLAGS = -c -O3 -Wall -Wextra -MMD -MP
SRC = $(wildcard ./*.c)
OBJ = $(patsubst %.c, %.o, $(SRC))
DEP = $(patsubst %.c, %.d, $(SRC))
EXE = calc
TESTCFLAGS = -O3 -Wall -Wextra -MMD -MP
TESTSRC = $(wildcard test/*.c)
TESTEXE = $(patsubst %.c, %, $(TESTSRC))
TESTDEP = $(patsubst %.c, %.d, $(TESTSRC))

.SUFFIXES: .c .o .h .d

.PHONY: all
all: $(EXE)

$(EXE): $(OBJ)
	$(CC) -o $(EXE) $(OBJ)

.PHONY: clean
clean:
	rm -f $(OBJ) $(DEP) $(EXE) $(TESTEXE) $(TESTDEP)

.PHONY: rebuild
rebuild: clean all

.PHONY: test
test: $(TESTEXE)
	test/test_input.sh $(TESTEXE)

.c.o:
	$(CC) $(CFLAGS) $<

%: test/%.c
	$(CC) $(TESTCFLAGS) $< -o $@

-include $(DEP)
