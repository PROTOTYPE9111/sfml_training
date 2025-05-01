# Компилятор
CXX = clang++

# Флаги компиляции (C++23 draft и путь к заголовочным файлам SFML)
CXXFLAGS = -std=c++2b -I/usr/local/Cellar/sfml/3.0.0_1/include

# Флаги линковки с библиотеками SFML
LDFLAGS = -L/usr/local/Cellar/sfml/3.0.0_1/lib -lsfml-graphics -lsfml-window -lsfml-system

# Путь к исполняемому файлу
TARGET = build/main

# Исходные файлы
SRCS = src/main.cpp

# Цель по умолчанию: сборка программы
all: $(TARGET)

# Правило сборки исполняемого файла
$(TARGET): $(SRCS)
	mkdir -p build
	$(CXX) $(CXXFLAGS) $^ $(LDFLAGS) -o $@

# Очистка собранных файлов
clean:
	rm -rf build
