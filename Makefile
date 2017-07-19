CC = g++
TARGET = todo
CFLAGS = -O3 -Wall

all: $(TARGET)
$(TARGET): $(TARGET).cc
	$(CC) $(CFLAGS) -o $(TARGET) $(TARGET).cc
clean:
	$(RM) $(TARGET)
