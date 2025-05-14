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
void registrarProducto(char producto[5][50], int cantidad[5], float tiempo[5], int recursos[5], int *cont);
int tablaDeProductos(int cont, char producto[5][50], int cantidad [5], float tiempo[5], int recursos[5],int tp);
int editarProducto(int cont, char producto[5][50], int cantidad[5], float tiempo[5], int recursos[5], int opc1);

char producto[5][50];
int cantidad[5];
float tiempo[5];
int recursos[5];
int opc, opc1, cont = 0,tp;

int main(int argc, char *argv[])
{

    do
    {
        opc=menu();
        
        switch (opc)
        {
        case 1:
            registrarProducto(producto, cantidad, tiempo, recursos, &cont);
            break;
        case 2:
            tp = 1;
            tablaDeProductos(cont, producto, cantidad, tiempo, recursos, tp);
            break;
        case 3:
            tp=2;
            opc1=tablaDeProductos(cont, producto, cantidad, tiempo, recursos, tp);
            editarProducto(cont,producto,cantidad,tiempo,recursos,opc1);
            break;
        default:
            printf("Opcion no valida\n");
            break;
        }
    } while (opc != 5);

    return 0;
}


int menu()
{
    int opc,v1;
    printf("\n****MENU****\n");
    printf("1. Registrar un producto\n");
    printf("2. Mostrar informacion del producto\n");
    printf("3. Edicion de un producto\n");
    printf("4. Eliminar un producto\n");
    printf("5. Salir\n");
    printf(">>>");
    do
    {
        fflush(stdin);
        v1 = scanf("%d", &opc);
        if (v1!=1)
        {
            printf("Error al ingresar la opcion\n");
        }
    } while (v1 > 1 & v1 < 5);
    return opc;
}
void registrarProducto(char producto[5][50], int cantidad[5], float tiempo[5], int recursos[5], int *cont)
{
    if (*cont >= 5) {
        printf("No se pueden ingresar mas productos.\n");
        return;
    }

    int v, v2, v3;

    printf("Ingrese el nombre del producto:\n");
    fflush(stdin);
    fgets(producto[*cont], 50, stdin);
    producto[*cont][strcspn(producto[*cont], "\n")] = 0;
    do {
        printf("Ingrese la cantidad demandada del producto:\n");
        fflush(stdin);
        v3 = scanf("%d", &cantidad[*cont]);
        if (v3 != 1) {
            printf("Error al ingresar la cantidad. Debe ser un numero entero.\n");
        } else if (cantidad[*cont] < 0) {
            printf("No se admiten cantidades negativas.\n");
        }
    } while (v3 != 1 || cantidad[*cont] < 0);
    do {
        printf("Ingrese el tiempo de fabricacion para cada producto:\n");
        fflush(stdin);
        v = scanf("%f", &tiempo[*cont]);
        if (v != 1) {
            printf("Error al ingresar el tiempo de fabricacion. Debe ser un numero entero\n");
        } else if (tiempo[*cont] < 0) {
            printf("No se admiten tiempos de fabricacion negativos.\n");
        }
    } while (v != 1 || tiempo[*cont] < 0);
    do {
        printf("Ingrese la cantidad de recursos necesarios para cada producto:\n");
        fflush(stdin);
        v2 = scanf("%d", &recursos[*cont]);
        if (v2 != 1) {
            printf("Error al ingresar la cantidad de recursos. Debe ser un numero entero.\n");
        } else if (recursos[*cont] < 0) {
            printf("No se admiten recursos negativos.\n");
        }
    } while (v2 != 1 || recursos[*cont] < 0);
    printf("Producto %d ingresado con exito.\n", *cont + 1);
    (*cont)++;
}
int tablaDeProductos(int cont, char producto[5][50], int cantidad [5], float tiempo[5], int recursos[5],int tp)
{
    int opc1,v1;
    printf("--Lista de productos--\n");
    printf("#\t\t\tNombre\t\tCantidad Demandada\t\t\tTiempo de fabricacion\t\tRecursos Necesarios\n");
    for (int i = 0; i < cont; i++)
    {
        printf("%d\t\t\t%s\t\t%d\t\t\t\t\t%.2f\t\t\t\t%d\n", i + 1, producto[i], cantidad[i], tiempo[i], recursos[i]);
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
int editarProducto(int cont, char producto[5][50], int cantidad[5], float tiempo[5], int recursos[5], int opc1)
{
    int v, ind;
    printf("Que desea editar?\n");
    printf("1. Nombre: %s\n", producto[opc1 - 1]);
    printf("2. Cantidad demandada: %d\n", cantidad[opc1 - 1]);
    printf("3. Tiempo: %.2f\n", tiempo[opc1 - 1]);
    printf("4. Recursos: %d\n", recursos[opc1 - 1]);
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
    } while (v != 1 || ind < 1 || ind > 4);
}
