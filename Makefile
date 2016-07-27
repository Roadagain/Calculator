# Roadagain's calculator

CC = gcc
CFLAGS = -c -O3 -Wall -Wextra -MMD -MP
SRC = $(wildcard *.c)
OBJ = $(patsubst %.c, %.o, $(SRC))
DEP = $(patsubst %.c, %.d, $(SRC))
EXE = calc

.SUFFIXES: .cpp .o .h .d

.PHONY: all
all: $(EXE)

$(EXE): $(OBJ)
	$(CC) -o $(EXE) $(OBJ)

.PHONY: clean
clean:
	rm -f $(OBJ) $(DEP) $(EXE)

.PHONY: rebuild
rebuild: clean all

.c.o:
	$(CC) $(CFLAGS) $<

-include $(DEP)
