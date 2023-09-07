# include "iGraphics.h"


int x = 0, y = 0;
int menu= 0;
/*
	function iDraw() is called again and again by the system.
*/
void iDraw()
{
    //place your drawing codes here
    if(menu==0)
    {
        iClear();
        iShowBMP( 0, 0, "space6.bmp");
        iShowBMP2(125,400,"logo.bmp",000000);
        iShowBMP2(250,300,"bg.bmp",000000);
        iShowBMP2(270,60,"exit.bmp",000000);
        iShowBMP2(250,170,"high score.bmp",000000);
    }
    if(menu==1)
    {
        iClear();
        iShowBMP(0,0,"space5.bmp");
    }
    if(menu==2)
    {
        iClear();
        iShowBMP(0,0,"space.bmp");
    }



    //iShowBMP2(x,y,"player.bmp",)


}


/*
	function iMouseMove() is called when the user presses and drags the mouse.
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
        if(mx<=450 && mx>=250 && my<=420 && my>=300 )
    {
        //place your codes here
        //printf("x = %d, y= %d\n",mx,my);
        menu=1;

    }
    if(mx>=270 && mx<=430 && my<=167 && my>=60)
    {
        exit(0);
    }
    if(mx<=450 && mx>=250  && my<=310 && my>=170 )
    {
          menu=2;
    }
    }

    if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
    {
        //place your codes here
        x -= 5;
        y -= 5;
    }
}

/*
	function iKeyboard() is called whenever the user hits a key in keyboard.
	key- holds the ASCII value of the key pressed.
*/
void iKeyboard(unsigned char key)
{
    if(key == 'q')
    {
        // exit(0);
    }
    if(key == 'w')
    {
        y+=5;
    }
    if(key == 's')
    {
        y-=5;
    }
    if(key == 'a')
    {
        x-=5;
    }
    if(key == 'd')
    {
        x+=5;
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

    if(key == GLUT_KEY_UP)
    {
        exit(0);
    }
    //place your codes for other keys here
}


int main()
{

    iInitialize(700, 700, "Space Shooter");
    return 0;
}
