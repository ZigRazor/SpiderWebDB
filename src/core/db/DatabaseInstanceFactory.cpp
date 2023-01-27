#include "DatabaseInstanceFactory.h"

namespace SPIDERWEBDB {

    std::shared_ptr<DatabaseInstance> DatabaseInstanceFactory::createDatabaseInstance(const std::string& dbName, DatabaseInstanceType dbType){
        switch(dbType){
            case DatabaseInstanceType::IN_MEMORY :
                return std::shared_ptr<DatabaseInstance>(new InMemoryDatabaseInstance(dbName));
                break;
            
            case DatabaseInstanceType::ON_DISK :
                return std::shared_ptr<DatabaseInstance>(new OnDiskDatabaseInstance(dbName));
                break;

            default :
                return std::shared_ptr<DatabaseInstance>(nullptr);
        }
    }

}