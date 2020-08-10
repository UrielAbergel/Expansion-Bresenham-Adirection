



#include <iostream>
#include "picture.hpp"
using namespace std;



int main()
{
    int x1 =2 ,y1 = 5 , x2 = 13, y2 = 14;
    vector<vector<int>> T(15 , vector<int>(15));
    picture<int> mat(T);
    mat.displayPic();
    mat.draw_line(x1,y1,x2,y2,5);
    mat.displayPic();
    mat[{8,8}] = 60;
    mat.displayPic();
    mat-mat;
    mat.displayPic();
    return 0;
}
