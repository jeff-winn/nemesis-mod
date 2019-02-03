# Arduino Library base folder and example structure
WORKSPACE_FOLDER = .\

# Arduino CLI executable name and directory location
ARDUINO_CLI = arduino-cli.exe
TOOLS_FOLDER = $(WORKSPACE_FOLDER)\tools

# Arduino CLI Board type
BOARD_TYPE = arduino:avr:uno

# Default port to upload to
SERIAL_PORT ?= 

# Optional verbose compile/upload trigger
VERBOSE = 

# Build path -- used to store built binary and object files
BUILD_FOLDER=$(WORKSPACE_FOLDER)\build
PROJECT_FOLDER=$(WORKSPACE_FOLDER)\Nemesis-Mod

.PHONY: build clean

build:
	$(TOOLS_FOLDER)/$(ARDUINO_CLI) compile $(VERBOSE) --build-path=$(BUILD_FOLDER) --build-cache-path=$(BUILD_FOLDER) -b $(BOARD_TYPE) $(PROJECT_FOLDER)

clean:
	@rm -rf $(BUILD_PATH)
	@rm $(PROJECT_FOLDER)/*.elf
	@rm $(PROJECT_FOLDER)/*.hex