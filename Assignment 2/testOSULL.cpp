#include "OSULL.h"
#include <iostream>

using namespace std;

int main() {
    const int N = 10;
    OSULL<int> lst;

    lst.display();
    cout << "\n";

    cout << " max: " << lst.getMax() << "\n";
    cout << " min: " << lst.getMin() << "\n";

    for (int i = 0; i < N; i++) {
        lst.insert(21 - i);
    }
    lst.display();
    cout << "\n";

    cout << "finding 4: " << ((lst.find(4)) ? "yes" : "no") << "\n";
    cout << "finding 14: " << ((lst.find(14)) ? "yes" : "no") << "\n";

    cout << "removing 4 and 14\n";
    lst.remove(4);
    lst.remove(14);
    lst.display();
    cout << "\n";

    cout << "inserting 5 and 15\n";
    lst.insert(5);
    lst.insert(15);
    lst.display();
    cout << "\n";

    cout << "removing 8 and 18\n";
    lst.remove(8);
    lst.remove(18);
    lst.display();
    cout << "\n";

    cout << "inserting 2 and 25\n";
    lst.insert(2);
    lst.insert(25);
    lst.display();
    cout << "\n";

    // Testing find operation
    cout << "finding 1: " << ((lst.find(1)) ? "yes" : "no") << "\n";
    cout << "finding 2: " << ((lst.find(2)) ? "yes" : "no") << "\n";
    cout << "finding 4: " << ((lst.find(4)) ? "yes" : "no") << "\n";
    cout << "finding 5: " << ((lst.find(5)) ? "yes" : "no") << "\n";
    cout << "finding 8: " << ((lst.find(8)) ? "yes" : "no") << "\n";
    cout << "finding 11: " << ((lst.find(11)) ? "yes" : "no") << "\n";
    cout << "finding 14: " << ((lst.find(14)) ? "yes" : "no") << "\n";
    cout << "finding 15: " << ((lst.find(15)) ? "yes" : "no") << "\n";
    cout << "finding 18: " << ((lst.find(18)) ? "yes" : "no") << "\n";
    cout << "finding 25: " << ((lst.find(25)) ? "yes" : "no") << "\n";
    cout << "finding 28: " << ((lst.find(28)) ? "yes" : "no") << "\n";

    if (!lst.isEmpty()) {
        cout << " max: " << lst.getMax() << "\n";
        cout << " min: " << lst.getMin() << "\n";
    }

    cout << "making and deleting the list\n";
    OSULL<int> *lst2 = new OSULL<int>;
    lst2->insert(2);
    lst2->insert(25);
    lst2->display();
    delete lst2;
    cout << "\n";

    cout << "making a character list\n";
    OSULL<char> *lst3 = new OSULL<char>;
    lst3->insert('c');
    lst3->insert('a');
    lst3->insert('d');
    lst3->insert('b');
    lst3->display();
    delete lst3;
    cout << "\n";

    cout << "\n";
    cout << "done\n";

    return 0;
}
