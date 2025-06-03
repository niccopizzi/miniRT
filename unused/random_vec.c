

t_vec4  random_unit_vector(float min, float max)
{
    t_vec4  vec;
    float   len;
    float   range;

    range = max - min;
    vec = vector_from_float(0);
    while (true)
    {
        vec[0] = min + (range) * drand48();
        vec[1] = min + (range) * drand48();
        vec[2] = min + (range) * drand48();
        len = vector_len_squared(vec);
        if (len > EPSILON && len <= 1)
            return (vec / sqrtf(len));
    }
}

t_vec4  random_vector_on_hemisphere(t_vec4 normal)
{
    t_vec4  random_vec;

    random_vec = random_unit_vector(-1, 1);
    if (vector_dot_product(random_vec, normal) < 0)
        return (-random_vec);
    return (random_vec);
}