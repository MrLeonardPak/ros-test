#include <memory>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/bool.hpp"

using std::placeholders::_1;

class Sub : public rclcpp::Node {
 public:
  Sub() : Node("sub") {
    subscribtion_ = this->create_subscription<std_msgs::msg::Bool>(
        "/test", 10, std::bind(&Sub::topic_callback, this, _1));
  }
  ~Sub() = default;

 private:
  void topic_callback(const std_msgs::msg::Bool::SharedPtr msg) const {
    if (msg->data) {
      RCLCPP_INFO(this->get_logger(), "True");
    } else {
      RCLCPP_INFO(this->get_logger(), "False");
    }
  }

  rclcpp::Subscription<std_msgs::msg::Bool>::SharedPtr subscribtion_;
};

int main(int argc, char* argv[]) {
  rclcpp::init(argc, argv);

  rclcpp::spin(std::make_shared<Sub>());

  rclcpp::shutdown();
  return 0;
}
