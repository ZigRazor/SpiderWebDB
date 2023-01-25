#include "RelationsMap.h"

namespace SPIDERWEBDB {

    RelationsMap::RelationsMap(){}
    RelationsMap::~RelationsMap(){}

    const std::unordered_map<std::string,std::shared_ptr<RelationsList>>& RelationsMap::getRelationsMap() const{
        return m_relationsMap;
    }

    void RelationsMap::addRelations(std::shared_ptr<RelationsList> relations){
        if(relations->getRelationsName() != ""){
            if(m_relationsMap.find(std::string(relations->getRelationsName())) == m_relationsMap.end()){ //Relations does not exist
                m_relationsMap[std::string(relations->getRelationsName())] = relations;
            }else{
                for( auto it : relations->getRelations()){ //Relations already exist add the elements that are not present
                    m_relationsMap.at(std::string(relations->getRelationsName()))->addRelation(it);
                }
            }
        }
    }

    void RelationsMap::addRelations(const RelationsList& relations){
        if(relations.getRelationsName() != ""){
            if(m_relationsMap.find(std::string(relations.getRelationsName())) == m_relationsMap.end()){ //Relations does not exist
                m_relationsMap[std::string(relations.getRelationsName())] = std::make_shared<RelationsList>(relations);
            }else{
                for( auto it : relations.getRelations()){ //Relations already exist add the elements that are not present
                    m_relationsMap.at(std::string(relations.getRelationsName()))->addRelation(it);
                }
            }
        }
    }

    void RelationsMap::addRelation(std::shared_ptr<Relation> relation){
        if(relation->getName() != ""){
            if(m_relationsMap.find(std::string(relation->getName())) == m_relationsMap.end()){ //Relations does not exist
                m_relationsMap[std::string(relation->getName())] = std::make_shared<RelationsList>();
            }
            m_relationsMap.at(std::string(relation->getName()))->addRelation(relation);
        }
    }
            
    void RelationsMap::addRelation(const Relation& relation){
        if(relation.getName() != ""){
            if(m_relationsMap.find(std::string(relation.getName())) == m_relationsMap.end()){ //Relations does not exist
                m_relationsMap[std::string(relation.getName())] = std::make_shared<RelationsList>();
            }
            m_relationsMap.at(std::string(relation.getName()))->addRelation(relation);
        }
    }
            
    void RelationsMap::removeRelations(std::shared_ptr<RelationsList> relations){
        if(m_relationsMap.find(std::string(relations->getRelationsName())) != m_relationsMap.end()){
            for( auto it : relations->getRelations()){
                m_relationsMap.at(std::string(relations->getRelationsName()))->removeRelation(it);                
            }
            if(m_relationsMap.at(std::string(relations->getRelationsName()))->relationsSize() == 0){ // if no elements in relations remove relations from map
                m_relationsMap.erase(m_relationsMap.find(std::string(relations->getRelationsName())));
            }
        }
    }

    void RelationsMap::removeRelations(const RelationsList& relations){
        if(m_relationsMap.find(std::string(relations.getRelationsName())) != m_relationsMap.end()){
            for( auto it : relations.getRelations()){
                m_relationsMap.at(std::string(relations.getRelationsName()))->removeRelation(it);                
            }
            if(m_relationsMap.at(std::string(relations.getRelationsName()))->relationsSize() == 0){ // if no elements in relations remove relations from map
                m_relationsMap.erase(m_relationsMap.find(std::string(relations.getRelationsName())));
            }
        }
    }

    void RelationsMap::removeRelations(const std::string& relationsName){
        if(m_relationsMap.find(relationsName) != m_relationsMap.end()){
            m_relationsMap.erase(m_relationsMap.find(relationsName));
        }
    }

    void RelationsMap::removeRelation(std::shared_ptr<Relation> relation){
        if(m_relationsMap.find(std::string(relation->getName())) != m_relationsMap.end()){
            m_relationsMap.at(std::string(relation->getName()))->removeRelation(relation);
        }
        if(m_relationsMap.at(std::string(relation->getName()))->relationsSize() == 0){ // if no elements in relations remove relations from map
            m_relationsMap.erase(m_relationsMap.find(std::string(relation->getName())));
        }
    }
    
    void RelationsMap::removeRelation(const Relation& relation){
        if(m_relationsMap.find(std::string(relation.getName())) != m_relationsMap.end()){
            m_relationsMap.at(std::string(relation.getName()))->removeRelation(relation);
        }
        if(m_relationsMap.at(std::string(relation.getName()))->relationsSize() == 0){ // if no elements in relations remove relations from map
            m_relationsMap.erase(m_relationsMap.find(std::string(relation.getName())));
        }
    }

    std::string RelationsMap::toString() const{
        std::stringstream ss;
        for(auto it : m_relationsMap){
            ss << it.second->toString() << std::endl;
        }
        return ss.str();
    }
            
    std::ostream& operator<<(std::ostream& os, const RelationsMap &r){
        os << r.toString();
        return os;
    }


}