class Solution {
public:
    vector<string> splitBySpace(string path) {
        vector<string> tokens;
        string buf;
        stringstream ss(path);
        
        while(ss >> buf) {
            tokens.push_back(buf);
        }
        
        return tokens;
    }
    
    pair<string, string> extractPathAndContent(string path) {
        string file, content;
        int idx = 0;
        while(path[idx] != '(') {
            file += path[idx++];
        }
        
        idx++;
        
        while(path[idx] != ')') {
            content += path[idx++];
        }
        
        return {file, content};
    }
    
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        
        unordered_map<string, vector<string>> pathMap;
        
        for(auto path: paths) {
            vector<string> tokens = splitBySpace(path);
            
            string root = tokens[0];
            for(int idx = 1; idx < tokens.size(); idx++) {
                pair<string, string> fileAndContent = extractPathAndContent(tokens[idx]);
                string directory = root + "/" + fileAndContent.first;
                pathMap[fileAndContent.second].push_back(directory);
            }
        }
        
        vector<vector<string>> result;
        for(auto file: pathMap) {
            if(file.second.size() > 1) {
                result.push_back(file.second);
            }
        }
        
        return result;
    }
};
/*
["root/a 1.txt(abcd) 2.txt(efgh)","root/c 3.txt(abcd)","root/c/d 4.txt(efgh)","root 4.txt(efgh)"]

["root/a 1.txt(abcd) 2.txt(efsfgh)","root/c 3.txt(abdfcd)","root/c/d 4.txt(efggdfh)"]
*/