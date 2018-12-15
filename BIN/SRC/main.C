/***********************
*  LITTLE GAME ENGINE  *
************************/

/*##########################################################################
	A lot of code from David Brackeen                                   
	http://www.brackeen.com/home/vga/                                     

	Sprite loader and bliter from xlib
	
	This is a 16-bit program, Remember to compile in the LARGE memory model!                        
	
	All code is 8086 / 8088 compatible
	
	Please feel free to copy this source code.                            
	

	LT_MODE = player movement modes

	//MODE TOP = 0;
	//MODE PLATFORM = 1;
	//MODE PUZZLE = 2;
	//MODE SIDESCROLL = 3;
	
	//33 fixed sprites:
	//	8x8   (16 sprites: 0 - 15)	
	//	16x16 (12 sprites: 16 - 27)
	//	32x32 ( 4 sprites: 28 - 31)
	//	64x64 ( 1 sprite: 32)
	
##########################################################################*/

#include "lt__eng.h"

LT_Col LT_Player_Col;

int x,y = 0;
int i,j = 0;
int Scene = 0;

void Load_Puzzle2(){
	LT_Set_Loading_Interrupt(); 
	
	Scene = 2;
	LT_Load_Map("GFX/sample.tmx");
	LT_Load_Tiles("GFX/atiles.bmp");
	LT_Load_Sprite("GFX/aball.bmp",16,16);
	LT_Clone_Sprite(17,16);
	LT_Clone_Sprite(18,16);
	LT_Clone_Sprite(19,16);
	LT_Clone_Sprite(20,16);
	LT_Clone_Sprite(21,16);
	LT_Clone_Sprite(22,16);
	LT_Clone_Sprite(23,16);
	
	//LT_Load_Music("music/ADLIB/top_down.imf");
	
	LT_Delete_Loading_Interrupt();
	//LT_Start_Music(70);
	
	LT_Set_Map(0,0);
	LT_MODE = 0; 
}

void Run_Puzzle2(){
	int n = 0;
	int score = 0;
	Scene = 2;
	
	sprite[16].pos_x = 4*16;
	sprite[16].pos_y = 8*16;
	sprite[16].speed_x = 1;
	sprite[16].speed_y = -1;
	sprite[17].pos_x = 5*16;
	sprite[17].pos_y = 5*16;
	sprite[17].speed_x = -1;
	sprite[17].speed_y = -1;
	sprite[18].pos_x = 6*16;
	sprite[18].pos_y = 12*16;
	sprite[18].speed_x = 1;
	sprite[18].speed_y = 1;
	sprite[19].pos_x = 7*16;
	sprite[19].pos_y = 8*16;
	sprite[19].speed_x = -1;
	sprite[19].speed_y = -1;
	sprite[20].pos_x = 8*16;
	sprite[20].pos_y = 4*16;
	sprite[20].speed_x = 1;
	sprite[20].speed_y = 1;
	sprite[21].pos_x = 9*16;
	sprite[21].pos_y = 11*16;
	sprite[21].speed_x = 1;
	sprite[21].speed_y = -1;
	sprite[22].pos_x = 10*16;
	sprite[22].pos_y = 13*16;
	sprite[22].speed_x = 1;
	sprite[22].speed_y = -1;
	sprite[23].pos_x = 11*16;
	sprite[23].pos_y = 6*16;
	sprite[23].speed_x = 1;
	sprite[23].speed_y = 1;
	
	while(Scene == 2){
		LT_WaitVsyncEnd();

		for (n = 19; n != 15; n--) LT_Restore_Sprite_BKG(n);
		for (n = 16; n != 20; n++) LT_Draw_Sprite(n);
		for (n = 16; n != 20; n++) LT_Bounce_Ball(n);

		if (LT_Keys[LT_ESC]) Scene = 1; //esc exit
		
		LT_WaitVsyncStart();
	}
	LT_Unload_Sprite(16); //manually free sprites
}


void main(){

	system("cls");

	LT_Init_GUS(12);
    LT_init();
	
	//You can use a custom loading animation for the Loading_Interrupt
	LT_Load_Animation("GFX/loading.bmp",32);
	LT_Set_Animation(0,4,2);
	
	Load_Puzzle2();
	Run_Puzzle2();
	
	LT_ExitDOS();
	
}
