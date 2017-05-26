# Roadagain's calculator

CC = gcc
CFLAGS = -c -O3 -Wall -Wextra -MMD -MP
SRC = $(wildcard ./*.c)
OBJ = $(patsubst %.c, %.o, $(SRC))
DEP = $(patsubst %.c, %.d, $(SRC))
EXE = calc
EXECFLAGS = -o $(EXE) -lm
TESTCFLAGS = -O3 -Wall -Wextra -MMD -MP -lm
TESTINPUTSRC = $(wildcard test/input/*.c)
TESTCALCSRC = $(wildcard test/calc/*.c)
TESTSRC = $(wildcard test/**/*.c)
TESTLIB = $(filter-out ./main.o, $(OBJ))
TESTINPUTEXE = $(patsubst %.c, %, $(TESTINPUTSRC))
TESTCALCEXE = $(patsubst %.c, %, $(TESTCALCSRC))
TESTEXE = $(patsubst %.c, %, $(TESTSRC))
TESTDEP = $(patsubst %.c, %.d, $(TESTSRC))

.SUFFIXES: .c .o .h .d

.PHONY: all
all: $(EXE)

$(EXE): $(OBJ)
	$(CC) $(OBJ) $(EXECFLAGS)

.PHONY: clean
clean:
	rm -f $(OBJ) $(DEP) $(EXE) $(TESTEXE) $(TESTDEP)

.PHONY: rebuild
rebuild: clean all

.PHONY: test
test: $(TESTEXE) test-input test-calc

test-input: $(TESTINPUTEXE)
	test/input/test.sh $^

test-calc: $(TESTCALCEXE)
	test/calc/test.sh $^

.c.o:
	$(CC) $< $(CFLAGS)

$(TESTEXE): $(TESTLIB)

.c:
	$(CC) $< $(TESTLIB) -o $@ $(TESTCFLAGS)

-include $(DEP)
