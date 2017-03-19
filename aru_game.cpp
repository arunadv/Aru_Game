#include <iostream>
#include <string>
#include <cstring>
#include "aru_game.hpp"

#define HEAP_LEN 3

void startGame(char startingPlayer);

using namespace std;
using namespace ARU_GAME;

//global variables
int g_iHeap[HEAP_LEN];
Player playerA;
Player playerB;

int main(int argc, char **argv){
   int iInNum, iSum = 0;   
   
   for(int i=1; i <=3; i++){
	   cout << "Enter num " << i << ": ";
	   cin  >> iInNum;
	   g_iHeap[i-1] = iInNum;
	   iSum += iInNum;
   }
   
   // assert the inputs
   if(iSum > 21 || iSum < 1){
	   cerr << "Wrong input!"
	           "\nThe iSum of input numbers exceeds 21 or it is less than 1!!" 
			<< endl;
	   return -1;
   }
   else{
	   cout << "Coins available: ";
	   for(int i = 0; i < 3; i++){
		   cout << g_iHeap[i] << " ";
	   }
	   cout << endl;
	   cout << "Who starts first player A or B ?" << endl;
	   
	   // strcpy(playerA.m_chName, "Player A");
	   // strcpy(playerB.m_chName, "Player B");
	   playerA.m_strName = "Player A";
	   playerB.m_strName = "Player B";
	   
	   char firstPlayer;
	   cin  >> firstPlayer;
	   if(firstPlayer == 'A' || firstPlayer == 'a'){
		   // play the game with player A as the start
		   startGame(firstPlayer);
	   }
	   else if(firstPlayer == 'B' || firstPlayer == 'b'){
		   // play the game with player B as the start
		   startGame(firstPlayer);
	   }
	   else{
		   cerr << "Wrong input!"
	               "\nThe options must be only A or B!!" 
			    << endl;
	       return -1;
	   }
   }
      
   return 0;
}

void startGame(char startingPlayer){
	bool loopFlag = true;
	int iCoin;
	int iHeap;
	int iHeapSum = -1;
	int l_iHeap[HEAP_LEN];
	
	memcpy(l_iHeap, g_iHeap, sizeof(g_iHeap));
	
	while(loopFlag){
		if(startingPlayer ==  'A' || startingPlayer == 'a'){
			// Player A
			cout << "Player A: Enter coin (valid coins 1, 2, 3)... " << endl;
			// valid coins 1, 2, 3
			cin  >> iCoin;
			if(iCoin != 1 && iCoin != 2 && iCoin != 3){
				cerr << "Wrong input! enter only 1, 2, or 3"
				        "\nYou entered iCoin: " << iCoin
				     << endl;
				continue;
			}
			else{
                playerA.m_iCoin = iCoin;			
			}			
			
			cout << "Player A: Enter heap (valid heap 0, 1, 2)... " << endl;
			// valid heap 0, 1, 2
			cin  >> iHeap;
			if(iHeap != 0 && iHeap != 1 && iHeap != 2){
				cerr << "Wrong input! enter only 0, 1, or 2"
				        "\nYou entered iHeap: " << iHeap
				     << endl;
				continue;
			}
			else{
                playerA.m_iHeap = iHeap;
				// subtract the coin from l_iHeap
			    l_iHeap[playerA.m_iHeap] -= playerA.m_iCoin;
				
				cout << "Coins available: ";
	            for(int i = 0; i < 3; i++){
		           cout << l_iHeap[i] << " ";
				   iHeapSum += l_iHeap[i];		   
	            }
	            cout << endl;
				if(iHeapSum == 0){
					cout << "Game over! " 
					     << playerA.m_strName
						 << " wins!!" << endl;
				}
				else{
					iHeapSum = -1;
				}
			}		

			// Player B
            cout << "Player B: Enter coin (valid coins 1, 2, 3)... " << endl;
			// valid coins 1, 2, 3
			cin  >> iCoin;
			if(iCoin != 1 && iCoin != 2 && iCoin != 3){
				cerr << "Wrong input! enter only 1, 2, or 3"
				     << endl;
				continue;
			}
			else{
                playerB.m_iCoin = iCoin;			
			}			
			
			cout << "Player B: Enter heap (valid heap 0, 1, 2)... " << endl;
			// valid heap 0, 1, 2
			cin  >> iHeap;
			if(iHeap != 0 && iHeap != 1 && iHeap != 2){
				cerr << "Wrong input! enter only 0, 1, or 2"
				     << endl;
				continue;
			}
			else{
                playerB.m_iHeap = iHeap;
                // subtract the coin from l_iHeap
			    l_iHeap[playerB.m_iHeap] -= playerB.m_iCoin;	
                cout << "Coins available: ";
	            for(int i = 0; i < 3; i++){
		           cout << l_iHeap[i] << " ";
	            }
	            cout << endl;	
                if(iHeapSum == 0){
					cout << "Game over! " 
					     << playerB.m_strName
						 << " wins!!" << endl;
				}
				else{
					iHeapSum = -1;
				}				
			}
						
			loopFlag = true;
		}
		else if(startingPlayer ==  'B' || startingPlayer == 'b'){
			// Player B
            cout << "Player B: Enter coin (valid coins 1, 2, 3)... " << endl;
			// valid coins 1, 2, 3
			cin  >> iCoin;
			if(iCoin != 1 && iCoin != 2 && iCoin != 3){
				cerr << "Wrong input! enter only 1, 2, or 3"
				     << endl;
				continue;
			}
			else{
                playerB.m_iCoin = iCoin;			
			}			
			
			cout << "Player B: Enter heap (valid heap 0, 1, 2)... " << endl;
			// valid heap 0, 1, 2
			cin  >> iHeap;
			if(iHeap != 0 && iHeap != 1 && iHeap != 2){
				cerr << "Wrong input! enter only 0, 1, or 2"
				     << endl;
				continue;
			}
			else{
                playerB.m_iHeap = iHeap;
                // subtract the coin from l_iHeap
			    l_iHeap[playerB.m_iHeap] -= playerB.m_iCoin;				
				cout << "Coins available: ";
	            for(int i = 0; i < 3; i++){
		           cout << l_iHeap[i] << " ";
	            }
	            cout << endl;
				if(iHeapSum == 0){
					cout << "Game over! " 
					     << playerB.m_strName
						 << " wins!!" << endl;
				}
				else{
					iHeapSum = -1;
				}
			}
			
			// Player A
			cout << "Player A: Enter coin (valid coins 1, 2, 3)... " << endl;
			// valid coins 1, 2, 3
			cin  >> iCoin;
			if(iCoin != 1 && iCoin != 2 && iCoin != 3){
				cerr << "Wrong input! enter only 1, 2, or 3"
				     << endl;
				continue;
			}
			else{
                playerA.m_iCoin = iCoin;			
			}			
			
			cout << "Player A: Enter heap (valid heap 0, 1, 2)... " << endl;
			// valid heap 0, 1, 2
			cin  >> iHeap;
			if(iHeap != 0 && iHeap != 1 && iHeap != 2){
				cerr << "Wrong input! enter only 0, 1, or 2"
				     << endl;
				continue;
			}
			else{
                playerA.m_iHeap = iHeap;
                // subtract the coin from l_iHeap
			    l_iHeap[playerA.m_iHeap] -= playerA.m_iCoin;	
                cout << "Coins available: ";
	            for(int i = 0; i < 3; i++){
		           cout << l_iHeap[i] << " ";
	            }
	            cout << endl;
                if(iHeapSum == 0){
					cout << "Game over! " 
					     << playerA.m_strName
						 << " wins!!" << endl;
				}
				else{
					iHeapSum = -1;
				}				
			}
			
			loopFlag = true;
		}
		else{
			cerr << "Wrong args!" << endl;
			loopFlag = false;
		}
	} //  end while(loopFlag) 
} // end startGame 