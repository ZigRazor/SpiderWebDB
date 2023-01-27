#pragma once

#include "DatabaseInstance.h"

namespace SPIDERWEBDB {
    
    class InMemoryDatabaseInstance : public DatabaseInstance{
        public:

            
            virtual ~InMemoryDatabaseInstance();

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

            InMemoryDatabaseInstance();
            InMemoryDatabaseInstance(const std::string& dbName);
    };
}