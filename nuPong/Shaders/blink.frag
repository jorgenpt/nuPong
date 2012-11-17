uniform float blink_t;
varying float position_relative_to_blink_y;

void main()
{
    if (blink_t < 0.3)
    {
        float hilight = abs(abs(position_relative_to_blink_y)*10. - blink_t*8.);
        float intensity = max(-pow(hilight, 2.0) + 1.0, 0.0);
        gl_FragColor = vec4(1.0, intensity/(1.0 + blink_t * 6.), intensity/(1.0 + blink_t * 6.), 1.0);
    }
    else
        gl_FragColor = vec4(1.0, 0.0, 0.0, 1.0);
}