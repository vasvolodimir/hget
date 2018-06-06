SRCS = src/main.c\
	src/io.c\
	src/network.c

OBJS = $(SRCS:.c=.o) 

TARGET = get
CC = gcc
CXXFLAGS = -g -Wall
PREFIX = /usr/local/bin


all: $(TARGET)

clean:
	rm -rf $(OBJS)

install:
	sudo install $(TARGET) $(PREFIX)

distclean:
	sudo rm -rf $(PREFIX)/$(TARGET)

$(TARGET): $(OBJS) 
	$(CC) -o $(TARGET) $(OBJS);
	mv $(TARGET) bin/


