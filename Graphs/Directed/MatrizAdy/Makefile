CC     = gcc
CFLAGS = -Wall -Wextra -O0 -g

TARGET  = prueba
OBJECTS = prueba.o matrizAdy.o
GRAFO   = grafo.pdf

.PHONY: all clean re


all: $(TARGET)

$(TARGET): prueba.o matrizAdy.o
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@

vis: $(TARGET)
	./$(TARGET) | dot -Tpdf > $(GRAFO)

clean:
	@rm -f $(TARGET) $(OBJECTS) $(GRAFO)

re: clean all
