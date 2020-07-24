#ifndef Navagation_h
#define Navagation_h

//#include "FWCore/DataHandle.h"
//#include "podio/CollectionBase.h"
#include "edm4hep/MCRecoTrackerAssociationCollection.h"
#include "edm4hep/TrackerHitCollection.h"
#include <map>

class Navagation{
 public:
  static Navagation* Instance();

  Navagation();
  ~Navagation();
  
  void Initialize();
  //void AddDataHandle(DataHandle* hdl){if(hdl)m_hdlVec.push_back(hdl);};
  void AddTrackerHitCollection(const edm4hep::TrackerHitCollection* col){m_hitColVec.push_back(col);};
  void AddTrackerAssociationCollection(const edm4hep::MCRecoTrackerAssociationCollection* col){m_assColVec.push_back(col);};

  edm4hep::TrackerHit* GetTrackerHit(const edm4hep::ObjectID& id, bool delete_by_caller=true);
  std::vector<edm4hep::ConstSimTrackerHit> GetRelatedTrackerHit(const edm4hep::ObjectID& id);
  std::vector<edm4hep::ConstSimTrackerHit> GetRelatedTrackerHit(const edm4hep::TrackerHit& hit);
  
  //static Navagation* m_fNavagation;
 private:
  static Navagation* m_fNavagation;
  //DataHandle<edm4hep::MCRecoTrackerAssociationCollection> _inHitAssColHdl{"FTDStripTrackerHitsAssociation", Gaudi::DataHandle::Reader, this};
  std::vector<const edm4hep::TrackerHitCollection*> m_hitColVec;
  std::vector<const edm4hep::MCRecoTrackerAssociationCollection*> m_assColVec;
  std::map<int, edm4hep::TrackerHit*> m_trkHits;
};
#endif 
