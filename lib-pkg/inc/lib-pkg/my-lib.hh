#ifndef MY_LIB_HH
#define MY_LIB_HH

namespace lib_pkg {
class Foo {
 public:
  Foo(int a);
  ~Foo() = default;

  void bar();

 private:
  int a_;
};

}  // namespace lib_pkg

#endif  // MY_LIB_HH