// Calculates the specular component of the phong reflection model.
vec4 phongSpecular(vec4 lightIntensity, vec4 cameraDir, vec4 reflectedLightDir,
                   float materialShininess, float materialSpecular)
{
    return materialSpecular * (pow(dot(reflectedLightDir, cameraDir), materialShininess) * lightIntensity);
}

// Calculates the diffuse compopnent of the phong reflection model.
vec4 phongDiffuse(vec4 lightIntensity, vec4 lightDir, vec4 normal, float materialDiffuse)
{
    return materialDiffuse * (dot(lightDir, normal) * lightIntensity);
}

// Calculates the phong reflection model for the given point & parameters (ignores ambient lighting).
vec4 phong(vec4 diffuseIntensity, vec4 specularIntensity,
           vec4 point, vec4 normal,
           vec4 cameraPosition, vec4 lightPosition,
           float materialShininess, float materialSpecular, float materialDiffuse)
{
    vec4 lightDir = normalize(lightPosition - point);
    vec4 cameraDir = normalize(cameraPosition - point);
    vec4 reflectedLightDir = reflect(-lightDir, normal);

    vec4 specular =  phongSpecular(specularIntensity, cameraDir, reflectedLightDir, materialShininess, materialSpecular);
    vec4 diffuse = phongDiffuse(diffuseIntensity, lightDir, normal, materialDiffuse);

    return specular + diffuse;
}