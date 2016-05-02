# Roadagain's calculator

CXX = g++
CXXFLAGS = -c -O3 -Wall -Wextra
SRC = $(wildcard *.c)
OBJ = $(patsubst %.c, %.o, $(SRC))
EXE = calc

.SUFFIXES: .cpp .o .h .d

.PHONY: all
all: $(EXE)

$(EXE): $(OBJ)
	$(CXX) -o $(EXE) $(OBJ)

.PHONY: clean
clean:
	rm -f $(OBJ) $(EXE)

.PHONY: rebuild
rebuild: clean all

.c.o:
	$(CXX) $(CXXFLAGS) $^
