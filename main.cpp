#include <iostream>
#include "Picture.cpp"
using namespace std;


void bresenham(int x1, int y1, int x2, int y2)
{
    int m_new = 2 * (y2 - y1);
    int slope_error_new = m_new - (x2 - x1);
    for (int x = x1, y = y1; x <= x2 ; x++)
    {
        cout << "(" << x << "," << y << ")\n";

        // Add slope to increment angle formed
        slope_error_new += m_new;

        // Slope error reached limit, time to
        // increment y and update slope error.
        if (slope_error_new >= 0)
        {
            y++;
            slope_error_new  -= 2 * (x2 - x1);
        }
    }

    cout << "=================" << endl;
}



    void linev6(
                unsigned x1, unsigned y1,
                unsigned x2, unsigned y2
                )
    {
        int dx  = x2 - x1,
                dy  = y2 - y1,
                y   = y1,
                eps = 0;

        for ( int x = x1; x <= x2; x++ )  {
            cout << "(" << x << "," << y << ")\n";
            eps += dy;
            if ( (eps << 1) >= dx )  {
                y++;  eps -= dx;
            }
        }
    }



int main() {
    vector<vector<int>> T(10 , vector<int>(10));
    Picture<int> t(10,10,T);
    int x1 =0, y1 = 0, x2 =6, y2 = 2;
//
    t.displayPic();
  t.draw_A_line(x1, y1, x2, y2 , 2);
    t.displayPic();

//bresenham(x1,y1,x2,y2);
//    t.draw_A_line(x1, y1, x2, y2 , 4);

linev6(x1,y1,x2,y2);

    return 0;
}
