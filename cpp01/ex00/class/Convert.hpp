#ifndef CONVERT_CLASS
#define CONVERT_CLASS

#include <iostream>
#include <limits>
#include <string>
#include <cmath>
#include <cstdlib>
#include <iomanip>

class Convert
{
private:
  const std::string	mInput;
  double	mDouble;
  char	mChar;
  int		mInt;
  float	mFloat;

public:
	Convert(std::string mInput);
	Convert(const Convert& other);
	virtual ~Convert();

	void	toChar() const;
	void	toInt() const;
	void	toFloat() const;
	void	toDouble() const;

	Convert();
	Convert&	operator=(const Convert& rhs);
};

#endif
