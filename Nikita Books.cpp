#include <iostream>
using namespace std;
void solve() {
    int n;cin >> n;
    long long extra = 0;
    bool ok = true;
    for (int i = 1; i <= n; i++) {
        long long books;
        cin >> books;
        long long total = books + extra;
        if (total < i) {
            ok = false;
        } else {
            extra = total - i;
        }
    }
    if (ok) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tc;cin >> tc;
    while (tc--) {
        solve();
    }
    return 0;
}
