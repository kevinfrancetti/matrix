/*
 * maintest.c
 *
 *  Created on: Feb 15, 2026
 *      Author: bomber
 */

#include <stdio.h>
#include "matrixcalc.h"

void test_multiplication_matrix() {

}

void test1() {

//	Mat4x4 m1 = mat4x4_identity();
//	Vec4 v1 = { 0, 1, 0, 1 };
//	mat4x4_print(&m1);
//	vec_print(&v1);
//	Mat4x4 m2 = mat4x4_translate_composed(m1, (Vec4 ) { 3, 1, 0, 1 });
//	mat4x4_print(&m2);
//	Vec4 v2 = mat4x4_vec4_mult(m2, (Vec4 ) { 1, 1, 1, 1 });
//	vec_print(&v2);
//	Mat4x4 m3 = mat4x4_translate_simple((Vec4 ) { 1, 2, 666, 1 });
//	mat4x4_print(&m3);

	Mat4x4 m4 = mat4x4_rotate(mat4x4_identity(), (Vec4 ) { 0, 0, 1, 1 }, degToRad(90));
	Vec4 v4 = mat4x4_vec4_mult(m4, (Vec4 ) { 1, 1, 0, 1 });
	vec_print(&v4);

}

void test_translate() {
	printf("==START==\n");
	Vec4 v_translation = (Vec4 ) { 1, -17, 34, 1 };
	printf("vec.x:= %f\n", v_translation.x);
	Mat4x4 m_transaltion = mat4x4_translate_simple(v_translation);
	Vec4 v1 = (Vec4 ) { 1, 1, 1, 1 };
	mat4x4_print(&m_transaltion);
	v1.x += 1;
	Vec4 v2 = mat4x4_vec4_mult(m_transaltion, v1);
	vec_print(&v2);
	printf("==END==\n");

}

void test_projection() {
	float l = -100;
	float r = 100;
	float b = -100;
	float t = 100;
	float n = 1;
	float f = 100;
	Mat4x4 m1 = mat4x4_projection(l, r, b, t, n, f);
	Vec4 v1 = mat4x4_vec4_mult(m1, (Vec4 ) { 1, 1, 1, 1 });
	Vec4 v2 = mat4x4_vec4_mult(m1, (Vec4 ) { 1, 0, 100, 1 });
	Vec4 v3 = mat4x4_vec4_mult(m1, (Vec4 ) { 50, -40, -50, 1 });
	Vec4 v4 = mat4x4_vec4_mult(m1, (Vec4 ) { 69, 15, -50, 1 });
	mat4x4_print(&m1);
	vec_print(&v1);
	vec_print(&v2);
	vec_print(&v3);
	vec_print(&v4);

}

int main() {
	printf("\nYOKLO\n");
	test_translate();
	test1();
	matrix_hello();
	test_projection();
	return 0;
}

