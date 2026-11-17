#version 330 core

layout(location = 0) in vec3 a_position;
layout(location = 1) in vec3 a_normal;
layout(location = 2) in vec2 a_uv;

uniform mat4 u_model;
uniform mat4 u_view;
uniform mat4 u_projection;
uniform float u_uv_scale;

out vec2 v_uv;
out vec3 v_world_normal;
out vec3 v_world_position;

void main() {
    // ===== STUDENT_TASK_BEGIN: assignment2_texture_vertex_shader =====
    vec4 w_position = u_model * vec4(a_position, 1.0);
    gl_Position = u_projection * u_view * w_position;

    v_world_position = vec3(w_position);

    mat3 n_matrix = mat3(transpose(inverse(u_model)));
    v_world_normal = normalize(n_matrix * a_normal);

    v_uv = a_uv * u_uv_scale;
    // ===== STUDENT_TASK_END: assignment2_texture_vertex_shader =====
}
