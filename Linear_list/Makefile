TARGET = list

# Build path
BUILD_DIR = build

# binaries
CC =gcc

# C sources
#默认使用链式表,默认编译测试函数,如需运行Dome,修改makefile
C_SOURCES =  \
link_list.c  \
main.c	 			

# ./dome/addition.c \	#使用链表实现任意位整数的加法

# C includes
C_INCLUDES =  \
-I../../platform \
-I./

# C defines
C_DEFS =  \

# compile gcc flags
CFLAGS = -std=c99 -g $(C_DEFS) $(C_INCLUDES) $(OPT) -Wall -fdata-sections -ffunction-sections 

LDFLAGS =   

# default action: build all
all: $(BUILD_DIR)/$(TARGET) 

# list of objects
OBJECTS = $(addprefix $(BUILD_DIR)/,$(notdir $(C_SOURCES:.c=.o)))
vpath %.c $(sort $(dir $(C_SOURCES)))
# list of ASM program objects
OBJECTS += $(addprefix $(BUILD_DIR)/,$(notdir $(ASM_SOURCES:.s=.o)))
vpath %.s $(sort $(dir $(ASM_SOURCES)))

$(BUILD_DIR)/%.o: %.c Makefile | $(BUILD_DIR) 
	$(CC) -c $(CFLAGS)  $< -o $@

$(BUILD_DIR)/%.o: %.s Makefile | $(BUILD_DIR)
	$(AS) -c $(CFLAGS) $< -o $@

$(BUILD_DIR)/$(TARGET): $(OBJECTS) Makefile
	$(CC) $(OBJECTS) $(LDFLAGS) -o $@

$(BUILD_DIR):
	mkdir $@
  
env:
	@echo -e $(C_SOURCES) \n $(C_INCLUDES)

# clean up
clean:
	-rm -fR $(BUILD_DIR)
  
#######################################
# dependencies
#######################################
-include $(wildcard $(BUILD_DIR)/*.d)

# *** EOF ***
