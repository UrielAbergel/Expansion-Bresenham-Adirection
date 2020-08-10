//
// Created by uriel on 09/08/2020.
//

#include "doctest.hpp"
#include "picture.hpp"

struct Pixel
{
    u_char _R,_G,_B;
    Pixel(){}
    Pixel(u_char r ,u_char g , u_char b): _R(r),_G(g),_B(b){}
};
template <typename T>
void clear_mat(picture<T> & r)
{
    for (int i = 0; i < r.get_rows(); ++i) {
        for (int j = 0; j < r.get_cols(); ++j) {
            r[{i,j}] = 0;
        }
    }
}

template <typename T>
pair<int,int> check_if_around(picture<T> & r,int x,int y)
{
    pair<int,int> ans = {-1,-1};
    try
    {
        for (int i = x-1; i <= x+1 ; ++i)
        {
            for (int j = y-1; j <=y+1; ++j)
            {

                if(i >= 0 && i < r.get_rows() && j >= 0 && j < r.get_cols())
                {
                    if(r[{i,j}] == 4)
                    {
                        ans.first = i;
                        ans.second = j;
                        return ans;
                    }
                }


            }
        }
        return ans;
    }
    catch (exception ex){}

}

template <typename T>
bool the_check_algorithem(picture<T> & r ,int x1 ,int y1,int x2,int y2)
{
    pair<int,int> current = {x1,y1};
    r[current] = -1;
    while(1)
    {
        current = check_if_around(r ,current.first,current.second);
        if(current == pair<int,int>(-1,-1))
            break;

        r[current] = -1;
        if(current == pair<int,int>(x2,y2))
            return true;
    }
    return false;
}



TEST_CASE("check range")
{
    int check_i = 4;
    Pixel check_p(3,3,3);
    u_char check_u = 60 ;
    picture<u_char> t(10,10);
    picture<Pixel> q(10,10);
    picture<int> r(10,10);
    CHECK_THROWS(t.draw_line(1,1,2,11,check_u));
    CHECK_THROWS(t.draw_line(11,1,2,0,check_u));
    CHECK_THROWS(q.draw_line(1,1,3,11,check_p));
    CHECK_THROWS(q.draw_line(1,1,-2,-1,check_p));
    CHECK_THROWS(t.draw_line(1,1,-4,11,60));
    CHECK_THROWS(r.draw_line(1,1,2,-1,60));
    CHECK_THROWS(r.draw_line(31,1,85,11,check_i));
    CHECK_THROWS(q.draw_line(1,1,2,11,check_p));
    CHECK_THROWS(t.draw_line(1,1,2,11,check_u));
    CHECK_THROWS(t.draw_line(1,1,2,11,check_i));
}

TEST_CASE("check constructors")
{
    CHECK_NOTHROW(picture<Pixel> q(80,80));
    CHECK_NOTHROW(picture<int> q(1,86));
    CHECK_NOTHROW(picture<double> q(300,3000));
    CHECK_NOTHROW(picture<long> q(300,10));
    CHECK_NOTHROW(picture<short> q(300,1));

}

TEST_CASE("check draw with m(slope) positive")
{
    picture<int> r(10,10);
    r.draw_line(0,0,2,6,4);
    CHECK(the_check_algorithem(r,0,0,2,6));
    clear_mat(r);

    r.draw_line(0,0,6,2,4);
    CHECK(the_check_algorithem(r,0,0,6,2));
    clear_mat(r);

    r.draw_line(2,2,4,4,4);
    CHECK(the_check_algorithem(r,2,2,4,4));
    clear_mat(r);

    r.draw_line(4,4,7,8,4);
    CHECK(the_check_algorithem(r,4,4,7,8));
    clear_mat(r);

    r.draw_line(0,0,6,6,4);
    CHECK_FALSE(the_check_algorithem(r,0,0,2,6));
    clear_mat(r);

    r.draw_line(0,0,6,8,4);
    CHECK(the_check_algorithem(r,0,0,6,2));
    clear_mat(r);

    r.draw_line(2,2,4,4,4);
            CHECK(the_check_algorithem(r,2,2,4,4));
    clear_mat(r);

    r.draw_line(4,4,7,8,4);
            CHECK(the_check_algorithem(r,4,4,7,8));
    clear_mat(r);

}




