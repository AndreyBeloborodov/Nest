//
// Created by bogdan on 30.01.2024.
//

#include <NestUI.hpp>
#include <imgui.h>

#include "Menu.hpp"

Menu::Menu() {
    m_color[0] = 1.0f;
    m_color[1] = 1.0f;
    m_color[2] = 1.0f;
}

void Menu::update(double deltaTime) {

    auto& colors = ImGui::GetStyle().Colors;
    colors[ImGuiCol_WindowBg] = {0.639, 0.639, 0.639, 0.7};

    ImVec2 displaySize = ImGui::GetIO().DisplaySize;
    ImGui::SetNextWindowPos(ImVec2(0.0f, 0.0f));
    ImGui::SetNextWindowSize(ImVec2(displaySize.x / 4 - 10, displaySize.y / 4 + 30));

    ImGui::Begin("Menu", nullptr);
    ImGui::TextColored({0, 1., 0, 1.}, "FPS: %d", Application::getInstance()->getFps());
    const glm::vec3& position = Application::getInstance()->getCamera()->getPosition();
    ImGui::Text("Position: %.2f, %.2f, %.2f", position.x, position.y, position.z);

    ImGui::ColorEdit3("Color", m_color);
    Application::getInstance()->getCamera()->getShader()->setVec3("u_color", m_color[0], m_color[1], m_color[2]);
    ImGui::Text("Time: %.3f", ImGui::GetTime());
    ImGui::Text("1 - ground");
    ImGui::Text("2 - boards");
    ImGui::Text("3 - stone");
    ImGui::Text("4 - stone bricks");
    ImGui::Text("5 - red bricks");
    ImGui::Text("6 - stone");
    ImGui::Text("7 - sand");

    ImGui::End();
}