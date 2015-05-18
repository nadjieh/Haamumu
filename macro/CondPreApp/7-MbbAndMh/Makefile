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
	$(CXX) DelphesHistCreator.C -c -o DelphesHistCreator.o -O0 $(ROOTCFLAGS) -fPIC $(HEADERS) -g
	@echo "Linking ...... \n"
	g++ DelphesHistCreator.o -o DelphesHistCreator $(ROOTGLIBS) $(LIBS) -g -fPIC -O0 -I/opt/root/include -m64 -pthread $(HEADERS)
	
plot:
	@echo "Compiling the ShapePlotter.C .... \n"
	$(CXX) ShapePlotter.C -c -o ShapePlotter.o -O0 $(ROOTCFLAGS) -fPIC $(HEADERS) -g
	@echo "Linking ...... \n"
	g++ ShapePlotter.o -o ShapePlotter $(ROOTGLIBS) $(LIBS) -g -fPIC -O0 -I/opt/root/include -m64 -pthread $(HEADERS)
	
PYTHIA:
	@echo "Compiling the PythiaHistCreator .... \n"
	$(CXX) PythiaHistCreator.C -c -o PythiaHistCreator.o -O0 $(ROOTCFLAGS) -fPIC $(HEADERS) -g
	@echo "Linking ...... \n"
	g++ PythiaHistCreator.o -o PythiaHistCreator $(ROOTGLIBS) $(LIBS) -g -fPIC -O0 -I/opt/root/include -m64 -pthread $(HEADERS)	
	
TemplateFittingDY:
	@echo "Compiling the TemplateFit_DY .... \n"
	$(CXX) TemplateFit_DY.C -c -o TemplateFit_DY.o -O0 $(ROOTCFLAGS) -fPIC $(HEADERS) -g
	@echo "Linking ...... \n"
	g++ TemplateFit_DY.o -o doTemplateFitDY $(ROOTGLIBS) $(LIBS) -g -fPIC -O0 -I/opt/root/include -m64 -pthread $(HEADERS)		
	
TemplateFittingTT:
	@echo "Compiling the TemplateFit_ttbar .... \n"
	$(CXX) TemplateFit_ttbar.C -c -o TemplateFit_ttbar.o -O0 $(ROOTCFLAGS) -fPIC $(HEADERS) -g
	@echo "Linking ...... \n"
	g++ TemplateFit_ttbar.o -o doTemplateFitTT $(ROOTGLIBS) $(LIBS) -g -fPIC -O0 -I/opt/root/include -m64 -pthread $(HEADERS)		
	
RDSP:
	@echo "Compiling the RDSPlot .... \n"
	$(CXX) RDSPlot.C -c -o RDSPlot.o -O0 $(ROOTCFLAGS) -fPIC $(HEADERS) -g
	@echo "Linking ...... \n"
	g++ RDSPlot.o -o plotRDS $(ROOTGLIBS) $(LIBS) -g -fPIC -O0 -I/opt/root/include -m64 -pthread $(HEADERS)	
	
TemplateFittingDYPE:
	@echo "Compiling the TemplateFit_DY .... \n"
	$(CXX) PeTemplateFit_DY.C -c -o PeTemplateFit_DY.o -O0 $(ROOTCFLAGS) -fPIC $(HEADERS) -g
	@echo "Linking ...... \n"
	g++ PeTemplateFit_DY.o -o doPeTemplateFitDY $(ROOTGLIBS) $(LIBS) -g -fPIC -O0 -I/opt/root/include -m64 -pthread $(HEADERS)		
	
DYPETreeReader:
	@echo "Compiling the ReadDYPETree .... \n"
	$(CXX) ReadDYPETree.C -c -o ReadDYPETree.o -O0 $(ROOTCFLAGS) -fPIC $(HEADERS) -g
	@echo "Linking ...... \n"
	g++ ReadDYPETree.o -o readDyTree $(ROOTGLIBS) $(LIBS) -g -fPIC -O0 -I/opt/root/include -m64 -pthread $(HEADERS)	
	
OPTIMIZATION:
	@echo "Compiling the Optimization .... \n"
	$(CXX) Optimization.C -c -o Optimization.o -O0 $(ROOTCFLAGS) -fPIC $(HEADERS) -g
	@echo "Linking ...... \n"
	g++ Optimization.o -o Optimize $(ROOTGLIBS) $(LIBS) -g -fPIC -O0 -I/opt/root/include -m64 -pthread $(HEADERS)			
	
clean:
	@echo "Cleaning..."
	@rm -f *.o


