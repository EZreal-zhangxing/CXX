#include<iostream>
#include<string>

using namespace std;

int main(){
    string temp = "";
    getline(cin,temp);// 换行符触发，并写入temp时丢弃最后一个换行符
    cout << temp << endl;
    cin >> temp; // 空格做为每个单词的结束
    cout << temp << endl;

    return 0;
}