#include <stdio.h>
#include <stdlib.h>
#include "bmp.h"
#include "bicubic.h"
#include <time.h>





int main(int argc, char const *argv[])
{
    if (argc < 3) {
        exit(1);
    }

    BMPImage *img = bmp_read(argv[1]);
    BMPImage *matDst = bmp_create(7680, 4320);
    BMPImage *res_2k = bmp_create(7680, 4320);

    BMPImage_float *temp_data = bmp_create_float(7680, 4320);
    BMPImage_float *temp_matDst = bmp_create_float(7680, 4320);
    BMPImage_float *temp_res_2k = bmp_create_float(7680, 4320);

    BMPImage *matDst2 = bmp_create(15360, 8640);
    BMPImage *res_4k = bmp_create(15360, 8640);/*  */
    BMPImage_float *temp_data4 = bmp_create_float(15360, 8640);
    BMPImage_float *temp_matDst2 = bmp_create_float(15360, 8640);
    BMPImage_float *temp_res_4k = bmp_create_float(15360, 8640);

		clock_t start, finish;
		double Total_time;
		start = clock();
    nearest(img->data, matDst->data, img->header.width_px, img->header.height_px, 2, 2);
    bmp_bicubic(img, res_2k);
    Harr_DWT(matDst->data, temp_data->data, temp_matDst->data, matDst->header.width_px, matDst->header.height_px);
    Harr_DWT(res_2k->data, temp_data->data, temp_res_2k->data, res_2k->header.width_px, res_2k->header.height_px);
    Range_DWT(temp_matDst->data, temp_res_2k->data, 1920, 1080);
    IDWT(temp_res_2k->data, temp_data->data, res_2k->data,  1920, 1080);
    

    nearest(res_2k->data, matDst2->data, res_2k->header.width_px, res_2k->header.height_px, 2, 2);
    bmp_bicubic(res_2k, res_4k);
    Harr_DWT(matDst2->data, temp_data4->data, temp_matDst2->data, matDst2->header.width_px, matDst2->header.height_px);
    Harr_DWT(res_4k->data, temp_data4->data, temp_res_4k->data, res_4k->header.width_px, res_4k->header.height_px);
    Range_DWT(temp_matDst2->data, temp_res_4k->data, 15360, 8640);
    IDWT(temp_res_4k->data, temp_data4->data, res_4k->data,  3840, 2160);
		Total_time = (double)(finish - start) / CLOCKS_PER_SEC;
		printf("%f seconds\n", Total_time);
    free(temp_data); free(temp_matDst); free(temp_res_2k); 
    free(temp_data4); free(temp_matDst2);free(temp_res_4k);
    return bmp_write(res_4k, argv[2]);
}




