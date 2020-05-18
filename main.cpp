#include <iostream>
#include <fstream>
#include <regex>
#include <algorithm>

int main (int argc, char* argv[]) {
  if (argc != 2) {
    std::cerr << "Usage: " << argv[0] << " PATH_TO_FILE" << "\n"
	      << "Lines begining with a \"#\" are ignored\n";
    return 1;
  } else {
    std::string helpArgument = argv[1];
    
    if (helpArgument == "-h") {
          std::cout << "Usage: " << argv[0] << " PATH_TO_FILE" << "\n"
	      << "Lines begining with a \"#\" are ignored\n";
        return 0;
    }
  }


  std::ifstream file {argv[1]};

  if (!file) {
    std::cerr << "Error reading file\n";
    return 1;
  }

  std::string line;
  unsigned int lineNumber = 0;
  std::string result = "";
  while (std::getline(file, line)) {
    ++lineNumber;

    std::regex emptyLine{"^(\\s)*$"};
    if (std::regex_match(line, emptyLine))
      continue;

    std::regex commentLine{"^(\\s)*#.*"};
    if (std::regex_match(line, commentLine))
      continue;

    line.erase(remove_if(line.begin(), line.end(), isspace), line.end());

    std::regex validAOB{"^([\\da-fA-F?])+$"};
    if (!std::regex_match(line, validAOB)) {
      std::cerr << "Invalid AOB at line: " << lineNumber << "\n";
      return 1;
    }

    if (result == "")
      result = line;
    else {
      if (result.length() != line.length()) {
	std::cerr << "Different length AOB at line: " << lineNumber << "\n";
	return 1;
      }

      for (int i = 0; i < result.length(); ++i)
	if (result[i] != line[i])
	  result[i] = '?';
    }
  }

  if (result == "") {
    std::cout << "No AOB\n";
    return 0;
  }

  std::string resultWithSpaces = "";
  for (int i = 0; i < result.length(); ++i) {
    resultWithSpaces.append(1, result[i]);

    if (i % 2 == 1)
      resultWithSpaces.append(" ");
  }

  std::cout << resultWithSpaces << '\n';

  return 0;
}
