#include "hw.hpp"

#include <iostream>

#include <opencv2/opencv.hpp>

void HW4_1()
{
    cv::Mat img = cv::imread("white_hell.bmp");
    cv::Mat templ = cv::imread("white_puzzle.bmp");
    cv::Mat result;

    cv::matchTemplate(img, templ, result, cv::TM_CCORR_NORMED);
    cv::normalize(result, result, 0, 1, cv::NORM_MINMAX);

    double minVal; double maxVal; cv::Point minLoc; cv::Point maxLoc;
    cv::minMaxLoc(result, &minVal, &maxVal, &minLoc, &maxLoc);
    cv::Point matchLoc = maxLoc;
    cv::rectangle(img, matchLoc, cv::Point(matchLoc.x + templ.cols, matchLoc.y + templ.rows), cv::Scalar(0, 0, 255), 2, 8, 0);

    cv::imwrite("HW4-1.bmp", img);
    std::cout << "Output: HW4-1.bmp" << std::endl;
}

void HW4_2()
{
    cv::Mat img = cv::imread("muti_white.bmp");
    cv::Mat templ = cv::imread("white.bmp");
    cv::Mat result;

    cv::resize(templ, templ, cv::Size(235, 235));

    cv::matchTemplate(img, templ, result, cv::TM_CCORR_NORMED);
    cv::normalize(result, result, 0, 1, cv::NORM_MINMAX);

    for (int r = 0; r < result.rows; r++)
        for (int c = 0; c < result.cols; c++)
            if (result.at<float>(r, c) > 0.8)
            {
                cv::Point matchLoc(c, r);
                cv::rectangle(img, matchLoc, cv::Point(matchLoc.x + templ.cols, matchLoc.y + templ.rows), cv::Scalar(0, 0, 255), 2, 8, 0);
            }

    cv::imwrite("HW4-2.bmp", img);
    std::cout << "Output: HW4-2.bmp" << std::endl;
}
