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

t: Ttest clean

ws: WS clean

dlps:
	@echo "Compiling the myF_test .... \n"
	$(CXX) myF_test.C -c -o myF_test.o -O0 $(ROOTCFLAGS) -fPIC -g
	@echo "Linking ...... \n"
	g++ myF_test.o -o dotest $(ROOTGLIBS) $(LIBS) -g -fPIC -O0 -I/opt/root/include -m64 -pthread 
	
WS:
	@echo "Compiling the WSProvider.C .... \n"
	$(CXX) WSProvider.C -c -o WSProvider.o -O0 $(ROOTCFLAGS) -fPIC -g
	@echo "Linking ...... \n"
	g++ WSProvider.o -o provideWS $(ROOTGLIBS) $(LIBS) -g -fPIC -O0 -I/opt/root/include -m64 -pthread 
	
Ttest:
	@echo "Compiling the myT_test .... \n"
	$(CXX) myT_test.C -c -o myT_test.o -O0 $(ROOTCFLAGS) -fPIC -g
	@echo "Linking ...... \n"
	g++ myT_test.o -o doTtest $(ROOTGLIBS) $(LIBS) -g -fPIC -O0 -I/opt/root/include -m64 -pthread 	
	
clean:
	@echo "Cleaning..."
	@rm -f *.o


