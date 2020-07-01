#############################################################################
#
# Project Makefile
#
# (c) Wouter van Ooijen (www.voti.nl) 2016
#
# This file is in the public domain.
# 
#############################################################################

# source files in this project (main.cpp is automatically assumed)
SOURCES := tetris.cpp effects.cpp tetris_animations.cpp tetris_pieces.cpp

# header files in this project
HEADERS := tetris.hpp effects.hpp tetris_animations.hpp tetris_pieces.hpp

# other places to look for files for this project
SEARCH  := ../ledscreen/library/

# set RELATIVE to the next higher directory 
# and defer to the appropriate Makefile.* there
RELATIVE := ../ledscreen/
include $(RELATIVE)/Makefile.due
include $(RELATIVE)/Makefile.ledscreen