===================================================
Fase 1: Preparación del Sistema Base y Repositorios
===================================================

Objetivos
=========

1. Activar los repositorios de paquetes de desarrollo requeridos en Rocky Linux 10 (`CRB` / *CodeReady Linux Builder*).
2. Actualizar la totalidad de los paquetes del sistema base.
3. Registrar el hito de control **GOLDEN-01** mediante la copia *reflink* correspondiente sobre VDO.

Procedimiento Técnico
=====================

Activación del Repositorio CRB
------------------------------

En Rocky Linux 10, los paquetes de desarrollo y librerías adicionales necesarias para compilar cabeceras de kernel y herramientas de bajo nivel se encuentran en el repositorio CRB.

.. code-block:: bash

   sudo dnf config-manager --set-enabled crb

Actualización del Sistema Base
------------------------------

Asegurar que todos los paquetes base estén en su versión más reciente antes de instalar la cadena de herramientas (*toolchain*):

.. code-block:: bash

   sudo dnf update -y

Marcado del Hito GOLDEN-01
---------------------------

Una vez completada la actualización, se procede a consolidar el estado del sistema mediante copia *reflink*.

:doc:`Índice principal </index>`