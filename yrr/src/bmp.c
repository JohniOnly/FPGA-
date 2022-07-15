#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "bmp.h"

BMPImage_float *bmp_create_float(uint32_t width, uint32_t height) {
    BMPImage_float *img = malloc(sizeof(BMPImage_float));
    if (!img) {
        printf("img create malloc fail!\n");
        return 0;
    }
    memset(img, 0, sizeof(BMPImage_float));
    img->data = (float *)malloc(width * height * 3 * 4);
    if (!img->data) {
        printf("img create data malloc fail!\n");
        return 0;
    }

    BMPHeader *h = &img->header;
    h->type = 0x4D42;
    h->size = width * height * 3 * 2 + 54;//注意：此处与int型下的BMPimage有区别，多乘了个2
    h->offset = 54;
    h->dib_header_size = 40;
    h->width_px = width;
    h->height_px = height;
    h->num_planes = 1;
    h->bits_per_pixel = 24*4;             //注意：此处与int型下的BMPimage有区别，多乘了个4
    h->compression = 0;
    h->image_size_bytes = width * height * 3 * 4;


    return img;
}


BMPImage *bmp_read(const char *filename)
{
    FILE *fp = fopen(filename, "r");
    if (!fp) {
        printf("file %s open failed!\n", filename);
        goto OPEN_FAIL;
    }

    BMPImage *img = malloc(sizeof(BMPImage));
    if (!img) {
        printf("image malloc fail!\n");
        goto IMG_MALLOC_FAIL;
    }

    fread(&img->header, 1, sizeof(BMPHeader), fp);
    if (img->header.type != 0x4D42) {
        printf("illegal bmp file %s", filename);
        goto NOT_BMP;
    }

    if (!img->header.image_size_bytes) {
        img->header.image_size_bytes = img->header.size - img->header.offset;
    }

    Pixel *pixel_data = malloc(img->header.image_size_bytes);
    if (!pixel_data) {
        printf("pixel data malloc fail!\n");
        goto PIX_MALLOC_FAIL;
    }

    rewind(fp);
    fread(pixel_data, 1, img->header.offset, fp);
    fread(pixel_data, 1,  img->header.image_size_bytes, fp);
    img->data = pixel_data;


    fclose(fp);

    return img;

PIX_MALLOC_FAIL:

NOT_BMP:
    free(img);
IMG_MALLOC_FAIL:
    fclose(fp);
OPEN_FAIL:
    return 0;
}


BMPImage *bmp_create(uint32_t width, uint32_t height) {
    BMPImage *img = malloc(sizeof(BMPImage));
    if (!img) {
        printf("img create malloc fail!\n");
        return 0;
    }
    memset(img, 0, sizeof(BMPImage));
    img->data = malloc(width * height * 3);
    if (!img->data) {
        printf("img create data malloc fail!\n");
        return 0;
    }

    BMPHeader *h = &img->header;
    h->type = 0x4D42; //文件类型
    h->size = width * height * 3 + 54;//该位图文件的大小（包含偏移量），用字节为单位ie
    h->offset = 54;             //说明从文件头开始到世纪的图像数据之间的字节偏移量
    h->dib_header_size = 40;   //位图信息头结构所需字数
    h->width_px = width;        //图像宽度，用像素为单位
    h->height_px = height;      //图像高度，以像素为单位 在此为正数，说明图像是倒图
    h->num_planes = 1;          //为目标设备说明颜色平面数
    h->bits_per_pixel = 24;     //说明比特数/像素，其值为1、4、8、16、24或32
    h->compression = 0;         //说明压缩类型，0 不压缩
    h->image_size_bytes = width * height * 3; //说明图像大小，以字节为单位


    return img;
}


int32_t   bmp_write(BMPImage *img, const char *filename)
{
    FILE *fp = fopen(filename, "wb+");
    if (!fp) {
        printf("open/create file %s failed!\n", filename);
        return -1;
    }

    fwrite(&img->header, 1, sizeof(BMPHeader), fp);
    fwrite(img->data, 1, img->header.image_size_bytes, fp);
    return 0;
}

Pixel    *bmp_pixel_at(BMPImage *img, uint32_t x, uint32_t y)
{
    if (x >= img->header.width_px || y >= img->header.height_px) {
        return 0;
    }
    return (Pixel *)((void *)img->data + (x + y * img->header.width_px) * img->header.bits_per_pixel / 8);
}

void bmp_print_header(BMPImage *img)
{
    BMPHeader *h = &img->header;
    printf("type=%x\n", h->type);             
    printf("size=%u\n", h->size);            
    printf("reserved1=%u\n", h->reserved1);       
    printf("reserved2=%u\n", h->reserved2);       
    printf("offset=%u\n", h->offset);           
    printf("dib_header_size=%u\n", h->dib_header_size);  
    printf("width_px=%d\n", h->width_px);        
    printf("height_px=%d\n", h->height_px);       
    printf("num_planes=%u\n", h->num_planes);       
    printf("bits_per_pixel=%u\n", h->bits_per_pixel);  
    printf("compression=%u\n", h->compression);     
    printf("image_size_bytes=%u\n", h->image_size_bytes);
    printf("x_resolution_ppm=%d\n", h->x_resolution_ppm);
    printf("y_resolution_ppm=%d\n", h->y_resolution_ppm);
    printf("num_colors=%u\n", h->num_colors);      
    printf("important_colors=%u\n", h->important_colors);
}
