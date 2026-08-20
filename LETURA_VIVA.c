#include <stdio.h>
#include <string.h>

#define MAX_LIBROS 3

/* Prototipos de los módulos */
void capturar_datos_cliente(char nombre_cliente[], int *num_socio);

void seleccionar_libros(
    char libros[][30],
    int dias_maximos[],
    int max_libros,
    int libros_seleccionados[],
    int dias_prestamo[],
    int *total_libros,
    int *total_dias
);

void asignar_recordatorio(int total_libros, char recordatorio[]);

void mostrar_resumen(
    char nombre_cliente[],
    int num_socio,
    int total_libros,
    int total_dias,
    char recordatorio[]
);

/* Módulo principal */
int main()
{
    /* Arreglo con los nombres de los libros */
    char libros[MAX_LIBROS][30] = {
        "Cien años de soledad",
        "El principito",
        "Don Quijote"
    };

    /* Arreglo con los días máximos de préstamo */
    int dias_maximos[MAX_LIBROS] = {7, 5, 10};

    /* Variables del módulo principal */
    char nombre_cliente[50];
    int num_socio;
    int libros_seleccionados[MAX_LIBROS];
    int dias_prestamo[MAX_LIBROS];
    int total_libros;
    int total_dias;
    char recordatorio[100];
    int opcion;
    char continuar = 'S';

    /* Datos de identificación */
    printf("========================================\n");
    printf("Nombre: Gabriela Lagunes Rodriguez\n");
    printf("Matricula: ES261108246\n");
    printf("Grupo: DS-DFPR-2602-B1-007\n");
    printf("========================================\n");
    printf("    SISTEMA DE BIBLIOTECA LECTURA VIVA\n");
    printf("========================================\n\n");

    /* Ciclo principal del sistema */
    while (continuar == 'S' || continuar == 's')
    {
        /* Menú principal */
        printf("\n");
        printf("---------- MENU PRINCIPAL ----------\n");
        printf("1. Capturar prestamo\n");
        printf("2. Cerrar prestamo\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        /* Opción para capturar un préstamo */
        if (opcion == 1)
        {
            /* Módulo 1: captura los datos del cliente */
            capturar_datos_cliente(nombre_cliente, &num_socio);

            /* Módulo 2: selecciona los libros */
            seleccionar_libros(
                libros,
                dias_maximos,
                MAX_LIBROS,
                libros_seleccionados,
                dias_prestamo,
                &total_libros,
                &total_dias
            );

            /* Módulo 3: asigna el recordatorio */
            asignar_recordatorio(total_libros, recordatorio);

            /* Módulo 4: muestra el resumen */
            mostrar_resumen(
                nombre_cliente,
                num_socio,
                total_libros,
                total_dias,
                recordatorio
            );

            printf("\n¿Desea realizar otro prestamo? (S/N): ");
            scanf(" %c", &continuar);
        }
        else
        {
            /* Opción para cerrar el préstamo */
            if (opcion == 2)
            {
                printf("\nPrestamo cerrado.\n");
                printf("¡Gracias por usar el Sistema de Biblioteca Lectura Viva!\n");

                continuar = 'N';
            }
            else
            {
                /* Mensaje para una opción no válida */
                printf("\nOpcion no valida. Intente nuevamente.\n");
            }
        }
    }

    return 0;
}


/* =====================================================
   MODULO 1: CAPTURAR DATOS DEL CLIENTE
   ===================================================== */
void capturar_datos_cliente(char nombre_cliente[], int *num_socio)
{
    /* Captura los datos del cliente */
    printf("\n--- DATOS DEL CLIENTE ---\n");

    printf("Ingrese el nombre del cliente: ");
    scanf(" %49[^\n]", nombre_cliente);

    printf("Ingrese el numero de socio: ");
    scanf("%d", num_socio);
}


/* =====================================================
   MODULO 2: SELECCIONAR LIBROS
   ===================================================== */
void seleccionar_libros(
    char libros[][30],
    int dias_maximos[],
    int max_libros,
    int libros_seleccionados[],
    int dias_prestamo[],
    int *total_libros,
    int *total_dias
)
{
    int i;

    /* Inicializa los totales */
    *total_libros = 0;
    *total_dias = 0;

    printf("\n--- SELECCION DE LIBROS ---\n");

    /* Recorre el arreglo de libros */
    for (i = 0; i < max_libros; i++)
    {
        printf("\nLibro %d: %s\n", i + 1, libros[i]);
        printf("¿Desea seleccionar este libro? (1=Si / 0=No): ");
        scanf("%d", &libros_seleccionados[i]);

        /* Verifica si el libro fue seleccionado */
        if (libros_seleccionados[i] == 1)
        {
            printf("Ingrese los dias de prestamo: ");
            scanf("%d", &dias_prestamo[i]);

            *total_libros = *total_libros + 1;
            *total_dias = *total_dias + dias_prestamo[i];
        }
    }
}


/* =====================================================
   MODULO 3: ASIGNAR RECORDATORIO
   ===================================================== */
void asignar_recordatorio(int total_libros, char recordatorio[])
{
    /* Determina el mensaje según el número de libros */
    if (total_libros == 0)
    {
        strcpy(recordatorio, "No se seleccionaron libros.");
    }
    else
    {
        if (total_libros == 1)
        {
            strcpy(
                recordatorio,
                "Recuerde devolver el libro en la fecha indicada."
            );
        }
        else
        {
            strcpy(
                recordatorio,
                "Recuerde devolver los libros en las fechas indicadas."
            );
        }
    }
}


/* =====================================================
   MODULO 4: MOSTRAR RESUMEN
   ===================================================== */
void mostrar_resumen(
    char nombre_cliente[],
    int num_socio,
    int total_libros,
    int total_dias,
    char recordatorio[]
)
{
    /* Muestra el resumen del préstamo */
    printf("\n");
    printf("========== RESUMEN DEL PRESTAMO ==========\n");
    printf("Nombre del cliente: %s\n", nombre_cliente);
    printf("Numero de socio: %d\n", num_socio);
    printf("Total de libros: %d\n", total_libros);
    printf("Total de dias de prestamo: %d\n", total_dias);
    printf("Recordatorio: %s\n", recordatorio);
    printf("===========================================\n");
}
