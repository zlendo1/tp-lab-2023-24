#include <iostream>

int main() {
    int a, b, c, d;

    std::cout << "Unesite duzinu, sirinu i dubinu bazena u metrima: ";
    std::cin >> a >> b >> c;

    std::cout << "Unesite sirinu plocice u centimetrima: ";
    std::cin >> d;

    int a1 = a * 100, b1 = b * 100, c1 = c * 100;
    int ost_a1 = a1 % d, ost_b1 = b1 % d, ost_c1 = c1 % d;

    if (ost_a1 != 0 || ost_b1 != 0 || ost_c1 % d != 0) {
        int ost_P = 2 * ost_c1 * (ost_a1 + ost_b1) + ost_a1 * ost_b1;
        int ost_N = ost_P / (d * d);

        if (ost_P % (d * d) != 0) {
            ost_N++;
        }

        std::cout << "Poplocavanje bazena dimenzija " << a << "x" << b << "x" << c << "m s plocicama dimenzija " << d << "x" << d << "cm nije izvodljivo bez lomljenja plocica!" << std::endl;
        std::cout << "Ostaje nepoplocana povrsina od " << ost_P << "cm^2, sto zahtjeva " << ost_N << " cijelih plocica koje ce se lomiti." << std::endl;

        return 0;
    }

    int P = 2 * c1 * (a1 + b1) + a1 * b1;
    int N = P / (d * d);

    std::cout << "Za poplocavanje bazena dimenzija " << a << "x" << b << "x" << c << "m s plocicama dimenzija " << d << "x" << d << "cm potrebno je " << N << " plocica.";

    return 0;
}