#include <iostream>
#include <vector>
#include <random>
#include <map>
#include <algorithm>
#include <string>
#include <cmath>
#include <unordered_map>

//[' ', '.', ':', '+', '#', '@', '░', '▒', '▓', '█']
// 1. Захват из камеры (cv::VideoCapture)
// 2. Преобразование в ASCII и визуализация ASCII-символов в графическом виде
// 3. Рендер ASCII в изображение (cv::putText на фоне)
// 4. Вывод через виртуальную камеру (через v4l2 или OBS output)