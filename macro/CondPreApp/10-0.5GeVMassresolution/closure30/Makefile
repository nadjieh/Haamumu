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

sys: UNC clean

com: COM clean

dlps:
	@echo "Compiling the ParametrizationTest .... \n"
	$(CXX) ParametrizationTest.C -c -o ParametrizationTest.o -O0 $(ROOTCFLAGS) -fPIC -g
	@echo "Linking ...... \n"
	g++ ParametrizationTest.o -o doParamTest $(ROOTGLIBS) $(LIBS) -g -fPIC -O0 -I/opt/root/include -m64 -pthread 
	
SIM:
	@echo "Compiling the SimultaneousFit_Closure30 .... \n"
	$(CXX) SimultaneousFit_Closure30.C -c -o SimultaneousFit_Closure30.o -O0 $(ROOTCFLAGS) -fPIC -g
	@echo "Linking ...... \n"
	g++ SimultaneousFit_Closure30.o -o SimFitClosure30 $(ROOTGLIBS) $(LIBS) -g -fPIC -O0 -I/opt/root/include -m64 -pthread 
	
UNC:
	@echo "Compiling the Uncertainties .... \n"
	$(CXX) Uncertainties.C -c -o Uncertainties.o -O0 $(ROOTCFLAGS) -fPIC -g
	@echo "Linking ...... \n"
	g++ Uncertainties.o -o doSysts $(ROOTGLIBS) $(LIBS) -g -fPIC -O0 -I/opt/root/include -m64 -pthread 	
	
COM:
	@echo "Compiling the ComposedFit .... \n"
	$(CXX) ComposedFit.C -c -o ComposedFit.o -O0 $(ROOTCFLAGS) -fPIC -g
	@echo "Linking ...... \n"
	g++ ComposedFit.o -o composedFit $(ROOTGLIBS) $(LIBS) -g -fPIC -O0 -I/opt/root/include -m64 -pthread 
		
clean:
	@echo "Cleaning..."
	@rm -f *.o


