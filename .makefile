# Компилятор и флаги
CXX = g++
CXXFLAGS = -Wall -O2
OUTPUT_DIR = bin
OBJ_DIR = $(OUTPUT_DIR)/obj
EXECUTABLE = $(OUTPUT_DIR)/program.exe

# Исходные и объектные файлы
SOURCES = testcmp.cpp mycomplex.cpp
OBJECTS = $(OBJ_DIR)/testcmp.o $(OBJ_DIR)/mycomplex.o

# Цель по умолчанию
all: $(EXECUTABLE)

# Создание исполняемого файла
$(EXECUTABLE): $(OBJECTS)
	@echo "Linking the program..."
	$(CXX) $(CXXFLAGS) -o $@ $^

# Правила для объектных файлов
$(OBJ_DIR)/%.o: %.cpp | $(OBJ_DIR)
	@echo "Compiling $< ..."
	@if [ -f $@ ]; then \
		SIZE_BEFORE=$$(stat -c%s "$@"); \
		$(CXX) $(CXXFLAGS) -c $< -o $@; \
		SIZE_AFTER=$$(stat -c%s "$@"); \
		if [ $$SIZE_BEFORE -ne $$SIZE_AFTER ]; then \
			echo "File $@ has been modified: size before = $$SIZE_BEFORE bytes, size after = $$SIZE_AFTER bytes."; \
		else \
			echo "File $@ has not been modified: size remains = $$SIZE_BEFORE bytes."; \
		fi; \
	else \
		$(CXX) $(CXXFLAGS) -c $< -o $@; \
		SIZE_AFTER=$$(stat -c%s "$@"); \
		echo "File $@ created: size = $$SIZE_AFTER bytes."; \
	fi

# Создание каталога для объектных файлов
$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

# Команда очистки
clean:
	@echo "Cleaning up..."
	@rm -rf $(OBJ_DIR)/*.o $(EXECUTABLE)
	@rmdir --ignore-fail-on-non-empty $(OBJ_DIR)
	@rmdir --ignore-fail-on-non-empty $(OUTPUT_DIR)

# Файлы, которые не нужно удалять случайно
.PHONY: all clean
