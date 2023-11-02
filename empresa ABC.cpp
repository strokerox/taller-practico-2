#include <iostream>
#include <map>

struct Cliente {
    int cantBloquesCemento;
    int cantBloquesArcilla;
    double montoSinDescuento;
    double montoDescuento;
};

int main() {
    std::map<int, Cliente> informacionClientes;
    int totalBloquesCemento = 0;
    int totalBloquesArcilla = 0;
    int codigoClienteMayorCompra = 0;
    double montoMayorCompra = 0;
    double totalComprasSinDescuento = 0;
    double totalDescuento = 0;
    int totalBloques = 0;

    while (true) {
        int codigoCliente;
        std::string tipoBloque;
        int cantidadBloques;
        int tiempoCliente;

        std::cout << "\n--- Ingrese los datos de una venta (Ingrese -1 como código del cliente para finalizar) ---\n";
        std::cout << "Código del cliente: ";
        std::cin >> codigoCliente;

        if (codigoCliente == -1) {
            break;
        }

        std::cout << "Tipo de bloque (arcilla/cemento): ";
        std::cin >> tipoBloque;

        std::cout << "Cantidad de bloques comprados: ";
        std::cin >> cantidadBloques;

        std::cout << "Tiempo que tiene el cliente comprando bloques en la empresa (en años): ";
        std::cin >> tiempoCliente;

        double precioBloque;
        if (tipoBloque == "arcilla") {
            precioBloque = 230;
            totalBloquesArcilla += cantidadBloques;
        } else if (tipoBloque == "cemento") {
            precioBloque = 350;
            totalBloquesCemento += cantidadBloques;
        } else {
            std::cout << "Tipo de bloque inválido. Los datos de esta venta no serán procesados.\n";
            continue;
        }

        double montoSinDescuento = cantidadBloques * precioBloque;
        double montoDescuento = 0;
        if (tiempoCliente > 3) {
            montoDescuento = montoSinDescuento * 0.03;
            montoSinDescuento -= montoDescuento;
        }

        totalComprasSinDescuento += montoSinDescuento;
        totalDescuento += montoDescuento;
        totalBloques += cantidadBloques;

        if (informacionClientes.find(codigoCliente) == informacionClientes.end()) {
            informacionClientes[codigoCliente] = {0, 0, montoSinDescuento, montoDescuento};
        }

        if (montoSinDescuento > montoMayorCompra) {
            codigoClienteMayorCompra = codigoCliente;
            montoMayorCompra = montoSinDescuento;
        }

        Cliente& cliente = informacionClientes[codigoCliente];
        if (tipoBloque == "arcilla") {
            cliente.cantBloquesArcilla += cantidadBloques;
        } else if (tipoBloque == "cemento") {
            cliente.cantBloquesCemento += cantidadBloques;
        }
    }

    double porcentajeArcilla = (totalBloquesArcilla / static_cast<double>(totalBloques)) * 100;
    double porcentajeCemento = (totalBloquesCemento / static_cast<double>(totalBloques)) * 100;

    std::cout << "\n--- Información por cliente ---\n";
    for (const auto& kv : informacionClientes) {
        std::cout << "Cliente " << kv.first << ":\n";
        std::cout << "- Cantidad de bloques de cemento comprados: " << kv.second.cantBloquesCemento << std::endl;
        std::cout << "- Cantidad de bloques de arcilla comprados: " << kv.second.cantBloquesArcilla << std::endl;
        std::cout << "- Monto total de las compras sin descuento: " << kv.second.montoSinDescuento << " Bs." << std::endl;
        std::cout << "- Monto total del descuento: " << kv.second.montoDescuento << " Bs." << std::endl;
    }

    std::cout << "\n--- Información de la empresa ---\n";
    std::cout << "- Código del cliente con mayor monto total de compras: Cliente " << codigoClienteMayorCompra
              << ", monto: " << montoMayorCompra << " Bs." << std::endl;
    std::cout << "- Porcentaje de bloques de arcilla vendidos: " << porcentajeArcilla << "%" << std::endl;
    std::cout << "- Porcentaje de bloques de cemento vendidos: " << porcentajeCemento << "%" << std::endl;

    return 0;
}
