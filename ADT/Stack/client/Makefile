CC     = gcc
CFLAGS = -Wall -Wextra -O0 -g3
LFLAGS = -L./lib -lstack

TRGT = client
SRCS = client.c
OBJS = $(SRCS:.c=.o)
LIBS = stack

.PHONY: all clean re run

all: $(TRGT)
	@rm -f $(OBJS)

$(TRGT): $(OBJS)
	$(CC) $(CFLAGS) $^ $(LFLAGS) -o $@

$(OBJS): $(SRCS)
	$(CC) $(CFLAGS) -c $^ -o $@

clean:
	@rm -f $(TRGT) $(OBJS)
	@echo "clean"

re: clean all

run: $(TRGT)
	@./$(TRGT)
