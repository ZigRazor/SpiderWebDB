#include "InMemoryDatabaseInstance.h"

#include <sys/stat.h>
#include <fstream>
#include <filesystem>
#include <sstream>

namespace SPIDERWEBDB
{

    InMemoryDatabaseInstance::InMemoryDatabaseInstance() : DatabaseInstance() {}

    InMemoryDatabaseInstance::InMemoryDatabaseInstance(std::string dbName): DatabaseInstance(dbName){}

    InMemoryDatabaseInstance::~InMemoryDatabaseInstance() {}

    void InMemoryDatabaseInstance::addRelations(std::shared_ptr<RelationsList> relations)
    {
        m_relationsMap.addRelations(relations);
    }

    void InMemoryDatabaseInstance::addRelations(const RelationsList &relations)
    {
        m_relationsMap.addRelations(relations);
    }

    void InMemoryDatabaseInstance::addRelation(std::shared_ptr<Relation> relation)
    {
        m_relationsMap.addRelation(relation);
    }

    void InMemoryDatabaseInstance::addRelation(const Relation &relation)
    {
        m_relationsMap.addRelation(relation);
    }

    void InMemoryDatabaseInstance::removeRelations(std::shared_ptr<RelationsList> relations)
    {
        m_relationsMap.removeRelations(relations);
    }

    void InMemoryDatabaseInstance::removeRelations(const RelationsList &relations)
    {
        m_relationsMap.removeRelations(relations);
    }

    void InMemoryDatabaseInstance::removeRelations(const std::string &relationsName)
    {
        m_relationsMap.removeRelations(relationsName);
    }

    void InMemoryDatabaseInstance::removeRelation(std::shared_ptr<Relation> relation)
    {
        m_relationsMap.removeRelation(relation);
    }

    void InMemoryDatabaseInstance::removeRelation(const Relation &relation)
    {
        m_relationsMap.removeRelation(relation);
    }

    int InMemoryDatabaseInstance::writeToFile() const
    {

        auto dbTofile = [&]()
        {
            for (auto relations : m_relationsMap.getRelationsMap())
            {
                std::ofstream relationsFile(std::string(getName()) + "/" + "relations_" + std::string(relations.second->getRelationsName()) + ".csv");
                for (auto relation : relations.second->getRelations())
                {
                    auto nodes = relation->getNodes();
                    relationsFile << *nodes.first << "," << *nodes.second << std::endl;
                }
                relationsFile.close();
            }
        };

        struct stat sb;
        if (stat(std::string(getName()).c_str(), &sb) != 0)
        {
            int check;

            check = mkdir(std::string(getName()).c_str(), 0777);

            // check if directory is created or not
            if (!check)
            {
                // printf("Directory created\n");
                dbTofile();
            }
            else
            {
                // printf("Unable to create directory\n");
                //  exit(1);
                return -1;
            }
        }
        else
        {
            dbTofile();
        }
        return 0;
    }

    int InMemoryDatabaseInstance::readFromFile()
    {
        auto dbFromfile = [&]()
        {
            for (const auto &entry : std::filesystem::directory_iterator(getName()))
            {
                std::string relationsSubStr = "relations_";
                if (entry.path().filename().string().rfind(relationsSubStr, 0) == 0)
                {
                    std::string relationsName = entry.path().filename().string().erase(0,relationsSubStr.length());
                    std::string line;
                    std::ifstream relationsFile(entry.path().string());
                    while (std::getline(relationsFile, line))
                    {
                        std::stringstream str(line);
                        std::string node_1;
                        std::string node_2;
                        std::getline(str, node_1, ',');
                        std::getline(str, node_2, ',');
                        Relation r(relationsName,std::make_shared<Node>(node_1), std::make_shared<Node>(node_2));
                        this->addRelation(r);
                    }
                }
            }
        };

        struct stat sb;
        if (stat(std::string(getName()).c_str(), &sb) != 0)
        {
            dbFromfile();
        }else{ // Database does not exist
            return -1;
        }
        return 0;
    }

    std::string InMemoryDatabaseInstance::toString() const
    {
        std::stringstream ss;
        ss << "Database Instance: " << std::string(getName()) << std::endl
           << m_relationsMap;
        return ss.str();
    }

}