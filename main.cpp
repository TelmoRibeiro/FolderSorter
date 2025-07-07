#include <filesystem>
#include <vector>
#include <set>
#include <iostream>


namespace fs = std::filesystem;
using std::vector;
using std::set;
using std::string;


// get all regular files in the directory, optionally filtered by extension
vector<fs::path> get_files_path(const fs::path& path, const string& extension = "") {
    vector<fs::path> files_path;
    
    for (const auto& entry : fs::directory_iterator(path)) {
        if (fs::is_regular_file(entry)) {
            if (extension.empty() || entry.path().extension().string() == extension) {
                files_path.push_back(entry.path());
            }
        }
    }

    return files_path;
}

void move_files_to_folder(const fs::path& file, const fs::path& target_folder) {
    fs::create_directories(target_folder);
    fs::path destination = target_folder / file.filename();
    fs::rename(file, destination);
}

int main() {
    fs::path path = "C:/Users/telmo/Desktop/FolderSorter";
    vector<fs::path> all_files = get_files_path(path);

    set<string> extensions;
    for (const auto& file : all_files) {
        extensions.insert(file.extension().string());
    }

    for (const auto& extension : extensions) {
        vector<fs::path> matching_files = get_files_path(path, extension);
        
        std::cout << "Extension: " << extension << "\n";
        for (const auto& file : matching_files) {
            std::cout << " " << file.string() << "\n";
        }
        std::cout << std::endl;

        for (const auto& file : matching_files) {
            const fs::path folder = path / (file.extension().string() + "_files");
            move_files_to_folder(file, folder);
        }
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