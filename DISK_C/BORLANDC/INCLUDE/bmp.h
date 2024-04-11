#ifndef _BITMAPINFOHEADER_
#define _BITMAPINFOHEADER_
typedef struct _tagBITMAPINFOHEADER {
    unsigned long       biSize;
    signed long         biWidth;
    signed long         biHeight;
    unsigned short      biPlanes;
    unsigned short      biBitCount;
    unsigned long       biCompression;
    unsigned long       biSizeImage;
    signed long         biXPelsPerMeter;
    signed long         biYPelsPerMeter;
    unsigned long       biClrUsed;
    unsigned long       biClrImportant;
} _BITMAPINFOHEADER;
#endif

#ifndef _BITMAPFILEHEADER_
#define _BITMAPFILEHEADER_
typedef struct  _tagBITMAPFILEHEADER {
    unsigned short    bfType;
    unsigned long     bfSize;
    unsigned short    bfReserved1;
    unsigned short    bfReserved2;
    unsigned long     bfOffBits;
}_BITMAPFILEHEADER;
#endif

#ifndef _RGBQUAD_
#define _RGBQUAD_
typedef struct tagRGBQUAD {
    unsigned char    rgbBlue;
    unsigned char    rgbGreen;
    unsigned char    rgbRed;
    unsigned char    rgbReserved;
} _RGBQUAD;
#endif

#ifndef _BMP_H_000001
#define _BMP_H_000001

unsigned char* ReadBMPFile(int* height, int* width, int* channels, char* path);
int SaveBMPFile(int height, int width, int channels, unsigned char* imageData, char* path);

#endif
