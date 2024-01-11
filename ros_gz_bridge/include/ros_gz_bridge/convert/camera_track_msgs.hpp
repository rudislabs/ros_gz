// Copyright 2024 Rudis Laboratories LLC
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

#ifndef ROS_GZ_BRIDGE__CONVERT__CAMERA_TRACK_MSGS_HPP_
#define ROS_GZ_BRIDGE__CONVERT__CAMERA_TRACK_MSGS_HPP_

// Gazebo Msgs
#include <gz/msgs/cameratrack.pb.h>

// ROS 2 messages
#include <camera_track_msgs/msg/camera_track.hpp>

#include <ros_gz_bridge/convert_decl.hpp>

namespace ros_gz_bridge
{
// camertrack_msgs
template<>
void
convert_ros_to_gz(
  const camera_track_msgs::msg::CameraTrack & ros_msg,
  gz::msgs::CameraTrack & gz_msg);

template<>
void
convert_gz_to_ros(
  const gz::msgs::CameraTrack & gz_msg,
  camera_track_msgs::msg::CameraTrack & ros_msg);

}  // namespace ros_gz_bridge

#endif  // ROS_GZ_BRIDGE__CONVERT__CAMERA_TRACK_MSGS_HPP_
