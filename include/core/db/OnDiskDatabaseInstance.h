#pragma once

#include "DatabaseInstance.h"

namespace SPIDERWEBDB {
    
    class OnDiskDatabaseInstance : public DatabaseInstance{
        public:

            
            virtual ~OnDiskDatabaseInstance();

            void addRelations(std::shared_ptr<RelationsList> relations) override;
            void addRelations(const RelationsList& relations) override;
            void addRelation(std::shared_ptr<Relation> relation)  ;
            void addRelation(const Relation& relation) override;
            void removeRelations(std::shared_ptr<RelationsList> relations) override;
            void removeRelations(const RelationsList& relations) override;
            void removeRelations(const std::string& relationsName) override;
            void removeRelation(std::shared_ptr<Relation> relation) override;
            void removeRelation(const Relation& relation) override;

            int writeToFile() const override;
            int readFromFile() override;

            std::string toString() const override;

            friend class DatabaseInstanceFactory;

        private:

            OnDiskDatabaseInstance();
            OnDiskDatabaseInstance(std::string dbName);
    };
}