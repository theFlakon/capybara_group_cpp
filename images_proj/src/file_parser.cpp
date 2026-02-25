#include "file_parser.hpp"
#include <opencv2/opencv.hpp>

static cv::Mat matFromPixels(const std::vector<std::vector<Pixel>>& pixels);

void FileParser::parse(const std::string& path, Image& image)
{
    CHECK_COND(path.empty(), "Empty file");

    // cv - using sth from cv-biblio; Mat = matrix; cv::image read - func
    cv::Mat img = cv::imread(path, cv::IMREAD_COLOR);

    CHECK_COND(img.empty(), "Image is empty or cannot be loaded");

    size_t height = img.rows;
    size_t width = img.cols;

    std::vector<std::vector<Pixel>> imagePixels{};
    for(size_t idx = 0; idx < height; ++idx)
    {
        std::vector<Pixel> row{};

        for(size_t jdx = 0; jdx < width; ++jdx)
            row.push_back(Pixel(0, 0, 0));

        imagePixels.push_back(row);
    }

    // OpenCV: BGR -> Pixel: RGB (the sequence matters!)
    for(size_t row = 0; row < height; ++row)
    {
        for(size_t col = 0; col < width; ++col)
        {
            // vector from 3 bytes;  at = target (current elem - [row][col])
            cv::Vec3b pixelBGR = img.at<cv::Vec3b>(row, col);
            imagePixels[row][col] =
                Pixel(pixelBGR[2], pixelBGR[1], pixelBGR[0]);  // RGB
        }
    }

    image = Image(width, height, imagePixels);
}

void FileParser::writePixelsToFile(const std::string& path, Image& image)
{
    if (path.empty()) throw std::runtime_error("Empty path");
    cv::Mat m = matFromPixels(image.getData());
    if (m.empty()) throw std::runtime_error("Empty image to write");
    if (!cv::imwrite(path, m)) throw std::runtime_error("Failed to write image: " + path);
}

static cv::Mat matFromPixels(const std::vector<std::vector<Pixel>>& pixels)
{
    if (pixels.empty() || pixels[0].empty())
        return cv::Mat();

    int height = static_cast<int>(pixels.size());
    int width  = static_cast<int>(pixels[0].size());
    cv::Mat out(height, width, CV_8UC3);

    for (int r = 0; r < height; ++r)
    {
        const auto &row = pixels[r];
        for (int c = 0; c < width; ++c)
        {
            Pixel p(row[c]);
            auto red = static_cast<unsigned char>(p.getRed());
            auto green = static_cast<unsigned char>(p.getGreen());
            auto blue = static_cast<unsigned char>(p.getBlue());
            out.at<cv::Vec3b>(r, c) = cv::Vec3b(blue, green, red);
        }
    }
    return out;
}
