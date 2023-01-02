CC     = gcc
CFLAGS = -Wall -Wextra -O0 -g3
 
TARGET = prueba
OBJS   = prueba.o arbolAVL.o
ARBOL  = arbol.pdf

.PHONY: all vis clean re open


all: $(TARGET)

vis: $(TARGET)
	./$(TARGET) | dot -Tpdf > $(ARBOL)

vis: VIS=-DVIS

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(VIS) $^ -o $@
	@rm -f $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) $(VIS) -c $^ -o $@

clean:
	@rm -f $(TARGET) $(OBJS) $(ARBOL)

re: clean all

open: clean vis
	@xdg-open $(ARBOL)
