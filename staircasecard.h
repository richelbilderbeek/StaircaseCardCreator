#ifndef STAIRCASECARD_H
#define STAIRCASECARD_H

#include <iosfwd>
#include <vector>
#include "staircasecardcolumn.h"





#include <boost/shared_ptr.hpp>


struct QImage;

namespace ribi {

struct TextCanvas;

namespace scc {

struct StaircaseCard
{
  StaircaseCard(const int n_cols, const int n_rows);
  StaircaseCard(const std::vector<Column>& v) noexcept : m_v{v} {}

  static boost::shared_ptr<StaircaseCard> GetTest(const int i);

  ///Give a measurement of aesthetics
  int RateAesthetics() const noexcept;

  ///Create a random card
  void Shuffle() noexcept;

  ///Create a random card with an aesthetic algorithm
  void ShuffleAesthetic() noexcept;

  boost::shared_ptr<QImage> ToImage() const noexcept;
  TextCanvas ToTextCanvas() const noexcept;
  TextCanvas ToTextCanvasCompact() const noexcept;

  private:
  std::vector<Column> m_v;

};

std::vector<int> ColumnToMap(const Column& c) noexcept;
std::vector<Column> CreateGrid(const int n_cols, const int n_rows);

std::ostream& operator<<(std::ostream& os, const StaircaseCard& c);

} //~namespace scc
} //~namespace ribi

#endif // STAIRCASECARD_H
