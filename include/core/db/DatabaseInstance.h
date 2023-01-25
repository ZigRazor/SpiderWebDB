#pragma once

#include <string>
#include "RelationsMap.h"

namespace SPIDERWEBDB {
    
    class DatabaseInstance {
        public:

            
            virtual ~DatabaseInstance();

            const std::string_view getName() const; 

            void addRelations(std::shared_ptr<RelationsList> relations);
            void addRelations(const RelationsList& relations);
            void addRelation(std::shared_ptr<Relation> relation);
            void addRelation(const Relation& relation);
            void removeRelations(std::shared_ptr<RelationsList> relations);
            void removeRelations(const RelationsList& relations);
            void removeRelations(const std::string& relationsName);
            void removeRelation(std::shared_ptr<Relation> relation);
            void removeRelation(const Relation& relation);

            int writeToFile() const;
            int readFromFile();

            std::string toString() const;

            friend std::ostream& operator<<(std::ostream& os, const DatabaseInstance &dbi);

            friend class DatabaseManager;

        private:

            DatabaseInstance();
            DatabaseInstance(std::string dbName);

            std::string m_name;
            RelationsMap m_relationsMap;

    };
}