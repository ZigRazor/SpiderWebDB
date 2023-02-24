#include "RelationsList.h"
#include <iostream>

namespace SPIDERWEBDB {

    RelationsList::RelationsList(){}
    RelationsList::~RelationsList(){}

    const std::string_view RelationsList::getRelationsName() const{
        if(!m_relations.empty()){
            return (*m_relations.begin())->getName();
        }
        return "";
    }

    const std::unordered_set<std::shared_ptr<Relation>>& RelationsList::getRelations() const {
        return m_relations;
    }

    size_t RelationsList::relationsSize() const{
        return m_relations.size();
    }

    void RelationsList::addRelation(std::shared_ptr<Relation> relation){
        if(m_relations.empty() || getRelationsName() == relation->getName()){
            m_relations.insert(relation);
        }
    }

    void RelationsList::addRelation(const Relation& relation){
        if(m_relations.empty() || getRelationsName() == relation.getName()){
            m_relations.insert(std::make_shared<Relation>(relation));
        }
    }

    void RelationsList::removeRelation(std::shared_ptr<Relation> relation){
        removeRelation(*relation);
    }

    void RelationsList::removeRelation(const Relation& relation){
        for(auto it : m_relations){
            if( *it == relation){
                m_relations.erase(it);
                break;
            }
        }
    }

    std::string RelationsList::toString() const{
        std::stringstream ss;
        for(auto it : m_relations){
            ss << it->toString() << std::endl;
        }
        return ss.str();
    }

    std::ostream& operator<<(std::ostream& os, const RelationsList &r){
        os << r.toString();
        return os;
    }



}