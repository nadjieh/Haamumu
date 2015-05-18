HOMELIB		= $(HOME)/lib
ROOTINC		=-I$(shell root-config --incdir)
ROOTLIBS	=$(shell root-config --libs) -lMinuit -lRooFit -lRooFitCore -lRooStats 
ROOTCFLAGS	=$(shell root-config --cflags)
ROOTGLIBS	=$(shell root-config --glibs) -lMinuit -lRooFit -lRooFitCore -lRooStats
DLPSLIBS	= -L$(HOMELIB) -lDelphesTree.2014
MYHEADERS=-I../../interface

CXX=g++

GLIBS		=$(ROOTGLIBS) 
LIBS		= $(ROOTLIBS)
LIBS		+= $(DLPSLIBS)

HEADERS 	+= $(MYHEADERS)


all:  skim clean

skim:
	@echo "Compiling the Skimmer .... \n"
	$(CXX) Skimmer.C -c -o Skimmer.o -O0 $(ROOTCFLAGS) -fPIC $(HEADERS) -g
	@echo "Linking ...... \n"
	g++ Skimmer.o -o doSkim $(ROOTGLIBS) $(LIBS) -g -fPIC -O0 -I/opt/root/include -m64 -pthread $(HEADERS)
	
clean:
	@echo "Cleaning..."
	@rm -f *.o


