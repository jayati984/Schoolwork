#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
using namespace std;

class World;
class Organism;
class Doodlebug;
class Ant;

//valid moves for each organism
const int LEFT = 1;
const int RIGHT = 2;
const int DOWN = 3;
const int UP = 4;

const int WORLD_DIMENSION = 20;

//the number of each critter we initialize the world with
const int INIT_DOODLEBUG_COUNT = 5;
const int INIT_ANT_COUNT = 100;

//the time steps it takes for each critter to breed
const int DOODLEBUG_BREED_TIME = 8;
const int ANT_BREED_TIME = 3;

//the time steps it takes for a doodlebug to starve
const int DOODLEBUG_STARVE_TIME = 3;

//number to indicate the type of each critter
const int DOODLEBUG = 1;
const int ANT = 2;

typedef Organism* OrganismPtr;
typedef World* WorldPtr;

class World 
{

  friend class Organism;
  friend class Ant;
  friend class Doodlebug;

    public:
        World();
        void startWorld();
        void takeTimeStep();
        void printWorld() const;
    private:
        OrganismPtr world[WORLD_DIMENSION][WORLD_DIMENSION];
        int timeStepCount;
        int generateRandomNumber(int startRange, int endRange) const;
};

class Organism {
    
    public:
        Organism(): w(NULL), x(0), y(0), timeTillBreed(0), timeStepCount(0){}
        Organism(WorldPtr w, int x, int y);
        virtual void breed() = 0;
        virtual void move();
        virtual int getType() = 0;
        virtual bool starves() { return false; }
        
    protected:
        WorldPtr w;
        int x;
        int y;
        int timeTillBreed;
        int timeStepCount;
        //given a coordinate of the cell (x,y), 
        //returns a list of valid moves to adjacent empty cells
        vector<int> getMovesToEmptyCells(int x, int y) const;
        bool isValidCoordinate(int x, int y) const;
        //given a valid move from grid[x][y],
        //updates x and y according to the move
        void getCoordinate(int& x, int& y, int move) const;
};

class Doodlebug: public Organism {

    private:
        int timeTillStarve;
        //given a coordinate of the cell (x,y),
        //returns a list of valid moves to adjacent ants
        vector<int> getMovesToAnts(int x, int y) const;

    public:
        Doodlebug(): Organism(), timeTillStarve(0){}
        Doodlebug(WorldPtr w, int x, int y);
        void breed();
        void move();
        int getType(){ return DOODLEBUG; }
        bool starves(){ return timeTillStarve == 0; }
};

class Ant: public Organism {

    public:
        Ant(): Organism(){}
        Ant(WorldPtr w, int x, int y);
        void breed();
        int getType(){ return ANT; }
};

int World::generateRandomNumber(int startRange, int endRange) const
{
  return (rand() % (endRange - startRange + 1) + startRange);
}

World::World(){
  srand(time(NULL));
  timeStepCount = 0;
  for (int x = 0; x < WORLD_DIMENSION; x++)
  {
    for (int y = 0; y < WORLD_DIMENSION; y++)
    {
      world[x][y] = NULL;
    }
  }
}

void World::startWorld(){
  int x;
  int y;
  int doodlebugCount = 0;
  int antCount = 0;

  while (doodlebugCount < INIT_DOODLEBUG_COUNT)
  {
    x = generateRandomNumber(0, WORLD_DIMENSION - 1);
    y = generateRandomNumber(0, WORLD_DIMENSION - 1);
    if (world[x][y] != NULL) 
    {
        continue;
    }
    world[x][y] = new Doodlebug(this, x, y);
    doodlebugCount++;
  }

  while (antCount < INIT_ANT_COUNT)
  {
    x = generateRandomNumber(0, WORLD_DIMENSION - 1);
    y = generateRandomNumber(0, WORLD_DIMENSION - 1);
    if (world[x][y] != NULL) 
    {
        continue;
    }
    world[x][y] = new Ant(this, x, y);
    antCount++;
  }
}

void World::takeTimeStep(){
  timeStepCount++;

  for (int x = 0; x < WORLD_DIMENSION; x++)
  {
    for (int y = 0; y < WORLD_DIMENSION; y++)
    {
      if (world[x][y] == NULL) 
      {
          continue;
      }
      if (world[x][y]->getType() == DOODLEBUG)
      {
        world[x][y]->move();
      }
    }
  }

  for (int x = 0; x < WORLD_DIMENSION; x++)
  {
    for (int y = 0; y < WORLD_DIMENSION; y++)
    {
      if (world[x][y] == NULL)
      {
          continue;
      }
      if (world[x][y]->getType() == ANT)
      {
        world[x][y]->move();
      }
    }
  }

  for (int x = 0; x < WORLD_DIMENSION; x++)
  {
    for (int y = 0; y < WORLD_DIMENSION; y++)
    {
      if (world[x][y] == NULL)
      {
          continue;
      }
      world[x][y]->breed();
    }
  }

  for (int x = 0; x < WORLD_DIMENSION; x++)
  {
    for (int y = 0; y < WORLD_DIMENSION; y++)
    {
      if (world[x][y] == NULL) 
      {
          continue;
      }
      if (world[x][y]->starves())
      {
        delete world[x][y];
        world[x][y] = NULL;
      }
    }
  }
}

void World::printWorld() const {
  for (int x = 0; x < WORLD_DIMENSION; x++)
  {
    for (int y = 0; y < WORLD_DIMENSION; y++)
    {
      if (world[x][y] == NULL)
      {
        cout << " - ";
      }
      else if (world[x][y]->getType() == ANT)
      {
        cout << " O ";
      }
      else 
      {//world[x][y]->getType() == DOODLEBUG
        cout << " X ";
      }
    }
    cout << endl;
  }
}

vector<int> Organism::getMovesToEmptyCells(int x, int y) const {
  vector<int> movesToEmptyCells;
  int tempX, tempY;
  for (int move = LEFT; move <= UP; move++){
    tempX = x;
    tempY = y;
    getCoordinate(tempX, tempY, move);
    if (!isValidCoordinate(tempX, tempY))
    {
        continue;
    }
    if (w->world[tempX][tempY] == NULL)
    {
      movesToEmptyCells.push_back(move);
    }
  }
  return movesToEmptyCells;
}

bool Organism::isValidCoordinate(int x, int y) const {
  if (x < 0 || x >= WORLD_DIMENSION || y < 0 || y >= WORLD_DIMENSION)
  {
    return false;
  }
  else
  {
    return true;
  }
}

void Organism::getCoordinate(int& x, int& y, int move) const {
  if (move == LEFT)
  {
      x--;
  }
  if (move == RIGHT)
  {
      x++;
  }
  if (move == DOWN)
  {
      y--;
  }
  if (move == UP) 
  {
      y++;
  }
}

Organism::Organism(WorldPtr w, int x, int y){
  this->w = w;
  this->x = x;
  this->y = y;
  timeTillBreed = 0;
  timeStepCount = w->timeStepCount;
}

void Organism::move(){
  if (timeStepCount == w->timeStepCount)
  {
      return;
  }
  timeStepCount++;
  timeTillBreed--;
  int randomMove = w->generateRandomNumber(LEFT, UP);
  int newX = x;
  int newY = y;
  getCoordinate(newX, newY, randomMove);
  if (isValidCoordinate(newX, newY))
  {
    if (w->world[newX][newY] != NULL) 
    {
        return;
    }
    w->world[x][y] = NULL;
    w->world[newX][newY] = this;
    x = newX;
    y = newY;
  }
}

vector<int> Doodlebug::getMovesToAnts(int x, int y) const {
  vector<int> movesToAnts;
  int tempX, tempY;
  for (int move = LEFT; move <= UP; move++){
    tempX = x;
    tempY = y;
    getCoordinate(tempX, tempY, move);
    if (!isValidCoordinate(tempX, tempY))
    {
        continue;
    }
    if (w->world[tempX][tempY] == NULL) 
    {
        continue;
    }
    if (w->world[tempX][tempY]->getType() == ANT) 
    {
      movesToAnts.push_back(move);
    }
  }
  return movesToAnts;
}

Doodlebug::Doodlebug(WorldPtr w, int x, int y): Organism(w, x, y)
{
  timeTillStarve = DOODLEBUG_STARVE_TIME;
  timeTillBreed = DOODLEBUG_BREED_TIME;
}

void Doodlebug::breed(){
  if (timeTillBreed > 0) 
  {
      return;
  }
  vector<int> validMoves = getMovesToEmptyCells(x, y);
  if (validMoves.size() == 0)
  {
      return;
  }
  int randomMove = validMoves[w->generateRandomNumber(0, validMoves.size() - 1)];
  int newX = x;
  int newY = y;
  getCoordinate(newX, newY, randomMove);
  w->world[newX][newY] = new Doodlebug(w, newX, newY);
  timeTillBreed = DOODLEBUG_BREED_TIME;
}

void Doodlebug::move(){
  if (timeStepCount == w->timeStepCount) 
  {
      return;
  }
  vector<int> movesToAnts = getMovesToAnts(x, y);
  if (movesToAnts.size() == 0)
  {
    Organism::move();
    timeTillStarve--;
    return;
  }
  timeStepCount++;
  timeTillStarve = DOODLEBUG_STARVE_TIME;
  int randomMove = movesToAnts[w->generateRandomNumber(0, movesToAnts.size() - 1)];
  int antX = x;
  int antY = y;
  getCoordinate(antX, antY, randomMove);
  delete w->world[antX][antY];
  w->world[antX][antY] = this;
  w->world[x][y] = NULL;
  x = antX;
  y = antY;
}

Ant::Ant(WorldPtr w, int x, int y): Organism(w, x, y){
  timeTillBreed = ANT_BREED_TIME;
}

void Ant::breed(){
  if (timeTillBreed > 0) 
  { 
      return;
  }
  vector<int> validMoves = getMovesToEmptyCells(x, y);
  if (validMoves.size() == 0) 
  {
      return;
  }
  int randomMove = validMoves[w->generateRandomNumber(0, validMoves.size() - 1)];
  int newX = x;
  int newY = y;
  getCoordinate(newX, newY, randomMove);
  w->world[newX][newY] = new Ant(w, newX, newY);
  timeTillBreed = ANT_BREED_TIME;
}

int main(){
  char answer;
  World aWorld;

  cout << "WELCOME TO DOODLEBUG VS. ANTS GAME!" << endl;
  cout << "Press enter to start the game." << endl;
  cin.get(answer);
    
  if (answer != '\n')
  {
    cout << "End." << endl;
    exit(1);
  }

  aWorld.startWorld();
  aWorld.printWorld();
  cout << endl;

  cout << "Keep pressing enter to continue playing, any other letter to exit." << endl;
  cin.get(answer);

  while(answer == '\n'){
    aWorld.takeTimeStep();
    aWorld.printWorld();
    cout << endl;
    cout << "Keep pressing enter to continue playing, any other letter to exit." << endl;
    cin.get(answer);
  }

  cout << "END OF GAME!" << endl;
    
  return 0;
}