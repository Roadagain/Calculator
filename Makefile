# Roadagain's calculator

CC = gcc
CFLAGS = -c -O3 -Wall -Wextra -MMD -MP
SRC = $(wildcard ./*.c)
OBJ = $(patsubst %.c, %.o, $(SRC))
DEP = $(patsubst %.c, %.d, $(SRC))
EXE = calc
TESTCFLAGS = -O3 -Wall -Wextra -MMD -MP
TESTINPUTSRC = $(wildcard test/input/*.c)
TESTSRC = $(wildcard test/**/*.c)
TESTLIB = $(filter-out ./main.o, $(OBJ))
TESTINPUTEXE = $(patsubst %.c, %, $(TESTINPUTSRC))
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
test: $(TESTEXE) test-input

test-input: $(TESTINPUTEXE)
	test/input/test.sh $^

.c.o:
	$(CC) $(CFLAGS) $<

$(TESTEXE): $(TESTLIB)

.c:
	$(CC) $(TESTCFLAGS) $< $(TESTLIB) -o $@

-include $(DEP)
