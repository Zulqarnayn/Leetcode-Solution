class Solution {
public:
    string getUniqueEmail(string email) {
        int size = email.size();
        string cleanEmail = "";
        
        for(char ch: email) {
            if(ch == '@' || ch == '+') break;
            
            if(ch == '.') continue;
            
            cleanEmail += ch;
        }
        
        string domainName = "";
        for(int idx = size - 1; idx >= 0; idx--) {
            domainName += email[idx];
            
            if(email[idx] == '@') break; 
        }
        
        reverse(domainName.begin(), domainName.end());
        
        cleanEmail += domainName;
        return cleanEmail;
    }
    
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> uniqueEmails;
        
        for(auto email: emails) {
            uniqueEmails.insert(getUniqueEmail(email));
        }
        
        return uniqueEmails.size();
    }
};