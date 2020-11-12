/*
 * @Description: IMU-lidar fusion for localization
 * @Author: Ge Yao
 * @Date: 2020-11-12 15:14:07
 */
#include <ros/ros.h>

#include "lidar_localization/global_defination/global_defination.h"

#include "lidar_localization/filtering/filtering_flow.hpp"

#include "glog/logging.h"

using namespace lidar_localization;

int main(int argc, char *argv[]) {
    google::InitGoogleLogging(argv[0]);
    FLAGS_log_dir = WORK_SPACE_PATH + "/Log";
    FLAGS_alsologtostderr = 1;

    ros::init(argc, argv, "filtering_node");
    ros::NodeHandle nh;

    std::shared_ptr<FilteringFlow> filtering_flow_ptr = std::make_shared<FilteringFlow>(nh);

    ros::Rate rate(100);
    while (ros::ok()) {
        ros::spinOnce();

        filtering_flow_ptr->Run();

        rate.sleep();
    }

    return 0;
}