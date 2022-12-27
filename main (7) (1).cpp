#include <iostream> 
using namespace std;
void nextColumn(int q[], int &c); 
void nextRow(int q[], int &c);
void backtrack(int q[], int &c);
void print(int q[]);
bool ok(int q[], int col);

bool ok(int q[], int col){  // the okay function
    for (int r = 0; r < col; r++){
        if ((q[r] == q[col]) || (col - r == abs(q[col] - q[r]))){
            return false;}  
//else {
    //return true;
    //} 
}
return true;  //added
}
void nextColumn(int q[], int &c) {
	c++;//pass the value of c by reference so it can be altered within the function
	//go to the next column (alter the value of c)
	if (c == 8) {
		    print(q);
                backtrack(q,c);//we have a solution
	}
	nextRow(q, c);
}

void nextRow(int q[], int &c){

 q[c]++; //move to the next row
    if (q[c] == 8)
{  
q[c] = -1; // reset the value
 
backtrack(q, c); 
 
} 
        else if (ok(q, c))
 { 
 
nextColumn(q, c); //since the value we are trying to place in square c is valid since bool ok returns true we can go to the
}
else {
nextRow(q, c);//we need to try a new value in square c (i.e. go to the next row)
 
    }
 
    } 

void backtrack(int q[], int &c) {
	c--;
	if (c == -1) {
		exit(0); //we have backtracked into the non-existent column -1 which
		//means we've found all solutions and can terminate the program
	}
	nextRow(q, c);
}

void print(int q[]){
static int  sol =0;  
   cout << "Sol #" << ++sol;
        typedef char box [5][7];
        box bb, wb, *board[8][8];
       box bq = {{ ' ', ' ', ' ', ' ', ' ', ' ', ' ' },

                 {' ', ' ', char(219) , ' ',' ',' ', ' ' },

                 {' ', ' ', char(219) , ' ', ' ', ' ', ' '},

                 {' ', ' ', char(219) , char(219), char(219), ' ', ' '},

                 {' ', ' ', ' ', ' ', ' ', ' ', ' '}};
    
    box wq =     {{char(219), char(219), char(219), char(219), char(219), char(219), char(219)},

                 {char(219), char(219), ' ' , char(219),char(219),char(219), char(219)},

                 {char(219), char(219), ' ' , char(219), char(219), char(219), char(219)},

                 {char(219), char(219), ' ' , ' ', ' ', char(219), char(219)}, 

                 {char(219), char(219), char(219), char(219), char(219), char(219), char(219)}};
        for (int r = 0; r < 5; r++)
            for (int c = 0; c < 7; c++)
                {wb[r][c] = ' ';
                    bb[r][c] = char(219);
            }
        
    for(int r = 0; r < 8; r++ ) 
        for(int c = 0; c < 8; c++)
            if ( (r + c) % 2 == 0)
                if(q[c] == r){ ///just like the print function in the the 1d assignment 
                board[r][c] = &bq;
                   }              
                else{
                     board[r][c] = &wb;
                }
            else if ((r + c) % 2 != 0){
                if(q[c] == r){
                    board[r][c] = &wq;
                } 
                    else {
                  board[r][c] = &bb; 
               }
                
            }
    cout <<"";
    for (int r = 0; r < 7*8;r++)
        cout <<'_';
     cout << endl;
    for(int r = 0; r < 8; r++)
        for(int k = 0; k < 5; k++)
            {cout <<"     "<<char(179);
        for(int c = 0; c < 8; c++)
            for(int l = 0; l < 7; l++)
                cout << (*board[r][c])[k][l];    //dereferances board 
                     cout<< char(179) << endl;
    }
    cout <<"     ";
    for(int r = 0; r <7*8; r++)
        cout << char(196);
        cout << endl;
    
}

int main() 
{
    int q[8] = {0}, c = 0;
    nextColumn(q,c);
    return 0;
}

