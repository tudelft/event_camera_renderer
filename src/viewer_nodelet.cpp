// -*-c++-*---------------------------------------------------------------------------------------
// Copyright 2022 Bernd Pfrommer <bernd.pfrommer@gmail.com>
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

#include <nodelet/nodelet.h>
#include <ros/ros.h>

#include <memory>

#include "event_array_viewer/viewer_ros1.h"

namespace event_array_viewer
{
class ViewerNodelet : public nodelet::Nodelet
{
public:
  void onInit() override
  {
    nh_ = getPrivateNodeHandle();
    viewer_ = std::make_shared<Viewer>(nh_);
  }

private:
  // ------ variables --------
  std::shared_ptr<Viewer> viewer_;
  ros::NodeHandle nh_;
};
}  // namespace event_array_viewer

#include <pluginlib/class_list_macros.h>
PLUGINLIB_EXPORT_CLASS(event_array_viewer::ViewerNodelet, nodelet::Nodelet)
