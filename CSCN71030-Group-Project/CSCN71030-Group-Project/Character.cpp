#include "Character.h"

Character::Character()
{
    this->attack = 0;
    this->current_health = 0;
    this->defence = 0;
    this->max_health = 0;
    this->speed = 0;
    this->name = " ";
}

Character::Character(std::string name)
{
    this->attack = 0;
    this->current_health = 0;
    this->defence = 0;
    this->max_health = 0;
    this->speed = 0;

    this->name = name;
    this->Character_PTR = this;
}

void Character::setHealth(int health_reduction)
{
    this->current_health = this->current_health - health_reduction;



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

spoon::spoon()
{
    this->Character_PTR = this;
    this->current_health = this->max_health;
    this->name = " ";
    this->sprite = R"(
                __
              .'  '.
              '°  °'
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
                 '  ° °'
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

spoon::spoon(std::string name)
{
    this->name = name;
    this->Character_PTR = this;
    this->current_health = this->max_health;
    this->sprite = R"(
                __
              .'  '.
              '°  °'
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
                 '  ° °'
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
}

fork::fork()
{
    this->Character_PTR = this;
    this->current_health = this->max_health;
    this->name = " ";
    this->sprite = R"(
                 ||||  
                 ||||
                 \°°/
                  ||
                  ||
                  ||
                  ||
                  --
)";
    this->fight_sprite = R"(
                   ////\ 
                  /V//
                 (°°/
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

fork::fork(std::string name)
{
    this->name = name;
    this->Character_PTR = this;
    this->current_health = this->max_health;
    this->sprite = R"(
                 ||||  
                 ||||
                 \°°/
                  ||
                  ||
                  ||
                  ||
                  --
)";
    this->fight_sprite = R"(
                   ////\ 
                  /V//
                 (°°/
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
}

knife::knife()
{
    this->Character_PTR = this;
    this->current_health = this->max_health;
    this->name = " ";
    this->sprite = R"(
                  .-'
                 /  |
                 |°°|
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
              /°°/
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

knife::knife(std::string name)
{
    this->name = name;
    this->Character_PTR = this;
    this->current_health = this->max_health;
    this->sprite = R"(
                  .-'
                 /  |
                 |°°|
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
              /°°/
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
}

DrawerEnemy::DrawerEnemy(int maxHealth, int Attack, int Defence, int Speed)
{
    this->attack = Attack;
    this->max_health = maxHealth;
    this->current_health = maxHealth;
    this->defence = Defence;
    this->speed = Speed;

    this->sprite = R"()";
}

DrawerBoss::DrawerBoss(int maxHealth, int Attack, int Defence, int Speed)
{
    this->attack = Attack;
    this->max_health = maxHealth;
    this->current_health = maxHealth;
    this->defence = Defence;
    this->speed = Speed;
    this->name = "Chef's Knife";

    this->sprite = R"(
                  _ .
               .'   '
              /\ / /
             /° ° /
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

SinkEnemy::SinkEnemy(int maxHealth, int Attack, int Defence, int Speed)
{
    this->attack = Attack;
    this->max_health = maxHealth;
    this->current_health = maxHealth;
    this->defence = Defence;
    this->speed = Speed;

    this->sprite = R"(
          ____       ____  
        .'    '-._.-'    '.
      .' o      \ /      o '.
      (   o     ° °    o    ) Oo
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

SinkBoss::SinkBoss(int maxHealth, int Attack, int Defence, int Speed)
{
    this->attack = Attack;
    this->max_health = maxHealth;
    this->current_health = maxHealth;
    this->defence = Defence;
    this->speed = Speed;

    this->sprite = R"(
                            /'"-,
          ..-'"'"'"-._     /    -`
        .' °          '-.-'  _,"'
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

OvenEnemy::OvenEnemy(int maxHealth, int Attack, int Defence, int Speed)
{
    this->attack = Attack;
    this->max_health = maxHealth;
    this->current_health = maxHealth;
    this->defence = Defence;
    this->speed = Speed;
    this->name = "Food Ghost";

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

OvenBoss::OvenBoss(int maxHealth, int Attack, int Defence, int Speed)
{
    this->attack = Attack;
    this->max_health = maxHealth;
    this->current_health = maxHealth;
    this->defence = Defence;
    this->speed = Speed;
    this->name = "Souffle";

    this->sprite = R"(                   
         ,.-""""""""""""-.,                           
        (('      °u°     `))        
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

CounterEnemy::CounterEnemy(int maxHealth, int Attack, int Defence, int Speed)
{
    this->attack = Attack;
    this->max_health = maxHealth;
    this->current_health = maxHealth;
    this->defence = Defence;
    this->speed = Speed;

    this->sprite = R"(
       \\   |   //
        \\  |  //
         \\ | //      
       .-'     '-.
      .'---------'.
      '           '
      '.---\ /---.'
      '   °   °   '
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

CounterBoss::CounterBoss(int maxHealth, int Attack, int Defence, int Speed)
{
    this->name = "Rotten Egg";
    this->attack = Attack;
    this->max_health = maxHealth;
    this->current_health = maxHealth;
    this->defence = Defence;
    this->speed = Speed;

    this->sprite = R"(
                  ...
               .:"   ":.
            .:'         ':.
          .:'             ':.
         .:'    \     /    ':.
        .:'                 ':.
        ::      °     °      ::
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

FinalBoss::FinalBoss(int maxHealth, int Attack, int Defence, int Speed)
{
    this->attack = Attack;
    this->max_health = maxHealth;
    this->current_health = maxHealth;
    this->defence = Defence;
    this->speed = Speed;

    this->sprite = R"()";
    this->dead_sprite = R"(

)";
}
