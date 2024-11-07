#include <iostream>
#include <vector>
#include <string>

using namespace std;

class SeatReservation {
private:
    int n, m; // n is number of rows, m is number of seats per row
    vector<vector<bool>> seats; // to keep track of seat reservations (true means booked)

public:
    // Constructor to initialize the instance variables
    SeatReservation(int n, int m) : n(n), m(m) {
        // Initialize all seats to false (available), rows and seats are 1-based indexed
        seats = vector<vector<bool>>(n + 1, vector<bool>(m + 1, false));
    }

    // Method to find and reserve the first contiguous block of seats in a given row
    string reserveSeats(int row, int count) {
        // Check if the row is within bounds
        if (row < 1 || row > n) {
            return "Seats not available";
        }
        // if(count<0){
        //     return ""
        // }
        if(count > m)
        {
            return "Seats not available";
        }



        // Search for the first contiguous block of 'count' seats in the given row
        for (int i = 1; i <= m - count + 1; i++) {  // Adjusted for 1-based index
            bool available = true;
            for (int j = i; j < i + count; j++) {
                if (j<=m&&row<=n&&seats[row][j]) { // if any seat is already booked
                    available = false;
                    break;
                }
            }

            // If a block is available, reserve the seats
            if (available) {
                for (int j = i; j < i + count; j++) {
                if(j<=m&&row<=n){
                    seats[row][j] = true;}
                }
                return "Booked with seat number " + to_string(i);
            }
        }

        // If no contiguous block is found, return "Seats not available"
        return "Seats not available";
    }
};


int main() {
    // Example usage:
    int n = 2, m = 5; // 2 rows, 5 seats per row
    SeatReservation theater(n, m);

    // First query: try to book 3 contiguous seats in row 1
    cout << theater.reserveSeats(1, 3) << endl;

    // Second query: try to book 2 contiguous seats in row 1
    cout << theater.reserveSeats(1, 2) << endl;

    // Third query: try to book 4 contiguous seats in row 2
    cout << theater.reserveSeats(2, 4) << endl;

    return 0;
}
