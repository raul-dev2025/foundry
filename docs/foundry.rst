====================================
Foundry: Visión General del Proyecto
====================================

.. contents:: Tabla de Contenidos
   :depth: 2

Infraestructura Base
====================

* **vCPU:** 4
* **RAM:** 12 GB
* **SO:** Rocky Linux 10
* **Almacenamiento:** Volumen VDO con soporte Copy-on-Write (*reflink*)

Estrategia de Copias Golden (Reflink / VDO)
===========================================

+--------------+---------------------------------------------------+
| Hito Golden  | Estado de la Máquina / Laboratorio                |
+==============+===================================================+
| GOLDEN-00    | Sistema limpio (estado prístino actual).          |
+--------------+---------------------------------------------------+
| GOLDEN-01    | Repositorios (CRB/EPEL) y sistema base actualizado|
+--------------+---------------------------------------------------+
| GOLDEN-02    | Toolchain C completo y kernel-devel alineado.     |
+--------------+---------------------------------------------------+
| GOLDEN-03    | Entorno de depuración (GDB, perf, ftrace) y LTP.  |
+--------------+---------------------------------------------------+

Fases de Ejecución
==================

1. **Fase 0: Punto Cero y Estructura de Documentación**

   * Marcado de punto de control **GOLDEN-00** mediante copia reflink / VDO.
   * Inicialización del árbol de documentación en formato **reStructuredText (rST)**.

2. **Fase 1: Configuración Base de Rocky 10**

   * Activación del repositorio `CRB` (*CodeReady Linux Builder*).
   * Actualización del sistema.
   * Marcado de **GOLDEN-01**.

3. **Fase 2: Cadena de Herramientas (Toolchain C) y Kernel Headers**

   * Instalación del grupo de desarrollo (`gcc`, `make`, `bison`, `flex`, etc.).
   * Alineación estricta de `kernel-devel` y `kernel-headers` con el kernel en ejecución.
   * Validación de compilación de un módulo *Hello World* de kernel básico.
   * Marcado de **GOLDEN-02**.

4. **Fase 3: Entorno de Depuración y Trazado**

   * Instalación y ajuste de `gdb`, `perf`, `trace-cmd` y herramientas eBPF.
   * Configuración de la estrategia de depuración (espacio usuario vs. espacio kernel).

5. **Fase 4: Compilación e Instalación de LTP (Linux Test Project)**

   * Preparación de dependencias para el suite LTP.
   * Compilación e instalación en entorno aislado (`/opt/ltp`).
   * Marcado de **GOLDEN-03**.