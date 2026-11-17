#version 330 core

in vec2 v_uv;
in vec3 v_world_normal;
in vec3 v_world_position;

uniform sampler2D u_texture;
uniform vec3 u_base_color;
uniform vec3 u_light_pos;
uniform vec3 u_camera_pos;
uniform float u_shininess;

out vec4 fragment_color;

void main() {
    // ===== STUDENT_TASK_BEGIN: assignment2_texture_fragment_shader =====
    vec3 texture_color = texture(u_texture, v_uv).rgb;
    vec3 diffuse_color = texture_color * u_base_color;

    vec3 n_normalized = normalize(v_world_normal);
    vec3 l_normalized = normalize(u_light_pos - v_world_position);
    vec3 v_normalized = normalize(u_camera_pos - v_world_position);

    vec3 h_direction = normalize (l_normalized + v_normalized);

    float n_dot_l = max(dot(n_normalized, l_normalized), 0.0);
    float n_dot_h = max(dot(n_normalized, h_direction), 0.0);

    vec3 ambient = 0.15 * diffuse_color;
    vec3 diffuse = 0.75 * diffuse_color * n_dot_l;

    float s_value = 0.0;
    if (n_dot_l > 0.0) {
        s_value = pow(n_dot_h, u_shininess);
    }
    vec3 specular = 0.55 * vec3(1.0) * s_value;

    vec3 final_color = ambient + diffuse + specular;
    fragment_color = vec4(final_color, 1.0);
    // ===== STUDENT_TASK_END: assignment2_texture_fragment_shader =====
}
