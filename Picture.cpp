//
// Created by uriel on 06/08/2020.
//


#include "Picture.hpp"
#include <iostream>




template<typename T>
T& Picture<T>::operator[](std::pair<int, int> location)
{
    return this->_Pic.at(location.first).at(location.second);
}

template<typename T>
T Picture<T>::operator[](std::pair<int, int> location) const
{
    return this->_Pic.at(location.first).at(location.second);
}

template<typename T>
void Picture<T>::draw_A_line(int x1, int y1, int x2, int y2 ,T value)
{
    //not use uint do not do cast with value incurrect
    if(x1 >= _cols || x2 >=_cols || x1 < 0 || x2 < 0) throw out_of_range("x1 | x2 not in range");
    if(y1 >= _rows || y2 >=_rows || y1 < 0 || y2 < 0) throw out_of_range("y1 || y2 not in range");
    if(x1 == x2 || y1 == y2)
    {
        this->draw_ver_line(x1,y1,x2,y2,value);
        return;
    }
    if(y1 > y2)
    {
        // swap (x1,y1) with (x2,y2)
        int temp;
        temp = x1;
        x1 = x2;
        x2 = temp;
        temp = y1;
        y1 = y2;
        y2 = temp;
    }
    if(x2 < y2) {
        int dx,
                dy = y2 - y1,
                x = x1,
                eps = 0;
        if (x1 < x2) dx = x2 - x1;
        else dx = x1 - x2;

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
    else
    {
        int dx  = x2 - x1,
                dy  = y2 - y1,
                y   = y1,
                eps = 0;

        for ( int x = x1; x <= x2; x++ )  {
            _Pic.at(x).at(y) = value;
            eps += dy;
            if ( (eps << 1) >= dx )  {
                y++;  eps -= dx;
            }
        }
    }
    }




template<typename T>
void Picture<T>::displayPic() {

    for (int i = 0; i <this->_rows ; ++i)
    {
        cout << "[" ; // start with [ for matrix view
        for (int j = 0; j < this->_cols; ++j)
        {
            cout << this->_Pic.at(i).at(j);
        }
        cout << "]\n" ;
    }
    cout << "====================="  << endl;
}

template<typename T>
void Picture<T>::draw_ver_line(int x1, int y1, int x2, int y2, T value)
{

    if(x1 == x2)
    {
        int temp = std::abs(y2-y1);
        for (int i = min(y2,y1); i <= max(y2,y1) ; ++i)
        {
            _Pic.at(i).at(x1) = value;
        }
    }
    if(y1 == y2)
    {
        for (int i = min(x2,x1); i <= max(x2,x1) ; ++i)
        {
            _Pic.at(y1).at(i) = value;
        }
    }
}


