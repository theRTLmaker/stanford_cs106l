/*
 * CS106L Assignment 3: Make a Class
 * Created by Fabio Ibanez with modifications by Jacob Roberts-Baca.
 */

#include "class.h"

void sandbox() {
  Stock apple{"AAPL", "Apple"};
  const Stock s{"GOGL", "Google"};
  auto ts = s.getTickerSymbol();
  const auto& ts2 = s.getTickerSymbol();
  double avg = s.getAverageValue();

  const Stock a{"GOGL","Google"};
  (void)a.getTickerSymbol();
  (void)a.getAverageValue();
}