#include <iostream>
#include <fstream>
#include <vector>

#pragma pack(push, 1) // Ensure no padding for the struct
struct BMPHeader {
    uint16_t fileType;        // File type ("BM")
    uint32_t fileSize;        // Size of the file (in bytes)
    uint16_t reserved1;       // Reserved (must be 0)
    uint16_t reserved2;       // Reserved (must be 0)
    uint32_t offsetData;      // Offset to start of pixel data
};

struct DIBHeader {
    uint32_t size;            // Size of this header (in bytes)
    int32_t width;            // Width of the bitmap in pixels
    int32_t height;           // Height of the bitmap in pixels
    uint16_t planes;          // Number of color planes
    uint16_t bitCount;        // Number of bits per pixel
    uint32_t compression;     // Compression type
    uint32_t imageSize;       // Size of the raw bitmap data (including padding)
    int32_t xPixelsPerMeter;  // Print resolution of the image (horizontal)
    int32_t yPixelsPerMeter;  // Print resolution of the image (vertical)
    uint32_t colorsUsed;      // Number of colors in the palette
    uint32_t importantColors; // Important colors count
};
#pragma pack(pop)

struct RGB {
    uint8_t blue;
    uint8_t green;
    uint8_t red;
};

using PixelArray = std::vector<std::vector<RGB> >;

PixelArray readBMP(const std::string& filePath, int& width, int& height) {
    // Open the BMP file in binary mode
    std::ifstream file(filePath, std::ios::binary);
    if (!file) {
        throw std::runtime_error("Error: Could not open the BMP file!");
    }

    // Read BMP Header
    BMPHeader bmpHeader;
    file.read(reinterpret_cast<char*>(&bmpHeader), sizeof(BMPHeader));

    // Check if it's a BMP file by checking the file type
    if (bmpHeader.fileType != 0x4D42) { // "BM" in hexadecimal
        throw std::runtime_error("Error: Not a valid BMP file!");
    }

    // Read DIB Header
    DIBHeader dibHeader;
    file.read(reinterpret_cast<char*>(&dibHeader), sizeof(DIBHeader));

    // Check if the BMP is 24-bit (no compression)
    if (dibHeader.bitCount != 24 || dibHeader.compression != 0) {
        throw std::runtime_error("Error: Only uncompressed 24-bit BMP files are supported.");
    }

    // Extract image dimensions
    width = dibHeader.width;
    height = dibHeader.height;

    // Move to the pixel data
    file.seekg(bmpHeader.offsetData, std::ios::beg);

    // Prepare the pixel array
    PixelArray pixels(height, std::vector<RGB>(width));

    // Row size is padded to the nearest 4-byte boundary
    int rowStride = (width * 3 + 3) & ~3;

    // Read pixel data row by row (BMP stores pixels bottom-to-top)
    for (int y = height - 1; y >= 0; --y) {
        file.read(reinterpret_cast<char*>(pixels[y].data()), width * 3);
        file.ignore(rowStride - width * 3); // Skip padding
    }

    // Close the file
    file.close();

    return pixels;
}

int main(int argc, char** argv) {
    // Check if image path is provided
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <bmp_image_path>" << std::endl;
        return -1;
    }

    int width, height;

    try {
        // Read the BMP image and get the pixel array
        PixelArray pixels = readBMP(argv[1], width, height);

        // Print RGB values (you can access the array directly)
        
        for (int y = 0; y < height; ++y) {
            for (int x = 0; x < width; ++x) {
                RGB pixel = pixels[y][x];
                std::cout << "{" << y << ", " << x << "): "
                          << "R=" << static_cast<int>(pixel.red) << " "
                          << "G=" << static_cast<int>(pixel.green) << " "
                          << "B=" << static_cast<int>(pixel.blue) << std::endl;
            }
        }
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return -1;
    }

    return 0;
}
