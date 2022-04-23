class Solution {
    unordered_map<string, string> URLToCode, codeToURL;
    int count;
    string base = "https://tinyurl.com/";
public:

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        if(!URLToCode.count(longUrl)) {
            string shortUrl = base + to_string(count++);
            URLToCode[longUrl] = shortUrl;
            codeToURL[shortUrl] = longUrl;
        }
        
        return URLToCode[longUrl];
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return codeToURL[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));