/*Una fábrica de componentes electrónicos necesita optimizar su producción para cumplir con la demanda de cinco productos distintos.
Cada producto tiene un tiempo de fabricación específico y requiere una cantidad fija de recursos. El equipo de ingeniería ha
identificado que la línea de producción tiene limitaciones de tiempo y recursos que deben ser tomadas en cuenta.

1.El tiempo total de fabricación requerido para cumplir con la demanda.
2.La cantidad de recursos necesarios para producir los productos.
3.Si la fábrica puede cumplir con la demanda dada una cantidad limitada de recursos y tiempo de producción disponible.
*/
#include <stdio.h>
#include <string.h>

void menu();
void registrarProducto();
int tablaDeProductos(int cont, char producto[5][50], int tiempo[5], int recursos[5]);

char producto[5][50];
int tiempo[5];
int recursos[5];
int opc, opc1, cont = 0;

int main(int argc, char *argv[])
{

    do
    {
        menu();
        scanf("%d", &opc);
        switch (opc)
        {
        case 1:
            int v, v2;
    if (cont < 5)
    {
        printf("Ingrese el nombre del producto:\n");
        fflush(stdin);
        fgets(producto[cont], 50, stdin);
        producto[cont][strlen(producto[cont]) - 1] = '\0';
        do
        {
            printf("Ingrese el tiempo de fabricacion para cada producto:\n");
            fflush(stdin);
            v = scanf("%d", &tiempo[cont]);
            if (v != 1)
            {
                printf("Error al ingresar el tiempo de fabricacion.Porfavor ingrese numeros enteros\n");
            }
        } while (v != 1);
        do
        {
            printf("Ingrese la cantidad de recursos necesarios para cada producto:\n");
            fflush(stdin);
            v2 = scanf("%d", &recursos[cont]);
            if (v2 != 1)
            {
                printf("Error al ingresar la cantidad de recursos. Porfavor ingrese numeros enteros\n");
            }
            else
            {
                printf("Producto %d ingresado con exito.\n", cont);
            }
        } while (v2 != 1);
        cont++;
    }
    else
    {
        printf("No se pueden ingresar mas productos\n");
    }
            break;
        case 2:
            
            opc1= tablaDeProductos(cont,producto, tiempo, recursos);
            break;
        default:
            break;
        }
    } while (opc != 5);

    return 0;
}


void menu()
{
    int opc;
    printf("****MENU****");
    printf("\n1. Registrar un producto\n");
    printf("2. Mostrar informacion del producto\n");
    printf("3. Edicion de un producto\n");
    printf("4. Eliminar un producto\n");
    printf("5. Salir\n");
    printf(">>>");
}
//void registrarProducto()
//{}
int tablaDeProductos(int cont, char producto[5][50], int tiempo[5], int recursos[5])
{
    int opc1,v1;
    printf("--Lista de productos--\n");
    printf("#\t\t\tNombre\t\t\tTiempo de fabricacion\t\t\tRecursos Necesarios\n");
    for (int i = 0; i < cont; i++)
    {
        printf("%d\t\t\t%s\t\t\t%d\t\t\t\t%d\n", i +1,producto[i], tiempo[i], recursos[i]);
    }
    do
    {
        printf("Seleccione un producto: ");
        v1=scanf("%d", &opc1);
        if (v1!=1)
        {
            printf("Error al ingresar la opcion. Porfavor ingrese numeros enteros(1-%d)\n",cont);
        }
        
    } while (opc1 < 1 || opc1 > cont);;
}