INCDIR = inc
BINDIR = bin
SRCDIR = src
EXEDIR = ../src/bin
DEFS = -D__JL_RANDOM__
CCX = g++
CXXFlags += -Wall --std=c++11 -I$(INCDIR)

COMP = $(CCX) $(CXXFlags)
JLOBJ = $(BINDIR)/jl.o $(BINDIR)/jlutility.o $(BINDIR)/jlarray.o $(BINDIR)/jlmatrix.o $(BINDIR)/jlshape.o $(BINDIR)/jlmath.o $(BINDIR)/jlrandom.o
JLDEP = $(SRCDIR)/jl.cpp $(BINDIR)/jlutility.o $(BINDIR)/jlarray.o $(BINDIR)/jlmatrix.o $(BINDIR)/jlshape.o $(BINDIR)/jlmath.o $(BINDIR)/jlrandom.o
UTILDEP = $(SRCDIR)/jlutility.cpp $(INCDIR)/jlutility.h
ARRDEP = $(SRCDIR)/jlarray.cpp $(INCDIR)/jlarray.h
MATDEP = $(SRCDIR)/jlmatrix.cpp $(INCDIR)/jlmatrix.h $(BINDIR)/jlarray.o $(BINDIR)/jlshape.o
MATOBJ = $(BINDIR)/jlmatrix.o $(BINDIR)/jlarray.o $(BINDIR)/jlshape.o
SHPDEP = $(SRCDIR)/jlshape.cpp $(INCDIR)/jlshape.h
MATHDEP = $(SRCDIR)/jlmath.cpp $(INCDIR)/jlmath.h
RNDDEP = $(SRCDIR)/jlrandom.cpp $(INCDIR)/jlrandom.h

all : jl

jl : $(JLOBJ)
	$(COMP) -o $(EXEDIR)/jl.exe $(JLOBJ)

$(BINDIR)/jl.o : $(JLDEP)
	$(COMP) -c $(JLDEP) -o $(BINDIR)/jl.o

$(BINDIR)/jlutility.o : $(UTILDEP)
	$(COMP) -c $(SRCDIR)/jlutility.cpp -o $(BINDIR)/jlutility.o

$(BINDIR)/jlarray.o : $(ARRDEP)
	$(COMP) -c $(SRCDIR)/jlarray.cpp -o $(BINDIR)/jlarray.o

$(BINDIR)/jlmatrix.o : $(MATDEP)
	$(COMP) -c $(SRCDIR)/jlmatrix.cpp $(BINDIR)/jlarray.o $(BINDIR)/jlshape.o -o $(BINDIR)/jlmatrix.o

$(BINDIR)/jlshape.o : $(SHPDEP)
	$(COMP)	-c $(SRCDIR)/jlshape.cpp -o $(BINDIR)/jlshape.o

$(BINDIR)/jlmath.o : $(MATHDEP)
	$(COMP) -c $(SRCDIR)/jlmath.cpp -o $(BINDIR)/jlmath.o

$(BINDIR)/jlrandom.o : $(RNDDEP)
	$(COMP) -c $(SRCDIR)/jlrandom.cpp -o $(BINDIR)/jlrandom.o

clean :
	rm $(BINDIR)/*
