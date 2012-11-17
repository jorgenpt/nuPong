uniform float blink_y;
varying float position_relative_to_blink_y;

void main()
{
    vec4 worldPosition = gl_ModelViewMatrix * gl_Vertex;
    gl_Position = gl_ProjectionMatrix * worldPosition;
    position_relative_to_blink_y = worldPosition.y - blink_y;
}
