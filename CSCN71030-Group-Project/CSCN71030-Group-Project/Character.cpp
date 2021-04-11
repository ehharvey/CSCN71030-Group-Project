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
    return result;
}


void spoon::setHealth(int health)
{
    this->current_health = health;
}

int spoon::getHealth()
{
    return this->current_health;
}

int spoon::getAttack()
{
    return this->attack;
}

int spoon::getDefence()
{
    return this->defence;
}

int spoon::getSpeed()
{
    return this->speed;
}

std::string spoon::getSprite()
{
    return this->sprite;
}

std::string spoon::getFightSprite()
{
    return this->fight_sprite;
}

std::string spoon::getDeadSprite()
{
    return this->dead_sprite;
}

std::string spoon::getName()
{
    return this->name;
}

bool spoon::getPrepared()
{
    return this->isPrepared;
}

bool spoon::setPrepared(bool preperation)
{
    this->isPrepared = preperation;
    return this->isPrepared;
}
fork::fork() {
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
    return result;
}

void fork::setHealth(int health)
{
    this->current_health = health;
}

int fork::getHealth()
{
    return this->current_health;
}

int fork::getAttack()
{
    return this->attack;
}

int fork::getDefence()
{
    return this->defence;
}

int fork::getSpeed()
{
    return this->speed;
}

std::string fork::getSprite()
{
    return this->sprite;
}

std::string fork::getFightSprite()
{
    return this->fight_sprite;
}

std::string fork::getDeadSprite()
{
    return this->dead_sprite;
}

std::string fork::getName()
{
    return this->name;
}

bool fork::getPrepared()
{
    return this->isPrepared;
}

bool fork::setPrepared(bool preperation)
{
    this->isPrepared = preperation;
    return this->isPrepared;
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

knife::knife()
{
    this->name = " ";
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
    return result;
}

void knife::setHealth(int health) {
    this->current_health = health;
}
int knife::getHealth() {
    return this->current_health;
}
int knife::getAttack() {
    return this->attack;
}
int knife::getDefence() {
    return this->defence;
}
int knife::getSpeed() {
    return this->speed;
}
std::string knife::getSprite() {
    return this->sprite;
}
std::string knife::getFightSprite() {
    return this->fight_sprite;
}
std::string knife::getDeadSprite() {
    return this->dead_sprite;
}
std::string knife::getName() {
    return this->name;
}
bool knife::getPrepared() {
    return this->isPrepared;
}
bool knife::setPrepared(bool preperation) {
    this->isPrepared = preperation;
    return this->isPrepared;
}

DrawerEnemy::DrawerEnemy(int maxHealth, int Attack, int Defence, int Speed)
{
    this->attack = Attack;
    this->max_health = maxHealth;
    this->current_health = maxHealth;
    this->defence = Defence;
    this->speed = Speed;

    this->sprite = R"(
                     _
                  ./ /V'/.
                 (/ ° °/)
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
void DrawerEnemy::setHealth(int health) {
    this->current_health = health;
}
int DrawerEnemy::getHealth() {
    return this->current_health;
}
int DrawerEnemy::getAttack() {
    return this->attack;
}
int DrawerEnemy::getDefence() {
    return this->defence;
}
int DrawerEnemy::getSpeed() {
    return this->speed;
}
std::string DrawerEnemy::getSprite() {
    return this->sprite;
}
std::string DrawerEnemy::getDeadSprite() {
    return this->dead_sprite;
}
std::string DrawerEnemy::getName() {
    return this->name;
}
bool DrawerEnemy::getPrepared() {
    return this->isPrepared;
}
bool DrawerEnemy::setPrepared(bool preperation) {
    this->isPrepared = preperation;
    return this->isPrepared;
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
void DrawerBoss::setHealth(int health) {
    this->current_health = health;
}
int DrawerBoss::getHealth() {
    return this->current_health;
}
int DrawerBoss::getAttack() {
    return this->attack;
}
int DrawerBoss::getDefence() {
    return this->defence;
}
int DrawerBoss::getSpeed() {
    return this->speed;
}
std::string DrawerBoss::getSprite() {
    return this->sprite;
}
std::string DrawerBoss::getDeadSprite() {
    return this->dead_sprite;
}
std::string DrawerBoss::getName() {
    return this->name;
}
bool DrawerBoss::getPrepared() {
    return this->isPrepared;
}
bool DrawerBoss::setPrepared(bool preperation) {
    this->isPrepared = preperation;
    return this->isPrepared;
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
void SinkEnemy::setHealth(int health) {
    this->current_health = health;
}
int SinkEnemy::getHealth() {
    return this->current_health;
}
int SinkEnemy::getAttack() {
    return this->attack;
}
int SinkEnemy::getDefence() {
    return this->defence;
}
int SinkEnemy::getSpeed() {
    return this->speed;
}
std::string SinkEnemy::getSprite() {
    return this->sprite;
}
std::string SinkEnemy::getDeadSprite() {
    return this->dead_sprite;
}
std::string SinkEnemy::getName() {
    return this->name;
}
bool SinkEnemy::getPrepared() {
    return this->isPrepared;
}
bool SinkEnemy::setPrepared(bool preperation) {
    this->isPrepared = preperation;
    return this->isPrepared;
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
void SinkBoss::setHealth(int health) {
    this->current_health = health;
}
int SinkBoss::getHealth() {
    return this->current_health;
}
int SinkBoss::getAttack() {
    return this->attack;
}
int SinkBoss::getDefence() {
    return this->defence;
}
int SinkBoss::getSpeed() {
    return this->speed;
}
std::string SinkBoss::getSprite() {
    return this->sprite;
}
std::string SinkBoss::getDeadSprite() {
    return this->dead_sprite;
}
std::string SinkBoss::getName() {
    return this->name;
}
bool SinkBoss::getPrepared() {
    return this->isPrepared;
}
bool SinkBoss::setPrepared(bool preperation) {
    this->isPrepared = preperation;
    return this->isPrepared;
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
void OvenEnemy::setHealth(int health) {
    this->current_health = health;
}
int OvenEnemy::getHealth() {
    return this->current_health;
}
int OvenEnemy::getAttack() {
    return this->attack;
}
int OvenEnemy::getDefence() {
    return this->defence;
}
int OvenEnemy::getSpeed() {
    return this->speed;
}
std::string OvenEnemy::getSprite() {
    return this->sprite;
}
std::string OvenEnemy::getDeadSprite() {
    return this->dead_sprite;
}
std::string OvenEnemy::getName() {
    return this->name;
}
bool OvenEnemy::getPrepared() {
    return this->isPrepared;
}
bool OvenEnemy::setPrepared(bool preperation) {
    this->isPrepared = preperation;
    return this->isPrepared;
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
void OvenBoss::setHealth(int health) {
    this->current_health = health;
}
int OvenBoss::getHealth() {
    return this->current_health;
}
int OvenBoss::getAttack() {
    return this->attack;
}
int OvenBoss::getDefence() {
    return this->defence;
}
int OvenBoss::getSpeed() {
    return this->speed;
}
std::string OvenBoss::getSprite() {
    return this->sprite;
}
std::string OvenBoss::getDeadSprite() {
    return this->dead_sprite;
}
std::string OvenBoss::getName() {
    return this->name;
}
bool OvenBoss::getPrepared() {
    return this->isPrepared;
}
bool OvenBoss::setPrepared(bool preperation) {
    this->isPrepared = preperation;
    return this->isPrepared;
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
void CounterEnemy::setHealth(int health) {
    this->current_health = health;
}
int CounterEnemy::getHealth() {
    return this->current_health;
}
int CounterEnemy::getAttack() {
    return this->attack;
}
int CounterEnemy::getDefence() {
    return this->defence;
}
int CounterEnemy::getSpeed() {
    return this->speed;
}
std::string CounterEnemy::getSprite() {
    return this->sprite;
}
std::string CounterEnemy::getDeadSprite() {
    return this->dead_sprite;
}
std::string CounterEnemy::getName() {
    return this->name;
}
bool CounterEnemy::getPrepared() {
    return this->isPrepared;
}
bool CounterEnemy::setPrepared(bool preperation) {
    this->isPrepared = preperation;
    return this->isPrepared;
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
void CounterBoss::setHealth(int health) {
    this->current_health = health;
}
int CounterBoss::getHealth() {
    return this->current_health;
}
int CounterBoss::getAttack() {
    return this->attack;
}
int CounterBoss::getDefence() {
    return this->defence;
}
int CounterBoss::getSpeed() {
    return this->speed;
}
std::string CounterBoss::getSprite() {
    return this->sprite;
}
std::string CounterBoss::getDeadSprite() {
    return this->dead_sprite;
}
std::string CounterBoss::getName() {
    return this->name;
}
bool CounterBoss::getPrepared() {
    return this->isPrepared;
}
bool CounterBoss::setPrepared(bool preperation) {
    this->isPrepared = preperation;
    return this->isPrepared;
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
void FinalBoss::setHealth(int health) {
    this->current_health = health;
}
int FinalBoss::getHealth() {
    return this->current_health;
}
int FinalBoss::getAttack() {
    return this->attack;
}
int FinalBoss::getDefence() {
    return this->defence;
}
int FinalBoss::getSpeed() {
    return this->speed;
}
std::string FinalBoss::getSprite() {
    return this->sprite;
}
std::string FinalBoss::getDeadSprite() {
    return this->dead_sprite;
}
std::string FinalBoss::getName() {
    return this->name;
}
bool FinalBoss::getPrepared() {
    return this->isPrepared;
}
bool FinalBoss::setPrepared(bool preperation) {
    this->isPrepared = preperation;
    return this->isPrepared;
}