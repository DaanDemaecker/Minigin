#include <SDL.h>

#if _DEBUG
// ReSharper disable once CppUnusedIncludeDirective
#if __has_include(<vld.h>)
#include <vld.h>
#endif
#endif

#include "minigin.h"
#include "SceneManager.h"
#include "ResourceManager.h"
#include "Scene.h"
#include "GameObject.h"
#include "Transform.h"
#include "RenderComponent.h"
#include "Renderer.h"
#include "TextComponent.h"
#include "FPSCounter.h"

void load()
{
	auto& scene = dae::SceneManager::GetInstance().CreateScene("Demo");

	const auto pFont{ dae::ResourceManager::GetInstance().LoadFont("Lingua.otf", 36) };
	const auto pFont2{ dae::ResourceManager::GetInstance().LoadFont("Lingua.otf", 15) };
	const auto pBackgroundTexture{ dae::ResourceManager::GetInstance().LoadTexture("background.tga") };
	const auto pLogoTexture{ dae::ResourceManager::GetInstance().LoadTexture("logo.tga") };

	const auto pBackground{ std::make_shared<dae::GameObject>()};
	scene.Add(pBackground);
	const auto pBackgroundTransform{ pBackground->AddComponent<dae::Transform>() };
	pBackground->AddComponent<dae::RenderComponent>()->SetTexture(pBackgroundTexture);

	const auto pLogo{ std::make_shared<dae::GameObject>() };
	scene.Add(pLogo);
	pLogo->AddComponent<dae::Transform>()->SetPosition(216.f, 180.f);
	pLogo->AddComponent<dae::RenderComponent>()->SetTexture(pLogoTexture);

	const auto pHeader{ std::make_shared<dae::GameObject>() };
	scene.Add(pHeader);
	pHeader->AddComponent<dae::Transform>()->SetPosition(80.f, 20.f);
	pHeader->AddComponent<dae::RenderComponent>();
	const auto pHeaderText{ pHeader->AddComponent<dae::TextComponent>() };
	pHeaderText->SetFont(pFont);
	pHeaderText->SetText("Programming 4 Assignment");

	const auto fPSCounter{ std::make_shared<dae::GameObject>() };
	scene.Add(fPSCounter);
	fPSCounter->AddComponent<dae::Transform>()->SetPosition(0.0f, 0.0f);
	fPSCounter->AddComponent<dae::RenderComponent>();
	fPSCounter->AddComponent<dae::FPSCounter>();
	const auto pText{ fPSCounter->AddComponent<dae::TextComponent>() };
	pText->SetFont(pFont2);
	pText->SetColor(255, 255, 0);
}

int main(int, char*[]) {
	dae::Minigin engine("../Data/");
	engine.Run(load);
    return 0;
}