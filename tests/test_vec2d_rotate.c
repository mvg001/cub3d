#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "vec2d.h"

int test(double vx, double vy, double angle_degree, double ex, double ey) {
    t_vec2d *v = vec2d_create(vx, vy);
    t_rotation rot = vec2d_gen_rotation_degree(angle_degree);
    printf("vx: %f, vy: %f\n", v->x, v->y);
    vec2d_rotate(v, rot);
    printf("vrx: %f, vry: %f\n", v->x, v->y);
    int ok = (v->x == ex && v->y == ey);
    free(v);
    free(rot);
    printf("[%s]\n", ok ? "OK" : "NOK");
    return ok;
}

int main(void) {
    test(1.0, 0.0, 90.0, 0.0, 1.0);
    test(1.0, 0.0, -90.0, 0, -1.0);
    double val = sqrt(2.0)/2.0;
    test(val, val, 90.0, -val, val);
    test(val, val, -90.0, val, -val);
    return 0;
}