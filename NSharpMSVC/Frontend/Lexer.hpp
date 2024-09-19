#include <string>
#include <vector>
#include <map>
#include <thread>
#include <chrono>
#include <iostream>

enum TOKEN_TYPE
{
  _EOF,
  _KEYWORD_TYPE, // byt, sht, int, lng, sbyt, usht, uint, ulng, num, str, bit, chr, any, obj, void
  _KEYWORD_IF, // if
  _KEYWORD_ELSE, // else
  _KEYWORD_WHILE, // while
  _KEYWORD_FOR, //for
  _KEYWORD_RETURN, // return
  _KEYWORD_BREAK, // break
  _KEYWORD_CONTINUE, // continue
  _KEYWORD_SWITCH, // switch
  _KEYWORD_CASE, // case
  _KEYWORD_DEFAULT, // default
  _KEYWORD_STRUCT, // struct
  _KEYWORD_CLASS, // class
  _KEYWORD_IMPORT, // import
  _KEYWORD_USE, // use
  _KEYWORD_NAMESPACE, // namespace
  _KEYWORD_FUN, // fun
  _KEYWORD_ENUM, // enum
  _KEYWORD_PUBLIC, // public
  _KEYWORD_PRIVATE, // private
  _KEYWORD_PROTECTED, // protected
  _KEYWORD_STATIC, // static
  _KEYWORD_TYPEOF, // typeof
  _KEYWORD_NAMEOF, // nameof
  _IDENTIFIER,
  _SKIPPABLE,
  _COMMENT,
  _TEXT,
  _NUMBER,
  _INTEGER,
  _OPEN_PAREN, // (
  _CLOSE_PAREN, // )
  _OPEN_BRACE, // {
  _CLOSE_BRACE, // }
  _OPEN_BRACKET, // [
  _CLOSE_BRACKET, // ]
  _BINARY_OPERATOR, // +, -, *, /, %
  _BINARY_EQUALS, // =
  _LOGIC_OPERATOR, // ==, !=, <, >, <=, >=, !
  _QUOTE, // "
  _SINGLE_QUOTE, // '
};

class token
{
public:
  TOKEN_TYPE type;
  std::string value;
  int64_t line;
  int64_t column;
  token(TOKEN_TYPE type, std::string value, int64_t line, int64_t column);
};

class lexer {
public:
	static std::vector<token> tokenize(std::string code);
private:
	std::map<std::string, TOKEN_TYPE> keywords = {
		{ "bit", _KEYWORD_TYPE},
		{ "byt", _KEYWORD_TYPE},
		{ "sht", _KEYWORD_TYPE},
		{ "int", _KEYWORD_TYPE},
		{ "lng", _KEYWORD_TYPE},
		{ "ubyt", _KEYWORD_TYPE},
		{ "usht", _KEYWORD_TYPE},
		{ "uint", _KEYWORD_TYPE},
		{ "ulng", _KEYWORD_TYPE},
		{ "num", _KEYWORD_TYPE},
		{ "str", _KEYWORD_TYPE},
		{ "chr", _KEYWORD_TYPE},
		{ "any", _KEYWORD_TYPE},
		{ "obj", _KEYWORD_TYPE},
		{ "void", _KEYWORD_TYPE},
		{ "if", _KEYWORD_IF},
		{ "else", _KEYWORD_ELSE},
		{ "while", _KEYWORD_WHILE},
		{ "for", _KEYWORD_FOR},
		{ "return", _KEYWORD_RETURN},
	};
};