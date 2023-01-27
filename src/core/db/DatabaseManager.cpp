#include "DatabaseManager.h"
#include "DatabaseInstanceFactory.h"

namespace SPIDERWEBDB
{

    DatabaseManager::DatabaseManager() {}
    DatabaseManager::~DatabaseManager() {}

    void DatabaseManager::createNewDatabaseInstance(const std::string &dbName)
    {
        if (m_databaseMap.find(dbName) == m_databaseMap.end())
        {
            m_databaseMap[dbName] = DatabaseInstanceFactory::createDatabaseInstance(dbName, DatabaseInstanceType::IN_MEMORY);
        }
    }

    void DatabaseManager::removeDatabaseInstance(const std::string &dbName)
    {
        if (m_databaseMap.find(dbName) != m_databaseMap.end())
        {
            m_databaseMap.erase(m_databaseMap.find(dbName));
        }
    }

    std::shared_ptr<DatabaseInstance> DatabaseManager::getDatabaseInstance(const std::string &dbName) const
    {
        if (m_databaseMap.find(dbName) != m_databaseMap.end())
        {
            return m_databaseMap.at(dbName);
        }
        return nullptr;
    }

}