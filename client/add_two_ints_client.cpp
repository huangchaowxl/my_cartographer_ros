
#include <chrono>
#include <map>
#include <queue>
#include <string>
#include <vector>
#include <cstdlib>
#include <iostream>

#include "Eigen/Core"
#include "cartographer/common/configuration_file_resolver.h"
#include "cartographer/common/lua_parameter_dictionary.h"
#include "cartographer/common/make_unique.h"
#include "cartographer/common/mutex.h"
#include "cartographer/common/port.h"
#include "cartographer/common/rate_timer.h"
#include "cartographer/common/thread_pool.h"
#include "cartographer/common/time.h"
#include "cartographer/kalman_filter/pose_tracker.h"
#include "cartographer/mapping/global_trajectory_builder_interface.h"
#include "cartographer/mapping/map_builder.h"
#include "cartographer/mapping/proto/submaps.pb.h"
#include "cartographer/mapping/sensor_collator.h"
#include "cartographer/mapping_2d/global_trajectory_builder.h"
#include "cartographer/mapping_2d/local_trajectory_builder.h"
#include "cartographer/mapping_2d/sparse_pose_graph.h"
#include "cartographer/mapping_3d/global_trajectory_builder.h"
#include "cartographer/mapping_3d/local_trajectory_builder.h"
#include "cartographer/mapping_3d/local_trajectory_builder_options.h"
#include "cartographer/mapping_3d/sparse_pose_graph.h"
#include "cartographer/sensor/laser.h"
#include "cartographer/sensor/point_cloud.h"
#include "cartographer/sensor/proto/sensor.pb.h"
#include "cartographer/transform/rigid_transform.h"
#include "cartographer/transform/transform.h"
#include "cartographer_ros_msgs/FinishTrajectory.h"
#include "cartographer_ros_msgs/SubmapEntry.h"
#include "cartographer_ros_msgs/SubmapList.h"
#include "cartographer_ros_msgs/SubmapQuery.h"
#include "cartographer_ros_msgs/TrajectorySubmapList.h"
#include "gflags/gflags.h"
#include "glog/logging.h"
#include "nav_msgs/OccupancyGrid.h"
#include "nav_msgs/Odometry.h"
#include "ros/ros.h"
#include "ros/serialization.h"
#include "sensor_msgs/PointCloud2.h"
#include "tf2_eigen/tf2_eigen.h"
#include "tf2_ros/transform_broadcaster.h"
#include "tf2_ros/transform_listener.h"



constexpr char kFinishTrajectoryServiceName[] = "finish_trajectory";
DEFINE_string(configuration_directory, "",
              "First directory in which configuration files are searched, "
              "second is always the Cartographer installation to allow "
              "including files from there.");
DEFINE_string(configuration_basename, "",
              "Basename, i.e. not containing any directory prefix, of the "
              "configuration file.");
using namespace std;
int main(int argc, char** argv) {

     ros::init(argc, argv, "add_two_ints_client");
    cout<<"finish_trajectory"<<endl;
    ::ros::NodeHandle node_handle_;

    ros::ServiceClient client =node_handle_.serviceClient<cartographer_ros_msgs::FinishTrajectory>("finish_trajectory");

    ::cartographer_ros_msgs::FinishTrajectory srv;

    srv.request.stem = "my_slam";


    if (client.call(srv))
      {
        cout<<"send_request"<<endl;
      }
      else
      {
        cout<<"Failed to call service add_two_ints"<<endl;
        return 1;
      }

    return 0;
}























