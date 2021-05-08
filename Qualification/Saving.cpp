#include <bits/stdc++.h>
using namespace std;
#include <math.h>  
#include <string.h>
#include <map>
#include <vector>

int Costo(string p){
    int balas=1;
    int acum=0;

    for(int i=0;i<p.size();i++){
        if(p[i]=='C'){
        balas=balas*2;    
        }else{
            acum=acum+balas;
        }
    }

   return acum; 
}


void Solve(int D,string P,int t){
int steps=0;
vector<int>Cs;
for(int i=0;i<P.size()-1;i++){
    if(P[i]=='C'){
    Cs.push_back(i);
    }
}

int c=Costo(P);
for(int i=Cs.size()-1;i>=0;i--){
    if(c<=D){
    break;    
    }

    for(int j=Cs[i];j<P.size()-1;j++){
    c=Costo(P);
    if(c<=D){
        break;
    }
    if(P[j]!=P[j+1]){
    char a=P[j];
    P[j]=P[j+1];
    P[j+1]=a;
    steps=steps+1;
    }else{
        break;
    }
    }

}

if(Costo(P)>D){
    cout<<"Case #"<<t+1<<": "<<"IMPOSSIBLE"<<endl;
}else{
    cout<<"Case #"<<t+1<<": "<<steps<<endl;
}


}



int main(){
    int T;
    cin>>T;

    for(int t=0;t<T;t++){
    int D;
    string P;
    cin>>D;
    cin>>P;
    Solve(D,P,t);    

    }




   return 0;
}