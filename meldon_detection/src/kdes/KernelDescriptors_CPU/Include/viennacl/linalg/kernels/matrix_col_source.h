#ifndef _VIENNACL_MATRIX_COL_SOURCE_HPP_
#define _VIENNACL_MATRIX_COL_SOURCE_HPP_
//Automatically generated file from aux-directory, do not edit manually!
namespace viennacl
{
 namespace linalg
 {
  namespace kernels
  {
const char * const matrix_col_align1_unit_lower_triangular_substitute_inplace = 
"__kernel void unit_lower_triangular_substitute_inplace(\n"
"          __global const float * matrix,\n"
"          unsigned int matrix_rows,\n"
"          unsigned int matrix_cols,\n"
"          unsigned int matrix_internal_rows,\n"
"          unsigned int matrix_internal_cols,\n"
"          __global float * vector)\n"
"{\n"
"  float temp;\n"
"  for (int row = 0; row < matrix_rows; ++row)\n"
"  {\n"
"    barrier(CLK_GLOBAL_MEM_FENCE);\n"
"    temp = vector[row];\n"
"    for  (int elim = row + get_global_id(0) + 1; elim < matrix_rows; elim += get_global_size(0))\n"
"      vector[elim] -= temp * matrix[row * matrix_internal_rows + elim];\n"
"  }\n"
"}\n"
; //matrix_col_align1_unit_lower_triangular_substitute_inplace

const char * const matrix_col_align1_inplace_sub = 
"__kernel void inplace_sub(\n"
"          __global float * vec1,\n"
"          __global const float * vec2,\n"
"          unsigned int size) \n"
"{ \n"
"  for (unsigned int i = get_global_id(0); i < size; i += get_global_size(0))\n"
"    vec1[i] -= vec2[i];\n"
"}\n"
; //matrix_col_align1_inplace_sub

const char * const matrix_col_align1_lower_triangular_substitute_inplace = 
"__kernel void lower_triangular_substitute_inplace(\n"
"          __global const float * matrix,\n"
"          unsigned int matrix_rows,\n"
"          unsigned int matrix_cols,\n"
"          unsigned int matrix_internal_rows,\n"
"          unsigned int matrix_internal_cols,\n"
"          __global float * vector)\n"
"{\n"
"  float temp;\n"
"  for (int row = 0; row < matrix_rows; ++row)\n"
"  {\n"
"    barrier(CLK_GLOBAL_MEM_FENCE);\n"
"    if (get_global_id(0) == 0)\n"
"      vector[row] /= matrix[row+row*matrix_internal_rows];\n"
"    barrier(CLK_GLOBAL_MEM_FENCE);\n"
"    temp = vector[row];\n"
"    for  (int elim = row + get_global_id(0) + 1; elim < matrix_rows; elim += get_global_size(0))\n"
"      vector[elim] -= temp * matrix[row * matrix_internal_rows + elim];\n"
"  }\n"
"}\n"
; //matrix_col_align1_lower_triangular_substitute_inplace

const char * const matrix_col_align1_trans_vec_mul = 
"__kernel void trans_vec_mul(\n"
"          __global const float * matrix,\n"
"          unsigned int matrix_rows,\n"
"          unsigned int matrix_cols,\n"
"          unsigned int matrix_internal_rows,\n"
"          unsigned int matrix_internal_cols,\n"
"          __global const float * vector,  \n"
"          __global float * result) \n"
"{ \n"
"  //row and col indicate indices within transposed matrix\n"
"  for (unsigned int row = get_global_id(0); row < matrix_cols; row += get_global_size(0))\n"
"  {\n"
"    float dot_prod2 = 0.0f;\n"
"    for (unsigned int col = 0; col < matrix_rows; ++col)\n"
"      dot_prod2 += matrix[row * matrix_internal_rows + col] * vector[col];\n"
"    result[row] = dot_prod2;\n"
"  }\n"
"}\n"
; //matrix_col_align1_trans_vec_mul

const char * const matrix_col_align1_rank1_update = 
"//perform a rank-1 update of the matrix, i.e. A += x * x^T\n"
"__kernel void rank1_update(\n"
"          __global float * matrix,\n"
"          unsigned int matrix_rows,\n"
"          unsigned int matrix_cols,\n"
"          unsigned int matrix_internal_rows,\n"
"          unsigned int matrix_internal_cols,\n"
"          __global const float * vector1,  \n"
"          __global const float * vector2) \n"
"{ \n"
"  float tmp;\n"
"  for (unsigned int row= get_global_id(0); row < matrix_rows; row += get_global_size(0))\n"
"  {\n"
"    tmp = vector1[row];\n"
"    for (unsigned int col = 0; col < matrix_cols; ++col)\n"
"      matrix[row + col * matrix_internal_rows] += tmp * vector2[col];\n"
"  }\n"
"}\n"
; //matrix_col_align1_rank1_update

const char * const matrix_col_align1_sub = 
"__kernel void sub(\n"
"          __global const float * vec1,\n"
"          __global const float * vec2, \n"
"          __global float * result,\n"
"          unsigned int size)\n"
"{ \n"
"  for (unsigned int i = get_global_id(0); i < size; i += get_global_size(0))\n"
"    result[i] = vec1[i] - vec2[i];\n"
"}\n"
; //matrix_col_align1_sub

const char * const matrix_col_align1_trans_unit_upper_triangular_substitute_inplace = 
"//transposed lower triangular matrix\n"
"__kernel void trans_unit_upper_triangular_substitute_inplace(\n"
"          __global const float * matrix, \n"
"          unsigned int matrix_rows,\n"
"          unsigned int matrix_cols,\n"
"          unsigned int matrix_internal_rows,\n"
"          unsigned int matrix_internal_cols,\n"
"          __global float * vector) \n"
"{ \n"
"  float temp; \n"
"  for (int row = matrix_rows-1; row > -1; --row) \n"
"  { \n"
"    barrier(CLK_GLOBAL_MEM_FENCE); \n"
"    \n"
"    temp = vector[row]; \n"
"    //eliminate column with index 'row' in parallel: \n"
"    for  (int elim = get_global_id(0); elim < row; elim += get_global_size(0)) \n"
"      vector[elim] -= temp * matrix[row + elim  * matrix_internal_rows]; \n"
"  } \n"
"   \n"
"}\n"
; //matrix_col_align1_trans_unit_upper_triangular_substitute_inplace

const char * const matrix_col_align1_lu_factorize = 
"__kernel void lu_factorize(\n"
"          __global float * matrix,\n"
"          unsigned int matrix_rows,\n"
"          unsigned int matrix_cols,\n"
"          unsigned int matrix_internal_rows,\n"
"          unsigned int matrix_internal_cols) \n"
"{ \n"
"  float temp;\n"
"  for (unsigned int i=1; i<matrix_rows; ++i)\n"
"  {\n"
"    for (unsigned int k=0; k<i; ++k)\n"
"    {\n"
"      if (get_global_id(0) == 0)\n"
"        matrix[i + k*matrix_internal_rows] /= matrix[k + k*matrix_internal_rows];\n"
"      barrier(CLK_GLOBAL_MEM_FENCE);\n"
"      temp = matrix[i + k*matrix_internal_rows];\n"
"      \n"
"      //parallel subtraction:\n"
"      for (unsigned int j=k+1 + get_global_id(0); j<matrix_cols; j += get_global_size(0))\n"
"        matrix[i + j*matrix_internal_rows] -= temp * matrix[k + j*matrix_internal_rows];\n"
"    }\n"
"  }\n"
"} \n"
; //matrix_col_align1_lu_factorize

const char * const matrix_col_align1_add = 
"__kernel void add(\n"
"          __global const float * vec1,\n"
"          __global const float * vec2, \n"
"          __global float * result,\n"
"          unsigned int size) \n"
"{ \n"
"  for (unsigned int i = get_global_id(0); i < size; i += get_global_size(0))\n"
"    result[i] = vec1[i] + vec2[i];\n"
"}\n"
; //matrix_col_align1_add

const char * const matrix_col_align1_vec_mul = 
"__kernel void vec_mul(\n"
"          __global const float * matrix,\n"
"          unsigned int matrix_rows,\n"
"          unsigned int matrix_cols,\n"
"          unsigned int matrix_internal_rows,\n"
"          unsigned int matrix_internal_cols,\n"
"          __global const float * vector,  \n"
"          __global float * result) \n"
"{ \n"
"  for (unsigned int row = get_global_id(0); row < matrix_rows; row += get_global_size(0))\n"
"  {\n"
"    float dot_prod = 0.0f;\n"
"    for (unsigned int col = 0; col < matrix_cols; ++col)\n"
"      dot_prod += matrix[row + col*matrix_internal_rows] * vector[col];\n"
"    result[row] = dot_prod;\n"
"  }\n"
"}\n"
; //matrix_col_align1_vec_mul

const char * const matrix_col_align1_trans_lower_triangular_substitute_inplace = 
"__kernel void trans_lower_triangular_substitute_inplace(\n"
"          __global const float * matrix,\n"
"          unsigned int matrix_rows,\n"
"          unsigned int matrix_cols,\n"
"          unsigned int matrix_internal_rows,\n"
"          unsigned int matrix_internal_cols,\n"
"          __global float * vector)\n"
"{\n"
"  float temp;\n"
"  for (int row = 0; row < matrix_rows; ++row)\n"
"  {\n"
"    barrier(CLK_GLOBAL_MEM_FENCE);\n"
"    if (get_global_id(0) == 0)\n"
"      vector[row] /= matrix[row+row*matrix_internal_rows];\n"
"    barrier(CLK_GLOBAL_MEM_FENCE);\n"
"    temp = vector[row];\n"
"    for  (int elim = row + get_global_id(0) + 1; elim < matrix_rows; elim += get_global_size(0))\n"
"      vector[elim] -= temp * matrix[elim * matrix_internal_rows + row];\n"
"  }\n"
"}\n"
; //matrix_col_align1_trans_lower_triangular_substitute_inplace

const char * const matrix_col_align1_inplace_divide = 
"__kernel void inplace_divide(\n"
"          __global float * vec,\n"
"          __global const float * fac,  //note: CPU variant is mapped to prod_scalar\n"
"          unsigned int size) \n"
"{ \n"
"  float factor = *fac;\n"
"  for (unsigned int i = get_global_id(0); i < size; i += get_global_size(0))\n"
"    vec[i] /= factor;\n"
"}\n"
; //matrix_col_align1_inplace_divide

const char * const matrix_col_align1_trans_upper_triangular_substitute_inplace = 
"//transposed lower triangular matrix\n"
"__kernel void trans_upper_triangular_substitute_inplace(\n"
"          __global const float * matrix, \n"
"          unsigned int matrix_rows,\n"
"          unsigned int matrix_cols,\n"
"          unsigned int matrix_internal_rows,\n"
"          unsigned int matrix_internal_cols,\n"
"          __global float * vector) \n"
"{ \n"
"  float temp; \n"
"  for (int row = matrix_rows-1; row > -1; --row) \n"
"  { \n"
"    barrier(CLK_GLOBAL_MEM_FENCE); \n"
"    if (get_global_id(0) == 0) \n"
"      vector[row] /= matrix[row + row*matrix_internal_rows]; \n"
" \n"
"    barrier(CLK_GLOBAL_MEM_FENCE); \n"
"    temp = vector[row]; \n"
"    //eliminate column with index 'row' in parallel: \n"
"    for  (int elim = get_global_id(0); elim < row; elim += get_global_size(0)) \n"
"      vector[elim] -= temp * matrix[row + elim * matrix_internal_rows]; \n"
"  } \n"
"   \n"
"}\n"
; //matrix_col_align1_trans_upper_triangular_substitute_inplace

const char * const matrix_col_align1_unit_upper_triangular_substitute_inplace = 
"__kernel void unit_upper_triangular_substitute_inplace( \n"
"          __global const float * matrix, \n"
"          unsigned int matrix_rows,\n"
"          unsigned int matrix_cols,\n"
"          unsigned int matrix_internal_rows,\n"
"          unsigned int matrix_internal_cols,\n"
"          __global float * vector) \n"
"{ \n"
"  float temp; \n"
"  for (int row = matrix_rows-1; row > -1; --row) \n"
"  { \n"
"    barrier(CLK_GLOBAL_MEM_FENCE); \n"
"    \n"
"    temp = vector[row]; \n"
"    //eliminate column with index 'row' in parallel: \n"
"    for  (int elim = get_global_id(0); elim < row; elim += get_global_size(0)) \n"
"      vector[elim] -= temp * matrix[elim + row  * matrix_internal_rows]; \n"
"  } \n"
"   \n"
"}\n"
; //matrix_col_align1_unit_upper_triangular_substitute_inplace

const char * const matrix_col_align1_inplace_add = 
"__kernel void inplace_add(\n"
"          __global float * vec1,\n"
"          __global const float * vec2,\n"
"          unsigned int size) \n"
"{ \n"
"  for (unsigned int i = get_global_id(0); i < size; i += get_global_size(0))\n"
"    vec1[i] += vec2[i];\n"
"}\n"
; //matrix_col_align1_inplace_add

const char * const matrix_col_align1_trans_unit_lower_triangular_substitute_inplace = 
"\n"
"__kernel void trans_unit_lower_triangular_substitute_inplace(\n"
"          __global const float * matrix,\n"
"          unsigned int matrix_rows,\n"
"          unsigned int matrix_cols,\n"
"          unsigned int matrix_internal_rows,\n"
"          unsigned int matrix_internal_cols,\n"
"          __global float * vector)\n"
"{\n"
"  float temp;\n"
"  for (int row = 0; row < matrix_rows; ++row)\n"
"  {\n"
"    barrier(CLK_GLOBAL_MEM_FENCE);\n"
"\n"
"    temp = vector[row];\n"
"\n"
"    for  (int elim = row + get_global_id(0) + 1; elim < matrix_rows; elim += get_global_size(0))\n"
"      vector[elim] -= temp * matrix[elim * matrix_internal_rows + row];\n"
"  }\n"
"}\n"
"\n"
"\n"
; //matrix_col_align1_trans_unit_lower_triangular_substitute_inplace

const char * const matrix_col_align1_scaled_rank1_update = 
"__kernel void scaled_rank1_update(\n"
"          __global float * matrix,\n"
"          unsigned int matrix_rows,\n"
"          unsigned int matrix_cols,\n"
"          unsigned int matrix_internal_rows,\n"
"          unsigned int matrix_internal_cols,\n"
"          float val,\n"
"          __global const float * vector1,  \n"
"          __global const float * vector2) \n"
"{ \n"
"  float tmp;\n"
"  for (unsigned int row = get_global_id(0); row < matrix_rows; row += get_global_size(0))\n"
"  {\n"
"    tmp = val * vector1[row];\n"
"    for (unsigned int col = 0; col < matrix_cols; ++col)\n"
"      matrix[row + col*matrix_internal_rows] += tmp * vector2[col];\n"
"  }\n"
"}\n"
; //matrix_col_align1_scaled_rank1_update

const char * const matrix_col_align1_clear = 
"__kernel void clear(\n"
"          __global float * vec,\n"
"          unsigned int size) \n"
"{ \n"
"  for (unsigned int i = get_global_id(0); i < size; i += get_global_size(0))\n"
"    vec[i] = 0;\n"
"}\n"
; //matrix_col_align1_clear

const char * const matrix_col_align1_cpu_inplace_mult = 
"__kernel void cpu_inplace_mult(\n"
"          __global float * vec,\n"
"          float factor, \n"
"          unsigned int size) \n"
"{ \n"
"  for (unsigned int i = get_global_id(0); i < size; i += get_global_size(0))\n"
"    vec[i] *= factor;\n"
"}\n"
; //matrix_col_align1_cpu_inplace_mult

const char * const matrix_col_align1_inplace_mult = 
"__kernel void inplace_mult(\n"
"          __global float * vec,\n"
"          __global const float * fac, \n"
"          unsigned int size) \n"
"{ \n"
"  float factor = *fac;\n"
"  for (unsigned int i = get_global_id(0); i < size; i += get_global_size(0))\n"
"    vec[i] *= factor;\n"
"}\n"
; //matrix_col_align1_inplace_mult

const char * const matrix_col_align1_upper_triangular_substitute_inplace = 
"__kernel void upper_triangular_substitute_inplace( \n"
"          __global const float * matrix, \n"
"          unsigned int matrix_rows,\n"
"          unsigned int matrix_cols,\n"
"          unsigned int matrix_internal_rows,\n"
"          unsigned int matrix_internal_cols,\n"
"          __global float * vector) \n"
"{ \n"
"  float temp; \n"
"  for (int row = matrix_rows-1; row > -1; --row) \n"
"  { \n"
"    barrier(CLK_GLOBAL_MEM_FENCE); \n"
"    if (get_global_id(0) == 0) \n"
"      vector[row] /= matrix[row + row*matrix_internal_rows]; \n"
" \n"
"    barrier(CLK_GLOBAL_MEM_FENCE); \n"
"    temp = vector[row]; \n"
"    //eliminate column with index 'row' in parallel: \n"
"    for  (int elim = get_global_id(0); elim < row; elim += get_global_size(0)) \n"
"      vector[elim] -= temp * matrix[elim + row  * matrix_internal_rows]; \n"
"  } \n"
"   \n"
"}\n"
; //matrix_col_align1_upper_triangular_substitute_inplace

  }  //namespace kernels
 }  //namespace linalg
}  //namespace viennacl
#endif
