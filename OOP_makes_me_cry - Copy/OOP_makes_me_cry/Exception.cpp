#include "Exception.h"


Exception::Exception(string msg) : runtime_error(msg) { this->msg = msg; }
string Exception::what() { return this->msg; }