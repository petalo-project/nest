#include "NESTStackingAction.hh"

NESTStackingAction::NESTStackingAction(){}
NESTStackingAction::~NESTStackingAction(){}

NESTStackingAction* NESTStackingAction::theStackingAction = 0;
G4StackManager* NESTStackingAction::savedManager=0;

G4ClassificationOfNewTrack NESTStackingAction::ClassifyNewTrack(const G4Track* track) 
{
    savedManager=stackManager;
//  return Analysis::GetInstance()->ClassifyNewTrack(track);
}

bool NESTStackingAction::isUrgentEmpty(){
    return savedManager->GetNUrgentTrack()==0;
}
void NESTStackingAction::NewStage() {
//    NESTAnalysis::GetInstance()->NewStage(stackManager);

    
}