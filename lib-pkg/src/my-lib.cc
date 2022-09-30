#include "lib-pkg/my-lib.hh"

#include <iostream>

namespace lib_pkg {

Foo::Foo(int a) : a_(a) {}

void Foo::bar() {
  std::cout << "Here! a = " << a_ << std::endl;
}

}  // namespace lib_pkg