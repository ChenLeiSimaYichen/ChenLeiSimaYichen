#include <iostream>
#include <cmath>
using namespace std;

// ��������
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

    // ��ʾ�����εĶ���
    displayTriangleDefinition();

    // ��ʾ�����ε�����
    displayTriangleProperties();

    // ��ʾ�����εķ���
    displayTriangleClassification();

    // ��ʾ�����ε��ڽǺ�
    displayTriangleAngleSum();

    // ��ʾ�����εĸ�
    displayTriangleHeight();

    do {
        // �ṩ��������
        cout << "\n��ѡ��Ҫִ�еĲ�����\n";
        cout << "1. �ж������ε����ͣ����߷��ࣩ\n";
        cout << "2. �ж������ε����ͣ����Ƿ��ࣩ\n";
        cout << "3. ���������εĵ������ǵĶ���\n";
        cout << "4. �˳�����\n";
        cout << "������ѡ�1-4����";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "\n�����������ε������߳���";
                cin >> side1 >> side2 >> side3;
                classifyTriangleBySides(side1, side2, side3);
                break;
            case 2:
                cout << "\n�����������ε������Ƕȣ�";
                cin >> angle1 >> angle2 >> angle3;
                classifyTriangleByAngles(angle1, angle2, angle3);
                break;
            case 3:
                cout << "\n�����������ε�������֪�Ƕȣ�";
                cin >> angle1 >> angle2;
                cout << "�������ǵĶ���Ϊ��" << calculateThirdAngle(angle1, angle2) << "��\n";
                break;
            case 4:
                cout << "\n�������˳���\n";
                return 0;
            default:
                cout << "\n��Ч��ѡ�\n";
                break;
        }

        // ѯ���û��Ƿ��������
        cout << "\n�Ƿ����������(y/n): ";
        cin >> continueOption;
    } while (continueOption == 'y' || continueOption == 'Y');

    cout << "\n�������˳���\n";
    return 0;
}

// ��ʾ�����εĶ���
void displayTriangleDefinition() {
    cout << "\n�����εĶ��壺\n";
    cout << "�������߶���β˳�����Χ�ɵķ��ͼ�ν��������Ρ�\n";
}

// ��ʾ�����ε�����
void displayTriangleProperties() {
    cout << "\n�����ε����ԣ�\n";
    cout << "- �ȶ��ԣ������ξ����ȶ��ԣ������г��ĳ��ܡ�����ܵȶ���������һ���ԡ�\n";
    cout << "- �ߵĹ�ϵ����������������֮�ʹ��ڵ����ߣ���������֮��С�ڵ����ߡ�\n";
}

// ��ʾ�����εķ���
void displayTriangleClassification() {
    cout << "\n�����εķ��ࣺ\n";
    cout << "- ���Ƿ��ࣺ\n";
    cout << "  - ��������Σ������Ƕ�����ǣ�\n";
    cout << "  - ֱ�������Σ���һ������ֱ�ǣ�\n";
    cout << "  - �۽������Σ���һ�����Ƕ۽ǣ�\n";
    cout << "- ���߷��ࣺ\n";
    cout << "  - ���ȱ������Σ������߶�����ȣ�\n";
    cout << "  - ���������Σ�����������ȣ�\n";
    cout << "  - �ȱ������Σ������߶���ȣ����ȱ�������������ĵ��������Ρ�\n";
}

// ��ʾ�����ε��ڽǺ�
void displayTriangleAngleSum() {
    cout << "\n�����ε��ڽǺͣ�\n";
    cout << "- �����ε��ڽǺ���180�㡣����ͨ����ƴ����ƴ�ȷ�����֤��\n";
    cout << "- ��֪�����������ǵĶ���������������ǵĶ�������180���ȥ��֪���ǵĶ����ͼ��ɡ�\n";
}

// ��ʾ�����εĸ�
void displayTriangleHeight() {
    cout << "\n�����εĸߣ�\n";
    cout << "- �������ε�һ�����㵽���ĶԱ���һ�����ߣ�����ʹ���֮����߶ν��������εĸߣ������Ա߽��������εĵס�\n";
    cout << "- ���������ζ��������ߡ���������ε������߶����������ڣ�ֱ������������������ֱ�Ǳߣ���һ�������������ڣ��۽������������������������⣬һ�������������ڡ�\n";
}

// �ж������ε����ͣ����߷��ࣩ
void classifyTriangleBySides(double a, double b, double c) {
    if (a + b > c && a + c > b && b + c > a) {
        if (a == b && b == c) {
            cout << "����һ���ȱ������Ρ�\n";
        } else if (a == b || a == c || b == c) {
            cout << "����һ�����������Ρ�\n";
        } else {
            cout << "����һ�����ȱ������Ρ�\n";
        }
    } else {
        cout << "����ı߳��޷����������Ρ�\n";
    }
}

// �ж������ε����ͣ����Ƿ��ࣩ
void classifyTriangleByAngles(double angle1, double angle2, double angle3) {
    if (angle1 + angle2 + angle3 == 180) {
        if (angle1 > 90 || angle2 > 90 || angle3 > 90) {
            cout << "����һ���۽������Ρ�\n";
        } else if (angle1 == 90 || angle2 == 90 || angle3 == 90) {
            cout << "����һ��ֱ�������Ρ�\n";
        } else {
            cout << "����һ����������Ρ�\n";
        }
    } else {
        cout << "����ĽǶ��޷����������Ρ�\n";
    }
}

// ���������εĵ������ǵĶ���
double calculateThirdAngle(double angle1, double angle2) {
    return 180 - (angle1 + angle2);
}
