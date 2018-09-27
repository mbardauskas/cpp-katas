#include <iostream>
#include <boost/algorithm/string.hpp>
#include "./greeter.h"

static inline int getTime() {
  time_t rawtime;
  struct tm * timeinfo;
  char buffer [2];

  time (&rawtime);
  timeinfo = localtime (&rawtime);

  strftime (buffer,2,"%H",timeinfo);
  puts(buffer);
  return std::stoi(buffer);
}

std::string Greeter::greet(std::string name) {
  boost::trim(name);
  return "Hello " + this->capitalize(name);
}

std::string Greeter::capitalize(std::string name) {
  name[0] = toupper(name[0]);
  return name;
}
