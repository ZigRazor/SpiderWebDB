#pragma once

#include <string>
#include "DatabaseInstance.h"
#include "DatabaseInstanceType.h"

namespace SPIDERWEBDB {
    
    class DatabaseManager {
        public:

            DatabaseManager();
            virtual ~DatabaseManager();

            void createNewDatabaseInstance(const std::string& dbName, DatabaseInstanceType dbType = DatabaseInstanceType::IN_MEMORY);
            void removeDatabaseInstance(const std::string& dbName);
            std::shared_ptr<DatabaseInstance> getDatabaseInstance(const std::string& dbName) const;


        private:
            std::unordered_map<std::string, std::shared_ptr<DatabaseInstance>> m_databaseMap;
    };
}