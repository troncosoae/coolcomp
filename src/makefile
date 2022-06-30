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


BOOST_PROGRAM_OPTIONS_A = $(BOOST_LIB_DIR)/libboost_program_options.a
BOOST_REGEX_A = $(BOOST_LIB_DIR)/libboost_regex.a

LEXICAL_ANALYSIS_OBJ = $(OBJ_DIR)/lexical_analysis.o
LEXICAL_ANALYSIS_EXE = $(BIN_DIR)/run_lexical_analysis


# builds
default: all

all: $(TARGET) $(LEXICAL_ANALYSIS_EXE)

$(TARGET): main.cpp $(LEXICAL_ANALYSIS_OBJ) $(INC_DIR) $(BOOST_PROGRAM_OPTIONS_A)
	$(COMPILE) -I $(INC_DIR) -o $(TARGET) main.cpp $(LEXICAL_ANALYSIS_OBJ) $(BOOST_PROGRAM_OPTIONS_A)

$(LEXICAL_ANALYSIS_OBJ): lexical_analysis.cpp lexical_analysis.h $(BOOST_REGEX_A)
	$(COMPILE) -o $(LEXICAL_ANALYSIS_OBJ) -c lexical_analysis.cpp $(BOOST_REGEX_A)

$(LEXICAL_ANALYSIS_EXE): run_lexical_analysis.cpp $(LEXICAL_ANALYSIS_OBJ) $(INC_DIR) $(BOOST_REGEX_A)
	$(COMPILE) -I $(INC_DIR) -o $(LEXICAL_ANALYSIS_EXE) run_lexical_analysis.cpp $(LEXICAL_ANALYSIS_OBJ) $(BOOST_PROGRAM_OPTIONS_A) $(BOOST_REGEX_A)
