#
# This is an example GNUmakefile for my packages
#

# specific names for this package
DICT  = Pixlar_CoreDataProductsDict
SHLIB = libPixlar_CoreDataProducts.so
SOURCES = $(filter-out $(DICT).cxx, $(wildcard *.cxx))
FMWK_HEADERS = LinkDef.h $(DICT).h
HEADERS = $(filter-out $(FMWK_HEADERS), $(wildcard *.h))
OBJECTS = $(SOURCES:.cxx=.o)

# include options for this package
INCFLAGS  = -I.                       #Include itself
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
include $(PIXLAR_EVD_BASEDIR)/Makefile/GNUmakefile.CORE

