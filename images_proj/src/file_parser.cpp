#include "file_parser.hpp"
#include <opencv2/opencv.hpp>

void FileParser::parse(std::ifstream& file, Image& image)
{
    CHECK_COND(!file.is_open(), "File is not open");

    std::string path{};
    file >> path;  // path (ex: "img.png")

    CHECK_COND(path.empty(), "Empty file");

    // cv - using sth from cv-biblio; Mat = matrix; cv::image read - func
    cv::Mat img = cv::imread(path, cv::IMREAD_COLOR);

    CHECK_COND(img.empty(), "Image is empty or cannot be loaded");

    size_t height = img.rows;
    size_t width = img.cols;

    std::vector<std::vector<Pixel>> imagePixels{};
    /* [ Pixel Pixel Pixel ], [ Pixel Pixel Pixel ]  */
    /* [ Pixel Pixel Pixel ], [ Pixel Pixel Pixel ]  */
    /* [ Pixel Pixel Pixel ], [ Pixel Pixel Pixel ]  */
    // creating:
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
