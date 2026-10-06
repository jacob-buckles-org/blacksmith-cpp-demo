#include "libs/orderbook/order_book.h"

#include "gtest/gtest.h"

namespace orderbook {
namespace {

Order Make(uint64_t id, Side side, double px, int64_t qty) {
  Order o;
  o.id = id;
  o.symbol = "ESZ6";
  o.side = side;
  o.price = Price::FromDouble(px);
  o.qty = qty;
  return o;
}

TEST(OrderBook, RestsWhenNotCrossing) {
  OrderBook book("ESZ6");
  EXPECT_TRUE(book.Add(Make(1, Side::kBuy, 100.0, 5)).empty());
  EXPECT_TRUE(book.Add(Make(2, Side::kSell, 101.0, 5)).empty());
  EXPECT_EQ(book.BestBid()->ToDouble(), 100.0);
  EXPECT_EQ(book.BestAsk()->ToDouble(), 101.0);
  EXPECT_EQ(book.OrderCount(), 2u);
}

TEST(OrderBook, MatchesAtMakerPrice) {
  OrderBook book("ESZ6");
  book.Add(Make(1, Side::kSell, 100.0, 5));
  auto trades = book.Add(Make(2, Side::kBuy, 101.0, 3));
  ASSERT_EQ(trades.size(), 1u);
  EXPECT_EQ(trades[0].price.ToDouble(), 100.0);
  EXPECT_EQ(trades[0].qty, 3);
  EXPECT_EQ(book.DepthAt(Side::kSell, Price::FromDouble(100.0)), 2);
}

TEST(OrderBook, PriceTimePriority) {
  OrderBook book("ESZ6");
  book.Add(Make(1, Side::kSell, 100.0, 2));
  book.Add(Make(2, Side::kSell, 100.0, 2));
  book.Add(Make(3, Side::kSell, 99.0, 2));
  auto trades = book.Add(Make(4, Side::kBuy, 100.0, 5));
  ASSERT_EQ(trades.size(), 3u);
  EXPECT_EQ(trades[0].sell_id, 3u);
  EXPECT_EQ(trades[1].sell_id, 1u);
  EXPECT_EQ(trades[2].sell_id, 2u);
  EXPECT_EQ(trades[2].qty, 1);
}

TEST(OrderBook, Cancel) {
  OrderBook book("ESZ6");
  book.Add(Make(1, Side::kBuy, 100.0, 5));
  EXPECT_TRUE(book.Cancel(1));
  EXPECT_FALSE(book.Cancel(1));
  EXPECT_FALSE(book.BestBid().has_value());
}

}
}
