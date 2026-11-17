#version 330 core

layout(location = 0) in vec3 a_position;
layout(location = 1) in vec3 a_normal;

uniform mat4 u_model;
uniform mat4 u_view;
uniform mat4 u_projection;

out vec3 v_world_position;
out vec3 v_world_normal;

void main() {
    // ===== STUDENT_TASK_BEGIN: assignment2_blinn_phong_vertex_shader =====
    vec4 w_position = u_model * vec4(a_position, 1.0);
    gl_Position = u_projection * u_view * w_position;

    v_world_position = vec3(w_position);

    mat3 n_matrix = mat3(transpose(inverse(u_model)));
    v_world_normal = normalize(n_matrix * a_normal);
    // ===== STUDENT_TASK_END: assignment2_blinn_phong_vertex_shader =====
}
