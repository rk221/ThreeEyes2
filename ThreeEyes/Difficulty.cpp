#include "Difficulty.h"

#define ICON_OFFSET_X 100
#define ICON_OFFSET_Y 100
#define ICON_INTERVAL_Y 130

static Sprite backSprite;	//背景画像
static Sprite profile[CHAR_SIZE];
static Sprite charIcon[CHAR_SIZE][2];
static BOOL mouseOnFlag[CHAR_SIZE];
static CHAR_TYPE holdChar;


void Difficulty_Initialize() {
	#define ICON_WIDTH 108
	#define ICON_HEIGHT 108
	backSprite = initSprite("images/difback.png", WINDOW_WIDTH, WINDOW_HEIGHT);
	charIcon[0][0] = initSprite("images/characters/神代凛/icon.png", ICON_WIDTH, ICON_HEIGHT);
	charIcon[0][1] = initSprite("images/characters/神代凛/iconon.png", ICON_WIDTH, ICON_HEIGHT);

	charIcon[1][0] = initSprite("images/characters/望月くるみ/icon.png", ICON_WIDTH, ICON_HEIGHT);
	charIcon[1][1] = initSprite("images/characters/望月くるみ/iconon.png", ICON_WIDTH, ICON_HEIGHT);

	charIcon[2][0] = initSprite("images/characters/中嶋美嘉/icon.png", ICON_WIDTH, ICON_HEIGHT);
	charIcon[2][1] = initSprite("images/characters/中嶋美嘉/iconon.png", ICON_WIDTH, ICON_HEIGHT);

	#define PROF_WIDTH 385
	#define PROF_HEIGHT 289
	profile[0] = initSprite("images/characters/神代凛/prof.png", PROF_WIDTH, PROF_HEIGHT);
	profile[1] = initSprite("images/characters/望月くるみ/prof.png", PROF_WIDTH, PROF_HEIGHT);
	profile[2] = initSprite("images/characters/中嶋美嘉/prof.png", PROF_WIDTH, PROF_HEIGHT);


	for (int i = 0; i < CHAR_SIZE; i++) {
		mouseOnFlag[i] = 0;
	}
}
void Difficulty_Finalize() {
	deleteSprite(&backSprite);
	for (int i = 0; i < CHAR_SIZE; i++) {
		deleteSprite(&charIcon[i][0]);
		deleteSprite(&charIcon[i][1]);
	}
}
void Difficulty_Update() {
	if (getCurrentLoadState() > 0) {
		if (isLoadEnd()) {
			setCharacter((CHAR_TYPE)(holdChar + 1), CHAR_EX_NORMAL);
			Difficulty_Finalize();
			SceneMgr_ChangeScene(SCENE_GAME);
		}
		return;
	}

	int mouseX, mouseY;
	GetMousePoint(&mouseX, &mouseY); 
	for (int i = 0; i < CHAR_SIZE; i++) {
		int a = mouseX - ICON_OFFSET_X;
		int b = mouseY - (ICON_OFFSET_Y + i * ICON_INTERVAL_Y);
		int r = charIcon[i][0].width / 2;

		if(a * a + b * b <= r * r){
			mouseOnFlag[i] = TRUE;
			holdChar = (CHAR_TYPE)i;
			if (getLeftDown()) {
				onLoadFlag(LOAD_FLUSH);
				return;
			}
		}
		else {
			mouseOnFlag[i] = FALSE;
		}
	}

}
void Difficulty_Draw() {
	drawAtSprite(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2, &backSprite, TRUE);//背景描画
	for (int i = 0; i < CHAR_SIZE; i++) {
		int alpha = 170;
		if (mouseOnFlag[i] == TRUE) {
			alpha = 255;
		}
		//SetDrawBlendMode(DX_BLENDMODE_ALPHA, alpha);
		drawAtSprite(ICON_OFFSET_X, ICON_OFFSET_Y + i * ICON_INTERVAL_Y, &charIcon[i][mouseOnFlag[i]], TRUE);
		drawAtSprite(WINDOW_WIDTH / 2 + 100, WINDOW_HEIGHT / 2, &profile[holdChar], TRUE);
		//SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
		
	} 
}