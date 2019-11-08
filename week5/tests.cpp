#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <ctime>

TEST_CASE("Test") {
    CHECK(1==1);
    CHECK(2==1+1);
}