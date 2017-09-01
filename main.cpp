#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <fstream>
#include <time.h>
#include <queue>


using namespace std;

int s=7,clicks=0,mines,minesLeft,seconds,score;
time_t timee;
bool first=true,lost=false;
string name;

char table[9][9];
char view[9][9];


void preGame(int choice);

int startMenu(){
    int choice;
    cout<<"\t\t\t*****  Minesweeper Game  *****\n\n";
    cout<<"\t\t\t 1- New game\n\t\t\t 2- Scores\n";

    cin>>choice;
    system("cls");
    preGame(choice);
}

void initializeView(){
    for(int i=0;i<s;i++){
        for(int k=0;k<s;k++){
            view[i][k] = 'X';
        }
    }
}

void initializeTable(){
    for(int i=0;i<s;i++){
        for(int k=0;k<s;k++){
            table[i][k] = ' ';
        }
    }
}

void preGame(int choice){
    if(choice == 1){
    int level=9;

    do{
        cout<<"\n\t\tChoose Level:\n\t\t1- Easy\n\t\t2- Intermediate\n\t\t3- Hard\n\n";
        cin>>level;
        system("cls");


        if(level == 1){s = 5;}
        else if(level == 2){s = 7;}
        else if(level == 3){s = 9;}
        else{
            cout<<"No such an option .. try again..";
            }}
    while(level!=1 && level!=2 && level!=3);

    mines = 1+(s*s)/10;
    minesLeft=mines;




    }
    else if(choice == 2){
        ifstream r;
        r.open("scores.txt");
        cout<<r.rdbuf();
        r.close();
        getch();
        system("cls");
        startMenu();
    }
    else{
        cout<<"No such a choice .. please try again";
        getch();
        system("cls");
        startMenu();
    }
}

void drawTable(){
    cout<<" ";
    for(int i=0;i<s;i++){cout<<i;}
    cout<<"\n";
    for(int i=0;i<s;i++){
        cout<<i;
        for(int k=0;k<s;k++){
            cout<<view[i][k];
        }
        cout<<"\n";
    }
    cout<<"\n\n";

    timee=clock();
    seconds=timee/1000;
}

void interface(int clicks,int minesLeft, int timee);

void fillTable(int row, int col){
    srand(time(0));
    int m=mines;
    int temprow,tempcol;

    while(m!=0){
    temprow=rand()%s;
    tempcol=rand()%s;

    if(table[temprow][tempcol]!='*' && temprow!=row && tempcol!=col){
        table[temprow][tempcol]='*';
        m--;
    }
    }

    for(int i=0;i<s;i++){
        for(int k=0;k<s;k++){
            if(table[i][k]!='*'){
                int num=0;

                if((i-1)>=0 && (i-1)<s && (k-1)>=0 && (k-1)<s && table[i-1][k-1]=='*'){num++;}
                if((i-1)>=0 && (i-1)<s && (k)>=0 && (k)<s && table[i-1][k]=='*'){num++;}
                if((i-1)>=0 && (i-1)<s && (k+1)>=0 && (k+1)<s && table[i-1][k+1]=='*'){num++;}
                if((i)>=0 && (i)<s && (k-1)>=0 && (k-1)<s && table[i][k-1]=='*'){num++;}
                if((i)>=0 && (i)<s && (k+1)>=0 && (k+1)<s && table[i][k+1]=='*'){num++;}
                if((i+1)>=0 && (i+1)<s && (k-1)>=0 && (k-1)<s && table[i+1][k-1]=='*'){num++;}
                if((i+1)>=0 && (i+1)<s && (k)>=0 && (k)<s && table[i+1][k]=='*'){num++;}
                if((i+1)>=0 && (i+1)<s && (k+1)>=0 && (k+1)<s && table[i+1][k+1]=='*'){num++;}

                if(num!=0){table[i][k]=num+'0';}
            }

        }
    }
}

void processActions(int action){
    int row,col;
    if(action==1 || action==2 || action==3 || action==4){
        do{
        cout<<"Row:";
        cin>>row;
        cout<<"Column:";
        cin>>col;
        if(row<0 || row>(s-1) || col<0 || col>(s-1)){cout<<"Wrong cell .. try again!\n";}
        }
        while(row<0 || row>(s-1) || col<0 || col>(s-1));

        if(first==true){
            fillTable(row,col);
            first=false;
        }

        if(action==1){
            view[row][col]=table[row][col];
            if(table[row][col]=='*'){lost=true;}


            else if(table[row][col]==' '){
                    queue<int> q;
                    q.push(row);
                    q.push(col);

                    while(!q.empty()){
                        int tempRow = q.front();
                        q.pop();
                        int tempCol = q.front();
                        q.pop();


                        cout<<"Check!";

                        if((tempRow-1)>=0 && (tempRow-1)<s && (tempCol-1)>=0 && (tempCol-1)<s && table[tempRow-1][tempCol-1]==' '){q.push(tempRow-1);q.push(tempCol-1);}
                        if((tempRow-1)>=0 && (tempRow-1)<s && (tempCol)>=0 && (tempCol)<s && table[tempRow-1][tempCol]==' '){q.push(tempRow-1);q.push(tempCol);}
                        if((tempRow-1)>=0 && (tempRow-1)<s && (tempCol+1)>=0 && (tempCol+1)<s && table[tempRow-1][tempCol+1]==' '){q.push(tempRow-1);q.push(tempCol+1);}
                        if((tempRow)>=0 && (tempRow)<s && (tempCol-1)>=0 && (tempCol-1)<s && table[tempRow][tempCol-1]==' '){q.push(tempRow);q.push(tempCol-1);}
                        if((tempRow)>=0 && (tempRow)<s && (tempCol+1)>=0 && (tempCol+1)<s && table[tempRow][tempCol+1]==' '){q.push(tempRow);q.push(tempCol+1);}
                        if((tempRow+1)>=0 && (tempRow+1)<s && (tempCol-1)>=0 && (tempCol-1)<s && table[tempRow+1][tempCol-1]==' '){q.push(tempRow+1);q.push(tempCol-1);}
                        if((tempRow+1)>=0 && (tempRow+1)<s && (tempCol)>=0 && (tempCol)<s && table[tempRow+1][tempCol]==' '){q.push(tempRow+1);q.push(tempCol);}
                        if((tempRow+1)>=0 && (tempRow+1)<s && (tempCol+1)>=0 && (tempCol+1)<s && table[tempRow+1][tempCol+1]==' '){q.push(tempRow+1);q.push(tempCol+1);}

                        view[tempRow][tempCol]=' ';
                        table[tempRow][tempCol]='O';


                    }

            }
        }
        else if(action==2){
            if(view[row][col]!=' ' && !isdigit(view[row][col])){
                view[row][col]='F';
                minesLeft--;}
            else{cout<<"Wrong action!\n";
            getch();}
        }
        else if(action==3){
            if(view[row][col]!=' ' && !isdigit(view[row][col])){
                view[row][col]='?';}
            else{cout<<"Wrong action!\n";
            getch();}
        }
        else if(action==4){
            if(view[row][col]='F'){minesLeft++;}
            if(view[row][col]!=' ' && !isdigit(view[row][col])){
                view[row][col]='X';}
            else{cout<<"Wrong action!\n";
            getch();}

        }
        clicks++;

        system("cls");
        interface(clicks,minesLeft,timee);

    }
    else if(action==5){
        exit(0);
    }
    else{
        cout<<"wrong action!";
        getch();
        system("cls");
        interface(clicks,minesLeft,timee);

    }
}

void interface(int clicks,int minesLeft, int timee){
    drawTable();



    if(lost==true){cout<<"You Lost!\n";
        getch();
        exit(0);}

    int numb=0;
    for(int i=0;i<s;i++){
        for(int k=0;k<s;k++){
            if(view[i][k]=='X' || view[i][k]=='F' || view[i][k]=='?'){numb++;}
        }
    }
    if(numb<=mines){cout<<"Congrats..You Win!!\n";
    cout<<"Enter your name: ";
    cin>>name;
    score= (s*s*s*s*s*s*s*s)/(seconds*clicks);
    cout<<"Your score: "<<score;
    cout<<"\n\n"<<name<<"\t"<<score<<"\n\n";
    ofstream f;
    f.open("scores.txt",std::ios_base::app);
    f<<"\n"<<name<<"\t"<<score;
    f.close();
    getch();
    exit(0);


    }


    cout<<"Clicks: "<<clicks<<"  - Mines left: "<<minesLeft<<"  - Seconds: "<<seconds;
    cout<<"\n\n";

    cout<<"What to do..?\n1-Open Cell\t2-Flag\t\t3-Question\t4-Unmark\n5-Exit\n";

    int action;
    cin>>action;

    processActions(action);

}





int main()
{
    startMenu();

    initializeView();
    initializeTable();

    interface(clicks,minesLeft,timee);

}
