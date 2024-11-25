#include <string.h>
#include "config/video.h"
// Parameters:
//   w: width of the image
//   h: height of the image
//   durationMovie: duration in second of movie (colored image)
//   durationCredits: duration in second of credit (image Black/White)
//   unit: Unit of the output value. It could be 'bt' byte, 'ko' kilobits, 'mo' megabits, 'go' gigabits
// Return value
//   colored video size (based on the unit passed parametter)
float video(int w, int h, int durationMovie, int durationCredits, int fps, char* unit) {
   // YOUR CODE HERE - BEGIN
   // Number of bits used per pixel for a colored image (24 bits for RGB)
    float bitsPerColorPixel = 24;

    // Calculate the sizes for the colored video frames and black-and-white credits frames
    float videoSizeColor = w * h * bitsPerColorPixel * durationMovie * fps;
    float videoSizeBW = w * h * durationCredits * fps;

    // Calculate the total size in bits
    float totalSizeBits = videoSizeColor + videoSizeBW;

    // Variable to store the size in the requested unit
    float finalSize;

    // Convert the size based on the requested unit
    if (strcmp(unit, "bt") == 0) {
        finalSize = totalSizeBits; // Size in bits
    } else if (strcmp(unit, "ko") == 0) {
        finalSize = totalSizeBits / 1024; // Size in kilobits
    } else if (strcmp(unit, "mo") == 0) {
        finalSize = totalSizeBits / (1024 * 1024); // Size in megabits
    } else if (strcmp(unit, "go") == 0) {
        finalSize = totalSizeBits / (1024 * 1024 * 1024); // Size in gigabits
    } else {
        // If the unit is invalid, return an error value
        return -1.0f;
    }

    // Return the size in bytes
    return finalSize / 8;
   // YOUR CODE HERE - END
}