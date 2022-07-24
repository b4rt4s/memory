// #include "threeRevealsTwoRemove.hpp"

// void threeRevealsTwoRemove::securityParticular(int &x1, int &y1, int &x2, int
// &y2, bool &g, char &c)
// {
//     if (x1 == x2 && y1 == y2)
//     {
//         std::cout << "You chosed same time as your second guess, please chose
//         another tile to reveal!\n"; g = false;
//     }
//     else
//     {
//         securityBasic(x2, y2, g);

//         c = model.getSignAt(x2,y2);
//     }
// }

// void threeRevealsTwoRemove::basicInstructions(std::tuple<int, int> &Tile, int
// &x1, int &y1, int &x2, int &y2, bool &g,
//                                             char &c, boardRender
//                                             &boardRender, int &moves)
// {
//     do
//     {
//         setValues(Tile, x2, y2, g, c);
//         securityParticular(x1, y1, x2, y2, g, c);
//     }
//     while (!g);

//     doBasicMethods(x2, y2, c, moves, boardRender);
// }

// void threeRevealsTwoRemove::basicInstructions(std::tuple<int, int> &Tile, int
// &x1, int &y1, int &x2, int &y2, int &x3, int &y3, bool &g, char &c,
// boardRender &boardRender, int &moves)
// {

// }

// void threeRevealsTwoRemove::setOrReveal(int &x1, int &y1, int &x2, int &y2,
// int &x3, int &y3, char &c1, char &c2, char &c3)
// {
//     if((c1 == c2) || (c1 == c3) || (c2 == c3))
//     {
//         setNumberOrStar(x1, y1);
//         setNumberOrStar(x2, y2);
//         setNumberOrStar(x3, y3);
//     }
//     else
//     {
//         model.revealTile(x1, y1);
//         model.revealTile(x2, y2);
//         model.revealTile(x3, y3);
//         model.addScore(2);
//     }
// }

// void threeRevealsTwoRemove::play()
// {
//     system("clear");

//     std::tuple<int, int> Tile1, Tile2, Tile3;

//     int x1, x2, x3, y1, y2, y3, moves = 0;
//     char c1, c2, c3;
//     bool g1, g2, g3, won = false;

//     boardRender boardRender;

//     boardRender.height = model.getWidth();
//     boardRender.width = model.getHeight();

//     while (model.getUnrevealedTiles() > 0 && model.getPossibleMovesLeft() >
//     0)
//     {
//         boardRender.board = model.getPlayerBoard();
//         view.renderGame(boardRender, model.getScore(), moves,
//         model.getPossibleMovesLeft());

//         basicInstructions(Tile1, x1, y1, g1, c1, boardRender, moves);
//         basicInstructions(Tile2, x1, y1, x2, y2, g2, c2, boardRender, moves);
//         basicInstructions(Tile3, x1, y1, x2, y2, x3, y3, g3, c3, boardRender,
//         moves);

//         setOrReveal(x1, y1, x2, y2, x3, y3, c1, c2, c3);

//         winTrue(won);

//         ++moves;
//     }

//     winningMessage(won, moves);
// }