/*
*   Get all file name in current directory and create a list
*   Complie with c++17:
*   g++ -o <execute filename> CreateFileList.cpp -std=c++17 && ./<execute filename>
*/

#ifndef KFILE_H
#define KFILE_H

#include <iostream>
#include <filesystem>
#include <fstream>
#include <string>
#include <vector>
#include <regex>

namespace fs = std::filesystem;
using std::cin;
using std::cout;
using std::endl;
using std::regex;
using std::string;
using std::vector;

class KFile
{
private:
public:
    KFile(){};
    ~KFile(){};

    string GetCurrentPath();
    string GetUserPath();
    string GetHeader();
    vector<string> GetAllFilename(string path);
    bool IsVideo(string filename);
    void CreateList(std::string header, vector<string> list, string path, bool flag);
};

#endif