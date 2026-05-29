#include <iostream>
#include "CTime.h"

int main() {
    CTime t1;
    cout << "--- Nhap thoi gian ban dau ---\n";
    cin >> t1;
    cout << "Thoi gian hien tai: " << t1 << "\n\n";

    int s;
    cout << "Nhap so giay muon cong them: ";
    cin >> s;

    CTime t_cong = t1 + s;
    cout << "Sau khi cong " << s << " giay: " << t_cong << "\n";

    CTime t_tru = t1 - s;
    cout << "Sau khi tru " << s << " giay: " << t_tru << "\n\n";

    cout << "--- Them/bot 1 giay ---\n";

    ++t1;
    cout << "Sau khi them 1 giay: " << t1 << "\n";

    --t1;
    --t1;
    cout << "Sau khi bot 1 giay: " << t1 << "\n";

    return 0;
}
