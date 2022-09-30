#include <memory>

#include "geometry_msgs/msg/twist.hpp"
#include "rclcpp/rclcpp.hpp"

using std::placeholders::_1;

class Sub : public rclcpp::Node {
 public:
  Sub() : Node("sub") {
    subscribtion_ = this->create_subscription<geometry_msgs::msg::Twist>(
        "cmd_linear", 10, std::bind(&Sub::topic_callback, this, _1));
  }
  ~Sub() = default;

 private:
  void topic_callback(const geometry_msgs::msg::Twist::SharedPtr msg) const {
    RCLCPP_INFO(this->get_logger(), "Set speed X: '%f'", msg->linear.x);
  }

  rclcpp::Subscription<geometry_msgs::msg::Twist>::SharedPtr subscribtion_;
};

int main(int argc, char* argv[]) {
  rclcpp::init(argc, argv);

  rclcpp::spin(std::make_shared<Sub>());

  rclcpp::shutdown();
  return 0;
}