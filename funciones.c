#include <stdio.h>
#include <string.h>
#include "funciones.h"
int registrarInventario(char nombresInv[5][50], int cantInv[5], int *contInv)
{
    int v;
    printf("======================BIENVENIDO AL PROGRAMA STOCKRO======================\n");
    printf("Porfavor para inciar porfavor registre primero los articulos que tiene en su inventario\n");
    for (int i = *contInv; i < 5; i++)
    {
        printf("Ingrese el nombre del elemento %d de su inventario: ", i + 1);
        fflush(stdin);
        fgets(nombresInv[i], 50, stdin);
        nombresInv[i][strcspn(nombresInv[i], "\n")] = 0;
        do
        {
            printf("Ingrese la cantidad de %s disponible: ", nombresInv[i]);
            v = scanf("%d", &cantInv[i]);
            if (v != 1)
            {
                printf("Error al ingresar la cantidad, se deben ingresar solo numeros enteros\n");
                while (getchar() != '\n');
            }
            else if (cantInv[i] < 0)
            {
                printf("La cantidad no puede ser negativa\n");
            }
        } while (v != 1 || cantInv[i] < 0);

        (*contInv)++;
        if (*contInv >= 5)
        {
            printf("\nEl inventario ha alcanzado su capacidad maxima\n");
            break;
        }
    }

    printf("Inventario registrado correctamente\n");
}

int tablaDeInventario(int *contInv, char nombresInv[5][50], int cantInv[5], int tp1)
{
    if (*contInv < 1)
    {
        printf("No hay un inventario registrado\n");
        return 0;
    }
    int v, opc2;
    printf("-------------------------------------------------------------\n");
    printf("| #  | Nombre del componente             | Stock            |\n");
    printf("-------------------------------------------------------------\n");
    for (int i = 0; i < *contInv; i++)
    {
        printf("| %-2d | %-32s | %-16d |\n", i + 1, nombresInv[i], cantInv[i]);
    }
    printf("-------------------------------------------------------------\n");

    if (tp1 == 2)
    {
        do
        {
            printf("Seleccione el componente a reabastecer: ");
            fflush(stdin);
            v = scanf("%d", &opc2);
            if (v != 1)
            {
                printf("Error al ingresar el componente. Debe ser un numero entero.\n");
            }
            else if (opc2 < 0)
            {
                printf("No se admiten cantidades negativas\n");
            }
        } while (v != 1 || opc2 < 0);
        return opc2;
    }
}
int menu()
{
    int opc, v1;
    printf("\n****MENU DE STOCKRO****\n");
    printf("1. Ingresar inventario\n");
    printf("2. Mostrar Inventario\n");
    printf("3. Registrar un producto\n");
    printf("4. Mostrar informacion del producto\n");
    printf("5. Edicion de un producto\n");
    printf("6. Eliminar un producto\n");
    printf("7. Seleccionar producto a producir\n");
    printf("8. Mostrar pedidos realizados\n");
    printf("9. Reabastecer inventario\n");
    printf("10. Salir\n");
    printf(">>>");
    do
    {
        fflush(stdin);
        v1 = scanf("%d", &opc);
        if (v1 != 1)
        {
            printf("Error al ingresar la opcion\n");
        }
    } while (v1 > 1 & v1 < 9);
    return opc;
}
void registrarProducto(char producto[5][50], int cantidad[5], float tiempo[5], float tiempoLim[5], int comProdu[5][5], char nombresInv[5][50], int *cont, int *contInv)
{
    if (*cont >= 5)
    {
        printf("No se pueden ingresar mas productos.\n");
        return;
    }
    if (*contInv < 1)
    {
        printf("No hay un inventario registrado\n");
        return;
    }
    int v, v2, v3, v4;
    printf("Ingrese el nombre del producto:\n");
    fflush(stdin);
    fgets(producto[*cont], 50, stdin);
    producto[*cont][strcspn(producto[*cont], "\n")] = 0;

    do
    {
        printf("Ingrese el tiempo de fabricacion para cada producto (En horas):\n");
        fflush(stdin);
        v = scanf("%f", &tiempo[*cont]);
        if (v != 1)
        {
            printf("Error al ingresar el tiempo de fabricacion. Debe ser un numero entero\n");
        }
        else if (tiempo[*cont] < 0)
        {
            printf("No se admiten tiempos de fabricacion negativos\n");
        }
    } while (v != 1 || tiempo[*cont] < 0);
    printf("Ingrese la cantidad de recursos necesarios para cada producto:\n");
    for (int i = 0; i < *contInv; i++)
    {
        do
        {
            printf("%s: ", nombresInv[i]);
            v2 = scanf("%d", &comProdu[*cont][i]);
            if (v2 != 1)
            {
                printf("Error al ingresar la cantidad de recursos. Debe ser un numero entero\n");
                while (getchar() != '\n')
                    ;
            }
            else if (comProdu[*cont][i] < 0)
            {
                printf("No se admiten recursos negativos\n");
            }
        } while (v2 != 1 || comProdu[*cont][i] < 0);
    }

    printf("Producto %d ingresado con exito.\n", *cont + 1);
    (*cont)++;
}
int tablaDeProductos(int *cont, char producto[5][50], int cantidad[5], float tiempo[5], float tiempoLim[5], int comProdu[5][5], char nombresInv[5][50], int *contInv, int tp)
{
    if (*cont < 1)
    {
        printf("No hay productos ingresados\n");
        return 0;
    }

    int opc1, v1;

    printf("--Lista de productos--\n");
    printf("---------------------------------------------------\n");
    printf("| # | Nombre              | Tiempo Fab. (h) |\n");
    printf("---------------------------------------------------\n");

    for (int i = 0; i < *cont; i++)
    {
        printf("| %-2d | %-18s | %-15.2f |\n", i + 1, producto[i], tiempo[i]);
    }
    printf("-------------------------------------------------------------------------------\n");
    printf("\n-- Componentes necesarios por producto --\n");
    for (int i = 0; i < *cont; i++)
    {
        printf("Producto %d (%s):\n", i + 1, producto[i]);
        for (int j = 0; j < *contInv; j++)
        {
            printf("  - %s: %d\n", nombresInv[j], comProdu[i][j]);
        }
        printf("\n");
    }

    if (tp != 1)
    {
        do
        {
            if (tp == 2)
            {
                printf("Seleccione el producto a editar: ");
            }
            if (tp == 3)
            {
                printf("Seleccione el producto a eliminar: ");
            }
            if (tp == 4)
            {
                printf("Seleccione el producto a fabricar: ");
            }
            fflush(stdin);
            v1 = scanf("%d", &opc1);
            if (v1 != 1)
            {
                printf("Error al ingresar la opcion. Por favor, ingrese numeros enteros (1-%d)\n", *cont);
            }
            if (opc1 < 1 || opc1 > *cont)
            {
                printf("Error, ese numero de producto no esta registrado\n");
            }
        } while (opc1 < 1 || opc1 > *cont || v1 != 1);
        return opc1;
    }
}

int editarProducto(int *cont, char producto[5][50], int cantidad[5], float tiempo[5], float tiempoLim[5], char nombresInv[5][50], int comProdu[5][5], int *contInv, int opc1)
{
    if (*cont < 1)
    {
        printf("No hay productos ingresados\n");
        return 0;
    }
    int v, ind, v3, v1, v4, v2, v5, v6, v7, v8, n = opc1 - 1;
    printf("Que desea editar?\n");
    printf("1. Nombre: %s\n", producto[n]);
    printf("2. Tiempo de produccion por unidad de producto: %.2f\n", tiempo[n]);
    printf("3. %s: %d\n", nombresInv[0], comProdu[n][0]);
    printf("4. %s: %d\n", nombresInv[1], comProdu[n][1]);
    printf("5. %s: %d\n", nombresInv[2], comProdu[n][2]);
    printf("6. %s: %d\n", nombresInv[3], comProdu[n][3]);
    printf("7. %s: %d\n", nombresInv[4], comProdu[n][4]);
    do
    {
        printf("Ingrese una opcion: ");
        fflush(stdin);
        v = scanf("%d", &ind);
        if (v != 1)
        {
            printf("Error, ingrese un valor entero\n");
        }
        if (ind < 1 || ind > 4)
        {
            printf("Error, valor no valido\n");
        }
    } while (v != 1 || ind < 1 || ind > 9);
    if (ind == 1)
    {
        printf("Ingrese el nuevo nombre del producto: ");
        fflush(stdin);
        fgets(producto[opc1 - 1], 50, stdin);
        producto[opc1 - 1][strcspn(producto[opc1 - 1], "\n")] = 0;
        printf("Modificacion realizada con exito");
    }
    else if (ind == 2)
    {
        do
        {
            printf("Ingrese el nuevo tiempo de fabricacion para cada producto:\n");
            fflush(stdin);
            v1 = scanf("%f", &tiempo[opc1 - 1]);
            if (v1 != 1)
            {
                printf("Error al ingresar el tiempo de fabricacion. Debe ser un numero entero\n");
            }
            else if (tiempo[opc1 - 1] < 0)
            {
                printf("No se admiten tiempos de fabricacion negativos.\n");
            }
        } while (v1 != 1 || tiempo[opc1 - 1] < 0);
        printf("Modificacion realizada con exito");
    }
    else if (ind == 3)
    {
        do
        {
            printf("Ingrese la nueva cantidad de %s necesarios para cada producto:\n", nombresInv[0]);
            fflush(stdin);
            v2 = scanf("%d", &comProdu[n][0]);
            if (v2 != 1)
            {
                printf("Error al ingresar la cantidad de recursos. Debe ser un numero entero.\n");
            }
            else if (comProdu[n][0] < 0)
            {
                printf("No se admiten recursos negativos.\n");
            }
        } while (v2 != 1 || comProdu[n][0] < 0);
        printf("Modificacion realizada con exito");
    }
    else if (ind == 4)
    {
        do
        {
            printf("Ingrese la nueva cantidad de %s necesarios para cada producto:\n", nombresInv[1]);
            fflush(stdin);
            v5 = scanf("%d", &comProdu[n][1]);
            if (v5 != 1)
            {
                printf("Error al ingresar la cantidad de recursos. Debe ser un numero entero.\n");
            }
            else if (comProdu[n][1] < 0)
            {
                printf("No se admiten recursos negativos.\n");
            }
        } while (v5 != 1 || comProdu[n][1] < 0);
        printf("Modificacion realizada con exito");
    }
    else if (ind == 5)
    {
        do
        {
            printf("Ingrese la nueva cantidad de %s necesarios para cada producto:\n", nombresInv[2]);
            fflush(stdin);
            v6 = scanf("%d", &comProdu[n][2]);
            if (v6 != 1)
            {
                printf("Error al ingresar la cantidad de recursos. Debe ser un numero entero.\n");
            }
            else if (comProdu[n][2] < 0)
            {
                printf("No se admiten recursos negativos.\n");
            }
        } while (v6 != 1 || comProdu[n][2] < 0);
        printf("Modificacion realizada con exito");
    }
    else if (ind == 6)
    {
        do
        {
            printf("9. %s: %d\n", nombresInv[n], comProdu[n][4]);
            printf("Ingrese la nueva cantidad de %s necesarios para cada producto:\n", nombresInv[3]);
            fflush(stdin);
            v7 = scanf("%d", &comProdu[n][3]);
            if (v7 != 1)
            {
                printf("Error al ingresar la cantidad de recursos. Debe ser un numero entero.\n");
            }
            else if (comProdu[n][3] < 0)
            {
                printf("No se admiten recursos negativos.\n");
            }
        } while (v7 != 1 || comProdu[n][3] < 0);
        printf("Modificacion realizada con exito");
    }
    else if (ind == 7)
    {
        do
        {
            printf("Ingrese la nueva cantidad de %s necesarios para cada producto:\n", nombresInv[4]);
            fflush(stdin);
            v8 = scanf("%d", &comProdu[n][4]);
            if (v8 != 1)
            {
                printf("Error al ingresar la cantidad de recursos. Debe ser un numero entero.\n");
            }
            else if (comProdu[n][4] < 0)
            {
                printf("No se admiten recursos negativos.\n");
            }
        } while (v8 != 1 || comProdu[n][4] < 0);
        printf("Modificacion realizada con exito");
    }
}
int eliminarProducto(int *cont, char producto[5][50], int cantidad[5], float tiempo[5], float tiempoLim[5], char nombresInv[5][50], int comProdu[5][5], int *contInv, int opc1)
{
    if (*cont == 0)
    {
        printf("No hay productos registrados para eliminar.\n");
        return 0;
    }
    int index = opc1 - 1;
    if (index < 0 || index >= *cont)
    {
        printf("Indice no valido.\n");
        return 0;
    }
    for (int i = index; i < *cont - 1; i++)
    {
        strcpy(producto[i], producto[i + 1]);
        cantidad[i] = cantidad[i + 1];
        tiempo[i] = tiempo[i + 1];
        tiempoLim[i] = tiempoLim[i + 1];

        for (int j = 0; j < *contInv; j++)
        {
            comProdu[i][j] = comProdu[i + 1][j];
        }
    }
    producto[*cont - 1][0] = '\0';
    cantidad[*cont - 1] = 0;
    tiempo[*cont - 1] = 0.0;
    tiempoLim[*cont - 1] = 0.0;
    for (int i = 0; i < *contInv; i++)
    {
        comProdu[*cont - 1][i] = 0;
    }

    (*cont)--;
    printf("Accion realizada exitosamente\n");
}

int mostrarResultados(int *cont, char producto[5][50], int cantidad[5], float tiempo[5], float tiempoLim[5], char nombresInv[5][50], int comProdu[5][5], int cantInv[5], int *contInv, int opc1, char nombPedidos[10][50], int cantPedidos[10], int *contPedidos)
{
    char tex[2][3] = {"SI", "NO"};
    int tiemTotal, ind, ind2, n = opc1 - 1, confir = 0, v, opc,v3,v4;
    int compoTotales[5];
    if (*cont == 0)
    {
        printf("No hay productos registrados.\n");
    }
    else
    {
        printf("Producto seleccionado: %s\n", producto[n]);
        do
        {
            printf("Ingrese la cantidad demandada del producto:\n");
            fflush(stdin);
            v3 = scanf("%d", &cantidad[n]);
            if (v3 != 1)
            {
                printf("Error al ingresar la cantidad. Debe ser un numero entero.\n");
            }
            else if (cantidad[n] < 0)
            {
                printf("No se admiten cantidades negativas.\n");
            }
        } while (v3 != 1 || cantidad[n] < 0);
        do
        {
            printf("Ingrese el tiempo limite para producir el producto (En horas):\n");
            fflush(stdin);
            v4 = scanf("%f", &tiempoLim[n]);
            if (v4 != 1)
            {
                printf("Error al ingresar el tiempo limite para producir el producto. Debe ser un numero entero\n");
            }
            else if (tiempoLim[n] < 0)
            {
                printf("No se admiten tiempos limite de produccion negativos\n");
            }
        } while (v4 != 1 || tiempoLim[*cont] < 0);
        printf("***********Resumen del Producto***********\n");
        printf("Producto seleccionado: %s\n", producto[n]);
        printf("Cantidad: %d\n", cantidad[n]);
        printf("Tiempo de fabricacion: %.2f\n", tiempo[n]);
        printf("Tiempo limite: %.2f\n", tiempoLim[n]);
        printf("Componentes necesarios:\n");
        printf("%s: %d\n", nombresInv[0], comProdu[n][0]);
        printf("%s: %d\n", nombresInv[1], comProdu[n][1]);
        printf("%s: %d\n", nombresInv[2], comProdu[n][2]);
        printf("%s: %d\n", nombresInv[3], comProdu[n][3]);
        printf("%s: %d\n", nombresInv[4], comProdu[n][4]);
        tiemTotal = tiempo[n] * cantidad[n];
        if (tiemTotal <= tiempoLim[n])
        {
            ind = 0;
        }
        else
        {
            ind = 1;
        }
        for (int i = 0; i < 5; i++)
        {
            compoTotales[i] = comProdu[n][i] * cantidad[n];
        }
        for (int i = 0; i < 5; i++)
        {
            if (compoTotales[i] <= cantInv[i])
            {
                confir++;
            }
            if (confir == 5)
            {
                ind2 = 0;
            }
            else if (confir != 5)
            {
                ind2 = 1;
            }
            
            
        }
        printf("La fabrica %s cumple con el tiempo necesario para producir %d %s\n", tex[ind], cantidad[n], producto[n]);
        printf("La fabrica %s tiene suficiente inventario para producir %d %s.\n", tex[ind2], cantidad[n], producto[n]);
        if (confir == 5 && ind == 0)
        {
            printf("Desea fabricarlos? (1) Si (2) No: ");
            do
            {
                fflush(stdin);
                v = scanf("%d", &opc);
                if (v != 1)
                {
                    printf("Error al ingresar opcion, porfavor ingrese valores enteros\n");
                }
                else if (opc != 1 && opc != 2)
                {
                    printf("Error al ingresar opcion, porfavor seleccione 1 o 2\n");
                }
            } while (v != 1 || (opc != 1 && opc != 2));
            if (opc == 1)
            {
                printf("La fabrica ha comenzado a producir %d %s.\n", cantidad[n], producto[n]);
                strcpy(nombPedidos[*contPedidos], producto[n]);
                cantPedidos[*contPedidos] = cantidad[n];
                (*contPedidos)++;
                for (int i = 0; i < *contInv; i++)
                {
                    cantInv[i] -= compoTotales[i];
                }
                tiempoLim[n] = 0.0;
                cantidad[n] = 0;
            }
        }
    }
}
void mostrarPedidos(char nombPedidos[10][50], int cantPedidos[10], int *contPedidos)
{
    if (*contPedidos < 1)
    {
        printf("No se han realizado pedidos\n");
        return;
    }
    printf("--Lista de productos pedidos--\n");
    printf("----------------------------------------------\n");
    printf("| # | Nombre              | Cantidad  |\n");
    printf("----------------------------------------------\n");

    for (int i = 0; i < *contPedidos; i++)
    {
        printf("| %-2d | %-18s | %-17d |\n", i + 1, nombPedidos[i], cantPedidos[i]);
    }
}
void reabastecerInv(char nombresInv[5][50], int cantInv[5], int opc2, int *contInv)
{
    int n = opc2 - 1, cantReabastecer, v;
    if (*contInv < 1)
    {
        printf("No hay un inventario registrado\n");
        return;
    }
    printf("Componente seleccionado: %s\n", nombresInv[n]);
    do
    {
        printf("Ingrese el valor a reabastecer: ");
        fflush(stdin);
        v = scanf("%d", &cantReabastecer);
        if (v != 1)
        {
            printf("Error al ingresar la cantidad. Debe ser un numero entero.\n");
        }
        else if (cantReabastecer < 0)
        {
            printf("No se admiten cantidades negativas\n");
        }
    } while (v != 1 || cantReabastecer < 0);
    cantInv[n] += cantReabastecer;
}
