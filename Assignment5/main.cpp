#include <iostream>
#include <opencv2/opencv.hpp>

std::vector<cv::Point2i> control_points;

void mouse_handler(int event, int x, int y, int flags, void* userdata)
{
    if  ( event == cv::EVENT_LBUTTONDOWN && control_points.size() < 4)
    {
        std::cout << "Left button of the mouse is clicked - position (" << x << ", " << y << ")" << '\n';
        control_points.emplace_back(x, y);
    }
}

void naive_bezier(const std::vector<cv::Point2i>& points, cv::Mat& window)
{
    auto& p_0 = points[0];
    auto& p_1 = points[1];
    auto& p_2 = points[2];
    auto& p_3 = points[3];

    for (double t = 0.0; t <= 1.0; t += 0.001)
    {
        auto point = std::pow(1-t, 3) * p_0 +
                     3 * t * std::pow(1 - t, 2) * p_1 +
                     3 * std::pow(t, 2) * (1 - t) * p_2 +
                     std::pow(t, 3) * p_3;

        window.at<cv::Vec3b>(point.y, point.x)[2] = 255;
    }
}

cv::Point2i recursive_bezier(const std::vector<cv::Point2i>& points, float t)
{
	// TODO - Implement this function
    // p_x= (1-t)p_0+t*p_1;
    if (points.size()==1){
        return points[0];
    }
    std::vector<cv::Point2i> newPoints(points.size()-1);
    for (int i=0; i<newPoints.size(); ++i){
        auto p_x=(1-t)*points[i]+t*points[i+1];
        newPoints[i]=p_x;
    }
    return recursive_bezier(newPoints,t);

}

void bezier(const std::vector<cv::Point2i>& points, cv::Mat& window)
{
	// TODO - Implement this function
    for (double t=0.0; t<=1.0;t+=0.001){
        auto point=recursive_bezier(points,t);
        window.at<cv::Vec3b>(point.y, point.x)[1] = 255;
    }
}

int main()
{
    cv::Mat window = cv::Mat(700, 700, CV_8UC3, cv::Scalar(0));
    cv::cvtColor(window, window, cv::COLOR_BGR2RGB);
    cv::namedWindow("Bezier Curve", cv::WINDOW_AUTOSIZE);

    cv::setMouseCallback("Bezier Curve", mouse_handler, nullptr);

    int key = -1;
    while(key != 27)
    {
        for (auto& point : control_points)
        {
            cv::circle(window, point, 3, {255, 255, 255}, 3);
        }

        if (control_points.size() == 4)
        {
            naive_bezier(control_points, window);
            bezier(control_points, window);

            cv::imshow("Bezier Curve", window);
            cv::imwrite("my_bezier_curve.png", window);
            key = cv::waitKey(0);

            return 0;
        }

        cv::imshow("Bezier Curve", window);
        key = cv::waitKey(20);
    }

    return 0;
}
