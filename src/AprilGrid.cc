#include <iostream>

#include "apriltags/TagFamily.h"
#include "apriltags/AprilGrid.h"
#include "apriltags/TagDetector.h"

#include <Eigen/Dense>


/**

// example of instantiation of tag family:

#include "apriltags/TagFamily.h"
#include "apriltags/Tag36h11.h"
TagFamily *tag36h11 = new TagFamily(tagCodes36h11);

// available tag families:

#include "apriltags/Tag16h5.h"
#include "apriltags/Tag16h5_other.h"
#include "apriltags/Tag25h7.h"
#include "apriltags/Tag25h9.h"
#include "apriltags/Tag36h11.h"
#include "apriltags/Tag36h11_other.h"
#include "apriltags/Tag36h9.h"

*/


namespace AprilTags {



std::vector<cv::Vec2f> AprilGrid::imgpoints(const vector<AprilTags::TagDetection> detections, const int rows, const int columns, const int start_ID) {
  //cv::Mat imagef;
  //image.copyTo(imagef);

  //AprilTags::TagDetector tagDetector(TagCodes);
  //vector<TagDetection> detections = tagDetector.extractTags(imagef);
  //std::vector<TagDetection> detections = TagDetector::extractTags(image);

  std::vector<cv::Vec2f> imagepoints;
  int p = start_ID;
  int rows1 = rows;
  int cols = columns;

  int q = p + rows*cols;
  for (int h = p; h < q; h++){
    for (size_t i = 0; i < detections.size(); ++i) {
        const auto& det = detections[i];
        if (det.id == h){
            for (int j = 0; j < 4; ++j){
                cv::Vec2f currentpoint = {det.p[j].first,det.p[j].second};
                //std::cout << currentpoint << endl ;
                imagepoints.push_back(currentpoint);
                }
        
    }
  }    
  }

 
  return imagepoints;
}


std::vector<cv::Vec3f> AprilGrid::objpoints(const vector<AprilTags::TagDetection> detections, const int rows, const int columns, const int start_ID, const float size, const float spacing) {
  std::vector<cv::Vec3f> newobjectpoints;
  int p = start_ID;
  int rows1 = rows;
  int cols = columns;
  float a;
  float b;
  float sum;
  a = size;
  b = spacing;
  float c = b*a;
  sum = c + a;
  int q = p + rows*cols;
  for (int h = p; h < q; h++){
    for (size_t i = 0; i < detections.size(); ++i) {
        const auto& det = detections[i];
        if (det.id == h){
            int jdash = h % cols;
            int idash = (h-jdash)/cols;
            std::vector<cv::Vec3f > obj;
            float toprightx = (float)jdash * sum;
            float toprighty = (float)idash * sum;
            cv::Vec3f topright = {toprightx, toprighty, 0};
            cv::Vec3f topleft = {(float)jdash * sum + a, (float)idash * sum, 0};
            cv::Vec3f bottomleft = {(float)jdash * sum + a, (float)idash * sum + a, 0};
            cv::Vec3f bottomright = {(float)jdash * sum, (float)idash * sum + a, 0};
            newobjectpoints.push_back(topright);
            newobjectpoints.push_back(topleft);
            newobjectpoints.push_back(bottomleft);
            newobjectpoints.push_back(bottomright);
        
    }
  }    
  }
  return newobjectpoints;
}




}

