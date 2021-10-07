#include "KFile.h"
#include "KFile.cpp"

int main()
{

    try
    {
        KFile *kfile = new KFile();
        string path = "";
        string header = "";
        bool flag = false;
        vector<string> list;
        delete kfile;

        int choose = 0;
        printf("=============== Create Filename List ===============\n");
        printf("1. Use current directory\n");
        printf("2. Enter path derectory!\n");
        printf("3. Exit\n");

        printf("Enter your option: ");
        cin >> choose;
        do
        {

            switch (choose)
            {
            case 1:
                flag = false;
                header = kfile->GetHeader();
                path = kfile->GetCurrentPath();
                list = kfile->GetAllFilename(path);
                kfile->CreateList(header, list, path, flag);
                return 0;
            case 2:
                flag = true;
                path = kfile->GetUserPath();
                header = kfile->GetHeader();
                list = kfile->GetAllFilename(path);
                kfile->CreateList(header, list, path, flag);
                return 0;
            case 3:
                return 0;
            default:
                printf("Invalid option, try again !!!\n");
                printf("Enter your option: ");
                cin >> choose;
            }
        } while (choose > 0 && choose < 4);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    return 0;
}
