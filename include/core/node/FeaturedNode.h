#pragma once

#include <set>
#include <memory>

#include "Node.h"
#include "Feature.h"

namespace SPIDERWEBDB {
    
    class FeaturedNode : public Node {
        public:

            FeaturedNode();
            virtual ~FeaturedNode();

            const std::set<std::shared_ptr<Feature>>& getFeaturesSet() const;

            void addFeature(std::shared_ptr<Feature> feature);
            void removeFeature(std::shared_ptr<Feature> feature);

        private:
            std::set<std::shared_ptr<Feature>> m_featuresSet;

    };
}