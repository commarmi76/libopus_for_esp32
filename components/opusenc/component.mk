#
# Component Makefile
#
COMPONENT_ADD_INCLUDEDIRS := include  

COMPONENT_SRCDIRS := library 

CFLAGS += -Wno-implicit-function-declaration -Wno-unused-function -DHAVE_CONFIG_H -lm
