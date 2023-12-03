#include<bits/stdc++.h>
// Programa para resolver advent of code 2023 Dia 1
std::priority_queue<int> cola_prioridad;
std::map<int,int> map_;
std::map<int,std::string> pare_numero;
std::map<std::string,int> numero_;

int main(int argc, char *argv[])
{
    std::string line;
    int num_rojo = 12;
    int num_verde = 13;
    int num_azul = 14;
    int contador = 1;
    int  sum = 0;
    int sum2 = 0;
    while(std::getline(std::cin, line))
    {   
        std::regex patron_conjunto(":.*");
        std::regex rojo(("(\\d)+ red"));
        std::regex verde(("(\\d)+ green"));
        std::regex azul(("(\\d)+ blue"));
        std::regex numero("(\\d)+");
        std::regex game("Game (\\d)+");
        std::smatch match;
       // if(std::regex_search(line,match,patron_conjunto)){
       //     std::string game = match[0].str();
       //     std::cout << game << "\n";
      //  }
        std::sregex_iterator it(line.begin(), line.end(), rojo);
        std::sregex_iterator end;
        bool sigue = true;
        int numero_rojo_min = 1;
        int numero_verde_min = 1;
        int numero_azul_min = 1;
        while((it != end) && sigue){
            std::smatch match = *it;
            std::string line_rojo = match[0].str();
            std::regex_search(line_rojo,match,numero);
            int numero = stoi(match[0].str());
           // if(numero > num_rojo){
           //     sigue = false;
           // }
            if(numero > numero_rojo_min){
                numero_rojo_min = numero;
            }
        
            it++;
        }
        it = std::sregex_iterator(line.begin(), line.end(), verde);
        while((it != end) && sigue){
            std::smatch match = *it;
            std::string line_rojo = match[0].str();
            std::regex_search(line_rojo,match,numero);
            int numero = stoi(match[0].str());
           //  if(numero > num_verde){
           //     sigue = false;
           // }
            if(numero > numero_verde_min){
                numero_verde_min = numero;
            }
            it++;
        }
        it = std::sregex_iterator(line.begin(), line.end(), azul);
        while((it != end) && sigue){
            std::smatch match = *it;
            std::string line_rojo = match[0].str();
            std::regex_search(line_rojo,match,numero);
            int numero = stoi(match[0].str());
        //    if(numero > num_azul){
        //        sigue = false;
        //    }
        if(numero > numero_azul_min){
                numero_azul_min = numero;
            }
            it++;
        }
        if(sigue){
            sum +=contador;
            std::cout  << contador << " " << line << "\n";
        }
        it = std::sregex_iterator(line.begin(), line.end(), game);
        int numero_aux = stoi((*it)[1].str());
        contador++;
        sum2+=numero_azul_min*numero_rojo_min*numero_verde_min;
        std::cout << "\n";
    }
    std::cout << sum << "\n";
    std::cout << sum2 << "\n";
    return 0;
}