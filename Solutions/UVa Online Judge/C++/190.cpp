#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main(void){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    double  x1, y1, x2, y2, x3, y3;
    while(cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3){
        // DETERMINANTES
        double A = (x1 * (y2 - y3)) - (y1 * (x2 - x3)) + (x2 * y3) - (x3 * y2);
        double B = ((pow(x1, 2) + pow(y1, 2)) * (y3 - y2)) + ((pow(x2, 2) + pow(y2, 2)) * (y1 - y3)) + ((pow(x3, 2) + pow(y3, 2)) * (y2 - y1));
        double C = ((pow(x1, 2) + pow(y1, 2)) * (x2 - x3)) + ((pow(x2, 2) + pow(y2, 2)) * (x3 - x1)) + ((pow(x3, 2) + pow(y3, 2)) * (x1 - x2));
        double D = ((pow(x1, 2) + pow(y1, 2)) * ((x3 * y2) - (x2 * y3))) + ((pow(x2, 2) + pow(y2, 2)) * ((x1 * y3) - (x3 * y1))) + ((pow(x3, 2) + pow(y3, 2)) * ((x2 * y1) - (x1 * y2)));
        // CENTRO E RAIO
        double x = -(B/(2*A));
        double y = -(C/(2*A));
        double r = sqrt((pow(B, 2) + pow(C, 2) - (4*A*D))/(4*A*A));
        
        cout << fixed << setprecision(3);
        // PRIMEIRA EQUACAO
        char op[3];
        if(x < 0) op[0] = '+';
        else op[0] = '-';
        if(y < 0) op[1] = '+';
        else op[1] = '-';
        if(x == 0 && y == 0) cout << "x^2 + y^2 = " << r << "^2" << endl;
        else if(x == 0 && y < 0) cout << "x^2" << " + (y + " << abs(y) << ")^2 = " << r << "^2" << endl;
        else if(x == 0 && y > 0) cout << "x^2" << " + (y - " << y << ")^2 = " << r << "^2" << endl;
        else if(y == 0 && x < 0) cout << "(x + " << x << ")^2 + y^2 = " << r << "^2" << endl;
        else if(y == 0 && x > 0) cout << "(x - " << abs(x) << ")^2 + y^2 = " << r << "^2" << endl;
        else cout << "(x " << op[0] << " " << abs(x) << ")^2 + (y " << op[1] << " " << abs(y) << ")^2 = " << r << "^2" << endl;

        // SEGUNDA EQUACAO
        if(B/A == 0 && C/A == 0){
            if(D/A < 0){
                cout << "x^2 + y^2 - " << abs(D/A) << " = 0" << endl;
            }else{
                cout << "x^2 + y^2 + " << D/A << " = 0" << endl; 
            }
        }else if(B/A == 0 && C/A < 0){
            if(D/A < 0){
                cout << "x^2 + y^2 - " << abs(C/A) << "y - " << abs(D/A) << " = 0" << endl;
            }else{
                cout << "x^2 + y^2 - " << abs(C/A) << "y + " << D/A << " = 0" << endl;
            }
        }else if(B/A == 0 && C/A > 0){
            if(D/A < 0){
                cout << "x^2 + y^2 + " << abs(C/A) << "y - " << abs(D/A) << " = 0" << endl;
            }else{
                cout << "x^2 + y^2 + " << abs(C/A) << "y + " << D/A << " = 0" << endl;
            }
        }else if(B/A < 0 && C/A == 0){
            if(D/A < 0){
                cout << "x^2 + y^2 - " << abs(B/A) << "x - " << abs(D/A) << " = 0" << endl;
            }else{
                cout << "x^2 + y^2 - " << abs(B/A) << "x + " << D/A << " = 0" << endl;
            }
        }else if(B/A > 0 && C/A == 0){
            if(D/A < 0){
                cout << "x^2 + y^2 + " << abs(B/A) << "x - " << abs(D/A) << " = 0" << endl;
            }else{
                cout << "x^2 + y^2 + " << abs(B/A) << "x + " << D/A << " = 0" << endl;
            }
        }else{
            if(B/A < 0 && C/A < 0){
                if(D/A < 0){
                    cout << "x^2 + y^2 - " << abs(B/A) << "x - " << abs(C/A) << "y - " << abs(D/A) << " = 0" << endl;
                }else{
                    cout << "x^2 + y^2 - " << abs(B/A) << "x - " << abs(C/A) << "y + " << D/A << " = 0" << endl;
                }
            }else if(B/A > 0 && C/A > 0){
                if(D/A < 0){
                    cout << "x^2 + y^2 + " << abs(B/A) << "x + " << abs(C/A) << "y - " << abs(D/A) << " = 0" << endl; 
                }else{
                    cout << "x^2 + y^2 + " << abs(B/A) << "x + " << abs(C/A) << "y + " << D/A << " = 0" << endl;
                }
            }else if(B/A > 0 && C/A < 0){
                if(D/A < 0){
                    cout << "x^2 + y^2 + " << abs(B/A) << "x - " << abs(C/A) << "y - " << abs(D/A) << " = 0" << endl;
                }else{
                    cout << "x^2 + y^2 + " << abs(B/A) << "x - " << abs(C/A) << "y + " << D/A << " = 0" << endl;
                }
            }else if(B/A < 0 && C/A > 0){
                if(D/A < 0){
                    cout << "x^2 + y^2 - " << abs(B/A) << "x + " << abs(C/A) << "y - " << abs(D/A) << " = 0" << endl;
                }else{
                    cout << "x^2 + y^2 - " << abs(B/A) << "x + " << abs(C/A) << "y + " << D/A << " = 0" << endl;
                }
            }
        }

        if(!cin.eof()) cout << endl;
    }
    return 0;
}