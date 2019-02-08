# Arduino Library base folder and example structure
WORKSPACE_FOLDER ?= $(abspath .)
EXTERNAL_FOLDER = $(WORKSPACE_FOLDER)/external
TOOLS_FOLDER = $(WORKSPACE_FOLDER)/tools

# Arduino CLI executable name and directory location
ifeq ($(OS),Windows_NT)
	ARDUINO_CLI = $(TOOLS_FOLDER)/arduino-cli.exe
else
	ARDUINO_CLI = $(TOOLS_FOLDER)/tools/arduino-cli
endif

# Arduino CLI Board type
BOARD_TYPE = arduino:avr
FQBN = $(BOARD_TYPE):uno

# Default port to upload to
SERIAL_PORT ?= 

# Optional verbose compile/upload trigger
VERBOSE = 

# Build path -- used to store built binary and object files
BUILD_FOLDER = $(WORKSPACE_FOLDER)/build
PROJECT_NAME = Nemesis-Mod
PROJECT_FOLDER = $(WORKSPACE_FOLDER)/$(PROJECT_NAME)
CONFIG_FILE = $(WORKSPACE_FOLDER)/.cli-config.yml

all: install_prerequisites rebuild

rebuild: clean build

install_prerequisites:
	"$(ARDUINO_CLI)" core update-index --config-file "$(CONFIG_FILE)"
	"$(ARDUINO_CLI)" core install $(BOARD_TYPE) --config-file "$(CONFIG_FILE)"

clean:
	@rm -rf "$(BUILD_FOLDER)"

build:
	"$(ARDUINO_CLI)" compile $(VERBOSE) --build-path="$(BUILD_FOLDER)" --build-cache-path="$(BUILD_FOLDER)" -b $(FQBN) "$(PROJECT_FOLDER)" --config-file "$(CONFIG_FILE)"

upload:
	"$(ARDUINO_CLI)" upload --port $(SERIAL_PORT) --fqbn $(FQBN) --verify "$(PROJECT_FOLDER)" --config-file "$(CONFIG_FILE)"
