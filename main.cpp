#include <iostream>
#include "Pictrue.cpp"
using namespace std;


void bresenham(int x1, int y1, int x2, int y2)
{
    int m_new = 2 * (y1 - y2);
    int slope_error_new = m_new - (x2 - x1);
    for (int x = x1, y = y1; x <= x2; x++)
    {
        cout << "(" << x << "," << y << ")\n";

        // Add slope to increment angle formed
        slope_error_new += m_new;

        // Slope error reached limit, time to
        // increment y and update slope error.
        if (slope_error_new >= 0)
        {
            y--;
            slope_error_new  -= 2 * (x2 - x1);
        }
    }
}

int main() {
    vector<vector<int>> T(20 , vector<int>(20));
    Pictrue<int> t(20,20,T);
    t[{3,3}] = 8;
    int x1 = 18, y1 = 2, x2 = 2, y2 = 8;
//
    t.displayPic();
  t.draw_A_line(x1, y1, x2, y2 , 4);

    t.displayPic();

//bresenham(x1,y1,x2,y2);


    return 0;
}
