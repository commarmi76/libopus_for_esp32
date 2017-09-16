#
# Component Makefile
#
COMPONENT_ADD_INCLUDEDIRS := include  

COMPONENT_SRCDIRS := library 

CFLAGS += -Wno-implicit-function-declaration -Wno-unused-function -DHAVE_CONFIG_H  -DSPX_RESAMPLE_EXPORT= -DRANDOM_PREFIX=libopusenc -DOUTSIDE_SPEEX -lm -Os -DFLOATING_POINT -funroll-loops -ffast-math
