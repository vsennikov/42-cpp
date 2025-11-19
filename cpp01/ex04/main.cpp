#include <fstream>
#include <iostream>
#include <string>

void replaceString(std::string &content, const std::string &s1,
                   const std::string &s2) {
  if (s1.empty())
    return;

  std::string result;
  size_t pos = 0;
  size_t found;

  while ((found = content.find(s1, pos)) != std::string::npos) {
    result.append(content, pos, found - pos);
    result.append(s2);
    pos = found + s1.length();
  }
  result.append(content, pos, std::string::npos);
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

  // Read entire file into string
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
