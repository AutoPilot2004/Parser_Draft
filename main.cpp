#include <fstream>
#include "src/JSONParser/JSONTokenizer.h"
#include <iostream>
#include "src/JSONParser/JSONParser.h"
/*
std::ostream& operator<<(std::ostream& s, JSONTokenType t)
{
	std::string str;

	switch (t) {
	case JSONTokenType::LEFT_BRACE:  str = "LEFT_BRACE";  break;
	case JSONTokenType::RIGHT_BRACE: str = "RIGHT_BRACE"; break;
	case JSONTokenType::COMMA:       str = "COMMA";       break;
	case JSONTokenType::COLON:       str = "COLON";       break;
	case JSONTokenType::LEFT_BRACK:  str = "LEFT_BRACK";  break;
	case JSONTokenType::RIGHT_BRACK: str = "RIGHT_BRACK"; break;
	}

	s << str;

	return s;
}

void print(const JSONToken& token)
{
	if (token.type == JSONTokenType::KEYWORD_V) std::cout << "KEYWORD";
	if (token.type == JSONTokenType::STRING_V)  std::cout << "STRING";
	if (token.type == JSONTokenType::NUMBER_V) {
		std::cout << "NUMBER";
		std::cout << "(d form: " << std::stod(token.lexeme) << ')';
	}
}
*/

#define v(c) "\c"

int main()
{
	std::ifstream file("hello.txt");
	if (file.fail()) return 5;

	std::cout << "\n\n\n\n\n\n";

	char c[] = { '\\', 'n', '\0'};

	std::string s;
	s += 'b';
	s += c;
	s += 'n';

	std::cout << (std::string)s;

	std::cout << "\n\n\n\n\n\n";

	auto b = parse(file);

	const auto& val = *static_cast<AST::Value::Object*>(b.get());

	for (const auto& [name, value]: val.pairs) {
		std::cout << name << std::endl;
	}

	bool br = false;

	int i;
	
	for (i = 0; i < 5 && !br; i++) {
		std::cout << i << std::endl;

		break;
	}

	std::cout << i;

	std::cin.get();

	return 0;
}