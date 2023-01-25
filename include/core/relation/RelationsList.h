#pragma once

#include "Relation.h"

#include <unordered_set>

namespace SPIDERWEBDB {
    
    class RelationsList {
        public:

            RelationsList();
            virtual ~RelationsList();

            const std::string_view getRelationsName() const;

            const std::unordered_set<std::shared_ptr<Relation>>& getRelations() const;

            size_t relationsSize() const;

            void addRelation(std::shared_ptr<Relation> relation);
            void addRelation(const Relation& relation);
            void removeRelation(std::shared_ptr<Relation> relation);
            void removeRelation(const Relation& relation);

            std::string toString() const;

            friend std::ostream& operator<<(std::ostream& os, const RelationsList &r);

        private:
            std::unordered_set<std::shared_ptr<Relation>> m_relations;

    };
}