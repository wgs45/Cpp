Design a character system, including the abstract category Player and two subcategories Enemy\_ and Knight, the abstract category Player
Has protected variables string name (character name) and int health (blood volume)

Pure virtual function void attack() for action subcategories for different characters to perform attacks Enemy and Knight have
public constructor: used to initialize the character's name and health

The void attack() function is used to perform the attack actions of Enemy and Knight.
Enemy's attack has 10 points of damage, and Knight's attack has 20 points of damage.
Suppose we have the following code to simulate attacks and injuries between game characters. Please refer to the following main() code.

int main(){
Player \*player = new Enemy( "Alice" , 100):
player-›attack();

    Player *player2 = new Knight ( "Bob", 100%;
    player2-›attack();

    return 0;

}

Example output:
Enemy attacks Alice, inflicting 10 damage!
Alice's health is now 90.

Knight attacks Bob, inflicting 20 damage!
Bob's health is now 80.
