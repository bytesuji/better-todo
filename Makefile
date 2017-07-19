CC = g++
TARGET = todo
CFLAGS = -O3 -Wall -std=c++1z
LDFLAGS = -lboost_serialization

all: $(TARGET)
$(TARGET): $(TARGET).cc
	$(CC) $(CFLAGS) $(LDFLAGS) -o $(TARGET) $(TARGET).cc
clean:
	$(RM) $(TARGET)
