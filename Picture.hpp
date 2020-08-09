//
// Created by uriel on 06/08/2020.
//

#pragma once

#include "vector"

using namespace std;

template<typename T = u_char> // uchar as Default
class Picture
{

private:
   vector<vector<T>> _Pic ;
   uint  _rows;
   uint _cols;
   void draw_vertical_line(int x1 ,int y1 , int x2, int y2 ,T value);
   void draw_std(int x1 ,int y1 , int x2, int y2 ,T value);
   void draw_rotate_ver(int x1 ,int y1 , int x2, int y2 ,T value);

public:
    Picture(uint row, uint cols) :  _rows(row),_cols(cols) ,_Pic(row, std::vector<T>(cols)){}

    Picture(uint row ,uint cols,const vector<vector<T>> pic): _rows(row),_cols(cols),_Pic(row, std::vector<T>(cols))
    {
        _Pic = pic; // the operator = is deep copy in vector class
    }

    virtual ~Picture() = default ;

    T& operator[](std::pair<int,int> location) {}

    T operator[](std::pair<int,int> location) const{}

    void draw_A_line(int x1 ,int y1 ,int x2,int y2 , T value){}

    void displayPic(){}
};
