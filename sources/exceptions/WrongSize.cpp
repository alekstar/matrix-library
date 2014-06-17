#include "WrongSize.h"
using namespace MatrixExceptions;

WrongSize::WrongSize(const std::string& message) 
    :logic_error(message)
{}
WrongSize::WrongSize() 
    :logic_error("Wrong size for matrix.")
{}


