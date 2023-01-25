#pragma once

#include "RelationsList.h"

#include <unordered_map>

namespace SPIDERWEBDB {
    
    class RelationsMap {
        public:

            RelationsMap();
            virtual ~RelationsMap();

            const std::unordered_map<std::string,std::shared_ptr<RelationsList>>& getRelationsMap() const;

            void addRelations(std::shared_ptr<RelationsList> relations);
            void addRelations(const RelationsList& relations);
            void addRelation(std::shared_ptr<Relation> relation);
            void addRelation(const Relation& relation);
            void removeRelations(std::shared_ptr<RelationsList> relations);
            void removeRelations(const RelationsList& relations);
            void removeRelations(const std::string& relationsName);
            void removeRelation(std::shared_ptr<Relation> relation);
            void removeRelation(const Relation& relation);

            std::string toString() const;
            
            friend std::ostream& operator<<(std::ostream& os, const RelationsMap &r);

        private:
            std::unordered_map<std::string,std::shared_ptr<RelationsList>> m_relationsMap;

    };
}