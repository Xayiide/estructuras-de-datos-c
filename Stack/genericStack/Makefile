CC       = gcc
CFLAGS   = -Wall -O0 -g
OBJFILES = genericstack.o prueba.o
LDFLAGS =

TARGET   = prueba
SOURCES  = prueba.c genericstack.c 
OBJECTS  = $(SOURCES:.c=.o)


.PHONY: clean

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)
	@rm -f $(OBJECTS)

clean:
	@rm -f $(TARGET) $(OBJECTS)
