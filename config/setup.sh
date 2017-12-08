#!/bin/bash


me="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
# Find the directory one above.
export PIXLAR_EVD_BASEDIR="$( cd "$( dirname "$me" )" && pwd )"

# Abort if ROOT not installed. Let's check rootcint for this.
if [ `command -v rootcling` ]; then
    export PIXLAR_EVD_ROOT6=1
else 
    if [[ -z `command -v rootcint` ]]; then
        echo
        echo Looks like you do not have ROOT installed.
        echo You cannot use PIXLAR_EVD w/o ROOT!
        echo Aborting.
        echo
        return;
    fi
fi


PIXLAR_EVD_OS=`uname -s`

# Set path to sub directories
export PIXLAR_EVD_LIBDIR=$PIXLAR_EVD_BASEDIR/lib
export PIXLAR_EVD_COREDIR=$PIXLAR_EVD_BASEDIR/core

# Check compiler availability for clang++ and g++
PIXLAR_EVD_CXX=g++
if [ `command -v $PIXLAR_EVD_CXX` ]; then
    export PIXLAR_EVD_CXX="$PIXLAR_EVD_CXX -std=c++11";
else
    PIXLAR_EVD_CXX=g++
    if [[ -z `command -v $PIXLAR_EVD_CXX` ]]; then
        echo
        echo Looks like you do not have neither clang or g++!
        echo You need one of those to compile PIXLAR_EVD... Abort config...
        echo
        return;
    fi
    export PIXLAR_EVD_CXX;
    if [ $PIXLAR_EVD_OS = 'Darwin' ]; then
        echo $PIXLAR_EVD_OS
        echo
        echo "***************** COMPILER WARNING *******************"
        echo "*                                                    *"
        echo "* You are using g++ on Darwin to compile Gallery Framework.    *"
        echo "* Currently Gallery Framework assumes you do not have C++11    *"
        echo "* in this combination. Contact the author if this is *"
        echo "* not the case. At this rate you have no ability to  *"
        echo "* compile packages using C++11 in Gallery Framework.           *"
        echo "*                                                    *"
        echo "* Help to install clang? See manual/contact author!  *"
        echo "*                                                    *"
        echo "******************************************************"
        echo 
    fi
fi
if [[ -z $ROOTSYS ]]; then
    echo
    echo "****************** PyROOT WARNING ********************"
    echo "*                                                    *"
    echo "* Did not find your \$ROOTSYS. To use PyROOT feature, *"
    echo "* Make sure ROOT.py is installed (comes with ROOT).  *"
    echo "* You need to export \$PYTHONPATH to include the dir  *"
    echo "* where ROOT.py exists.                              *"
    echo "*                                                    *"
    echo "* Help to install PyROOT? See manual/contact author! *"
    echo "*                                                    *"
    echo "******************************************************"
    echo
else
    export PYTHONPATH=$ROOTSYS/lib:$PYTHONPATH;
fi



# python $LARLITE_BASEDIR/config/python/gen_usermakefile.py
# python $LARLITE_BASEDIR/config/python/gen_topmakefile.py
export LD_LIBRARY_PATH=$PIXLAR_EVD_LIBDIR:$LD_LIBRARY_PATH
# if [ $LARLITE_OS = 'Darwin' ]; then
#     export DYLD_LIBRARY_PATH=$LARLITE_LIBDIR:$DYLD_LIBRARY_PATH
# fi
export PATH=$PIXLAR_EVD_BASEDIR/bin:$PATH
# if [ $ENABLE_LARLITE_ALIAS ]; then
#     alias maketop="make --directory=$LARLITE_BASEDIR"
#     alias cdtop="cd $LARLITE_BASEDIR"
#     alias llgen_package="python $LARLITE_BASEDIR/bin/gen_package"
#     alias llgen_repository="python $LARLITE_BASEDIR/bin/gen_repository"
#     alias llgen_class_empty="python $LARLITE_BASEDIR/bin/gen_class_empty"
#     alias llgen_class_anaunit="python $LARLITE_BASEDIR/bin/gen_class_anaunit"
#     alias llgen_class_erana="python $LARLITE_BASEDIR/bin/gen_class_erana"
#     alias llgen_class_eralgo="python $LARLITE_BASEDIR/bin/gen_class_eralgo"
#     alias llgen_class_erfilter="python $LARLITE_BASEDIR/bin/gen_class_erfilter"
# fi

echo
echo "Finish configuration. To build, type:"
echo "> cd \$PIXLAR_EVD_BASEDIR"
echo "> make"
echo



PYTHONPATH_backup=$PYTHONPATH
PATH_backup=$PATH

if [[ ! ":$PATH:" == *":$PIXLAR_EVD_BASEDIR/python:"* ]]; then
  export PATH=$PIXLAR_EVD_BASEDIR/python:$PATH
fi

if [[ ! ":$PYTHONPATH:" == *":$PIXLAR_EVD_BASEDIR/python:"* ]]; then
  export PYTHONPATH=$PIXLAR_EVD_BASEDIR/python/:$PYTHONPATH
fi

# Test argparse
if ! $(python -c "import argparse" &> /dev/null); then 
  echo "Warning: can not use evd due to missing package argparse"
  export PATH=$PATH_backup
  export PYTHONPATH=$PYTHONPATH_backup
  return
fi

# Test numpy
if ! $(python -c "import numpy" &> /dev/null); then 
  echo "Warning: can not use evd due to missing package numpy"
  export PATH=$PATH_backup
  export PYTHONPATH=$PYTHONPATH_backup 
  return
fi

# Test pyqt4
if ! $(python -c "import pyqtgraph.Qt" &> /dev/null); then 
  echo "Warning: can not use evd due to missing package PyQt"
  export PATH=$PATH_backup
  export PYTHONPATH=$PYTHONPATH_backup
  return
fi