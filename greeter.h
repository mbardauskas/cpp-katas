#include <string>

class Greeter {
  public:
    std::string greet(std::string name);

  private:
    std::string capitalize(std::string name);
};

