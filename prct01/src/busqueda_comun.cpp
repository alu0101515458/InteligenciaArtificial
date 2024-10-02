#include "../include/busqueda_comun.h"

/**
 * @brief Función para insertar un nodo en orden ascendente en un vector.
 * 
 * @param nodos_generados 
 * @param nodo 
 */
void InsertarMenorAMayor(std::vector<int>& nodos_generados, int nodo) {
  // Si el vector está vacío, insertamos el nodo y salimos.
  if (nodos_generados.empty()) {
    nodos_generados.push_back(nodo);
    return;
  }
  // Iteramos sobre el vector para encontrar la posición correcta.
  for (unsigned i = 0; i < nodos_generados.size(); ++i) {
    // Si encontramos un nodo mayor, lo insertamos antes.
    if (nodo < nodos_generados[i]) {
      nodos_generados.insert(nodos_generados.begin() + i, nodo);
      return;
    }
  }
  nodos_generados.push_back(nodo);
}

/**
 * @brief Función para mostrar información de la iteración actual.
 * 
 * @param iteracion 
 * @param nodos_generados 
 * @param nodos_inspeccionados 
 * @param archivo_salida 
 */
void InformacionIteracion(int& iteracion, const std::vector<int>& nodos_generados,
                          const std::vector<int>& nodos_inspeccionados, std::ofstream& archivo_salida) {
  ++iteracion;
  archivo_salida << "Iteración " << iteracion << std::endl;
  archivo_salida << "Nodos Generados: ";
  for (int nodo : nodos_generados) {
    archivo_salida << nodo + 1;  // Mostrar nodos indexados a partir de 1.
    if (nodo != nodos_generados.back()) {
      archivo_salida << ", ";
    }
  }
  archivo_salida << "\nNodos Inspeccionados: ";
  if (nodos_inspeccionados.size() >= 1) {
    for (unsigned i = 0; i < nodos_inspeccionados.size(); ++i) {
      archivo_salida << nodos_inspeccionados[i] + 1;  // Mostrar nodos indexados a partir de 1.
      if (i < nodos_inspeccionados.size() - 1) {
        archivo_salida << ", ";
      }
    }
  } else {
    archivo_salida << "-";
  }
  archivo_salida << std::endl;
  archivo_salida << "──────────────────────────────────────────────────" << std::endl;
}