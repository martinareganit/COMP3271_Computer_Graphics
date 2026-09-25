#include "triangle_app.hpp"

// clang-format off
#include <glad/glad.h>
#include <GLFW/glfw3.h>
// clang-format on

#include <array>
#include <vector>

namespace {

struct Triangle {
    std::array<std::array<double, 2>, 3> vertices{};
    int color_index = 0;
};

std::vector<Triangle> triangles;
Triangle triangle_to_draw;
int point_count = 0;

constexpr std::array<std::array<double, 3>, 11> color_array{
    {
     {0.9, 0.0, 0.0},
     {0.0, 0.5, 0.4},
     {0.1, 0.2, 0.46},
     {0.9, 0.9, 0.0},
     {0.0, 1.0, 0.0},
     {0.0, 1.0, 1.0},
     {0.0, 0.0, 1.0},
     {1.0, 0.0, 1.0},
     {0.9, 0.6, 0.0},
     {0.9, 1.0, 0.6},
     {0.2, 0.2, 0.2},
     }
};

} // namespace

void ClearTriangles() {
    triangles.clear();
    point_count = 0;
}

void DrawTriangles() {

    glColor3d(1.0, 1.0, 1.0);
    glPointSize(5.0F);
    // ===== STUDENT_TASK_BEGIN: part_a_draw_triangles =====
    glBegin(GL_TRIANGLES);
    int i = 0;
    while (i < triangles.size()) {
        int color_idx = triangles[i].color_index;
        glColor3d(color_array[color_idx][0], color_array[color_idx][1], color_array[color_idx][2]);

        glVertex2d(triangles[i].vertices[0][0], triangles[i].vertices[0][1]);
        glVertex2d(triangles[i].vertices[1][0], triangles[i].vertices[1][1]);
        glVertex2d(triangles[i].vertices[2][0], triangles[i].vertices[2][1]);
        i++;
    }
    glEnd();

    glColor3d(1.0, 1.0, 1.0);
    glBegin(GL_POINTS);
    i = 0;
    while (i < point_count) {
        glVertex2d(triangle_to_draw.vertices[i][0], triangle_to_draw.vertices[i][1]);
        i++;
    }
    glEnd();
    // ===== STUDENT_TASK_END: part_a_draw_triangles =====
}

void MouseInteraction(double m_x, double m_y) {
    // ===== STUDENT_TASK_BEGIN: part_a_mouse_interaction =====
    triangle_to_draw.vertices[point_count][0] = m_x;
    triangle_to_draw.vertices[point_count][1] = m_y;
    point_count++;

    if (point_count == 3) {
        int total_triangles = (int)triangles.size();
        int total_colors = (int)color_array.size();

        triangle_to_draw.color_index = total_triangles % total_colors;
        triangles.push_back(triangle_to_draw);
        point_count = 0;
    }
    // ===== STUDENT_TASK_END: part_a_mouse_interaction =====
}