TARGET = app
CC = gcc -std=c23 -ggdb -Wall -Wextra -pedantic -O0
INC =
LIBS =
HEADERS =
SOURCES = main.c

all: $(TARGET)

$(TARGET): $(HEADERS) $(SOURCES)
	@$(CC) $(INC) $(SOURCES) -o $(TARGET) $(LIBS)

.PHONY: clean run test

clean:
	@rm -rf $(TARGET)

run: $(TARGET)
	-@./$(TARGET)
	@rm -rf $(TARGET)

test: $(TARGET)
	@valgrind ./$(TARGET)
	@rm -rf $(TARGET)
