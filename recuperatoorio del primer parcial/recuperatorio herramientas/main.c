#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "alquiler.h"
#include "validaciones.h"

#define tamClientes 5
#define tamAlquiler 30
#define tamEquipo 3
#define tamOperador 3

int menu();

int main()
{
    int seguir = 0;
    int seguir2 = 0;
	int id = 1;
	int idA = 1;
	int flag = 0;
	int flag2 = 0;

	eCliente clientes[tamClientes];
	eAlquiler alquileres[tamAlquiler];

	eEquipo equipos[tamEquipo] = {{1, "Amoladora"}, {2, "Mezcladora"}, {3, "Taladro"}};
    eOperador operadores[tamOperador] = {{1, "Juan", "Perez"}, {2, "Aaron", "Costa"}, {3, "Lucia", "Garcia"}};

	inicializarClientes(clientes, tamClientes);
	inicializarAlquileres(alquileres, tamAlquiler);

    do
	{
		switch(menu())
		{
		case 1:
            if(!(altaCliente(id, clientes, tamClientes)))
			{
				id++;
				flag = 1;
			}
			break;

		case 2:
            if(flag)
            {
                modificarCliente(clientes, tamClientes);
            }
            else
            {
                printf("\n**Debe dar de alta**\n");
            }
			break;

		case 3:
            if(flag)
            {
                bajaCliente(clientes, tamClientes);
            }
            else
            {
                printf("\n**Debe dar de alta**\n");
            }
			break;

		case 4:
            if(flag)
            {
                if(!altaAlquiler(idA, clientes, tamClientes, alquileres, tamAlquiler, equipos, tamEquipo, operadores, tamOperador))
                {
                    idA++;
                    flag2 = 1;
                }
            }
            else
            {
                printf("\n**Debe dar de alta **\n");
            }
			break;

		case 5:
            if(flag2)
            {
                finalizarAlquiler(clientes, tamClientes, alquileres, tamAlquiler, equipos, tamEquipo, operadores, tamOperador);
            }
            else
            {
                printf("\n**Debe dar de alta un alquiler primero**\n");
            }
			break;

		case 6:
		    if(flag2)
            {
                do
                {
                    switch(menuInformes())
                    {
                    case 1:
                        informarClienteMasAlquilados(clientes, tamClientes, alquileres, tamAlquiler);
                        break;
                    case 2:
                        informarEquipoMasAlquilado(alquileres, tamAlquiler, equipos, tamEquipo);
                        break;
                    case 3:
                        informarTiempoEquipos(equipos, tamEquipo, alquileres, tamAlquiler);
                        break;
                    case 4:
                        imprimirClientesAlquileres(clientes, tamClientes, alquileres, tamAlquiler, equipos, tamEquipo);
                        break;
                    case 5:
                        seguir2 = 1;
                        break;
                    }
                    system("pause");
                }while(seguir2 == 0);
            }
            else
            {
                printf("\n**Debe dar de alta **\n");
            }
			break;

		case 7:
            seguir = 1;
            break;
			}
			system("pause");
		}while(seguir == 0);

    return 0;
}

int menu()
{
	system("cls");
	int opcion;

	printf("M E N U\n");
	printf("1.Alta Cliente\n");
	printf("2.Modificar cliente\n");
	printf("3.Baja cliente\n");
	printf("4.Nuevo alquiler\n");
	printf("5.Finalizacion del alquiler\n");
	printf("6.Informar\n");
	printf("7.Salir\n");

	utn_getEntero(&opcion, 2, "\nIngrese una opcion : ", "\nError.\n", 1, 7);

	return opcion;
}
