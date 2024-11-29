# Nama file output
TARGET = pingpong.out

# Flags kompilasi
CXXFLAGS = -std=c++17 -Wall

# Libraries yang dibutuhkan (SFML)
LIBS = -lsfml-graphics -lsfml-window -lsfml-system

# Compiler yang digunakan
CXX = g++

# Nama file sumber
SRC = pingpong.cpp

# Rule default (kompilasi dan linking)
all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET) $(LIBS)

# Rule untuk membersihkan file hasil kompilasi
clean:
	rm -f $(TARGET)
