#include <fstream>
#include <iostream>
#include <cargs.h>

#define PRINT(x) std::cout << #x << ": " << (x) << "\n"

static cag_option options[] =
{
    {
        .identifier = 'a',
        .access_letters = "a",
        .access_name = "add",
        .value_name = nullptr,
        .description = "Adds a file to ASJ_List.txt"
    },
    {
        .identifier = 'r',
        .access_letters = "r",
        .access_name = "remove",
        .value_name = nullptr,
        .description = "Removes a file from ASJ_List.txt"
    },
    {
        .identifier = 's',
        .access_letters = "s",
        .access_name = "split",
        .value_name = nullptr,
        .description = "Splits all files listed in ASJ_List.txt"
    },
    {
        .identifier = 'j',
        .access_letters = "j",
        .access_name = "join",
        .value_name = nullptr,
        .description = "Joins all files listed in ASJ_List.txt with their parts"
    },
    {
        .identifier = 'h',
        .access_letters = "h",
        .access_name = "help",
        .value_name = nullptr,
        .description = "Shows this help information"
    }
};

static void ShowUsage()
{
    std::cout << "Usage: asj [OPTION] [FILE]...\n";
    std::cout << "AssetSplitJoin splits large files into smaller chunks, and joins them. "
        "Useful for checking large assets into version control.\n\n";
    cag_option_print(options, CAG_ARRAY_SIZE(options), stdout);
    std::cout << "Please only use one of the options above.\n";
}

static void AddFile(const char* filePath)
{
    std::cout << "Adding ";
    PRINT(filePath);
}

static void RemoveFile(const char* filePath)
{
    std::cout << "Removing ";
    PRINT(filePath);
}

static void SplitFiles()
{
    std::fstream list("ASJ_List.txt", std::ios_base::in);
    if (!list)
    {
        std::cout << "WARNING: ASJ_List.txt not found. No files split.\n";
    }
}

static void JoinFiles()
{
    std::fstream list("ASJ_List.txt", std::ios_base::in);
    if (!list)
    {
        std::cout << "WARNING: ASJ_List.txt not found. No files joined.\n";
    }
}

int main(int argc, char* argv[])
{
    if (argc == 1)
    {
        ShowUsage();
        return 0;
    }

    bool isAdding = false, isRemoving = false, isSplitting = false, isJoining = false;
    bool isArgumentError = false;
    int optionsEnabled = 0;

    cag_option_context context;
    cag_option_init(&context, options, CAG_ARRAY_SIZE(options), argc, argv);
    while (cag_option_fetch(&context))
    {
        switch (cag_option_get_identifier(&context))
        {
        case 'a':
            isAdding = true;
            ++optionsEnabled;
            break;
        case 'r':
            isRemoving = true;
            ++optionsEnabled;
            break;
        case 's':
            isSplitting = true;
            ++optionsEnabled;
            break;
        case 'j':
            isJoining = true;
            ++optionsEnabled;
            break;
        case 'h':
            ShowUsage();
            return 0;
        case '?':
            isArgumentError = true;
            cag_option_print_error(&context, stdout);
            break;
        }
    }

    if (isArgumentError || optionsEnabled != 1)
    {
        ShowUsage();
        return 0;
    }

    for (int param_index = cag_option_get_index(&context); param_index < argc; ++param_index)
    {
        if (isSplitting || isJoining)
            printf("Ignoring additional parameter: %s\n", argv[param_index]);
        if (isAdding)
            AddFile(argv[param_index]);
        if (isRemoving)
            RemoveFile(argv[param_index]);
    }

    if (isSplitting)
        SplitFiles();

    if (isJoining)
        JoinFiles();

    return 0;
}
