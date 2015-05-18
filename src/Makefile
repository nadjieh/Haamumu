ObjSuf        = o
SrcSuf        = cc
ExeSuf        = 
DllSuf        = so
OutPutOpt     = -o
HeadSuf       = h
CLIBS		=-L/usr/lib -lstdc++
ROOTINC		=-I$(shell root-config --incdir)
ROOTLIBS	=$(shell root-config --libs) -lMinuit -lRooFit -lRooFitCore -lRooStats 
ROOTCFLAGS	=$(shell root-config --cflags)
ROOTGLIBS	=$(shell root-config --glibs) -lMinuit -lRooFit -lRooFitCore -lRooStats 
HOMELIB		= $(HOME)/lib

BASEINC = -I../../Base/BaseAnalysis/interface/
ORSOINCLUDES = -I../interface
ORSOSOURCES = ../src

#PHYSOBJINC = -I../../AnalysisClasses/PhysicsObjects/interface/
#TOYINCLUDES = -I../../AnalysisClasses/ToyAnalysis/interface/

CXX=g++
CXXFLAGS	= -O -Wall -fPIC
LD		= g++
LDFLAGS 	= -g
SOFLAGS 	= -shared

HEADERS 	=$(ORSOINCLUDES)

PHYSOBJLIB	=-L$(HOMELIB) -lPhysObj.2013
TOYLIB	=-L$(HOMELIB) -lToyAnalysis.2013
TROOTLIB	=-L$(HOMELIB) -lToto.2013
BASELIB	=-L$(HOMELIB) -lBaseBaseAnalysis.2013
# Linux with egcs



CXXFLAGS	+= $(ROOTCFLAGS)
GLIBS		=$(ROOTGLIBS) 
LIBS		= $(ROOTLIBS) 
LIBS		+= $(PHYSOBJLIB)
LIBS		+= $(TOYLIB)
LIBS		+= $(TROOTLIB)
LIBS		+= $(BASELIB)
#------------------------------------------------------------------------------
SOURCES 	= $(wildcard $(ORSOSOURCES)/*.cc)
HEADERS 	= $(wildcard $(ORSOINCLUDES)/*.h)
OBJECTS 	= $(SOURCES:.$(SrcSuf)=.$(ObjSuf))
DEPENDS 	= $(SOURCES:.$(SrcSuf)=.d)
SOBJECTS	= $(SOURCES:.$(SrcSuf)=.$(DllSuf))


HEADERS 	+= $(BASEINC)
#HEADERS 	+= $(TOYINCLUDES)
#PROGRAMS	=  $(SOBJECTS)

all: libDelphesTree.2014.so clean ; cp libDelphesTree.2014.so $(HOMELIB)

clean:
	@echo "Cleaning..."
	@rm -f $(OBJECTS) $(DEPENDS) *Dict.* core

.SUFFIXES: .$(SrcSuf) .C .o .so

###


.$(SrcSuf).$(ObjSuf):
	$(CXX) $(CXXFLAGS) -c $<

tst:
	echo $(LD) $(LIBS) $(GLIBS) $(SOFLAGS) $(LDFLAGS) $+ -o $@

libDelphesTree.2014.so: $(OBJECTS)
	$(LD) $(LIBS) $(GLIBS) $(SOFLAGS) $(LDFLAGS) $+ -o $@
	@echo "$@ done"
