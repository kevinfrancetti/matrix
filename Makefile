.SUFFIXES:

#Last modification 17.11.2025

#config
GCC := gcc
AR := ar




#Names
LIB_NAME := libkevmatrix.a

#Directory structure
SRC_DIR := src
BUILD_DIR := build
STATIC_DIR := $(BUILD_DIR)/static
STATIC_OBJ_DIR := $(STATIC_DIR)/obj
STATIC_LIB_DIR := $(STATIC_DIR)/lib
INCLUDE_DIR := include
TEST_DIR := test
TEST_TARGET := $(TEST_DIR)/main

STATIC_LIB_NAME := $(STATIC_LIB_DIR)/$(LIB_NAME)


#Compiler flags
INCLUDES := -Iinclude  #modify this line bro
CFLAGS := -Wall -MMD $(INCLUDES) -c


srcs := $(wildcard $(SRC_DIR)/*.c)
#objs := $(srcs:.c=cacca.o)
objs := $(patsubst $(SRC_DIR)/%.c, $(STATIC_OBJ_DIR)/%.o, $(srcs))
deps := $(patsubst $(STATIC_DIR)/%.o, $(STATIC_DIR)/%.d, $(objs))
#deps := $(wildcard $(STATIC_OBJ_DIR)/*.d)

.PHONY: object_files
object_files: $(objs)

.PHONY: debug
debug: CFLAGS += -g
debug: static_lib
debug: $(TEST_TARGET)

.PHONY: create_directory
create_directory: | $(STATIC_LIB_DIR) $(STATIC_OBJ_DIR) $(SRC_DIR) $(INCLUDE_DIR)

#.PHONY: static_lib 
#static_lib:  $(STATIC_LIB_NAME)


$(STATIC_LIB_NAME): $(objs) | $(STATIC_LIB_DIR)
	$(AR) rcs $@  $^


$(STATIC_OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(STATIC_OBJ_DIR)
	$(GCC) $(CFLAGS)  $< -o $@


$(STATIC_LIB_DIR) $(STATIC_OBJ_DIR) $(SRC_DIR) $(INCLUDE_DIR):
	mkdir -p $@


.PHONY: clean
clean:
	rm  $(objs) $(STATIC_LIB_NAME) $(deps)


print:
	@echo "srcs: $(srcs)"
	@echo "objs:  $(objs)"
	@echo "deps:  $(deps)"
	@echo $(STATIC_DIR)
	@echo $(SRC_DIR)
	@echo $(BUILD_DIR)



-include $(deps)
