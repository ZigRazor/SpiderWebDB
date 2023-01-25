#pragma once

#include <string>

namespace SPIDERWEBDB {
    
    class Feature {
        public:

            Feature();
            virtual ~Feature();

            const std::string_view getName() const; 

            //Function to implement when derived
            virtual void toStringFeature() const = 0;
            virtual void fromStringFeature() = 0;

        private:
            std::string m_name;

    };
}