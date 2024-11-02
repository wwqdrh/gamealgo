
#include <gtest/gtest.h>

#include "parser/typewriter.h"

using namespace gamealgo;

TEST(TestParser, typewriter) {
  TextParser parser;
  std::string input =
      "[color=#ff0000]h[/color][shake]e[/shake][size=20]llo[/size]";
  auto tokens = parser.parse_text(input);

  ASSERT_EQ(tokens.size(), 5);
  ASSERT_TRUE(std::get<TokenType>(tokens[0].at("type")) == TokenType::COLOR &&
              std::get<std::string>(tokens[0].at("content")) ==
                  std::string("h"));
  ASSERT_TRUE(std::get<TokenType>(tokens[1].at("type")) == TokenType::SHAKE &&
              std::get<std::string>(tokens[1].at("content")) ==
                  std::string("e"));
  ASSERT_TRUE(std::get<TokenType>(tokens[2].at("type")) == TokenType::SIZE &&
              std::get<std::string>(tokens[2].at("content")) ==
                  std::string("l"));
  ASSERT_TRUE(
      std::get<TokenType>(tokens[3].at("type")) == TokenType::SIZE &&
      std::get<std::string>(tokens[3].at("content")) == std::string("l"));
  ASSERT_TRUE(
      std::get<TokenType>(tokens[4].at("type")) == TokenType::SIZE &&
      std::get<std::string>(tokens[4].at("content")) == std::string("o"));
}