CC = g++
TARGET = todo
CFLAGS = -O3 -Wall
LDFLAGS = -lboost_serialization

all: $(TARGET)
$(TARGET): $(TARGET).cc
	$(CC) $(CFLAGS) $(LDFLAGS) -o $(TARGET) $(TARGET).cc
clean:
	$(RM) $(TARGET)
