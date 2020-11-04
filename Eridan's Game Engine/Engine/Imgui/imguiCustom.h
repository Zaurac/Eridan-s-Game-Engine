#include <GLFW/glfw3.h>
#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"

#include <vector>

class imguiCustom
{
public:
	imguiCustom() = delete;
	~imguiCustom() = delete;
	static void Imgui_Init(GLFWwindow *windows);
	static void Imgui_Render();
	static void Imgui_Draw();
	static void Imgui_Destroy();

	static void StyleCustom(ImGuiStyle* dst);

	

private:

};