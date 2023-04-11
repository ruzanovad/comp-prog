//
// Created by light on 03.08.2022.
//

#include <iostream>
#include <iomanip>
#include <vector>
#include <math.h>

using namespace std;
/*Костя разрабатывает модуль статистики для высоконагруженного сервиса. Накопилось много исторических данных: n вещественных чисел $a_0, a_1, \dots, a_{n-1}$.

Из-за частого обращения к его модулю за вычислением среднего геометрического эту функцию необходимо ускорить!

На вход поступают множество запросов по поиску среднего на интервале индексов от l до r. Найдите необходимые значения.

Для запроса от $l$ до $r$ необходимо вернуть величину:
$ \sqrt[r-l+1]{a_{l} \cdot a_{l+1} \cdot \ldots \cdot a_{r}} $
*/
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, q;
    cin >> n;
    vector<double> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    vector<double> sum(n + 1);
    double s = 0;
    for (int i = 0; i < n; ++i)
    {
        sum[i] = s;
        s += std::log(a[i]);
    }
    sum[n] = s;
    cin >> q;

    while (q--)
    {
        int l, r;
        cin >> l >> r;
        double result;
        result = exp((sum[r+1] - sum[l]) / (double)(r - l + 1));
        cout << setprecision(6) << fixed << result << "\n";
    }
}

// yeah i know...

/* 
Ввод	Вывод
8
79.02 36.68 79.83 76.00 95.48 48.84 49.95 91.91
10
0 0
0 1
0 2
0 3
0 4
0 5
0 6
0 7
1 7
2 7
79.020000
53.837288
61.391865
64.756970
69.986085
65.913194
63.352986
66.369195
64.735454
71.164108
*/
/* 
Ввод	Вывод
8
1.34 1.37 1.40 1.44 1.91 1.95 1.96 1.97
5
1 4
2 7
4 6
0 3
2 6
1.515518
1.752724
1.939879
1.387008
1.712233
*/