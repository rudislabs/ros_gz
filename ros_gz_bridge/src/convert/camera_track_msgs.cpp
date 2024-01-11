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

#include "convert/utils.hpp"
#include "ros_gz_bridge/convert/camera_track_msgs.hpp"

namespace ros_gz_bridge
{

template<>
void
convert_ros_to_gz(
  const camera_track_msgs::msg::CameraTrack & ros_msg,
  gz::msgs::CameraTrack & gz_msg)
{
  convert_ros_to_gz(ros_msg.header, (*gz_msg.mutable_header()));
  switch (ros_msg.track_mode) {
    case camera_track_msgs::msg::CameraTrack::TRACK_MODE_TRACK:
      gz_msg.set_track_mode(gz::msgs::CameraTrack::TRACK);
      break;
    case camera_track_msgs::msg::CameraTrack::TRACK_MODE_FOLLOW:
      gz_msg.set_track_mode(gz::msgs::CameraTrack::FOLLOW);
      break;
    default:
      std::cerr << "Unsupported track mode [" << ros_msg.track_mode << "]\n";
  }
  gz_msg.set_target(ros_msg.target);
  convert_ros_to_gz(ros_msg.offset, (*gz_msg.mutable_offset()));
  gz_msg.set_pgain(ros_msg.pgain);

}

template<>
void
convert_gz_to_ros(
  const gz::msgs::CameraTrack & gz_msg,
  camera_track_msgs::msg::CameraTrack & ros_msg)
{
  convert_gz_to_ros(gz_msg.header(), ros_msg.header);
  if (gz_msg.track_mode() == gz::msgs::CameraTrack::TRACK) {
    ros_msg.track_mode = camera_track_msgs::msg::CameraTrack::TRACK_MODE_TRACK;
  } else if (gz_msg.track_mode() == gz::msgs::CameraTrack::FOLLOW) {
    ros_msg.track_mode = camera_track_msgs::msg::CameraTrack::TRACK_MODE_FOLLOW;
  } else {
    std::cerr << "Unsupported track mode [" <<
      gz_msg.track_mode() << "]" << std::endl;
  }

  ros_msg.target = gz_msg.target();
  convert_gz_to_ros(gz_msg.offset(), ros_msg.offset);
  ros_msg.pgain = gz_msg.pgain();

}

}  // namespace ros_gz_bridge
