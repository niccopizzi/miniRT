#include "matrix.h"

inline t_vec4      matrix4_mult_vec4(t_mat4 m, t_vec4 vec)
{
    return ((t_vec4){vector_dot_product(m.row[0], vec),
                    vector_dot_product(m.row[1], vec),
                    vector_dot_product(m.row[2], vec),
                    vector_dot_product(m.row[3], vec)});
}

t_mat3    matrix4_submatrix(t_mat4 m, int row, int col)
{
    t_mat3  subm;
    int     i;
    int     j;
    int     x;
    int     y;

    i = -1;
    x = 0;
    while (++i < 4)
    {
        if (i == row)   
            i++;
        j = 0;
        y = 0;
        while (j < 4)
        {
            if (j != col)
                subm.row[x][y++] = m.row[i][j];
            j++;
        }
        subm.row[x++][3] = 0;
    }
    subm.row[3] = _mm_setzero_ps();    
    return (subm);
}

inline float   matrix4_cofactor(t_mat4 m, int row, int col)
{
    if ((row + col ) % 2 != 0)
        return (-(matrix3_det(matrix4_submatrix(m, row, col))));
    return (matrix3_det(matrix4_submatrix(m, row, col)));
}

inline float   matrix4_det(t_mat4 m)
{
    return (vector_dot_product(m.row[0],(t_vec4)
            {
                matrix4_cofactor(m, 0, 0),
                matrix4_cofactor(m, 0, 1),
                matrix4_cofactor(m, 0, 2),
                matrix4_cofactor(m, 0, 3),
            }));
}

t_mat4    matrix4_invert(t_mat4 m)
{
    t_mat4  invm;
    float   det;
    int     i;
    int     j;

    det = matrix4_det(m);
    if (det == 0)
        return(m);
    det = 1 / det;
    i = 0;
    while (i < 4)
    {
        j = 0;
        while (j < 4)
        {
            invm.row[j][i] = matrix4_cofactor(m, i, j);
            j++;
        }
        i++;
    }
    invm.row[0] *= det;
    invm.row[1] *= det;
    invm.row[2] *= det;
    invm.row[3] *= det;
    return (invm);
}
