#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>

int main() {
  cv::Mat img = cv::imread("../lena.png");

  cv::Mat dst;
  cv::Sobel(img, dst, CV_32F, 1, 1);

  // Write out image with Sobel filter
  cv::imwrite("lena_sobel.png", dst);
/*
  cv::imshow("img", img);
  cv::imshow("dst", dst / 256);
  cv::waitKey();
*/
}
