#ifndef VERTEX_H
#define VERTEX_H

#include <armadillo>

struct vertex {
    float x, y, z; // w
};

struct vertex_texture {
    float u, v; // w

    vertex_texture operator/(float value) const {
        return {u / value, v / value};
    }
    vertex_texture operator*(float value) const {
        return {u * value, v * value};
    }
    void operator+=(const vertex_texture& other) {
        u += other.u;
        v += other.v;
    }
    void operator*=(float value) {
        u *= value;
        v *= value;
    }
    vertex_texture operator+(const vertex_texture& other) const {
        return {u + other.u, v + other.v};
    }
    vertex_texture operator-(const vertex_texture& other) const {
        return {u - other.u, v - other.v};
    }
};

struct vertex_normal {
    float x, y, z;

    vertex_normal operator*(float v) const {
        return {x * v, y * v, z * v};
    }
    vertex_normal operator+(const vertex_normal& other) {
        return {x + other.x, y + other.y, z + other.z};
    }
    vertex_normal operator-(const vertex_normal& other) {
        return {x - other.x, y - other.y, z - other.z};
    }
};

//struct face_node {
//    vertex v;
//    texture_vertex vt;
//    vertex_normal vn;
//};

struct render_point {
    float x, y;//, z; // punkt na ekranie
    arma::vec v; // punkt w 3d względem kamery
    vertex_texture vt;
    vertex_normal vn;

    static render_point interpolate(const render_point& a, const render_point& b, float alpha);
};

#endif // VERTEX_H
