#ifndef MY_LIB_HH
#define MY_LIB_HH

#include "rclcpp/rclcpp.hpp"

class Consol {
 public:
  Consol() = default;
  ~Consol() = default;

  void Run(int argc, char* argv[]);
};

#endif  // MY_LIB_HH