#include<stdlib.h>
#include<GL/glut.h>
#include<stdio.h>
#include<GL/GL.h>
#include<Windows.h>
#include<mmsystem.h>

float speed = 0.04;
float block1x = 50.0, block1y = 0, heli = 0.0, mnk = 1, tree1 = -50.0, speedtree = 0.004, tree2 = 0, tree3 = 70, tree4 = 30;;
int i = 0, ijk = 0, flg = 1, flag = 2;
char str1[20];
char str2[20];
char str3[20];

GLfloat spin = 0.0f;
void renderBitmapString(float x, float y, void *font, const char *string)
{
	const char *c;
	glRasterPos2f(x, y);
	for (c = string; *c != '\0'; c++)
	{
		glutBitmapCharacter(font, *c);
	}
}
void init(void)
{
	//block1y = (rand() % 45) + 10;
	//glClearColor(0.0, 0.0, 0.0, 0.0);
	glShadeModel(GL_SMOOTH);
	glClearColor(0.7, 0.8, 1, 1); //bg
	glLoadIdentity();
	glOrtho(0.0, 100.0, 0.0, 100.0, -1.0, 0.0);

}


void drawcopter()
{

	glPushMatrix();
	glTranslatef(0, -34, 0);

	glColor3f(1.0, 0.5, 1.0);

	glPushMatrix();
	glColor3f(1, 0, 0);
	glBegin(GL_POLYGON); //helicopter body
	glVertex2f(10, 53);
	glVertex2f(20, 53);
	glVertex2f(20, 45);
	glVertex2f(10, 45);
	glEnd();
	glPopMatrix();

	glColor3f(1, 1, 0);
	glBegin(GL_POLYGON); //helicopter tail
	glVertex2f(2, 46);
	glVertex2f(10, 46);
	glVertex2f(10, 48);
	glVertex2f(2, 48);
	glEnd();


	//helicopter mini tail
	glBegin(GL_POLYGON);
	glVertex2f(2, 46);
	glVertex2f(3, 46);
	glVertex2f(3, 51);
	glVertex2f(2, 51);
	glEnd();

	//mini blade
	//
	glPushMatrix();
	spin += 360;
	//glLoadIdentity();
	glRotatef(spin, 0, 1, 0);//spins blade
	glColor3f(0.3, 0.3, 0.3);
	glBegin(GL_POLYGON); //mini fan
	glVertex2f(1, 51);
	glVertex2f(4, 51);
	glVertex2f(4, 52);
	glVertex2f(1, 52);
	glEnd();
	glPopMatrix();





	//glColor3f(1, 0, 0);
	glColor3f(1.0, 0, 0); //helicopter body head
	glBegin(GL_POLYGON);
	glVertex2f(14, 53);
	glVertex2f(15, 53);
	glVertex2f(15, 56);
	glVertex2f(14, 56);
	glEnd();

	glPushMatrix();
	spin += 360;
	//glLoadIdentity();
	glRotatef(spin, 0, 1, 0);
	glColor3f(0.3, 0.3, 0.3); //helicoper body fan
	glBegin(GL_POLYGON);
	glVertex2f(7, 58);
	glVertex2f(23, 58);
	glVertex2f(23, 56);
	glVertex2f(7, 56);
	glEnd();
	glPopMatrix();

	//helicopter left leg
	glColor3f(0, 0, 0);
	glBegin(GL_POLYGON);
	glVertex2f(13, 45);
	glVertex2f(13.7, 45);
	glVertex2f(13.7, 43);
	glVertex2f(13, 43);
	glEnd();

	//helicopter right leg
	glColor3f(0, 0, 0);
	glBegin(GL_POLYGON);
	glVertex2f(17, 45);
	glVertex2f(17.7, 45);
	glVertex2f(17.7, 43);
	glVertex2f(17, 43);
	glEnd();

	//helicopter stand
	glColor3f(0, 0, 0);
	glBegin(GL_POLYGON);
	glVertex2f(10, 43);
	glVertex2f(20, 42);
	glVertex2f(20, 43);
	glVertex2f(10, 42);
	glEnd();

	//(15, 53) (20, 53) (15, 48) (20, 48) helicopter window
	glColor3f(0, 0.5, 1);
	glBegin(GL_POLYGON);
	glVertex2f(15, 53);
	glVertex2f(20, 53);
	glVertex2f(20, 48);
	glVertex2f(15, 48);
	glEnd();

	glPopMatrix();
}

void road()
{
	glColor3f(0.5, 00.5, 0.5);
	glBegin(GL_POLYGON);
	glVertex2f(-100, -100);
	glVertex2f(-100, 10);
	glVertex2f(100, 10);
	glVertex2f(100, -100);
	glEnd();

}


void drawClouds() {
	glColor3f(0.9, 0.9, 0.9);

	glPushMatrix();
	glTranslatef(10, 90, 0);
	glScalef(6, 5, 0);
	glutSolidSphere(1, 10, 10);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(30, 50, 0);
	glScalef(6, 5, 0);
	glutSolidSphere(1, 10, 10);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(50, 78, 0);
	glScalef(6, 5, 0);
	glutSolidSphere(1, 10, 10);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(80, 65, 0);
	glScalef(6, 5, 0);
	glutSolidSphere(1, 10, 10);
	glPopMatrix();

}

void draw_tree()
{

	glPushMatrix();
	//glScalef(1.7, 1.9, 0.0);
	//glTranslatef(-200, -100, 0);

	glBegin(GL_POLYGON);        //bark
	glColor3f(0.6, 0.0, 0.0);
	glVertex2f(55, 10);
	glVertex2f(55, 20);
	glVertex2f(50, 20);
	glVertex2f(50, 10);
	glEnd();



	glBegin(GL_POLYGON);    //tree1-lower1
	glColor3f(0.0, 1.0, 0.0);
	glVertex2f(45, 20);
	glVertex2f(42, 23);
	glVertex2f(45, 25);
	glVertex2f(60, 25);
	glVertex2f(62, 23);
	glVertex2f(60, 20);
	glEnd();


	glBegin(GL_POLYGON);    //tree-lower2
	glColor3f(0.0, 1.0, 0.0);
	glVertex2f(46, 25);
	glVertex2f(43, 26);
	glVertex2f(46, 31);
	glVertex2f(59, 31);
	glVertex2f(61, 26);
	glVertex2f(59, 25);
	glEnd();


	glBegin(GL_POLYGON);    //tree-lower3
	glColor3f(0.0, 1.0, 0.0);
	glVertex2f(47, 31);
	glVertex2f(45, 33);
	glVertex2f(47, 38);
	glVertex2f(57, 38);
	glVertex2f(60, 33);
	glVertex2f(57, 31);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.0, 1.0, 0.0);
	glVertex2f(50, 38);
	glVertex2f(47, 40);
	glVertex2f(50, 42);
	glVertex2f(55, 42);
	glVertex2f(57, 40);
	glVertex2f(55, 38);
	glEnd();

	glPopMatrix();

}

/*void Reshape(int w, int h)
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if (w <= h)
		glOrtho(15.0, 20.0, 10.0*(GLfloat)h / (GLfloat)w, 10.0*(GLfloat)h / (GLfloat)w, 10.0, 20.0);
	else
		glOrtho(20.0*(GLfloat)w / (GLfloat)h, 20.0*(GLfloat)w / (GLfloat)h, 20.0, 20.0, 10.0, 20.0);
	glMatrixMode(GL_MODELVIEW);
	glutPostRedisplay();
}*/

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	/*if ((i == 800 || i == -800) || (((int)block1x == 10 || (int)block1x == 7 || (int)block1x == 4 || (int)block1x == 1) && (int)block1y < 53 + (int)heli && (int)block1y + 35>53 + (int)heli) || (((int)block1x == 9 || (int)block1x == 3 || (int)block1x == 6) && (int)block1y < 45 + (int)heli && (int)block1y + 35>45 + (int)heli) || (((int)block1x == 0) && (int)block1y < 46 + (int)heli && (int)block1y + 35>46 + (int)heli))*/
	if (
		/*(i == 730 || i == -700)*/
		//top and bottom checking 

		//||
		(((int)block1x == 10 || (int)block1x == 7 || (int)block1x == 4 || (int)block1x == 1) && (int)block1y < 53 + (int)heli && (int)block1y + 35>53 + (int)heli)
		// propeller front checking 

		||
		(((int)block1x == 9 || (int)block1x == 3 || (int)block1x == 6) && (int)block1y < 45 + (int)heli && (int)block1y + 35>45 + (int)heli)
		//lower body checking 




		||
		(((int)block1x == 0) && (int)block1y < 46 + (int)heli && (int)block1y + 35>46 + (int)heli))
		// lower tail checking 
	{

		PlaySound(NULL, 0, 0);
		PlaySound("\smash.wav", NULL, SND_ASYNC);
		glColor3f(0.8, 0.4, 0.1); //crashing color

		glRectf(0.0, 0.0, 100.0, 100.0);

		glColor3f(0.0, 0.0, 0.0);

		renderBitmapString(40, 70, GLUT_BITMAP_TIMES_ROMAN_24, "***YOU CRASHED***");
		renderBitmapString(40, 60, GLUT_BITMAP_TIMES_ROMAN_24, "****GAME OVER****");

		//renderBitmapString(70, 58, GLUT_BITMAP_TIMES_ROMAN_24, str1);
		glutSwapBuffers();
		glFlush();
		printf("\n*********GAME OVER***********\n");
		printf("\nStart New Game\n");
		//exit(0);



	}
	else if ((i >= 800 || i <= -360))//crashing ground
	{
		PlaySound(NULL, 0, 0);
		//	PlaySound("\smash.wav", NULL, SND_ASYNC);
		glColor3f(0.3, 0.9, 0.1); //crashing color

		glRectf(0.0, 0.0, 100.0, 100.0);

		glColor3f(0.0, 0.0, 0.0);
		renderBitmapString(40, 70, GLUT_BITMAP_TIMES_ROMAN_24, "***limit exceeded ***");
		glutSwapBuffers();
		glFlush();
	}
	else if (flg == 1)
	{

		flg = 0;
		glColor3f(0.3, 0.9, 1); // 


		//renderBitmapString(10, 70, GLUT_BITMAP_TIMES_ROMAN_24, "***YOU CRASHED***");
		//renderBitmapString(10, 70, GLUT_BITMAP_TIMES_ROMAN_24, "***YOU CRASHED***");

		printf("Steps to run this project\n");
		printf("\n------------------------------------------------------------------\n");
		printf("Step1: Click any mouse key to start\n");
		printf("\nStep2: Click and hold left mouse key to handle the helicopter avoid the blocks\n\n");
		drawcopter();
		renderBitmapString(10, 70, GLUT_BITMAP_TIMES_ROMAN_24, "dont crash");
		glutSwapBuffers();
		glFlush();
	}
	else
	{
		glPushMatrix();
		tree1 = tree1 - speedtree;
		glTranslatef(tree1, 0, 0);
		draw_tree();
		glPopMatrix();

		glPushMatrix();
		tree2 = tree2 - speedtree;
		glTranslatef(tree2, 0, 0);
		draw_tree();
		glPopMatrix();

		glPushMatrix();
		tree3 = tree3 - speedtree;
		glTranslatef(tree3, 0, 0);
		draw_tree();
		glPopMatrix();

		glPushMatrix();
		tree4 = tree4 - speedtree;
		glTranslatef(tree4, 0, 0);
		draw_tree();
		glPopMatrix();
		road();
		drawClouds();
		glPushMatrix();

		glColor3f(0.30, 0.21, 0.78); //sky color
		//glClearColor(0.5, 1.0, 1.0, 1);
		//glRectf(0.0, 100.0, 100.0, 10.0);
		//glRectf(0.0, 50.0, 100.0, 40.0);

		glTranslatef(0.0, heli, 0.0);

		drawcopter();
		if (block1x < -10)
		{
			block1x = 50;
			block1y = (rand() % 25) + 20;
		}
		else block1x -= speed;

		glTranslatef(block1x, -heli, 0.0);


		//drawClouds(); // moving clouds
		glColor3f(0, 0.0, 0.0);
		glRectf(block1x, block1y, block1x + 5, block1y + 35);
		glPopMatrix();

		//glLoadIdentity();

		glFlush();
		glutSwapBuffers();


	}
}

void Heliup()
{
	//PlaySound("\helicopter-fly-over-01.wav", NULL, SND_ASYNC | SND_LOOP);
	heli += 0.1;
	i++;

	glutPostRedisplay();

}
void Helidown()
{

	//PlaySound(TEXT("helicopter - fly - over - 01.wav"), NULL, SND_FILENAME);
	heli -= 0.1;
	i--;

	glutPostRedisplay();
}
void mouse(int btn, int state, int x, int y)
{
	if (btn == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		//PlaySound("\helicopter-fly-over-01.wav", NULL, SND_ASYNC | SND_LOOP);
		glutIdleFunc(Heliup); //animation for helicopter to go up


	}

	if (btn == GLUT_LEFT_BUTTON && state == GLUT_UP)
	{
		PlaySound("\helicopter-fly-over-01.wav", NULL, SND_ASYNC | SND_LOOP);
		glutIdleFunc(Helidown);//animation for helicopter to go down
		//PlaySound("\helicopter-fly-over-01.wav", NULL, SND_ASYNC | SND_LOOP);
	}

	glutPostRedisplay();


}

void keyboard(unsigned char key, int x, int y)
{
	if (key == 'u')
		glutIdleFunc(Heliup);
	if (key == 'd')
		glutIdleFunc(Helidown);
	glutPostRedisplay();
}



int main(int argc, char** argv)
{
	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(600, 600);
	glutInitWindowPosition(200, 300);
	glutCreateWindow(" The Helicopter Game");
	init();
	//glutReshapeFunc(Reshape);
	glutDisplayFunc(display);

	glutMouseFunc(mouse);

	glutKeyboardFunc(keyboard);

	glutMainLoop();

	return(0);

}
