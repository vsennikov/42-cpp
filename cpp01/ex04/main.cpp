#include <fstream>
#include <iostream>
#include <string>

#include <cctype>

void replaceString(std::string &content, const std::string &s1,
                   const std::string &s2) {
  if (s1.empty())
    return;

  std::string result;
  size_t last_copied_pos = 0;
  size_t search_pos = 0;
  size_t found;

  while ((found = content.find(s1, search_pos)) != std::string::npos) {
    bool is_start_boundary = (found == 0) || !std::isalnum(content[found - 1]);
    bool is_end_boundary = (found + s1.length() == content.length()) ||
                           !std::isalnum(content[found + s1.length()]);

    if (is_start_boundary && is_end_boundary) {
      result.append(s2);
      last_copied_pos = found + s1.length();
      search_pos = last_copied_pos;
    } else {
      search_pos = found + 1;
    }
  }
  result.append(content, last_copied_pos, std::string::npos);
  content = result;
}

int main(int argc, char **argv) {
  if (argc != 4) {
    std::cerr << "Usage: " << argv[0] << " <filename> <s1> <s2>" << std::endl;
    return 1;
  }

  std::string filename = argv[1];
  std::string s1 = argv[2];
  std::string s2 = argv[3];

  std::ifstream inFile(filename.c_str());
  if (!inFile.is_open()) {
    std::cerr << "Error: could not open input file: " << filename << std::endl;
    return 1;
  }

  std::string content;
  std::string line;
  while (std::getline(inFile, line)) {
    content += line;
    if (!inFile.eof())
      content += "\n";
  }
  inFile.close();

  replaceString(content, s1, s2);

  std::string outFilename = filename + ".replace";
  std::ofstream outFile(outFilename.c_str());
  if (!outFile.is_open()) {
    std::cerr << "Error: could not create output file: " << outFilename
              << std::endl;
    return 1;
  }

  outFile << content;
  outFile.close();

  return 0;
}
