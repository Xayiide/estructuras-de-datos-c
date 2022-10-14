CC       = gcc
CFLAGS   = -Wall -O0 -g
OBJFILES = intstack.o prueba.o
LDFLAGS =

TARGET   = prueba
SOURCES  = prueba.c intstack.c 
OBJECTS  = $(SOURCES:.c=.o)

.PHONY: clean

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)
	@rm -f $(OBJECTS)

clean:
	@rm -f $(TARGET) $(OBJECTS)
