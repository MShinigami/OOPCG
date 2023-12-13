#include <iostream>
#include <graphics.h>
#include <math.h>
using namespace std;

class transform {
public:
    int ma[20][20], c[20][20];
    int i, j, k;

    void object();
    void accept();
};

void transform::object() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    line(300, 0, 300, 600);
    line(0, 300, 600, 300);

    for (i = 0; i < m - 1; i++) {
        line(300 + a[i][0], 300 - a[i][1], 300 + a[i + 1][0], 300 - a[i + 1][1]);
    }

    line(300 + a[0][0], 300 - a[0][1], 300 + a[i][0], 300 - a[i][1]);

    for (i = 0; i < m - 1; i++) {
        line(300 + c[i][0], 300 - c[i][1], 300 + c[i + 1][0], 300 - c[i + 1][1]);
    }

    line(300 + c[0][0], 300 - c[0][1], 300 + c[i][0], 300 - c[i][1]);

    int temp;
    cout << "Press 1 to continue: ";
    cin >> temp;
    closegraph();
}

void transform::accept() {
    cout << "in\n";
    cout << "Enter the Number Of Edges: ";
    cin >> m;
    cout << "Enter The Coordinates: ";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            if (2) {
                // You need to specify the condition here
            } else {
                // You need to specify the condition here
            }
        }
    }
}

int main() {
    int ch, tx, ty, sx, sy;
    float deg, theta, b[20][20];

    transform t;

    t.accept();

    cout << "Enter your choice:\n";
    cout << "1. Translation\n2. Scaling\n3. Rotation\n";
    cin >> ch;

    switch (ch) {
        case 1:
            cout << "TRANSLATION OPERATION\n";
            cout << "Enter value for tx and ty: ";
            cin >> tx >> ty;

            t.object();
            break;

        case 2:
            cout << "SCALING OPERATION\n";
            cout << "Enter value for sx and sy: ";
            cin >> sx >> sy;

            // Scaling logic here

            t.object();
            break;

        case 3:
            cout << "ROTATION OPERATION\n";
            cout << "Enter value for angle: ";
            cin >> deg;

            theta = deg * (3.14 / 180);

            b[0][0] = cos(theta);
            b[0][1] = -sin(theta);
            b[1][0] = sin(theta);
            b[1][1] = cos(theta);
            b[2][2] = 1;

            // Rotation logic here

            t.object();
            break;

        default:
            cout << "Invalid choice\n";
    }

    getch();
    return 0;
}