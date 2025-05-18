/*Una fábrica de componentes electrónicos necesita optimizar su producción para cumplir con la demanda de cinco productos distintos.
Cada producto tiene un tiempo de fabricación específico y requiere una cantidad fija de recursos. El equipo de ingeniería ha
identificado que la línea de producción tiene limitaciones de tiempo y recursos que deben ser tomadas en cuenta.

1.El tiempo total de fabricación requerido para cumplir con la demanda.
2.La cantidad de recursos necesarios para producir los productos.
3.Si la fábrica puede cumplir con la demanda dada una cantidad limitada de recursos y tiempo de producción disponible.
*/
#include <stdio.h>
#include <string.h>
#include "funciones.h"


int main(int argc, char *argv[])
{
    char producto[5][50];
    int cantidad[5];
    float tiempo[5];
    float tiempoLim[5];
    char nombresInv[5][50];
    int cantInv[5];
    int comProdu[5][5];
    char nombPedidos[10][50];
    int cantPedidos[10];
    int opc, opc1, opc2, cont = 0, contInv = 0, tp, tp1, contPedidos = 0;
    registrarInventario(nombresInv, cantInv, &contInv);
    do
    {
        opc = menu();
        switch (opc)
        {
        case 1:
            tp1 = 1;
            tablaDeInventario(&contInv, nombresInv, cantInv, tp1);
            break;
        case 2:
            registrarProducto(producto, cantidad, tiempo, tiempoLim, comProdu, nombresInv, &cont, &contInv);
            break;
        case 3:
            tp = 1;
            tablaDeProductos(&cont, producto, cantidad, tiempo, tiempoLim, comProdu, nombresInv, &contInv, tp);
            break;
        case 4:
            tp = 2;
            opc1 = tablaDeProductos(&cont, producto, cantidad, tiempo, tiempoLim, comProdu, nombresInv, &contInv, tp);
            editarProducto(&cont, producto, cantidad, tiempo, tiempoLim, nombresInv, comProdu, &contInv, opc1);
            break;
        case 5:
            tp = 3;
            opc1 = tablaDeProductos(&cont, producto, cantidad, tiempo, tiempoLim, comProdu, nombresInv, &contInv, tp);
            eliminarProducto(&cont, producto, cantidad, tiempo, tiempoLim, nombresInv, comProdu, &contInv, opc1);
            break;
        case 6:
            tp = 4;
            opc1 = tablaDeProductos(&cont, producto, cantidad, tiempo, tiempoLim, comProdu, nombresInv, &contInv, tp);
            mostrarResultados(&cont, producto, cantidad, tiempo, tiempoLim, nombresInv, comProdu, cantInv, &contInv, opc1, nombPedidos, cantPedidos, &contPedidos);

            break;
        case 7:
            mostrarPedidos(nombPedidos, cantPedidos, &contPedidos);
            break;
        case 8:
            tp1 = 2;
            opc2 = tablaDeInventario(&contInv, nombresInv, cantInv, tp1);
            reabastecerInv(nombresInv, cantInv, opc2);
            break;
        case 9:
            printf("Gracias por usar el programa\n");
            break;
        default:
            printf("Opcion no valida\n");
            break;
        }
    } while (opc != 9);

    return 0;
}
