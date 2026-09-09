// circuit calculator - built this to stop redoing the same Circuits homework
// math by hand every week. three tools: ohm's law, series/parallel resistance,
// and a resistor color code decoder.

#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

void ohms_law() {
    cout << "\n-- Ohm's Law Solver (V = I * R) --\n";
    cout << "Which one are you solving for?\n";
    cout << "1. Voltage (V)\n2. Current (I)\n3. Resistance (R)\n> ";
    int choice;
    cin >> choice;

    double a, b;
    switch (choice) {
        case 1:
            cout << "Current (A): ";
            cin >> a;
            cout << "Resistance (ohms): ";
            cin >> b;
            cout << "V = " << a * b << " V\n";
            break;
        case 2:
            cout << "Voltage (V): ";
            cin >> a;
            cout << "Resistance (ohms): ";
            cin >> b;
            if (b == 0) {
                cout << "resistance can't be 0, that's a short circuit\n";
                break;
            }
            cout << "I = " << a / b << " A\n";
            break;
        case 3:
            cout << "Voltage (V): ";
            cin >> a;
            cout << "Current (A): ";
            cin >> b;
            if (b == 0) {
                cout << "current can't be 0\n";
                break;
            }
            cout << "R = " << a / b << " ohms\n";
            break;
        default:
            cout << "not a valid option\n";
    }
}

void resistor_network() {
    cout << "\n-- Series / Parallel Resistance --\n";
    cout << "How many resistors are we combining? ";
    int count;
    cin >> count;
    if (count <= 0) {
        cout << "need at least one resistor\n";
        return;
    }

    vector<double> values(count);
    for (int i = 0; i < count; i++) {
        cout << "  R" << (i + 1) << " (ohms): ";
        cin >> values[i];
    }

    cout << "1. Series\n2. Parallel\n> ";
    int mode;
    cin >> mode;

    if (mode == 1) {
        // series is just adding them all up
        double total = 0;
        for (double v : values) total += v;
        cout << "Total = " << total << " ohms\n";
    } else if (mode == 2) {
        // parallel: 1/Rtotal = sum of 1/R
        double reciprocal_sum = 0;
        for (double v : values) {
            if (v == 0) {
                cout << "one of these is 0 ohms, so the parallel total is just 0\n";
                return;
            }
            reciprocal_sum += 1.0 / v;
        }
        cout << "Total = " << (1.0 / reciprocal_sum) << " ohms\n";
    } else {
        cout << "not a valid option\n";
    }
}

void resistor_color_code() {
    cout << "\n-- 4-Band Resistor Color Code Decoder --\n";

    // digit each color stands for on bands 1 and 2
    map<string, int> digit_value = {
        {"black", 0}, {"brown", 1}, {"red", 2}, {"orange", 3}, {"yellow", 4},
        {"green", 5}, {"blue", 6}, {"violet", 7}, {"gray", 8}, {"white", 9}
    };
    // multiplier for band 3
    map<string, double> multiplier_value = {
        {"black", 1}, {"brown", 10}, {"red", 100}, {"orange", 1000}, {"yellow", 10000},
        {"green", 100000}, {"blue", 1000000}, {"gold", 0.1}, {"silver", 0.01}
    };
    // tolerance for band 4 (not every color has one)
    map<string, double> tolerance_value = {
        {"brown", 1}, {"red", 2}, {"gold", 5}, {"silver", 10}
    };

    string band1, band2, band3, band4;
    cout << "Band 1 (1st digit): ";
    cin >> band1;
    cout << "Band 2 (2nd digit): ";
    cin >> band2;
    cout << "Band 3 (multiplier): ";
    cin >> band3;
    cout << "Band 4 (tolerance, or type 'none'): ";
    cin >> band4;

    if (!digit_value.count(band1) || !digit_value.count(band2) || !multiplier_value.count(band3)) {
        cout << "didn't recognize one of those colors, check spelling\n";
        return;
    }

    double value = (digit_value[band1] * 10 + digit_value[band2]) * multiplier_value[band3];
    cout << "Resistance = " << value << " ohms";

    if (tolerance_value.count(band4)) {
        cout << " +/- " << tolerance_value[band4] << "%";
    }
    cout << "\n";
}

int main() {
    while (true) {
        cout << "\n=== Circuit Calculator Toolkit ===\n";
        cout << "1. Ohm's Law Solver\n";
        cout << "2. Series/Parallel Resistance\n";
        cout << "3. Resistor Color Code Decoder\n";
        cout << "4. Exit\n";
        cout << "> ";

        int choice;
        cin >> choice;

        if (choice == 1) ohms_law();
        else if (choice == 2) resistor_network();
        else if (choice == 3) resistor_color_code();
        else if (choice == 4) { cout << "later.\n"; break; }
        else cout << "not a valid option\n";
    }
    return 0;
}
