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
    glColor3f(0.6f, 0.3f, 0.2f);

    // left wall
    glVertex2f(0.1f, 0.38f);
    glVertex2f(0.31f, 0.38f);
    glVertex2f(0.31f, 0.60f);
    glVertex2f(0.1f, 0.60f);

    // left 2nd wall
    glVertex2f(0.15f, 0.32f);
    glVertex2f(0.36f, 0.32f);
    glVertex2f(0.36f, 0.50f);
    glVertex2f(0.15f, 0.50f);

    // right wall
    glVertex2f(0.91f, 0.38f);
    glVertex2f(0.71f, 0.38f);
    glVertex2f(0.71f, 0.60f);
    glVertex2f(0.91f, 0.60f);

    // right 2nd wall
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
        if (flag == true){ glColor3f(1.0, 0.25, 0.0); flag = false; }
        else             { glColor3f(1.0, 0.816, 0.0); flag = true; }
    }
    else { glColor3f(0.3, 1.2, 0.0); }

    float x = rocketX, y = rocketY;
    glBegin(GL_POLYGON);
    glVertex3f(x+0.56, y+.35, 0.0);
    glVertex3f(x+0.54, y+.31, 0.0);
    glVertex3f(x+0.58, y+0.28, 0.0);
    glVertex3f(x+0.61, y+0.31, 0.0);
    glVertex3f(x+0.59, y+0.35, 0.0);

    if (value)
    {
        if (flag2 == true){ glColor3f(1.0, 0.816, 0.0); flag2 = false; }
        else              { glColor3f(1.0, 0.25, 0.0);  flag2 = true; }
    }
    else { glColor3f(0.3, 1.2, 0.0); }

    glVertex3f(x+0.56, y+.35, 0.0);
    glVertex3f(x+0.54, y+.31, 0.0);
    glVertex3f(x+0.58, y+0.28, 0.0);
    glVertex3f(x+0.61, y+0.31, 0.0);
    glVertex3f(x+0.59, y+0.35, 0.0);
    glEnd();
}

void rocket()
{
    float x = rocketX, y = rocketY;
    glBegin(GL_QUADS);

    // body
    glColor3f(0.96f, 0.94f, 0.88f);
    glVertex3f(x+0.55, y+.35,  0.0);
    glVertex3f(x+0.6,  y+.35,  0.0);
    glVertex3f(x+0.6,  y+0.6,  0.0);
    glVertex3f(x+0.55, y+0.6,  0.0);

    // head
    glColor3f(0.95, 0.95, 0.90);
    glVertex3f(x+0.6,   y+0.6,  0.0);
    glVertex3f(x+0.55,  y+0.6,  0.0);
    glVertex3f(x+0.574, y+0.65, 0.0);
    glVertex3f(x+0.6,   y+0.6,  0.0);

    // smoke1
    glColor3f(1.0, 1.0, 0.0);
    glVertex3f(x+0.56, y+0.34, 0.0);
    glVertex3f(x+0.57, y+0.34, 0.0);
    glVertex3f(x+0.57, y+0.35, 0.0);
    glVertex3f(x+0.56, y+0.35, 0.0);

    // smoke2
    glVertex3f(x+0.58, y+0.34, 0.0);
    glVertex3f(x+0.59, y+0.34, 0.0);
    glVertex3f(x+0.59, y+0.35, 0.0);
    glVertex3f(x+0.58, y+0.35, 0.0);

    // left wing
    glColor3f(1.0, 0.0, 0.0);
    glVertex3f(x+0.55, y+0.37,  0.0);
    glVertex3f(x+0.55, y+0.425, 0.0);
    glVertex3f(x+0.51, y+0.365, 0.0);
    glVertex3f(x+0.55, y+0.37,  0.0);

    // right wing
    glVertex3f(x+0.6,  y+0.37,  0.0);
    glVertex3f(x+0.6,  y+0.425, 0.0);
    glVertex3f(x+0.64, y+0.365, 0.0);
    glVertex3f(x+0.6,  y+0.37,  0.0);

    glEnd();
    flame();
}

void sun()
{
    glColor3f(0.90, 0.30, 0.0);
    float x = 0.8f, y = 0.8f, r = 0.07f;
    glBegin(GL_POLYGON);
    for(int i = 0; i < 100; i++)
    {
        float angle = 2.0f * 3.1416f * i / 100;
        glVertex2f(x + cos(angle)*r, y + sin(angle)*r);
    }
    glEnd();

    glColor3f(1.0, 0.60, 0.0);
    glBegin(GL_LINES);
    for(int i = 0; i < 12; i++)
    {
        float angle = 2.0f * 3.1416f * i / 12;
        glVertex2f(x + cos(angle)*0.09f, y + sin(angle)*0.09f);
        glVertex2f(x + cos(angle)*0.14f, y + sin(angle)*0.14f);
    }
    glEnd();
}

// ── NEW: moon drawn at same position as sun ──────────────────────────────────
void moon()
{
    float x = 0.8f, y = 0.8f, r = 0.06f;

    // full circle (pale yellow)
    glColor3f(0.95f, 0.95f, 0.70f);
    glBegin(GL_POLYGON);
    for(int i = 0; i < 100; i++)
    {
        float angle = 2.0f * 3.1416f * i / 100;
        glVertex2f(x + cos(angle)*r, y + sin(angle)*r);
    }
    glEnd();

    // overlay circle (sky color) shifted left to create crescent
    if(isNight)
        glColor3f(0.05f, 0.05f, 0.15f);   // matches night sky
    else
        glColor3f(0.4f, 0.7f, 1.0f);      // matches day sky (unused but safe)

    glBegin(GL_POLYGON);
    for(int i = 0; i < 100; i++)
    {
        float angle = 2.0f * 3.1416f * i / 100;
        glVertex2f((x - 0.025f) + cos(angle)*r,
                    y            + sin(angle)*r);
    }
    glEnd();
}

// ── NEW: stars scattered across the sky ──────────────────────────────────────
void stars()
{
    glColor3f(1.0f, 1.0f, 0.9f);
    glPointSize(2.5f);
    glBegin(GL_POINTS);
    // fixed list of (x, y) pairs — all above y=0.4 (sky area)
    float pts[][2] = {
        {0.05f,0.95f},{0.12f,0.85f},{0.22f,0.92f},{0.35f,0.88f},
        {0.48f,0.96f},{0.55f,0.82f},{0.63f,0.91f},{0.72f,0.78f},
        {0.18f,0.75f},{0.30f,0.70f},{0.42f,0.80f},{0.58f,0.74f},
        {0.68f,0.86f},{0.10f,0.65f},{0.25f,0.60f},{0.38f,0.68f},
        {0.50f,0.63f},{0.20f,0.99f},{0.44f,0.72f},{0.76f,0.93f},
        {0.88f,0.68f},{0.93f,0.85f},{0.08f,0.78f},{0.60f,0.98f}
    };
    for(auto& p : pts)
        glVertex2f(p[0], p[1]);
    glEnd();
}

void rocket_stand()
{
    glBegin(GL_QUADS);
    glColor3f(0.95f, 0.93f, 0.88f);

    // left arm
    glVertex2f(0.40f, 0.60f);
    glVertex2f(0.45f, 0.60f);
    glVertex2f(0.45f, 0.35f);
    glVertex2f(0.40f, 0.35f);

    // right arm
    glVertex2f(0.60f, 0.60f);
    glVertex2f(0.65f, 0.60f);
    glVertex2f(0.65f, 0.35f);
    glVertex2f(0.60f, 0.35f);

    // crossbar
    glVertex2f(0.40f, 0.55f);
    glVertex2f(0.65f, 0.55f);
    glVertex2f(0.65f, 0.60f);
    glVertex2f(0.40f, 0.60f);

    glEnd();

    glColor3f(0.0f, 0.0f, 0.0f);
    glLineWidth(2.0f);

    glBegin(GL_LINE_LOOP);
    glVertex2f(0.40f, 0.60f); glVertex2f(0.45f, 0.60f);
    glVertex2f(0.45f, 0.35f); glVertex2f(0.40f, 0.35f);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glVertex2f(0.60f, 0.60f); glVertex2f(0.65f, 0.60f);
    glVertex2f(0.65f, 0.35f); glVertex2f(0.60f, 0.35f);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glVertex2f(0.40f, 0.55f); glVertex2f(0.65f, 0.55f);
    glVertex2f(0.65f, 0.60f); glVertex2f(0.40f, 0.60f);
    glEnd();
}

// ── NEW: road along the very bottom ──────────────────────────────────────────
void road()
{
    // asphalt base
    glBegin(GL_QUADS);
    glColor3f(0.25f, 0.25f, 0.25f);
    glVertex2f(0.0f, 0.0f);
    glVertex2f(1.0f, 0.0f);
    glVertex2f(1.0f, 0.08f);
    glVertex2f(0.0f, 0.08f);
    glEnd();

    // white dashed center line
    glColor3f(1.0f, 1.0f, 1.0f);
    glLineWidth(2.0f);
    glBegin(GL_LINES);
    float dashX = 0.02f;
    while(dashX < 1.0f)
    {
        glVertex2f(dashX,        0.04f);
        glVertex2f(dashX + 0.06f, 0.04f);
        dashX += 0.12f;
    }
    glEnd();

    // yellow edge lines
    glColor3f(1.0f, 0.85f, 0.0f);
    glLineWidth(2.0f);
    glBegin(GL_LINES);
    glVertex2f(0.0f, 0.075f); glVertex2f(1.0f, 0.075f);  // top edge
    glVertex2f(0.0f, 0.005f); glVertex2f(1.0f, 0.005f);  // bottom edge
    glEnd();
}

void keyboard(unsigned char key, int x, int y)
{
    if(key == 'n' || key == 'N')
    {
        isNight = !isNight;
        // update sky color
        if(isNight)
            glClearColor(0.05f, 0.05f, 0.15f, 1.0f);   // dark blue
        else
            glClearColor(0.4f,  0.7f,  1.0f,  1.0f);   // day blue

        glutPostRedisplay();
    }
}

void specialKey(int key, int x, int y)
{
    switch(key)
    {
    case GLUT_KEY_UP:
        value = true;
        rocketY += 0.05f;
        break;
    case GLUT_KEY_DOWN:
        rocketY -= 0.05f;
        break;
    }

    if(rocketY < 0.0f)  rocketY = 0.0f;
    if(rocketY > 0.35f) rocketY = 0.35f;

    glutPostRedisplay();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    // ground — dimmer at night
    glBegin(GL_QUADS);
    if(isNight) glColor3f(0.05f, 0.25f, 0.02f);
    else        glColor3f(0.3f,  1.0f,  0.0f);
    glVertex3f(0.0, 0.08, 0.0);   // sits above the road
    glVertex3f(1.0, 0.08, 0.0);
    glVertex3f(1.0, 0.40, 0.0);
    glVertex3f(0.0, 0.40, 0.0);
    glEnd();

    road();                        // road at the very bottom

    if(isNight) { stars(); moon(); }
    else        { sun(); }

    wall();
    rocket_stand();
    rocket();

    glFlush();
}

void init()
{
    glClearColor(0.4f, 0.7f, 1.0f, 1.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Assignment Graphics");
    glutDisplayFunc(display);
    glutSpecialFunc(specialKey);
    glutKeyboardFunc(keyboard);    // ← register normal key handler
    init();
    glutMainLoop();
}
