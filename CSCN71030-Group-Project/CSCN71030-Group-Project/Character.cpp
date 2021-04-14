#include "Character.h"

Character::Character(std::string name)
{
    this->attack = 0;
    this->current_health = 0;
    this->defence = 0;
    this->max_health = 0;
    this->speed = 0;

    this->name = name;
}

Character::Character(json j) 
{
    this->attack = j["attack"];
    this->current_health = j["current health"];
    this->defence = j["defence"];
    this->max_health = j["max health"];
    this->speed = j["speed"];
    this->name = j["name"];
}

json Character::jsonify() 
{
    json result;
    result["name"] = this->name;
    result["current health"] = this->current_health;
    result["max health"] = this->max_health;
    result["attack"] = this->attack;
    result["defence"] = this->defence;
    result["speed"] = this->speed;

    return result;
}

void Character::setHealth(int health)
{
    this->current_health = health;
}

int Character::getHealth()
{
    return this->current_health;
}

int Character::getMaxHealth() 
{
    return this->max_health;
}

int Character::getAttack()
{
    return this->attack;
}

int Character::getDefence()
{
    return this->defence;
}

int Character::getSpeed()
{
    return this->speed;
}

std::string Character::getSprite()
{
    return this->sprite;
}

std::string Character::getFightSprite()
{
    return this->fight_sprite;
}

std::string Character::getDeadSprite()
{
    return this->dead_sprite;
}

std::string Character::getName()
{
    return this->name;
}

bool Character::getPrepared()
{
    return this->isPrepared;
}

bool Character::setPrepared(bool preperation)
{
    this->isPrepared = preperation;
    return this->isPrepared;
}

spoon::spoon(std::string name) : Character(name)
{
    // Set stats
    this->max_health = 10;
	this->attack = 5;
	this->defence = 10;
	this->speed = 4;
    this->current_health = this->max_health;

    this->sprite = R"(
                __
              .'  '.
              'o  o'
              '.  .'
                ||
                ||
                ||
                ||
                --
)";
    this->fight_sprite = R"(
                     _
                  .' V'.
                 '  o o'
                 '. .-'
                  //
                 //
                //
               //
              (/
)";
    this->dead_sprite = R"(
                __
              .'  '.
              '*  *'
              '.  .'
                ||
                ||
                ||
                ||
                --
)";
}

json spoon::jsonify() 
{
    json result = Character::jsonify();
    result["type"] = "spoon";
    return result;
}


fork::fork(std::string name) : Character(name)
{
    this->max_health = 7;
	this->attack = 7;
	this->defence = 5;
	this->speed = 10;
    this->current_health = this->max_health;
    
    this->sprite = R"(
                 ||||  
                 ||||
                 \oo/
                  ||
                  ||
                  ||
                  ||
                  --
)";
    this->fight_sprite = R"(
                   ////\ 
                  /V//
                 (oo/
                  //
                 //
                //
               //
              (/
)";
    this->dead_sprite = R"(
                 |||| 
                 ||||
                 \**/
                  ||
                  ||
                  ||
                  ||
                  --
)";
}

json fork::jsonify() 
{
    json result = Character::jsonify();
    result["type"] = "fork";
    return result;
}

knife::knife(std::string name) : Character(name)
{
    this->max_health = 5;
	this->attack = 10;
	this->defence = 2;
	this->speed = 8;
    this->current_health = this->max_health;

    this->sprite = R"(
                  .-'
                 /  |
                 |oo|
                 |  |
                 |  |
                 '._|
                   ||
                   ||
                   ||
                   ||
                   --
)";
    this->fight_sprite = R"(

                .-'
               /V /
              /oo/
             /  /
            /  /
           '. /
            --
           //
          //
         //
        //
       (/

)";
    this->dead_sprite = R"(
                  .-'
                 /  |
                 |**|
                 |  |
                 |  |
                 '._|
                   ||
                   ||
                   ||
                   ||
                   --
)";
}


json knife::jsonify() 
{
    json result = Character::jsonify();
    result["type"] = "knife";
    return result;
}

DrawerEnemy::DrawerEnemy(int max_health, int attack, int defence, int speed) 
: Character((std::string) "DrawerEnemy")
{
    this->attack = attack;
    this->max_health = max_health;
    this->current_health = max_health;
    this->defence = defence;
    this->speed = speed;

    this->sprite = R"(
                     _
                  ./ /V'/.
                 (/o  o/)
                 './ /.-'
                  //
                 //
                //
               //
              (/
)";

    this->dead_sprite = R"(
                __
              .'||'.
             ( *||* )
              '.||.'
                ||
                ||
                ||
                ||
                --
)";
}

DrawerBoss::DrawerBoss(int max_health, int attack, int defence, int speed)
: Character((std::string) "Chef's Knife")
{
    this->attack = attack;
    this->max_health = max_health;
    this->current_health = max_health;
    this->defence = defence;
    this->speed = speed;

    this->sprite = R"(
                  _ .
               .'   '
              /\ / /
             /o o /
            /    /
           /    /
           \_  /
            / /
           / /
          / /
         / /
        ( /

)";
   this->dead_sprite = R"(
                  _ .
               .'   '
              /\ / /
             /* * /
            /    /
           /    /
           \_  /
            / /
           / /
          / /
         / /
        ( /

)";
}

SinkEnemy::SinkEnemy(int max_health, int attack, int defence, int speed)
: Character((std::string) "SinkEnemy")
{
    this->attack = attack;
    this->max_health = max_health;
    this->current_health = max_health;
    this->defence = defence;
    this->speed = speed;

    this->sprite = R"(
          ____       ____  
        .'    '-._.-'    '.
      .' o      \ /      o '.
      (   o     O O    o    ) Oo
      Oo.o    o  _  o    o .oO
      OO'-.___.-' '-.___.-'OoO    
)";
    this->dead_sprite = R"(
          ____       ____  
        .'    '-._.-'    '.
      .' o      \ /      o '.
      (   o     X X    o    ) Oo
      Oo.o    o  _  o    o .oO
      OO'-.___.-' '-.___.-'OoO      
)";
}

SinkBoss::SinkBoss(int max_health, int attack, int defence, int speed)
: Character((std::string) "SinkBoss")
{
    this->attack = attack;
    this->max_health = max_health;
    this->current_health = max_health;
    this->defence = defence;
    this->speed = speed;

    this->sprite = R"(
                            /'"-,
          ..-'"'"'"-._     /    -`
        .' o          '-.-'  _,"'
         \,    -. .-        "-.,   
         /       "             -',     
         '-.___.,,,,____.-'\   -.
                            \,-'   
)";
    this->dead_sprite = R"(
                            /'"-,
          ..-'"'"'"-._     /    -`
        .' X          '-.-'  _,"'
         \,    -. .-        "-.,   
         /       "            -',     
         '-.___.,,,,____.-'\   -.
                            \,-'   
)";
}

OvenEnemy::OvenEnemy(int max_health, int attack, int defence, int speed)
: Character((std::string) "Food Ghost")
{
    this->attack = attack;
    this->max_health = max_health;
    this->current_health = max_health;
    this->defence = defence;
    this->speed = speed;

    this->sprite = R"(
      .-'""""`-.___                      
   .-'             """""""`-.
   '-.      O     O       .-` 
     "'-.      O          `-.
        '-...            ...-'              
             '-.      ..-'                
                "'-.  -`                  
                    `,`   
)";
    this->dead_sprite = R"(

      .-'""""`-.___                      
   .-'             """""""`-.
   '-.      X     X       .-` 
     "'-.      ___        `-.
        '-...    U       ...-'              
             '-.      ..-'                
                "'-.  -`                  
                    `,` 

)";
}

OvenBoss::OvenBoss(int max_health, int attack, int defence, int speed)
: Character((std::string) "Souffle")
{
    this->attack = attack;
    this->max_health = max_health;
    this->current_health = max_health;
    this->defence = defence;
    this->speed = speed;

    this->sprite = R"(                   
         ,.-""""""""""""-.,                           
        (('      ouo     `))        
        |'-.____________.-'|
        | | |  |  |  |  | ||                           
        | | |  |  |  |  | ||            
        '-'.'__'__'__'__'.''                         
        '-.______________.-'
)";
    this->dead_sprite = R"(
         ..____________..                           
       (('.-------------`))                            
       |'-._____x_x____.-'|
       | | |  |  |  |  | ||                           
       | | |  |  |  |  | ||            
       '-'.'__'__'__'__'.''                         
       '-.______________.-' 
)";

}

CounterEnemy::CounterEnemy(int max_health, int attack, int defence, int speed)
: Character((std::string) "CounterEnemy")
{
    this->attack = attack;
    this->max_health = max_health;
    this->current_health = max_health;
    this->defence = defence;
    this->speed = speed;

    this->sprite = R"(
       \\   |   //
        \\  |  //
         \\ | //      
       .-'     '-.
      .'---------'.
      '           '
      '.---\ /---.'
      '   o   o   '
      '-----------'
       '- _____ -'
       \ ------- /
        \ ----- /
         \ --- /
          \ - /
           \-/ 
            V  
)";
    this->dead_sprite = R"(
     
       \\   |   //
        \\  |  //
         \\ | //      
       .-'     '-.
      .'---------'.
      '           '
      '.---\ /---.'
      '   X   X   '
      '-----------'
       '- _____ -'
       \ -----U- /
        \ ----- /
         \ --- /
          \ - /
           \-/ 
            V  
)";

}

CounterBoss::CounterBoss(int max_health, int attack, int defence, int speed)
: Character((std::string) "Rotten Egg")
{
    this->attack = attack;
    this->max_health = max_health;
    this->current_health = max_health;
    this->defence = defence;
    this->speed = speed;

    this->sprite = R"(
                  ...
               .:"   ":.
            .:'         ':.
          .:'             ':.
         .:'    \     /    ':.
        .:'                 ':.
        ::      O     O      ::
        ::                   ::
        ::                   ::
        ::         _         ::
        ::                   ::
        ':.                 .:'
         ':.               .:'
          ':.             .:'
            ':..       ..:'
               ":.....:"
                  '''
)";
    this->dead_sprite = R"(
                  ...
               .:"   ":.
             \/\ /\ /\ /\/

          .:'V V V V V V V':.
         .:'    \     /    ':.
        .:'                 ':.
        ::      X     X      ::
        ::                   ::
        ::                   ::
        ::        ___        ::
        ::          U        ::
        ::                   ::
        ':.                 .:'
         ':.               .:'
          ':.             .:'
            ':..       ..:'
               ":.....:"
                  '''
)";
}

FinalBoss::FinalBoss(int max_health, int attack, int defence, int speed)
: Character((std::string) "FinalBoss")
{
    this->attack = attack;
    this->max_health = max_health;
    this->current_health = max_health;
    this->defence = defence;
    this->speed = speed;

    this->sprite = R"()";
    this->dead_sprite = R"(

)";
}