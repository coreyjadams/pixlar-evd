
ifndef PIXLAR_EVD_BASEDIR
ERROR_MESSAGE := $(error PIXLAR_EVD_BASEDIR is not set... run configure.sh!)
endif

#####################################################################################
#
# Define directories to be compile upon a global "make"...
#
SUBDIRS := dataproducts utils io


#####################################################################################
#
# COMPILATION...
#
#.phony: all configure default-config clean
.phony: all clean

all:
	@for i in $(SUBDIRS); do ( echo "" && echo "Compiling $$i..." && cd $$i && $(MAKE) ) || exit $$?; done
#####################################################################################
#
# CLEANs...
#
clean:
	@for i in $(SUBDIRS); do ( echo "" && echo "Cleaning $$i..." && cd $$i && $(MAKE) clean ) || exit $$?; done

#####################################################################################
#
# DOCUMENTATION...
#
doxygen:
	@echo 'dOxygenising pixlar evd...'
	@mkdir -p $(LARCV_COREDIR)/doc/dOxygenMyProject
	@doxygen $(LARCV_COREDIR)/doc/doxygenMyProject.script
#
#####################################################################################
#EOF
