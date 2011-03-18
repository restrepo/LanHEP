#CC = 
#FC =
#CXX =
#CFLAGS = 
#FFLAGS = 
#CXXFLAGS = 


.PHONY: all clean


all: libSLHAplus.a

OBJ =  alpha_s.o aux.o ferror.o  jacobi.o fixArg.o chDiag.o SLHAreader.o 

ifneq (,$(FC))
    override OBJ += faux.o fortran.o
endif 

libSLHAplus.a:libSLHAplus.a($(OBJ))
	rm -f *.o

clean: 
	rm -f libSLHAplus.a *.o MSSM/*.mdl 
	$(MAKE) -C test clean	
