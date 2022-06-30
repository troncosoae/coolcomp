# definitions
GXX = g++
GXX_FLAGS = 
COMPILE = $(GXX) $(GXX_FLAGS)

HOME_DIR = .
BIN_DIR = $(HOME_DIR)/bin
OBJ_DIR = $(HOME_DIR)/obj
SRC_DIR = $(HOME_DIR)/src



# builds
default: build_src

.PHONY: build_src
build_src: $(SRC_DIR)/makefile
	$(MAKE) -C $(SRC_DIR)

.PHONY: run
run:
	$(BIN_DIR)/coolcomp

.PHONY: clean
clean:
	rm $(BIN_DIR)/coolcomp
	rm $(OBJ_DIR)/*.o

.PHONY: run_tests
run_tests:
	cd tests; ./run.sh; cd ..
