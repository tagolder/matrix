#include "Serializer.h"

int main()
{
    Matrix m(8,9);

    Serializer s;
    s.serialize(std::make_shared<AbstractMatrix>(m), "taya.txt");

}