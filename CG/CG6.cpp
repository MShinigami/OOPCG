#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <cstdlib>

float sunX = -0.8f;
float sunY = -0.3f;
float sunZ = -1.2f;
float sunColorR = 2.0f;
float sunColorG = 1.5f;
float sunColorB = 1.0f;
float bgColorR = 0.0f;
float bgColorG = 0.0f;
float bgColorB = 0.0f;

class Landscape {
public:
    void drawSun() const {
        glColor3f(sunColorR, sunColorG, sunColorB);
        glTranslatef(sunX, sunY, sunZ);
        glutSolidSphere(0.05, 30, 30);
    }

    void draw() const {
        glBegin(GL_TRIANGLES);
        glColor3f(0.0, 1.5, 0.0);  

        glVertex3f(0.1, -0.5, -1.0);
        glVertex3f(0.5, 0.3, -1.0);
        glVertex3f(0.9, -0.5, -1.0);

        glVertex3f(0.1, -0.5, -1.0);
        glVertex3f(0.5, 0.3, -1.0);
        glVertex3f(0.9, -0.5, -1.0);

        glEnd();
    }
};

Landscape landscape;

static int flag = 1;

void sunrise() {
    sunX += 0.001f;
    sunY += 0.0007f;


    bgColorR += 0.001;
    bgColorG += 0.0005;
    bgColorB += 0.0;

    if (sunX > 0.01) {
        flag = 0;
    }
}

void sunset() {
    sunX += 0.001f;
    sunY -= 0.0007f;

    bgColorR -= 0.001;
    bgColorG -= 0.0005;
    bgColorB -= 0.0;

    if (sunX < -0.3) {
        flag = 1;
    }
}

void updateSun() {
    if (sunX > 0.9f) {
        sunX = -0.8f;
        sunY = -0.3f;
        flag = 1;
        sunColorR = 2.0f;
        sunColorG = 1.5f;
        sunColorB = 1.0f;
        bgColorR = 0.0f;
        bgColorG = 0.0f;
        bgColorB = 0.0f;
    }

    if (flag) {
        sunrise();
    } else {
        sunset();
    }
}

void drawScene() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(bgColorR, bgColorG, bgColorB, 0.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    GLfloat ambientColor[] = {0.2f, 0.2f, 0.2f, 1.0f};
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambientColor);

    GLfloat lightColor0[] = {0.5f, 0.5f, 0.5f, 1.0f};
    GLfloat lightPos0[] = {4.0f, 0.0f, 8.0f, 1.0f};
    glLightfv(GL_LIGHT0, GL_DIFFUSE, lightColor0);
    glLightfv(GL_LIGHT0, GL_POSITION, lightPos0);

    GLfloat lightColor1[] = {0.5f, 0.2f, 0.2f, 1.0f};
    GLfloat lightPos1[] = {-1.0f, 0.5f, 0.5f, 0.0f};
    glLightfv(GL_LIGHT1, GL_DIFFUSE, lightColor1);
    glLightfv(GL_LIGHT1, GL_POSITION, lightPos1);

    glPushMatrix();
    landscape.drawSun();
    glPopMatrix();

    glPushMatrix();
    landscape.draw();
    glPopMatrix();

    glutSwapBuffers();
}

void keyPress(unsigned char key, int x, int y) {
    if (key == 27)
        exit(0);
}

void initRendering() {
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHT1);
    glEnable(GL_NORMALIZE);
}

void handleResize(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (double)w / (double)h, 1.0, 200.0);
}

void update(int value) {
    updateSun();
    glutPostRedisplay();
    glutTimerFunc(25, update, 0);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(400, 400);
    glutCreateWindow("Sun");

    initRendering();

    glutDisplayFunc(drawScene);
    glutFullScreen();
    glutKeyboardFunc(keyPress);
    glutReshapeFunc(handleResize);
    glutTimerFunc(25, update, 0);

    glutMainLoop();

    return 0;
}
