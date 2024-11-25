#include <string.h>
#include "config/coloredBitmap.h"
// Parameters:
//   w: width of the image
//   h: height of the image
//   u: Unit of the output value. It could be 'bt' bits, 'ko' kilobits, 'mo' megabits, 'go' gigabits
// Return value
//   colored image size Bitmap (based on the unit passed parametter)
float coloredBitmap(int w, int h, char* unit) {
   // YOUR CODE HERE - BEGIN
    int bits_per_pixel = 24;
    float size_colored = w * h * bits_per_pixel;

    // Convert the size based on the specified unit
    if (strcmp(unit, "bt") == 0) {
        return size_colored;
    } 
    else if (strcmp(unit, "ko") == 0) {
        return (size_colored / 8) / 1024;
    } 
    else if (strcmp(unit, "mo") == 0) {
        return ((size_colored / 8) / 1024) / 1024;
    } 
    else if (strcmp(unit, "go") == 0) {
        return (((size_colored / 8) / 1024) / 1024) / 1024;
    } 
   // YOUR CODE HERE - END
   return 0;
}