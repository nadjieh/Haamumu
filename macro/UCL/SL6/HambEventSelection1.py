import ROOT
import MonteCarloSelection
from ObjectSelection import *
import os
confCfg = os.environ["PatAnalysisCfg"]
if confCfg : from UserCode.zbb_louvain.PatAnalysis.CPconfig import configuration
else : from zbbConfig import configuration

#########################################################################
#  Standard methods  ####################################################
#########################################################################

# Everything is duplicated for Electrons and Muons. 
# For simplicity and clarity, methods are defined generically for each
# and the final (public) methods work by concatenating/splitting 

channels = [ "Muon" ]

categories = [ 

  "Trigger", #0
  #signal
  #m40: 24, 8, 20, 15, CSVT, 18, 20
  "ll + 1b (HP) + 1j (m40) ", #1
  "ll + 1b (HP) + 1j + METSIG < 6 (m40)", #2
  "ll + 1b (HP) + 1j + METSIG < 6 + mHWindow (m40)", #3
  "ll + 1b (HP) + 1j + METSIG < 6 + mHWindow + diffM (m40)", #4
  #m50: 24, 8, 18, 15, CSVT, 20, 25
  "ll + 1b (HP) + 1j (m50) ", #5
  "ll + 1b (HP) + 1j + METSIG < 6 (m50)", #6
  "ll + 1b (HP) + 1j + METSIG < 6 + mHWindow (m50)", #7
  "ll + 1b (HP) + 1j + METSIG < 6 + mHWindow + diffM (m50)", #8
  #m60: 24, 8, 15, 15, CSVT, 20, 20
  "ll + 1b (HP) + 1j (m60) ", #9
  "ll + 1b (HP) + 1j + METSIG < 6 (m60)", #10
  "ll + 1b (HP) + 1j + METSIG < 6 + mHWindow (m60)", #11
  "ll + 1b (HP) + 1j + METSIG < 6 + mHWindow + diffM (m60)", #12
]

categoryNames = [ chan+"/"+cat for chan in channels for cat in categories ]

def isInCategory(category, categoryTuple):
  return isInCategoryChannel(category,categoryTuple)

def isInCategoryChannel(category, categoryTuple):
  """Check if the event enters category X, given the tuple computed by eventCategory."""
  div = (category/4)
  # category 0: Trigger
  if category==0:
    return categoryTuple[0]==1
  # caregory 1: 2 muons + 2 jets + 1 Tight btag
  elif (category%4)==1:
    return isInCategoryChannel(0, categoryTuple) and categoryTuple[1] > configuration.mu1pt[div] and categoryTuple[2] > configuration.mu2pt[div] and categoryTuple[4] > configuration.jet1pt[div] and categoryTuple[5] > configuration.jet2pt[div] and categoryTuple[8]>0 
 # category 2: 2 muons + 2 jets + 1 Tight btag + METSIG 
  elif (category%4)==2:
    return isInCategoryChannel(1, categoryTuple) and categoryTuple[10]< configuration.MetSig[div]

 # category 3: 2 muons + 2 jets + 1 Tight btag + METSIG + hMass
  elif (category%4)==3:
    cat1 = isInCategoryChannel(2, categoryTuple) and categoryTuple[15]< configuration.hMass[div]
    if (configuration.blindingOpt == 0):
      return cat1
    elif (configuration.blindingOpt == 1):
      if(configuration.isRealData and cat1):
        return False
      if(not configuration.isRealData):
        return cat1 

 # category 4: 2 muons + 2 jets + 1 Tight btag + METSIG + hMass + diffM
  elif (category%4)==0:
    return isInCategoryChannel(3, categoryTuple) and categoryTuple[14]< configuration.diffM[div - 1] 


def eventCategory(event,btagging="CSV", WP=["M","L"], ZjetFilter="none"):
  if event.object().event().eventAuxiliary().isRealData():
    configuration.JERfactor = 0
    configuration.JESfactor = 0
    configuration.isRealData = True   
  else: # Is it data? useful for blinding
    configuration.isRealData = False   
  return eventCategoryChannel(event, muChannel=configuration.muChannel, btagging=btagging, WP=WP, ZjetFilter=ZjetFilter)
  
def eventCategoryChannel(event, muChannel=True, btagging="CSV", WP=["M","L"], ZjetFilter="none"):
  """Check analysis requirements for various steps."""
  # first of all: ZjetFilter. If failed, we don't even evaluate the rest of the vector and we return the special -1 value.
  if not ZjetFilter=="none":
    if MonteCarloSelection.isRecoZbbEvent(event) and not ('2b' in ZjetFilter): return [-1]
    if (MonteCarloSelection.isRecoZbEvent(event) and not MonteCarloSelection.isRecoZbbEvent(event)) and not ('1b' in ZjetFilter): return [-1]
    if (not MonteCarloSelection.isRecoZbbEvent(event) and not MonteCarloSelection.isRecoZbEvent(event)) and not ('0b' in ZjetFilter): return [-1]
  output = []
  # find the best Z candidate, and make sure it is of the proper type.
  bestDiLeptcandidate = event.bestHambDiMuCandidate
  goodJets = event.goodJets_all
  nlept = 0
  higgs = ROOT.TLorentzVector(0,0,0,0)
  mass = -1  
  mbb = -1
  # output[0]: Trigger
  checkTrigger = event.object().event().eventAuxiliary().isRealData()
#  if checkTrigger==False or (event.isMuTriggerOK and muChannel and not eleChannel) or (event.isEleTriggerOK and eleChannel and not muChannel) or (event.isINCTriggerOK and eleChannel and muChannel):
  if checkTrigger==False or event.isHambDiMuTriggerOK :
    output.append(1)  
  else:
    output.append(0)      
  # output[1]: leading muon pT, default -1
  # output[2]: sub-leading muon pT, default -1  
  # output[3]: dimuon mass, default -1  
  if bestDiLeptcandidate is None:
    output.append(-1)
    output.append(-1) 
    output.append(-1) 
  else:
    nDilep = len(bestDiLeptcandidate) 
    for i in range(0,nDilep) :
      if bestDiLeptcandidate[i] is not None:
        nlept += 1    
    lept1=bestDiLeptcandidate[0]
    lept2=bestDiLeptcandidate[1] 
    l1 = ROOT.TLorentzVector(lept1.px(),lept1.py(),lept1.pz(),lept1.energy())
    l2 = ROOT.TLorentzVector(lept2.px(),lept2.py(),lept2.pz(),lept2.energy())
    mass=(l1+l2).M()	
    higgs = l1+l2
   
    if lept1.isMuon() and lept2.isMuon() and nlept==2:
      #mumu channel only filled for muChannel=True
      if muChannel:
        output.append(lept1.pt())
        output.append(lept2.pt())
        output.append(mass)
      else: 
        output.append(-1)
        output.append(-1)
        output.append(-1)  
  # output[4]: leading jet  pT, default -1
  # output[5]: sub-leading jet pT, default -1  
  # output[6]: number of jets, default 0  
  # output[7]: number of HE jets, default 0, Medium
  # output[8]: number of HP jets, default 0, Tight  
  nJets = 0
  nBjetsHE = 0
  nBjetsHP = 0
  jetlist = []
  for index,jet in enumerate(event.jets):
    if goodJets[index]:
      jetlist.append(jet.pt())
      nJets += 1
      HE = isBJet(jet,WP[1],btagging)#Loose
      HP = isBJet(jet,WP[0],btagging)#Medium
      if HE: nBjetsHE += 1
      if HP: nBjetsHP += 1
  jetlist.sort(reverse=True)
  if len(jetlist) >= 2:
    output.append(jetlist[0])
    output.append(jetlist[1])
  else:
    output.append(-1)
    output.append(-1)
  output.append(nJets)
  output.append(nBjetsHE)
  output.append(nBjetsHP)
  # output[9] and [10] : MET and MET Significance
  MetToCutOn=getMet(event = event,type = configuration.MetType)
  output.append(isMetLowerThan(met = MetToCutOn,cut = configuration.MetCut))
  #output.append(isMetSigLowerThan(met = MetToCutOn,cut = configuration.MetSigCut))
  metSig = MetToCutOn.significance();
  if MetToCutOn.getSignificanceMatrix()(0,0)<1e10 and MetToCutOn.getSignificanceMatrix()(1,1)<1e10 :
      output.append(metSig)
  else:
      output.append(9999)
  
  # output[11] : bb DR
  # output[12] : bb SVDR
  # output[13]: bb invariant mass, default value: -1
  dijet = event.dijet_muChannel
  if dijet[0] is None or dijet[1] is None: 
    output.append(-1)
    output.append(-1)
    output.append(-1)
  else:
    b1 = ROOT.TLorentzVector(dijet[0].px(),dijet[0].py(),dijet[0].pz(),dijet[0].energy())
    b2 = ROOT.TLorentzVector(dijet[1].px(),dijet[1].py(),dijet[1].pz(),dijet[1].energy())
    higgs = higgs + b1 + b2  
    output.append(b1.DeltaR(b2))
    if dijet[0].tagInfoSecondaryVertex("secondaryVertex").nVertices()>0 and dijet[1].tagInfoSecondaryVertex("secondaryVertex").nVertices()>0:
      b1SVvec = dijet[0].tagInfoSecondaryVertex("secondaryVertex").flightDirection(0)
      b1SV = ROOT.TVector3(b1SVvec.x(),b1SVvec.y(),b1SVvec.z())
      b2SVvec = dijet[1].tagInfoSecondaryVertex("secondaryVertex").flightDirection(0)
      b2SV = ROOT.TVector3(b2SVvec.x(),b2SVvec.y(),b2SVvec.z())
      output.append(b1SV.DeltaR(b2SV))
    else:
      output.append(-1)
    mbb = (b1+b2).M()
    output.append(mbb)


  # output[14]: "mbb - mll", default value: -999
  # output[15]: "Higgs candidate mass - mH: 0"
  if (mbb != -1) and (mass != -1):
    output.append(abs(mbb - mass))
    output.append(abs(higgs.M()-configuration.mH))
  else:
    output.append(-999)
    output.append(0)
  #print "The length of CategoryChannel is "
  #print len(output)
  # return the list of results
  

  
  return output


