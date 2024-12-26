#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n; // Number of test cases
    
    while (n--) {
        int k, l1, r1, l2, r2;
        cin >> k >> l1 >> r1 >> l2 >> r2;

        int cnt = 0;

        // Precompute powers of k up to a reasonable limit
        vector<int> powers;
        long long r = 1;
        while (r <= 1e9) { // Limit to prevent overflow
            powers.push_back(r);
            r *= k;
        }

        // Iterate through valid x and y
        for (int x = l1; x <= r1; x++) {
            if (x == 0) continue; // Prevent division by zero
            
            for (int y = l2; y <= r2; y++) {
                int p = y / x; // Calculate the quotient

                // Check if p exists in precomputed powers
                if (binary_search(powers.begin(), powers.end(), p)) {
                    cnt++;
                }
            }
        }

        cout << cnt << endl;
    }
    return 0;
}

