SRCS = src/main.c\
	src/io.c\
	src/network.c

OBJS = $(SRCS:.c=.o) 

TARGET = get
CC = gcc
CXXFLAGS = -g -Wall
PREFIX = /usr/local/bin
BIN = ./bin


all: $(TARGET)

clean:
	rm -rf $(OBJS)

install:
	sudo install $(BIN)/$(TARGET) $(PREFIX)
	rm -Rf $(BIN)/$(TARGET)
	ln -s $(PREFIX)/$(TARGET)
	mv $(TARGET) $(BIN)

distclean:
	sudo rm -rf $(PREFIX)/$(TARGET)
	sudo rm -rf $(BIN)/$(TARGET)

$(TARGET): $(OBJS) 
	$(CC) -o $(TARGET) $(OBJS);
	mv $(TARGET) bin/


