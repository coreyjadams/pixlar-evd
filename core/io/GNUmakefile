#
# This is an example GNUmakefile for my packages
#

# specific names for this package
DICT  = Pixlar_CoreIODict
SHLIB = libPixlar_CoreIO.so
SOURCES = $(filter-out $(DICT).cxx, $(wildcard *.cxx))
FMWK_HEADERS = LinkDef.h $(DICT).h
HEADERS = $(filter-out $(FMWK_HEADERS), $(wildcard *.h))
OBJECTS = $(SOURCES:.cxx=.o)

# include options for this package
INCFLAGS  = -I.                       #Include itself
INCFLAGS += -I$(PIXLAR_EVD_BASEDIR)
INCFLAGS += $(shell python-config --includes)
INCFLAGS += -I$(shell python -c "import numpy; print numpy.get_include()")

# platform-specific options
OSNAME          = $(shell uname -s)
HOST            = $(shell uname -n)
OSNAMEMODE      = $(OSNAME)



include $(PIXLAR_EVD_BASEDIR)/Makefile/Makefile.${OSNAME}

# set compiler options for ROOT
CXXFLAGS +=  `root-config --cflags`

# call the common GNUmakefile
LDFLAGS += -L$(shell python-config --prefix)/lib/
LDFLAGS += $(shell python-config --ldflags)
LDFLAGS += -L$(PIXLAR_EVD_BASEDIR)/lib/ -lPixlar_CoreDataProducts -lPixlar_CoreUtils
include $(PIXLAR_EVD_BASEDIR)/Makefile/GNUmakefile.CORE

