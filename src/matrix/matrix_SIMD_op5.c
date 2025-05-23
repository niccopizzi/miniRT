#include "matrix.h"

t_mat2    matrix3_submatrix(t_mat3 m, int row, int col)
{
    t_mat2  subm;
    int     i;
    int     j;
    int     x;
    
    i = -1;
    x = 0;
    while (++i < 3)
    {
        if (i == row)
            i++;
        j = -1;
        while (++j < 3)
        {
            if (j != col)
                subm.vec[x++] = m.row[i][j];
        }
    }
    return (subm);
}

inline float    matrix3_cofactor(t_mat3 m, int row, int col)
{
    if (((row + col) % 2) != 0)
        return (-(matrix3_minor(m, row, col)));
    return (matrix3_minor(m, row, col));
    
}

inline float    matrix2_det(t_mat2 m)
{
    return (m.vec[0] * m.vec[3] - m.vec[2] * m.vec[1]);
}

inline float    matrix3_minor(t_mat3 m, int row, int col)
{
    return (matrix2_det(matrix3_submatrix(m, row, col)));
}


inline float    matrix3_det(t_mat3 m)
{
    return (vector_dot_product(m.row[0], 
            (t_vec4){
                matrix3_cofactor(m, 0, 0),
                matrix3_cofactor(m, 0, 1),
                matrix3_cofactor(m, 0, 2),
                0}));
}