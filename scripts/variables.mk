# Set MCU name and length of binary for bootloader
# WARNING: Fuse settings not tested!
MCU := $(CONFIG_MCU)
ifeq ($(MCU),atmega16)
	BINARY_LENGTH = 0x3c00
	EFUSE = 0xff
	HFUSE = 0xd2
	LFUSE = 0xfc
else ifeq ($(MCU),atmega8)
	BINARY_LENGTH = 0x1c00
  HFUSE = 0xd1
  LFUSE = 0xe4
else ifeq ($(MCU),atmega88)
  BINARY_LENGTH = 0x1c00
  EFUSE = 0xf9
  HFUSE = 0xdc
  LFUSE = 0xe2
else ifeq ($(MCU),atmega168)
  BINARY_LENGTH = 0x3c00
  EFUSE = 0xf9
  HFUSE = 0xdc
  LFUSE = 0xe2
else ifeq ($(MCU),atmega162)
  BINARY_LENGTH = 0x3c00
  EFUSE = 0xff
  HFUSE = 0xd2
  LFUSE = 0xfc
else ifeq ($(MCU),atmega32)
  BINARY_LENGTH = 0x7800
  EFUSE = 0xff
  HFUSE = 0xd2
  LFUSE = 0xfc
else ifeq ($(MCU),atmega128)
  BINARY_LENGTH = 0x1f000
  EFUSE = 0xff
  HFUSE = 0xd2
  LFUSE = 0xfc
else ifeq ($(MCU),atmega1281)
  BINARY_LENGTH = 0x1f000
  EFUSE = 0xff
  HFUSE = 0xd2
  LFUSE = 0xfc
else ifeq ($(MCU),atmega2561)
  BINARY_LENGTH = 0x3f000
  EFUSE = 0xfd
  HFUSE = 0x93
  LFUSE = 0xef
else ifeq ($(MCU),atmega644)
  BINARY_LENGTH = 0xf000
  EFUSE = 0xfd
  HFUSE = 0x91
  LFUSE = 0xef
else ifeq ($(MCU),atmega644p)
  BINARY_LENGTH = 0xf000
  EFUSE = 0xfd
  HFUSE = 0x91
  LFUSE = 0xef
else ifeq ($(MCU),attiny2313)
  BINARY_LENGTH = 0x7800
  EFUSE = 0xff
  HFUSE = 0x9f
  LFUSE = 0xff
else ifeq ($(MCU),attiny26)
  BINARY_LENGTH = 0x7800
  HFUSE = 0x9f
  LFUSE = 0xff
else
.PHONY: nochip
nochip:
	@echo '=============================================================='
	@echo 'No known target chip specified.'
	@echo
	@echo 'Please edit the Makefile.'
	@exit 1
endif