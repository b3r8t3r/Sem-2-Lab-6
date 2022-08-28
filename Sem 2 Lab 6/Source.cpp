#include <conio.h>
#include <locale.h>
#include <math.h>
#include <stdio.h>

#include <iostream>
#include <iterator>
#include <string>
#include <vector>

using namespace std;

using vector2d = vector<vector<int>>;
using vector1d = vector<int>;

istream& operator>>(istream& in, vector2d& v) {
  for (int i = 0; i < v.size(); ++i) {
    for (int j = 0; j < v[i].size(); ++j) {
      cout << "i = " << i << ", j = " << j << ": ";
      in >> v[i][j];
      cout << endl;
    }
    cout << endl;
  }
  cout << endl;
  return in;
}

ostream& operator<<(ostream& out, const vector2d& v) {
  for (int i = 0; i < v.size(); ++i) {
    for (int j = 0; j < v[i].size(); ++j) {
      out << v[i][j] << " ";
    }
    out << endl;
  }
  return out;
}

istream& operator>>(istream& in, vector1d& v) {
  for (int i = 0; i < v.size(); ++i) {
    cout << "i = " << i << ": ";
    in >> v[i];
    cout << endl;
  }
  cout << endl;
  return in;
}

ostream& operator<<(ostream& out, const vector1d& v) {
  out;
  for (int i = 0; i < int(v.size()); ++i) {
    out << v[i] << " ";
  }
  out << endl;
  return out;
}

void zadacha1_1() {
  vector2d p;
  int height, width, str_num = 0;
  bool is_even = true;

  cout << "Введите размерность массива (Высоту и ширину): " << endl;
  cin >> height >> width;

  p.resize(height);
  for (int i = 0; i < height; ++i) {
    p[i].resize(width);
  }

  cout << "Введите элементы массива: " << endl;
  cin >> p;

  for (int i = 0; i < int(p.size()); i++) {
    /*for (int j = 0; j < int(p[i].size()); i++) {
        if ((p[i][j] % 2) == 1) {
            is_even = false;
            break;
        }
    }*/

    for (const auto& element : p[i])  // element - это константная ссылка на
                                      // текущий элемент массива в итерации
      if ((element % 2) == 1) {
        is_even = false;
        break;
      }

    if (is_even) str_num = i;
    is_even = true;
  }

  cout << "Str_num = " << str_num << " в пределах (0 - " << (height - 1) << ")"
       << endl;

  cout << p;
}

void zadacha1_2() {
  vector2d p;
  int height;
  bool stop = false;

  cout << "Введите размерность массива (Высоту): " << endl;
  cin >> height;

  p.resize(height);
  for (int i = 0; i < height; ++i) {
    p[i].resize(height);
  }

  /*cout << "Введите элементы массива: " << endl;
  cin >> p;*/

  for (int i = 0; i < height; i++)
    for (int j = 0; j < height; j++) p[i][j] = 1;

  cout << p << endl;

  for (int i = 0; i < height; i++) {
    for (int j = 0; j < height; j++) {
      p[i][j] = ((i >= j) || (j <= (height - i - 1))) ? 0 : p[i][j];
    }
  }

  cout << p << endl;
}

// void zadacha1_3() {
//     vector2d p;
//     vector1d width,bufer;
//     int height,sum = 0,count = 0;
//     cout << "Введите размерность массива (Высоту): " << endl;
//     cin >> height;
//     width.resize(height);
//     cout << "Введите размерность каждой из строк массива (ширину): " << endl;
//     cin >> width;
//
//     for (int j = 1; j < int(width.size()); j++) {
//         for (int i = 0; i < int(width.size()); i++) {
//             if (width[i] > width[j]) {
//                 int sml_bufer = width[i];
//                 width[i] = width[j];
//                 width[j] = sml_bufer;
//             }
//         }
//     }
//
//     p.resize(height);
//     for (int i = 0; i < height; ++i) {
//         p[i].resize(width[i]);
//     }
//
//     for (int i = 0; i < height; ++i) {
//         sum += width[i];
//     }
//
//     for (int i = 0; i < height; i++)
//         for (int j = 0; j < width[i]; j++) {
//             p[i][j] = sum - count;
//             count++;
//         }
//
//     cout << p;
//
// }

void zadacha1_3() {
  vector2d p;
  vector1d max;
  int height, width, sum = 0, count = 0;

  cout << "Введите размерность массива (Высоту и ширину): " << endl;
  cin >> height >> width;

  p.resize(height);
  for (int i = 0; i < height; ++i) {
    p[i].resize(width);
  }

  for (int i = 0; i < height; i++) {
    for (auto& element : p[i]) {
      element = int(rand() % 20 - 10);
    }
  }

  cout << "Начальный двумерный массив: " << endl << p << endl;

  max.resize(height);
  for (int i = 0; i < height; i++) max[i] = p[i][0];

  /*cout << "Инициализация max: " << endl << max << endl;*/

  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      if (abs(p[i][j]) > abs(max[i])) max[i] = p[i][j];
    }
  }

  /*cout << "Максимальные по модулю элементы: " << endl << max << endl;*/

  for (int j = 1; j < height; j++)
    for (int i = 0; i < height - 1; i++) {
      if (abs(max[i]) > abs(max[j])) {
        int sml_bufer;
        vector1d bufer;

        sml_bufer = max[i];
        max[i] = max[j];
        max[j] = sml_bufer;

        bufer = p[i];
        p[i] = p[j];
        p[j] = bufer;
      }
    }

  /* cout << "Для сравнения: " << endl;
   cout << max << endl;*/
  cout << "Конечный двумерный массив: " << endl;
  cout << p << endl;
}

string str, code, crypt, decrypt;

string Visiner_Encrypt(string message, string key) {
  int keyLen = key.size();

  for (int i = 0, j = 0; i < message.size(); i++) {
    if (message[i] > 64 && message[i] < 91) {
      message[i] += key[j % keyLen] - 'a';
      j++;
      if (message[i] > 90) message[i] -= 26;
    } else if (message[i] > 96 && message[i] < 123) {
      message[i] -= 32;
      message[i] += key[j % keyLen] - 'a';
      j++;
      if (message[i] > 90) {
        message[i] -= 26;
      }
      message[i] += 32;
    }
  }
  return message;
}

string Visiner_Decrypt(string message, string key) {
  int keyLen = key.size();
  for (int i = 0, j = 0; i < message.size(); i++) {
    if (message[i] > 64 && message[i] < 91) {
      message[i] -= key[j % keyLen] - 'a';
      j++;
      if (message[i] < 65) message[i] += 26;
    } else if (message[i] > 96 && message[i] < 123) {
      message[i] -= 32;
      message[i] -= key[j % keyLen] - 'a';
      j++;
      if (message[i] < 65) message[i] += 26;

      message[i] += 32;
    }
  }
  return message;
}

void Visiner_in() {
  cout << "Введите шифруемое сообщение: " << endl;
  getline(cin, str);

  cout << "Введите ключ шифрования:\n: ";
  getline(cin, code);

  crypt = Visiner_Encrypt(str, code);
  cout << "Зашифрованное сообщение: " << crypt << endl;
}

void Visiner_out() {
  // cout << "Введите дешифруемое сообщение: " << endl;
  // getline(cin, str);

  // cout << "Введите ключ дешифрования:\n: ";
  // getline(cin, code);

  decrypt = Visiner_Decrypt(crypt, code);
  cout << "Расшифрованное сообщение: " << decrypt << endl;
}

void zadacha2() {
  Visiner_in();
  Visiner_out();
}

int main() {
  setlocale(LC_ALL, "");
  zadacha2();

  // cout << (5 & 0) ? "&1\n" : "!&1\n";

  return 0;
}