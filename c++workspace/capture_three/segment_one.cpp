#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main(){
    vector<string> v(10,"hello");
    // 遍历中修改元素
    // for(int i=0;i<10;i++){
    //     v[i] = "world";
    // }
    for(vector<string>::value_type &temp : v){
        temp += " world";
    }
    // for(auto temp:v){
    //     cout << temp << endl;
    // }

    auto start = v.begin(),end = v.end();
    while(start != end){
        *start += "c";
        cout << *start << endl;
        start ++ ;
    }

    return 0;
}