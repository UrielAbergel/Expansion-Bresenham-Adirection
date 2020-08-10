//
// Created by uriel on 09/08/2020.
//

#include "doctest.hpp"
#include "Picture.hpp"

TEST_CASE("check range")
{
CHECK_THROWS(Picture<int> t(8,8););
}




