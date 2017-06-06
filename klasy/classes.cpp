#include<iostream>
#include "classes.h"



    my::vector::vector()
    {
        spaces_=NULL;
        lenght_=0;
    }

    my::vector::vector(int rozmiar)
    {
        spaces_= new int[rozmiar];
        lenght_=rozmiar;
    }

    my::vector::~vector()
    {
        if(lenght_>0)
           delete(spaces_);
    }

    my::vector::vector(const vector &obj)
    {
        int i;
        int* new_spaces;
        new_spaces = new int[obj.lenght_];
        for(i=0;i<obj.lenght_;i++)
            new_spaces[i]=obj.spaces_[i];
            lenght_=obj.lenght_;
         spaces_=new_spaces;

    }




    int my::vector::push_back(int number)
    {
        int i;
        int * new_spaces;
        new_spaces=new int[lenght_+1];
        if(!new_spaces)
        {
            std::cout << "nie udalo sie zaalokowac pamieci";
            return -1;
        }
        for(i=0;i<lenght_;i++)
            new_spaces[i]=spaces_[i];

        new_spaces[lenght_]=number;

        delete(spaces_);
        spaces_=new_spaces;
        lenght_++;
        return 0;
    }

    int my::vector::insert(int place,int new_value)
    {
        if(place>-1 && place<lenght_)
            spaces_[place]=new_value;
        else
        {
            std::cout << "wektor nie posiada takiego pola";
            return -1;
        }
        return 0;
    }

    int my::vector::size() const
    {
        return lenght_;
    }

    int my::vector::clear()
    {
        delete(spaces_);
        spaces_=NULL;
        lenght_=0;
        return 0;
    }

    int my::vector::erase(int place)
    {
        int i=0;
        int * new_spaces;
        new_spaces=new int[lenght_-1];
        while(i<place)
        {
            new_spaces[i]=spaces_[i];
            i++;
        }
        while(i<lenght_-1);
        {
            new_spaces[i]=spaces_[i+1];
            i++;
        }
        delete(spaces_);
        spaces_=new_spaces;
        lenght_--;
        return 0;

    }

    void my::vector::print_vector() const
    {
        int i;
        std::cout<< "(";
        for(i=0;i<lenght_;i++)
        {

            std::cout <<   spaces_[i];
            if(i!=lenght_-1)
            std::cout  << ", ";

        }
        std::cout << ")\n";
    }

    int my::vector::erase(int start,int finish)
    {

    }



    my::Matrix::Matrix()
    {
     vector_number_=0;
     vectors_=new vector;
    }


    my::Matrix::Matrix(const Matrix &obj)
    {
        int i,j;
        vectors_=new vector[obj.vector_number_];

        for(i=0;i<obj.vector_number_;i++)
            for(j=0;j<obj.rows_number_;j++)
                vectors_[i].push_back(0);



        for(i=0;i<obj.vector_number_;i++)
            for(j=0;j<obj.rows_number_;j++)
                vectors_[i].insert(j,obj.vectors_[i][j]);
        vector_number_=obj.vector_number_;
        rows_number_=obj.rows_number_;


    }

    my::Matrix::Matrix(int cols,int rows)
    {
        int i,j;
        vector_number_=cols;
        rows_number_=rows;
        vectors_ = new vector[cols];
        for(i=0;i<cols;i++)
            for(j=0;j<rows;j++)
                vectors_[i].push_back(0);

    }

    int my::Matrix::get_value(int row_number,int col_number)
    {
        return vectors_[col_number][row_number];
    }

    my::Matrix::~Matrix()
    {

        delete[] vectors_;

    }

    int my::Matrix::insert(int col,int row,int value)
    {
        vectors_[col].insert(row,value);
        return 0;
    }

    int my::Matrix::clear()
    {
        delete(vectors_);
        vector_number_ =0;
        rows_number_=0;
        return 1;
    }

    int my::Matrix::cols()
    {
        return vector_number_;
    }


int my::Matrix::rows()
    {
        return rows_number_;
    }

    void my::Matrix::print_matrix()
    {
        int i,j;
        if(vector_number_==0)
        {
            std::cout << "pusta macierz";
            return;
        }
        for(i=0;i<rows_number_;i++)
        {
            for(j=0;j<vector_number_;j++)
            {
                std::cout << vectors_[j][i] << " ";
            }
        std::cout << "\n";
        }


    }

    int my::Matrix::add_vector()
    {
        int i;
        if(vector_number_==0)
        {
            std::cout<< "nie ma zadnych wektorw w macierzy wiec nie da sie dodac bez zdefiniowania rozmiaru \n";
            return -1;
        }

        my::vector new_vector(rows_number_);
        for(i=0;i<rows_number_;i++)
            new_vector.insert(i,0);


        my::vector * new_vectors;
        new_vectors= new vector[vector_number_+1];
        for(i=0;i<vector_number_;i++)
            new_vectors[i]=vectors_[i];


        new_vectors[vector_number_]=new_vector;

        delete(vectors_);
        vectors_=new_vectors;
        vector_number_++;

        return 0;

    }

    int my::Matrix::add_vector(int vector_size)
    {
        int i;
        if(vector_number_==0)
        {
            vector new_vector(vector_size);
            for(i=0;i<vector_size;i++)
                new_vector.insert(i,0);
            vectors_[0]=new_vector;
                vector_number_=1;
                rows_number_=vector_size;
        return 0;
        }

        return -1;

    }








