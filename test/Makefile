# This is the test makefile for bugfree-robot firmware
#
# It works based on CppUTest

## Variables to help building absolute paths

MAKEFILE_DIR=$(dir $(realpath $(firstword $(MAKEFILE_LIST))))

PROJECT_DIR=$(realpath $(MAKEFILE_DIR)..)

TEST_DIR=$(PROJECT_DIR)/test


CPPUTEST_HOME=$(TEST_DIR)/cpputest


# -------------------- Source files paths ----------------------- 
# project source files path
SRC_DIRS=$(PROJECT_DIR)
SRC_DIRS+=$(PROJECT_DIR)/lib
SRC_DIRS+=$(PROJECT_DIR)/lib/MyGpio
SRC_DIRS+=$(PROJECT_DIR)/lib/MyGpio/HalGpio

# project header files path
INCLUDE_DIRS=$(PROJECT_DIR)
INCLUDE_DIRS+=$(PROJECT_DIR)/lib/MyGpio
INCLUDE_DIRS+=$(PROJECT_DIR)/lib/MyGpio/HalGpio
INCLUDE_DIRS+=$(PROJECT_DIR)/Core/Inc
INCLUDE_DIRS+=$(PROJECT_DIR)/Drivers/STM32F1xx_HAL_Driver/Inc
INCLUDE_DIRS+=$(PROJECT_DIR)/Drivers/CMSIS/Device/ST/STM32F1xx/Include
INCLUDE_DIRS+=$(PROJECT_DIR)/Drivers/CMSIS/Include

# add this to avoid problems when including cpputest headers on test files
INCLUDE_DIRS+=$(CPPUTEST_HOME)/include

## test source files path
TEST_SRC_DIRS=$(TEST_DIR)
#TEST_SRC_DIRS+=$(TEST_DIR)/drivers
TEST_SRC_DIRS+=$(TEST_DIR)/utils
#TEST_SRC_DIRS+=$(TEST_DIR)/mocks_tests

## mock path
# MOCKS_SRC_DIRS=$(TEST_DIR)/mocks
# MOCKS_SRC_DIRS+=$(TEST_DIR)/mocks/drivers
# MOCKS_SRC_DIRS+=$(TEST_DIR)/mocks/utils

#---------------------- Build flags ------------------
CPPUTEST_CPPFLAGS+=-DSTM32F103xB
CPPUTEST_CPPFLAGS+=-Wno-register
CPPUTEST_CPPFLAGS+=-Wno-error=unused-parameter
CPPUTEST_CPPFLAGS+=-Wall -fdata-sections -ffunction-sections

## what to call the test binary
TEST_TARGET=test_runner

# Add the library linking to your Makefile
LD_LIBRARIES += -L$(CPPUTEST_HOME)/lib -lCppUTestExt

#Reduce the excess of prints in the build process
ifndef SILENCE
	SILENCE = @
endif

#run MakefileWorker.mk with the variables defined here
include $(CPPUTEST_HOME)/build/MakefileWorker.mk


.PHONY: run
run: start $(TEST_TARGET)
	$(RUN_TEST_TARGET)

.PHONY: check_paths
check_paths:
		@echo "Repository dir: " $(REPOSITORY_DIR)
		@echo "Test dir :" $(TEST_DIR)
		@echo "Makefile dir :" $(MAKEFILE_DIR)
		@echo "Project dir :" $(PROJECT_DIR)
		@echo "Src dir :" $(SRC_DIR)
		@echo "Src dirs  :" $(SRC_DIRS)
		@echo "Include dirs  :" $(INCLUDE_DIRS)
		@echo "Cpputest home  :" $(CPPUTEST_HOME)