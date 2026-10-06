#include "libs/marketdata/feed_parser.h"

#include "gtest/gtest.h"

namespace marketdata {
namespace {

TEST(FeedParser, ParsesAdd) {
  auto msg = ParseLine("A,42,ESZ6,B,5012.25,10");
  ASSERT_TRUE(msg.ok());
  const auto& add = std::get<AddMsg>(*msg);
  EXPECT_EQ(add.order.id, 42u);
  EXPECT_EQ(add.order.symbol, "ESZ6");
  EXPECT_EQ(add.order.side, Side::kBuy);
  EXPECT_EQ(add.order.price.ticks, 50122500);
  EXPECT_EQ(add.order.qty, 10);
}

TEST(FeedParser, ParsesCancel) {
  auto msg = ParseLine("X,42");
  ASSERT_TRUE(msg.ok());
  EXPECT_EQ(std::get<CancelMsg>(*msg).id, 42u);
}

TEST(FeedParser, RejectsGarbage) {
  EXPECT_FALSE(ParseLine("A,1,ESZ6,Q,1.0,1").ok());
  EXPECT_FALSE(ParseLine("Z,1").ok());
  EXPECT_FALSE(ParseLine("A,x,ESZ6,B,1.0,1").ok());
}

}
}
