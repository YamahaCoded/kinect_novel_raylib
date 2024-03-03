# Compiler
CC = gcc

# Flags 
CFLAGS = -O1 -Wall -std=c99 -Wno-missing-braces

# Libs
LIBS = 
LIBSWINDOWS = -lraylib -lopengl32 -lgdi32 -lwinmm
LIBSLINUX = -lraylib
# Source files
SRCS = *.c

# Name of binary
TARGET = main

# Check if some libs and folders are unnecessary
ifeq ($(OS), Windows_NT)
	INCLUDE_FOLDER = -Iinclude
	LIB_FOLDER = -L ./lib/
	LIBS := $(LIBSWINDOWS)
else 
	INCLUDE_FOLDER =
	LIB_FOLDER =
	LIBS := $(LIBSLINUX)
endif

# Build binary
$(TARGET): $(SRCS)
	$(CC) $(SRCS) -o $(TARGET) $(INCLUDE_FOLDER) $(LIB_FOLDER) $(LIBS) $(CFLAGS) 

# Clean temp files
clean:
	rm -f $(TARGET)

# Rebuild 
rebuild: clean $(TARGET)