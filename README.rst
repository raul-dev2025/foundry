====================================
Foundry: Visión General del Proyecto
====================================

**Foundry** es el entorno de laboratorio sobre Rocky Linux 10 diseñado para el desarrollo, compilación y pruebas de código C, módulos del kernel de Linux (controladores de dispositivo) y ejecuciones de validación con el **Linux Test Project (LTP)**.

Especificaciones del Entorno
============================

* **vCPU:** 4
* **RAM:** 12 GB
* **SO:** Rocky Linux 10
* **Almacenamiento:** Volumen VDO con soporte Copy-on-Write (*reflink*)

Estrategia de Preservación: Copias Golden
==========================================

Para garantizar un entorno seguro y de rápida recuperación frente a pruebas destructivas o errores de compilación, se utiliza una estrategia de hitos mediante *reflink* sobre VDO:

+--------------+---------------------------------------------------+
| Hito Golden  | Estado del Laboratorio                            |
+==============+===================================================+
| GOLDEN-00    | Sistema limpio (estado prístino inicial).         |
+--------------+---------------------------------------------------+
| GOLDEN-01    | Repositorios (CRB) activos y SO actualizado.      |
+--------------+---------------------------------------------------+
| GOLDEN-02    | Toolchain C completo y kernel-devel alineado.     |
+--------------+---------------------------------------------------+
| GOLDEN-03    | Entorno de depuración (GDB/perf/ftrace) y LTP.    |
+--------------+---------------------------------------------------+

Estructura del Repositorio
==========================

* ``config/``: Archivos de configuración de build, kernel y herramientas.
* ``docs/``: Documentación técnica del laboratorio escrita en reStructuredText (rST).
* ``fases/``: Guías de ejecución y scripts auxiliares por cada fase de despliegue.
* ``scripts/``: Herramientas de automatización de entorno y pruebas.

-----

* Ver documentación `Foundry <https://github.com/raul-dev2025/raul-dev2025.github.io/blob/docs-integration/source/07_Development/Foundry/EntornoLTP/foundry.rst>`_