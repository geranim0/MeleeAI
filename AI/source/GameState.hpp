#ifndef GAME_STATE_HPP
#define GAME_STATE_HPP

#define MEM_SIZE 19

#include <utility>
#include <stdint.h>

class GameState {

private:

  float LongToFloat(long);

protected:

	uint32_t raw_input[MEM_SIZE];
  
public:
	
	virtual ~GameState() {}
	
  virtual void UpdateAddress(int) = 0;

  int Stocks(int);
  int Percent(int);
  int CharacterID(int);
  std::pair<float, float> Coordinates(int);
  int StageID();
  int FrameCount();
  bool InGame();
  
  //TODO: have a function that waits for the next frame in the game
  int P2Hitstun();
  float P2VerticalVelocity();
  long P2ActionState();
  int P2Hitlag();
  int P2JumpsUsed();
  float P2ShieldSize();
  bool P2InAir();

  uint8_t  Read8(int);
  uint16_t Read16(int);

  uint32_t Raw(int); //get raw data from dolphin

};

#endif



