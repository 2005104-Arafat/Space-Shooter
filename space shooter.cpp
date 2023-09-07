/*



*/
# include "iGraphics.h"
#include <stdlib.h>
#include <string.h>
#include<stdio.h>
void rectanglechange();
void circlechange();
void enemychange1();
void enemychange2();
void enemychange3();
void asteroidchange1();
void asteroidchange2();
void highscore();
void pl_sound();
int  pic_x= 300, pic_y=40;
double rectangle_x=pic_x+46;
double rectangle_y= pic_y+100;
double rectangle_x1, rectangle_y1;
double enemy_x1= 0, enemy_y1= 600;
double circle_x1= enemy_x1+130, circle_y1= enemy_y1;
double enemy_x2=550, enemy_y2=1200;
double circle_x2= enemy_x2+130, circle_y2= enemy_y2;
double enemy_x3= 300, enemy_y3= 1800;
double circle_x3= enemy_x3+130, circle_y3= enemy_y3;
double asteroid_x1= 2400, asteroid_y1=2400;
double asteroid_x2=2400, asteroid_y2=2800;
int dy1, dy2, dy3,dy2_1,dy2_2,dy1_1,dy1_2,dy3_1,dy3_2;
int kill=0;
int damage=0;
int *p1= &dy2;
int *p2= &dy1;
int menu=0;
int t=0;
int f;
char str [50];
char str_score[50];
int score ;
int mode=0;
int high_score;
int show;
int s1;
int s2;
int h1;
int h2;
int e_x1,e_y1;
int e_x2,e_y2;
int e_x3,e_y3;
int a_x1,a_y1;
int a_x2,a_y2;
int sound_name=1;
char point[50];
char str2[15][50]= {"health15.bmp","health14.bmp","health13.bmp","health12.bmp","health11.bmp","health10.bmp",
                    "health9.bmp","health8.bmp","health7.bmp","health6.bmp","health5.bmp","health4.bmp","health3.bmp","health2.bmp","health1.bmp"
                   };
char str3[17][100]= {"explosion1.bmp","explosion2.bmp","explosion4.bmp","explosion6.bmp","explosion9.bmp","explosion11.bmp","explosion14.bmp",
                     "explosion17.bmp","explosion19.bmp","explosion22.bmp","explosion24.bmp","explosion26.bmp","explosion29.bmp","explosion32.bmp",
                     "explosion34.bmp","explosion36.bmp","explosion39.bmp"
                    };
int index_str3=0;
char score_img[10][50]= {"0.bmp","1.bmp","2.bmp","3.bmp","4.bmp","5.bmp","6.bmp","7.bmp","8.bmp","9.bmp"};
char high_img[10][50]= {"0.bmp","1.bmp","2.bmp","3.bmp","4.bmp","5.bmp","6.bmp","7.bmp","8.bmp","9.bmp"};
/*
	function iDraw() is called again and again by the system.
*/
void iDraw()
{
    //place your drawing codes here
    if(menu==0)
    {
        iClear();
        iShowBMP( 0, 0, "space.bmp");
        iShowBMP2(125,400,"logo.bmp",000000);
        iShowBMP(225,320,"bg.bmp");
        iShowBMP(225,100,"exit.bmp");
        iShowBMP(225,210,"high score.bmp");
        iShowBMP(225,155,"credits.bmp");
        iShowBMP(225,265,"INS.bmp");
    }
    if(menu==1)
    {
        iClear();
        //iSetColor(20,200,255);
        iShowBMP(0, 0, "space6.bmp");
        iShowBMP(0,650,"backbutton.bmp");
        iShowBMP2(pic_x, pic_y, "f2.bmp", 16777215 );
        //iShowBMP(enemy_x, enemy_y, "e4.bmp");
        iShowBMP2(enemy_x1, enemy_y1, "e4.bmp", 16777215 );
        iShowBMP2(enemy_x2, enemy_y2, "e5.bmp", 16777215);
        iShowBMP2(enemy_x3, enemy_y3, "e4.bmp", 16777215 );
        iSetColor(255, 0, 0);
        iFilledCircle(circle_x1, circle_y1, 5);
        iFilledCircle(circle_x2, circle_y2, 5);
        iFilledCircle(circle_x3, circle_y3, 5);
        iShowBMP2(rectangle_x, rectangle_y,"bullet.bmp",16777215);
        iShowBMP2(asteroid_x1, asteroid_y1, "asteroid1.bmp", 0xffffff);
        iShowBMP2(asteroid_x2, asteroid_y2, "asteroid1.bmp", 0xffffff);
        itoa(kill,str,10);
        iText(650,650,str, GLUT_BITMAP_TIMES_ROMAN_24);
        iText(550,650,"SCORE :",GLUT_BITMAP_TIMES_ROMAN_24);
        iShowBMP2(20,600,str2[damage],16777215 );

        if(index_str3<17)
        {

            if(mode==1)
                iShowBMP2(e_x1,e_y1,str3[index_str3],16777215 );
            if(mode==2)
                iShowBMP2(e_x2,e_y2,str3[index_str3],16777215 );
            if(mode==3)
                iShowBMP2(e_x3,e_y3,str3[index_str3],16777215 );
            if(mode==4)
                iShowBMP2(a_x1,a_y1,str3[index_str3],16777215 );
            if(mode==5)
                 iShowBMP2(a_x2,a_y2,str3[index_str3],16777215 );

            index_str3++;
            if(index_str3==17)
                mode=0;
        }
    }
    if(menu==2)
    {
        iClear();
        iShowBMP(0,0,"hs menu.bmp");
        iShowBMP(0,650,"backbutton.bmp");
        FILE *fp2;
        fp2=fopen("highcore.txt","r");
        fscanf(fp2,"%d",&show);
        h1=show%10;
        h2=show/10;
        iShowBMP2(200,250, high_img[h2],16777215 );
        iShowBMP2(360,250, high_img[h1],16777215 );
    }
    if(menu==3)
    {
        iClear();
        iShowBMP(0,0,"pause menu.bmp");
        iShowBMP2(250,380,"continuebutton.bmp",000000);
        iShowBMP2(270,180,"quit.bmp",000000);

    }
    if(menu==4)
    {
        iClear();
        iShowBMP(0,0,"game_ovr.bmp");
        iText(300,500,"YOUR SCORE IS ",GLUT_BITMAP_TIMES_ROMAN_24);
        s1=score%10;
        s2=score/10;
        iShowBMP2(200,250, score_img[s2],16777215 );
        iShowBMP2(360,250, score_img[s1],16777215 );
        iShowBMP(0,650,"backbutton.bmp");

    }
    if(menu==5)
    {
        iClear();
        iShowBMP(0,0,"credentials.bmp");
        iShowBMP(0,650,"backbutton.bmp");
    }
    if(menu==6)
    {
        iClear();
        iShowBMP(0,0,"instructions.bmp");
        iShowBMP(0,650,"backbutton.bmp");
    }

}
void rectanglechange()
{
    rectangle_y +=dy1;
    if(rectangle_y>=700)
    {
        rectangle_y = pic_y+100;
        rectangle_x = pic_x+46;
    }
}

void circlechange()
{

    if(kill>=0 && kill<=10)
    {
        circle_y1 -=dy1;
        circle_y2-=dy1;
        circle_y3-=dy1;
    }
    if(kill>=11 && kill<=20)
    {
        circle_y1 -=dy1_1;
        circle_y2-=dy1_1;
        circle_y3-=dy1_1;
    }
    if(kill>=21 )
    {
        circle_y1 -=dy1_2;
        circle_y2-=dy1_2;
        circle_y3-=dy1_2;
    }

    if(circle_y1<-10)
    {
        circle_y1= enemy_y1;
        circle_x1= enemy_x1+48;

    }
    if(circle_y2<-10)
    {
        circle_y2= enemy_y2;
        circle_x2= enemy_x2+48;
    }
    if(circle_y3<-10)
    {
        circle_y3= enemy_y3;
        circle_x3= enemy_x3+48;
    }
    if(menu==1)
    {
        if(circle_x1>pic_x && circle_x1<(pic_x+100) && circle_y1>pic_y  && circle_y1<(pic_y+100))
        {
            circle_y1=enemy_y1;
            circle_x1= enemy_x1+65;
            damage++;
            PlaySound("mixkit-falling-hit-757.wav",NULL,SND_ASYNC | SND_ALIAS_START);
        }
        if(circle_x2>pic_x && circle_x2<(pic_x+100) && circle_y2>pic_y && circle_y2<(pic_y+100))
        {
            circle_y2=enemy_y2;
            circle_x2= enemy_x2+48;
            damage++;
            PlaySound("mixkit-falling-hit-757.wav",NULL,SND_ASYNC | SND_ALIAS_START);
        }
        if(circle_x3>pic_x && circle_x3<(pic_x+100) && circle_y3>pic_y && circle_y3<(pic_y+100))
        {
            circle_y3=enemy_y3;
            circle_x3= enemy_x3+65;
            damage++;
            PlaySound("mixkit-falling-hit-757.wav",NULL,SND_ASYNC | SND_ALIAS_START);
        }

    }
    if(damage>=15)
    {
        score=kill;
        damage=0;
        kill=0;
        menu=4;
        highscore();

        PlaySound("mixkit-game-level-completed-2059.wav",NULL,SND_ASYNC | SND_ALIAS_START);
        //printf("%d",score);
    }
}

void enemychange1()
{
    if(menu==1)
    {
        if(kill>=0 && kill<=10)
        {
            enemy_y1-=dy2;
        }
        if(kill>=11 && kill<=20)
        {
            enemy_y1-=dy2_1;
        }
        if(kill>=21)
        {
            enemy_y1-=dy2_2;
        }
        if(rectangle_y>enemy_y1 && rectangle_y<(enemy_y1+100) && rectangle_x >enemy_x1 && rectangle_x< (enemy_x1+100) )
        {
            e_x1=enemy_x1;
            e_y1=enemy_y1;
            rectangle_y = pic_y+100;
            rectangle_x = pic_x+46;
            enemy_y1=760;
            enemy_x1=rand()%600;
            kill++;
            mode=1;
            index_str3=0;
            PlaySound("mixkit-whip-small-explosion-1519.wav",NULL,SND_ASYNC | SND_ALIAS_START);
        }
        if(enemy_y1<-1000)
        {
            enemy_y1=600;
            enemy_x1=rand()%600;
        }
    }
}
void enemychange2()
{
    if(menu==1)
    {

        if(kill>=0 && kill<=10)
        {
            enemy_y2 -= (dy2+4);
        }
        if(kill>=11 && kill<=20)
        {
            enemy_y2 -= (dy2_1+4);
        }
        if(kill>=21 )
        {
            enemy_y2 -= (dy2_2+4);
        }
        if(rectangle_y>enemy_y2 && rectangle_y<(enemy_y2+100) && rectangle_x>enemy_x2 && rectangle_x< (enemy_x2+100))
        {
            e_x2=enemy_x2;
            e_y2=enemy_y2;
            rectangle_y = pic_y+100;
            rectangle_x = pic_x+46;
            enemy_y2=850;
            enemy_x2=rand()%600;
            kill++;
            mode=2;
            index_str3=0;
            PlaySound("mixkit-whip-small-explosion-1519.wav",NULL,SND_ASYNC | SND_ALIAS_START);
        }

        if(enemy_y2<0)
        {
            enemy_y2=850;
            enemy_x2=rand()%600;
        }
    }
}
void enemychange3()
{
    if(menu==1)
    {
        if(kill>=0 && kill<=10)
        {
            enemy_y3-=(dy2+6);
        }
        if(kill>=11 && kill<=20)
        {
            enemy_y3-=(dy2_1+6);
        }
        if(kill>=21)
        {
            enemy_y3-=(dy2_2+6);
        }
        if(rectangle_y>enemy_y3 && rectangle_y<(enemy_y3+100) && rectangle_x >enemy_x3 && rectangle_x< (enemy_x3+100) )
        {
            e_x3=enemy_x3;
            e_y3=enemy_y3;
            rectangle_y = pic_y+100;
            rectangle_x = pic_x+46;
            enemy_y3=1000;
            enemy_x3=rand()%600;
            kill++;
            mode=3;
            index_str3=0;
            PlaySound("mixkit-whip-small-explosion-1519.wav",NULL,SND_ASYNC | SND_ALIAS_START);
        }
        if(enemy_y3<0 )
        {
            enemy_y3=1000;
            enemy_x3=rand()%600;
        }
    }
}

void asteroidchange1()
{
    if(kill>=0 && kill<=10)
    {
        asteroid_x1-=dy3;
        asteroid_y1-=dy3;
    }
    if(kill>=11 && kill<=20)
    {
        asteroid_x1-=dy3_1;
        asteroid_y1-=dy3_1;
    }
    if(kill>=21 )
    {
        asteroid_x1-=dy3_2;
        asteroid_y1-=dy3_2;
    }

    if(asteroid_x1<-600)
    {
        asteroid_x1=2400;
        asteroid_y1= 2400;
    }
    if(asteroid_x1>pic_x && asteroid_x1<(pic_x+60) && asteroid_y1>pic_y && asteroid_y1<(pic_y+40))
    {
        damage=damage+4;
        a_x1=asteroid_x1;
        a_y1=asteroid_y1;
        asteroid_x1=2400;
        asteroid_y1= 2400;
        mode=4;
        index_str3=0;
        PlaySound("mixkit-whip-small-explosion-1519.wav",NULL,SND_ASYNC | SND_ALIAS_START);
    }
}

void asteroidchange2()
{
    if(kill>=0 && kill<=10)
    {
        asteroid_x2-=dy3;
        asteroid_y2-=dy3;
    }
    if(kill>=11 && kill<=20)
    {
        asteroid_x2-=dy3_1;
        asteroid_y2-=dy3_1;
    }
    if(kill>=21 )
    {
        asteroid_x2-=dy3_2;
        asteroid_y2-=dy3_2;
    }

    if(asteroid_x2<1200)
    {
        asteroid_x2=rand()%600;
        asteroid_y2=rand()%800;
    }
    if(asteroid_x2>pic_x && asteroid_x2<(pic_x+60) && asteroid_y2>pic_y && asteroid_y2<(pic_y+40))
    {
        damage=damage+4;
        a_x2=asteroid_x2;
        a_y2=asteroid_y2;
        asteroid_x2=rand()%500;
        asteroid_y2= rand()%1000;
        mode=5;
        index_str3=0;
        PlaySound("mixkit-whip-small-explosion-1519.wav",NULL,SND_ASYNC | SND_ALIAS_START);
    }
}

void highscore()
{
    FILE *fp;
    fp=fopen("highcore.txt","r");
    fscanf(fp,"%d",&high_score);
    fclose(fp);
    if(score>=high_score)
    {
        high_score=score;
        FILE *fp1;
        fp1=fopen("highcore.txt","w");
        fprintf(fp1,"%d",high_score);
        fclose(fp1);
    }
}


/*function iMouseMove() is called when the user presses and drags the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouseMove(int mx, int my)
{
    //printf("x = %d, y= %d\n",mx,my);
    //place your codes here
}

/*
	function iMouse() is called when the user presses/releases the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouse(int button, int state, int mx, int my)
{
    if(menu==0)
    {
        if(mx<=475 && mx>=225 && my<=370 && my>=320 )
        {
            //place your codes here
            //printf("x = %d, y= %d\n",mx,my);
            menu=1;

        }
        if(mx>=225 && mx<=475 && my<=150 && my>=100)
        {
            exit(0);
        }
        if(mx<=475 && mx>=225  && my<=260 && my>=210 )
        {
            menu=2;
        }
        if(mx<=475 && mx>=225  && my<=205 && my>=155)
        {
            menu=5;
        }
        if(mx<=475 && mx>=225  && my<=315 && my>=265 )
        {
            menu=6;
        }
    }
    if(menu==1)
    {
        if(mx<=50 && mx>=0  && my<=700 && my>=650 )
        {
            menu=3;
        }
    }
    if(menu==2)
    {
        if(mx<=50 && mx>=0  && my<=700 && my>=650 )
        {
            menu=0;
        }
    }
    if(menu==3)
    {
        if(mx<=450 && mx>=250  && my<=520 && my>=380 )
        {
            menu=1;
        }
        if(mx<=430 && mx>=270  && my<=320 && my>=180 )
        {
            menu=0;
            damage=0;
            kill=0;
        }
    }

    if(menu==4)
    {
        if(mx<=50 && mx>=0  && my<=700 && my>=650 )
        {
            menu=0;
        }
    }
    if(menu==5)
    {
        if(mx<=50 && mx>=0  && my<=700 && my>=650 )
        {
            menu=0;
        }
    }
    if(menu==6)
    {
        if(mx<=50 && mx>=0  && my<=700 && my>=650 )
        {
            menu=0;
        }
    }

    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        //place your codes here
        //printf("x = %d, y= %d\n",mx,my);
        //x += 5;
        // y += 5;

    }
    if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
    {
        //place your codes here
        //x -= 5;
        //y -= 5;
    }
}

/*
	function iKeyboard() is called whenever the user hits a key in keyboard.
	key- holds the ASCII value of the key pressed.
*/
void iKeyboard(unsigned char key)
{
    if(key == 'k')
    {
        f= 1;
    }
    if(key =='p')
    {
        iPauseTimer(0);
        rectangle_x=pic_x+46;
        rectangle_y=pic_y+96;
    }
    if(key=='r')
    {
        iResumeTimer(0);
    }
    if(key == 'q')
    {
        //exit(0);
    }
    if(key == 'a')
    {
        if(pic_x>0)
        {
            pic_x = pic_x-10;
            //rectangle_x= rectangle_x-10;
        }
    }
    if(key == 'd')
    {
        if(pic_x<600)
        {
            pic_x =pic_x+10;
            //rectangle_x= rectangle_x+10;
        }
    }
    if(key == 'w')
    {
        if(pic_y<600)
        {
            pic_y= pic_y+10;
            rectangle_y= rectangle_y+ 10;
        }
    }
    if(key == 's')
    {
        if(pic_y>0)
        {
            pic_y = pic_y-10;
            rectangle_y= rectangle_y- 10;
        }
    }
    if(key == ' ')
    {
        if(sound_name==0)
        {
            sound_name=1;
            pl_sound();
        }

        else
        {
            sound_name=0;
            pl_sound();
        }
    }
    //place your codes for other keys here
}

/*
	function iSpecialKeyboard() is called whenver user hits special keys like-
	function keys, home, end, pg up, pg down, arraows etc. you have to use
	appropriate constants to detect them. A list is:
	GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
	GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
	GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
	GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
*/
void iSpecialKeyboard(unsigned char key)
{

    if(key == GLUT_KEY_END)
    {
        exit(0);
    }
    if(key == GLUT_KEY_LEFT)
    {
        if(pic_x>0)
        {
            pic_x = pic_x-10;
            rectangle_x= rectangle_x-10;
        }
    }
    if(key == GLUT_KEY_RIGHT)
    {
        if(pic_x<600)
        {
            pic_x =pic_x+10;
            rectangle_x= rectangle_x+10;
        }
    }
    if(key == GLUT_KEY_UP)
    {
        if(pic_y<600)
        {
            pic_y= pic_y+10;
            //rectangle_y= rectangle_y+ 10;
        }
    }
    if(key == GLUT_KEY_DOWN)
    {
        if(pic_y>0)
        {
            pic_y = pic_y-10;
            //rectangle_y= rectangle_y- 10;
        }
    }
    //place your codes for other keys here
}
void pl_sound()
{
    if(sound_name==1)
    {
        PlaySound("mixkit-game-level-music-689.wav",NULL,SND_ASYNC | SND_LOOP);
    }
    if(sound_name==0)
    {
        PlaySound(0,0,0);
    }
}
int main()
{
    iSetTimer(50, rectanglechange);
    iSetTimer(100, enemychange1);
    iSetTimer(100, enemychange2);
    iSetTimer(100, enemychange3);
    iSetTimer(100, asteroidchange1);
    iSetTimer(100, circlechange);
    dy1=30;
    dy2=8;
    dy3=30;
    dy2_1=18;
    dy2_2=28;
    dy1_1=40;
    dy1_2=50;
    dy3_1=40;
    dy3_2=50;
    if(sound_name==1)
    {
        PlaySound("mixkit-game-level-music-689.wav",NULL,SND_ASYNC | SND_LOOP);
    }
    //place your own initialization codes here
    iInitialize(700, 700, "Space Shooter!");
    return 0;
}
