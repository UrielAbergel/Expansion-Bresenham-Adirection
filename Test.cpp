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

/*
 * delete all values from the matrix
 */
template <typename T>
void clear_mat(picture<T> & r)
{
    for (int i = 0; i < r.get_rows(); ++i) {
        for (int j = 0; j < r.get_cols(); ++j) {
            r[{i,j}] = 0;
        }
    }
}


/*
 * Checks if there is any number around the middle return the location of the number
 */
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


/*
 * An algorithm that checks if there is a line connecting the points and that the slope works
 */
template <typename T>
bool check_the_draw(picture<T> & r ,int x1 ,int y1,int x2,int y2)
{
    if(x1 == x2 && y1 == y2)
        return true;
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
    picture<int> mat(10,10);
    mat.draw_line(0,0,2,6,4);
    CHECK(check_the_draw(mat,0,0,2,6));
    clear_mat(mat);

    mat.draw_line(0,0,6,2,4);
    CHECK(check_the_draw(mat,0,0,6,2));
    clear_mat(mat);

    mat.draw_line(2,2,4,4,4);
    CHECK(check_the_draw(mat,2,2,4,4));
    clear_mat(mat);

    mat.draw_line(4,4,7,8,4);
    CHECK(check_the_draw(mat,4,4,7,8));
    clear_mat(mat);

    mat.draw_line(0,0,6,6,4);
    CHECK_FALSE(check_the_draw(mat,0,0,2,6));
    clear_mat(mat);

    mat.draw_line(0,0,6,8,4);
    CHECK_FALSE(check_the_draw(mat,0,3,6,2));
    clear_mat(mat);

    mat.draw_line(2,2,8,4,4);
    CHECK_FALSE(check_the_draw(mat,2,2,4,4));
    clear_mat(mat);

    mat.draw_line(4,4,7,8,4);
    CHECK_FALSE(check_the_draw(mat,0,0,1,1));
    clear_mat(mat);
}




TEST_CASE("check draw with m(slope) negative")
{
    picture<int> mat(10,10);
    mat.draw_line(8,0,2,6,4);
    CHECK(check_the_draw(mat,8,0,2,6));
    clear_mat(mat);

    mat.draw_line(4,0,6,2,4);
    CHECK(check_the_draw(mat,4,0,6,2));
    clear_mat(mat);

    mat.draw_line(8,2,4,4,4);
    CHECK(check_the_draw(mat,8,2,4,4));
    clear_mat(mat);

    mat.draw_line(8,4,7,8,4);
    CHECK(check_the_draw(mat,8,4,7,8));
    clear_mat(mat);

    mat.draw_line(8,3,6,2,4);
    CHECK_FALSE(check_the_draw(mat,0,0,2,6));
    clear_mat(mat);

    mat.draw_line(7,0,6,8,4);
    CHECK_FALSE(check_the_draw(mat,0,3,6,2));
    clear_mat(mat);

    mat.draw_line(7,2,6,4,4);
    CHECK_FALSE(check_the_draw(mat,2,2,4,4));
    clear_mat(mat);

    mat.draw_line(8,4,7,8,4);
    CHECK_FALSE(check_the_draw(mat,0,0,1,1));
    clear_mat(mat);
}

TEST_CASE("check draw with m(slope) = 0 ")
{
    picture<int> mat(10,10);
    mat.draw_line(8,0,8,6,4);
    CHECK(check_the_draw(mat,8,0,8,6));
    clear_mat(mat);

    mat.draw_line(4,0,4,2,4);
    CHECK(check_the_draw(mat,4,0,4,2));
    clear_mat(mat);

    mat.draw_line(8,2,8,4,4);
    CHECK(check_the_draw(mat,8,2,8,4));
    clear_mat(mat);

    mat.draw_line(7,0,6,8,4);
    CHECK_FALSE(check_the_draw(mat,0,3,0,2));
    clear_mat(mat);

    mat.draw_line(7,2,6,4,4);
    CHECK_FALSE(check_the_draw(mat,2,2,2,4));
    clear_mat(mat);

    mat.draw_line(8,4,7,8,4);
    CHECK_FALSE(check_the_draw(mat,1,0,1,1));
    clear_mat(mat);
}


TEST_CASE("test random 50000 tests with random number and any direction")
{
    int x1,y1,x2,y2 ,size = rand() % 100 ;

    picture<int> mat(size,size);
    for (int i = 0; i < 50000; ++i)
    {
        x1 = rand() % size;
        x2 = rand() % size;
        y1 = rand() % size;
        y2 = rand() % size;
        mat.draw_line(x1,y1,x2,y2,4);
        CHECK(check_the_draw(mat,x1,y1,x2,y2));
        clear_mat(mat);
    }

}




