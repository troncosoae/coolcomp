# definitions
GXX = g++
GXX_FLAGS = -Wall -std=c++11
COMPILE = $(GXX) $(GXX_FLAGS)

HOME_DIR = ..
BIN_DIR = $(HOME_DIR)/bin
OBJ_DIR = $(HOME_DIR)/obj
SRC_DIR = $(HOME_DIR)/src

TARGET_NAME = coolcomp
TARGET = $(BIN_DIR)/$(TARGET_NAME)

INC_DIR = /usr/local/include
BOOST_LIB_DIR = /usr/local/lib/boost


# builds
default: $(TARGET)

$(TARGET): main.cpp $(OBJ_DIR)/lexical_analysis.o $(INC_DIR)
	$(COMPILE) -I $(INC_DIR) -o $(TARGET) main.cpp $(OBJ_DIR)/lexical_analysis.o $(BOOST_LIB_DIR)/libboost_program_options.a

$(OBJ_DIR)/lexical_analysis.o: lexical_analysis.cpp lexical_analysis.h
	$(COMPILE) -o $(OBJ_DIR)/lexical_analysis.o -c lexical_analysis.cpp

