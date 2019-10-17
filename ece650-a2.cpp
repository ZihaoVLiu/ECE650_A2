// Created by Zihao Liu on 2019-10-12.
//
#include <iostream>
#include <string>
#include <regex>
using namespace std;

// build a array to store edge elements.
int edgeList[10000];
int startendList[2];
int iarray[5000];
int jarray[5000];
int EleLength;// the number of edge end and start points.
int VNumber; //the number of vertexs.
int ENumber; //the number of edges.
int inf = 9999999; //define a infinite number.
int graph[5000][5000]; // build a matrix to store graph structure.
int parents[5000][5000]; // build matrix to store the path.

// function to get the input string.
string getString(){
    string gather;
    getline(cin, gather);
    return gather;
}

// function to append edge elements into the edgeList.
void getEdgeArr(string gather){
    smatch result;
    regex pattern("-?[1-9]\\d*|0");
    string::const_iterator iterStart = gather.begin();
    string::const_iterator iterEnd = gather.end();
    string temp;
    int index = 0;
    while (regex_search(iterStart, iterEnd, result, pattern)){
        temp = result[0];
        edgeList[index] = stoi(temp);
        iterStart = result[0].second;
        index += 1;
    }
    EleLength = index;
    ENumber = index/2;
}

// function to get the start and end point after input 's'.
void getStartEndPoint(string gather){
    smatch result;
    regex pattern("-?[1-9]\\d*|0");
    string::const_iterator iterStart = gather.begin();
    string::const_iterator iterEnd = gather.end();
    string temp;
    int index = 0;
    while (regex_search(iterStart, iterEnd, result, pattern)){
        temp = result[0];
        startendList[index] = stoi(temp);
        iterStart = result[0].second;
        index += 1;
    }
}

// function to get the number of vertex. Using after input command V.
void getVNumber(string gather){
    smatch result;
    regex pattern("[1-9]\\d*");
    string::const_iterator iterStart = gather.begin();
    string::const_iterator iterEnd = gather.end();
    string temp;
    while (regex_search(iterStart, iterEnd, result, pattern)){
        temp = result[0];
        iterStart = result[0].second;
    }
    VNumber = stoi(temp);
}

// append i, j (start and end point of edges) into array.
void twoArray(){
    int valuei = 0;
    int valuej = 1;
    for (int i = 0; i < EleLength/2; ++i) {
        iarray[i] = edgeList[valuei];
        valuei += 2;
    }
    for (int j = 0; j < EleLength/2; ++j) {
        jarray[j] = edgeList[valuej];
        valuej += 2;
    }
}

// use Floyd algorithm to build a route cost matrix
// and build a two-dimension array and initial each row.
void floyd(){
    //initialization parents[][]
    for (int l = 0; l < VNumber; ++l) {
        for (int i = 0; i < VNumber; ++i) {
            parents[l][i] = l;
        }
    }
    // build the graph.
    for (int i = 0; i < VNumber; ++i) {
        for (int j = 0; j < VNumber; ++j) {
            if (i == j) graph[i][j] = 0;
            else graph[i][j] = inf;
        }
    }
    // input the edge information.
    for (int i = 0; i < ENumber; ++i) {
        graph[iarray[i]][jarray[i]] = 1;
        graph[jarray[i]][iarray[i]] = 1;
    }

    //Floyd-Warshall algorithm
    for (int k = 0; k < VNumber; ++k) {
        for (int i = 0; i < VNumber; ++i) {
            for (int j = 0; j < VNumber; ++j) {
                if (graph[i][j] > graph[i][k] + graph[k][j]){
                    graph[i][j] = graph[i][k] + graph[k][j];
                    parents[i][j] = parents[k][j];
                }
            }
        }
    }
}

// use Recursive to get the parent of each edge.
void print_path(int i, int j){
    if (i != j){
        print_path(i, parents[i][j]);
    }
    if (startendList[1] != j)
        cout << j << "-";
    else
        cout << j << endl;
}

// detect is there a edge between two input node.
int IsCovered(){
    if (graph[startendList[0]][startendList[1]] == inf){
        cout << "Error: There is no edge between start and end nodes." << endl;
        return 0;
    }
    return 1;
}


// If input edge nodes exceeds the vertex number, an error will be output.
int eInVertex(){
    int temp = 1;
    for (int i = 0; i < EleLength; ++i) {
        if (edgeList[i] >= VNumber) {
            cout << "Error: Input edge node does not exist." << endl;
            temp = 0;
            break;
        }
    }
    return temp;
}

// If an input s path does not exist between the vertices, an error will be output.
int sInEdge(){
    int start = 0, end = 0;
    for (int i = 0; i < EleLength; ++i) {
        if (edgeList[i] == startendList[0]){
            start = 1;
        }
        if (edgeList[i] == startendList[1]){
            end = 1;
        }
    }
    if ((start + end) == 2){
        return 1;
    }
    else{
        cout << "Error: Input s is not a edge node or not a vertex." << endl;
        return 0;
    }
}


int main() {
    for (;;)
    {
        string gather = getString();
        int judge;
        char firstChar = gather[0];
        if (firstChar == 'V'){
            getVNumber(gather);
            continue;
        }
        if (firstChar == 'E'){
            getEdgeArr(gather);
            if (eInVertex() == 0){
                judge = 1;
                continue;
            }
            judge = 0;
            twoArray();
            floyd();
            continue;
        }
        if (firstChar == 's'){
            if (judge == 0) {
                getStartEndPoint(gather);
                if (sInEdge() == 0) continue;
                if (IsCovered() == 0) continue;
                print_path(startendList[0], startendList[1]);
                continue;
            }
            else {
                cout << "Error: No Edges are input." << endl;
                continue;
            }
        }
        /*if (firstChar != 'V' && firstChar != 'E' && firstChar != 's'){
            cout << "Error: Input is invalid." << endl;
        }*/
        return 0;
    }
}