//
// Created by uriel on 06/08/2020.
//

#ifndef TASKINTERVIEW_PICTRUE_H
#define TASKINTERVIEW_PICTRUE_H


#include "vector"


using namespace std;




template<typename T = unsigned char>
class Pictrue {

private:
   vector<vector<T>> _Pic ;
   uint  _rows;
   uint _cols;
   void draw_ver_line(uint x1 ,uint y1 , uint x2, uint y2 ,T value);



public:
    Pictrue(uint row ,uint cols,const vector<vector<T>> pic): _rows(row),_cols(cols),_Pic(row, std::vector<T>(cols))
    {
        _Pic = pic; // the operator = is deep copy in vector class
    }

    virtual ~Pictrue() = default ;

    T& operator[](std::pair<int,int> location);

    T operator[](std::pair<int,int> location) const;

    void draw_A_line(int x1 ,int y1 ,int x2,int y2 , T value);

    void displayPic();






};




#endif //TASKINTERVIEW_PICTRUE_H
