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