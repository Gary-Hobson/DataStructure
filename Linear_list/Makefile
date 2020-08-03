######################################
# target
######################################
TARGET = list

# debug build?
DEBUG = 1
# optimization
OPT = -Os

# Build path
BUILD_DIR = build


# binaries
CC =gcc

# C sources
C_SOURCES =  \
linear_list.c  \
main.c \

# C includes
C_INCLUDES =  \
-I../../platform

# C defines
C_DEFS =  \


# compile gcc flags
CFLAGS = $(MCU) $(C_DEFS) $(C_INCLUDES) $(OPT) -Wall -fdata-sections -ffunction-sections 

ifeq ($(DEBUG), 1)
CFLAGS += -g -gdwarf-2
endif

# Generate dependency information
CFLAGS += 


# libraries
LIBS = 
LIBDIR = -L/usr/local/lib 
LDFLAGS =   $(LIBDIR) $(LIBS) 

# default action: build all
all: $(BUILD_DIR)/$(TARGET) 


#######################################
# build the application
#######################################
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
