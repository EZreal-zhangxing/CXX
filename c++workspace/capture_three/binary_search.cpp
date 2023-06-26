#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main(){
    vector<int> v = {0,1,2,3,4,5,6,7,8,9,100,333};
    int search = -1;
    cin >> search;
    auto start = v.begin(),end = v.end();
    while (start <= end){
        auto mid = start + (end - start)/2;
        if(*mid == search){
            cout << "find index :" << mid - v.begin() << endl;;
            return 0;
        }else if(*mid < search){
            start = mid+1;
        }else{
            end = mid - 1;
        }
    }
    cout << "can not find you input " << endl;
    return 0;
}
