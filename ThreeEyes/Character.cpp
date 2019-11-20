#include "Character.h"

static Sprite character[CHAR_SIZE][CHAR_EX_SIZE];
static CHAR_TYPE currentChar;
static CHAR_EXPRESSION currentCharEx;
static Sprite message[CHAR_MG_SIZE];//ゲームメッセージ
static CHAR_MESSAGE currentMessage;
static BOOL messageFlag;
static BOOL drawFlag;

void initCharacter(void) {
	currentChar = NONE;
	currentCharEx = CHAR_EX_NORMAL;
	messageFlag = FALSE;
	drawFlag = FALSE;
	//画像サイズ要変更
#define CHAR_WIDTH 200
#define CHAR_HEIGHT 550
		
		
		
		
		
	character[0][CHAR_EX_NORMAL] = initSprite("images/characters/神代凛/normal.png", CHAR_WIDTH, CHAR_HEIGHT);
	character[0][CHAR_EX_THINK] = initSprite("images/characters/神代凛/think.png", CHAR_WIDTH, CHAR_HEIGHT);
	character[0][CHAR_EX_LOSING] = initSprite("images/characters/神代凛/losing.png", CHAR_WIDTH, CHAR_HEIGHT);
	character[0][CHAR_EX_WINNING] = initSprite("images/characters/神代凛/winning.png", CHAR_WIDTH, CHAR_HEIGHT);
	character[0][CHAR_EX_WIN] = initSprite("images/characters/神代凛/win.png", CHAR_WIDTH, CHAR_HEIGHT);
	character[0][CHAR_EX_LOSE] = initSprite("images/characters/神代凛/lose.png", CHAR_WIDTH, CHAR_HEIGHT);

	character[1][CHAR_EX_NORMAL] = initSprite("images/characters/望月くるみ/normal.png", CHAR_WIDTH, CHAR_HEIGHT);
	character[1][CHAR_EX_THINK] = initSprite("images/characters/望月くるみ/think.png", CHAR_WIDTH, CHAR_HEIGHT);
	character[1][CHAR_EX_LOSING] = initSprite("images/characters/望月くるみ/losing.png", CHAR_WIDTH, CHAR_HEIGHT);
	character[1][CHAR_EX_WINNING] = initSprite("images/characters/望月くるみ/winning.png", CHAR_WIDTH, CHAR_HEIGHT);
	character[1][CHAR_EX_WIN] = initSprite("images/characters/望月くるみ/win.png", CHAR_WIDTH, CHAR_HEIGHT);
	character[1][CHAR_EX_LOSE] = initSprite("images/characters/望月くるみ/lose.png", CHAR_WIDTH, CHAR_HEIGHT);

	character[2][CHAR_EX_NORMAL] = initSprite("images/characters/中嶋美嘉/normal.png", CHAR_WIDTH, CHAR_HEIGHT);
	character[2][CHAR_EX_THINK] = initSprite("images/characters/中嶋美嘉/think.png", CHAR_WIDTH, CHAR_HEIGHT);
	character[2][CHAR_EX_LOSING] = initSprite("images/characters/中嶋美嘉/losing.png", CHAR_WIDTH, CHAR_HEIGHT);
	character[2][CHAR_EX_WINNING] = initSprite("images/characters/中嶋美嘉/winning.png", CHAR_WIDTH, CHAR_HEIGHT);
	character[2][CHAR_EX_WIN] = initSprite("images/characters/中嶋美嘉/win.png", CHAR_WIDTH, CHAR_HEIGHT);
	character[2][CHAR_EX_LOSE] = initSprite("images/characters/中嶋美嘉/lose.png", CHAR_WIDTH, CHAR_HEIGHT);

}
void deleteCharacter(void) {
	for (int i = 0; i < CHAR_SIZE; i++) {
		for (int j = 0; j < CHAR_SIZE; j++) {
			deleteSprite(&character[i][j]);
		}
	}
}


void Character_Draw() {
	if (currentChar != NONE) {
		drawSprite(-20, WINDOW_HEIGHT * 0.4, &character[currentChar - 1][currentCharEx], TRUE);
	}
	if (messageFlag) {
		//座標をゲームによって変える　シーン
		
		drawSprite(0, 0, &message[currentMessage], TRUE);
	}
}


void setCharacter(CHAR_TYPE type, CHAR_EXPRESSION charEx) {
#define MESSAGE_WIDTH 200
#define MESSAGE_HEIGHT 200
	drawFlag = TRUE;
	currentChar = type;
	switch (type) {
	case CHAR_EASY:
		message[0] = initSprite("images/characters/神代凛/message/normal.png", MESSAGE_WIDTH, MESSAGE_HEIGHT);
		message[1] = initSprite("images/characters/神代凛/message/think.png", MESSAGE_WIDTH, MESSAGE_HEIGHT);
		message[2] = initSprite("images/characters/神代凛/message/losing.png", MESSAGE_WIDTH, MESSAGE_HEIGHT);
		message[3] = initSprite("images/characters/神代凛/message/winning.png", MESSAGE_WIDTH, MESSAGE_HEIGHT);
		message[4] = initSprite("images/characters/神代凛/message/win.png", MESSAGE_WIDTH, MESSAGE_HEIGHT);
		message[5] = initSprite("images/characters/神代凛/message/lose.png", MESSAGE_WIDTH, MESSAGE_HEIGHT);
		break;
	case CHAR_NORMAL:
		message[0] = initSprite("images/characters/望月くるみ/message/normal.png", MESSAGE_WIDTH, MESSAGE_HEIGHT);
		message[1] = initSprite("images/characters/望月くるみ/message/think.png", MESSAGE_WIDTH, MESSAGE_HEIGHT);
		message[2] = initSprite("images/characters/望月くるみ/message/losing.png", MESSAGE_WIDTH, MESSAGE_HEIGHT);
		message[3] = initSprite("images/characters/望月くるみ/message/winning.png", MESSAGE_WIDTH, MESSAGE_HEIGHT);
		message[4] = initSprite("images/characters/望月くるみ/message/win.png", MESSAGE_WIDTH, MESSAGE_HEIGHT);
		message[5] = initSprite("images/characters/望月くるみ/message/lose.png", MESSAGE_WIDTH, MESSAGE_HEIGHT);
		break;
	case CHAR_DIF:
		message[0] = initSprite("images/characters/中嶋美嘉/message/normal.png", MESSAGE_WIDTH, MESSAGE_HEIGHT);
		message[1] = initSprite("images/characters/中嶋美嘉/message/think.png", MESSAGE_WIDTH, MESSAGE_HEIGHT);
		message[2] = initSprite("images/characters/中嶋美嘉/message/losing.png", MESSAGE_WIDTH, MESSAGE_HEIGHT);
		message[3] = initSprite("images/characters/中嶋美嘉/message/winning.png", MESSAGE_WIDTH, MESSAGE_HEIGHT);
		message[4] = initSprite("images/characters/中嶋美嘉/message/win.png", MESSAGE_WIDTH, MESSAGE_HEIGHT);
		message[5] = initSprite("images/characters/中嶋美嘉/message/lose.png", MESSAGE_WIDTH, MESSAGE_HEIGHT);
		break;


	}
}

void setCharacterExpression(CHAR_EXPRESSION charEx) {
	currentCharEx = charEx;
}

void setCharacterMessage(CHAR_MESSAGE charMsg) {
	currentMessage = charMsg;
}

void setMessageFlag(BOOL flag) {
	messageFlag = flag;
}

void clearCharacter() {
	currentChar = NONE;
	drawFlag = FALSE;
	messageFlag = FALSE;
}
