
#ifndef BOOSTPYTHONMODULE
#define BOOSTPYTHONMODULE

#include <boost/python.hpp>
#include "MyException.hpp"
#include "Board.hpp"

/*! \brief funkcja sluzaca do komunikacji z interfejsem modulu pythona
 */
int addPlayer(std::string name)
{
  try
    {
      return Board::getInstance().addPlayer(name)+1;
    }
  catch(GameNotStartedException& e)
    {
      return -1;
    }
  catch(GameInProgressException& e)
    {
      return -1;
    }
  catch(MaxPlayersException& e)
    {
      return -2;
    }
    
}
/*! \brief funkcja sluzaca do komunikacji z interfejsem modulu pythona
 */
int choose(int player, int x, int y)
{
  try
    {
      return Board::getInstance().choose(player-1, x, y);
    }
  catch(UknownPlayerException& e)
    {
      return -400;
    }
  catch(NoPlayerException& e)
    {
      return -300;
    }
  catch(NotCurrentPlayerException& e)
    {
      return -200;
    }
  catch(TileOutOfBoardException& e)
    {
      return -100;
    }
  catch(TwoTilesChosenException& e)
    {
      return -1;
    }
    
}
/*! \brief funkcja sluzaca do komunikacji z interfejsem modulu pythona
 */
int initGame(int x, int y)
{
  try
    {
      return Board::getInstance().initGame(x, y);
    }
  catch(GameInProgressException& e)
    {
      return -1;
    }
  catch(WrongParametersException&)
    {
      return -2;
    }
    
}
/*! \brief funkcja sluzaca do komunikacji z interfejsem modulu pythona
 */
void endGame()
{
  Board::getInstance().endGame();
}
/*! \brief funkcja sluzaca do komunikacji z interfejsem modulu pythona
 */
int getCurrentPlayer()
{
  return Board::getInstance().getCurrentPlayer()+1;
}
/*! \brief funkcja sluzaca do komunikacji z interfejsem modulu pythona
 */
int getState()
{
  return Board::getInstance().getState();
}
/*! \brief funkcja sluzaca do komunikacji z interfejsem modulu pythona
 */
int getFirstPicked()
{
  return Board::getInstance().getFirstPicked();
}
/*! \brief funkcja sluzaca do komunikacji z interfejsem modulu pythona
 */
int getFirstX()
{
  return Board::getInstance().getFirstX();
}
/*! \brief funkcja sluzaca do komunikacji z interfejsem modulu pythona
 */
int getFirstY()
{
  return Board::getInstance().getFirstY();
}
/*! \brief funkcja sluzaca do komunikacji z interfejsem modulu pythona
 */
int getSecondPicked()
{
  return Board::getInstance().getSecondPicked();
}
/*! \brief funkcja sluzaca do komunikacji z interfejsem modulu pythona
 */
int getSecondX()
{
  return Board::getInstance().getSecondX();
}
/*! \brief funkcja sluzaca do komunikacji z interfejsem modulu pythona
 */
int getSecondY()
{
  return Board::getInstance().getSecondY();
}
/*! \brief funkcja sluzaca do komunikacji z interfejsem modulu pythona
 */
int getScore(int player)
{
  try
    {
      return Board::getInstance().getScore(player-1);
    }
  catch(UknownPlayerException& e)
    {
      return -1;
    }
  catch(NoPlayerException& e)
    {
      return -2;
    }
}
/*! \brief funkcja sluzaca do komunikacji z interfejsem modulu pythona
 */
int endTurn()
{
  return Board::getInstance().endTurn()+1;
}
/*! \brief funkcja sluzaca do komunikacji z interfejsem modulu pythona
 */
int getSizeX()
{
  return Board::getInstance().getSizeX();
}
/*! \brief funkcja sluzaca do komunikacji z interfejsem modulu pythona
 */
int getSizeY()
{
  return Board::getInstance().getSizeY();
}
/*! \brief funkcja sluzaca do komunikacji z interfejsem modulu pythona
 */
std::string getName(int player)
{
  try
    {
      return Board::getInstance().getName(player-1);
    }
  catch(UknownPlayerException& e)
    {
      return "uknown player";
    }
  catch(NoPlayerException& e)
    {
      return "no player";
    }
}
/*! \brief funkcja sluzaca do komunikacji z interfejsem modulu pythona
 */
int getWinner(int player)
{
  try
    {
      return Board::getInstance().getWinner(player-1);
    }
  catch(UknownPlayerException& e)
    {
      return -1;
    }
  catch(NoPlayerException& e)
    {
      return 0;
    }
}
/*! \brief modul pythona sluzacy do komunikacji z serwerem
 */
int playerDead(int player)
{
  try
    {
      Board::getInstance().playerDead(player-1);
      return 1;
    }
  catch(NoPlayerException& e)
    {
      return -1;
    }
  catch(UknownPlayerException& e)
    {
      return -2;
    }
}

BOOST_PYTHON_MODULE(model)
{
  boost::python::def("addPlayer", addPlayer);
  boost::python::def("choose", choose);
  boost::python::def("initGame", initGame);
  boost::python::def("endGame", endGame);
  boost::python::def("getCurrentPlayer", getCurrentPlayer);
  boost::python::def("getState", getState);
  boost::python::def("getFirstPicked", getFirstPicked);
  boost::python::def("getFirstX", getFirstX);
  boost::python::def("getFirstY", getFirstY);
  boost::python::def("getSecondPicked", getSecondPicked);
  boost::python::def("getSecondX", getSecondX);
  boost::python::def("getSecondY", getSecondY);
  boost::python::def("endTurn", endTurn);
  boost::python::def("getScore", getScore);
  boost::python::def("getSizeX", getSizeX);
  boost::python::def("getSizeY", getSizeY);
  boost::python::def("getName", getName);
  boost::python::def("getWinner", getWinner);
  boost::python::def("playerDead", playerDead);
  }

#endif
