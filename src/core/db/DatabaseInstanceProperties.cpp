#include "DatabaseInstanceProperties.h"

#include <sys/stat.h>
#include <fstream>
#include <filesystem>
#include "Constants.hpp"

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
            std::ifstream propertiesFile(propertiesPath + CONSTANTS::SLASH_CHAR + std::string(CONSTANTS::PROPERTIES_FILENAME_STR));
            std::string line;
            while (std::getline(propertiesFile, line))
            {
                std::stringstream str(line);
                std::string propertiesName;
                std::string propertiesValue;
                std::getline(str, propertiesName, CONSTANTS::COMMA_CHAR);
                std::getline(str, propertiesValue, CONSTANTS::COMMA_CHAR);

                if (propertiesName == ALLOW_DUPLICATES)
                {
                    m_allowDuplicates = (propertiesValue == CONSTANTS::TRUE_STR);
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
            std::ofstream propertiesFile(propertiesPath + CONSTANTS::SLASH_CHAR + std::string(CONSTANTS::PROPERTIES_FILENAME_STR));
            propertiesFile << ALLOW_DUPLICATES << CONSTANTS::COMMA_CHAR << (m_allowDuplicates ? CONSTANTS::TRUE_STR : CONSTANTS::FALSE_STR) << std::endl;

            propertiesFile.close();
            return 0;
        }
        else
        {
            return -1;
        }
    }
}