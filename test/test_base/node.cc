#include <gtest/gtest.h>
#include "Node.h"

using namespace SPIDERWEBDB;

TEST(NodeTest, Constructor_01) {
    Node n;
    ASSERT_EQ(n.getId(), "");
}

TEST(NodeTest, Constructor_02) {
    Node n("node_test");
    ASSERT_EQ(n.getId(), "node_test");
}