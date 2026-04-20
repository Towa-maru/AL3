#include "GameScene.h"

using namespace KamataEngine;

void GameScene::Initialize() {
	textureHandle_ = TextureManager::Load("uvChecker.png");
	// sprite_ = Sprite::Create(textureHandle_, {100, 50});
	// delete sprite_;
	model_ = Model::Create();

	worldTransform_.Initialize();
	camera_.Initialize();

	debugCamera_ = new DebugCamera(1280, 720);

	AxisIndicator::GetInstance()->SetVisible(true);
	AxisIndicator::GetInstance()->SetTargetCamera(&debugCamera_->GetCamera());
}

void GameScene::Update() { debugCamera_->Update(); }

void GameScene::Draw() {
	Model::PreDraw();

	model_->Draw(worldTransform_, debugCamera_->GetCamera(), textureHandle_);

	Model::PreDraw();
}