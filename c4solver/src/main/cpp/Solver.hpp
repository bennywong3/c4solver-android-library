/*
 * Reference from Connect4 Game Solver <http://connect4.gamesolver.org>
 * Modified to suit our project.
 */

#ifndef SOLVER_HPP
#define SOLVER_HPP

#include <vector>
#include <string>
#include "Position.hpp"
#include "TranspositionTable.hpp"
#include "OpeningBook.hpp"
#include <android/log.h>

namespace GameSolver {
namespace Connect4 {

class Solver {
 private:
  static constexpr int TABLE_SIZE = 23; // store 2^TABLE_SIZE elements in the transpositiontbale
  TranspositionTable < uint_t < Position::WIDTH*(Position::HEIGHT + 1) - TABLE_SIZE >, uint8_t, TABLE_SIZE > transTable;

  OpeningBook book{Position::WIDTH, Position::HEIGHT}; // opening book
  unsigned long long nodeCount; // counter of explored nodes.

  int columnOrder[Position::WIDTH]; // column exploration order

  /**
   * Reccursively score connect 4 position using negamax variant of alpha-beta algorithm.
   * @param: position to evaluate, this function assumes nobody already won and
   *         current player cannot win next move. This has to be checked before
   * @param: alpha < beta, a score window within which we are evaluating the position.
   *
   * @return the exact score, an upper or lower bound score depending of the case:
   * - if actual score of position <= alpha then actual score <= return value <= alpha
   * - if actual score of position >= beta then beta <= return value <= actual score
   * - if alpha <= actual score <= beta then return value = actual score
   */
  int negamax(const Position &P, int alpha, int beta);

 public:
  static const int INVALID_MOVE = -1000;

  // Returns the score of a position
  int solve(const Position &P, bool weak = false);

  // Returns the score off all possible moves of a position as an array.
  // Returns INVALID_MOVE for unplayable columns
  std::vector<int> analyze(const Position &P, bool weak = false);

  unsigned long long getNodeCount() const {
    return nodeCount;
  }

  void reset() {
    nodeCount = 0;
    transTable.reset();
  }

  void loadBook(std::string book_file) {
    __android_log_print(ANDROID_LOG_VERBOSE, "solver.hpp", "loadbook");
    book.load(book_file);
  }

  Solver(); // Constructor
};

} // namespace Connect4
} // namespace GameSolver
#endif
