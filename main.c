/*Una fábrica de componentes electrónicos necesita optimizar su producción para cumplir con la demanda de cinco productos distintos.
Cada producto tiene un tiempo de fabricación específico y requiere una cantidad fija de recursos. El equipo de ingeniería ha
identificado que la línea de producción tiene limitaciones de tiempo y recursos que deben ser tomadas en cuenta.

1.El tiempo total de fabricación requerido para cumplir con la demanda.
2.La cantidad de recursos necesarios para producir los productos.
3.Si la fábrica puede cumplir con la demanda dada una cantidad limitada de recursos y tiempo de producción disponible.
*/
#include <stdio.h>
#include <string.h>

int menu();
void registrarProducto(char producto[5][50], int cantidad[5], float tiempo[5], float tiempoLim[5], int recursos[5], int *cont);
int tablaDeProductos(int cont, char producto[5][50], int cantidad[5], float tiempo[5], float tiempoLim[5], int recursos[5], int tp);
int editarProducto(int cont, char producto[5][50], int cantidad[5], float tiempo[5], float tiempoLim[5], int recursos[5], int opc1);
int eliminarProducto(int *cont, char producto[5][50], int cantidad[5], float tiempo[5], float tiempoLim[5], int recursos[5], int opc1);
void mostrarResultados(int *cont, char producto[5][50], int cantidad[5], float tiempo[5], float tiempoLim[5], int recursos[5]);
int registrarInventario(char nombresInv[5][50], int cantInv[5], int *contInv);
int tablaDeInventario(int *contInv, char nombresInv[5][50], int cantInv[5]);

int main(int argc, char *argv[])
{
    char producto[5][50];
    int cantidad[5];
    float tiempo[5];
    float tiempoLim[5];
    int recursos[5];
    char nombresInv[5][50];
    int cantInv[5];
    int opc, opc1, cont = 0, contInv=0, tp;
    registrarInventario(nombresInv, cantInv, &contInv);
    tablaDeInventario(&contInv, nombresInv, cantInv);
    do
    {

        opc = menu();

        switch (opc)
        {
        case 1:
            registrarProducto(producto, cantidad, tiempo, tiempoLim, recursos, &cont);
            break;
        case 2:
            tp = 1;
            tablaDeProductos(cont, producto, cantidad, tiempo, tiempoLim, recursos, tp);
            break;
        case 3:
            tp = 2;
            opc1 = tablaDeProductos(cont, producto, cantidad, tiempo, tiempoLim, recursos, tp);
            editarProducto(cont, producto, cantidad, tiempo, tiempoLim, recursos, opc1);
            break;
        case 4:
            tp = 3;
            opc1 = tablaDeProductos(cont, producto, cantidad, tiempo, tiempoLim, recursos, tp);
            eliminarProducto(&cont, producto, cantidad, tiempo, tiempoLim, recursos, opc1);
            break;
        case 5:
            mostrarResultados(&cont, producto, cantidad, tiempo,tiempoLim, recursos);
            break;
        case 6:
            printf("Gracias por usar el programa\n");
            break;
        default:
            printf("Opcion no valida\n");
            break;
        }
    } while (opc != 6);

    return 0;
}
int registrarInventario(char nombresInv[5][50], int cantInv[5], int *contInv)
{
    int cont1, v, opc, v1;
    if (*contInv > 5)
    {
        printf("El inventario esta lleno\n");
    }
    else
    {
        do
        {
            printf("Ingrese el nombre del componente %d: ", *contInv + 1);
            fgets(nombresInv[*contInv], 50, stdin);
            nombresInv[*contInv][strcspn(nombresInv[*contInv], "\n")] = 0;
            printf("Ingrese la cantidad de %s disponible: ", nombresInv[*contInv]);
            do
            {
                fflush(stdin);
                v = scanf("%d", &cantInv[*contInv]);
                if (v != 1)
                {
                    printf("Error al ingresar la cantidad, se deben ingresar solo numeros enteros\n");
                }
            } while (v != 1);
            *contInv++;
            printf("\nDesea agregar otro componente? (1) si (2) no\n");
            {
                fflush(stdin);
                v1 = scanf("%d", &opc);
                if (opc!=1 || opc!=2)
                {
                    printf("Error al ingresar la opcion, porfavor ingrese 1 o 2\n");
                }
                
                if (v1 != 1)
                {
                    printf("Error al ingresar la opcion, solo se admiten numeros enteros\n");
                }
            }
            while (v1 != 1);
        } while (opc != 2);
    }
}
int tablaDeInventario(int *contInv, char nombresInv[5][50], int cantInv[5]){
    printf("#\t\tNombre del componente\t\t\t\tStock");
    for (int i = 0; i <= *contInv; i++)
    {
        printf("\n%d\t\t%s\t\t\t\t\t\t%d", i + 1, nombresInv[i], cantInv[i]);
    }
    
}
int menu()
{
    int opc, v1;
    printf("\n****MENU DE ****\n");
    printf("1. Registrar un producto\n");
    printf("2. Mostrar informacion del producto\n");
    printf("3. Edicion de un producto\n");
    printf("4. Eliminar un producto\n");
    printf("5. Mostrar resultados\n");
    printf("6. Salir\n");
    printf(">>>");
    do
    {
        fflush(stdin);
        v1 = scanf("%d", &opc);
        if (v1 != 1)
        {
            printf("Error al ingresar la opcion\n");
        }
    } while (v1 > 1 & v1 < 6);
    return opc;
}
void registrarProducto(char producto[5][50], int cantidad[5], float tiempo[5], float tiempoLim[5], int recursos[5], int *cont)
{
    if (*cont >= 5)
    {
        printf("No se pueden ingresar mas productos.\n");
        return;
    }

    int v, v2, v3, v4;

    printf("Ingrese el nombre del producto:\n");
    fflush(stdin);
    fgets(producto[*cont], 50, stdin);
    producto[*cont][strcspn(producto[*cont], "\n")] = 0;
    do
    {
        printf("Ingrese la cantidad demandada del producto:\n");
        fflush(stdin);
        v3 = scanf("%d", &cantidad[*cont]);
        if (v3 != 1)
        {
            printf("Error al ingresar la cantidad. Debe ser un numero entero.\n");
        }
        else if (cantidad[*cont] < 0)
        {
            printf("No se admiten cantidades negativas.\n");
        }
    } while (v3 != 1 || cantidad[*cont] < 0);
    do
    {
        printf("Ingrese el tiempo de fabricacion para cada producto:\n");
        fflush(stdin);
        v = scanf("%f", &tiempo[*cont]);
        if (v != 1)
        {
            printf("Error al ingresar el tiempo de fabricacion. Debe ser un numero entero\n");
        }
        else if (tiempo[*cont] < 0)
        {
            printf("No se admiten tiempos de fabricacion negativos.\n");
        }
    } while (v != 1 || tiempo[*cont] < 0);
    do
    {
        printf("Ingrese el tiempo limite para producir el producto:\n");
        fflush(stdin);
        v4 = scanf("%f", &tiempoLim[*cont]);
        if (v4 != 1)
        {
            printf("Error al ingresar el tiempo limite para producir el producto. Debe ser un numero entero\n");
        }
        else if (tiempoLim[*cont] < 0)
        {
            printf("No se admiten tiempos limite de produccion negativos.\n");
        }
    } while (v4 != 1 || tiempoLim[*cont] < 0);
    do
    {
        printf("Ingrese la cantidad de recursos necesarios para cada producto:\n");
        fflush(stdin);
        v2 = scanf("%d", &recursos[*cont]);
        if (v2 != 1)
        {
            printf("Error al ingresar la cantidad de recursos. Debe ser un numero entero.\n");
        }
        else if (recursos[*cont] < 0)
        {
            printf("No se admiten recursos negativos.\n");
        }
    } while (v2 != 1 || recursos[*cont] < 0);
    printf("Producto %d ingresado con exito.\n", *cont + 1);
    (*cont)++;
}
int tablaDeProductos(int cont, char producto[5][50], int cantidad[5], float tiempo[5], float tiempoLim[5], int recursos[5], int tp)
{
    int opc1, v1;
    printf("--Lista de productos--\n");
    printf("#\t\t\tNombre\t\tCantidad Demandada\t\t\tTiempo de fabricacion\t\tTiempo limite\t\tRecursos Necesarios\n");
    for (int i = 0; i < cont; i++)
    {
        printf("%d\t\t\t%s\t\t%d\t\t\t\t\t%.2f\t\t\t\t%.2f\t\t\t%d\n", i + 1, producto[i], cantidad[i], tiempo[i], tiempoLim[i], recursos[i]);
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
                printf("Seleccion el producto a eliminar: ");
            }
            fflush(stdin);
            v1 = scanf("%d", &opc1);
            if (v1 != 1)
            {
                printf("Error al ingresar la opcion. Porfavor ingrese numeros enteros(1-%d)\n", cont);
            }
            if (opc1 < 1 || opc1 > cont)
            {
                printf("Error, ese numero de producto no esta registrado\n");
            }
        } while (opc1 < 1 || opc1 > cont || v1 != 1);
        return opc1;
    }
}
int editarProducto(int cont, char producto[5][50], int cantidad[5], float tiempo[5], float tiempoLim[5], int recursos[5], int opc1)
{
    int v, ind, v3, v1, v4, v2;
    printf("Que desea editar?\n");
    printf("1. Nombre: %s\n", producto[opc1 - 1]);
    printf("2. Cantidad demandada: %d\n", cantidad[opc1 - 1]);
    printf("3. Tiempo Limite: %.2f\n", tiempoLim[opc1 - 1]);
    printf("4. Tiempo de produccion por unidad de producto: %.2f\n", tiempo[opc1 - 1]);
    printf("5. Recursos: %d\n", recursos[opc1 - 1]);
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
    } while (v != 1 || ind < 1 || ind > 5);
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
            printf("Ingrese la nueva cantidad demandada del producto:\n");
            fflush(stdin);
            v3 = scanf("%d", &cantidad[opc1 - 1]);
            if (v3 != 1)
            {
                printf("Error al ingresar la cantidad. Debe ser un numero entero.\n");
            }
            else if (cantidad[opc1 - 1] < 0)
            {
                printf("No se admiten cantidades negativas.\n");
            }
        } while (v3 != 1 || cantidad[opc1 - 1] < 0);
        printf("Modificacion realizada con exito");
    }
    else if (ind == 3)
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
    else if (ind == 4)
    {
        do
        {
            printf("Ingrese el nuevo tiempo limite para producir el producto:\n");
            fflush(stdin);
            v4 = scanf("%f", &tiempoLim[opc1 - 1]);
            if (v4 != 1)
            {
                printf("Error al ingresar el tiempo limite para producir el producto. Debe ser un numero entero\n");
            }
            else if (tiempoLim[opc1 - 1] < 0)
            {
                printf("No se admiten tiempos limite de produccion negativos.\n");
            }
        } while (v4 != 1 || tiempoLim[opc1 - 1] < 0);
        printf("Modificacion realizada con exito");
    }
    else if (ind == 5)
    {
        do
        {
            printf("Ingrese la cantidad de recursos necesarios para cada producto:\n");
            fflush(stdin);
            v2 = scanf("%d", &recursos[opc1 - 1]);
            if (v2 != 1)
            {
                printf("Error al ingresar la cantidad de recursos. Debe ser un numero entero.\n");
            }
            else if (recursos[opc1 - 1] < 0)
            {
                printf("No se admiten recursos negativos.\n");
            }
        } while (v2 != 1 || recursos[opc1 - 1] < 0);
        printf("Modificacion realizada con exito");
    }
}
int eliminarProducto(int *cont, char producto[5][50], int cantidad[5], float tiempo[5], float tiempoLim[5], int recursos[5], int opc1)
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
        recursos[i] = recursos[i + 1];
    }
    strcpy(producto[*cont - 1], "");
    cantidad[*cont - 1] = 0;
    tiempo[*cont - 1] = 0.0f;
    tiempoLim[*cont - 1] = 0.0f;
    recursos[*cont - 1] = 0;
    (*cont)--;
    printf("Producto eliminado exitosamente\n");
}
void mostrarResultados(int *cont, char producto[5][50], int cantidad[5], float tiempo[5], float tiempoLim[5], int recursos[5])
{
    char tex[2][3] = { "Si", "No" };
    int tiemTotal,ind;
    if (*cont == 0)
    {
        printf("No hay productos registrados.\n");
    }
    else
    {

        printf("Productos registrados:\n");
        for (int i = 0; i < *cont; i++)
        {
            tiemTotal = tiempo[i] * cantidad[i];
            if (tiemTotal <= tiempoLim[i])
            {
                ind=0;
            }
            else
            {
                ind=1;
            }
            printf("Producto %d: %s\n", i + 1, producto[i]);
            printf("Cantidad: %d\n", cantidad[i]);
            printf("Tiempo: %.2f\n", tiempo[i]);
            printf("Tiempo Limite: %.2f\n", tiempoLim[i]);
            printf("Recursos: %d\n", recursos[i]);
            printf("La fabrica %s cumple con la demanda necesaria para producir %d productos de %s\n", tex[ind], cantidad[i],producto[i]);
            printf("----------------------------------------------------------------------------------------\n");
        }

    }
}