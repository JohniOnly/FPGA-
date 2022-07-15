#include "bmp.h"

int bmp_bicubic(BMPImage *img, BMPImage *res);
int nearest(void *src, void *matDst, uint32_t width_in, uint32_t height_in, float mf_x, float mf_y);
int Range_DWT(void *src, void *data_out, uint32_t row, uint32_t col);
int Harr_DWT(void *data_in,  void *temp_data, void *data_out,  uint32_t width_out, uint32_t height_out);
int IDWT( void *temp2, void *temp1, void *dwt_mat, uint32_t row, uint32_t col);
