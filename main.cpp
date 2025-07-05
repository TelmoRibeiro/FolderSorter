#include <filesystem>
#include <vector>
#include <iostream>

namespace filesystem = std::filesystem;
using std::vector;
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

    // @ telmo - just printing 
    for (const auto& file : files_path) {
        std::cout << file << '\n';
    }

    return 0;
}