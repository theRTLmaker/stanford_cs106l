#include "spellcheck.h"

#include <algorithm>
#include <iostream>
#include <numeric>
#include <ranges>
#include <set>
#include <vector>

template <typename Iterator, typename UnaryPred>
std::vector<Iterator> find_all(Iterator begin, Iterator end, UnaryPred pred);

Corpus tokenize(std::string& source) {
  std::vector<std::string::iterator> space_it = find_all(source.begin(),
                                                         source.end(),
                                                         [](char c) { return std::isspace(c);});

  Corpus tokens;
  std::transform(space_it.begin(),
                 space_it.end() - 1,
                 space_it.begin() + 1,
                 std::inserter(tokens, tokens.begin()),
                 [&source](auto it1, auto it2) {
                    return Token{source, it1, it2};
                 });

  std::erase_if(tokens, [](Token token) {
    return token.content.empty();
  });

  return tokens;
}

namespace rv = std::ranges::views;

std::set<Misspelling> spellcheck(const Corpus& source, const Dictionary& dictionary) {
  auto in_dict = [&dictionary] (const Token & token) -> bool { return dictionary.count(token.content) == 0; };
  auto create_misspelling = [&dictionary] (const Token & token) -> Misspelling {
    auto view = dictionary | rv::filter([&token] (const std::string & str) -> bool  {
      return levenshtein(str, token.content) < 2;
    });
    std::set<std::string> suggestions(view.begin(), view.end());
    return Misspelling{token, suggestions};
   };
  auto discard_no_suggestions = [](const Misspelling & m) -> bool {
    return (m.suggestions.empty()) ? false : true;
  };
  auto view = source
      | rv::filter(in_dict)
      | rv::transform(create_misspelling)
      | rv::filter(discard_no_suggestions);


  return std::set<Misspelling>(view.begin(), view.end());
};

/* Helper methods */

#include "utils.cpp"