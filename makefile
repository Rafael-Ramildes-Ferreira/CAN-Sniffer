CC = g++
CFLAGS = -Wall -Wextra -std=c++20
RM = rm -f

OUT = a.out

SRCS = $(shell find . -name '*.cpp')

all: $(OUT)

$(OUT): $(SRCS)
	$(CC) $(CFLAGS) -o $(OUT) $(SRCS)

run: $(OUT)
	./$(OUT)

clean:
	$(RM) $(OUT)

.PHONY: all run clean