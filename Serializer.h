#include "Matrix.h"
#include <memory>
#include <fstream>

class Serializer
{
    public:
    void serialize(std::shared_ptr<AbstractMatrix> matrix, std::string fileName)
    {

        std::ofstream out;
        out.open(fileName);
        if(out.is_open())
        {
            uint n = matrix->getN();
            uint m = matrix->getM();
            out << n << " " << m << " ";
            for(uint i = 0; i < n; i++)
            {
                for(int j = 0; j < m; j++)
                {
                    out << matrix->getMatrix().at(i).at(j) << " ";
                }
            }
            out.close();
        }
    }

    void deserialize(std::shared_ptr<AbstractMatrix> matrix, std::string fileName)
    {

    }
};