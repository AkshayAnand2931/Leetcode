#include <iostream>

void pattern1(int n) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++){
            std::cout << "*";
        }
        std::cout << std::endl;
    }
}

void pattern2(int n) {
    for(int i = 0; i < n; i++) {
        for (int j = 0; j < i + 1; j++) {
            std::cout << "*";
        }
        std::cout << std::endl;
    }
}

void pattern3(int n) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < i + 1; j++) {
            std::cout << j + 1;
        }
        std::cout << std::endl;
    }
}

void pattern4(int n) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < i + 1; j++) {
            std::cout << i + 1;
        }
        std::cout << std::endl;
    }
}

void pattern5(int n) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n - i; j++) {
            std::cout << "*";
        }
        std::cout << std::endl;
    }
}

void pattern6(int n) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n - i; j++) {
            std::cout << j + 1;
        }
        std::cout << std::endl;
    }
}

void pattern7(int n) {
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n - i - 1; j++) {
            std::cout << " ";
        }
        for(int j = 0; j < 2 * i + 1; j++) {
            std::cout << "*";
        }
        for(int j = 0; j < n - 1; j++) {
            std::cout << " ";
        }
        std::cout << std::endl;
    }
}

void pattern8(int n) {
    for(int i = 0; i < n; i++){
        for(int j = 0; j < i; j++) {
            std::cout << " ";
        }
        for(int j = 0; j < 2 * (n - 1) + 1; j++) {
            std::cout << "*";
        }
        for(int j = 0; j < i; j++) {
            std::cout << " ";
        }
        std::cout << std::endl;
    }
}

void pattern9(int n) {
    for(int i = 0; i < 2 * n + 1; i++) {
        int stars = i;
        if (i > n) stars = 2*n - i;
        for(int j = 0; j < i + 1; j++) {
            std::cout << "*";
        }
        std::cout << std::endl;
    }
}

void pattern10(int n) {
    int start = 1;
    for(int i = 0; i < n; i++) {
        if(i % 2 == 0) start = 1;
        else start = 0;
        for (int j = 0; j < i + 1; j++) {
            std::cout << start;
            start = 1 - start;
        }
        std::cout << std::endl;
    }
}

void pattern11(int n) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < i + 1; j++) {
            std::cout << j + 1;
        }
        for(int j = 0; j < (n - i + 1) * 2; j++) {
            std::cout << " ";
        }
        for(int j = i + 1; j > 0; j--) {
            std::cout << j;
        }
        std::cout << std::endl;
    }
}

void pattern12(int n) {
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n - i; j++) {
            std::cout << "*";
        }
        for(int j = 0; j < i * 2; j++) {
            std::cout << " ";
        }
        for(int j = 0; j < n - i; j++) {
            std::cout << "*";
        }
        std::cout << std::endl;
    }
}

int main() {
    return 0;
}

