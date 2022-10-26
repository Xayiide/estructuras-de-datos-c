CC     = gcc
CFLAGS = -Wall -Wextra -O0 -g3

TARGET = prueba
OBJS   = prueba.o arbBin.o
ARBOL  = arbol.pdf

.PHONY: all clean re


all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@
	@rm -f $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@

vis: $(TARGET)
	./$(TARGET) | dot -Tpdf > $(ARBOL)

clean:
	@rm -f $(TARGET) $(OBJS) $(ARBOL)

re: clean all
