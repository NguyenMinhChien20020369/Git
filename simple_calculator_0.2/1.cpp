#include <bits/stdc++.h>

using namespace std;

double arithmetic(double num1, double num2, char op)
{
    switch (op) {
    case '+':
        return num1 + num2;
    case '-':
        return num1 - num2;
    case 'x':
        return num1 * num2;
    case '/':
        if (num2 == 0) {
            cout << "Invalid divisor" << endl;
            exit(1);
        }
        else
            return num1 / num2;
    default:
        cout << "Invalid operator" << endl;
        exit(1);
    }
}

double arithmetic_2(string enter_operator, double num)
{
    if(enter_operator=="sin"){
        return sin(num);}else
    if(enter_operator=="cos"){
        return cos(num);}
    else if(enter_operator=="tan"){
        return tan(num);}
    else if(enter_operator=="cot"){
        return double(1) / tan(num);}
    else if(enter_operator=="sqrt"){
        return sqrt(num);}else{
        cout << "Invalid operator" << endl;
        exit(1);
        }

}

int main(int argc, char* argv[])
{
    if(argc==3){
        if(argv[2]!="0"&&atof(argv[2])==0){
            cout<<"Invalid parameter";
        }else{
            string enter_operator=argv[1];
            double num=atof(argv[2]);
            cout<<arithmetic_2(enter_operator,num);
        }

    }else{

        double num1, num2;
        char op;

        num1 = atof(argv[1]);
        op = argv[2][0];
        num2 = atof(argv[3]);

        if((argv[1]!="0"&&num1==0)||(argv[3]!="0"&&num2==0)){
            cout<<"Invalid parameter";
        }else{
            cout << arithmetic(num1, num2, op);
            return 0;
        }

    }
}
