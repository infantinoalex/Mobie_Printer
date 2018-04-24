#ifndef IMAGE_HPP
#define IMAGE_HPP

class Image
{
    public:
        Image();
        Image(int width, int height);
        ~Image();

        void SetImage(unsigned int image[], int width, int height);

        void SetImagePixelAtIndex(int indexX, int indexY, unsigned int pixel);

        int GetImageWidth();

        int GetImageHeight();

        unsigned int GetImagePixelAtIndex(int indexX, int indexY);

    private:
        unsigned int * _image;
        int _width;
        int _height;
};

#endif
