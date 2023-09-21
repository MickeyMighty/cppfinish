#include "../class/Convert.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout << "Error: the program must be called with a single argument" << std::endl;
        return 1;
    }
    Convert convert(argv[1]);
    convert.toChar();
    convert.toInt();
    convert.toFloat();
    convert.toDouble();
    return 0;
}
