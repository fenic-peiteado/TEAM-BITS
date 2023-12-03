#include <bits/stdc++.h>

typedef std::vector<std::vector<char>> vi_c;
typedef std::vector<char> li_c;
typedef std::vector<bool> li_b;
typedef std::vector<std::vector<bool>> vi_b;
typedef std::pair<int, int> pa;
void print_map(vi_c mapa) {
  for (auto i : mapa) {
    for (auto j : i) {
      std::cout << j;
    }
    std::cout << std::endl;
  }
}

std::vector<std::pair<int, int>> mov{{1, 1}, {-1, 1}, {1, -1}, {-1, -1},
                                     {0, 1}, {1, 0},  {0, -1}, {-1, 0}};

int find_all_number(pa x_y, vi_b &mapa_b, vi_c mapa_c) {
  std::list<int> numero_l;
  std::string numero_s;
  if (mapa_b[x_y.first][x_y.second] == false) {
    numero_l.push_back((mapa_c[x_y.first][x_y.second]));
    numero_s += (mapa_c[x_y.first][x_y.second]);
    int y = x_y.second;
    mapa_b[x_y.first][y] = true;
    y++;
    while (y < mapa_c[x_y.first].size() && isdigit(mapa_c[x_y.first][y]) &&
           !mapa_b[x_y.first][y]) {
      numero_l.push_back((mapa_c[x_y.first][y]));
      numero_s += (mapa_c[x_y.first][y]);
      mapa_b[x_y.first][y] = true;
      y++;
    }
    y = x_y.second - 1;
    while (y >= 0 && isdigit(mapa_c[x_y.first][y]) && !mapa_b[x_y.first][y]) {
      numero_l.push_back((mapa_c[x_y.first][y]));
      numero_s = (mapa_c[x_y.first][y]) + numero_s;
      mapa_b[x_y.first][y] = true;
      y--;
    }
    std::cout << "-" << numero_s << "-\n";
   int numero_y = stoi(numero_s);
    return numero_y;
  }
  std:: cout << "Algo salio mal\n";
  return 0;
}

void fun1(vi_b mapa_b, vi_c mapa_c) {
  int sum = 0;
  int sum2 = 0;
  for (int i = 0; i < mapa_c.size(); i++) {
    for (int j = 0; j < mapa_c[i].size(); j++) {
      if (!isdigit(mapa_c[i][j]) && mapa_c[i][j] != '.') {
        // Calculamos adyencia
        std::vector<int> ratio;
        for (auto [x, y] : mov) {
          int new_x = i + x;
          int new_y = j + y;
          if (new_x >= 0 && new_y >= 0 && new_x < mapa_c.size() &&
              new_y < mapa_c[i].size() && isdigit(mapa_c[new_x][new_y]) &&
              !mapa_b[new_x][new_y]) {
            //    std::cout << "Numero: " << mapa_c[new_x][new_y] << "\n";
            //    std::cout << "Posicion: " << new_x << " " << new_y << "\n";
            int valor = find_all_number(std::make_pair(new_x, new_y), mapa_b, mapa_c);
            sum += valor;
            ratio.push_back(valor);
          }
        }
        if(ratio.size() == 2){
         sum2+= ratio[0]*ratio[1];   
        }
      }
    }
  }
  std::cout << sum << "\n";
  std::cout << sum2 << "\n";
}

int main() {
  std::string line;
  vi_c mapa;
  vi_b mapa_bool;
  while (std::getline(std::cin, line)) {
    li_c vec_char;
    li_b vec_bool;
    for (auto i : line) {
      vec_char.push_back(i);
    }
    vec_bool.resize(vec_char.size());
    mapa.push_back(vec_char);
    mapa_bool.push_back(vec_bool);
  }
  print_map(mapa);
  fun1(mapa_bool, mapa);
  return 0;
}