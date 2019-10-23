# Arduino Library base folder and example structure
WORKSPACE_FOLDER ?= $(abspath .)
TOOLS_FOLDER = $(WORKSPACE_FOLDER)/tools

# Arduino CLI executable name and directory location
ifeq ($(OS),Windows_NT)
	ARDUINO_CLI = $(WORKSPACE_FOLDER)/arduino-cli.exe
else
	ARDUINO_CLI = $(WORKSPACE_FOLDER)/arduino-cli
endif

# Arduino CLI Board type
BOARD_TYPE = adafruit:samd
FQBN = $(BOARD_TYPE):adafruit_feather_m0

# Default port to upload to
SERIAL_PORT ?= 

# Optional verbose compile/upload trigger
VERBOSE = 

# Build path -- used to store built binary and object files
BUILD_FOLDER = $(WORKSPACE_FOLDER)/build
PROJECT_NAME = Nemesis-Mod
PROJECT_FOLDER = $(WORKSPACE_FOLDER)/$(PROJECT_NAME)
SKETCH_PATH = $(PROJECT_FOLDER)/Nemesis-Mod.ino
CONFIG_FILE = $(WORKSPACE_FOLDER)/arduino-cli.yaml

all: install_prerequisites rebuild

install_prerequisites: install_boards install_libraries

install_boards:
	"$(ARDUINO_CLI)" core update-index --config-file "$(CONFIG_FILE)"
	"$(ARDUINO_CLI)" core install $(BOARD_TYPE) --config-file "$(CONFIG_FILE)"

install_libraries:
	"$(ARDUINO_CLI)" lib install "Adafruit BluefruitLE nRF51"
	"$(ARDUINO_CLI)" lib install "Adafruit FRAM I2C"
	"$(ARDUINO_CLI)" lib install "DualG2HighPowerMotorShield"

rebuild: clean build

clean:
	@rm -rf "$(BUILD_FOLDER)"

build:
	"$(ARDUINO_CLI)" compile $(VERBOSE) --build-path="$(BUILD_FOLDER)" --build-cache-path="$(BUILD_FOLDER)" --fqbn $(FQBN) "$(SKETCH_PATH)" --output "$(SKETCH_PATH)" --config-file "$(CONFIG_FILE)"
