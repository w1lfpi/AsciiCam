# ASCII Video Converter

Проект для преобразования видео в ASCII-графику с использованием OpenCV.

Автор: w1lfpi

---

## Требования
- CMake ≥ 3.10
- Компилятор C++ (GCC/Clang)
- OpenCV 4.9.0 (или новее)

---

## Установка

### 1. Установите OpenCV

#### Для macOS/Linux:
```bash
# Скачайте OpenCV
git clone https://github.com/opencv/opencv.git
cd opencv
git checkout 4.9.0  # или последнюю стабильную версию

# Соберите и установите
mkdir build && cd build
cmake -DCMAKE_BUILD_TYPE=Release -DBUILD_EXAMPLES=OFF -DBUILD_TESTS=OFF ..
make -j$(sysctl -n hw.ncpu)  # Для macOS
# ИЛИ make -j$(nproc)        # Для Linux
sudo make install

###Фикс для проблемы
zsh: abort      ./AsciiCam
install_name_tool -add_rpath /usr/local/lib ./AsciiCam
