HOMELIB		= $(HOME)/lib
ROOTINC		=-I$(shell root-config --incdir)
ROOTLIBS	=$(shell root-config --libs) -lMinuit -lRooFit -lRooFitCore -lRooStats 
ROOTCFLAGS	=$(shell root-config --cflags)
ROOTGLIBS	=$(shell root-config --glibs) -lMinuit -lRooFit -lRooFitCore -lRooStats
DLPSLIBS	= -L$(HOMELIB) -lDelphesTree.2014
MYHEADERS=-I../interface

CXX=g++

GLIBS		=$(ROOTGLIBS) 
LIBS		= $(ROOTLIBS)
LIBS		+= $(DLPSLIBS)

HEADERS 	+= $(MYHEADERS)


all:  dlps clean

p: plot clean

pythia: PYTHIA clean

tt: TemplateFittingTT clean

dy: TemplateFittingDY clean

dype: TemplateFittingDYPE clean

rds: RDSP clean

dt: DYPETreeReader clean

opt: OPTIMIZATION clean

dlps:
	@echo "Compiling the DelphesHistCreator .... \n"
	$(CXX) mainFit.C -c -o mainFit.o -O0 $(ROOTCFLAGS) -fPIC $(HEADERS) -g
	@echo "Linking ...... \n"
	g++ mainFit.o -o mainFit $(ROOTGLIBS) $(LIBS) -g -fPIC -O0 -I/opt/root/include -m64 -pthread $(HEADERS)
	

clean:
	@echo "Cleaning..."
	@rm -f *.o


