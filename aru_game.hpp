#include <string>

typedef short STATUS;

#define WIN 1
#define LOST -1
#define INP_ERROR -2

namespace ARU_GAME{
   class Player{
       public:
	       int m_iCoin;
	       int m_iHeap;
           std::string m_strName;
           STATUS m_iStatus;
    
           Player(){
		       m_iCoin = 0;
		       m_iHeap = 0;
               // m_strName = "";			   
		       m_iStatus = 0;			  
	       }
	       // ~Player();
    };
}