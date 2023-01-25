#include "FeaturedNode.h"

namespace SPIDERWEBDB {
    
    FeaturedNode::FeaturedNode() : Node(){}
    FeaturedNode::~FeaturedNode(){}

    const std::set<std::shared_ptr<Feature>>& FeaturedNode::getFeaturesSet() const{
        return m_featuresSet;
    }

    void FeaturedNode::addFeature(std::shared_ptr<Feature> feature){
        m_featuresSet.insert(feature);
    }

    void FeaturedNode::removeFeature(std::shared_ptr<Feature> feature){
        if(m_featuresSet.find(feature) != m_featuresSet.end()){
            m_featuresSet.erase(m_featuresSet.find(feature));
        }
    }

}