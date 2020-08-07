//
// Created by uriel on 06/08/2020.
//

#ifndef TASKINTERVIEW_PICTRUE_H
#define TASKINTERVIEW_PICTRUE_H

#include <cstdint>
#include "vector"


using namespace std;




template<typename T = unsigned char>
class Pictrue {

private:
   vector<vector<T>> _Pic ;
   unsigned int _rows;
   unsigned int _cols;
    void draw_A_lineX1(int x1 ,int y1 ,int x2,int y2 , T value);
    void draw_A_lineX2(int x1 ,int y1 ,int x2,int y2 , T value);
    void draw_A_lineY1(int x1 ,int y1 ,int x2,int y2 , T value);
    void draw_A_lineY2(int x1 ,int y1 ,int x2,int y2 , T value);


public:
    Pictrue(unsigned row ,unsigned cols,const vector<vector<T>> pic): _rows(row),_cols(cols),_Pic(row, std::vector<T>(cols))
    {
        _Pic = pic; // the operator = is deep copy in vector class
    }

    virtual ~Pictrue()
    {
        for (int i = 0; i <_rows ; ++i)
        {
            _Pic.erase(_Pic.begin(),_Pic.end());
        }
    }

    T& operator[](std::pair<int,int> location);

    T operator[](std::pair<int,int> location) const;

    void draw_A_line(int x1 ,int y1 ,int x2,int y2 , T value);

    void displayPic();






};




#endif //TASKINTERVIEW_PICTRUE_H
