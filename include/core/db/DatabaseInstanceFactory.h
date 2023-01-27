#pragma once

#include "DatabaseInstanceType.h"
#include "InMemoryDatabaseInstance.h"
#include "OnDiskDatabaseInstance.h"


namespace SPIDERWEBDB {
    
    class DatabaseInstanceFactory {
        public:
            static std::shared_ptr<DatabaseInstance> createDatabaseInstance(const std::string& dbName, DatabaseInstanceType dbType);
    };
}