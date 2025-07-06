#include <filesystem>
#include <vector>
#include <set>
#include <iostream>

namespace filesystem = std::filesystem;
using std::vector;
using std::set;
using std::string;

vector<filesystem::path> get_files_path(const filesystem::path& path) {
    vector<filesystem::path> files_path;
    
    for (const auto& file : filesystem::directory_iterator(path)) {
        files_path.push_back(file.path());
    }

    return files_path;
}

int main() {
    filesystem::path path = "C:/Users/telmo/Desktop/FolderSorter";
    vector<filesystem::path> files_path = get_files_path(path);

    set<string> extensions;
    
    for (const auto& file : files_path) {
        extensions.insert(file.extension().string());
    }

    for (const string extension : extensions) {
        std::cout << extension << '\n';
    }

    return 0;
}

/* UNUSED SPLIT
vector<string> split(const string& str, char delimiter) {
    vector<string> tokens;
    string token;

    for (const char character : str) {
        if (character == delimiter && !token.empty()) {
            tokens.push_back(token);
            token.clear();
            continue;
        }
        
        token += character;
    }

    // appending the last 'non-delimited' token
    if (!token.empty()) {
        tokens.push_back(token);
    }

    return tokens;
}
*/