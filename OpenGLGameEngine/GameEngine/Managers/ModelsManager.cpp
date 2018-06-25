#include "ModelsManager.h"

using namespace GameEngine::Managers;
using namespace GameEngine::Rendering;

ModelsManager::ModelsManager()
{
	
	Models::Triangle* triangle = new Models::Triangle();
	triangle->SetProgram(ShaderManager::GetShader("colourShader"));
	triangle->Create();
	gameModelList["triangle"] = triangle;

	Models::Quad* quad = new Models::Quad();
	quad->SetProgram(ShaderManager::GetShader("colourShader"));
	quad->Create();
	gameModelList["quad"] = quad;
}

ModelsManager::~ModelsManager()
{
	for (auto model : gameModelList)
		delete model.second;

	gameModelList.clear();
}

void ModelsManager::DeleteModel(const std::string& gameModelName)
{
	IGameObject* model = gameModelList[gameModelName];
	model->Destroy();
	gameModelList.erase(gameModelName);
}

void ModelsManager::SetModel(const std::string& gameModelName, IGameObject* gameModel) 
{ 
	if (gameModelList.find(gameModelName) != gameModelList.end())
		gameModelList[gameModelName] = gameModel;
	else
		gameModelList.insert(std::pair<std::string, IGameObject*>(gameModelName, gameModel));
}

const IGameObject& ModelsManager::GetModel(const std::string& gameModelName) const
{
	return (*gameModelList.at(gameModelName));
}

void ModelsManager::Update()
{
	for (auto model : gameModelList)
		model.second->Update();
}

void ModelsManager::Draw()
{
	for (auto model : gameModelList)
		model.second->Draw();
}

void ModelsManager::Draw(const glm::mat4& projectionMatrix, const glm::mat4& viewMatrix)
{
	for (auto model : gameModelList)
		model.second->Draw(projectionMatrix, viewMatrix);
}