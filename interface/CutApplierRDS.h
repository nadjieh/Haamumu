/* 
 * File:   CutApplierRDS.h
 * Author: nadjieh
 *
 * Created on November 25, 2014, 4:21 PM
 */

#ifndef CUTAPPLIERRDS_H
#define	CUTAPPLIERRDS_H
#include "RDS.h"
#include "RDSData.h"
#include <iostream>
using namespace std;

/*
 * The cut ordering:
 * mu1pt
 * mu2pt
 * jet1pt
 * jet2pt
 * eventSelectionMETsignificance_hamb
 * eventSelectiondiffMassaa
 * eventSelectionhMass
 */
bool isSelected(RDSData * rds, std::vector<double> cutValues, bool blind = false) {
    bool ret = true;
    if (cutValues.size() < 7) {
        cout << ">>>>>> WARNING: You gave me bad cut sequence, nothing will be applied then!!!" << endl;
    }
    //    if (rds->jetmetjet1CSVdisc > rds->jetmetjet2CSVdisc) {
    //        if (!(rds->jetmetjet1CSVdisc > 0.898))
    //            return false;
    //    } else {
    //        if (!(rds->jetmetjet2CSVdisc > 0.898))
    //            return false;
    //    }
    ret = (ret && !(rds->eventSelectionmu1pt < cutValues[0]));
    ret = (ret && !(rds->eventSelectionmu2pt < cutValues[1]));
    ret = (ret && !(rds->jetmetjet1pt < cutValues[2]));
    ret = (ret && !(rds->jetmetjet2pt < cutValues[3]));
    ret = (ret && !(rds->eventSelectionMETsignificance_hamb > cutValues[4]));
    ret = (ret && !(fabs(rds->eventSelectionhMass - 125) < cutValues[5]));
    ret = (ret && !(fabs(rds->eventSelectionhMass - 125) > cutValues[6]));
	if(blind){
       	ret = (ret && !(fabs(rds->eventSelectionamassMu-30)< 1 || fabs(rds->eventSelectionamassMu-40)< 1 || fabs(rds->eventSelectionamassMu-50)< 1 || fabs(rds->eventSelectionamassMu-60)< 1 ));
    }    
    //ret = (ret && (rds->eventSelectionamassMu > 20 && rds->eventSelectionamassMu < 70));
    return ret;
}

bool isSelected2(RDSData * rds, std::vector<double> cutValues, bool blind = false) {
    bool ret = true;
    if (cutValues.size() < 7) {
        cout << ">>>>>> WARNING: You gave me bad cut sequence, nothing will be applied then!!!" << endl;
    }
    ret = (ret && !(rds->eventSelectionmu1pt < cutValues[0]));
    ret = (ret && !(rds->eventSelectionmu2pt < cutValues[1]));
    ret = (ret && !(rds->jetmetjet1pt < cutValues[2]));
    ret = (ret && !(rds->jetmetjet2pt < cutValues[3]));
    ret = (ret && !(rds->eventSelectionMETsignificance_hamb > cutValues[4]));
    ret = (ret && !(rds->eventSelectionMETsignificance_hamb < cutValues[5]));
    ret = (ret && !(fabs(rds->eventSelectionhMass - 125) < cutValues[6]));
    ret = (ret && !(fabs(rds->eventSelectionhMass - 125) > cutValues[7]));

    ret = (ret && (rds->eventSelectionamassMu > 20 && rds->eventSelectionamassMu < 70));
    if(blind){
       	ret = (ret && !(fabs(rds->eventSelectionamassMu-30)< 1 || fabs(rds->eventSelectionamassMu-40)< 1 || fabs(rds->eventSelectionamassMu-50)< 1 || fabs(rds->eventSelectionamassMu-60)< 1 ));
    }
    return ret;
}

#endif	/* CUTAPPLIERRDS_H */
