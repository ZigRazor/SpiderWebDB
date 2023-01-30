#include "DatabaseInstanceProperties.h"

#include <sys/stat.h>
#include <fstream>
#include <filesystem>

namespace SPIDERWEBDB
{

    DatabaseInstanceProperties::DatabaseInstanceProperties() {}

    DatabaseInstanceProperties::~DatabaseInstanceProperties() {}

    bool DatabaseInstanceProperties::getAllowDuplicates() const
    {
        return m_allowDuplicates;
    }

    void DatabaseInstanceProperties::setAllowDuplicates(bool allowDuplicates)
    {
        m_allowDuplicates = allowDuplicates;
    }

    int DatabaseInstanceProperties::readProperties(const std::string &propertiesPath)
    {
        struct stat sb;
        if (stat(propertiesPath.c_str(), &sb) == 0)
        {
            std::ifstream propertiesFile(propertiesPath + "/" + "properties.swdb");
            std::string line;
            while (std::getline(propertiesFile, line))
            {
                std::stringstream str(line);
                std::string propertiesName;
                std::string propertiesValue;
                std::getline(str, propertiesName, ',');
                std::getline(str, propertiesValue, ',');

                if (propertiesName == ALLOW_DUPLICATES)
                {
                    m_allowDuplicates = (propertiesValue == "true");
                }
                else
                {
                    // not know property
                }
            }
            return 0;
        }
        else
        {
            return -1;
        }
    }

    int DatabaseInstanceProperties::writeProperties(const std::string &propertiesPath) const
    {
        struct stat sb;
        if (stat(propertiesPath.c_str(), &sb) == 0)
        {
            std::ofstream propertiesFile(propertiesPath + "/" + "properties.swdb");
            propertiesFile << ALLOW_DUPLICATES << "," << (m_allowDuplicates ? "true" : "false") << std::endl;

            propertiesFile.close();
            return 0;
        }
        else
        {
            return -1;
        }
    }
}