#include "../class/Convert.hpp"

Convert::Convert(std::string input)
        :mInput(input)
        ,mDouble(std::strtod(input.c_str(), NULL))
        ,mChar(static_cast<char>(mDouble))
        ,mInt(static_cast<int>(mDouble))
        ,mFloat(static_cast<float>(mDouble))
{
}

Convert::Convert(const Convert& copy)
        :mInput(copy.mInput)
        ,mDouble(copy.mDouble)
        ,mChar(copy.mChar)
        ,mInt(copy.mInt)
        ,mFloat(copy.mFloat)
{
}

Convert&	Convert::operator=(const Convert& rhs)
{
  if (this != &rhs) {
		this->mDouble = rhs.mDouble;
		this->mChar = rhs.mChar;
	}
	return (*this);
}

Convert::~Convert() {}

void Convert::toChar() const {
  std::cout << "char: ";
  if (std::isnan(mDouble) || std::isinf(mDouble) || mDouble < 0 || mDouble > 127)
      std::cout << "impossible" << std::endl;
  else if (!std::isprint(mChar))
      std::cout << "Non displayable" << std::endl;
  else
      std::cout << "'" << mChar << "'" << std::endl;
}

void Convert::toInt() const {
  std::cout << "int: ";
  if (std::isnan(mDouble) || std::isinf(mDouble) || mDouble > std::numeric_limits<int>::max() || mDouble < std::numeric_limits<int>::min())
      std::cout << "impossible" << std::endl;
  else
      std::cout << mInt << std::endl;
}

void Convert::toFloat() const {
  std::cout << "float: ";
  if (std::isnan(mFloat))
      std::cout << "nanf" << std::endl;
  else if (std::isinf(mFloat))
      std::cout << ((mFloat < 0) ? "-" : "") << "inff" << std::endl;
  else
      std::cout << std::fixed << std::setprecision(1) << mFloat << "f" << std::endl;
}

void Convert::toDouble() const {
    std::cout << "double: ";
    if (std::isnan(mDouble)) {
        std::cout << "nan" << std::endl;
        return;
    }
    if (std::isinf(mDouble)) {
        if (mDouble < 0) {
            std::cout << "-inf" << std::endl;
        } else {
            std::cout << "+inf" << std::endl;
        }
        return;
    }
  std::cout << std::fixed << std::setprecision(1) << mDouble << std::endl;
}
