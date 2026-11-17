#version 330 core

in vec3 v_world_normal;
out vec4 fragment_color;

void main() {
    // ===== STUDENT_TASK_BEGIN: assignment2_normal_fragment_shader =====
    vec3 n_normalized = normalize(v_world_normal);
    vec3 mapped_color = n_normalized * 0.5 + 0.5;
    fragment_color = vec4(mapped_color, 1.0);
    // ===== STUDENT_TASK_END: assignment2_normal_fragment_shader =====
}
