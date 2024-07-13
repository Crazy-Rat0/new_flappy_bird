#include "scoreboard.h"

scoreboard::scoreboard() : score(0), best(0) {}

int scoreboard::getScore() {
    return score;
}

void scoreboard::addScore() {
    score++;
}

void scoreboard::resetScore() {
    score = 0;
}

int scoreboard::getBest() {
    return best;
}

void scoreboard::setBest(int best_score) {
    best = best_score;
}
