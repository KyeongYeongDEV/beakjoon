#include <iostream>
#include <set>
using namespace std;

int main() {cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);

    int n;
    cin >> n;

    set<string, greater<string> > people;

    for (int i = 0; i < n; i++) {
        string name, action;
        cin >> name >> action;
        if (action == "enter") {
            people.insert(name);
        } else {
            people.erase(name);
        }
    }

    for (auto &name : people) {
        cout << name << "\n";
    }

    return 0;
}
