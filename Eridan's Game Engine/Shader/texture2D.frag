#version 430 core
out vec4 FragColor;

in vec2 TexCoord;
in vec3 Normal;
in vec3 FragPos; 

uniform sampler2D ourTexture;
uniform vec3 ourColor;
uniform vec3 lightColor;

uniform vec3 lightPos;
uniform vec3 viewPos;


void main()
{
	//AMBIENT
	float ambientStrenght = 0.1f;
	vec3 ambient = ambientStrenght * lightColor;

	//DIFFUSE
	vec3 norm = normalize(Normal);
	vec3 lightDir = normalize(lightPos - FragPos);
	float diff = max(dot(norm, lightDir), 0.0);
	vec3 diffuse = diff * lightColor;

	//SPECULAR
	float specularStrenght = 0.5f;
	vec3 viewDir = normalize(viewPos - FragPos);
	vec3 reflectDir = reflect(-lightDir, norm);
	float spec = pow(max(dot(viewDir, reflectDir), 0.0), 32);
	vec3 specular = specularStrenght * spec * lightColor;

	

	vec3 result = (ambient + diffuse + specular) * ourColor;

	FragColor = vec4(result,1.0f);


};