#include <iostream>

// means that we can use object and variables inside iostream header file
using namespace std;

int main(int argc, char **argv)
{
  cout << "Hello World!" << endl;
  // also we can write cout like this, if we ommit using namespace std;
  // std::cout << "hello world!" << endl;
  return 0;
}
