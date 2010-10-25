
#include <time.h>
#include "GameState.h"
#include "MainView.h"
#include "IntroView.h"
#include "PlayerCreateView.h"
#include "DataManager.h"

GameState::GameState(unsigned long seed) : 
	m_seed(seed), m_isRunning(true), m_currentView(NULL), 
	m_state(GAME_STATE_INITIAL) {
}

GameState::~GameState() {
	if(m_currentView) {
		delete m_currentView;
	}
}

void GameState::Initialize() {
	// use this for any init that isn't simple variable defaults
	if(m_seed == 0) {
		m_seed = time(NULL);
	}
	srand(m_seed);
	DataManager::Instance()->CreateNewGame();
	m_currentView = new IntroView(this, 80, 24);
	m_currentView->Initialize();
	m_views["intro"] = m_currentView;
}

void GameState::Update() {
	if(m_isRunning) {
		m_currentView->Update();
		m_currentView->Draw();
		m_currentView->RequestInput();
	}
}

bool GameState::IsRunning() {
	return m_isRunning;
}

void GameState::RequestQuit() {
	m_isRunning = false;
}

void GameState::ChangeState(StateType newState) {
	switch(newState) {
		case GAME_STATE_PLAYER_CREATE:
			if(m_views.find("player_create") == m_views.end()) {
				m_currentView = new PlayerCreateView(this, 80, 24);
				m_currentView->Initialize();
				m_views["player_create"] = m_currentView;
			}
			else {
				m_currentView = m_views["player_create"];
			}
			break;
		case GAME_STATE_MAIN:
			if(m_views.find("main") == m_views.end()) {
				m_currentView = new MainView(this, 80, 24);
				m_currentView->Initialize();
				m_views["main"] = m_currentView;
			}
			else {
				m_currentView = m_views["main"];
			}
			break;
		default:
			// should probably do something here
			break;
	}
	m_state = newState;
}
