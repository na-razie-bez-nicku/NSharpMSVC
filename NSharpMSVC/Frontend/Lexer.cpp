#include "Lexer.hpp"

token::token(TOKEN_TYPE type, std::string value, int64_t line, int64_t column) {
  this->type = type;
  this->value = value;
  this->line = line;
  this->column = column;
}

std::vector<token> lexer::tokenize(std::string code) {
	std::vector<token> tokens;

	int64_t ln = 1;
	int64_t chr = 1;

	for (size_t c = 0; c < code.length(); c++) {
		if (code[c] == '(')
			tokens.emplace_back(new token(_OPEN_PAREN, std::string(1, code[c]), ln, chr));
		else if (code[c] == ')')
			tokens.emplace_back(new token(_CLOSE_PAREN, std::string(1, code[c]), ln, chr));
		else if (code[c] == '{')
			tokens.emplace_back(new token(_OPEN_BRACE, std::string(1, code[c]), ln, chr));
		else if (code[c] == '}')
			tokens.emplace_back(new token(_CLOSE_BRACE, std::string(1, code[c]), ln, chr));
		else if (code[c] == '[')
			tokens.emplace_back(new token(_OPEN_BRACKET, std::string(1, code[c]), ln, chr));
		else if (code[c] == ']')
			tokens.emplace_back(new token(_CLOSE_BRACKET, std::string(1, code[c]), ln, chr));
		else if (code[c] == '+')
			tokens.emplace_back(new token(_BINARY_OPERATOR, std::string(1, code[c]), ln, chr));
		else if (code[c] == '-')
			tokens.emplace_back(new token(_BINARY_OPERATOR, std::string(1, code[c]), ln, chr));
		else if (code[c] == '*')
			tokens.emplace_back(new token(_BINARY_OPERATOR, std::string(1, code[c]), ln, chr));
		else if (code[c] == '/')
			tokens.emplace_back(new token(_BINARY_OPERATOR, std::string(1, code[c]), ln, chr));
		else if (code[c] == '%')
			tokens.emplace_back(new token(_BINARY_OPERATOR, std::string(1, code[c]), ln, chr));
		else if (code[c] == '=') {
			c++;
			if(code[c] == '=')
				tokens.emplace_back(new token(_LOGIC_OPERATOR, "==", ln, chr));
			else
				tokens.emplace_back(new token(_BINARY_EQUALS, std::string(1, code[c]), 0, chr));
		}
		else if (code[c] == '!') {
			c++;
			if(code[c] == '=')
				tokens.emplace_back(new token(_LOGIC_OPERATOR, "!=", ln, chr));
			else
				tokens.emplace_back(new token(_LOGIC_OPERATOR, std::string(1, code[c]), ln, chr));
		}
		else if (code[c] == '<') {
			c++;
			if(code[c] == '=')
				tokens.emplace_back(new token(_LOGIC_OPERATOR, "<=", ln, chr));
			else
				tokens.emplace_back(new token(_LOGIC_OPERATOR, std::string(1, code[c]), ln, chr));
		}
		else if (code[c] == '>') {
			c++;
			if(code[c] == '=')
				tokens.emplace_back(new token(_LOGIC_OPERATOR, ">=", ln, chr));
			else
				tokens.emplace_back(new token(_LOGIC_OPERATOR, std::string(1, code[c]), ln, chr));
		}
		else if (code[c] == '>') {
			c++;
			if(code[c] == '=')
				tokens.emplace_back(new token(_LOGIC_OPERATOR, ">=", ln, chr));
			else
				tokens.emplace_back(new token(_LOGIC_OPERATOR, std::string(1, code[c]), ln, chr));
		}
		else if(std::isspace(code[c]))
			tokens.emplace_back(new token(_SKIPPABLE, std::string(1, code[c]), ln, chr));
		else if (code[c] == '\'') {
			tokens.emplace_back(new token(_SINGLE_QUOTE, std::string(1, code[c]), ln, chr));
			chr++;
			c++;
			if (code[c] == '\\') {
				tokens.emplace_back(new token(_TEXT, std::string() + code[c] + code[c + 1], ln, chr));
				chr++;
				c++;
			}
			else
				tokens.emplace_back(new token(_TEXT, std::string(1, code[c]), ln, chr));
			chr++;
			c++;
			if (code[c] == '\'')
				tokens.emplace_back(new token(_SINGLE_QUOTE, std::string(1, code[c]), ln, chr));
			else {
				std::cerr << "Error while tokenizing. \"' '\" must have one character";
				std::this_thread::sleep_until(std::chrono::system_clock::now() + std::chrono::seconds(5));
				std::exit(1);
			}
			chr++;
			c++;
		}
		else if (code[c] == '"') {
			tokens.emplace_back(new token(_QUOTE, std::string(1, code[c]), ln, chr));
			chr++;
			c++;
			std::string text = std::string(1, code[c]);
			while (c < code.length()) {
				c++;
				if (code[c] == '\\') {
					text += code[c] + code[c + 1];
					c += 2;
				}
				if (code[c] == '"')
					break;
				text += code[c];
			}
			tokens.emplace_back(new token(_TEXT, text, ln, chr));
			c++;
			tokens.emplace_back(new token(_QUOTE, std::string(1, code[c]), ln, chr));
		}
		chr++;
	}

	return tokens;
}