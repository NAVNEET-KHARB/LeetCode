class MyCalendarTwo {
public:
    vector<pair<int, int>> bookings;
    vector<pair<int, int>> overlapBookings;

    MyCalendarTwo() {}

    bool book(int start, int end) {
        for (pair<int, int> booking : overlapBookings) {
            if (doesOverlap(booking.first, booking.second, start, end)) {
                return false;
            }
        }
        for (pair<int, int> booking : bookings) {
            if (doesOverlap(booking.first, booking.second, start, end)) {
                overlapBookings.push_back(
                    getOverlapped(booking.first, booking.second, start, end));
            }
        }
        bookings.push_back({start, end});
        return true;
    }

private:
    bool doesOverlap(int start1, int end1, int start2, int end2) {
        return max(start1, start2) < min(end1, end2);
    }
    pair<int, int> getOverlapped(int start1, int end1, int start2, int end2) {
        return {max(start1, start2), min(end1, end2)};
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */