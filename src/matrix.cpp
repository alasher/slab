//
//  matrix.cpp
//  slab
//
//  Created by Austin Lasher on 7/24/17.
//
//

#include <slab/matrix.hpp>

namespace Slab {

    Matrix::Matrix(const size_t na) : n(na)
    {
        m = new float[n*n];

        for(int i = 0; i < n*n; i++)
        {
            m[i] = 0.0f;
        }
    }

    Matrix::Matrix(const Matrix &other) : n(other.n)
    {
        m = new float[n*n];
        if (n == other.n) copy(other);
    }

    Matrix::~Matrix()
    {
        delete[] m;
    }

    void Matrix::load(const float *data[])
    {
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                m[i*n + j] = data[i][j];
            }
        }
    }

    void Matrix::load(const float *data)
    {
        for(int i = 0; i < n*n; i++)
        {
            m[i] = data[i];
        }
    }

    float Matrix::get(int i, int j)
    {
        return m[i*n + j];
    }

    void Matrix::set(int i, int j, float val)
    {
        m[i*n + j] = val;
    }

    void Matrix::storeIdentity()
    {
        copy(Identity(n));
    }

    void Matrix::copy(const Slab::Matrix &other)
    {
        if (n != other.n) return;

        for(int i = 0; i < n*n; i++)
        {
            m[i] = other.m[i];
        }
    }

    Matrix Matrix::Identity(const size_t na)
    {
        Matrix new_mat(na);

        for(int i = 0; i < na*na; i += (na+1))
        {
            new_mat.m[i] = 1.0f;
        }

        return new_mat;
    }

    Matrix &Matrix::operator=(const Slab::Matrix &other)
    {
        for (int i = 0; i < n*n; ++i)
        {
            m[i] = other.m[i];
        }
        return *this;
    }

    Matrix &Matrix::operator*=(const Slab::Matrix &other)
    {
        Matrix tmp;

        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                tmp.m[i*n + j] = 0.0;
                for (int k = 0; k < n; k++)
                {
                    tmp.m[i*n + j] += m[i*n + k] * other.m[k*n + j];
                }
            }
        }

        copy(tmp);

        return *this;
    }

    Matrix &Matrix::operator+=(const Slab::Matrix &other)
    {
        for (int i = 0; i < n*n; ++i)
        {
            m[i] += other.m[i];
        }

        return *this;
    }

    Matrix &Matrix::operator-=(const Slab::Matrix &other)
    {
        for (int i = 0; i < n*n; ++i)
        {
            m[i] -= other.m[i];
        }

        return *this;
    }

    Matrix Matrix::operator*(const Slab::Matrix &other)
    {
        return Matrix(*this) *= other;
    }

    Matrix Matrix::operator+(const Slab::Matrix &other)
    {
        return Matrix(*this) += other;
    }

    Matrix Matrix::operator-(const Slab::Matrix &other)
    {
        return Matrix(*this) -= other;
    }
}
