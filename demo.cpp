#include <iostream>
#include "picture.hpp"
using namespace std;




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


int main() {

//    vector<vector<int>> T(1 , vector<int>(1));
//    picture<int> t(T);
//    t.draw_line(0,0,2,4,4);
//    t.displayPic();
//    t.draw_line(0,0,4,2,4);
//    t.displayPic();
//    t.draw_line(0,0,2,6,4);
//    t.displayPic();
//    t.draw_line(3,6,4,8,4);
//    t.displayPic();
//    t.draw_line(1,7,2,8,4);
//
//    t.displayPic();



    picture<int> r(10,10);
    r.draw_line(0,0,1,1,4);
    if(the_check_algorithem(r,0,0,2,6))
    {
        cout << "yyyyyyyyyyyyyyyyyyyyyy";
    }
//Pixel *q = new Pixel();
//    t.draw_line(1,1,2,11,60);
//    t.displayPic();
//    t.draw_line(x1, y1, x2, y2 , 77);
//    t.displayPic();

//    t-t;
//    t.displayPic();


//linev5R(x1,y1,x2,y2);
//linev6R(x1,y1,x2,y2);
//linev10(x1,y1,x2,y2);

    return 0;
}
