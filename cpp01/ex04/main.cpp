#include <fstream>
#include <iostream>

bool isValidMatch(const std::string &content, size_t pos, size_t len) {
  bool is_start_valid = (pos == 0) || std::isspace(content[pos - 1]);
  bool is_end_valid =
      (pos + len == content.length()) || std::isspace(content[pos + len]);
  return is_start_valid && is_end_valid;
}

void replaceString(std::string &content, const std::string &s1,
                   const std::string &s2) {
  if (s1.empty())
    return;

  std::string result;
  size_t last_token_end = 0;
  size_t search_pos = 0;
  size_t found_pos;

  while ((found_pos = content.find(s1, search_pos)) != std::string::npos) {
    if (isValidMatch(content, found_pos, s1.length())) {
      result.append(content, last_token_end, found_pos - last_token_end);
      result.append(s2);
      last_token_end = found_pos + s1.length();
      search_pos = last_token_end;
    } else {
      search_pos = found_pos + 1;
    }
  }
  result.append(content, last_token_end, std::string::npos);
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
