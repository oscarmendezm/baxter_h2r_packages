#ifndef _VIENNACL_MATRIX_SOLVE_ROW_COL_SOURCE_HPP_
#define _VIENNACL_MATRIX_SOLVE_ROW_COL_SOURCE_HPP_
//Automatically generated file from aux-directory, do not edit manually!
namespace viennacl
{
 namespace linalg
 {
  namespace kernels
  {
const char * const matrix_solve_row_col_align1_upper_trans_solve = 
"// file automatically generated - do not edit!\n"
"// inplace solve A \\ B^T\n"
"// matrix layouts: A...row_major, B...col_major\n"
"__kernel void upper_trans_solve(\n"
"          __global const float * A,\n"
"          unsigned int A_rows,\n"
"          unsigned int A_cols,\n"
"          unsigned int A_internal_rows,\n"
"          unsigned int A_internal_cols,\n"
"          __global float * B,  \n"
"          unsigned int B_rows,\n"
"          unsigned int B_cols,\n"
"          unsigned int B_internal_rows,\n"
"          unsigned int B_internal_cols)\n"
"{ \n"
"  float temp; \n"
"  for (int row = A_rows-1; row > -1; --row) \n"
"  { \n"
"    barrier(CLK_GLOBAL_MEM_FENCE); \n"
"    if (get_local_id(0) == 0) \n"
"      B[row * B_internal_rows + get_group_id(0)] /= A[row + row*A_internal_cols]; \n"
"    barrier(CLK_GLOBAL_MEM_FENCE); \n"
"      temp = B[row * B_internal_rows + get_group_id(0)]; \n"
"    //eliminate column of op(A) with index 'row' in parallel: \n"
"    for  (int elim = get_local_id(0); elim < row; elim += get_local_size(0)) \n"
"      B[elim * B_internal_rows + get_group_id(0)] -= temp * A[elim * A_internal_cols + row];\n"
"   }\n"
"}\n"
; //matrix_solve_row_col_align1_upper_trans_solve

const char * const matrix_solve_row_col_align1_trans_upper_trans_solve = 
"// file automatically generated - do not edit!\n"
"// inplace solve A^T \\ B^T\n"
"// matrix layouts: A...row_major, B...col_major\n"
"__kernel void trans_upper_trans_solve(\n"
"          __global const float * A,\n"
"          unsigned int A_rows,\n"
"          unsigned int A_cols,\n"
"          unsigned int A_internal_rows,\n"
"          unsigned int A_internal_cols,\n"
"          __global float * B,  \n"
"          unsigned int B_rows,\n"
"          unsigned int B_cols,\n"
"          unsigned int B_internal_rows,\n"
"          unsigned int B_internal_cols)\n"
"{ \n"
"  float temp; \n"
"  for (int row = A_rows-1; row > -1; --row) \n"
"  { \n"
"    barrier(CLK_GLOBAL_MEM_FENCE); \n"
"    if (get_local_id(0) == 0) \n"
"      B[row * B_internal_rows + get_group_id(0)] /= A[row + row*A_internal_cols]; \n"
"    barrier(CLK_GLOBAL_MEM_FENCE); \n"
"      temp = B[row * B_internal_rows + get_group_id(0)]; \n"
"    //eliminate column of op(A) with index 'row' in parallel: \n"
"    for  (int elim = get_local_id(0); elim < row; elim += get_local_size(0)) \n"
"      B[elim * B_internal_rows + get_group_id(0)] -= temp * A[elim + row * A_internal_cols];\n"
"   }\n"
"}\n"
; //matrix_solve_row_col_align1_trans_upper_trans_solve

const char * const matrix_solve_row_col_align1_unit_lower_solve = 
"// file automatically generated - do not edit!\n"
"// inplace solve A \\ B\n"
"// matrix layouts: A...row_major, B...col_major\n"
"__kernel void unit_lower_solve(\n"
"          __global const float * A,\n"
"          unsigned int A_rows,\n"
"          unsigned int A_cols,\n"
"          unsigned int A_internal_rows,\n"
"          unsigned int A_internal_cols,\n"
"          __global float * B,  \n"
"          unsigned int B_rows,\n"
"          unsigned int B_cols,\n"
"          unsigned int B_internal_rows,\n"
"          unsigned int B_internal_cols)\n"
"{ \n"
"  float temp; \n"
"  for (int row = 0; row < A_rows; ++row) \n"
"  { \n"
"    barrier(CLK_GLOBAL_MEM_FENCE); \n"
"      temp = B[row + get_group_id(0) * B_internal_rows]; \n"
"    //eliminate column of op(A) with index 'row' in parallel: \n"
"    for  (int elim = row + get_local_id(0) + 1; elim < A_rows; elim += get_local_size(0)) \n"
"      B[elim + get_group_id(0) * B_internal_rows] -= temp * A[elim * A_internal_cols + row];\n"
"   }\n"
"}\n"
; //matrix_solve_row_col_align1_unit_lower_solve

const char * const matrix_solve_row_col_align1_trans_unit_upper_trans_solve = 
"// file automatically generated - do not edit!\n"
"// inplace solve A^T \\ B^T\n"
"// matrix layouts: A...row_major, B...col_major\n"
"__kernel void trans_unit_upper_trans_solve(\n"
"          __global const float * A,\n"
"          unsigned int A_rows,\n"
"          unsigned int A_cols,\n"
"          unsigned int A_internal_rows,\n"
"          unsigned int A_internal_cols,\n"
"          __global float * B,  \n"
"          unsigned int B_rows,\n"
"          unsigned int B_cols,\n"
"          unsigned int B_internal_rows,\n"
"          unsigned int B_internal_cols)\n"
"{ \n"
"  float temp; \n"
"  for (int row = A_rows-1; row > -1; --row) \n"
"  { \n"
"    barrier(CLK_GLOBAL_MEM_FENCE); \n"
"      temp = B[row * B_internal_rows + get_group_id(0)]; \n"
"    //eliminate column of op(A) with index 'row' in parallel: \n"
"    for  (int elim = get_local_id(0); elim < row; elim += get_local_size(0)) \n"
"      B[elim * B_internal_rows + get_group_id(0)] -= temp * A[elim + row * A_internal_cols];\n"
"   }\n"
"}\n"
; //matrix_solve_row_col_align1_trans_unit_upper_trans_solve

const char * const matrix_solve_row_col_align1_trans_upper_solve = 
"// file automatically generated - do not edit!\n"
"// inplace solve A^T \\ B\n"
"// matrix layouts: A...row_major, B...col_major\n"
"__kernel void trans_upper_solve(\n"
"          __global const float * A,\n"
"          unsigned int A_rows,\n"
"          unsigned int A_cols,\n"
"          unsigned int A_internal_rows,\n"
"          unsigned int A_internal_cols,\n"
"          __global float * B,  \n"
"          unsigned int B_rows,\n"
"          unsigned int B_cols,\n"
"          unsigned int B_internal_rows,\n"
"          unsigned int B_internal_cols)\n"
"{ \n"
"  float temp; \n"
"  for (int row = A_rows-1; row > -1; --row) \n"
"  { \n"
"    barrier(CLK_GLOBAL_MEM_FENCE); \n"
"    if (get_local_id(0) == 0) \n"
"      B[row + get_group_id(0) * B_internal_rows] /= A[row + row*A_internal_cols]; \n"
"    barrier(CLK_GLOBAL_MEM_FENCE); \n"
"      temp = B[row + get_group_id(0) * B_internal_rows]; \n"
"    //eliminate column of op(A) with index 'row' in parallel: \n"
"    for  (int elim = get_local_id(0); elim < row; elim += get_local_size(0)) \n"
"      B[elim + get_group_id(0) * B_internal_rows] -= temp * A[elim + row * A_internal_cols];\n"
"   }\n"
"}\n"
; //matrix_solve_row_col_align1_trans_upper_solve

const char * const matrix_solve_row_col_align1_unit_lower_trans_solve = 
"// file automatically generated - do not edit!\n"
"// inplace solve A \\ B^T\n"
"// matrix layouts: A...row_major, B...col_major\n"
"__kernel void unit_lower_trans_solve(\n"
"          __global const float * A,\n"
"          unsigned int A_rows,\n"
"          unsigned int A_cols,\n"
"          unsigned int A_internal_rows,\n"
"          unsigned int A_internal_cols,\n"
"          __global float * B,  \n"
"          unsigned int B_rows,\n"
"          unsigned int B_cols,\n"
"          unsigned int B_internal_rows,\n"
"          unsigned int B_internal_cols)\n"
"{ \n"
"  float temp; \n"
"  for (int row = 0; row < A_rows; ++row) \n"
"  { \n"
"    barrier(CLK_GLOBAL_MEM_FENCE); \n"
"      temp = B[row * B_internal_rows + get_group_id(0)]; \n"
"    //eliminate column of op(A) with index 'row' in parallel: \n"
"    for  (int elim = row + get_local_id(0) + 1; elim < A_rows; elim += get_local_size(0)) \n"
"      B[elim * B_internal_rows + get_group_id(0)] -= temp * A[elim * A_internal_cols + row];\n"
"   }\n"
"}\n"
; //matrix_solve_row_col_align1_unit_lower_trans_solve

const char * const matrix_solve_row_col_align1_trans_unit_upper_solve = 
"// file automatically generated - do not edit!\n"
"// inplace solve A^T \\ B\n"
"// matrix layouts: A...row_major, B...col_major\n"
"__kernel void trans_unit_upper_solve(\n"
"          __global const float * A,\n"
"          unsigned int A_rows,\n"
"          unsigned int A_cols,\n"
"          unsigned int A_internal_rows,\n"
"          unsigned int A_internal_cols,\n"
"          __global float * B,  \n"
"          unsigned int B_rows,\n"
"          unsigned int B_cols,\n"
"          unsigned int B_internal_rows,\n"
"          unsigned int B_internal_cols)\n"
"{ \n"
"  float temp; \n"
"  for (int row = A_rows-1; row > -1; --row) \n"
"  { \n"
"    barrier(CLK_GLOBAL_MEM_FENCE); \n"
"      temp = B[row + get_group_id(0) * B_internal_rows]; \n"
"    //eliminate column of op(A) with index 'row' in parallel: \n"
"    for  (int elim = get_local_id(0); elim < row; elim += get_local_size(0)) \n"
"      B[elim + get_group_id(0) * B_internal_rows] -= temp * A[elim + row * A_internal_cols];\n"
"   }\n"
"}\n"
; //matrix_solve_row_col_align1_trans_unit_upper_solve

const char * const matrix_solve_row_col_align1_trans_unit_lower_trans_solve = 
"// file automatically generated - do not edit!\n"
"// inplace solve A^T \\ B^T\n"
"// matrix layouts: A...row_major, B...col_major\n"
"__kernel void trans_unit_lower_trans_solve(\n"
"          __global const float * A,\n"
"          unsigned int A_rows,\n"
"          unsigned int A_cols,\n"
"          unsigned int A_internal_rows,\n"
"          unsigned int A_internal_cols,\n"
"          __global float * B,  \n"
"          unsigned int B_rows,\n"
"          unsigned int B_cols,\n"
"          unsigned int B_internal_rows,\n"
"          unsigned int B_internal_cols)\n"
"{ \n"
"  float temp; \n"
"  for (int row = 0; row < A_rows; ++row) \n"
"  { \n"
"    barrier(CLK_GLOBAL_MEM_FENCE); \n"
"      temp = B[row * B_internal_rows + get_group_id(0)]; \n"
"    //eliminate column of op(A) with index 'row' in parallel: \n"
"    for  (int elim = row + get_local_id(0) + 1; elim < A_rows; elim += get_local_size(0)) \n"
"      B[elim * B_internal_rows + get_group_id(0)] -= temp * A[elim + row * A_internal_cols];\n"
"   }\n"
"}\n"
; //matrix_solve_row_col_align1_trans_unit_lower_trans_solve

const char * const matrix_solve_row_col_align1_lower_trans_solve = 
"// file automatically generated - do not edit!\n"
"// inplace solve A \\ B^T\n"
"// matrix layouts: A...row_major, B...col_major\n"
"__kernel void lower_trans_solve(\n"
"          __global const float * A,\n"
"          unsigned int A_rows,\n"
"          unsigned int A_cols,\n"
"          unsigned int A_internal_rows,\n"
"          unsigned int A_internal_cols,\n"
"          __global float * B,  \n"
"          unsigned int B_rows,\n"
"          unsigned int B_cols,\n"
"          unsigned int B_internal_rows,\n"
"          unsigned int B_internal_cols)\n"
"{ \n"
"  float temp; \n"
"  for (int row = 0; row < A_rows; ++row) \n"
"  { \n"
"    barrier(CLK_GLOBAL_MEM_FENCE); \n"
"    if (get_local_id(0) == 0) \n"
"      B[row * B_internal_rows + get_group_id(0)] /= A[row + row*A_internal_cols]; \n"
"    barrier(CLK_GLOBAL_MEM_FENCE); \n"
"      temp = B[row * B_internal_rows + get_group_id(0)]; \n"
"    //eliminate column of op(A) with index 'row' in parallel: \n"
"    for  (int elim = row + get_local_id(0) + 1; elim < A_rows; elim += get_local_size(0)) \n"
"      B[elim * B_internal_rows + get_group_id(0)] -= temp * A[elim * A_internal_cols + row];\n"
"   }\n"
"}\n"
; //matrix_solve_row_col_align1_lower_trans_solve

const char * const matrix_solve_row_col_align1_upper_solve = 
"// file automatically generated - do not edit!\n"
"// inplace solve A \\ B\n"
"// matrix layouts: A...row_major, B...col_major\n"
"__kernel void upper_solve(\n"
"          __global const float * A,\n"
"          unsigned int A_rows,\n"
"          unsigned int A_cols,\n"
"          unsigned int A_internal_rows,\n"
"          unsigned int A_internal_cols,\n"
"          __global float * B,  \n"
"          unsigned int B_rows,\n"
"          unsigned int B_cols,\n"
"          unsigned int B_internal_rows,\n"
"          unsigned int B_internal_cols)\n"
"{ \n"
"  float temp; \n"
"  for (int row = A_rows-1; row > -1; --row) \n"
"  { \n"
"    barrier(CLK_GLOBAL_MEM_FENCE); \n"
"    if (get_local_id(0) == 0) \n"
"      B[row + get_group_id(0) * B_internal_rows] /= A[row + row*A_internal_cols]; \n"
"    barrier(CLK_GLOBAL_MEM_FENCE); \n"
"      temp = B[row + get_group_id(0) * B_internal_rows]; \n"
"    //eliminate column of op(A) with index 'row' in parallel: \n"
"    for  (int elim = get_local_id(0); elim < row; elim += get_local_size(0)) \n"
"      B[elim + get_group_id(0) * B_internal_rows] -= temp * A[elim * A_internal_cols + row];\n"
"   }\n"
"}\n"
; //matrix_solve_row_col_align1_upper_solve

const char * const matrix_solve_row_col_align1_trans_lower_trans_solve = 
"// file automatically generated - do not edit!\n"
"// inplace solve A^T \\ B^T\n"
"// matrix layouts: A...row_major, B...col_major\n"
"__kernel void trans_lower_trans_solve(\n"
"          __global const float * A,\n"
"          unsigned int A_rows,\n"
"          unsigned int A_cols,\n"
"          unsigned int A_internal_rows,\n"
"          unsigned int A_internal_cols,\n"
"          __global float * B,  \n"
"          unsigned int B_rows,\n"
"          unsigned int B_cols,\n"
"          unsigned int B_internal_rows,\n"
"          unsigned int B_internal_cols)\n"
"{ \n"
"  float temp; \n"
"  for (int row = 0; row < A_rows; ++row) \n"
"  { \n"
"    barrier(CLK_GLOBAL_MEM_FENCE); \n"
"    if (get_local_id(0) == 0) \n"
"      B[row * B_internal_rows + get_group_id(0)] /= A[row + row*A_internal_cols]; \n"
"    barrier(CLK_GLOBAL_MEM_FENCE); \n"
"      temp = B[row * B_internal_rows + get_group_id(0)]; \n"
"    //eliminate column of op(A) with index 'row' in parallel: \n"
"    for  (int elim = row + get_local_id(0) + 1; elim < A_rows; elim += get_local_size(0)) \n"
"      B[elim * B_internal_rows + get_group_id(0)] -= temp * A[elim + row * A_internal_cols];\n"
"   }\n"
"}\n"
; //matrix_solve_row_col_align1_trans_lower_trans_solve

const char * const matrix_solve_row_col_align1_lower_solve = 
"// file automatically generated - do not edit!\n"
"// inplace solve A \\ B\n"
"// matrix layouts: A...row_major, B...col_major\n"
"__kernel void lower_solve(\n"
"          __global const float * A,\n"
"          unsigned int A_rows,\n"
"          unsigned int A_cols,\n"
"          unsigned int A_internal_rows,\n"
"          unsigned int A_internal_cols,\n"
"          __global float * B,  \n"
"          unsigned int B_rows,\n"
"          unsigned int B_cols,\n"
"          unsigned int B_internal_rows,\n"
"          unsigned int B_internal_cols)\n"
"{ \n"
"  float temp; \n"
"  for (int row = 0; row < A_rows; ++row) \n"
"  { \n"
"    barrier(CLK_GLOBAL_MEM_FENCE); \n"
"    if (get_local_id(0) == 0) \n"
"      B[row + get_group_id(0) * B_internal_rows] /= A[row + row*A_internal_cols]; \n"
"    barrier(CLK_GLOBAL_MEM_FENCE); \n"
"      temp = B[row + get_group_id(0) * B_internal_rows]; \n"
"    //eliminate column of op(A) with index 'row' in parallel: \n"
"    for  (int elim = row + get_local_id(0) + 1; elim < A_rows; elim += get_local_size(0)) \n"
"      B[elim + get_group_id(0) * B_internal_rows] -= temp * A[elim * A_internal_cols + row];\n"
"   }\n"
"}\n"
; //matrix_solve_row_col_align1_lower_solve

const char * const matrix_solve_row_col_align1_trans_lower_solve = 
"// file automatically generated - do not edit!\n"
"// inplace solve A^T \\ B\n"
"// matrix layouts: A...row_major, B...col_major\n"
"__kernel void trans_lower_solve(\n"
"          __global const float * A,\n"
"          unsigned int A_rows,\n"
"          unsigned int A_cols,\n"
"          unsigned int A_internal_rows,\n"
"          unsigned int A_internal_cols,\n"
"          __global float * B,  \n"
"          unsigned int B_rows,\n"
"          unsigned int B_cols,\n"
"          unsigned int B_internal_rows,\n"
"          unsigned int B_internal_cols)\n"
"{ \n"
"  float temp; \n"
"  for (int row = 0; row < A_rows; ++row) \n"
"  { \n"
"    barrier(CLK_GLOBAL_MEM_FENCE); \n"
"    if (get_local_id(0) == 0) \n"
"      B[row + get_group_id(0) * B_internal_rows] /= A[row + row*A_internal_cols]; \n"
"    barrier(CLK_GLOBAL_MEM_FENCE); \n"
"      temp = B[row + get_group_id(0) * B_internal_rows]; \n"
"    //eliminate column of op(A) with index 'row' in parallel: \n"
"    for  (int elim = row + get_local_id(0) + 1; elim < A_rows; elim += get_local_size(0)) \n"
"      B[elim + get_group_id(0) * B_internal_rows] -= temp * A[elim + row * A_internal_cols];\n"
"   }\n"
"}\n"
; //matrix_solve_row_col_align1_trans_lower_solve

const char * const matrix_solve_row_col_align1_unit_upper_trans_solve = 
"// file automatically generated - do not edit!\n"
"// inplace solve A \\ B^T\n"
"// matrix layouts: A...row_major, B...col_major\n"
"__kernel void unit_upper_trans_solve(\n"
"          __global const float * A,\n"
"          unsigned int A_rows,\n"
"          unsigned int A_cols,\n"
"          unsigned int A_internal_rows,\n"
"          unsigned int A_internal_cols,\n"
"          __global float * B,  \n"
"          unsigned int B_rows,\n"
"          unsigned int B_cols,\n"
"          unsigned int B_internal_rows,\n"
"          unsigned int B_internal_cols)\n"
"{ \n"
"  float temp; \n"
"  for (int row = A_rows-1; row > -1; --row) \n"
"  { \n"
"    barrier(CLK_GLOBAL_MEM_FENCE); \n"
"      temp = B[row * B_internal_rows + get_group_id(0)]; \n"
"    //eliminate column of op(A) with index 'row' in parallel: \n"
"    for  (int elim = get_local_id(0); elim < row; elim += get_local_size(0)) \n"
"      B[elim * B_internal_rows + get_group_id(0)] -= temp * A[elim * A_internal_cols + row];\n"
"   }\n"
"}\n"
; //matrix_solve_row_col_align1_unit_upper_trans_solve

const char * const matrix_solve_row_col_align1_unit_upper_solve = 
"// file automatically generated - do not edit!\n"
"// inplace solve A \\ B\n"
"// matrix layouts: A...row_major, B...col_major\n"
"__kernel void unit_upper_solve(\n"
"          __global const float * A,\n"
"          unsigned int A_rows,\n"
"          unsigned int A_cols,\n"
"          unsigned int A_internal_rows,\n"
"          unsigned int A_internal_cols,\n"
"          __global float * B,  \n"
"          unsigned int B_rows,\n"
"          unsigned int B_cols,\n"
"          unsigned int B_internal_rows,\n"
"          unsigned int B_internal_cols)\n"
"{ \n"
"  float temp; \n"
"  for (int row = A_rows-1; row > -1; --row) \n"
"  { \n"
"    barrier(CLK_GLOBAL_MEM_FENCE); \n"
"      temp = B[row + get_group_id(0) * B_internal_rows]; \n"
"    //eliminate column of op(A) with index 'row' in parallel: \n"
"    for  (int elim = get_local_id(0); elim < row; elim += get_local_size(0)) \n"
"      B[elim + get_group_id(0) * B_internal_rows] -= temp * A[elim * A_internal_cols + row];\n"
"   }\n"
"}\n"
; //matrix_solve_row_col_align1_unit_upper_solve

const char * const matrix_solve_row_col_align1_trans_unit_lower_solve = 
"// file automatically generated - do not edit!\n"
"// inplace solve A^T \\ B\n"
"// matrix layouts: A...row_major, B...col_major\n"
"__kernel void trans_unit_lower_solve(\n"
"          __global const float * A,\n"
"          unsigned int A_rows,\n"
"          unsigned int A_cols,\n"
"          unsigned int A_internal_rows,\n"
"          unsigned int A_internal_cols,\n"
"          __global float * B,  \n"
"          unsigned int B_rows,\n"
"          unsigned int B_cols,\n"
"          unsigned int B_internal_rows,\n"
"          unsigned int B_internal_cols)\n"
"{ \n"
"  float temp; \n"
"  for (int row = 0; row < A_rows; ++row) \n"
"  { \n"
"    barrier(CLK_GLOBAL_MEM_FENCE); \n"
"      temp = B[row + get_group_id(0) * B_internal_rows]; \n"
"    //eliminate column of op(A) with index 'row' in parallel: \n"
"    for  (int elim = row + get_local_id(0) + 1; elim < A_rows; elim += get_local_size(0)) \n"
"      B[elim + get_group_id(0) * B_internal_rows] -= temp * A[elim + row * A_internal_cols];\n"
"   }\n"
"}\n"
; //matrix_solve_row_col_align1_trans_unit_lower_solve

  }  //namespace kernels
 }  //namespace linalg
}  //namespace viennacl
#endif
