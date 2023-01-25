#include "DatabaseManager.h"
#include <iostream>

using namespace SPIDERWEBDB;

int main(){
    DatabaseManager dbMng;
    dbMng.createNewDatabaseInstance("MyDBInstance");
    auto db = dbMng.getDatabaseInstance("MyDBInstance");
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
    
    db->writeToFile();

    DatabaseManager dbMng2;
    dbMng2.createNewDatabaseInstance("MyDBInstance");

    auto db2 = dbMng.getDatabaseInstance("MyDBInstance");

    db2->readFromFile();

    std::cout << *db2 << std::endl;

    return 0;


}