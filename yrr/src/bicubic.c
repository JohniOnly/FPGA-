#include <math.h>
#include "stdio.h"
#include "bmp.h"


int  max(int a,int b);
int  min(int a,int b);
uint8_t u_cast(short a);
short __shout_cast(int a);
void choose(float f,short coeffs[4]);

static inline uint8_t *ptr_at(void *data, uint32_t width, uint32_t height, uint32_t x, uint32_t y)
{
    if (x >= width || y >= height) { return 0; }
    return ((uint8_t *)data) + (x + y * width) * 3;
}
static inline float *ptr_float(void *data, uint32_t width, uint32_t height, uint32_t x, uint32_t y)
{
    if (x >= width || y >= height) { return 0; }
    return ((float *)data) + (x + y * width) * 3;
}

int bmp_bicubic(BMPImage *img, BMPImage *res)
{
	
  uint32_t w = img->header.width_px;
  uint32_t h = img->header.height_px;
  uint32_t w_o = res->header.width_px;
  uint32_t h_o = res->header.height_px;	
  double scale_x = (double)w / w_o; 
  double scale_y = (double)h / h_o; 
	uint32_t i,j;
	for(j = 0;j < h_o; ++j)
	{
		float fy=(float)((j+0.5)*scale_y - 0.5);
		int sy= floor(fy);
		fy -= sy;
		sy = min(sy,h-3);
		sy = max(1, sy);
		short coeffsY[4];
    
		choose(fy,coeffsY);
		for (i = 0;i < w_o; ++i)
		{
			float fx = (float)((i + 0.5) * scale_x - 0.5);
			int sx = floor(fx);
			fx -= sx;
			sx = min(sx, w - 3);
			sx = max(1, sx);
			short coeffsX[4];
			choose(fx,coeffsX);
			Pixel *p0 =bmp_pixel_at(img,sx-1,sy-1);
			Pixel *p1 =bmp_pixel_at(img,sx-1,sy);
			Pixel *p2 =bmp_pixel_at(img,sx-1,sy+1);
			Pixel *p3 =bmp_pixel_at(img,sx-1,sy+2);
			Pixel *p4 =bmp_pixel_at(img,sx,sy-1);
			Pixel *p5 =bmp_pixel_at(img,sx,sy);
			Pixel *p6 =bmp_pixel_at(img,sx,sy+1);
			Pixel *p7 =bmp_pixel_at(img,sx,sy+2);
			Pixel *p8 =bmp_pixel_at(img,sx+1,sy-1);
			Pixel *p9 =bmp_pixel_at(img,sx+1,sy);
			Pixel *p10 =bmp_pixel_at(img,sx+1,sy+1);
			Pixel *p11 =bmp_pixel_at(img,sx+1,sy+2);
			Pixel *p12 =bmp_pixel_at(img,sx+2,sy-1);
			Pixel *p13 =bmp_pixel_at(img,sx+2,sy);
			Pixel *p14 =bmp_pixel_at(img,sx+2,sy+1);
			Pixel *p15 =bmp_pixel_at(img,sx+2,sy+2);
			Pixel *t=bmp_pixel_at(res,i,j);
			t->r =  u_cast(__shout_cast(((p0 ->r)* coeffsX[0] * coeffsY[0] +(p1 ->r)* coeffsX[0] *coeffsY[1]+(p2 ->r)* coeffsX[0] * coeffsY[2] + (p3 ->r)* coeffsX[0]*coeffsY[3]+(p4 ->r)* coeffsX[1]*coeffsY[0] +(p5 ->r)* coeffsX[1]* coeffsY[1]+(p6 ->r)* coeffsX[1] * coeffsY[2] + (p7 ->r) * coeffsX[1] * coeffsY[3]+(p8 ->r) * coeffsX[2] * coeffsY[0] + (p9 ->r) * coeffsX[2] * coeffsY[1]+(p10 ->r)* coeffsX[2] * coeffsY[2] + (p11 ->r)* coeffsX[2] * coeffsY[3]+(p12 ->r)* coeffsX[3] *coeffsY[0] +(p13 ->r)* coeffsX[3] * coeffsY[1]+(p14 ->r) * coeffsX[3] * coeffsY[2] +(p15 ->r)* coeffsX[3] * coeffsY[3])>>22));
			t->g = u_cast(__shout_cast(((p0 ->g)* coeffsX[0] * coeffsY[0] +(p1 ->g)* coeffsX[0] * coeffsY[1]+(p2 ->g)* coeffsX[0] * coeffsY[2] +(p3 ->g)* coeffsX[0] * coeffsY[3]+(p4 ->g)* coeffsX[1] * coeffsY[0] +(p5 ->g)* coeffsX[1] * coeffsY[1]+(p6 ->g)* coeffsX[1] * coeffsY[2] +(p7 ->g)* coeffsX[1] * coeffsY[3]+(p8 ->g)* coeffsX[2] * coeffsY[0] +(p9 ->g)* coeffsX[2] * coeffsY[1]+(p10 ->g)* coeffsX[2] * coeffsY[2] +(p11 ->g)* coeffsX[2] * coeffsY[3]+(p12 ->g)* coeffsX[3] * coeffsY[0] +(p13 ->g)* coeffsX[3] * coeffsY[1]+(p14 ->g)* coeffsX[3] * coeffsY[2] +(p15 ->g)* coeffsX[3] * coeffsY[3]) >>22)) ;
			t->b = u_cast(__shout_cast(((p0 ->b)* coeffsX[0] * coeffsY[0] +(p1 ->b)* coeffsX[0] * coeffsY[1]+(p2 ->b)* coeffsX[0] * coeffsY[2] +(p3 ->b)* coeffsX[0] * coeffsY[3]+(p4 ->b)* coeffsX[1] * coeffsY[0] +(p5 ->b)* coeffsX[1] * coeffsY[1]+(p6 ->b)* coeffsX[1] * coeffsY[2] +(p7 ->b)* coeffsX[1] * coeffsY[3]+(p8 ->b)* coeffsX[2] * coeffsY[0] +(p9 ->b)* coeffsX[2] * coeffsY[1]+(p10 ->b)* coeffsX[2] * coeffsY[2] +(p11 ->b)* coeffsX[2] * coeffsY[3]+(p12 ->b)* coeffsX[3] * coeffsY[0] +(p13 ->b)* coeffsX[3] * coeffsY[1]+(p14 ->b)* coeffsX[3] * coeffsY[2] +(p15 ->b)* coeffsX[3] * coeffsY[3]) >>22));
		}
		
	}
	printf("done!\n");
	return 0;
}

int max(int a,int b)
{
	if(a>b)
	{return a;
		}
	else return b;
}

int min(int a,int b)
{
	if(a<b)
	{return a;
		}
	else return b;
}

uint8_t u_cast(short a)
{
	if(a<0)
		return 0;
	else if(a >255 )
		return 255;
	else return (uint8_t)a;
}

short __shout_cast(int b)
{
    short max=32767;
		short min=-32768;
    if(b > max )
       return max;
    else if(b < min) 
       return min;  
		else return (short)b;
}

void choose(float fy,short coeffs[4])
{
	if(fy==0.25)
	{
		coeffs[0]=-216;
		coeffs[1]=1800;
		coeffs[2]=536;
		coeffs[3]=2048-coeffs[0]-coeffs[1]-coeffs[2];
	}
	else if(fy==0.75)
	{
		coeffs[0]=-72;
		coeffs[1]=536;
		coeffs[2]=1800;
		coeffs[3]=2048-coeffs[0]-coeffs[1]-coeffs[2];
	}
	else
	{
		coeffs[0]=-216;
		coeffs[1]=1800;
		coeffs[2]=536;
		coeffs[3]=2048-coeffs[0]-coeffs[1]-coeffs[2];
	}
}

int nearest(void *src, void *matDst, uint32_t width_in, uint32_t height_in, float mf_x, float mf_y) {
	float scale_x = 1.0 / mf_x;
	float scale_y = 1.0 / mf_y;
	for (int i = 0; i < width_in*2; ++i)
	{
		int sx = floor(i * scale_x);
		sx = min(sx, width_in - 1);
		for (int j = 0; j < height_in*2; ++j)
		{
			int sy = floor(j * scale_y);
			sy =  min(sy, height_in - 1);
            uint8_t *pix_matDst = ptr_at(matDst, width_in*2, height_in*2, i , j);
            uint8_t *pix_src = ptr_at(src, width_in, height_in, sx, sy);
            pix_matDst[0] = pix_src[0]; 
            pix_matDst[1] = pix_src[1];
            pix_matDst[2] = pix_src[2];
		}
	}
	return 0;
}
  //基于哈尔小波的图像小波分解
int Range_DWT(void *src, void *data_out, uint32_t row, uint32_t col)
{ 
	for (int i = 0; i < (row / 2); i++) {
		for (int j = 0; j < (col / 2); j++) {
        float *temp  = ptr_float(data_out, row, col, i , j);
        float *pix_0 = ptr_float(src, row, col, i,  j);
			temp[0] = pix_0[0] ;
            temp[1] = pix_0[1] ;
            temp[2] = pix_0[2] ;
		}
	}
	return 0;
}

int Harr_x(void *data_in, void *data_out, uint32_t width_out, uint32_t height_out)
{
    for (int j = 0; j < height_out; ++j)
	{
		for (int i = 0; i < width_out/2; ++i)
		{
        float *temp_l = ptr_float(data_out, width_out, height_out, i , j);
        float *temp_h = ptr_float(data_out, width_out, height_out, i + (width_out / 2) , j );
        uint8_t *pix_0 = ptr_at(data_in, width_out, height_out, 2 * i, j);
        uint8_t *pix_1 = ptr_at(data_in, width_out, height_out, 2 * i + 1,  j );

			for (int k = 0; k < 3; ++k)
			{
					temp_l[k] = ((pix_0[k] + pix_1[k]) / sqrt(2));
					temp_h[k] = ((pix_0[k] - pix_1[k]) / sqrt(2));  
			}
		}
	}
    return 0;
}

int Harr_y(void *data_in, void *data_out, uint32_t width_out, uint32_t height_out)
{
    for (int i = 0; i < width_out; ++i)
	{
		for (int j = 0; j < height_out/2; ++j)
		{
        float *temp_l = ptr_float(data_out, width_out, height_out, i , j);
        float *temp_h = ptr_float(data_out, width_out, height_out, i  , j+ (height_out / 2));
        float *pix_0 = ptr_float(data_in, width_out, height_out, i, 2 * j);
        float *pix_1 = ptr_float(data_in, width_out, height_out, i, 2 * j + 1);

			for (int k = 0; k < 3; ++k)
			{
					temp_l[k] = ((pix_0[k] + pix_1[k]) / sqrt(2));
					temp_h[k] = ((pix_0[k] - pix_1[k]) / sqrt(2));  
			}
		}
	}
    return 0;
}

//基于哈尔小波的图像小波分解
int Harr_DWT(void *data_in,  void *temp_data, void *data_out,  uint32_t width_out, uint32_t height_out)
{
 
    for (int j = 0; j < height_out; ++j)
	{
		for (int i = 0; i < width_out/2; ++i)
		{
        float *temp_l = ptr_float(temp_data, width_out, height_out, i , j);
        float *temp_h = ptr_float(temp_data, width_out, height_out, i + (width_out / 2) , j );
        uint8_t *pix_0 = ptr_at(data_in, width_out, height_out, 2 * i, j);
        uint8_t *pix_1 = ptr_at(data_in, width_out, height_out, 2 * i + 1,  j );

			for (int k = 0; k < 3; ++k)
			{
					temp_l[k] = ((pix_0[k] + pix_1[k]) / sqrt(2));
					temp_h[k] = ((pix_0[k] - pix_1[k]) / sqrt(2));  
			}
		}
	}
    for (int i = 0; i < width_out; ++i)
	{
		for (int j = 0; j < height_out/2; ++j)
		{
        float *temp_l = ptr_float(data_out, width_out, height_out, i , j);
        float *temp_h = ptr_float(data_out, width_out, height_out, i , j + (height_out / 2));
        float *pix_0f = ptr_float(temp_data, width_out, height_out, i, 2 * j);
        float *pix_1f = ptr_float(temp_data, width_out, height_out, i, 2 * j + 1);

			for (int k = 0; k < 3; ++k)
			{
					temp_l[k] = ((pix_0f[k] + pix_1f[k]) / sqrt(2));
					temp_h[k] = ((pix_0f[k] - pix_1f[k]) / sqrt(2));  
			}
		}
	}
	return 0;
}
//基于哈尔小波的图像小波重构
int IDWT( void *temp2, void *temp1, void *dwt_mat, uint32_t row, uint32_t col) 
{
 //   BMPImage *temp = bmp_create(row, col);
    float *temp_l;
    float *temp_h;
    float *pix_0;
    float *pix_1;
    uint8_t *out_l;
    uint8_t *out_h;
	//先做行逆变换
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < (col / 2); j++) {
            temp_l = ptr_float(temp1, row, col, i , 2 * j);
            temp_h = ptr_float(temp1, row, col, i , 2 * j + 1);

            pix_0 = ptr_float(temp2, row, col, i, j);
            pix_1 = ptr_float(temp2, row, col, i, j + (col / 2));
			temp_l[0] = __shout_cast((pix_0[0] + pix_1[0]) / sqrt(2));
            temp_l[1] = __shout_cast((pix_0[1] + pix_1[1]) / sqrt(2));
            temp_l[2] = __shout_cast((pix_0[2] + pix_1[2]) / sqrt(2));

			temp_h[0] = __shout_cast((pix_0[0] - pix_1[0]) / sqrt(2));
            temp_h[1] = __shout_cast((pix_0[1] - pix_1[1]) / sqrt(2));
            temp_h[2] = __shout_cast((pix_0[2] - pix_1[2]) / sqrt(2));
		}
	}
	//再做列还原
	for (int j = 0; j < col; j++) {
		for (int i = 0; i < (row / 2); i++) {
            out_l = ptr_at(dwt_mat, row, col, 2 * i, j);
            out_h = ptr_at(dwt_mat, row, col, 2 * i + 1, j);

            pix_0 = ptr_float(temp1, row, col, i, j);
            pix_1 = ptr_float(temp1, row, col, i + (row / 2), j);
			out_l[0] = u_cast((pix_0[0] + pix_1[0]) / sqrt(2));
            out_l[1] = u_cast((pix_0[1] + pix_1[1]) / sqrt(2));
            out_l[2] = u_cast((pix_0[2] + pix_1[2]) / sqrt(2));

			out_h[0] = u_cast((pix_0[0] - pix_1[0]) / sqrt(2));
            out_h[1] = u_cast((pix_0[1] - pix_1[1]) / sqrt(2));
            out_h[2] = u_cast((pix_0[2] - pix_1[2]) / sqrt(2));
		}
	}
 //   free(temp);
	return 0;
}
