#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/bool.hpp"

class Pub : public rclcpp::Node {
 public:
  Pub() : Node("pub") {
    publisher_ = this->create_publisher<std_msgs::msg::Bool>("test", 10);
  }
  ~Pub() = default;

  void Execute() {
    auto msg = std_msgs::msg::Bool();
    msg.set__data(true);
    publisher_->publish(msg);
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