#####################################################################################
#
# A top Makefile for building my project.
# One needs to define $PIXLAR_EVD_BASEDIR to build the sub directories.
#
#####################################################################################
#
# IMPOSE CONDITION BETWEEN PIXLAR_EVD_BASEDIR & PWD =>
#   do not compile if PWD !=$PIXLAR_EVD_BASEDIR is set elsewhere
#
ifndef PIXLAR_EVD_BASEDIR
 PIXLAR_EVD_BASEDIR := $(shell cd . && pwd -P)
endif
NORMALIZED_PIXLAR_EVD_BASEDIR := $(shell cd ${PIXLAR_EVD_BASEDIR} && pwd -P)
ifneq ($(NORMALIZED_PIXLAR_EVD_BASEDIR), $(shell cd . && pwd -P))
 ifneq ($(wildcard ./PMTDecoder/*),)
ERROR_MESSAGE := $(error Your source code detected in current dir, but PIXLAR_EVD_BASEDIR is not current dir.  \
   To avoid recompiling the wrong installation,\
   PIXLAR_EVD_BASEDIR must be set to the current directory when making.  \
   Currently it is set to ${PIXLAR_EVD_BASEDIR} [$(NORMALIZED_PIXLAR_EVD_BASEDIR)].  \
   Current directory is $(shell pwd).)
 endif
endif
export PIXLAR_EVD_BASEDIR

all:
	@mkdir -p $(PIXLAR_EVD_BASEDIR)/lib
	@echo "Start building core"
	@+make --directory=$(PIXLAR_EVD_COREDIR)
	@echo 
	@echo "Exiting"

clean:
	@echo "Cleaning core"
	@+make clean --directory=$(PIXLAR_EVD_COREDIR)
	@echo
	@echo "Exiting"

#####################################################################################
#
# DOCUMENTATION...
#
doxygen:
	@echo 'dOxygenising your code...'
	@doxygen $(PIXLAR_EVD_BASEDIR)/doc/doxygenMyProject.script

doxygen+:
	@echo 'dOxygenising MyProject + local-ROOT...'
	@doxygen $(PIXLAR_EVD_BASEDIR)/doc/doxygenMyProject+.script
#
#####################################################################################
