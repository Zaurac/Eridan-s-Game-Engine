#include "imguiCustom.h"

void imguiCustom::Imgui_Init(GLFWwindow* windows)
{
	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGui_ImplGlfw_InitForOpenGL(windows, true);
	ImGui_ImplOpenGL3_Init();
	StyleCustom(NULL);
}

void imguiCustom::Imgui_Render()
{
	ImGui_ImplOpenGL3_NewFrame();
	ImGui_ImplGlfw_NewFrame();
	ImGui::NewFrame();

	Imgui_Draw();

	ImGui::Render();
	ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}

void imguiCustom::Imgui_Draw()
{
	static float f = 0.0f;
	static int counter = 0;

	ImGui::Text("Parmeter, world!");
	ImGui::SliderFloat("float", &f, 0.0f, 1.0f);
}

void imguiCustom::Imgui_Destroy()
{
	ImGui_ImplOpenGL3_Shutdown();
	ImGui_ImplGlfw_Shutdown();
	ImGui::DestroyContext();
}

void imguiCustom::StyleCustom(ImGuiStyle* dst)
{
	ImGuiStyle* style = dst ? dst : &ImGui::GetStyle();


	float hspacing = 8;
	float vspacing = 6;
	style->DisplaySafeAreaPadding = ImVec2(0, 0);
	style->WindowPadding = ImVec2(hspacing / 2, vspacing);
	style->FramePadding = ImVec2(hspacing, vspacing);
	style->ItemSpacing = ImVec2(hspacing, vspacing);
	style->ItemInnerSpacing = ImVec2(hspacing, vspacing);
	style->IndentSpacing = 20.0f;

	style->WindowRounding = 0.0f;
	style->FrameRounding = 0.0f;

	style->WindowBorderSize = 0.0f;
	style->FrameBorderSize = 1.0f;
	style->PopupBorderSize = 1.0f;

	style->ScrollbarSize = 20.0f;
	style->ScrollbarRounding = 0.0f;
	style->GrabMinSize = 5.0f;
	style->GrabRounding = 0.0f;

	ImVec4 white = ImVec4(1.00f, 1.00f, 1.00f, 1.00f);
	ImVec4 transparent = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
	ImVec4 dark = ImVec4(0.00f, 0.00f, 0.00f, 0.20f);
	ImVec4 darker = ImVec4(0.00f, 0.00f, 0.00f, 0.50f);

	ImVec4 background = ImVec4(0.95f, 0.95f, 0.95f, 1.00f);
	ImVec4 text = ImVec4(0.10f, 0.10f, 0.10f, 1.00f);
	ImVec4 border = ImVec4(0.60f, 0.60f, 0.60f, 1.00f);
	ImVec4 grab = ImVec4(0.69f, 0.69f, 0.69f, 1.00f);
	ImVec4 header = ImVec4(0.86f, 0.86f, 0.86f, 1.00f);
	ImVec4 active = ImVec4(0.00f, 0.47f, 0.84f, 1.00f);
	ImVec4 hover = ImVec4(0.00f, 0.47f, 0.84f, 0.20f);

	style->Colors[ImGuiCol_Text] = text;
	style->Colors[ImGuiCol_WindowBg] = background;
	style->Colors[ImGuiCol_ChildBg] = background;
	style->Colors[ImGuiCol_PopupBg] = dark;

	style->Colors[ImGuiCol_Border] = border;
	style->Colors[ImGuiCol_BorderShadow] = transparent;

	style->Colors[ImGuiCol_Button] = header;
	style->Colors[ImGuiCol_ButtonHovered] = hover;
	style->Colors[ImGuiCol_ButtonActive] = active;

	style->Colors[ImGuiCol_FrameBg] = white;
	style->Colors[ImGuiCol_FrameBgHovered] = hover;
	style->Colors[ImGuiCol_FrameBgActive] = active;

	style->Colors[ImGuiCol_MenuBarBg] = header;
	style->Colors[ImGuiCol_Header] = header;
	style->Colors[ImGuiCol_HeaderHovered] = hover;
	style->Colors[ImGuiCol_HeaderActive] = active;

	style->Colors[ImGuiCol_CheckMark] = text;
	style->Colors[ImGuiCol_SliderGrab] = grab;
	style->Colors[ImGuiCol_SliderGrabActive] = darker;


	style->Colors[ImGuiCol_ScrollbarBg] = header;
	style->Colors[ImGuiCol_ScrollbarGrab] = grab;
	style->Colors[ImGuiCol_ScrollbarGrabHovered] = dark;
	style->Colors[ImGuiCol_ScrollbarGrabActive] = darker;
}
