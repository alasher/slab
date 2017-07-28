//
//  matrix.hpp
//  slab
//
//  Created by Austin Lasher on 7/24/17.
//


//  I could easily use a pre-defined matrix library like GLM, but
//  the point of this project is for learning, and I thought it'd
//  be fun to implement these features myself.

#ifndef matrix_hpp
#define matrix_hpp

#include <cstddef>

namespace Slab
{
    class Matrix
    {
    public:
        Matrix(const size_t na = 4);
        Matrix(const Matrix &other);
        virtual ~Matrix();

        void load(const float *data[]);
        void load(const float *data);
        float get(int i, int j);
        void set(int i, int j, float val);
        void storeIdentity();
        void copy(const Matrix &other);

        static Matrix Identity(const size_t na);
        Matrix &operator=(const Matrix &other);
        Matrix &operator*=(const Matrix &other);
        Matrix &operator+=(const Matrix &other);
        Matrix &operator-=(const Matrix &other);
        Matrix operator*(const Matrix &other);
        Matrix operator+(const Matrix &other);
        Matrix operator-(const Matrix &other);

    private:
        float *m;
        const size_t n;

    };
}

#endif /* matrix_hpp */
