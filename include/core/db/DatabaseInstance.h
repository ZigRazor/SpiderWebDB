#pragma once

#include <string>
#include "DatabaseInstanceProperties.h"
#include "RelationsMap.h"

namespace SPIDERWEBDB {
    
    class DatabaseInstance {
        public:

            
            virtual ~DatabaseInstance();

            virtual const std::string_view getName() const; 

            virtual void setProperties(const DatabaseInstanceProperties& properties);

            virtual void addRelations(std::shared_ptr<RelationsList> relations) = 0;
            virtual void addRelations(const RelationsList& relations) = 0;
            virtual void addRelation(std::shared_ptr<Relation> relation) = 0;
            virtual void addRelation(const Relation& relation) = 0;
            virtual void removeRelations(std::shared_ptr<RelationsList> relations) = 0;
            virtual void removeRelations(const RelationsList& relations) = 0;
            virtual void removeRelations(const std::string& relationsName) = 0;
            virtual void removeRelation(std::shared_ptr<Relation> relation) = 0;
            virtual void removeRelation(const Relation& relation) = 0;

            virtual int writeToFile() const = 0;
            virtual int readFromFile() = 0;

            virtual std::string toString() const = 0;

            friend std::ostream& operator<<(std::ostream& os, const DatabaseInstance &dbi);

        protected:

            RelationsMap m_relationsMap;
            DatabaseInstanceProperties m_properties;

            DatabaseInstance();
            DatabaseInstance(const std::string& dbName);

        private:            

            std::string m_name;

    };
}