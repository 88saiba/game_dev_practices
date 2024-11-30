# Nama file output
TARGET = pingpong.out

# Flags kompilasi
CXXFLAGS = -std=c++17 -Wall

# Libraries yang dibutuhkan (SFML)
LIBS = -lsfml-graphics -lsfml-window -lsfml-system

# Nama file sumber
SRC = pingpong.cpp

# Penentuan compiler secara otomatis
CXX := $(shell if command -v clang++ > /dev/null 2>&1; then echo clang++; else echo g++; fi)

# Rule default (kompilasi dan linking)
all: check_compiler $(TARGET)

# Rule untuk memeriksa dan mencetak compiler yang digunakan
check_compiler:
	@if [ "$(CXX)" = "clang++" ]; then \
		echo "clang++ found, using clang++"; \
	else \
		echo "clang++ not found, switching to g++"; \
	fi

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET) $(LIBS)

# Rule untuk membersihkan file hasil kompilasi
clean:
	rm -f $(TARGET)
