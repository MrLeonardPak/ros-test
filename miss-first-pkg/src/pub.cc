#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/bool.hpp"

#include <chrono>

using namespace std::chrono_literals;

class Pub : public rclcpp::Node {
 public:
  Pub() : Node("pub") {
    publisher_ = this->create_publisher<std_msgs::msg::Bool>("/test", 10);
    while (publisher_->get_subscription_count() == 0) {
      RCLCPP_WARN(this->get_logger(), "wait");
    }

    // rclcpp::sleep_for(5s);
  }
  ~Pub() = default;

  void Execute() {
    auto msg = std_msgs::msg::Bool();
    msg.set__data(true);

    publisher_->publish(msg);
    RCLCPP_INFO(this->get_logger(), "Set bool");
  }

 private:
  rclcpp::Publisher<std_msgs::msg::Bool>::SharedPtr publisher_;
};

int main(int argc, char* argv[]) {
  rclcpp::init(argc, argv);

  Pub node;

  node.Execute();

  rclcpp::shutdown();
  return 0;
}