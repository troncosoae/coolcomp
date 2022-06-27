# definitions
GXX = g++
GXX_FLAGS = -Wall
COMPILE = $(GXX) $(GXX_FLAGS)

HOME_DIR = ..
BIN_DIR = $(HOME_DIR)/bin
OBJ_DIR = $(HOME_DIR)/obj
SRC_DIR = $(HOME_DIR)/src

TARGET_NAME = coolcomp
TARGET = $(BIN_DIR)/$(TARGET_NAME)


# builds
default: $(TARGET)

$(TARGET): $(OBJ_DIR)/lexical_analysis.o
	$(COMPILE) -o $(TARGET) main.cpp $(OBJ_DIR)/lexical_analysis.o

$(OBJ_DIR)/lexical_analysis.o: lexical_analysis.cpp lexical_analysis.h
	$(COMPILE) -o $(OBJ_DIR)/lexical_analysis.o -c lexical_analysis.cpp

