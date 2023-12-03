#include<bits/stdc++.h>
// Programa para resolver advent of code 2023 Dia 1
std::priority_queue<int> cola_prioridad;
std::map<int,int> map_;
std::map<int,std::string> pare_numero;
std::map<std::string,int> numero_;

int main(int argc, char *argv[])
{
    
    int num = 0;
    std::string line;
    long long sum=0;
         numero_["one"] = 1;
        numero_["two"] = 2;
        numero_["three"] = 3;
        numero_["four"] = 4;
        numero_["five"] = 5;
        numero_["six"] = 6;
        numero_["seven"] = 7;
        numero_["eight"] = 8;
        numero_["nine"] = 9;
    while(std::getline(std::cin, line))
    {   
    std::deque<std::pair<long long,long long>> lista_doble;
        int contador = 0;
        std::cout << "\n" <<  line << "\n";
        for(auto i:line){
            if(isdigit(i)){
                lista_doble.push_back(std::make_pair(atoi(&i),contador));
            }
            contador++;
        }
        for(auto i :numero_){
            size_t ind = line.find(i.first);   
            bool lol = true;    
            if( ind != std::string::npos && (lista_doble.empty() || ind < lista_doble.front().second)){
               lista_doble.push_front(std::make_pair(i.second, ind));
               lol = false;
            }
            size_t ind_f = line.rfind(i.first);
            if((lol || ind_f != ind) && ind_f != std::string::npos && (lista_doble.empty() || ind_f > lista_doble.back().second)){
                lista_doble.push_back(std::make_pair(i.second, ind_f));
            }
        }
          if(lista_doble.size() >= 2){
           sum += 10*lista_doble.front().first + lista_doble.back().first;
            std::cout << lista_doble.front().first <<  " " <<  lista_doble.back().first << "\n";
        }else{
           sum += 10*lista_doble.front().first + lista_doble.front().first;
             std::cout << lista_doble.front().first << " \n";
        }
    }
    std::cout << sum << "\n";
    return 0;
}