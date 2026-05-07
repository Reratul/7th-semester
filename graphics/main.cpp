#include <GL/glut.h>
#include <cmath>
float rocketX = -0.05f;
float rocketY = 0.05f;
bool isNight = false;
bool flag = true, flag2 = true;
bool value = false;


void wall()
{
    glBegin(GL_QUADS);

    // wall color
    glColor3f(0.6f, 0.3f, 0.2f);

    // left wall
    glVertex2f(0.1f, 0.38f);
    glVertex2f(0.31f, 0.38f);
    glVertex2f(0.31f, 0.60f);
    glVertex2f(0.1f, 0.60f);

    //left 2nd wall


    glVertex2f(0.15f, 0.32f);
    glVertex2f(0.36f, 0.32f);
    glVertex2f(0.36f, 0.50f);
    glVertex2f(0.15f, 0.50f);

    //right wall

    glVertex2f(0.91f, 0.38f);
    glVertex2f(0.71f, 0.38f);
    glVertex2f(0.71f, 0.60f);
    glVertex2f(0.91f, 0.60f);

    //right 2nd wall

     glVertex2f(0.86f, 0.32f);
    glVertex2f(0.66f, 0.32f);
    glVertex2f(0.66f, 0.50f);
    glVertex2f(0.86f, 0.50f);

    glEnd();
}




void flame()
{
	if (value)
	{
		if (flag == true){
			glColor3f(1.0, 0.25, 0.0);
			flag = false;
		}
		else{
			glColor3f(1.0, 0.816, 0.0);
			flag = true;
		}
	}
	else
	{
		glColor3f(0.3, 1.2, 0.0);
	}

	float x = rocketX, y = rocketY;
	glBegin(GL_POLYGON);
	glVertex3f(x + 0.56, y + .35, 0.0);
	glVertex3f(x + 0.54, y + .31, 0.0);
	glVertex3f(x + 0.58, y + 0.28, 0.0);
	glVertex3f(x + 0.61, y + 0.31, 0.0);
	glVertex3f(x + 0.59, y + 0.35, 0.0);

	if (value)
	{
		if (flag2 == true){
			glColor3f(1.0, 0.816, 0.0);
			flag2 = false;
		}
		else{
			glColor3f(1.0, 0.25, 0.0);
			flag2 = true;
		}
	}
	else
	{
		glColor3f(0.3, 1.2, 0.0);
	}

	glVertex3f(x + 0.56, y + .35, 0.0);
	glVertex3f(x + 0.54, y + .31, 0.0);
	glVertex3f(x + 0.58, y + 0.28, 0.0);
	glVertex3f(x + 0.61, y + 0.31, 0.0);
	glVertex3f(x + 0.59, y + 0.35, 0.0);
	glEnd();
}


void rocket(){
	float x = rocketX;
	float y = rocketY;

	glBegin(GL_QUADS);
	glColor3f(0.95, 0.95, 0.90);
	glPointSize(100.0);
	glColor3f(0.95, 0.95, 0.90);
	glPointSize(100.0);
	//body
	glColor3f(0.96f, 0.94f, 0.88f);
	glVertex3f(x + 0.55, y + .35, 0.0);
	glVertex3f(x + 0.6, y + .35, 0.0);
	glVertex3f(x + 0.6, y + 0.6, 0.0);
	glVertex3f(x + 0.55, y + 0.6, 0.0);
	glFlush();
	//head
	glColor3f(0.95, 0.95, 0.90);
	glVertex3f(x + 0.6, y + 0.6, 0.0);
	glVertex3f(x + 0.55, y + 0.6, 0.0);
	glVertex3f(x + 0.574, y + 0.65, 0.0);
	glVertex3f(x + 0.6, y + 0.6, 0.0);
	glFlush();
	//smoke1
	glColor3f(1.0, 1.0, 0.0);
	glVertex3f(x + 0.56, y + 0.34, 0.0);
	glVertex3f(x + 0.57, y + 0.34, 0.0);
	glVertex3f(x + 0.57, y + 0.35, 0.0);
	glVertex3f(x + 0.56, y + 0.35, 0.0);
	glFlush();
	//smoke2
	glVertex3f(x + 0.58, y + 0.34, 0.0);
	glVertex3f(x + 0.59, y + 0.34, 0.0);
	glVertex3f(x + 0.59, y + 0.35, 0.0);
	glVertex3f(x + 0.58, y + 0.35, 0.0);
	glFlush();
	//left wing
	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(x + 0.55, y + 0.37, 0.0);
	glVertex3f(x + 0.55, y + 0.425, 0.0);
	glVertex3f(x + 0.51, y + 0.365, 0.0);
	glVertex3f(x + 0.55, y + 0.37, 0.0);
	glFlush();
	//right wing
	glVertex3f(x + 0.6, y + 0.37, 0.0);
	glVertex3f(x + 0.6, y + 0.425, 0.0);
	glVertex3f(x + 0.64, y + 0.365, 0.0);
	glVertex3f(x + 0.6, y + 0.37, 0.0);

	glEnd();

	//flame in rocket
	flame();


}

void sun()
{
    glColor3f(0.90, 0.30, 0.0);

    float x = 0.8f;
    float y = 0.8f;
    float r = 0.07f;

    glBegin(GL_POLYGON);

    for(int i=0; i<100; i++)
    {
        float angle = 2.0f * 3.1416f * i / 100;

        glVertex2f(
            x + cos(angle)*r,
            y + sin(angle)*r
        );
    }

    glEnd();
    // sun rays
    glColor3f(1.0, 0.60, 0.0);
    glBegin(GL_LINES);
    for(int i = 0; i < 12; i++)
    {
        float angle = 2.0f * 3.1416f * i / 12;
        glVertex2f(x + cos(angle) * 0.09f, y + sin(angle) * 0.09f);
        glVertex2f(x + cos(angle) * 0.14f, y + sin(angle) * 0.14f);
    }


    glEnd();
}







void specialKey(int key, int x, int y){


    switch(key){

    case GLUT_KEY_UP:
        value = true;
        rocketY += 0.05f;
        break;
    case GLUT_KEY_DOWN:
        rocketY -= 0.05f;
        break;


    }
     // Restriction area


    if(rocketY < 0.0f)
        rocketY = 0.0f;

    if(rocketY > 0.35f)
        rocketY = 0.35f;



    //night
     if(key == 'n')
    {
        isNight = !isNight;
    }




    glutPostRedisplay();
    // tell program to redraw the position



}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // ground
    glBegin(GL_QUADS);

    glColor3f(0.3f, 1.0f, 0.0f);

    glVertex3f(0.0, 0.0, 0.0);
    glVertex3f(1.0, 0.0, 0.0);
    glVertex3f(1.0, 0.4, 0.0);
    glVertex3f(0.0, 0.4, 0.0);
    //night



glClear(GL_COLOR_BUFFER_BIT);

    glEnd();

    rocket();
    sun();
    wall();

    glFlush();
}

void init() {
    glClearColor(0.4f, 0.7f, 1.0f, 1.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0); // coordinate system: 0..1 in X and Y
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Assignment Graphics");
    glutDisplayFunc(display);
    glutSpecialFunc(specialKey);
    init();
    glutMainLoop();
}
