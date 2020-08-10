//
// Created by uriel on 06/08/2020.
//

#pragma once

#include <iostream>
#include <vector>

using namespace std;

template<typename T = u_char> // uchar as Default
class picture
{
private:
    vector<vector<T>> _Pic;
    uint _rows;
    uint _cols;


 /*
  * draw_vertical_line Produces a straight line within the matrix both Length & Width
  */
//------------------------------------------------------------------------

    void draw_vertical_line(int x1, int y1, int x2, int y2, T value)
    {
        int i;

        if (x1 == x2)
            for (i = min(y2, y1) ; i <= max(y2, y1) ; ++i)
                _Pic.at(x1).at(i) = value;

        if (y1 == y2)
            for (i = min(x2, x1) ; i <= max(x2, x1) ; ++i)
                _Pic.at(i).at(y1) = value;
    }
/*
 * A function that produces a line between two points when m(slope) is negative
 */
//------------------------------------------------------------------------

    void draw_std_lower_case(int x1, int y1, int x2, int y2, T value)
    {
        int dx = x1 - x2,
            dy = y2 - y1,
            x = x1,
            eps = 0;

        for (int y = y1 ; y <= y2 ; y++)
        {
            _Pic.at(x).at(y) = value;
            eps += dx;
            if ((eps << 1) >= dy ) // eps * 2
            {
                x--;
                eps -= dy;
            }
        }
    }
/*
 * A function that draws a line between two points when m(slope) negative and the density is very small (do "rotate")
 */
//------------------------------------------------------------------------

    void draw_rotate_ver_lower_case(int x1, int y1, int x2, int y2, T value)
    {
        int dx = x1 - x2,
            dy = y2 - y1,
            y = y1,
            eps = 0;

        for (int x = x1 ; x >= x2 ; x--)
        {
            _Pic.at(x).at(y) = value;
            eps += dy;
            if ((eps << 1) >= dx) // eps * 2
            {
                y++;
                eps -= dx;
            }
        }
    }
/*
 *   A function that produces a line between two points when m(slope) is positive
 */
//------------------------------------------------------------------------

    void draw_std(int x1, int y1, int x2, int y2, T value)
    {
        int dx,
            dy = y2 - y1,
            x = x1,
            eps = 0;
            dx = abs(x2 - x1);

        for (int y = y1 ; y <= y2 ; y++)
        {
            _Pic.at(x).at(y) = value;
            eps += dx;
            if ((eps << 1) >= dy) // eps * 2
            {
                x++;
                eps -= dy;
            }
        }
    }
/*
 *   A function that draws a line between two points when m(slope) positive and the density is very small (do "rotate")
 */
//------------------------------------------------------------------------

    void draw_rotate_ver(int x1, int y1, int x2, int y2, T value)
    {
        int dx = x2 - x1,
            dy = y2 - y1,
            y = y1,
            eps = 0;

        for (int x = x1 ; x <= x2 ; x++)
        {
            _Pic.at(x).at(y) = value;
            eps += dy;
            if ((eps << 1) >= dx) // eps * 2
            {
                y++;
                eps -= dx;
            }
        }
    }
/*
 * Check which algorithm makes better density
 */
//------------------------------------------------------------------------

    int check(int x1, int y1, int x2, int y2)
    {
        int countSTD = 0;
        int countROT = 0;

        /*
        * check the density in algo num 1
        */
        int dx = abs(x2 - x1),
            dy = y2 - y1,
            x = x1,
            eps = 0,
            y = y1;

        for (int y = y1 ; y <= y2 ; y++)
        {
            countSTD++;
            eps += dx;
            if ((eps << 1) >= dy)
            {
                x++;
                eps -= dy;
            }
        }

        /*
         * check the density in algo num 2
         */
        dx = x1 - x2;
        dy = y2 - y1;
        eps = 0;

        for (x = x1 ; x >= x2 ; x--)
        {
            countROT++;
            eps += dy;
            if ((eps << 1) >= dx)
            {
                y++;
                eps -= dx;
            }
        }

        if (countSTD > countROT)
            return 1;
        else
            return -1;
    }

//-----------------------------------public---------------------
public:

    picture(uint row, uint cols) : _rows(row), _cols(cols), _Pic(row, std::vector<T>(cols)){} // row/col constructor

    picture(const vector<vector<T>> pic) : _Pic(pic) ,_rows(pic.size()),_cols(pic.at(0).size()){} // vector constructor

    virtual ~picture() = default;

    /*
     * oprerator [] get pair and return the value in the matrix
     */
//------------------------------------------------------------------------

    T &operator[](std::pair<int,int> location)
    {
        try
        {
            return this->_Pic.at(location.first).at(location.second);
        }
        catch (out_of_range &ex)
        {
            cout << "not in range" << endl;
            throw ex;
        }
    }

    /*
    * oprerator [] get pair and return the value in the matrix get const value
    */
//------------------------------------------------------------------------

    T operator[](std::pair<int,int> location) const
    {
        try
        {
            return this->_Pic.at(location.first).at(location.second);
        }
        catch (exception ex)
        {
            cout << "not in range" << endl;
            throw ex;
        }
    }
/*
 * operator diff for other pic get & to not do copy
 */
//------------------------------------------------------------------------

    picture& operator-(picture<T>& to_delete)
    {
        for (int i = 0; i < _rows; ++i)
            for (int j = 0; j < _cols; ++j)
                if (this->_Pic.at(i).at(j) - to_delete[{i,j}] >= 0)
                    this->_Pic.at(i).at(j) -= to_delete[{i,j}];

        return *this;
    }

    /*
     * equal between 2 picture
     */
    bool operator==(picture<T>& check_equal)
    {
        bool ans = true ;
        for (int i = 0; i < _rows; ++i)
            for (int j = 0; j < _cols; ++j)
                if (!(this->_Pic.at(i).at(j) == check_equal[{i,j}]))
                    return false;

        return true;
    }
/*
 *An algorithm that draws a line in any shape on the matrix, from point to point by dividing it into different cases,
 * some of which check density and some of which color the matrix
 * lower case for m(slope) negative
 * not lower case for m(slope) positive
 */
//------------------------------------------------------------------------

    void draw_line(int x1, int y1, int x2, int y2, T value)
    {
        int temp;
        //not use uint do not do cast with incurrect value
        if (x1 >= _rows || x2 >= _rows || x1 < 0 || x2 < 0)
            throw out_of_range("x1 | x2 not in range");
        if (y1 >= _cols || y2 >= _cols || y1 < 0 || y2 < 0)
            throw out_of_range("y1 || y2 not in range");
        if (y2 < y1)
        {
            //swap points
           swap(x1,x2);
           swap(y1,y2);
        }
        if (x1 == x2 || y1 == y2)
        {
            this->draw_vertical_line(x1, y1, x2, y2, value);
            return;
        }
        if(x1 < x2)
            if (x2 < y2)
                draw_std(x1, y1, x2, y2, value);
            else
                draw_rotate_ver(x1, y1, x2, y2, value);
        else
            if (check(x1,y1,x2,y2) == 1)
                draw_std_lower_case(x1, y1, x2, y2, value);
            else
                draw_rotate_ver_lower_case(x1,y1,x2,y2,value);
    }
/*
 * A function that prints the matrix to the terminal
 */
//------------------------------------------------------------------------

    void displayPic()
    {
        for (int i = 0 ; i <this->_rows ; ++i)
        {
            cout << "[\t"; // start with [ for matrix view

            for (int j = 0 ; j < this->_cols ; ++j)
                cout << this->_Pic.at(i).at(j) << "\t";

            cout << "]\n";
        }
        cout << "=====================" << endl;
    }

    uint get_rows()
    {
        return this->_rows;
    }

    uint get_cols()
    {
        return this->_cols;
    }
};


