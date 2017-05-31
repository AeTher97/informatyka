#include<iostream>

#ifndef CLASSES_H_INCLUDED
#define CLASSES_H_INCLUDED



namespace my{

    class vector{
    private:
        int lenght_;
        int * spaces_;

    public:
        vector();
        vector(int rozmiar);
        vector(const vector &obj);
        ~vector();
        int push_back(int number);
        int insert(int place,int new_value);
        int size() const;
        int erase(int place);
        int erase(int start,int finish);
        int clear();
        void print_vector() const;

        int operator[](const unsigned & index)
        {
            return spaces_[index];
        }


        vector operator+(const vector& vector_)
        {
            int i;
            vector new_vector(this->lenght_);
            for(i=0;i<this->lenght_;i++)
            {
                new_vector.insert(i,this->spaces_[i]+vector_.spaces_[i]);

            }
            return new_vector;
        }

        vector operator+(int& liczba)
        {
            int i;
            vector new_vector(this->lenght_);
            for(i=0;i<this->lenght_;i++)
            {
                new_vector.insert(i,this->spaces_[i]+liczba);

            }
            return new_vector;
        }



        vector operator=(const vector& vector_)
        {
            int i;
            this->clear();

            for(i=0;i<vector_.size();i++)
            {
                this->push_back(vector_.spaces_[i]);
            }
            return *this;
        }

        vector operator-(const vector& vector_)
        {
            int i;
            vector new_vector(this->lenght_);
            for(i=0;i<this->lenght_;i++)
            {
                new_vector.insert(i,this->spaces_[i]-vector_.spaces_[i]);

            }
            return new_vector;
        }

        vector operator-(int & liczba)
        {
            int i;
            vector new_vector(this->lenght_);
            for(i=0;i<this->lenght_;i++)
            {
                new_vector.insert(i,this->spaces_[i]-liczba);

            }
            return new_vector;
        }



        vector operator*(const vector& vector_)
        {
            int i;
            vector new_vector(this->lenght_);
            for(i=0;i<this->lenght_;i++)
            {
                new_vector.insert(i,this->spaces_[i]*vector_.spaces_[i]);

            }
            return new_vector;
        }

        vector operator*(int & liczba)
        {
            int i;
            vector new_vector(this->lenght_);
            for(i=0;i<this->lenght_;i++)
            {
                new_vector.insert(i,this->spaces_[i]*liczba);

            }
            return new_vector;
        }


        bool operator==(const vector & vector_)
        {
            int i=0;
            while(i<vector_.size())
            {
                if(this->spaces_[i]!=vector_.spaces_[i])
                    return false;
                    i++;
            }
            return true;

        }

        bool operator!=(const vector & vector_)
        {
            int i=0;
            while(i<vector_.size())
            {
                if(this->spaces_[i]!=vector_.spaces_[i])
                    return true;
                    i++;
            }
            return false;

        }

        void operator+=(const int& add)
        {
            int i;
            for(i=0;i<this->size();i++)
                this->spaces_[i]=this->spaces_[i]+add;


        }

        void operator+=(vector & vector_)
        {
            int i;
            for(i=0;i<this->size();i++)
                this->spaces_[i]=this->spaces_[i]+vector_[i];


        }

        void operator-=(const int& removed)
        {
            int i;
            for(i=0;i<this->size();i++)
                this->spaces_[i]=this->spaces_[i]-removed;

        }

        void operator-=(vector & vector_)
        {
            int i;
            for(i=0;i<this->size();i++)
                this->spaces_[i]=this->spaces_[i]-vector_[i];

        }

         void operator*=(const int& multiplied)
        {
            int i;
            for(i=0;i<this->size();i++)
                this->spaces_[i]=this->spaces_[i]*multiplied;

        }


    };

    class Matrix{
        private:
            my::vector * vectors_;
            int vector_number_;
            int rows_number_;
        public:
            void print_matrix();
            ~Matrix();
            Matrix();
            Matrix(int cols,int rows);
            Matrix(const Matrix &obj);
            int insert(int col,int row, int value);
            int clear();
            int cols();
            int rows();
            int add_vector();
            int get_value(int l,int s);
            int add_vector(int vector_size);


            vector operator[](const unsigned & col)
            {
                return vectors_[col];
            }

            Matrix operator=(Matrix& copied_matrix)
            {
                int i;
                if(vector_number_!=copied_matrix.cols())
                {
                    delete(vectors_);
                    vectors_=new my::vector[copied_matrix.cols()];
                }

                for(i=0;i<copied_matrix.vector_number_;i++)
                {
                    vectors_[i]=copied_matrix.vectors_[i];


                }
                rows_number_=copied_matrix.rows_number_;
                vector_number_=copied_matrix.vector_number_;

                return *this;
            }

            Matrix operator+(Matrix& added)
            {
                my::Matrix new_matrix(added.cols(),added.rows());
                int i;
                int j;
                for(i=0;i<this->cols();i++)
                    for(j=0;j<this->rows();j++)
                        new_matrix.insert(i,j,this->vectors_[i][j]+added.vectors_[i][j]);
                return new_matrix;
            }

            Matrix operator+(const int& liczba)
            {
                my::Matrix new_matrix(this->cols(),this->rows());
                int i;
                int j;
                for(i=0;i<this->cols();i++)
                    for(j=0;j<this->rows();j++)
                        new_matrix.insert(i,j,this->vectors_[i][j]+liczba);
                return new_matrix;
            }

            Matrix operator*(const int& liczba)
            {
                my::Matrix new_matrix(this->cols(),this->rows());
                int i;
                int j;
                for(i=0;i<this->cols();i++)
                    for(j=0;j<this->rows();j++)
                        new_matrix.insert(i,j,this->vectors_[i][j]*liczba);
                return new_matrix;
            }

            Matrix operator* (Matrix& multiplied)
            {
            int sum=0;
            int i,j,k;
            my::Matrix temp(this->rows(),multiplied.cols());
            for (i = 0; i < multiplied.vector_number_; i++) {
                for (j = 0; j < this->rows_number_; j++) {

                    for (k = 0;  k< this->vector_number_; k++) {

                        sum = sum + this->vectors_[k][i]*multiplied.vectors_[j][k];
                        std::cout << sum << " = " << this->vectors_[k][i]<<" * "<<multiplied.vectors_[j][k]<<std::endl;
                    }

                temp.insert(j,i,sum);

                sum = 0;
                }
            }
            return temp;
        }

        void operator*= (Matrix& multiplied)
            {
            int sum=0;
            int i,j,k;
            my::Matrix temp(this->rows(),multiplied.cols());
            for (i = 0; i < multiplied.vector_number_; i++) {
                for (j = 0; j < this->rows_number_; j++) {

                    for (k = 0;  k< this->vector_number_; k++) {

                        sum = sum + this->vectors_[k][i]*multiplied.vectors_[j][k];
                        std::cout << sum << " = " << this->vectors_[k][i]<<" * "<<multiplied.vectors_[j][k]<<std::endl;
                    }

                temp.insert(j,i,sum);

                sum = 0;
                }
            }
            for(i=0;i<vector_number_;i++)
                vectors_[i]=temp.vectors_[i];
            vector_number_=multiplied.cols();
            rows_number_=temp.rows();

            }






             Matrix operator-(Matrix& added)
            {
                my::Matrix new_matrix(added.cols(),added.rows());
                int i;
                int j;
                for(i=0;i<this->cols();i++)
                    for(j=0;j<this->rows();j++)
                        new_matrix.insert(i,j,this->vectors_[i][j]-added.vectors_[i][j]);
                return new_matrix;
            }

            Matrix operator-(int & liczba)
            {
                my::Matrix new_matrix(this->cols(),this->rows());
                int i;
                int j;
                for(i=0;i<this->cols();i++)
                    for(j=0;j<this->rows();j++)
                        new_matrix.insert(i,j,this->vectors_[i][j]-liczba);
                return new_matrix;
            }

            bool operator ==(Matrix& checked)
            {
                int i,j;
                for(i=0;i<this->cols();i++)
                    for(j=0;j<this->rows();j++)
                        if(this->vectors_[i]!=checked.vectors_[i])
                            return false;
                return true;
            }

            bool operator !=(Matrix& checked)
            {
                int i,j;
                for(i=0;i<this->cols();i++)
                    for(j=0;j<this->rows();j++)
                        if(this->vectors_[i]!=checked.vectors_[i])
                            return true;
                return false;
            }

            void operator+=(Matrix& added)
            {

                int i;
                int j;
                for(i=0;i<this->cols();i++)
                    for(j=0;j<this->rows();j++)
                       this->insert(i,j,this->vectors_[i][j]+added.vectors_[i][j]);
            }

            void operator+=(int& liczba)
            {

                int i;
                int j;
                for(i=0;i<this->cols();i++)
                    for(j=0;j<this->rows();j++)
                       this->insert(i,j,this->vectors_[i][j]+liczba);
            }

            void operator-=(Matrix& added)
            {

                int i;
                int j;
                for(i=0;i<this->cols();i++)
                    for(j=0;j<this->rows();j++)
                       this->insert(i,j,this->vectors_[i][j]-added.vectors_[i][j]);
            }

            void operator-=(int & liczba)
            {

                int i;
                int j;
                for(i=0;i<this->cols();i++)
                    for(j=0;j<this->rows();j++)
                       this->insert(i,j,this->vectors_[i][j]-liczba);
            }
            void operator*=(int & liczba)
            {

                int i;
                int j;
                for(i=0;i<this->cols();i++)
                    for(j=0;j<this->rows();j++)
                       this->insert(i,j,this->vectors_[i][j]*liczba);
            }




    };


}

inline std::ostream & operator<<(std::ostream & out, my::Matrix matrix)
{
    matrix.print_matrix();
    return out;
}

inline std::istream& operator>>(std::istream & in, my::vector vector_)
{
    int i;
    std::string input;
    in >> input;
    for(i=0;i<vector_.size();i++)
        vector_.insert(i,input[2*i]-48);

    return in;
}


 inline std::ostream & operator<<(std::ostream & out, my::vector vector_)
{
    vector_.print_vector();
    return out;
}


#endif // CLASSES_H_INCLUDED
