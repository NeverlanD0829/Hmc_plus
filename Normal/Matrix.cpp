#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> generateZeroMatrix(int n){
    vector<vector<int>> matrix(n,vector<int>(n,0));         //(n,0) n为数组维度，0为值
    return matrix;
}

int main(){
    vector<vector<int>> zeroMatrix=generateZeroMatrix(3);

    for(int i=0;i<zeroMatrix.size();i++){
        for (int j = 0; j < zeroMatrix.size(); j++)
        {
            cout<<zeroMatrix[i][j]<<' ';
        }
        cout<<endl;
    }
    return 0;
}