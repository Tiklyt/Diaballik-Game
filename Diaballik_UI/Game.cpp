#include "Game.h"
#include "Directions.h"

static Directions d;


//==========================================================================CONSTRUCTOR

/**
 * @brief Allow to construct the game
 * @param side the side of the plate of the game
 * @param name1 the first name of the player for playing the game
 * @param name2 the second name of the player for playing the game
 */
Game::Game(unsigned side,std::string name1,std::string name2):_board(side)
{
    _antiGame = false;
    _players = std::make_pair(Player(name1,Color::BROWN),Player(name2,Color::BLACK));\
    initializer();
}

//==========================================================================INITIALIZER

/**
 * @brief Allow to initialize the game
 */
void Game::initializer()
{
    for(int i = 0; i < static_cast<int>(_board.getSize());i++)
    {
        _board.putPawn(Pawn(Color::BROWN),Position(0,i));
    }
    for(int i = 0; i < static_cast<int>(_board.getSize());i++)
    {
        _board.putPawn(Pawn(Color::BLACK),Position(static_cast<int>(_board.getSize()-1),i));
    }
    _board.setBall(Position(0,getBoard().getSize()/2));
    _board.setBall(Position(static_cast<int>(getBoard().getSize()-1),getBoard().getSize()/2));
}

void Game::resetTable(){
    for(int i = 0;i <static_cast<int>(_board.getSize());i++){
        for(int j = 0;j < static_cast<int>(_board.getSize());j++){
            Pawn copy(NUL);
            _board.getCell(Position(i,j)).copy(copy);
        }
    }
}

//==========================================================================GETTER

/**
 * @brief get the board from the game
 * @return the board
 */
Board &  Game::getBoard()
{
    return _board;
}

void Game::resize(unsigned size){
    _board.resize(size);
}

//==========================================================================GETTER

/**
 * @brief get the current Player from
 * the game
 * @return the current player
 */
Player & Game::getCurrentPlayer()
{
    return _players.first;
}

//==========================================================================GETTER
/**
 * @brief Allow to get Move(s)
 * for a selected Position
 * @return a container of Move(s)
 */
std::vector<Move> Game::getMoves()
{
    std::vector<Move> moves;
    if(_board.getCell(_selectedPawn).getPawn().isMovable())
    {
        if(getCurrentPlayer().getMovementDone() == 2){
            return moves;
        }

        Position start = Position(_selectedPawn);
        for(unsigned i = 0;i < d.getDirections().size();i++)
        {
            Direction di = d.getDirections().at(i);
            Position end = Position(start.getRow()+di.getRow(),start.getCol()+di.getColumn());
            if(_board.isInside(end) && _board.isFree(end)){
                moves.push_back(Move(start,end));
            }
        }
    } else {
        if(getCurrentPlayer().getBallMovementDone() == 1){
            return moves;
        }

        for(unsigned i = 0;i<d.getDiagonals().size();i++)
        {
            Direction di = d.getDiagonals().at(i);
            Position start = Position(_selectedPawn);
            Position end = Position(start.getRow()+di.getRow(),start.getCol()+di.getColumn());
            std::cout << end << std::endl;
            while(_board.isInside(end))
            {
                if(_board.isInside(end) && !_board.isFree(end) && !_board.isMyOwn(end,_players.first.getColor()))
                {
                    return moves;
                } else if(_board.isInside(end) && !_board.isFree(end) && _board.isMyOwn(end,_players.first.getColor()))
                {
                    moves.push_back(Move(_selectedPawn,end));
                    return moves;
                }
                end = Position(end.getRow()+di.getRow(),end.getCol()+di.getColumn());
            }
        }

        for(unsigned i = 0;i<d.getDirections().size();i++)
        {
            Direction di = d.getDirections().at(i);
            Position start = Position(_selectedPawn);
            Position end = Position(start.getRow()+di.getRow(),start.getCol()+di.getColumn());
            std::cout << end << std::endl;
            while(_board.isInside(end))
            {
                if(_board.isInside(end) && !_board.isFree(end) && !_board.isMyOwn(end,_players.first.getColor()))
                {
                    return moves;
                } else if(_board.isInside(end) && !_board.isFree(end) && _board.isMyOwn(end,_players.first.getColor()))
                {
                    moves.push_back(Move(_selectedPawn,end));
                    return moves;
                }
                end = Position(end.getRow()+di.getRow(),end.getCol()+di.getColumn());
            }
        }
    }
    return moves;
}

//==========================================================================EXECUTER

/**
 * @brief Allow to select a Pawn
 * @param pos the Position of the selected Pawn
 * @return true if the command succeed
 */
bool Game::select(Position pos)
{

    if(!_board.isInside(pos)){
        throw std::invalid_argument("Invalid Position");
    }
    if(_board.isInside(pos) && _board.isMyOwn(pos,_players.first.getColor()) && !_board.isFree(pos)){
        _selectedPawn = Position(pos);
        return true;
    }
    return false;
}

//==========================================================================CHECKER

/**
 * @brief Check if the game is not Over
 * @return true or false
 */
bool Game::isNotOver()
{
    return  !_antiGame && !_players.first.haveGiveUp()
            && !_players.second.haveGiveUp();
}

//==========================================================================CHECKER

/**
 * @brief Check if the current player
 * have move(s)
 * @return  true or false
 */
bool Game::haveMoves()
{
    return getMoves().empty();
}

//==========================================================================CHECKER

/**
 * @brief Allow to the current player to ask
 * a antigame
 * @return true or false if succeed
 */
bool Game::askAntiGame()
{
    std::vector<Position> wall;
    std::vector<unsigned> posCol;
    Color enemyColor = _players.second.getColor();
    std::size_t size = _board.getSize();
    bool isWall = true;
    for(unsigned i =0;i<size;i++){
        for(unsigned j = 0;j<size;j++)
        {
            if(_board.getBoard()[j][i].getPawn().getColor() == enemyColor)
            {
                wall.push_back(Position(static_cast<int>(j),static_cast<int>(i)));
                posCol.push_back(j);
            }
        }
    }
        for(unsigned i = 0;i<size-1 && isWall ;i++)
        {
            isWall = (posCol[i] == (posCol[i+1] + 1 ))
                    || (posCol[i] == (posCol[i+1] - 1 ))
                    || (posCol[i] == (posCol[i+1]));
        }

    if(!isWall)
        return false;
    int counter = 0;
    Direction UP(-1, 0);
    Direction DOWN(1, 0);
    for(unsigned i = 0; i < wall.size();i++)
    {
        Position pos1(wall.at(i).getRow()+UP.getRow(),wall.at(i).getCol()+UP.getColumn());
        Position pos2(wall.at(i).getRow()+DOWN.getRow(),wall.at(i).getCol()+DOWN.getColumn());
        if(_board.isInside(pos1) && _board.isMyOwn(pos1,_players.first.getColor()))
        {
            counter++;
        }
        if(_board.isInside(pos2) && _board.isMyOwn(pos2,_players.first.getColor()))
        {
            counter++;
        }
    }
    if(counter >= 3)
    {
        _antiGame = true;
        return true;
    }
    _antiGame = false;
    return false;
}

//==========================================================================CHECKER/EXECUTER

/**
 * @brief skip the turn of the current player
 * @return true if the command succeed
 */
bool Game::askSkipTurn()
{
    if(canSkipTurn())
    {
        swapPlayers();
        return true;
    }
    return false;
}

//==========================================================================CHECKER

/**
 * @brief Check if the current player
 * can skip the turn
 * @return true or false
 */
bool Game::canSkipTurn()
{
    return _players.first.haveDoneMinDisp();
}

//==========================================================================EXECUTER

/**
 * @brief Allow to execute
 * a movement from the move received
 * in parameter
 * @param move the move that will be executed
 */
void  Game::mov(Move & move){
    Position start = move.getStart();
    Position end = move.getEnd();
    Pawn saver = _board.getCell(start).getPawn();
    if(saver.containBall())
    {
        _board.getCell(start).resetBall();
        _board.getCell(end).setBall();
        _players.first.incBallMovement();
    } else
    {
        _board.getCell(end).copy(saver);
        _board.getCell(start).setEmpty();
        _players.first.incMovement();
    }
}

//==========================================================================CHECKER

/**
 * @brief Check if there a Winner
 * @return true or false
 */
bool Game::thereIsWinner(){
    unsigned indice = getBoard().getSize()-1;
    Color currentColor = getCurrentPlayer().getColor();
    if(currentColor == Color::BLACK){
        indice = 0;
    }
    for(unsigned i = 0; i < getBoard().getBoard().size();i++){
        if(getBoard().getBoard()[indice][i].getPawn().containBall()
                && getBoard().getBoard()[indice][i].getPawn().getColor() == currentColor){
            return true;
        }
    }
    return false;
}

//==========================================================================EXECUTER

/**
 * @brief Allow to swap 2 players
 */
void Game::swapPlayers()
{
    _players.first.resetAllMovement();
    _players = std::make_pair(_players.second,_players.first);
}

//==========================================================================
