#ifndef MATRIXCALC_H
#define MATRIXCALC_H

#include<math.h>


#define PI   3.14159265358979323846264338327950288
#define degToRad(angleInDegrees) ((angleInDegrees) * PI / 180.0)
#define radToDeg(angleInRadians) ((angleInRadians) * 180.0 / PI)

#define COL_MAJOR 0
#define ROW_MAJOR 1



typedef struct {
	float x;
	float y;
	float z;
	float w;
} Vec4;

typedef struct {
	float data[16];
} Mat4x4;


void matrix_hello();
void test_matrix();
void vec_print(const Vec4 *v);
void mat4x4_print(const Mat4x4 *m);
Mat4x4 mat4x4_mult(Mat4x4 m1, Mat4x4 m2);
Mat4x4 matnxn_mult(Mat4x4 m1, Mat4x4 m2, int n);
Vec4 mat4x4_vec4_mult(Mat4x4 m, Vec4 v);
Mat4x4 mat4x4_identity();
Mat4x4 mat4x4_zero();

Mat4x4 mat4x4_transpose(const Mat4x4 *m);
Mat4x4 mat4x4_translate_composed(Mat4x4 m, Vec4 v);
Mat4x4 mat4x4_translate_simple(Vec4 v);
Mat4x4 mat4x4_scale(Mat4x4 m, Vec4 v);
Mat4x4 mat4x4_rotate(Mat4x4 m, Vec4 v, float phi);
Mat4x4 mat4x4_projection(float l, float r, float b, float t, float n, float f);


#endif // MATRIXCALC_H
