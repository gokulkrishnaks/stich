CC := cc
CFLAGS := -std=c11 -Wall -Wextra -Wpedantic -I.
BUILD_DIR := build
TARGET := $(BUILD_DIR)/stich

SOURCES := \
	runtime/core/runtime.c \
	runtime/core/event_loop.c \
	runtime/core/router.c \
	runtime/core/registry.c \
	runtime/events/event_serializer.c \
	runtime/adapters/mqtt/mqtt_adapter.c \
	runtime/adapters/mqtt/mqtt_parser.c \
	runtime/observability/logger.c \
	runtime/observability/metrics.c \
	runtime/utils/config.c \
	runtime/utils/timestamp.c

OBJECTS := $(SOURCES:%.c=$(BUILD_DIR)/%.o)

.PHONY: all clean run test

all: $(TARGET)

$(TARGET): $(OBJECTS)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(OBJECTS) -o $@

$(BUILD_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

run: $(TARGET)
	./$(TARGET)

test: $(TARGET)
	./scripts/test.sh

clean:
	rm -rf $(BUILD_DIR)
