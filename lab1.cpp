#include <iostream>
#include <chrono>
#include <string>

using namespace std;
using namespace chrono;

const long long op_am_ = 10000000;

template <typename T>
T empty() {
    T a1, a2 = static_cast<T>(2), a3 = static_cast<T>(3), a4 = static_cast<T>(4), a5 = static_cast<T>(5), a6 = static_cast<T>(6), a7 = static_cast<T>(7), a8 = static_cast<T>(8), a9 = static_cast<T>(9), a10 = static_cast<T>(10);
    auto begin = high_resolution_clock::now();
    for (long long i = 0; i < op_am_; i++) {
        a1 = a2, a2 = a3, a3 = a4, a4 = a5, a5 = a6, a6 = a7, a7 = a8, a8 = a9, a9 = a10, a10 = a1;
    }
    auto end = high_resolution_clock::now();
    return (end - begin).count();
}

template <typename T>
T perform_operation(const T& param1, const T& param2, long long t, char operation) {
    T a1 = param1, a2 = param2, a3, a4, a5, a6, a7, a8, a9, a10;
    auto begin = high_resolution_clock::now();
    for (long long i = 0; i < op_am_; i++) {
        switch (operation) {
        case '+':
            a3 = a1 + a2;
            break;
        case '-':
            a3 = a1 - a2;
            break;
        case '*':
            a3 = a1 * a2;
            break;
        case '/':
            a3 = a1 / a2;
            break;
        }
        a4 = a2 + a3;
        a5 = a3 + a4;
        a6 = a4 + a5;
        a7 = a5 + a6;
        a8 = a6 + a7;
        a9 = a7 + a8;
        a10 = a8 + a9;
        a1 = a9 + a10;
        a2 = a10 + a1;
    }
    auto end = high_resolution_clock::now();
    return (double)(op_am_ * 1e10 / ((end - begin).count() - t));
}

int main() {

    long long time_int = empty<int>();
    long long time_long = empty<long>();
    long long time_long_long = empty<long long>();
    long long time_float = empty<float>();
    long long time_double = empty<double>();
    long long time_char = empty<char>();

    double data[24];

    data[1] = perform_operation<int>(13859, 2, time_int, '+');
    data[0] = perform_operation<int>(3, 2, time_int, '-');
    data[2] = perform_operation<int>(3, 2, time_int, '*');
    data[3] = perform_operation<int>(123456789, 4, time_int, '/');

    data[4] = perform_operation<long>(5589, 3442, time_long, '+');
    data[5] = perform_operation<long>(8569731, 1473, time_long, '-');
    data[6] = perform_operation<long>(32, 11, time_long, '*');
    data[7] = perform_operation<long>(8500000, 3, time_long, '/');

    data[8] = perform_operation<long long>(456852, 12659, time_long_long, '+');
    data[9] = perform_operation<long long>(55873695, 1149755, time_long_long, '-');
    data[10] = perform_operation<long long>(6597, 8, time_long_long, '*');
    data[11] = perform_operation<long long>(3900001000, 4, time_long_long, '/');

    data[12] = perform_operation<float>(1.489, 2.202, time_float, '+');
    data[13] = perform_operation<float>(1.034, 2.98345, time_float, '-');
    data[14] = perform_operation<float>(1.5864, 2.123, time_float, '*');
    data[15] = perform_operation<float>(9876543.267, 21.645556, time_float, '/');

    data[16] = perform_operation<double>(1.98765432134, 2.511156555, time_double, '+');
    data[17] = perform_operation<double>(1.87654345678, 2.656655, time_double, '-');
    data[18] = perform_operation<double>(1.123457, 2.121103121, time_double, '*');
    data[19] = perform_operation<double>(3684843.1231, 18.4738473847, time_double, '/');

    data[20] = perform_operation<int>(10, 5, time_char, '+');
    data[21] = perform_operation<int>(20, 4, time_char, '-');
    data[22] = perform_operation<int>(30, 2, time_char, '*');
    data[23] = perform_operation<int>(40, 3, time_char, '/');

    double max = 0;
    for (int i = 0; i < 24; i++) {
        if (data[i] > max) {
            max = data[i];
        }
    }

    char opers[4] = { '+', '-', '*', '/' };
    string types[6] = { "   int   ", "  long   ", "long long", "  float  ", " double  ", "   char  " };

    cout << "------------------------------------------------------------------------------------------" << endl;
    cout << "| Op |   Type   |     Speed    |                 Bar                           |Percentage|" << endl;
    cout << "------------------------------------------------------------------------------------------" << endl;

    for (int i = 0; i < 24; i++) {
        if (i % 4 == 0) {
            cout << "--------------------------------------------------------------------------------------------" << endl;
        }

        cout << "| " << opers[i % 4] << " | " << types[i / 4] << " | " << data[i] << " | ";

        int bar_length = int(50 * (data[i] / max));
        for (int j = 0; j < bar_length; j++) {
            cout << 'X';
        }
        for (int j = 0; j < 50 - bar_length; j++) {
            cout << ' ';
        }

        cout << " | " << int(100 * (data[i] / max)) << "% |" << endl;
    }
    cout << "--------------------------------------------------------------------------------------------" << endl;

    return 0;
}
