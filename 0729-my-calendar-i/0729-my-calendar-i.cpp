class MyCalendar {
    set<pair<int, int>> cal;

public:
    MyCalendar() {}

    bool book(int start, int end) {
        const pair<int, int> event{start, end};
        const auto nextEvent = cal.lower_bound(event);
        if (nextEvent != cal.end() && nextEvent->first < end) {
            return false;
        }
        if (nextEvent != cal.begin()) {
            const auto prevEvent = prev(nextEvent);
            if (prevEvent->second > start) {
                return false;
            }
        }
        cal.insert(event);
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */