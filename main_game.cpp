#include <iostream>
#include <windows.h>
#include <stdlib.h>
#include "Characters.h"

    struct Player{
        std::string name {" "};
        unsigned int HP{100};
        unsigned int ATK{10};
        unsigned int HEAL{20};
    };

    struct Enemy{
        std::string name {" "};
        unsigned int HP{100};
        unsigned int ATK{15};
    };


    bool gameState(int player_status, int enemy_status){
        if(player_status <= 0 && enemy_status >= 1){
            std::cout << "\n``Player lose, game over``\n";
            return false;
        }

         if(player_status >= 1 && enemy_status <= 0){
            std::cout << "\n``Player wins!!``\n";
            return false;
        }

         if (player_status <= 0 && enemy_status <= 0){
            std::cout << "\n``Game Tie``\n";
           return false;
        }
        
    return true;
    
    }

   
int main(){
    //game updates
    std::cout << "``Welcome to Basic Attack Demo``\n 1. Play \n" <<"Press '1' to play: ";
    int play{config()};

    Player warrior;
    Enemy orc;
    
    warrior.name = " ";
    std::cout << std::endl << "Set warrior name: ";
    std::cin >> warrior.name;
    orc.name = " ";
    std::cout << "Set orc name: ";
    std::cin >> orc.name;\

    

    while(gameState(warrior.HP, orc.HP) != false){
      // In-game   

            std::cout << "\n\n";
            std::cout << "Game Status:\n" << warrior.name << "(You): " << warrior.HP << " HP\n" << 
            orc.name << "(Enemy): " << orc.HP << " HP\n";
            std::cout << "Choose: \n" << "1. attack \n" << "2. heal \n\n" << "enter command: ";
            int input {};
            std::cin >> input;

            //Orc's turn
            warrior.HP -= orc.ATK;

                //battle inputs
                if (input == 1){
                    orc.HP -= warrior.ATK;
                } 
                if (input == 2)
                {
                    warrior.HP += warrior.HEAL;
                } 
                
    }

 system("pause");

}


