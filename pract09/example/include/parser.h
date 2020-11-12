#ifndef PARSER_H_
#define PARSER_H_

#include <expression.h>

#include <optional>
#include <string>

std::optional<Expression> parse(const std::string&);

#endif
