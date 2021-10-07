#include "KFile.h"

string KFile::GetCurrentPath()
{
    string path = fs::current_path();
    return path;
}

string KFile::GetUserPath()
{
    string user_path = "";
    printf("Enter folder path: ");
    cin >> user_path;
    return user_path;
}

string KFile::GetHeader()
{
    string header = "";
    cout << "Enter your header (Type NONE to skip): ";
    cin >> header;
    if (header == "none" || header == "NONE")
    {
        header = "";
    }
    return header;
}

bool KFile::IsVideo(string filename)
{
    regex video_type("^.*.(avi|AVI|wmv|WMV|flv|FLV|mpg|MPG|mp4|MP4|MOV|mov|3gp|3GP|webm)$");
    return regex_match(filename, video_type);
}

vector<string> KFile::GetAllFilename(string path)
{

    vector<string> list;
    for (const auto &entry : fs::directory_iterator(path))
    {

        if (fs::is_regular_file(entry))
        {
            if (IsVideo(entry.path().filename()))
            {
                list.push_back(entry.path().filename());
                //std::cout << entry.path().filename() << std::endl;
            }
        }
    }
    return list;
}
void KFile::CreateList(std::string header, std::vector<string> list, string path, bool flag)
{
    std::fstream output;
    string dir_out = path + "/my_list.txt";
    output.open(dir_out, std::ios::out);
    while (!list.empty())
    {
        output << header << " " << list.back() << "\n";
        list.pop_back();
    }

    cout << "Create list successfull!!!\n";
    printf("Output file: %s/my_list.txt\n", path.c_str());
    output.close();
}
