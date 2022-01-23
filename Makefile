CC      := gcc
BIN     := ./bin
INCLUDE := ./include
SRC     := ./src
OBJ     := ./obj
SRCS    := $(wildcard $(SRC)/*.c)
OBJS    := $(patsubst $(SRC)/%.c, $(OBJ)/%.o, $(SRCS))
EXE     := $(BIN)/output.exe
CFLAGS  := -I$(INCLUDE)

.PHONY: all run clean

all: $(EXE)

$(EXE): $(OBJS) | $(BIN)
	$(CC) $(CFLAGS) -o $@ $^

$(OBJ)/%.o: $(SRC)/%.c | $(OBJ)
	$(CC) $(CFLAGS) -c $< -o $@

$(BIN) $(OBJ):
	mkdir $@

run: $(EXE)
	$<

clean:
	rm $(OBJ)/*.o