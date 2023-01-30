#pragma once

#pragma once

#include <string>

namespace SPIDERWEBDB
{

    static const std::string &ALLOW_DUPLICATES = "ALLOW_DUPLICATES";

    class DatabaseInstanceProperties
    {
    public:
        DatabaseInstanceProperties();
        virtual ~DatabaseInstanceProperties();

        bool getAllowDuplicates() const;
        void setAllowDuplicates(bool allowDuplicates);

        int readProperties(const std::string &propertiesPath);
        int writeProperties(const std::string &propertiesPath) const;

    private:
        // Properties
        bool m_allowDuplicates = true;
    };
}
