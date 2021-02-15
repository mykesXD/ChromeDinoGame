#include<SDL.h>
#include<SDL_image.h>
#include<stdio.h>
#include<stdbool.h>
#include<time.h>
#include <Windows.h>

SDL_Window *g_pWindow = 0;
SDL_Renderer *g_pRenderer = 0;
SDL_Texture* m_pTexture;
SDL_Texture* b_pTexture;
SDL_Texture* b2_pTexture;
SDL_Texture* c_pTexture;
SDL_Rect c_sourceR;
SDL_Rect c_destinationR;
SDL_Texture* c2_pTexture;
SDL_Rect f_sourceR;
SDL_Rect f_destinationR;
SDL_Texture* f_pTexture;
SDL_Rect button_sourceR;
SDL_Rect button_destinationR;
SDL_Texture* button_pTexture;
SDL_Rect c2_sourceR;
SDL_Rect c2_destinationR;
SDL_Texture* b4_pTexture;
SDL_Rect b4_sourceR;
SDL_Rect b4_destinationR;
SDL_Texture* b5_pTexture;
SDL_Rect b5_sourceR;
SDL_Rect b5_destinationR;
SDL_Texture* b3_pTexture;
SDL_Rect b3_sourceR;
SDL_Rect b3_destinationR;
SDL_Texture* c1_pTexture;
SDL_Texture* duckTexture;
SDL_Rect c1_sourceR;
SDL_Rect c1_destinationR;
SDL_Rect m_sourceR;
SDL_Rect m_destinationR;
SDL_Rect b_sourceR;
SDL_Rect b_destinationR;
SDL_Rect b2_sourceR;
SDL_Rect b2_destinationR;
SDL_Event event;
SDL_Event event1;

const Uint8 *keystate;
int fly = 0;
int mouse_x, mouse_y;
int niseh = 0;
int frame = 0;
int choice = 1;
int velo = 0;
int rectVelo = 0;
int h = 40;
int x = 80;
int speed = 5;
float timer = 10;
int gameRunning = 0;
bool exite = true;
bool start = true;
bool ducking = false;
bool dead = true;
bool end = false;
const int ground = 260;
bool g_pRunning = true;

SDL_Rect rectPlayer = { 57,248,28,45 };
SDL_Rect rectCactus = { 655,220,22,50 };
SDL_Rect rectCactusSmall = { 645,230,14,35 };
SDL_Rect rectCactusLot = { 645,230,51,50 };
SDL_Rect rectFly = { 650,180,46,35 };
SDL_Rect rectBack = { 100,200,550,90 };

void quit() {
	SDL_DestroyTexture(m_pTexture);
	SDL_DestroyTexture(b_pTexture);
	SDL_DestroyTexture(b2_pTexture);
	SDL_DestroyTexture(c_pTexture);
	SDL_DestroyTexture(c1_pTexture);
	SDL_DestroyRenderer(g_pRenderer);
	SDL_DestroyWindow(g_pWindow);
	SDL_Quit();
	exit(0);
}
void getImages() {
	SDL_Surface* b5TempSurface = IMG_Load("images/cloud.png");
	b5_pTexture = SDL_CreateTextureFromSurface(g_pRenderer, b5TempSurface);
	SDL_FreeSurface(b5TempSurface);
	b5_sourceR.w = 47;
	b5_sourceR.h = 14;
	b5_destinationR.x = 1100;
	b5_destinationR.y = 200;
	b5_destinationR.w = b5_sourceR.w;
	b5_destinationR.h = b5_sourceR.h;
	SDL_Surface* b4TempSurface = IMG_Load("images/cloud.png");
	b4_pTexture = SDL_CreateTextureFromSurface(g_pRenderer, b4TempSurface);
	SDL_FreeSurface(b4TempSurface);
	b4_sourceR.w = 47;
	b4_sourceR.h = 14;
	b4_destinationR.x = 900;
	b4_destinationR.y = 220;
	b4_destinationR.w = b4_sourceR.w;
	b4_destinationR.h = b4_sourceR.h;
	SDL_Surface* b3TempSurface = IMG_Load("images/cloud.png");
	b3_pTexture = SDL_CreateTextureFromSurface(g_pRenderer, b3TempSurface);
	SDL_FreeSurface(b3TempSurface);
	b3_sourceR.w = 47;
	b3_sourceR.h = 14;
	b3_destinationR.x = 800;
	b3_destinationR.y = 250;
	b3_destinationR.w = b3_sourceR.w;
	b3_destinationR.h = b3_sourceR.h;

	SDL_Surface* c2TempSurface = IMG_Load("images/cactuslot.png");
	c2_pTexture = SDL_CreateTextureFromSurface(g_pRenderer, c2TempSurface);
	SDL_FreeSurface(c2TempSurface);
	c2_sourceR.w = 51;
	c2_sourceR.h = 50;
	c2_destinationR.x = 1200;
	c2_destinationR.y = 220;
	c2_destinationR.w = c2_sourceR.w;
	c2_destinationR.h = c2_sourceR.h;
	SDL_Surface* c1TempSurface = IMG_Load("images/cactussmall.png");
	c1_pTexture = SDL_CreateTextureFromSurface(g_pRenderer, c1TempSurface);
	SDL_FreeSurface(c1TempSurface);
	c1_sourceR.w = 17;
	c1_sourceR.h = 35;
	c1_destinationR.x = 640;
	c1_destinationR.y = 230;
	c1_destinationR.w = c1_sourceR.w;
	c1_destinationR.h = c1_sourceR.h;
	SDL_Surface* cTempSurface = IMG_Load("images/cactus.png");
	c_pTexture = SDL_CreateTextureFromSurface(g_pRenderer, cTempSurface);
	SDL_FreeSurface(cTempSurface);
	c_sourceR.w = 25;
	c_sourceR.h = 50;
	c_destinationR.x = 600;
	c_destinationR.y = 220;
	c_destinationR.w = c_sourceR.w;
	c_destinationR.h = c_sourceR.h;
	SDL_Surface* bTempSurface = IMG_Load("images/back.png");
	b_pTexture = SDL_CreateTextureFromSurface(g_pRenderer, bTempSurface);
	SDL_FreeSurface(bTempSurface);
	b_sourceR.w = 3600;
	b_sourceR.h = 13;
	b_destinationR.x = 40;
	b_destinationR.y = 260;
	b_destinationR.w = b_sourceR.w;
	b_destinationR.h = b_sourceR.h;

	SDL_Surface* duckTempSurface = IMG_Load("images/duck.png");
	duckTexture = SDL_CreateTextureFromSurface(g_pRenderer, duckTempSurface);
	SDL_Surface* pTempSurface = IMG_Load("images/run.png");
	m_pTexture = SDL_CreateTextureFromSurface(g_pRenderer, pTempSurface);
	SDL_FreeSurface(pTempSurface);
	m_sourceR.w = 44;
	m_sourceR.h = 49;
	m_destinationR.x = 50;
	m_destinationR.y = 220;
	m_destinationR.w = m_sourceR.w;
	m_destinationR.h = m_sourceR.h;

	SDL_Surface* fTempSurface = IMG_Load("images/fly.png");
	f_pTexture = SDL_CreateTextureFromSurface(g_pRenderer, fTempSurface);
	SDL_FreeSurface(fTempSurface);
	f_sourceR.w = 46;
	f_sourceR.h = 42;
	f_destinationR.x = 650;
	f_destinationR.y = 180;
	f_destinationR.w = f_sourceR.w;
	f_destinationR.h = f_sourceR.h;
}
void input() {
	SDL_PollEvent(&event);

	if (m_destinationR.y + h < ground)
	{
		velo += 1;
	}
	else
	{
		velo = 0;
		m_destinationR.y = ground - h;
	}
	m_destinationR.y += velo;
	if (rectPlayer.y + h < ground)
	{
		rectVelo += 1;
	}
	else
	{
		rectVelo = 0;
		rectPlayer.y = ground - h;
	}


	rectPlayer.y += rectVelo;
	if (event.type == SDL_KEYDOWN)
	{
		switch (event.key.keysym.sym)
		{
		case SDLK_SPACE:
			start = false;
			if (m_destinationR.y + h == ground) {
				m_destinationR.y--;
				velo = -15;
				if (rectPlayer.y + h == ground) {
					rectPlayer.y--;
					rectVelo = -15;
				}
			}
			break;
		case SDLK_0:
			exite = false;
			break;

		}

	}
	else if (event.type == SDL_KEYUP) {
		switch (event.key.keysym.sym)
		{
		case SDLK_DOWN:
			ducking = true;
			frame += 1000;
		}
	}

}

bool init(const char* title, int xpos, int ypos, int
	height, int width, int flags)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) >= 0)
	{
		g_pWindow = SDL_CreateWindow(title, xpos, ypos,
			height, width, flags);

		if (g_pWindow != 0)
		{
			g_pRenderer = SDL_CreateRenderer(g_pWindow, -1, SDL_RENDERER_PRESENTVSYNC);
		}
	}
	else
	{
		return false;
	}
	getImages();
}
void update()
{
	SDL_UpdateWindowSurface(g_pWindow);
	frame++;
	//printf("%d\n", frame);
	b_destinationR.x -= 5;
	if (b_destinationR.x == -2620) {
		b_destinationR.x = 0;
	}
	m_sourceR.x = 44 * (((SDL_GetTicks() / 100) % 2));

	f_sourceR.x = 46 * (((SDL_GetTicks() / 100) % 2));


}
void enemy() {
	int flyChance;
	int flyHeight;
	int distance, distance2, distance3;
	int cloudChance = 0;
	c_destinationR.x -= speed;
	b3_destinationR.x -= 2;
	b4_destinationR.x -= 2;
	b5_destinationR.x -= 2;
	cloudChance = rand() / 10 + 1;
	if (b3_destinationR.x < 0) {
		b3_destinationR.x = 620;
		if (cloudChance == 8) {
			b3_destinationR.y = 200;
		}
	}
	if (b5_destinationR.x < 0) {
		b5_destinationR.x = 620;
		if (cloudChance == 8) {
			b5_destinationR.y = 200;
		}
	}
	if (b4_destinationR.x < 0) {
		b4_destinationR.x = 620;
		if (cloudChance == 6) {
			b4_destinationR.y = 250;
		}
	}
	if (fly > 200) {
		c1_destinationR.x -= speed;
	}
	fly++;
	flyHeight = rand() % 700 + 10;
	if (fly > 500) {
		f_destinationR.x -= 6;
	}
	flyChance = rand() % 700 + 10;
	if ((f_destinationR.x < -100 && flyChance == 35) && ((c_destinationR.x > 0 && c_destinationR.x < 400) && (c1_destinationR.x > 0 && c1_destinationR.x < 500))) {
		f_destinationR.x = 650;
		rectFly.x = 650;
	}
	else if ((f_destinationR.x < -200 && flyChance == 50) && ((c_destinationR.x > 0 && c_destinationR.x < 400) && (c1_destinationR.x > 0 && c1_destinationR.x < 500))) {
		f_destinationR.x = 650;
		rectFly.x = 650;
		f_destinationR.y = 220;
		rectFly.y = 220;
	}
	rectFly.x = f_destinationR.x;
	rectCactus.x = c_destinationR.x + 2;
	rectCactusSmall.x = c1_destinationR.x + 2;
	int cactusChance;
	cactusChance = rand() / 30 + 4;
	if (c_destinationR.x < -4) {
		if (cactusChance > 13) {
			c_destinationR.x = 650;
		}
	}
	else if (c1_destinationR.x < -4) {
		if (cactusChance <= 13) {
			c1_destinationR.x = 650;
		}
	}
	else if (c2_destinationR.x < -4) {
		if (cactusChance % 10 == 0) {
			c2_destinationR.x = 650;
		}
	}
	SDL_bool collision = SDL_HasIntersection(&rectPlayer, &rectCactus);
	if (collision) {
		dead = false;
	}
	SDL_bool collision1 = SDL_HasIntersection(&rectPlayer, &rectCactusSmall);
	if (collision1) {
		dead = false;
	}
	SDL_bool collision3 = SDL_HasIntersection(&rectPlayer, &rectFly);
	if (collision3) {
		dead = false;
	}
	SDL_bool collision2 = SDL_HasIntersection(&rectPlayer, &rectCactusLot);
	if (collision2) {
		dead = false;
	}
	SDL_bool collision4 = SDL_HasIntersection(&rectCactus, &rectCactusSmall);
	if (collision4) {
		c1_destinationR.x = 650;
	}

}
void render()
{
	SDL_SetRenderDrawColor(g_pRenderer, 242, 242, 242, 255);
	SDL_RenderClear(g_pRenderer);
	SDL_RenderCopy(g_pRenderer, b3_pTexture, &b3_sourceR, &b3_destinationR);
	SDL_RenderCopy(g_pRenderer, b4_pTexture, &b4_sourceR, &b4_destinationR);
	SDL_RenderCopy(g_pRenderer, b5_pTexture, &b5_sourceR, &b5_destinationR);
	SDL_RenderCopy(g_pRenderer, c_pTexture, &c_sourceR, &c_destinationR);
	SDL_RenderCopy(g_pRenderer, c2_pTexture, &c2_sourceR, &c2_destinationR);
	SDL_RenderCopy(g_pRenderer, c1_pTexture, &c1_sourceR, &c1_destinationR);
	SDL_RenderCopy(g_pRenderer, b_pTexture, &b_sourceR, &b_destinationR);
	SDL_RenderCopy(g_pRenderer, f_pTexture, &f_sourceR, &f_destinationR);
	SDL_RenderCopy(g_pRenderer, m_pTexture, &m_sourceR, &m_destinationR);

	SDL_SetRenderDrawColor(g_pRenderer, 242, 242, 242, 255);
	SDL_RenderFillRect(g_pRenderer, &rectBack);
	if (dead == false) {
		SDL_Surface* buttonTempSurface = IMG_Load("images/gameover.png");
		button_pTexture = SDL_CreateTextureFromSurface(g_pRenderer, buttonTempSurface);
		SDL_FreeSurface(buttonTempSurface);
		button_sourceR.w = 196;
		button_sourceR.h = 68;
		button_destinationR.x = 190;
		button_destinationR.y = 130;
		button_destinationR.w = button_sourceR.w;
		button_destinationR.h = button_sourceR.h;
		SDL_RenderCopy(g_pRenderer, button_pTexture, &button_sourceR, &button_destinationR);
	}
	/*
	SDL_SetRenderDrawColor(g_pRenderer, 0, 255, 0, 255);
	SDL_RenderFillRect(g_pRenderer, &rectPlayer);
	SDL_SetRenderDrawColor(g_pRenderer, 0, 0, 255, 255);
	SDL_RenderFillRect(g_pRenderer, &rectCactus);
	SDL_SetRenderDrawColor(g_pRenderer, 0, 0, 255, 255);
	SDL_RenderFillRect(g_pRenderer, &rectCactusSmall);
	SDL_SetRenderDrawColor(g_pRenderer, 0, 0, 255, 255);
	SDL_RenderFillRect(g_pRenderer, &rectCactusLot);
	SDL_SetRenderDrawColor(g_pRenderer, 0, 0, 255, 20);
	SDL_RenderFillRect(g_pRenderer, &rectFly);
	*/


	SDL_RenderPresent(g_pRenderer);
}
int main(int argc, char* args[]) {
	if (init("Dino Game by Mykes", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 600, 480, SDL_WINDOW_SHOWN)) {
		g_pRunning = true;
		//HWND windowHandle = GetConsoleWindow();
		//ShowWindow(windowHandle, SW_HIDE);
	}
	else {
		return 1;
	}
	while (gameRunning == 0) {
		srand(time(NULL));
		while (start) {
			input();
			render();
		}
		while (g_pRunning && dead) {
			if (event.type == SDL_QUIT) {
				quit();
			}
			SDL_PumpEvents();

			rectBack.x += 10;

			input();
			update();
			enemy();
			render();
			timer -= 0.001;
			SDL_Delay(timer);
		}
		while (exite) {
			render();
			SDL_PollEvent(&event);
			switch (event.type) {
			case SDL_MOUSEMOTION:
				mouse_x = event.motion.x;
				mouse_y = event.motion.y;
				//printf("%d , %d\n", mouse_x, mouse_y);
				break;
			case SDL_MOUSEBUTTONDOWN:
				if ((mouse_x > 270 && mouse_x < 304) && (mouse_y > 162 && mouse_y < 192)) {
					gameRunning = 1;
				}
				break;
			case SDL_QUIT:
				quit();
				break;
			}
		}
	}
	return 0;
}

