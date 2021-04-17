CC = gcc
CFLAGS = -W -Wall
TARGET = product
DTARGET = product_debug
OBJECTS = productmain.c product.o manager.o
all : $(TARGET)

$(TARGET) : $(OBJECTS)
	$(CC) $(CFLAGS) -I ../ product.h manager.h -o $@ $^

$(DTARGET) : $(OBJECTS)
	$(CC) $(CFLAGS) -I ../ product.h manager.h -o $@ $^

clean:
	rm *.o product
	rm product_debug
