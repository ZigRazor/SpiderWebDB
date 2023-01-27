#include "DatabaseInstance.h"

#include <sys/stat.h>
#include <fstream>
#include <filesystem>
#include <sstream>

namespace SPIDERWEBDB
{

    DatabaseInstance::DatabaseInstance() {}

    DatabaseInstance::DatabaseInstance(const std::string& dbName)
    {
        m_name = dbName;
    }

    DatabaseInstance::~DatabaseInstance() {}

    const std::string_view DatabaseInstance::getName() const
    {
        return m_name;
    }

    std::ostream &operator<<(std::ostream &os, const DatabaseInstance &dbi)
    {
        os << dbi.toString();
        return os;
    }

}