HOMELIB		= $(HOME)/lib
ROOTINC		=-I$(shell root-config --incdir)
ROOTLIBS	=$(shell root-config --libs) -lMinuit -lRooFit -lRooFitCore -lRooStats 
ROOTCFLAGS	=$(shell root-config --cflags)
ROOTGLIBS	=$(shell root-config --glibs) -lMinuit -lRooFit -lRooFitCore -lRooStats
DLPSLIBS	= -L$(HOMELIB) -lDelphesTree.2014
#MYHEADERS=-I../interface

CXX=g++

GLIBS		=$(ROOTGLIBS) 
LIBS		= $(ROOTLIBS)
LIBS		+= $(DLPSLIBS)

#HEADERS 	+= $(MYHEADERS)


all:  dlps clean

sim: SIM clean


dlps:
	@echo "Compiling the ParametrizationTest .... \n"
	$(CXX) ParametrizationTest.C -c -o ParametrizationTest.o -O0 $(ROOTCFLAGS) -fPIC -g
	@echo "Linking ...... \n"
	g++ ParametrizationTest.o -o doParamTest $(ROOTGLIBS) $(LIBS) -g -fPIC -O0 -I/opt/root/include -m64 -pthread 
	
SIM:
	@echo "Compiling the SimultaneousFit .... \n"
	$(CXX) SimultaneousFit.C -c -o SimultaneousFit.o -O0 $(ROOTCFLAGS) -fPIC -g
	@echo "Linking ...... \n"
	g++ SimultaneousFit.o -o SimFit $(ROOTGLIBS) $(LIBS) -g -fPIC -O0 -I/opt/root/include -m64 -pthread 
	
clean:
	@echo "Cleaning..."
	@rm -f *.o


