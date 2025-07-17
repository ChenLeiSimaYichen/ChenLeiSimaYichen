#include <iostream>
#include <cmath>
using namespace std;

// 函数声明
void displayTriangleDefinition();
void displayTriangleProperties();
void displayTriangleClassification();
void displayTriangleAngleSum();
void displayTriangleHeight();
void classifyTriangleBySides(double a, double b, double c);
void classifyTriangleByAngles(double angle1, double angle2, double angle3);
double calculateThirdAngle(double angle1, double angle2);

int main() {
    int choice;
    double side1, side2, side3, angle1, angle2, angle3;
    char continueOption;

    // 显示三角形的定义
    displayTriangleDefinition();

    // 显示三角形的特性
    displayTriangleProperties();

    // 显示三角形的分类
    displayTriangleClassification();

    // 显示三角形的内角和
    displayTriangleAngleSum();

    // 显示三角形的高
    displayTriangleHeight();

    do {
        // 提供交互功能
        cout << "\n请选择要执行的操作：\n";
        cout << "1. 判断三角形的类型（按边分类）\n";
        cout << "2. 判断三角形的类型（按角分类）\n";
        cout << "3. 计算三角形的第三个角的度数\n";
        cout << "4. 退出程序\n";
        cout << "请输入选项（1-4）：";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "\n请输入三角形的三条边长：";
                cin >> side1 >> side2 >> side3;
                classifyTriangleBySides(side1, side2, side3);
                break;
            case 2:
                cout << "\n请输入三角形的三个角度：";
                cin >> angle1 >> angle2 >> angle3;
                classifyTriangleByAngles(angle1, angle2, angle3);
                break;
            case 3:
                cout << "\n请输入三角形的两个已知角度：";
                cin >> angle1 >> angle2;
                cout << "第三个角的度数为：" << calculateThirdAngle(angle1, angle2) << "度\n";
                break;
            case 4:
                cout << "\n程序已退出。\n";
                return 0;
            default:
                cout << "\n无效的选项。\n";
                break;
        }

        // 询问用户是否继续操作
        cout << "\n是否继续操作？(y/n): ";
        cin >> continueOption;
    } while (continueOption == 'y' || continueOption == 'Y');

    cout << "\n程序已退出。\n";
    return 0;
}

// 显示三角形的定义
void displayTriangleDefinition() {
    cout << "\n三角形的定义：\n";
    cout << "由三条线段首尾顺次相接围成的封闭图形叫做三角形。\n";
}

// 显示三角形的特性
void displayTriangleProperties() {
    cout << "\n三角形的特性：\n";
    cout << "- 稳定性：三角形具有稳定性，如自行车的车架、篮球架等都利用了这一特性。\n";
    cout << "- 边的关系：三角形任意两边之和大于第三边，任意两边之差小于第三边。\n";
}

// 显示三角形的分类
void displayTriangleClassification() {
    cout << "\n三角形的分类：\n";
    cout << "- 按角分类：\n";
    cout << "  - 锐角三角形（三个角都是锐角）\n";
    cout << "  - 直角三角形（有一个角是直角）\n";
    cout << "  - 钝角三角形（有一个角是钝角）\n";
    cout << "- 按边分类：\n";
    cout << "  - 不等边三角形（三条边都不相等）\n";
    cout << "  - 等腰三角形（有两条边相等）\n";
    cout << "  - 等边三角形（三条边都相等）。等边三角形是特殊的等腰三角形。\n";
}

// 显示三角形的内角和
void displayTriangleAngleSum() {
    cout << "\n三角形的内角和：\n";
    cout << "- 三角形的内角和是180°。可以通过剪拼、折拼等方法验证。\n";
    cout << "- 已知三角形两个角的度数，可求第三个角的度数，用180°减去已知两角的度数和即可。\n";
}

// 显示三角形的高
void displayTriangleHeight() {
    cout << "\n三角形的高：\n";
    cout << "- 从三角形的一个顶点到它的对边作一条垂线，顶点和垂足之间的线段叫做三角形的高，这条对边叫做三角形的底。\n";
    cout << "- 任意三角形都有三条高。锐角三角形的三条高都在三角形内；直角三角形有两条高是直角边，另一条高在三角形内；钝角三角形有两条高在三角形外，一条高在三角形内。\n";
}

// 判断三角形的类型（按边分类）
void classifyTriangleBySides(double a, double b, double c) {
    if (a + b > c && a + c > b && b + c > a) {
        if (a == b && b == c) {
            cout << "这是一个等边三角形。\n";
        } else if (a == b || a == c || b == c) {
            cout << "这是一个等腰三角形。\n";
        } else {
            cout << "这是一个不等边三角形。\n";
        }
    } else {
        cout << "输入的边长无法构成三角形。\n";
    }
}

// 判断三角形的类型（按角分类）
void classifyTriangleByAngles(double angle1, double angle2, double angle3) {
    if (angle1 + angle2 + angle3 == 180) {
        if (angle1 > 90 || angle2 > 90 || angle3 > 90) {
            cout << "这是一个钝角三角形。\n";
        } else if (angle1 == 90 || angle2 == 90 || angle3 == 90) {
            cout << "这是一个直角三角形。\n";
        } else {
            cout << "这是一个锐角三角形。\n";
        }
    } else {
        cout << "输入的角度无法构成三角形。\n";
    }
}

// 计算三角形的第三个角的度数
double calculateThirdAngle(double angle1, double angle2) {
    return 180 - (angle1 + angle2);
}
