# MAKE FILE
#    	FUNCTION: 	Complie the NANO program
#	   	AUTHOR  : 	ZHIRUI FAN
#	   	DATE    :	2019-1-10
#		COPYRIGHT(C) ALL RESERVED 2018-2019
#
# The Include file of Petsc
#		DEBUG
#PETSC_DIR=/usr/include/petsc/petsc-3.12.5/debug
PETSC_DIR=/usr/include/petsc/petsc-3.15.0/debug
#PETSC_ARCH=arch-linux-c-debug
PETSC_ARCH=arch-linux2-c-debug
#
#		RELEASE
#PETSC_DIR=/usr/include/petsc/petsc-3.12.5/release
#PETSC_DIR=/usr/include/petsc/petsc-3.15.0/release
#PETSC_ARCH=arch-linux-c-opt
#PETSC_ARCH=arch-linux2-c-opt
include ${PETSC_DIR}/lib/petsc/conf/variables
include ${PETSC_DIR}/lib/petsc/conf/rules
include ${PETSC_DIR}/lib/petsc/conf/test

PETSC_INC = -I ${PETSC_DIR}/include
PETSC_ARCH_INC = -I ${PETSC_DIR}/${PETSC_ARCH}/include

# Get the all .cpp files' name
SRCFILES = $(wildcard *.cpp)
# $(info $(SRCFILES))

# Generate all .o files' name
OBJFILES = $(patsubst %.cpp, %.o, $(notdir $(SRCFILES)))
# $(info $(OBJFILES))

# Compile the nanolab program
main: $(OBJFILES)
	$(CLINKER) -w -o main $(OBJFILES) $(PETSC_SYS_LIB) $(PETSC_INC) $(PETSC_ARCH_INC)
%.o: %.cpp
	${CLINKER} -c $< $(PETSC_SYS_LIB) $(PETSC_INC) $(PETSC_ARCH_INC) -o $@
cleanup:
	rm *.o main

