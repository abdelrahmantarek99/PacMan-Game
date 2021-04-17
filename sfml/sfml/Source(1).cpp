#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include <fstream>
#include <vector>


using namespace std;
using namespace sf;

RenderWindow window(VideoMode(1008, 604), "SFML ");

int go, mouse_move, score, dir_ghost1, dir_ghost2, dir_ghost3, dir_ghost4, lastscore;
Texture pac, mylevel, black, selecet, start, t_ghost1, t_ghost2, t_ghost3, t_ghost4;
Font font, font2;

int intt, neww = 0;
float edite_speed;
string  str2 = "0", strnew;


String Player_score = "0", str_best = "Best_Score", str_best2 = strnew;
int level, lifes, disapper;
bool okay = 1, stop, stop2, stop3, stop4, del[30], transformm, lw = 0;
Sprite sfruits[100];
Texture fruits[100];

Texture press, gameover, win, life, t_scoreboard, t_scoreboard2;
Sprite Press_space(press), GameOver(gameover), Win(win), Life[4], s_scoreboard(t_scoreboard), s_scoreboard2(t_scoreboard2);

Vector2i source(10, 0);
Text text(Player_score, font, 40), text2(str_best, font2, 30);


Sprite  sahm(selecet), s_ghost1(t_ghost1), s_ghost2(t_ghost2), s_ghost3(t_ghost3), s_ghost4(t_ghost4);
Sprite  intro(start);
int enter, strt;
Sprite PacMan(pac);
Sprite mylevel_(mylevel);
Sprite black_(black);
Texture gold_key;
Sprite gold(gold_key);
string sentence;
Text textname(sentence, font2, 30);


bool valid1(float x, float y)
{
	//0-1
	if ((x + 32 >= 0 && x <600) && (y + 32 >= 0 && y<10))
		return 0;
	//0-2
	if ((x + 32 >= 0 && x <10) && (y + 32 >= 0 && y<185))
		return 0;
	//0-3
	if ((x + 32 >= 586 && x <600) && (y + 32 >= 0 && y<185))
		return 0;
	//0-4
	if ((x + 32 >= 0 && x <10) && (y + 32 >= 376 && y<600))
		return 0;
	//0-5
	if ((x + 32 >= 586 && x <600) && (y + 32 >= 376 && y<600))
		return 0;
	//0-6
	if ((x + 32 >= 0 && x <600) && (y + 32 >= 593 && y<600))
		return 0;
	//1
	if ((x + 32 >= 55 && x <115) && (y + 32 >= 51 && y<86))
		return 0;
	//2
	if ((x + 32 >= 162 && x  <240) && (y + 32 >= 51 && y<86))
		return 0;
	//3
	if ((x + 32 >= 350 && x  < 432) && (y + 32 >= 51 && y<86))
		return 0;
	//4
	if ((x + 32 >= 478 && x  <539) && (y + 32 >= 51 && y<86))
		return 0;
	//5
	if ((x + 32 >= 287 && x  <306) && (y + 32 >= 0 && y<86))
		return 0;
	//6
	if ((x + 32 >= 55 && x <116) && (y + 32 >= 129 && y<146))
		return 0;
	//7
	if ((x + 32 >= 478 && x <539) && (y + 32 >= 129 && y<146))
		return 0;
	//8
	if ((x + 32 >= 224 && x  <368) && (y + 32 >= 129 && y<146))
		return 0;
	//9
	if ((x + 32 >= 162 && x <179) && (y + 32 >= 129 && y<259))
		return 0;
	//10
	if ((x + 32 >= 414 && x  <432) && (y + 32 >= 129 && y<259))
		return 0;
	//11
	if ((x + 32 >= 287 && x <306) && (y + 32 >= 145 && y<202))
		return 0;
	//12
	if ((x + 32 >= 350 && x <432) && (y + 32 >= 185 && y<202))
		return 0;
	//13
	if ((x + 32 >= 162 && x  <240) && (y + 32 >= 185 && y<202))
		return 0;
	//14
	if ((x + 32 >= 224 && x <231) && (y + 32 >= 248 && y<319))
		return 0;
	//14-1
	if ((x + 32 >= 225 && x  <368) && (y + 32 >= 312 && y<319))
		return 0;
	//15
	if ((x + 32 >= 360 && x <368) && (y + 32 >= 248 && y<319))
		return 0;
	//15-1
	if ((x + 32 >= 318 && x  <368) && (y + 32 >= 248 && y<252))
		return 0;
	//15-2
	if ((x + 32 >= 225 && x  <275) && (y + 32 >= 248 && y<252))
		return 0;
	//16
	if ((x + 32 >= 162 && x <179) && (y + 32 >= 308 && y<376))
		return 0;
	//17
	if ((x + 32 >= 414 && x  <432) && (y + 32 >= 308 && y<376))
		return 0;
	//18
	if ((x + 32 >= 0 && x <116) && (y + 32 >= 185 && y<259))
		return 0;
	//19
	if ((x + 32 >= 478 && x  <600) && (y + 32 >= 185 && y<259))
		return 0;
	//20
	if ((x + 32 >= 0 && x <116) && (y + 32 >= 308 && y<376))
		return 0;
	//21
	if ((x + 32 >= 478 && x  <600) && (y + 32 >= 308 && y<376))
		return 0;
	//22
	if ((x + 32 >= 225 && x  <368) && (y + 32 >= 360 && y<376))
		return 0;
	//23
	if ((x + 32 >= 287 && x <306) && (y + 32 >= 360 && y<435))
		return 0;
	//24
	if ((x + 32 >= 55 && x <115) && (y + 32 >= 420 && y<435))
		return 0;
	//24-1
	if ((x + 32 >= 97 && x <115) && (y + 32 >= 420 && y<493))
		return 0;
	//25
	if ((x + 32 >= 162 && x  <240) && (y + 32 >= 420 && y<435))
		return 0;
	//26
	if ((x + 32 >= 350 && x  < 432) && (y + 32 >= 420 && y<435))
		return 0;
	//27
	if ((x + 32 >= 478 && x  <539) && (y + 32 >= 420 && y<435))
		return 0;
	//27-1
	if ((x + 32 >= 478 && x  <493) && (y + 32 >= 420 && y<493))
		return 0;
	//29
	if ((x + 32 >= 0 && x  <50) && (y + 32 >= 478 && y<493))
		return 0;
	//30
	if ((x + 32 >= 543 && x  <600) && (y + 32 >= 478 && y<493))
		return 0;
	//31
	if ((x + 32 >= 224 && x  <368) && (y + 32 >= 478 && y<493))
		return 0;
	//31-1
	if ((x + 32 >= 287 && x  <306) && (y + 32 >= 478 && y<553))
		return 0;
	//32
	if ((x + 32 >= 162 && x <179) && (y + 32 >= 478 && y<553))
		return 0;
	//33
	if ((x + 32 >= 414 && x  <432) && (y + 32 >= 478 && y<553))
		return 0;
	//34
	if ((x + 32 >= 55 && x  <240) && (y + 32 >= 535 && y<553))
		return 0;
	//35
	if ((x + 32 >= 350 && x  <539) && (y + 32 >= 535 && y<553))
		return 0;




	return 1;


}

bool valid2(float x, float y)
{

	if ((x + 32 >= 55 && x <177) && (y + 32 >= 55 && y<87))
		return 0;
	//24
	if ((x + 32 >= 55 && x <177) && (y + 32 >= 420 && y<433))
		return 0;
	//25
	if ((x + 32 >= 227 && x <373) && (y + 32 >= 420 && y<433))
		return 0;
	//26
	if ((x + 32 >= 422 && x <545) && (y + 32 >= 420 && y<433))
		return 0;


	//2
	if ((x + 32 >= 228 && x <372) && (y + 32 >= 55 && y<87))
		return 0;

	//7
	if ((x + 32 >= 292 && x <308) && (y + 32 >= 92 && y<202))
		return 0;
	//23
	if ((x + 32 >= 292 && x <308) && (y + 32 >= 362 && y<375))
		return 0;
	//28
	if ((x + 32 >= 96 && x <116) && (y + 32 >= 475 && y<491))
		return 0;
	//27
	if ((x + 32 >= 0 && x <49) && (y + 32 >= 475 && y<491))
		return 0;
	//31
	if ((x + 32 >= 485 && x <502) && (y + 32 >= 475 && y<491))
		return 0;
	//32
	if ((x + 32 >= 551 && x <596) && (y + 32 >= 474 && y<492))
		return 0;
	//34

	if ((x + 32 >= 292 && x <308) && (y + 32 >= 476 && y<587))
		return 0;
	//4
	if ((x + 32 >= 55 && x <113) && (y + 32 >= 130 && y<145))
		return 0;
	//3

	if ((x + 32 >= 421 && x <545) && (y + 32 >= 55 && y<87))
		return 0;

	//6
	if ((x + 32 >= 225 && x <243) && (y + 32 >= 132 && y<204))
		return 0;
	//7-2
	if ((x + 32 >= 355 && x <372) && (y + 32 >= 132 && y<204))
		return 0;
	//35
	if ((x + 32 >= 355 && x <372) && (y + 32 >= 476 && y<546))
		return 0;


	//9
	if ((x + 32 >= 485 && x <545) && (y + 32 >= 130 && y<145))
		return 0;
	//5
	if ((x + 32 >= 162 && x <179) && (y + 32 >= 132 && y<375))
		return 0;
	//29
	if ((x + 32 >= 162 && x <179) && (y + 32 >= 420 && y<491))
		return 0;
	//21
	if ((x + 32 >= 162 && x <243) && (y + 32 >= 362 && y<375))
		return 0;

	//12
	if ((x + 32 >= 0 && x <162) && (y + 32 >= 265 && y<299))
		return 0;

	//11
	if ((x + 32 >= 0 && x <113) && (y + 32 >= 188 && y<221))
		return 0;

	//20

	if ((x + 32 >= 0 && x <113) && (y + 32 >= 342 && y<375))
		return 0;

	//8
	if ((x + 32 >= 420 && x <436) && (y + 32 >= 132 && y<375))
		return 0;
	//30
	if ((x + 32 >= 420 && x <436) && (y + 32 >= 420 && y<491))
		return 0;
	//33
	if ((x + 32 >= 225 && x <243) && (y + 32 >= 476 && y<546))
		return 0;
	//36
	if ((x + 32 >= 55 && x <243) && (y + 32 >= 533 && y<547))
		return 0;
	//37
	if ((x + 32 >= 355 && x <545) && (y + 32 >= 533 && y<547))
		return 0;

	//22
	if ((x + 32 >= 355 && x <436) && (y + 32 >= 362 && y<375))
		return 0;
	//10
	if ((x + 32 >= 485 && x <600) && (y + 32 >= 188 && y<221))
		return 0;
	//18
	if ((x + 32 >= 436 && x <600) && (y + 32 >= 265 && y<299))
		return 0;

	//19
	if ((x + 32 >= 485 && x <600) && (y + 32 >= 342 && y<375))
		return 0;
	//17
	if ((x + 32 >= 227 && x <273) && (y + 32 >= 245 && y<255))
		return 0;
	//16
	if ((x + 32 >= 322 && x <373) && (y + 32 >= 246 && y<254))
		return 0;
	//13
	if ((x + 32 >= 222 && x <236) && (y + 32 >= 245 && y<321))
		return 0;
	//15
	if ((x + 32 >= 364 && x <375) && (y + 32 >= 245 && y<321))
		return 0;
	//14
	if ((x + 32 >= 222 && x <375) && (y + 32 >= 310 && y<321))
		return 0;

	//up
	if ((x + 32 >= 12 && x <590) && (y + 32 >= 0 && y<14))
		return 0;
	//down
	if ((x + 32 >= 0 && x <590) && (y + 32 >= 590 && y<600))
		return 0;
	//left
	if ((x + 32 >= 590 && x <600) && (y + 32 >= 10 && y<225))
		return 0;
	//left 2
	if ((x + 32 >= 590 && x <600) && (y + 32 >= 342 && y<600))
		return 0;
	//right
	if ((x + 32 >= 0 && x <10) && (y + 32 >= 12 && y<225))
		return 0;
	//right 2
	if ((x + 32 >= 0 && x <10) && (y + 32 >= 342 && y<600))
		return 0;

	return 1;
}

bool valid3(float x, float y)
{
	if ((x + 32 >= 58 && x <= 118) && (y + 32 >= 48 && y<83))
		return 0;
	//1-2
	if ((x + 32 >= 165 && x <182) && (y + 32 >= 12 && y<83))
		return 0;
	//2
	if ((x + 32 >= 230 && x <379) && (y + 32 >= 48 && y<83))
		return 0;
	//6

	if ((x + 32 >= 294 && x <312) && (y + 32 >= 85 && y<141))
		return 0;
	//2-3
	if ((x + 32 >= 423 && x <441) && (y + 32 >= 12 && y<83))
		return 0;
	//3
	if ((x + 32 >= 486 && x <552) && (y + 32 >= 48 && y<83))
		return 0;

	//10
	if ((x + 32 >= 12 && x <118) && (y + 32 >= 126 && y<163))
		return 0;
	//4
	if ((x + 32 >= 165 && x <182) && (y + 32 >= 126 && y<203))
		return 0;
	//8
	if ((x + 32 >= 423 && x <441) && (y + 32 >= 126 && y<203))
		return 0;
	//9
	if ((x + 32 >= 488 && x <592) && (y + 32 >= 126 && y<163))
		return 0;
	//12
	if ((x + 32 >= 228 && x <377) && (y + 32 >= 185 && y<201))
		return 0;
	//11
	if ((x + 32 >= 55 && x <118) && (y + 32 >= 204 && y<258))
		return 0;
	//13
	if ((x + 32 >= 488 && x <547) && (y + 32 >= 204 && y<258))
		return 0;
	//21
	if ((x + 32 >= 55 && x <118) && (y + 32 >= 300 && y<356))
		return 0;
	//22
	if ((x + 32 >= 488 && x <547) && (y + 32 >= 300 && y<356))
		return 0;

	//26
	if ((x + 32 >= 165 && x <441) && (y + 32 >= 359 && y<379))
		return 0;

	if ((x + 32 >= 423 && x <441) && (y + 32 >= 242 && y<320))
		return 0;
	if ((x + 32 >= 10 && x <120) && (y + 32 >= 396 && y<432))
		return 0;

	if ((x + 32 >= 488 && x <= 594) && (y + 32 >= 396 && y<432))
		return 0;
	if ((x + 32 >= 165 && x <= 182) && (y + 32 >= 242 && y<318))
		return 0;
	if ((x + 32 >= 165 && x <= 182) && (y + 32 >= 359 && y<430))
		return 0;
	if ((x + 32 >= 293 && x <= 316) && (y + 32 >= 359 && y<432))
		return 0;

	if ((x + 32 >= 423 && x <= 441) && (y + 32 >= 359 && y<432))
		return 0;

	if ((x + 32 >= 58 && x <= 118) && (y + 32 >= 476 && y<493))
		return 0;
	if ((x + 32 >= 165 && x <= 247) && (y + 32 >= 476 && y<493))
		return 0;

	if ((x + 32 >= 228 && x <= 247) && (y + 32 >= 414 && y<551))
		return 0;

	if ((x + 32 >= 358 && x <= 377) && (y + 32 >= 414 && y<551))
		return 0;

	if ((x + 32 >= 358 && x <= 441) && (y + 32 >= 476 && y<493))
		return 0;
	if ((x + 32 >= 487 && x <550) && (y + 32 >= 474 && y<493))
		return 0;
	if ((x + 32 >= 293 && x <313) && (y + 32 >= 475 && y<492))
		return 0;

	if ((x + 32 >= 293 && x <313) && (y + 32 >= 532 && y<551))
		return 0;

	if ((x + 32 >= 58 && x <76) && (y + 32 >= 536 && y<551))
		return 0;

	if ((x + 32 >= 529 && x <550) && (y + 32 >= 534 && y<551))
		return 0;
	if ((x + 32 >= 423 && x <485) && (y + 32 >= 534 && y<590))
		return 0;
	if ((x + 32 >= 120 && x <182) && (y + 32 >= 534 && y<590))
		return 0;
	//up
	if ((x + 32 >= 0 && x <600) && (y + 32 >= 0 && y<10))
		return 0;
	//down
	if ((x + 32 >= 0 && x <600) && (y + 32 >= 590 && y<600))
		return 0;
	//left1
	if ((x + 32 >= 0 && x <10) && (y + 32 >= 0 && y<161))
		return 0;
	//left2
	if ((x + 32 >= 0 && x <10) && (y + 32 >= 200 && y<600))
		return 0;
	//right1
	if ((x + 32 >= 590 && x <600) && (y + 32 >= 0 && y<161))
		return 0;
	//right2
	if ((x + 32 >= 590 && x <600) && (y + 32 >= 200 && y<600))
		return 0;

	if ((x + 32 >= 226 && x <377) && (y + 32 >= 308 && y<319))
		return 0;
	if ((x + 32 >= 365 && x <377) && (y + 32 >= 241 && y<319))
		return 0;
	if ((x + 32 >= 226 && x <243) && (y + 32 >= 241 && y<319))
		return 0;
	if ((x + 32 >= 226 && x <283) && (y + 32 >= 240 && y<254))
		return 0;
	if ((x + 32 >= 327 && x <377) && (y + 32 >= 240 && y<254))
		return 0;
	if ((x + 32 >= 223 && x <246) && (y + 32 >= 120 && y<141))
		return 0;
	if ((x + 32 >= 356 && x <377) && (y + 32 >= 120 && y<141))
		return 0;

	return 1;

}

int random_move1(int dirction, float pox, float poy)
{
	if (level == 1)
	{
		if (dirction == 1)
		{
			if (valid1(pox + .17, poy))
			{
				s_ghost1.move(.17, 0);
			}
			else
			{
				return 0;
			}

		}
		else if (dirction == 2)
		{
			if (valid1(pox - .17, poy))
			{
				s_ghost1.move(-.17, 0);
			}
			else
			{
				return 0;
			}

		}
		else if (dirction == 3)
		{
			if (valid1(pox, .17 + poy))
			{
				s_ghost1.move(0, .17);
			}
			else
			{
				return 0;
			}

		}
		else if (dirction == 4)
		{
			if (valid1(pox, poy - .17))
			{
				s_ghost1.move(0, -.17);
			}
			else
			{
				return 0;
			}

		}
	}
	if (level == 2)
	{
		if (dirction == 1)
		{
			if (valid2(pox + .17, poy))
			{
				s_ghost1.move(.17, 0);
			}
			else
			{
				return 0;
			}

		}
		else if (dirction == 2)
		{
			if (valid2(pox - .17, poy))
			{
				s_ghost1.move(-.17, 0);
			}
			else
			{
				return 0;
			}

		}
		else if (dirction == 3)
		{
			if (valid2(pox, .17 + poy))
			{
				s_ghost1.move(0, .17);
			}
			else
			{
				return 0;
			}

		}
		else if (dirction == 4)
		{
			if (valid2(pox, poy - .17))
			{
				s_ghost1.move(0, -.17);
			}
			else
			{
				return 0;
			}

		}
	}
	if (level == 3)
	{
		if (dirction == 1)
		{
			if (valid3(pox + .17, poy))
			{
				s_ghost1.move(.17, 0);
			}
			else
			{
				return 0;
			}

		}
		else if (dirction == 2)
		{
			if (valid3(pox - .17, poy))
			{
				s_ghost1.move(-.17, 0);
			}
			else
			{
				return 0;
			}

		}
		else if (dirction == 3)
		{
			if (valid3(pox, .17 + poy))
			{
				s_ghost1.move(0, .17);
			}
			else
			{
				return 0;
			}

		}
		else if (dirction == 4)
		{
			if (valid3(pox, poy - .17))
			{
				s_ghost1.move(0, -.17);
			}
			else
			{
				return 0;
			}

		}
	}

	return dirction;


}

int random_move2(int dirction, float pox, float poy)
{
	if (level == 1)
	{
		if (dirction == 1)
		{
			if (valid1(pox + .17, poy))
			{
				s_ghost2.move(.17, 0);
			}
			else
			{
				return 0;
			}

		}
		else if (dirction == 2)
		{
			if (valid1(pox - .17, poy))
			{
				s_ghost2.move(-.17, 0);
			}
			else
			{
				return 0;
			}

		}
		else if (dirction == 3)
		{
			if (valid1(pox, .17 + poy))
			{
				s_ghost2.move(0, .17);
			}
			else
			{
				return 0;
			}

		}
		else if (dirction == 4)
		{
			if (valid1(pox, poy - .17))
			{
				s_ghost2.move(0, -.17);
			}
			else
			{
				return 0;
			}

		}
	}
	if (level == 2)
	{
		if (dirction == 1)
		{
			if (valid2(pox + .17, poy))
			{
				s_ghost2.move(.17, 0);
			}
			else
			{
				return 0;
			}

		}
		else if (dirction == 2)
		{
			if (valid2(pox - .17, poy))
			{
				s_ghost2.move(-.17, 0);
			}
			else
			{
				return 0;
			}

		}
		else if (dirction == 3)
		{
			if (valid2(pox, .17 + poy))
			{
				s_ghost2.move(0, .17);
			}
			else
			{
				return 0;
			}

		}
		else if (dirction == 4)
		{
			if (valid2(pox, poy - .17))
			{
				s_ghost2.move(0, -.17);
			}
			else
			{
				return 0;
			}

		}
	}
	if (level == 3)
	{
		if (dirction == 1)
		{
			if (valid3(pox + .17, poy))
			{
				s_ghost2.move(.17, 0);
			}
			else
			{
				return 0;
			}

		}
		else if (dirction == 2)
		{
			if (valid3(pox - .17, poy))
			{
				s_ghost2.move(-.17, 0);
			}
			else
			{
				return 0;
			}

		}
		else if (dirction == 3)
		{
			if (valid3(pox, .17 + poy))
			{
				s_ghost2.move(0, .17);
			}
			else
			{
				return 0;
			}

		}
		else if (dirction == 4)
		{
			if (valid3(pox, poy - .17))
			{
				s_ghost2.move(0, -.17);
			}
			else
			{
				return 0;
			}

		}
	}

	return dirction;



}

int random_move3(int dirction, float pox, float poy)
{
	if (level == 1)
	{
		if (dirction == 1)
		{
			if (valid1(pox + .17, poy))
			{
				s_ghost3.move(.17, 0);
			}
			else
			{
				return 0;
			}

		}
		else if (dirction == 2)
		{
			if (valid1(pox - .17, poy))
			{
				s_ghost3.move(-.17, 0);
			}
			else
			{
				return 0;
			}

		}
		else if (dirction == 3)
		{
			if (valid1(pox, .17 + poy))
			{
				s_ghost3.move(0, .17);
			}
			else
			{
				return 0;
			}

		}
		else if (dirction == 4)
		{
			if (valid1(pox, poy - .17))
			{
				s_ghost3.move(0, -.17);
			}
			else
			{
				return 0;
			}

		}
	}
	if (level == 2)
	{
		if (dirction == 1)
		{
			if (valid2(pox + .17, poy))
			{
				s_ghost3.move(.17, 0);
			}
			else
			{
				return 0;
			}

		}
		else if (dirction == 2)
		{
			if (valid2(pox - .17, poy))
			{
				s_ghost3.move(-.17, 0);
			}
			else
			{
				return 0;
			}

		}
		else if (dirction == 3)
		{
			if (valid2(pox, .17 + poy))
			{
				s_ghost3.move(0, .17);
			}
			else
			{
				return 0;
			}

		}
		else if (dirction == 4)
		{
			if (valid2(pox, poy - .17))
			{
				s_ghost3.move(0, -.17);
			}
			else
			{
				return 0;
			}

		}
	}
	if (level == 3)
	{
		if (dirction == 1)
		{
			if (valid3(pox + .17, poy))
			{
				s_ghost3.move(.17, 0);
			}
			else
			{
				return 0;
			}

		}
		else if (dirction == 2)
		{
			if (valid3(pox - .17, poy))
			{
				s_ghost3.move(-.17, 0);
			}
			else
			{
				return 0;
			}

		}
		else if (dirction == 3)
		{
			if (valid3(pox, .17 + poy))
			{
				s_ghost3.move(0, .17);
			}
			else
			{
				return 0;
			}

		}
		else if (dirction == 4)
		{
			if (valid3(pox, poy - .17))
			{
				s_ghost3.move(0, -.17);
			}
			else
			{
				return 0;
			}

		}
	}

	return dirction;

}

int random_move4(int dirction, float pox, float poy)
{
	if (level == 1)
	{
		if (dirction == 1)
		{
			if (valid1(pox + .17, poy))
			{
				s_ghost4.move(.17, 0);
			}
			else
			{
				return 0;
			}

		}
		else if (dirction == 2)
		{
			if (valid1(pox - .17, poy))
			{
				s_ghost4.move(-.17, 0);
			}
			else
			{
				return 0;
			}

		}
		else if (dirction == 3)
		{
			if (valid1(pox, .17 + poy))
			{
				s_ghost4.move(0, .17);
			}
			else
			{
				return 0;
			}

		}
		else if (dirction == 4)
		{
			if (valid1(pox, poy - .17))
			{
				s_ghost4.move(0, -.17);
			}
			else
			{
				return 0;
			}

		}
	}
	if (level == 2)
	{
		if (dirction == 1)
		{
			if (valid2(pox + .17, poy))
			{
				s_ghost4.move(.17, 0);
			}
			else
			{
				return 0;
			}

		}
		else if (dirction == 2)
		{
			if (valid2(pox - .17, poy))
			{
				s_ghost4.move(-.17, 0);
			}
			else
			{
				return 0;
			}

		}
		else if (dirction == 3)
		{
			if (valid2(pox, .17 + poy))
			{
				s_ghost4.move(0, .17);
			}
			else
			{
				return 0;
			}

		}
		else if (dirction == 4)
		{
			if (valid2(pox, poy - .17))
			{
				s_ghost4.move(0, -.17);
			}
			else
			{
				return 0;
			}

		}
	}
	if (level == 3)
	{
		if (dirction == 1)
		{
			if (valid3(pox + .17, poy))
			{
				s_ghost4.move(.17, 0);
			}
			else
			{
				return 0;
			}

		}
		else if (dirction == 2)
		{
			if (valid3(pox - .17, poy))
			{
				s_ghost4.move(-.17, 0);
			}
			else
			{
				return 0;
			}

		}
		else if (dirction == 3)
		{
			if (valid3(pox, .17 + poy))
			{
				s_ghost4.move(0, .17);
			}
			else
			{
				return 0;
			}

		}
		else if (dirction == 4)
		{
			if (valid3(pox, poy - .17))
			{
				s_ghost4.move(0, -.17);
			}
			else
			{
				return 0;
			}

		}
	}

	return dirction;

}

void moving_pacman(int pos)
{
	float pox = PacMan.getPosition().x;
	float poy = PacMan.getPosition().y;
	if (level == 1)
	{
		if (pos == 1)
		{

			if (valid1(pox + .1, poy)) {
				PacMan.move(.1, 0);
			}
		}
		else if (pos == 2)
		{
			if (valid1(pox, poy + .1)) {
				PacMan.move(0, .1);
			}
		}
		else if (pos == 3)
		{
			if (valid1(pox - .1, poy)) {
				PacMan.move(-.1, 0);
			}
		}
		else if (pos == 4)
		{
			if (valid1(pox, poy - .1)) {
				PacMan.move(0, -.1);
			}
		}

	}
	else if (level == 2)
	{
		if (pos == 1)
		{

			if (valid2(pox + .1, poy)) {
				PacMan.move(.1, 0);
			}
		}
		else if (pos == 2)
		{
			if (valid2(pox, poy + .1)) {
				PacMan.move(0, .1);
			}
		}
		else if (pos == 3)
		{
			if (valid2(pox - .1, poy)) {
				PacMan.move(-.1, 0);
			}
		}
		else if (pos == 4)
		{
			if (valid2(pox, poy - .1)) {
				PacMan.move(0, -.1);
			}
		}
	}
	else if (level == 3)
	{
		if (pos == 1)
		{

			if (valid3(pox + .1, poy)) {
				PacMan.move(.1, 0);
			}
		}
		else if (pos == 2)
		{
			if (valid3(pox, poy + .1)) {
				PacMan.move(0, .1);
			}
		}
		else if (pos == 3)
		{
			if (valid3(pox - .1, poy)) {
				PacMan.move(-.1, 0);
			}
		}
		else if (pos == 4)
		{
			if (valid3(pox, poy - .1)) {
				PacMan.move(0, -.1);
			}
		}
	}

}
///intro
void st(int pos)
{
	if (pos == 5)
	{
		sahm.setPosition(300, 335);
	}
	else if (pos == 6)
	{
		sahm.setPosition(300, 400);
	}
	else if (pos == 7)
	{
		sahm.setPosition(360, 455);
	}

}
/// level 1
void moving_ghost1()
{
	float pox = s_ghost1.getPosition().x;
	float poy = s_ghost1.getPosition().y;
	float pox2 = s_ghost2.getPosition().x;
	float poy2 = s_ghost2.getPosition().y;
	///to eat pacman

	if (abs(PacMan.getPosition().x - pox) <= 20 && abs(PacMan.getPosition().y - poy) <= 20)
		stop = 1;
	if (abs(PacMan.getPosition().x - pox2) <= 20 && abs(PacMan.getPosition().y - poy2) <= 20)
		stop2 = 1;

	///
	///to move automatically
	if (dir_ghost1 == 0)
	{
		dir_ghost1 = rand() % 4 + 1;
	}
	if (dir_ghost2 == 0)
	{
		dir_ghost2 = rand() % 4 + 1;
	}

	dir_ghost1 = random_move1(dir_ghost1, pox, poy);
	dir_ghost2 = random_move2(dir_ghost2, pox2, poy2);

}
/// level 2
void moving_ghost2()
{
	float pox = s_ghost1.getPosition().x;
	float poy = s_ghost1.getPosition().y;
	float pox2 = s_ghost2.getPosition().x;
	float poy2 = s_ghost2.getPosition().y;
	float pox3 = s_ghost3.getPosition().x;
	float poy3 = s_ghost3.getPosition().y;
	///to eat pacman

	if (abs(PacMan.getPosition().x - pox) <= 20 && abs(PacMan.getPosition().y - poy) <= 20)
		stop = 1;
	if (abs(PacMan.getPosition().x - pox2) <= 20 && abs(PacMan.getPosition().y - poy2) <= 20)
		stop2 = 1;
	if (abs(PacMan.getPosition().x - pox3) <= 20 && abs(PacMan.getPosition().y - poy3) <= 20)
		stop3 = 1;


	///
	///to move automatically
	if (dir_ghost1 == 0)
	{
		dir_ghost1 = rand() % 4 + 1;
	}
	if (dir_ghost2 == 0)
	{
		dir_ghost2 = rand() % 4 + 1;
	}
	if (dir_ghost3 == 0)
	{
		dir_ghost3 = rand() % 4 + 1;
	}

	dir_ghost1 = random_move1(dir_ghost1, pox, poy);
	dir_ghost2 = random_move2(dir_ghost2, pox2, poy2);
	dir_ghost3 = random_move3(dir_ghost3, pox3, poy3);

}
/// level 3
void moving_ghost3()
{
	float pox = s_ghost1.getPosition().x;
	float poy = s_ghost1.getPosition().y;
	float pox2 = s_ghost2.getPosition().x;
	float poy2 = s_ghost2.getPosition().y;
	float pox3 = s_ghost3.getPosition().x;
	float poy3 = s_ghost3.getPosition().y;
	float pox4 = s_ghost4.getPosition().x;
	float poy4 = s_ghost4.getPosition().y;
	///to eat pacman

	if (abs(PacMan.getPosition().x - pox) <= 20 && abs(PacMan.getPosition().y - poy) <= 20)
		stop = 1;
	if (abs(PacMan.getPosition().x - pox2) <= 20 && abs(PacMan.getPosition().y - poy2) <= 20)
		stop2 = 1;
	if (abs(PacMan.getPosition().x - pox3) <= 20 && abs(PacMan.getPosition().y - poy3) <= 20)
		stop3 = 1;
	if (abs(PacMan.getPosition().x - pox4) <= 20 && abs(PacMan.getPosition().y - poy4) <= 20)
		stop4 = 1;


	///
	///to move automatically
	if (dir_ghost1 == 0)
	{
		dir_ghost1 = rand() % 4 + 1;
	}
	if (dir_ghost2 == 0)
	{
		dir_ghost2 = rand() % 4 + 1;
	}
	if (dir_ghost3 == 0)
	{
		dir_ghost3 = rand() % 4 + 1;
	}
	if (dir_ghost4 == 0)
	{
		dir_ghost4 = rand() % 4 + 1;
	}

	dir_ghost1 = random_move1(dir_ghost1, pox, poy);
	dir_ghost2 = random_move2(dir_ghost2, pox2, poy2);
	dir_ghost3 = random_move3(dir_ghost3, pox3, poy3);
	dir_ghost4 = random_move4(dir_ghost4, pox4, poy4);

}

void scoor()
{
	int scor = score;
	Player_score.clear();
	while (scor > 0)
	{
		int x = scor % 10;
		Player_score += (char)(x + '0');
		scor /= 10;
	}
	reverse(Player_score.begin(), Player_score.end());

}

void forloop(int start, int one, int two, int three, int four, int plus)
{
	for (int i = start; i<start + plus; i++)
	{
		fruits[i].loadFromFile("ddddd.png");
		sfruits[i].setTexture(fruits[i]);
		sfruits[i].setTextureRect(IntRect(one, two, three, four));
		if (plus<4)
			sfruits[i].setScale(2, 2);
		else
			sfruits[i].setScale(1.6, 1.5);
	}

}

void set_fruits1()
{ ///apples	
	sfruits[0].setPosition(22, 150);
	sfruits[1].setPosition(550, 560);
	sfruits[2].setPosition(315, 420);
	sfruits[3].setPosition(380, 150);
	forloop(0, 2, 35, 15, 16, 4);
	////

	///banana
	sfruits[4].setPosition(20, 55);
	sfruits[5].setPosition(125, 480);
	sfruits[6].setPosition(440, 420);
	sfruits[7].setPosition(380, 210);
	forloop(4, 18, 35, 15, 16, 4);
	////

	///donate
	sfruits[8].setPosition(446, 558);
	sfruits[9].setPosition(340, 20);
	sfruits[10].setPosition(480, 265);
	sfruits[11].setPosition(500, 100);

	forloop(8, 35, 35, 15, 16, 4);
	////

	///burger
	sfruits[12].setPosition(20, 558);
	sfruits[13].setPosition(250, 180);
	sfruits[14].setPosition(185, 350);
	sfruits[15].setPosition(550, 55);
	forloop(12, 53, 35, 15, 16, 4);
	////

	//gift 
	forloop(16, 257, 35, 15, 16, 1);
	sfruits[16].setPosition(250, 55);





}

void set_fruits2()
{
	///red sweets
	sfruits[0].setPosition(22, 150);
	sfruits[1].setPosition(550, 560);
	sfruits[2].setPosition(324, 447);
	sfruits[3].setPosition(380, 150);

	forloop(0, 121, 35, 15, 16, 4);
	////

	///banana
	sfruits[4].setPosition(20, 55);
	sfruits[5].setPosition(125, 480);
	sfruits[6].setPosition(451, 454);
	sfruits[7].setPosition(380, 210);
	forloop(4, 18, 35, 15, 16, 4);
	////

	///donate
	sfruits[8].setPosition(446, 555);
	sfruits[9].setPosition(295, 20);
	sfruits[10].setPosition(19, 393);
	sfruits[11].setPosition(500, 100);

	forloop(8, 35, 35, 15, 16, 4);
	////

	///burger
	sfruits[12].setPosition(250, 555);
	sfruits[13].setPosition(250, 180);
	sfruits[14].setPosition(185, 330);
	sfruits[15].setPosition(550, 55);
	forloop(12, 53, 35, 15, 16, 4);
	////

	//gift 
	forloop(16, 257, 35, 15, 16, 1);
	sfruits[16].setPosition(124, 225);


	//egg
	sfruits[17].setPosition(20, 305);
	sfruits[18].setPosition(124, 20);
	sfruits[19].setPosition(150, 555);
	sfruits[20].setPosition(555, 393);
	forloop(17, 70, 35, 15, 16, 4);
	//coin
	sfruits[21].setPosition(555, 305);
	sfruits[22].setPosition(185, 150);
	sfruits[23].setPosition(490, 20);
	sfruits[24].setPosition(317, 555);
	forloop(21, 87, 35, 15, 16, 4);
	//shoce
	sfruits[25].setPosition(20, 555);
	sfruits[26].setPosition(380, 325);
	sfruits[27].setPosition(150, 95);
	sfruits[28].setPosition(555, 150);
	forloop(25, 103, 35, 15, 16, 4);

}

void set_fruits3()
{
	///red sweets
	sfruits[0].setPosition(23, 170);
	sfruits[1].setPosition(550, 620);
	sfruits[2].setPosition(324, 447);
	sfruits[3].setPosition(380, 150);

	forloop(0, 121, 35, 15, 16, 4);
	////

	///banana
	sfruits[4].setPosition(20, 55);
	sfruits[5].setPosition(125, 480);
	sfruits[6].setPosition(451, 454);
	sfruits[7].setPosition(380, 210);
	forloop(4, 18, 35, 15, 16, 4);
	////

	///donate
	sfruits[8].setPosition(490, 555);
	sfruits[9].setPosition(295, 15);
	sfruits[10].setPosition(14, 445);
	sfruits[11].setPosition(500, 90);

	forloop(8, 35, 35, 15, 16, 4);
	////

	///burger
	sfruits[12].setPosition(295, 555);
	sfruits[13].setPosition(295, 150);
	sfruits[14].setPosition(185, 330);
	sfruits[15].setPosition(560, 55);
	forloop(12, 53, 35, 15, 16, 4);
	////

	//gift 
	forloop(16, 257, 35, 15, 16, 1);
	sfruits[16].setPosition(124, 225);


	//egg
	sfruits[17].setPosition(20, 305);
	sfruits[18].setPosition(124, 20);
	sfruits[19].setPosition(190, 555);
	sfruits[20].setPosition(555, 360);
	forloop(17, 70, 35, 15, 16, 4);
	//coin
	sfruits[21].setPosition(555, 280);
	sfruits[22].setPosition(185, 150);
	sfruits[23].setPosition(490, 20);
	sfruits[24].setPosition(390, 555);
	forloop(21, 87, 35, 15, 16, 4);
	//shoce
	sfruits[25].setPosition(20, 555);
	sfruits[26].setPosition(380, 325);
	sfruits[27].setPosition(150, 95);
	sfruits[28].setPosition(555, 170);
	forloop(25, 103, 35, 15, 16, 4);


}

void delete_fn1()
{
	float tox = PacMan.getPosition().x;
	float toy = PacMan.getPosition().y;
	///apples

	if (tox >= 32 - 23 && tox <= 23 + 16 && toy >= 152 - 32 && toy <= 152 + 16 && !del[0])
		del[0] = 1, score += 10;
	if (tox >= 525 && tox <= 570 && toy >= 530 && toy <= 580 && !del[1])
		del[1] = 1, score += 10;
	if (tox >= 290 && tox <= 335 && toy >= 370 && toy <= 410 && !del[2])
		del[2] = 1, score += 10;
	if (tox >= 350 && tox <= 400 && toy >= 120 && toy <= 180 && !del[3])
		del[3] = 1, score += 10;

	///bananas

	if (tox >= 32 - 23 && tox <= 23 + 16 && toy >= 100 - 45 && toy <= 80 && !del[4])
		del[4] = 1, score += 15;
	if (tox >= 95 && tox <= 145 && toy >= 450 && toy <= 500 && !del[5])
		del[5] = 1, score += 15;
	if (tox >= 410 && tox <= 460 && toy >= 390 && toy <= 440 && !del[6])
		del[6] = 1, score += 15;
	if (tox >= 350 && tox <= 395 && toy >= 180 && toy <= 230 && !del[7])
		del[7] = 1, score += 15;

	///donates

	if (tox >= 415 && tox <= 465 && toy >= 528 && toy <= 578 && !del[8])
		del[8] = 1, score += 20;
	if (tox >= 310 && tox <= 360 && toy >= 10 && toy <= 60 && !del[9])
		del[9] = 1, score += 20;
	if (tox >= 450 && tox <= 500 && toy >= 235 && toy <= 285 && !del[10])
		del[10] = 1, score += 20;
	if (tox >= 470 && tox <= 520 && toy >= 70 && toy <= 120 && !del[11])
		del[11] = 1, score += 20;

	///burger
	if (tox >= 0 && tox <= 40 && toy >= 538 && toy <= 578 && !del[12])
		del[12] = 1, score += 25;
	if (tox >= 220 && tox <= 270 && toy >= 150 && toy <= 200 && !del[13])
		del[13] = 1, score += 25;
	if (tox >= 155 && tox <= 205 && toy >= 330 && toy <= 370 && !del[14])
		del[14] = 1, score += 25;
	if (tox >= 520 && tox <= 570 && toy >= 25 && toy <= 75 && !del[15])
		del[15] = 1, score += 25;
	///gift
	if (tox >= 210 && tox <= 290 && toy >= 28 && toy <= 85 && !del[16])
		del[16] = 1, score += rand() % 100 + 1;


}

void delete_fn2()
{
	float tox = PacMan.getPosition().x;
	float toy = PacMan.getPosition().y;
	//0
	if (tox + 32 >= 23 && tox <= 23 + 16 && toy + 32 >= 152 && toy <= 152 + 16 && !del[0])
		del[0] = 1, score += 10;
	//1
	if (tox + 32 >= 550 && tox <= 550 + 16 && toy + 32 >= 560 && toy <= 560 + 16 && !del[1])
		del[1] = 1, score += 10;
	//2
	if (tox + 32 >= 324 && tox <= 324 + 16 && toy + 32 >= 447 && toy <= 447 + 16 && !del[2])
		del[2] = 1, score += 10;
	//3
	if (tox + 32 >= 380 && tox <= 380 + 16 && toy + 32 >= 150 && toy <= 150 + 16 && !del[3])
		del[3] = 1, score += 10;
	//4
	if (tox + 32 >= 20 && tox <= 20 + 16 && toy + 32 >= 55 && toy <= 55 + 16 && !del[4])
		del[4] = 1, score += 15;
	//5
	if (tox + 32 >= 125 && tox <= 125 + 16 && toy + 32 >= 480 && toy <= 480 + 16 && !del[5])
		del[5] = 1, score += 15;
	//6
	if (tox + 32 >= 451 && tox <= 451 + 16 && toy + 32 >= 454 && toy <= 454 + 16 && !del[6])
		del[6] = 1, score += 15;
	//7
	if (tox + 32 >= 380 && tox <= 380 + 16 && toy + 32 >= 210 && toy <= 210 + 16 && !del[7])
		del[7] = 1, score += 15;
	//8
	if (tox + 32 >= 446 && tox <= 446 + 16 && toy + 32 >= 555 && toy <= 555 + 16 && !del[8])
		del[8] = 1, score += 20;
	//9
	if (tox + 32 >= 295 && tox <= 295 + 16 && toy + 32 >= 20 && toy <= 20 + 16 && !del[9])
		del[9] = 1, score += 20;
	//10	
	if (tox + 32 >= 19 && tox <= 19 + 16 && toy + 32 >= 393 && toy <= 393 + 16 && !del[10])
		del[10] = 1, score += 20;
	//11
	if (tox + 32 >= 500 && tox <= 500 + 16 && toy + 32 >= 100 && toy <= 100 + 16 && !del[11])
		del[11] = 1, score += 20;
	//12
	if (tox + 32 >= 250 && tox <= 250 + 16 && toy + 32 >= 555 && toy <= 555 + 16 && !del[12])
		del[12] = 1, score += 25;
	//13
	if (tox + 32 >= 250 && tox <= 250 + 16 && toy + 32 >= 180 && toy <= 180 + 16 && !del[13])
		del[13] = 1, score += 25;
	//14
	if (tox + 32 >= 185 && tox <= 185 + 16 && toy + 32 >= 330 && toy <= 330 + 16 && !del[14])
		del[14] = 1, score += 25;
	//15
	if (tox + 32 >= 550 && tox <= 550 + 16 && toy + 32 >= 55 && toy <= 55 + 16 && !del[15])
		del[15] = 1, score += 25;
	//16
	if (tox + 32 >= 124 && tox <= 124 + 16 && toy + 32 >= 225 && toy <= 225 + 16 && !del[16])
		del[16] = 1, score += rand() % 100 + 1;
	//17
	if (tox + 32 >= 20 && tox <= 20 + 16 && toy + 32 >= 305 && toy <= 305 + 16 && !del[17])
		del[17] = 1, score += 30;
	//18
	if (tox + 32 >= 124 && tox <= 124 + 16 && toy + 32 >= 20 && toy <= 20 + 16 && !del[18])
		del[18] = 1, score += 30;
	//19
	if (tox + 32 >= 150 && tox <= 150 + 16 && toy + 32 >= 555 && toy <= 555 + 16 && !del[19])
		del[19] = 1, score += 30;
	//20
	if (tox + 32 >= 555 && tox <= 555 + 16 && toy + 32 >= 393 && toy <= 393 + 16 && !del[20])
		del[20] = 1, score += 30;
	//21
	if (tox + 32 >= 555 && tox <= 555 + 16 && toy + 32 >= 305 && toy <= 305 + 16 && !del[21])
		del[21] = 1, score += 35;
	//22
	if (tox + 32 >= 185 && tox <= 185 + 16 && toy + 32 >= 150 && toy <= 150 + 16 && !del[22])
		del[22] = 1, score += 35;
	//23
	if (tox + 32 >= 490 && tox <= 490 + 16 && toy + 32 >= 20 && toy <= 20 + 16 && !del[23])
		del[23] = 1, score += 35;
	//24
	if (tox + 32 >= 317 && tox <= 317 + 16 && toy + 32 >= 555 && toy <= 555 + 16 && !del[24])
		del[24] = 1, score += 35;
	//25
	if (tox + 32 >= 20 && tox <= 20 + 16 && toy + 32 >= 555 && toy <= 555 + 16 && !del[25])
		del[25] = 1, score += 40;
	//26
	if (tox + 32 >= 380 && tox <= 380 + 16 && toy + 32 >= 325 && toy <= 325 + 16 && !del[26])
		del[26] = 1, score += 40;
	//27
	if (tox + 32 >= 150 && tox <= 150 + 16 && toy + 32 >= 95 && toy <= 95 + 16 && !del[27])
		del[27] = 1, score += 40;
	//28
	if (tox + 32 >= 555 && tox <= 555 + 16 && toy + 32 >= 150 && toy <= 150 + 16 && !del[28])
		del[28] = 1, score += 40;

}

void delete_fn3()
{
	float tox = PacMan.getPosition().x;
	float toy = PacMan.getPosition().y;

	//0
	if (tox + 32 >= 23 && tox <= 23 + 16 && toy + 32 >= 170 && toy <= 170 + 16 && !del[0])
		del[0] = 1, score += 10;
	//1
	if (tox + 32 >= 550 && tox <= 550 + 16 && toy + 32 >= 620 && toy <= 620 + 16 && !del[1])
		del[1] = 1, score += 10;
	//2
	if (tox + 32 >= 324 && tox <= 324 + 16 && toy + 32 >= 447 && toy <= 447 + 16 && !del[2])
		del[2] = 1, score += 10;
	//3
	if (tox + 32 >= 380 && tox <= 380 + 16 && toy + 32 >= 150 && toy <= 150 + 16 && !del[3])
		del[3] = 1, score += 10;
	//4
	if (tox + 32 >= 20 && tox <= 20 + 16 && toy + 32 >= 55 && toy <= 55 + 16 && !del[4])
		del[4] = 1, score += 15;
	//5
	if (tox + 32 >= 125 && tox <= 125 + 16 && toy + 32 >= 480 && toy <= 480 + 16 && !del[5])
		del[5] = 1, score += 15;
	//6
	if (tox + 32 >= 451 && tox <= 451 + 16 && toy + 32 >= 454 && toy <= 454 + 16 && !del[6])
		del[6] = 1, score += 15;
	//7
	if (tox + 32 >= 380 && tox <= 380 + 16 && toy + 32 >= 210 && toy <= 210 + 16 && !del[7])
		del[7] = 1, score += 15;
	//8
	if (tox + 32 >= 490 && tox <= 490 + 16 && toy + 32 >= 555 && toy <= 555 + 16 && !del[8])
		del[8] = 1, score += 20;
	//9
	if (tox + 32 >= 295 && tox <= 295 + 16 && toy + 32 >= 15 && toy <= 15 + 16 && !del[9])
		del[9] = 1, score += 20;
	//10	
	if (tox + 32 >= 14 && tox <= 14 + 16 && toy + 32 >= 445 && toy <= 445 + 16 && !del[10])
		del[10] = 1, score += 20;
	//11
	if (tox + 32 >= 500 && tox <= 500 + 16 && toy + 32 >= 90 && toy <= 90 + 16 && !del[11])
		del[11] = 1, score += 20;
	//12
	if (tox + 32 >= 295 && tox <= 295 + 16 && toy + 32 >= 555 && toy <= 555 + 16 && !del[12])
		del[12] = 1, score += 25;
	//13
	if (tox + 32 >= 295 && tox <= 295 + 16 && toy + 32 >= 150 && toy <= 150 + 16 && !del[13])
		del[13] = 1, score += 25;
	//14
	if (tox + 32 >= 185 && tox <= 185 + 16 && toy + 32 >= 330 && toy <= 330 + 16 && !del[14])
		del[14] = 1, score += 25;
	//15
	if (tox + 32 >= 560 && tox <= 560 + 16 && toy + 32 >= 55 && toy <= 55 + 16 && !del[15])
		del[15] = 1, score += 25;
	//16
	if (tox + 32 >= 124 && tox <= 124 + 16 && toy + 32 >= 225 && toy <= 225 + 16 && !del[16])
		del[16] = 1, score += rand() % 100 + 1;

	//17
	if (tox + 32 >= 20 && tox <= 20 + 16 && toy + 32 >= 305 && toy <= 305 + 16 && !del[17])
		del[17] = 1, score += 30;
	//18
	if (tox + 32 >= 124 && tox <= 124 + 16 && toy + 32 >= 20 && toy <= 20 + 16 && !del[18])
		del[18] = 1, score += 30;
	//19
	if (tox + 32 >= 190 && tox <= 190 + 16 && toy + 32 >= 555 && toy <= 555 + 16 && !del[19])
		del[19] = 1, score += 30;
	//20
	if (tox + 32 >= 555 && tox <= 555 + 16 && toy + 32 >= 360 && toy <= 360 + 16 && !del[20])
		del[20] = 1, score += 30;
	//21
	if (tox + 32 >= 555 && tox <= 555 + 16 && toy + 32 >= 280 && toy <= 280 + 16 && !del[21])
		del[21] = 1, score += 35;
	//22
	if (tox + 32 >= 185 && tox <= 185 + 16 && toy + 32 >= 150 && toy <= 150 + 16 && !del[22])
		del[22] = 1, score += 35;
	//23
	if (tox + 32 >= 490 && tox <= 490 + 16 && toy + 32 >= 20 && toy <= 20 + 16 && !del[23])
		del[23] = 1, score += 35;
	//24
	if (tox + 32 >= 390 && tox <= 390 + 16 && toy + 32 >= 555 && toy <= 555 + 16 && !del[24])
		del[24] = 1, score += 35;
	//25
	if (tox + 32 >= 20 && tox <= 20 + 16 && toy + 32 >= 555 && toy <= 555 + 16 && !del[25])
		del[25] = 1, score += 40;
	//26
	if (tox + 32 >= 380 && tox <= 380 + 16 && toy + 32 >= 325 && toy <= 325 + 16 && !del[26])
		del[26] = 1, score += 40;
	//27
	if (tox + 32 >= 150 && tox <= 150 + 16 && toy + 32 >= 95 && toy <= 95 + 16 && !del[27])
		del[27] = 1, score += 40;
	//28
	if (tox + 32 >= 555 && tox <= 555 + 16 && toy + 32 >= 170 && toy <= 170 + 16 && !del[28])
		del[28] = 1, score += 40;
}

int draw_fn1()
{
	float tox = PacMan.getPosition().x;
	float toy = PacMan.getPosition().y;
	window.draw(mylevel_);

	window.draw(text);
	window.draw(text2);

	delete_fn1();
	int num_frutis = 0;

	if (del[0] == 0)
		window.draw(sfruits[0]), num_frutis++;
	if (del[1] == 0)
		window.draw(sfruits[1]), num_frutis++;
	if (del[2] == 0)
		window.draw(sfruits[2]), num_frutis++;
	if (del[3] == 0)
		window.draw(sfruits[3]), num_frutis++;
	if (del[4] == 0)
		window.draw(sfruits[4]), num_frutis++;
	if (del[5] == 0)
		window.draw(sfruits[5]), num_frutis++;
	if (del[6] == 0)
		window.draw(sfruits[6]), num_frutis++;
	if (del[7] == 0)
		window.draw(sfruits[7]), num_frutis++;
	if (del[8] == 0)
		window.draw(sfruits[8]), num_frutis++;
	if (del[9] == 0)
		window.draw(sfruits[9]), num_frutis++;
	if (del[10] == 0)
		window.draw(sfruits[10]), num_frutis++;
	if (del[11] == 0)
		window.draw(sfruits[11]), num_frutis++;
	if (del[12] == 0)
		window.draw(sfruits[12]), num_frutis++;
	if (del[13] == 0)
		window.draw(sfruits[13]), num_frutis++;
	if (del[14] == 0)
		window.draw(sfruits[14]), num_frutis++;
	if (del[15] == 0)
		window.draw(sfruits[15]), num_frutis++;
	if (del[16] == 0)
		window.draw(sfruits[16]), num_frutis++;

	for (int i = 0; i < lifes; i++)
	{
		Life[i].setPosition(630 + i * 35, 550);
		window.draw(Life[i]);
	}


	if (!stop && !stop2) {
		window.draw(PacMan);
	}
	else
	{
		stop = 0;
		stop2 = 0;
		lifes--;
		if (lifes == 0)
			return -5;
		else
		{
			PacMan.setPosition(283, 440);
			go = 0;
		}
	}
	if (num_frutis == 0)
	{
		gold.setPosition(283, 280);
		gold.setTextureRect(IntRect(0, 0, 512, 258));
		gold.setScale(.08, .08);
		if (tox + 32 >= 283 && tox < 324 && toy + 32 >= 280 && toy < 301)
			return -1;
		else
			window.draw(gold);

	}

	window.draw(s_ghost1);
	window.draw(s_ghost2);

	return num_frutis;
}

int draw_fn2()
{
	float tox = PacMan.getPosition().x;
	float toy = PacMan.getPosition().y;
	window.draw(mylevel_);

	window.draw(text);
	window.draw(text2);

	delete_fn2();
	int num_frutis = 0;
	for (int i = 0; i <= 28; i++) {
		if (del[i] == 0) {
			window.draw(sfruits[i]), num_frutis++;

		}
	}
	/*
	if (del[0] == 0)
	window.draw(sfruits[0]), num_frutis++;
	if (del[1] == 0)
	window.draw(sfruits[1]), num_frutis++;
	if (del[2] == 0)
	window.draw(sfruits[2]), num_frutis++;
	if (del[3] == 0)
	window.draw(sfruits[3]), num_frutis++;
	if (del[4] == 0)
	window.draw(sfruits[4]), num_frutis++;
	if (del[5] == 0)
	window.draw(sfruits[5]), num_frutis++;
	if (del[6] == 0)
	window.draw(sfruits[6]), num_frutis++;
	if (del[7] == 0)
	window.draw(sfruits[7]), num_frutis++;
	if (del[8] == 0)
	window.draw(sfruits[8]), num_frutis++;
	if (del[9] == 0)
	window.draw(sfruits[9]), num_frutis++;
	if (del[10] == 0)
	window.draw(sfruits[10]), num_frutis++;
	if (del[11] == 0)
	window.draw(sfruits[11]), num_frutis++;
	if (del[12] == 0)
	window.draw(sfruits[12]), num_frutis++;
	if (del[13] == 0)
	window.draw(sfruits[13]), num_frutis++;
	if (del[14] == 0)
	window.draw(sfruits[14]), num_frutis++;
	if (del[15] == 0)
	window.draw(sfruits[15]), num_frutis++;
	if (del[16] == 0)
	window.draw(sfruits[16]), num_frutis++;
	if (del[17] == 0)
	window.draw(sfruits[17]), num_frutis++;
	if (del[18] == 0)
	window.draw(sfruits[18]), num_frutis++;
	if (del[19] == 0)
	window.draw(sfruits[19]), num_frutis++;
	if (del[20] == 0)
	window.draw(sfruits[20]), num_frutis++;
	if (del[21] == 0)
	window.draw(sfruits[21]), num_frutis++;
	if (del[22] == 0)
	window.draw(sfruits[22]), num_frutis++;
	if (del[23] == 0)
	window.draw(sfruits[23]), num_frutis++;
	if (del[24] == 0)
	window.draw(sfruits[24]), num_frutis++;
	if (del[25] == 0)
	window.draw(sfruits[25]), num_frutis++;
	if (del[26] == 0)
	window.draw(sfruits[26]), num_frutis++;
	if (del[27] == 0)
	window.draw(sfruits[27]), num_frutis++;
	if (del[28] == 0)
	window.draw(sfruits[28]), num_frutis++;*/

	for (int i = 0; i < lifes; i++)
	{
		Life[i].setPosition(630 + i * 35, 550);
		window.draw(Life[i]);
	}


	if (!stop && !stop2 && !stop3) {
		window.draw(PacMan);
	}
	else
	{
		stop = 0;
		stop2 = 0;
		stop3 = 0;
		lifes--;
		if (lifes == 0)
			return -5;
		else
		{
			PacMan.setPosition(283, 440);
			go = 0;
		}
	}
	if (num_frutis == 0)
	{
		gold.setPosition(283, 280);
		gold.setTextureRect(IntRect(0, 0, 512, 258));
		gold.setScale(.08, .08);
		if (tox + 32 >= 283 && tox < 324 && toy + 32 >= 280 && toy < 301)
			return -2;
		else
			window.draw(gold);


	}
	window.draw(s_ghost1);
	window.draw(s_ghost2);
	window.draw(s_ghost3);

	return num_frutis;



}

int draw_fn3()
{
	float tox = PacMan.getPosition().x;
	float toy = PacMan.getPosition().y;
	window.draw(mylevel_);

	window.draw(text);
	window.draw(text2);

	delete_fn3();
	int num_frutis = 0;

	if (del[0] == 0)
		window.draw(sfruits[0]), num_frutis++;
	if (del[1] == 0)
		window.draw(sfruits[1]), num_frutis++;
	if (del[2] == 0)
		window.draw(sfruits[2]), num_frutis++;
	if (del[3] == 0)
		window.draw(sfruits[3]), num_frutis++;
	if (del[4] == 0)
		window.draw(sfruits[4]), num_frutis++;
	if (del[5] == 0)
		window.draw(sfruits[5]), num_frutis++;
	if (del[6] == 0)
		window.draw(sfruits[6]), num_frutis++;
	if (del[7] == 0)
		window.draw(sfruits[7]), num_frutis++;
	if (del[8] == 0)
		window.draw(sfruits[8]), num_frutis++;
	if (del[9] == 0)
		window.draw(sfruits[9]), num_frutis++;
	if (del[10] == 0)
		window.draw(sfruits[10]), num_frutis++;
	if (del[11] == 0)
		window.draw(sfruits[11]), num_frutis++;
	if (del[12] == 0)
		window.draw(sfruits[12]), num_frutis++;
	if (del[13] == 0)
		window.draw(sfruits[13]), num_frutis++;
	if (del[14] == 0)
		window.draw(sfruits[14]), num_frutis++;
	if (del[15] == 0)
		window.draw(sfruits[15]), num_frutis++;
	if (del[16] == 0)
		window.draw(sfruits[16]), num_frutis++;
	if (del[17] == 0)
		window.draw(sfruits[17]), num_frutis++;
	if (del[18] == 0)
		window.draw(sfruits[18]), num_frutis++;
	if (del[19] == 0)
		window.draw(sfruits[19]), num_frutis++;
	if (del[20] == 0)
		window.draw(sfruits[20]), num_frutis++;
	if (del[21] == 0)
		window.draw(sfruits[21]), num_frutis++;
	if (del[22] == 0)
		window.draw(sfruits[22]), num_frutis++;
	if (del[23] == 0)
		window.draw(sfruits[23]), num_frutis++;
	if (del[24] == 0)
		window.draw(sfruits[24]), num_frutis++;
	if (del[25] == 0)
		window.draw(sfruits[25]), num_frutis++;
	if (del[26] == 0)
		window.draw(sfruits[26]), num_frutis++;
	if (del[27] == 0)
		window.draw(sfruits[27]), num_frutis++;
	if (del[28] == 0)
		window.draw(sfruits[28]), num_frutis++;

	for (int i = 0; i < lifes; i++)
	{
		Life[i].setPosition(630 + i * 35, 550);
		window.draw(Life[i]);
	}


	if (!stop && !stop2 && !stop3 && !stop4) {
		window.draw(PacMan);
	}
	else
	{
		stop = 0;
		stop2 = 0;
		stop3 = 0;
		stop4 = 0;
		lifes--;
		if (lifes == 0)
			return -5;
		else
		{
			PacMan.setPosition(283, 440);
			go = 0;
		}
	}
	if (num_frutis == 1)
	{
		gold.setPosition(283, 280);
		gold.setTextureRect(IntRect(0, 0, 512, 258));
		gold.setScale(.08, .08);
		if (tox + 32 >= 283 && tox < 324 && toy + 32 >= 280 && toy < 301)
			return -3;
		else
			window.draw(gold);

	}
	window.draw(s_ghost1);
	window.draw(s_ghost2);
	window.draw(s_ghost3);
	window.draw(s_ghost4);

	//cout<<num_frutis<<endl;
	return num_frutis;


}

void lodefile()
{
	gold_key.loadFromFile("gold.png");
	mylevel.loadFromFile("level 1.png");
	pac.loadFromFile("chompersprites.png");
	selecet.loadFromFile("chompersprites.png");
	start.loadFromFile("interface.png");
	t_ghost1.loadFromFile("chompersprites.png");
	t_ghost2.loadFromFile("chompersprites.png");
	t_ghost3.loadFromFile("chompersprites.png");
	t_ghost4.loadFromFile("chompersprites.png");
	font.loadFromFile("arial.ttf");
	font2.loadFromFile("arial.ttf");
	win.loadFromFile("win-screen.png");
	gameover.loadFromFile("game over.png");
	press.loadFromFile("press space.png");
	life.loadFromFile("4 life.png");

}

void set_sprite()
{
	sahm.setPosition(380, 335);
	Press_space.setTextureRect(IntRect(0, 0, 200, 50));
	Press_space.setScale(.5, .5);
	Press_space.setPosition(460, 560);
	//GameOver.setTextureRect(IntRect(0, 0, 1024, 536));
	GameOver.setScale(.9, .9);
	GameOver.setPosition(0, 0);
	Life[0].setTexture(life);
	Life[1].setTexture(life);
	Life[2].setTexture(life);
	Life[3].setTexture(life);
	Life[0].setTextureRect(IntRect(0, 0, 600, 600));
	Life[0].setScale(.05, .05);
	Life[1].setTextureRect(IntRect(0, 0, 600, 600));
	Life[1].setScale(.05, .05);
	Life[2].setTextureRect(IntRect(0, 0, 600, 600));
	Life[2].setScale(.05, .05);
	Life[3].setTextureRect(IntRect(0, 0, 600, 600));
	Life[3].setScale(.05, .05);
	GameOver.setTextureRect(IntRect(350, 100, 700, 700));

	Win.setTextureRect(IntRect(150, 0, 600, 600));

	Win.setPosition(200, 100);
	text.setFillColor(Color::Blue);
	text.setStyle(Text::Bold);
	text.setPosition(650, 10);
	text2.setFillColor(Color::Red);
	text2.setStyle(Text::Bold);
	text2.setPosition(750, 20);
}

void scoreboard()
{
	///photos
	t_scoreboard.loadFromFile("board.jpg");
	s_scoreboard.setTextureRect(IntRect(10, 0, 440, 600));
	window.draw(s_scoreboard);
	t_scoreboard2.loadFromFile("back.png");
	s_scoreboard2.setTextureRect(IntRect(0, 0, 50, 50));
	s_scoreboard2.setPosition(365, 530);
	window.draw(s_scoreboard2);
	if (Mouse::isButtonPressed(Mouse::Left))
	{
		int x = Mouse::getPosition().x;
		int y = Mouse::getPosition().y;
		if (x >= 552 && x <= 600 && y >= 645 && y <= 692)
			level = 0;
	}
	////////
	////////////
	///score
	Font f3;
	f3.loadFromFile("arial.ttf");
	vector<pair<int, string> >p;
	string str; int scr, siz = 0;

	ifstream project3("projject.txt");
	while (!project3.eof())
	{
		project3 >> str >> scr;
		if (project3.eof())break;
		p.push_back(make_pair(scr, str));
		siz++;
	}
	int a = 0;
	sort(p.rbegin(), p.rend());
	if (siz>10)siz = 10;
	Text text_scr1[11], text_scr2[11];
	for (int i = 0; i<siz; i++)
	{
		text_scr1[i].setString(p[i].second);
		text_scr1[i].setFont(f3);
		text_scr1[i].setCharacterSize(30);
		text_scr1[i].setFillColor(Color::Black);
		text_scr1[i].setPosition(90, 145 + a);
		window.draw(text_scr1[i]);
		///
		string scorewithstring = to_string(p[i].first);
		text_scr2[i].setString(scorewithstring);
		text_scr2[i].setFont(f3);
		text_scr2[i].setCharacterSize(30);
		text_scr2[i].setFillColor(Color::Black);
		text_scr2[i].setPosition(350, 145 + a);
		a += 40;
		window.draw(text_scr2[i]);
	}


}

void swap_level()
{
	intro.setTextureRect(IntRect(0, 0, 1007, 604));
	window.clear();
	if (level == 1) {
		//////////
		if (level && !transformm)
		{
			Texture plsname_t, plsname_t2;
			Sprite plsname_s(plsname_t), plsname_s2(plsname_t2);
			plsname_t.loadFromFile("enter name.jpg");
			plsname_t2.loadFromFile("arroww.png");
			plsname_s.setTextureRect(IntRect(0, 0, 1008, 604));
			plsname_s2.setTextureRect(IntRect(0, 0, 35, 35));
			plsname_s2.setPosition(700, 160);

			window.draw(plsname_s);
			window.draw(plsname_s2);
			Event event2;
			while (window.pollEvent(event2))
			{
				switch (event2.type)
				{
				case Event::Closed:
					window.close();
					break;
				case(Event::TextEntered):
				{
					if (event2.text.unicode >= 32 && event2.text.unicode <= 126)
						sentence += (char)event2.text.unicode;
					else if (event2.text.unicode == 8 && sentence.size() > 0)
						sentence.erase(sentence.size() - 1, 1);
					textname.setString(sentence);
					break;
				}
				}
			}

			textname.setFillColor(Color::Blue);
			textname.setPosition(330, 155);
			window.draw(textname);

			if (Mouse::isButtonPressed(Mouse::Left))
			{
				int x = Mouse::getPosition().x;
				int y = Mouse::getPosition().y;

				if (x >= 888 && x <= 920 && y >= 274 && y <= 308)
					transformm = 1;
			}
		}
		////////////////////////////
		else {
			moving_pacman(go);
			moving_ghost1();

			if (PacMan.getPosition().x >= 590)
				PacMan.setPosition(10, PacMan.getPosition().y);

			else if (PacMan.getPosition().x <= 0)
				PacMan.setPosition(590, PacMan.getPosition().y);

			if (s_ghost1.getPosition().x >= 590)
				s_ghost1.setPosition(10, s_ghost1.getPosition().y);

			else if (s_ghost1.getPosition().x <= 0)
				s_ghost1.setPosition(590, s_ghost1.getPosition().y);

			if (s_ghost2.getPosition().x >= 590)
				s_ghost2.setPosition(10, s_ghost2.getPosition().y);

			else if (s_ghost2.getPosition().x <= 0)
				s_ghost2.setPosition(590, s_ghost2.getPosition().y);


			if (mouse_move == 0)
				source.x++;
			if (source.x >= 12)
				source.x = 10;
			mouse_move++;
			if (mouse_move == 100)
				mouse_move = 0;
			PacMan.setTextureRect(IntRect(source.x * 32, source.y * 32, 32, 32));

			mylevel_.setTextureRect(IntRect(0, 0, 600, 600));
			scoor();
			text.setString(Player_score);
			text2.setString(sentence);
			int win = draw_fn1();
			// if (win >= 0)
			// edite_speed = win * .03;
			if (win == -5)
			{
				level = -5, disapper = 0, win = 0;
			}
			else if (win == -1)
			{
				level = -1, disapper = 0, win = 0;
			}

		}
	}
	else if (level == 2)
	{
		moving_pacman(go);
		moving_ghost2();

		////
		if (PacMan.getPosition().x >= 590)
			PacMan.setPosition(10, PacMan.getPosition().y);

		else if (PacMan.getPosition().x <= 0)
			PacMan.setPosition(590, PacMan.getPosition().y);

		if (s_ghost1.getPosition().x >= 590)
			s_ghost1.setPosition(10, s_ghost1.getPosition().y);

		else if (s_ghost1.getPosition().x <= 0)
			s_ghost1.setPosition(590, s_ghost1.getPosition().y);

		if (s_ghost2.getPosition().x >= 590)
			s_ghost2.setPosition(10, s_ghost2.getPosition().y);

		else if (s_ghost2.getPosition().x <= 0)
			s_ghost2.setPosition(590, s_ghost2.getPosition().y);
		///

		if (s_ghost3.getPosition().x >= 590)
			s_ghost3.setPosition(10, s_ghost3.getPosition().y);

		else if (s_ghost3.getPosition().x <= 0)
			s_ghost3.setPosition(590, s_ghost3.getPosition().y);
		////
		if (mouse_move == 0)
			source.x++;
		if (source.x >= 12)
			source.x = 10;
		mouse_move++;
		if (mouse_move == 100)
			mouse_move = 0;
		PacMan.setTextureRect(IntRect(source.x * 32, source.y * 32, 32, 32));

		mylevel_.setTextureRect(IntRect(0, 0, 600, 600));
		scoor();
		text.setString(Player_score);
		text2.setString(sentence);
		int win = draw_fn2();
		// if (win >= 0)
		// edite_speed = win * .03;
		if (win == -5)
		{
			level = -5, disapper = 0, win = 0;
		}
		else if (win == -2)
		{
			level = -2, disapper = 0, win = 0;
		}
	}
	else if (level == 3)
	{
		moving_pacman(go);
		moving_ghost3();
		///
		if (PacMan.getPosition().x >= 590)
			PacMan.setPosition(10, PacMan.getPosition().y);

		else if (PacMan.getPosition().x <= 0)
			PacMan.setPosition(590, PacMan.getPosition().y);

		if (s_ghost1.getPosition().x >= 590)
			s_ghost1.setPosition(10, s_ghost1.getPosition().y);

		else if (s_ghost1.getPosition().x <= 0)
			s_ghost1.setPosition(590, s_ghost1.getPosition().y);

		if (s_ghost2.getPosition().x >= 590)
			s_ghost2.setPosition(10, s_ghost2.getPosition().y);

		else if (s_ghost2.getPosition().x <= 0)
			s_ghost2.setPosition(590, s_ghost2.getPosition().y);
		///

		if (s_ghost3.getPosition().x >= 590)
			s_ghost3.setPosition(10, s_ghost3.getPosition().y);

		else if (s_ghost3.getPosition().x <= 0)
			s_ghost3.setPosition(590, s_ghost3.getPosition().y);

		if (s_ghost4.getPosition().x >= 590)
			s_ghost4.setPosition(10, s_ghost4.getPosition().y);

		else if (s_ghost4.getPosition().x <= 0)
			s_ghost4.setPosition(590, s_ghost4.getPosition().y);
		///
		if (mouse_move == 0)
			source.x++;
		if (source.x >= 12)
			source.x = 10;
		mouse_move++;
		if (mouse_move == 100)
			mouse_move = 0;
		PacMan.setTextureRect(IntRect(source.x * 32, source.y * 32, 32, 32));

		mylevel_.setTextureRect(IntRect(0, 0, 600, 600));
		scoor();
		text.setString(Player_score);

		text2.setString(sentence);

		int win = draw_fn3();
		// if (win >= 0)
		// edite_speed = win * .03;
		if (win == -5)
		{
			level = -5, disapper = 0, win = 0;
		}
		else if (win == -3)
		{
			level = -3, disapper = 0, win = 0;
		}
	}
	else if (level == 6)
	{
		scoreboard();
	}
	else if (level == 0)
	{
		int	py = sahm.getPosition().y;

		st(go);

		sahm.setTextureRect(IntRect(source.x * 32, source.y * 32, 32, 32));

		window.draw(intro);
		disapper++;
		if (disapper < 200)
			window.draw(Press_space);
		else if (disapper >= 300)
			disapper = 0;

		window.draw(sahm);
	}
	else if (level == -1)
	{
		disapper++;
		window.draw(Win);

		if (disapper == 2000)
		{
			level = 2, go = 0, PacMan.setPosition(283, 440);

			s_ghost1.setPosition(300, 18);
			s_ghost2.setPosition(300, 380);
			s_ghost3.setTextureRect(IntRect(32, 0, 30, 32));
			s_ghost3.setPosition(190, 210);

			dir_ghost1 = 0;
			dir_ghost2 = 0;
			dir_ghost3 = 0;
			dir_ghost4 = 0;

			mylevel.loadFromFile("level 2.png");
			set_fruits2();
			for (int i = 0; i < 30; i++)
			{
				del[i] = 0;
			}
		}

	}
	else if (level == -2)
	{
		disapper++;
		window.draw(Win);

		if (disapper == 2000)
		{
			level = 3, go = 0, PacMan.setPosition(283, 440);
			set_fruits3();
			mylevel.loadFromFile("level 3.png");
			s_ghost1.setPosition(300, 12);
			s_ghost2.setPosition(320, 380);
			s_ghost3.setPosition(190, 210);
			s_ghost4.setTextureRect(IntRect(32, 0, 30, 32));
			s_ghost4.setPosition(190, 210);
			for (int i = 0; i < 30; i++)
			{
				del[i] = 0;
			}
		}

	}
	else if (level == -3)
	{
		disapper++;
		window.draw(Win);

		if (disapper >= 2000)
		{
			level = 0, lifes = 4, go = 5, PacMan.setPosition(283, 440);
			mylevel.loadFromFile("level 1.png");
			for (int i = 0; i < 30; i++)
			{
				del[i] = 0;
			}
		}
		if (lw)
		{
			cout << score << endl;
			vector<pair<int, string> >allscore;
			ifstream project2("projject.txt");

			string find1; int find2;

			while (!project2.eof())
			{
				project2 >> find1 >> find2;
				if (project2.eof())break;
				allscore.push_back(make_pair(find2, find1));
			}
			allscore.push_back(make_pair(lastscore, sentence));
			sort(allscore.rbegin(), allscore.rend());
			if (allscore.size())
			{
				ofstream project("projject.txt");
				for (int i = 0; i<allscore.size(); i++)
					project << allscore[i].second << " " << allscore[i].first << endl;
				project.close();
			}
		}

	}
	else
	{
		disapper++;
		window.draw(GameOver);

		if (disapper == 2000)
		{
			level = 0, lifes = 4, go = 5, PacMan.setPosition(283, 440);
			set_sprite();
			mylevel.loadFromFile("level 1.png");
			for (int i = 0; i < 30; i++)
			{
				del[i] = 0;
			}
			lastscore = score;
			score = 0;
			if (lw)
			{
				cout << score << endl;
				vector<pair<int, string> >allscore;
				ifstream project2("projject.txt");

				string find1; int find2;

				while (!project2.eof())
				{
					project2 >> find1 >> find2;
					if (project2.eof())break;
					allscore.push_back(make_pair(find2, find1));
				}
				allscore.push_back(make_pair(lastscore, sentence));
				sort(allscore.rbegin(), allscore.rend());
				if (allscore.size())
				{
					ofstream project("projject.txt");
					for (int i = 0; i<allscore.size(); i++)
						project << allscore[i].second << " " << allscore[i].first << endl;
					project.close();
				}
			}

		}
	}
	window.display();
}

int press_fn()
{
	if (Keyboard::isKeyPressed(Keyboard::Key::Right))
	{
		go = 1;
		source.y = 0;
	}
	if (Keyboard::isKeyPressed(Keyboard::Key::Down))
	{
		go = 2;
		source.y = 1;
	}
	if (Keyboard::isKeyPressed(Keyboard::Key::Left))
	{
		go = 3;
		source.y = 2;
	}
	if (Keyboard::isKeyPressed(Keyboard::Key::Up))
	{
		go = 4;
		source.y = 3;
	}
	if (!level) {
		if (Keyboard::isKeyPressed(Keyboard::Key::Num1))
		{
			go = 5;
		}
		if (Keyboard::isKeyPressed(Keyboard::Key::Num2))
		{
			go = 6;
		}
		if (Keyboard::isKeyPressed(Keyboard::Key::Num3))
		{
			go = 7;
		}
		if (Keyboard::isKeyPressed(Keyboard::Key::Space))
		{
			if (go == 5)
			{
				level = 1;
				lw = 1;
				set_fruits1();
				lifes = 4;
				s_ghost1.setTextureRect(IntRect(0, 95, 30, 32));
				s_ghost1.setPosition(300, 555);
				s_ghost2.setTextureRect(IntRect(65, 31, 30, 32));
				s_ghost2.setPosition(300, 90);
				PacMan.setPosition(283, 440);

				dir_ghost1 = 0;
				dir_ghost2 = 0;
				dir_ghost3 = 0;
				dir_ghost4 = 0;

			}
			else if (go == 7)
			{
				return 0;
			}
			else if (go == 6)
				level = 6;

			go = 0;
		}
	}
	return 1;
}


int main()
{
	// to stop at New Game
	go = 5;
	lodefile();
	set_sprite();


	while (window.isOpen())
	{

		Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case Event::Closed:
				window.close();
				break;

			}
			int clos = press_fn();
			if (clos == 0)
				return 0;
		}
		swap_level();
	}

	return 0;
}