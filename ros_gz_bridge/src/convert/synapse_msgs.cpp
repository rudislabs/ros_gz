// Copyright 2018 Open Source Robotics Foundation, Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "convert/utils.hpp"
#include "ros_gz_bridge/convert/synapse_msgs.hpp"

namespace ros_gz_bridge
{
template<>
void
convert_ros_to_gz(
  const synapse_msgs::msg::BezierTrajectory & ros_msg,
  gz::msgs::BezierTrajectory & gz_msg)
{
  convert_ros_to_gz(ros_msg.header, (*gz_msg.mutable_header()));

  gz_msg.set_sequence(ros_msg.sequence);

  gz_msg.set_time_start(ros_msg.time_start);

  gz_msg.set_time_stop(ros_msg.time_stop);

  for (auto i = 0u; i < ros_msg.x.size(); ++i) {
    gz_msg.add_x(ros_msg.x[i]);
  }

  for (auto i = 0u; i < ros_msg.y.size(); ++i) {
    gz_msg.add_y(ros_msg.y[i]);
  }
  for (auto i = 0u; i < ros_msg.z.size(); ++i) {
    gz_msg.add_z(ros_msg.z[i]);
  }

  for (auto i = 0u; i < ros_msg.yaw.size(); ++i) {
    gz_msg.add_yaw(ros_msg.yaw[i]);
  }

}

template<>
void
convert_gz_to_ros(
  const gz::msgs::BezierTrajectory & gz_msg,
  synapse_msgs::msg::BezierTrajectory & ros_msg)
{
  convert_gz_to_ros(gz_msg.header(), ros_msg.header);

  ros_msg.sequence = gz_msg.sequence();

  ros_msg.time_start = gz_msg.time_start();

  ros_msg.time_stop = gz_msg.time_stop();

  for (auto i = 0; i < gz_msg.x_size(); ++i) {
    ros_msg.x.push_back(gz_msg.x(i));
  }

  for (auto i = 0; i < gz_msg.y_size(); ++i) {
    ros_msg.y.push_back(gz_msg.y(i));
  }

  for (auto i = 0; i < gz_msg.z_size(); ++i) {
    ros_msg.z.push_back(gz_msg.z(i));
  }

  for (auto i = 0; i < gz_msg.yaw_size(); ++i) {
    ros_msg.yaw.push_back(gz_msg.yaw(i));
  }
}

}  // namespace ros_gz_bridge
