#include "CheckUtils.h"

namespace SPIDERWEBDB
{

    bool CheckUtils::existRelationNameInRelationsMap(const RelationsMap &relationsMap, const std::string &relationName){
        return relationsMap.getRelationsMap().find(relationName) != relationsMap.getRelationsMap().end();
    }

    bool CheckUtils::existRelationInRelationsList(const RelationsList &relationsList, const Relation &relation)
    {
        for (auto relationIt : relationsList.getRelations())
        {
            if (*relationIt == relation)
            {
                return true;
            }
        }
        return false;
    }

}