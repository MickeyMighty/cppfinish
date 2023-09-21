#include "../class/Data.hpp"

static uintptr_t serialize(Data* ptr)
{
  return (reinterpret_cast<uintptr_t>(ptr));
}

//It is used to convert a pointer of some
//data type into a pointer of another data type
// even if the data types before and after conversion are different.
// It does not check if the pointer type and data pointed
// by the pointer is same or not.

static Data* deserialize(uintptr_t raw)
{
  return (reinterpret_cast<Data*>(raw));
}

int main()
{
  Data        data;
  Data*	      ptr;
  uintptr_t   raw;

  data.check_int = 42;
  data.check_str = "Loamar";
  data.check_char = 'L';

  std::cout << "-= BEFORE =-" << std::endl;
  std::cout << "data.check: " << data.check_int << std::endl;
  std::cout << "data.check_str: " << data.check_str << std::endl;
  std::cout << "data.char: " << data.check_char << std::endl;

  raw = serialize(&data);
  ptr = deserialize(raw);

  std::cout << "-= AFTER =-" << std::endl;
  std::cout << "data.check_int: " << data.check_int << std::endl;
  std::cout << "data.check_str: " << data.check_str << std::endl;
  std::cout << "data.char: " << data.check_char << std::endl;
  std::cout << "ptr->check_int: " << ptr->check_int << std::endl;
  std::cout << "ptr->check_str: " << ptr->check_str << std::endl;
  std::cout << "ptr->check_char: " << data.check_char << std::endl;
  std::cout << std::hex << std::uppercase << "Serialized data is " << raw << std::endl;

  if (&data != ptr) {
    std::cout << "They are different!" << std::endl;
    return 1;
  }
  return (0);
}
