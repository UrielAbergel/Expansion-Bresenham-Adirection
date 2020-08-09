//
// Created by uriel on 06/08/2020.
//

#pragma once

#include <iostream>
#include <vector>

using namespace std;

template<typename T = u_char> // uchar as Default
class Picture
{
private:
   vector<vector<T>> _Pic ;
   uint  _rows;
   uint _cols;
   void draw_vertical_line(int x1 ,int y1 , int x2, int y2 ,T value)
   {
       if (x1 == x2)
       {
           for (int i = min(y2,y1); i <= max(y2,y1) ; ++i)
           {
               _Pic.at(x1).at(i) = value;
           }
       }
       if (y1 == y2)
       {
           for (int i = min(x2,x1); i <= max(x2,x1) ; ++i)
           {
               _Pic.at(i).at(y1) = value;
           }
       }
   }
   void draw_std(int x1 ,int y1 , int x2, int y2 ,T value)
   {
       int dx,
               dy = y2 - y1,
               x = x1,
               eps = 0;
       dx = abs(x2-x1);

       for (int y = y1; y <= y2; y++) {
           _Pic.at(x).at(y) = value;
           eps += dx;
           if ((eps << 1) >= dy) {
               if (x2 > x1) x++;
               else x--;
               eps -= dy;
           }
       }
   }

   void draw_rotate_ver(int x1 ,int y1 , int x2, int y2 ,T value)
   {
       int temp;
       if(x1 > x2)
       {
           temp = x1 ;
           x1 = x2;
           x1 = temp;
           temp = y1;
           y1 = y2 ;
           y2 = temp;
       }
       int dx  = x2 - x1,
               dy  = y2 - y1,
               y   = y1,
               eps = 0;

       for ( int x = x1; x <= x2; x++ )
       {
           _Pic.at(x).at(y) = value;
           eps += dy;
           if ((eps << 1) >= dx )
           {
               if (y2 > y1)
                   y++;
               else
                   y--;
               eps -= dx;
           }
       }
   }

public:

    Picture(uint row ,uint cols,const vector<vector<T>> pic): _rows(row),_cols(cols),_Pic(pic)
    {
    }

    virtual ~Picture() = default ;

    T& operator[](std::pair<int,int> location)
    {
        return this->_Pic.at(location.first).at(location.second);
    }

    T operator[](std::pair<int,int> location) const
    {
        return this->_Pic.at(location.first).at(location.second);
    }






    void draw_A_line(int x1, int y1, int x2, int y2 ,T value)
    {
        //not use uint do not do cast with value incurrect
        if(x1 >= _rows || x2 >=_rows || x1 < 0 || x2 < 0) throw out_of_range("x1 | x2 not in range");
        if(y1 >= _cols || y2 >=_cols || y1 < 0 || y2 < 0) throw out_of_range("y1 || y2 not in range");
        if(x1 == x2 || y1 == y2)
        {
            this->draw_vertical_line(x1,y1,x2,y2,value);
            return;
        }

        if (x2 < y2) {
            int dx = abs(x2 - x1),
                    dy = y2 - y1,
                    x = x1,
                    eps = 0;

            for (int y = y1; y <= y2; y++) {
                _Pic.at(x).at(y) = value;
                eps += dx;
                if ((eps << 1) >= dy) {
                    if(x1 < x2)
                        x++;
                    else
                        x--;
                    eps -= dy;
                }
            }
        }
        else {
            if (x1 < x2) {
                int dx = x2 - x1,
                        dy = y2 - y1,
                        y = y1,
                        eps = 0;

                for (int x = x1; x <= x2; x++) {
                    _Pic.at(x).at(y) = value;
                    eps += dy;
                    if ((eps << 1) >= dx) {
                        y++;
                        eps -= dx;
                    }
                }
            }
            else
            {
                int dx = x1 - x2,
                        dy = y2 - y1,
                        y = y1,
                        eps = 0;

                for (int x = x1; x >= x2; x--) {
                    _Pic.at(x).at(y) = value;
                    eps += dy;
                    if ((eps << 1) >= dx) {
                        y++;
                        eps -= dx;
                    }
                }
            }
        }

    }












    void displayPic()
    {
        for (int i = 0 ; i <this->_rows ; ++i)
        {
            cout << "[\t" ; // start with [ for matrix view
            for (int j = 0 ; j < this->_cols ; ++j)
            {
                cout << this->_Pic.at(i).at(j) << "\t";
            }
            cout << "]\n";
        }
        cout << "====================="  << endl;

    }
};
