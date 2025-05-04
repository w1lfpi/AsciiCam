#include <opencv2/opencv.hpp>
#include <iostream>
#include <locale.h>
#include "../include/DedSecSymbols.h"

int main() {
    setlocale(LC_ALL, "en_US.UTF-8");
    auto& config = DedSec::Config::get_instance();

    cv::VideoCapture cap(0);
    if (!cap.isOpened()) {
        std::cerr << "ERROR: Camera breach failed!" << std::endl;
        return -1;
    }

    cv::Mat frame, gray, resized;
    cap >> frame;

    int target_height = static_cast<int>(
        (frame.rows * config.get_target_width() * config.get_font_aspect()) / frame.cols
    );

    while (true) {
        cap >> frame;
        if (frame.empty()) break;

        cv::cvtColor(frame, gray, cv::COLOR_BGR2GRAY);
        cv::resize(gray, resized, cv::Size(config.get_target_width(), target_height));

        std::string ascii_frame;
        for (int y = 0; y < resized.rows; ++y) {
            for (int x = 0; x < resized.cols; ++x) {
                uchar pixel = resized.at<uchar>(y, x);
                int raw_index = pixel * (config.get_symbol_count() - 1) / 255;
                int index = (raw_index < 0) ? 0 : 
                          ((raw_index >= config.get_symbol_count()) ? 
                           config.get_symbol_count() - 1 : raw_index);
                ascii_frame += config.get_symbols()[index];
            }
            ascii_frame += '\n';
        }

        const int font_size = 10;
        cv::Mat text_frame = cv::Mat::zeros(
            resized.rows * font_size * 2, 
            resized.cols * font_size, 
            CV_8UC3
        );

        for (int y = 0; y < resized.rows; ++y) {
            for (int x = 0; x < resized.cols; ++x) {
                cv::putText(
                    text_frame,
                    std::string(1, ascii_frame[y * (resized.cols + 1) + x]),
                    cv::Point(x * font_size, (y + 1) * font_size * 2),
                    cv::FONT_HERSHEY_SIMPLEX,
                    0.4,  //уменьшенный масштаб для лучшего отображения
                    cv::Scalar(255, 255, 255), //настройка цвета отображения по rgb
                    1
                );
            }
        }

        cv::imshow("ASCII Cam", text_frame);
        if (cv::waitKey(30) >= 0) break;
    }

    cap.release();
    cv::destroyAllWindows();
    return 0;
}