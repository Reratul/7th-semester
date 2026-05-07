#include <GL/glut.h>

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    // draw your scene here
    glFlush();
}

void init() {
    glClearColor(0.2f, 0.6f, 1.0f, 1.0f); // background color (R,G,B,A)
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0); // coordinate system: 0..1 in X and Y
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("My Scene");
    glutDisplayFunc(display);
    init();
    glutMainLoop();
}