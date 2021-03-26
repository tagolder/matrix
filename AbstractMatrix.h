#include <iostream>
#include <vector>

class AbstractMatrix
{
    protected:
        std::vector<std::vector<int> > matrix;

        AbstractMatrix(uint n, uint m)
        {
            matrix.assign(n, std::vector<int> (m));
        }


    virtual void transposition() = 0;
    virtual void print() = 0;

    friend std::ostream &operator << (std::ostream &os, const AbstractMatrix & M)
    {
        uint n = M.matrix.size(), m = 0;
        if(n != 0)
        {
            m = M.matrix.at(0).size();
        }
        os << "   ";

        for(uint i = 0; i < m; i++)
        {
            os << "  " << i + 1;
        }
        os << std::endl;

        for(uint i = 0; i < n; i++)
        {
            os << i + 1 << "| ";
            for(uint j = 0; j < m; j++)
            {
                os << "  " << M.matrix.at(i).at(j);
            }
            os << std::endl;
        }

        return os;
    }

    friend std::istream & operator>> (std::istream &is, AbstractMatrix & M)
    {
        uint n = M.matrix.size(), m = 0;
        if(n != 0)
        {
            m = M.matrix.at(0).size();
        }
        for (uint i = 0; i < n; i++)
        {
            for (uint j = 0; j < m; j++)
            {
                is >> M.matrix[i][j];
            }
        }

        return is;
    }

    public:

    uint getN()
    {
        return matrix.size();
    }

    uint getM()
    {
        if(matrix.size() > 0) return matrix[0].size();
        return 0;
    }


    std::vector<std::vector<int> > getMatrix()
    {
        return matrix;
    }


    virtual ~AbstractMatrix() = default;

};