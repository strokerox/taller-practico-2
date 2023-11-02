#include <iostream>
#include <map>

struct Zona {
    int num_camiones;
    double toneladas;
};

int main() {
    std::map<int, Zona> informacion_zonas;
    double total_basura_recolectada = 0;
    double max_basura = 0;
    int zona_max_basura = 0;

    int num_zona;
    std::string placa_camion;
    double toneladas_basura;

    while (true) {
        std::cout << "Ingrese el número de la zona (ingrese -1 para finalizar): ";
        std::cin >> num_zona;

        if (num_zona == -1) {
            break;
        }

        std::cout << "Ingrese la placa del camión recolector: ";
        std::cin >> placa_camion;

        std::cout << "Ingrese las toneladas de basura recolectadas por el camión: ";
        std::cin >> toneladas_basura;

        if (informacion_zonas.find(num_zona) == informacion_zonas.end()) {
            informacion_zonas[num_zona] = {1, toneladas_basura};
        } else {
            informacion_zonas[num_zona].num_camiones++;
            informacion_zonas[num_zona].toneladas += toneladas_basura;
        }

        total_basura_recolectada += toneladas_basura;

        if (toneladas_basura > max_basura) {
            max_basura = toneladas_basura;
            zona_max_basura = num_zona;
        }
    }

    std::cout << "\n--- Información por zona ---\n";
    for (const auto& kv : informacion_zonas) {
        double promedio = kv.second.toneladas / kv.second.num_camiones;
        std::cout << "Zona " << kv.first << ": " << kv.second.num_camiones << " camiones, "
                  << kv.second.toneladas << " toneladas, promedio: " << promedio << " toneladas\n";
    }

    std::cout << "\n--- Información del Asco Urbano ---\n";
    std::cout << "Toneladas de basura recolectadas por el Asco Urbano: " << total_basura_recolectada << " toneladas\n";
    std::cout << "Zona donde se recolectó más basura: Zona " << zona_max_basura << std::endl;

    return 0;
}

