//#include <iostream>
//#include "Picture.hpp"
//using namespace std;
//void linev5(
//        unsigned x1, unsigned y1,
//        unsigned x2, unsigned y2
//)
//{
//    int dx  = x2 - x1,
//            dy  = y2 - y1,
//            y   = y1,
//            eps = 0;
//
//    for ( int x = x1; x <= x2; x++ )  {
//        cout << "(" << x << "," << y << ")\n";
//        eps += dy;
//        if ( (eps << 1) >= dx )  {
//            y++;  eps -= dx;
//        }
//    }
//    cout << "----------" << endl;
//}
//
//void linev6(
//            unsigned x1, unsigned y1,
//            unsigned x2, unsigned y2
//             )
//{
//    int dx  = x2 - x1,
//            dy  = y2 - y1,
//            x   = x1,
//            eps = 0;
//
//    for ( int y = y1; y <= y2; y++ )  {
//        cout << "(" << x << "," << y << ")\n";
//        eps += dx;
//        if ( (eps << 1) >= dy )  {
//            x++;  eps -= dy;
//        }
//    }
//    cout << "----------------" << endl;
//}
//
//
//void linev6R(
//        unsigned x1, unsigned y1,
//        unsigned x2, unsigned y2
//)
//{
//    int dx  = x1 - x2,
//            dy  = y2 - y1,
//            x   = x1,
//            eps = 0;
//
//    for ( int y = y1; y <= y2; y++ )  {
//        cout << "(" << x << "," << y << ")\n";
//        eps += dx;
//        if ( (eps << 1) >= dy )  {
//            x--;  eps -= dy;
//        }
//    }
//    cout << "----------------" << endl;
//}
//
//void linev5R(
//        unsigned x1, unsigned y1,
//        unsigned x2, unsigned y2
//)
//{
//    int dx  = x1 - x2,
//            dy  = y2 - y1,
//            y   = y1,
//            eps = 0;
//
//    for ( int x = x1; x >= x2; x-- )  {
//        cout << "(" << x << "," << y << ")\n";
//        eps += dy;
//        if ( (eps << 1) >= dx )  {
//            y++;  eps -= dx;
//        }
//    }
//    cout << "----------" << endl;
//}
//
//
//void linev10(
//            unsigned x1, unsigned y1,
//            unsigned x2, unsigned y2
//            )
//{
//    int dx  = x2 - x1,
//            dy  = y2 - y1,
//            y   = y1,
//            eps = 0;
//
//    for ( int x = x1; x <= x2; x++ )  {
//        cout << "(" << x << "," << y << ")\n";
//        eps += dy;
//        if ( (eps << 1) >= dx )  {
//            y++;  eps -= dx;
//        }
//    }
//}
//
//int main() {
//
//    vector<vector<char>> T(10 , vector<char>(7));
//    Picture t(10,7 );
//    int x1 =8, y1 =0, x2 = 4, y2 = 6 ;
//
////Pixel *q = new Pixel();
//    t.displayPic();
//    t.draw_line(x1, y1, x2, y2 , 77);
//    t.displayPic();
//
////    t-t;
////    t.displayPic();
//
//
////linev5R(x1,y1,x2,y2);
//linev6R(x1,y1,x2,y2);
////linev10(x1,y1,x2,y2);
//
//    return 0;
//}
