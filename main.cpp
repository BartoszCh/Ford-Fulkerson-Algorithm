#include <iostream>
#include <fstream>
#include <stdio.h>
#include <conio.h>

using namespace std;

int maxFlow = 0;

int toInt(string number_s){
    int dlugosc = number_s.length();
    int number_i = 0;
    for(int i=0; i<dlugosc; i++){
        number_i *= 10;
        number_i += number_s[i]-'0';
    }
    return number_i;
}

int countVertex(int dlugosc, int graf[][3]){
    int ret=-1;
    for (int i=0; i<dlugosc; i++){
        if(graf[i][0]>ret) ret = graf[i][0];
        if(graf[i][1]>ret) ret = graf[i][1];
    }
    return (ret+1);
}

int getLength(string fileName){
    int length = 0;
    ifstream file;
    string line;
    file.open(fileName);
    while(file){
        getline(file, line);
        if (line[0]=='[') length++;
    }
    file.close();
    return length;
}

void reset(int length, int taken[]){
    for(int i=0; i<length; i++) taken[i]=0;
}

bool pathExists(int start, int stop, int length, int graf[][3], int taken[], int takenV[]){
    if(start == stop){
        //  cout << start;
         return true;
    }
    else{
        takenV[start] = 1;
        for(int i=0; i<length; i++){
            if(graf[i][0] == start && taken[i]!= 1 && graf[i][2]>0 && takenV[graf[i][1]] != 1) {
                // cout << graf[i][0] << "->";
                taken[i]=1;
                if(pathExists(graf[i][1], stop, length, graf, taken, takenV)) return true;
                taken[i]=0;
                takenV[graf[i][1]] = 0;
            }
        }
    }
    return false;   
}

int minFlow(int length, int taken[], int flow[][3]){
    int ret = 99999;
    for(int i=0; i<length; i++){
        if(taken[i]==1 && flow[i][2]<ret) ret=flow[i][2];
    }
    return ret;
}

void writeGraph(int length, int graph[][3]){
    cout << endl;
    for(int i=0; i<length; i++){
        for(int j=0; j<3;j++){
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}


void EdmondKarp(int start, int stop, int length, int flow[][3], bool found, int smallestFlow, int taken[], int takenV[], int v){
    
    reset(length, taken);
    reset(v, takenV);
    if(start == stop){
         found = true;
    }
    else{
        if(pathExists(start, stop, length, flow, taken, takenV)){
            int minimum = minFlow(length, taken, flow);
            // writeGraph(length, flow);
            for(int i=0; i<length; i++){
                if(taken[i]==1){
                    flow[i][2] -= minimum;
                }
            }
            // writeGraph(length, flow);
            maxFlow+=minimum;
        }
    }
}

int main(){
    int dlugosc = getLength("test.txt");
    int graf[dlugosc-1][3];                                                                               
    ifstream file;
    file.open("test.txt");
    char c;
    file.get(c);
    string numb = "";
    int index=0, linia=0;
    while(file.get(c)){
        if(linia>=dlugosc) break;
        if( c >='0' && c<='9') numb.push_back(c);
        if( c == ',') {
            graf[linia][index] = toInt(numb);
            numb = "";
            index++;
        } 
        if( c == ']'){
            graf[linia][index] = toInt(numb);
            numb = "";
            index = 0;
            linia++;
        }
    }
    cout << "Wczytany graf: \n";
    for(int i=0; i<dlugosc; i++){
        for(int j=0; j<3; j++){
            cout << graf[i][j] << " ";  
        }
        cout << endl;
    }


    int v = countVertex(dlugosc, graf);

    int zajete[dlugosc];
    int zajeteW[v];
    reset(v, zajeteW);
    // bool czyIstnieje = pathExists(0, 5, dlugosc, graf, zajete);
    // cout << "       " << czyIstnieje;

    reset(dlugosc, zajete);
    
    // bool czyIstnieje = pathExists(0, 5, dlugosc, graf, zajete, zajeteW);
    // cout << "       " << czyIstnieje;
    int start;
    int stop;
    cout << "Podaj wierzcholek startowy: ";
    cin >> start;
    cout << "Podaj wierzcholek koncowy:";
    cin >> stop;
    bool istnienie = pathExists(start, stop, dlugosc, graf, zajete, zajeteW);
    if(istnienie != 1) cout << "Miedzy tymi wierzcholkami nie ma przeplywu.";
    // cout << endl << istnienie;
    while(istnienie){
        reset(dlugosc, zajete);
        reset(v, zajeteW);
        for(int i=0; i<dlugosc; i++){
            zajete[i]=0;
        }
        // cout << endl << "CZY ISTNIEJE? " << pathExists(start, stop, dlugosc, graf, zajete, zajeteW) << endl;
        // cout << endl << "AKTUALNY PRZEPLYW: " << maxFlow << endl;
        
        // reset(dlugosc, zajete);
        // reset(v, zajeteW);
        EdmondKarp(start, stop, dlugosc, graf, false, 10000, zajete, zajeteW, v);

        reset(dlugosc, zajete);
        reset(v, zajeteW);
        istnienie = pathExists(start, stop, dlugosc, graf, zajete, zajeteW);
    }

    cout << "Maksymalny przeplyw miedzy tymi wierzcholkami wynosi: " <<maxFlow;
    file.close();
}