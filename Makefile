CC := cc
CFLAGS := -std=c11 -Wall -Wextra -Wpedantic -I.
BUILD_DIR := build
TARGET := $(BUILD_DIR)/stich

SOURCES := \
	canonical/validation/validation.c \
	canonical/normalization/normalization.c \
#	adapters/fake/fake_adapter.c \
	thread/router/router.c \
	sinks/stdout/stdout_sink.c
#	main.c

OBJECTS := $(SOURCES:%.c=$(BUILD_DIR)/%.o)

.PHONY: all clean run test

all: $(TARGET)

$(TARGET): $(SOURCES)
	$(CC) $(CFLAGS) $(SOURCES) -o $(TARGET)

$(BUILD_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

#run: $(TARGET)
#	./$(TARGET)

#test: $(TARGET)
#	./scripts/test.sh

clean:
	rm -rf $(BUILD_DIR)
