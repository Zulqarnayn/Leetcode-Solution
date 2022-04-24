class UndergroundSystem {
    unordered_map <int, pair<string, int>> stationToDistanceMap;
    unordered_map <string, pair<double, int>> avgToTimesOccurMap; 
public:
    UndergroundSystem() { }
    
    void checkIn(int id, string stationName, int t) {
        //map [id] = { from , time }
        stationToDistanceMap[id] = {stationName, t};
    }
    
    void checkOut(int id, string stationName, int t) {
        if(stationToDistanceMap.count(id)) {
            int checkInTime = stationToDistanceMap[id].second;
            string fromTo = stationToDistanceMap[id].first + "_" + stationName;
            
            int timesOccur = avgToTimesOccurMap[fromTo].second;
            double avg = avgToTimesOccurMap[fromTo].first * timesOccur + (t - checkInTime);
            avg = avg / (timesOccur + 1);
            
            avgToTimesOccurMap[fromTo].first = avg;
            avgToTimesOccurMap[fromTo].second = timesOccur + 1;
            
            //remove key
            stationToDistanceMap.erase(id);
        }
    }
    
    double getAverageTime(string startStation, string endStation) {
        string fromTo = startStation + "_" + endStation;
        return avgToTimesOccurMap[fromTo].first;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */