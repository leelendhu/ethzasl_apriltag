#ifndef APRILGRID_H
#define APRILGRID_H

#include <climits>
#include <cmath>
#include <stdio.h>
#include <vector>
#include <map>

#include "apriltags//TagDetection.h"

//using namespace std;

namespace AprilTags {


class AprilGrid {
public:

  int rows;
  int columns;
  float size;
  float spacing;
  int start_ID;
  AprilGrid(int rows1, int columns1, float size1,float spacing1, int start_ID1){
    rows = rows1;
    columns = columns1;
    size = size1;
    spacing = spacing1;
    start_ID = start_ID1;
  }

 
  
  std::vector<cv::Vec2f> imgpoints(const vector<AprilTags::TagDetection> detections, const int rows, const int columns, const int start_ID);

  std::vector<cv::Vec3f> objpoints(const vector<AprilTags::TagDetection> detections, const int rows, const int columns, const int start_ID, const float size, const float spacing);
  
  
};






} // namespace

#endif
