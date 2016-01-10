#include "Global.hpp"
#include "GameState.hpp"

#include <utility>
#include <boost/interprocess/managed_shared_memory.hpp>

GameState::GameState() {
	{
		using namespace boost::interprocess;
		melee_mem = managed_shared_memory{open_only, "MeleeAI"};
	}
}

void GameState::UpdateAddress(int n) {
  std::pair<long*, std::size_t> melee_read_address = melee_mem.find<long>("game_data");
  raw_input[n] = *(melee_read_address.first + n);
}

int GameState::Stocks(int player) {
  UpdateAddress(player - 1);  
  return raw_input[player - 1];
}

int GameState::Percent(int player) { 
  UpdateAddress(2 + (player - 1));
  return raw_input[2 + (player - 1)];
}

int GameState::CharacterID(int player) {
  UpdateAddress(4 + (player - 1));
  return raw_input[4 + (player - 1)];
}

std::pair<float, float> GameState::Coordinates(int player) {
  UpdateAddress(6 + 2 * (player - 1));
  UpdateAddress(7 + 2 * (player - 1));
  float x = LongToFloat(raw_input[6 + 2 * (player - 1)]);
  float y = LongToFloat(raw_input[7 + 2 * (player - 1)]);
  return std::make_pair(x, y);
}

int GameState::StageID() {
  UpdateAddress(10);
  return raw_input[10];
}

int GameState::FrameCount() {
  UpdateAddress(11);
  return raw_input[11];
}

int GameState::P2Hitstun() {
  UpdateAddress(12);
  return LongToFloat(raw_input[12]);
}

float GameState::P2VerticalVelocity() {
  UpdateAddress(13);
  return LongToFloat(raw_input[13]);
}

long GameState::P2ActionState() {
  UpdateAddress(14);
  return raw_input[14];
}

int GameState::P2Hitlag() {
  UpdateAddress(15);
  return LongToFloat(raw_input[15]);
}

int GameState::P2JumpsUsed() {
  UpdateAddress(16);
  return raw_input[16];
}

float GameState::P2ShieldSize() {
  UpdateAddress(17);
  return LongToFloat(raw_input[17]);
}  

bool GameState::P2InAir() {
  UpdateAddress(18);
  return raw_input[18];
}

long GameState::Raw(int n) {
  UpdateAddress(n);
  return raw_input[n];
}

//TODO: find a way to check in game without wasting time
bool GameState::InGame() {
  int last_frame = FrameCount();
  GLOBAL_SLEEP(30);
  return last_frame != FrameCount();
}

float GameState::LongToFloat(long n) {
  union LongFloat {
    long lg;
    float fl;
  };
  union LongFloat ret;
  ret.lg = n;
  return ret.fl;
}
