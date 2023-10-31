CC       = gcc
CFLAGS   = -Wall -O0 -g
OBJFILES = dobleenlaz.o prueba.o
LDFLAGS =

TARGET   = prueba
SOURCES  = prueba.c dobleenlaz.c 
OBJECTS  = $(SOURCES:.c=.o)


.PHONY: all clean re

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)
	@rm -f $(OBJECTS)

clean:
	@rm -f $(TARGET) $(OBJECTS)
	@echo "clean"

re: clean all 
