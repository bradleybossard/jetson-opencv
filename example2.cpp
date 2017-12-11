#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>

int main() {
  cv::Mat image0;

  image0.create(480, 640, CV_8UC1);

  // Initialize value in image to 0
  image0.setTo(0);

  cv::Point center(image0.cols / 2, image0.rows / 2);
  int radius = image0.rows / 2;
  cv::circle(image0, center, radius, 128, 3);

  // cv::Mat image1 = image0;  If we just use the original reference, both images will be the same
  
  cv::Mat image1;
  image0.copyTo(image1);  // Instead, but using copyTo, we make a copy of image0 at this point in time.

  cv::rectangle(image1,
      center - cv::Point(radius, radius),
      center + cv::Point(radius, radius),
      255, 
      3);

  cv::Mat image2;
  cv::cvtColor(image1, image2, CV_GRAY2BGR);

  int inscribed_radius = radius / sqrt(2);

  cv::Rect rect(
      center - cv::Point(inscribed_radius, inscribed_radius),
      center + cv::Point(inscribed_radius, inscribed_radius));

  cv::Mat roi = image2(rect);
  roi.setTo(cv::Scalar(0, 185, 118));

  // Add gradient for circle on image1
  for (int y = 0; y < image1.rows; y++) {
    uchar *row = image1.ptr<uchar>(y);
    for (int x = 0; x < image1.cols; x++) {
      if (row[x] == 128) {
        row[x] = x * y  * 255 / image1.total();
      }
    }
  }

  // Add gradient for square on image 2 
  for (int y = 0; y < image2.rows; y++) {
    cv::Vec3b *row = image2.ptr<cv::Vec3b>(y);
    for (int x = 0; x < image2.cols; x++) {
      if (row[x][1] == 185) {
        row[x] = cv::Vec3b(0, x * y * 255 / image1.total(), 118); 
      }
    }
  }

  cv::imshow("image2", image2);
  cv::imshow("image1", image1);
  cv::imshow("image0", image0);

  cv::waitKey();
}
