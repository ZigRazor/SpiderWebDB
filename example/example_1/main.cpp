#include "DatabaseManager.h"
#include <iostream>

using namespace SPIDERWEBDB;

int main(){

    DatabaseInstanceProperties prop1;
    prop1.setAllowDuplicates(false);
    DatabaseManager dbMng;
    dbMng.createNewDatabaseInstance("MyDBInstance");
    auto db = dbMng.getDatabaseInstance("MyDBInstance");
    db->setProperties(prop1);
    std::cout << db->getName() << std::endl;

    auto n1 = std::make_shared<Node>("node_1");
    auto n2 = std::make_shared<Node>("node_2");

    Relation r1("link", n1, n2);
    Relation r2("link", n2, n1);
    Relation r3("from", n2, n1);

    std::cout << r1 << std::endl;

    RelationsList rl1;

    rl1.addRelation(r1);
    std::cout << rl1 << std::endl;
    rl1.addRelation(r2);
    std::cout << rl1 << std::endl;
    rl1.addRelation(r3);
    std::cout << rl1 << std::endl;

    db->addRelation(r1);
    std::cout << *db << std::endl;
    db->addRelation(r3);
    std::cout << *db << std::endl;
    db->addRelation(r2);
    std::cout << *db << std::endl;
    auto r4 = r2;
    db->addRelation(r4);
    std::cout << *db << std::endl;
    db->addRelation(r2);
    std::cout << *db << std::endl;
    
    db->writeToFile();

    DatabaseManager dbMng2;
    dbMng2.createNewDatabaseInstance("MyDBInstance");

    auto db2 = dbMng.getDatabaseInstance("MyDBInstance");

    db2->readFromFile();

    std::cout << *db2 << std::endl;

    DatabaseInstanceProperties prop2;
    prop2.setAllowDuplicates(false);

    dbMng.createNewDatabaseInstance("MyDBInstanceOnDisk", DatabaseInstanceType::ON_DISK);
    auto dbOnDisk = dbMng.getDatabaseInstance("MyDBInstanceOnDisk");
    dbOnDisk->setProperties(prop2);
    std::cout << dbOnDisk->getName() << std::endl;

    dbOnDisk->addRelations(rl1);
    dbOnDisk->addRelation(r3);

    dbOnDisk->removeRelation(r3);
    dbOnDisk->removeRelations(rl1);

    return 0;


}