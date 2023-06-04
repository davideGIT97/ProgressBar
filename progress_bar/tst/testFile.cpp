//
// Created by davide on 23/04/23.
//

#include "../File.h"
#include "gtest/gtest.h"

TEST(testFile, testResourceNotFound){
    string name = "Divina Commedia - Prosa";
    File file(name);
    EXPECT_EQ(file.isLoaded(), false);
}