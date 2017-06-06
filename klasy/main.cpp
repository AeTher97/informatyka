#include<iostream>

#include "classes.h"



int main()
{
    my::vector wektor(2);
    my::Matrix matrix(10,10);

    my::Matrix matrix3(3,3);

    //std::cout<<matrix;


    std::cout << matrix3;
    std::cout << std::endl;

    std::cout << wektor;

    std::cout << matrix;
    std::cin >> &matrix;
    std::cout << matrix;
    return 0;



}
