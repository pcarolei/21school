CC = gcc
CFLAGS = -Wall -Werror -Wextra
TARGET = libft.a
SRC = ./src
OBJ = ./obj

SOURCES = $(wildcard $(SRC)/*.c)
OBJECTS = $(patsubst $(SRC)/%.c, $(OBJ)/%.o, $(SOURCES))

all: $(TARGET)

$(TARGET): $(OBJECTS)
#	@echo Compiling libft
	ar -rc $(TARGET) $(OBJECTS)

$(OBJ)/%.o: $(SRC)/%.c libft.h
	$(CC) -I. -c $< -o $@

clean:
	rm -rf obj/*.o

fclean: clean
	rm -rf libft.a

re: fclean all
