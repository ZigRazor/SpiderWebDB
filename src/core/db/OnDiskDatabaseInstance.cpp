#include "OnDiskDatabaseInstance.h"

#include <sys/stat.h>
#include <fstream>
#include <filesystem>
#include <sstream>
#include <iostream>

#include "FileManipulation.h"
#include "Constants.hpp"

namespace SPIDERWEBDB
{

    OnDiskDatabaseInstance::OnDiskDatabaseInstance() : DatabaseInstance() {}

    OnDiskDatabaseInstance::OnDiskDatabaseInstance(const std::string &dbName) : DatabaseInstance(dbName)
    {
        // Create DB Directory if not exist
        struct stat sb;
        if (stat(dbName.c_str(), &sb) != 0)
        {
            // if is the first time I create DB I create Dir
            mkdir(dbName.c_str(), 0777);
        }
        else
        {
            // else I read DB Properties
            m_properties.readProperties(dbName);
        }
    }

    OnDiskDatabaseInstance::~OnDiskDatabaseInstance() {}

    void OnDiskDatabaseInstance::setProperties(const DatabaseInstanceProperties &properties)
    {
        DatabaseInstance::setProperties(properties);
        m_properties.writeProperties(std::string(getName()));
    }

    void OnDiskDatabaseInstance::addRelations(std::shared_ptr<RelationsList> relations)
    {
        writeRelationsToFile(*relations);
    }

    void OnDiskDatabaseInstance::addRelations(const RelationsList &relations)
    {
        writeRelationsToFile(relations);
    }

    void OnDiskDatabaseInstance::addRelation(std::shared_ptr<Relation> relation)
    {
        writeRelationToFile(*relation);
    }

    void OnDiskDatabaseInstance::addRelation(const Relation &relation)
    {
        writeRelationToFile(relation);
    }

    void OnDiskDatabaseInstance::removeRelations(std::shared_ptr<RelationsList> relations)
    {
        removeRelations(*relations);
    }

    void OnDiskDatabaseInstance::removeRelations(const RelationsList &relations)
    {
        for(const auto &it : relations.getRelations()){
            removeRelation(*it);
        }
    }

    void OnDiskDatabaseInstance::removeRelations(const std::string &relationsName)
    {
        std::string relationsFileName = std::string(CONSTANTS::RELATIONS_PREFIX_STR) + std::string(relationsName);
        FileManipulation::removeFile(std::string(getName()) + CONSTANTS::SLASH_CHAR + relationsFileName + std::string(CONSTANTS::CSVEXT_STR));
    }

    void OnDiskDatabaseInstance::removeRelation(std::shared_ptr<Relation> relation)
    {
        removeRelation(*relation);
    }

    void OnDiskDatabaseInstance::removeRelation(const Relation &relation)
    {
        auto relationsList = readRelationsFromFile(std::string(relation.getName()));
        relationsList->removeRelation(relation);
        //Maybe can be optimized ( rewrite only if the relation is removed)
        if(relationsList->getRelations().size() != 0){
            writeRelationsToFile(*relationsList);
        }else{
            //No element in list, remove file
            std::string relationsFileName = std::string(CONSTANTS::RELATIONS_PREFIX_STR) + std::string(relation.getName());
            FileManipulation::removeFile(std::string(getName()) + CONSTANTS::SLASH_CHAR + relationsFileName + std::string(CONSTANTS::CSVEXT_STR));
        }

    }

    int OnDiskDatabaseInstance::writeToFile() const
    {
        // TODO
        return 0;
    }

    int OnDiskDatabaseInstance::readFromFile()
    {
        // TODO
        return 0;
    }

    std::string OnDiskDatabaseInstance::toString() const
    {
        // TODO
        std::stringstream ss;
        return ss.str();
    }

    int OnDiskDatabaseInstance::writeRelationToFile(const Relation &relation) const
    {
        std::ofstream relationsFile;
        std::string relationsFileName = std::string(CONSTANTS::RELATIONS_PREFIX_STR) + std::string(relation.getName());
        for (const auto &entry : std::filesystem::directory_iterator(getName()))
        {

            if (entry.path().filename().string() == relationsFileName)
            {
                relationsFile.open(entry.path().string(), std::ios_base::app);
            }
        }
        if (!relationsFile.is_open())
        {
            relationsFile.open(std::string(getName()) + CONSTANTS::SLASH_CHAR + relationsFileName + std::string(CONSTANTS::CSVEXT_STR));
        }

        auto nodes = relation.getNodes();
        relationsFile << *nodes.first << CONSTANTS::SLASH_CHAR << *nodes.second << std::endl;

        relationsFile.close();
        return 0;
    }

    int OnDiskDatabaseInstance::writeRelationsToFile(const RelationsList &relations) const
    {
        std::ofstream relationsFile;
        std::string relationsFileName = std::string(CONSTANTS::RELATIONS_PREFIX_STR) + std::string(relations.getRelationsName());
        for (const auto &entry : std::filesystem::directory_iterator(getName()))
        {

            if (entry.path().filename().string() == relationsFileName)
            {
                relationsFile.open(entry.path().string(), std::ios_base::app);
            }
        }
        if (!relationsFile.is_open())
        {
            relationsFile.open(std::string(getName()) + CONSTANTS::SLASH_CHAR + relationsFileName + std::string(CONSTANTS::CSVEXT_STR));
        }
        for (auto relation : relations.getRelations())
        {
            auto nodes = relation->getNodes();
            relationsFile << *nodes.first << CONSTANTS::COMMA_CHAR << *nodes.second << std::endl;
        }
        relationsFile.close();

        return 0;
    }

    int OnDiskDatabaseInstance::openRelationFile(const std::string &relationsName, std::fstream &relationFile) const
    {
        std::string relationsFileName = std::string(CONSTANTS::RELATIONS_PREFIX_STR) + std::string(relationsName);
        for (const auto &entry : std::filesystem::directory_iterator(getName()))
        {

            if (entry.path().filename().string() == relationsFileName)
            {
                relationFile.open(entry.path().string());
            }
        }
        if (!relationFile.is_open())
        {
            relationFile.open(std::string(getName()) + CONSTANTS::SLASH_CHAR + relationsFileName + std::string(CONSTANTS::CSVEXT_STR));
        }
        return 0;
    }

    int OnDiskDatabaseInstance::closeRelationFile(std::fstream &relationFile) const
    {
        relationFile.close();
        return 0;
    }

    std::shared_ptr<RelationsList> OnDiskDatabaseInstance::readRelationsFromFile(const std::string &relationsName) const
    {
        std::shared_ptr<RelationsList> result = std::make_shared<RelationsList>();
        std::fstream fileStream;
        openRelationFile(relationsName, fileStream);
        if (fileStream.is_open())
        {
            std::string line;
            while (std::getline(fileStream, line))
            {
                result->addRelation(Relation(relationsName, line));
            }
            closeRelationFile(fileStream);
        }
        return result;
    }

}
