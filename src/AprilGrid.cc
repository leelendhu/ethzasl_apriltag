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


std::vector<cv::Vec3f> AprilGrid::objpoints(const float size, const float spacing) {
  

  float a;
  float b;
  float sum;
  a = size;
  b = spacing;
  float c = b*a;
  sum = c + a;

  std::vector<cv::Vec3f> objectpoints;
  
  for (int i = 0; i < AprilGrid::rows; i++){
    for (int j = 0; j < AprilGrid::columns; j++){
      std::vector<cv::Vec3f > obj;
      float toprightx = (float)j * sum;
      float toprighty = (float)i * sum;
      cv::Vec3f topright = {toprightx, toprighty, 0};
      cv::Vec3f topleft = {(float)j * sum + a, (float)i * sum, 0};
      cv::Vec3f bottomleft = {(float)j * sum + a, (float)i * sum + a, 0};
      cv::Vec3f bottomright = {(float)j * sum, (float)i * sum + a, 0};
      objectpoints.push_back(topright);
      objectpoints.push_back(topleft);
      objectpoints.push_back(bottomleft);
      objectpoints.push_back(bottomright);
    }
  }

 
  return objectpoints;
}




}

