#include "AbstractMatrix.h"
#include <cstdlib>

class Matrix : public AbstractMatrix
{
    public:
        Matrix(uint n, uint m): AbstractMatrix(n, m)
        {
            srand(time(0));

            for (uint i = 0; i < n; i++)
            {
                for (uint j = 0; j < m; j++)
                {
                    matrix[i][j] = rand() % 19 - 9;
                } 
            }
        }

        virtual void transposition()
        {
            uint n = matrix.size(), m = 0;
            if(n != 0)
            {
                m = matrix.at(0).size();
            }

            std::vector<std::vector<int> > v(m);

            if(n < m)matrix.resize(m);
            for(uint i = 0; i < m; i++)
            {

                v[i].resize(n);
                for(uint j = 0; j < n; j++)
                {
                    v[i][j] = matrix[j][i];
                }
            }
            matrix = v;
        }

        virtual void print() final 
        {
            operator << (std::cout, *(this));
        }

        virtual ~Matrix() = default;
};