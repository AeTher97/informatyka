#include<iostream>
#include "classes.h"



int main()
{
    int i;
    int j;
    my::Matrix macierz(1,1);
    for(i=0;i<1;i++)
        for(j=0;j<1;j++)
            macierz.insert(i,j,i+1);
    my::Matrix macierz2(3,3);
    for(i=0;i<3;i++)
        for(j=0;j<3;j++)
            macierz2.insert(i,j,i+4);






    macierz=macierz2;
    std::cout<< macierz;
    std::cout<<"+"<<std::endl;
    std::cout <<macierz2;
    std::cout<<"="<<std::endl;
    std::cout<<macierz+macierz2;


    return 0;


}
