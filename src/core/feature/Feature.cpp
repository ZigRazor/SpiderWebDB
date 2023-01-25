#include "Feature.h"

namespace SPIDERWEBDB {
    
    Feature::Feature(){}
    
    Feature::~Feature(){}

    const std::string_view Feature::getName() const{
        return m_name;
    }

}