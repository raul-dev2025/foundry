===================================================
Fase 2: Entorno de Usuario y Metodología de Trabajo
===================================================

.. sectionauthor:: Raul Vilchez Ruiz

Resumen de la Fase
==================

En esta fase se establece el entorno operativo sin privilegios dentro de la máquina virtual ``buildlab`` y se define el flujo de sincronización de código fuente desde el host de desarrollo (WS). Se adopta una metodología de integración semiautomática basada en Git para garantizar un control riguroso sobre los ciclos de compilación y prueba de los controladores del núcleo, complementada con una arquitectura de almacenamiento compartimentada para aislar los artefactos y los registros de compilación.

Objetivos Técnicos
==================

1. Creación y configuración del usuario de compilación sin privilegios (``builder``).
2. Aplicación del principio de mínimo privilegio mediante la delegación estricta de comandos de administración de módulos (``sudoers``).
3. Establecimiento de la conectividad SSH sin contraseña entre la WS host (``raul-ipa``) y el entorno de compilación.
4. Definición del flujo de trabajo Git bajo demanda (*pull-on-demand*) para la transferencia de código.
5. Arquitectura de almacenamiento compartimentado para la segregación de salidas y registros del sistema.

Configuración del Usuario de Compilación
========================================

1. **Creación del Usuario:**
   Se habilita un usuario dedicado en el entorno ``buildlab`` para evitar la ejecución de procesos de compilación con privilegios de superusuario:

   .. code-block:: bash

      useradd -m -s /bin/bash builder

2. **Delegación de Privilegios para Operaciones del Núcleo:**
   Para permitir la prueba e inspección de controladores sin conceder acceso ``root`` completo, se parametriza la directiva en ``/etc/sudoers.d/builder-kernel``:

   .. code-block:: sudoers

      builder ALL=(ALL) NOPASSWD: /usr/sbin/insmod, /usr/sbin/rmmod, /usr/bin/dmesg, /usr/sbin/modinfo

   Se aplican los permisos estrictos al archivo de configuración:

   .. code-block:: bash

      chmod 0440 /etc/sudoers.d/builder-kernel

Segregación y Arquitectura de Almacenamiento
============================================

Para garantizar la seguridad operativa, prevenir la saturación de la partición raíz y permitir la inspección *offline* de los datos del laboratorio, se implementa una separación estricta mediante volúmenes dedicados sobre el pool de almacenamiento VDO de la infraestructura:

1. **Volumen de Artefactos (``/mnt/build-output``):**
   * **Dimensionamiento:** 5 GB.
   * **Propósito:** Almacenamiento exclusivo de módulos compilados (``.ko``) y binarios de prueba generados por el usuario ``builder``. Permite evaluar los artefactos de manera aislada sin requerir la ejecución de la máquina virtual.

2. **Volumen de Registros (``/mnt/build-logs``):**
   * **Dimensionamiento:** 5 GB.
   * **Propósito:** Centralización de las trazas de compilación, salidas de ejecución y registros del kernel para auditoría y depuración sin comprometer el espacio del sistema base.

Integración y Conectividad SSH / Git
====================================

1. **Intercambio de Claves SSH:**
   Se configura la autenticación mediante par de claves públicas para el usuario ``builder``, permitiendo la sincronización de repositorios desde el entorno del host (``raul-ipa``) sin intervención interactiva de contraseñas.

2. **Modelo de Sincronización Semiautomática (Opción B):**
   El código fuente del controlador se mantiene y edita en la estación de trabajo principal. La máquina virtual opera como cliente remoto:

   * **Edición y Control de Versiones:** Los cambios se confirman localmente en la WS.
   * **Sincronización Bajo Demanda:** Desde la VM ``buildlab``, el usuario ejecuta la actualización del repositorio previo a la compilación:

     .. code-block:: bash

        git pull origin main

Estado del Entorno
==================

Con la infraestructura de usuarios, conectividad y la compartimentación de almacenamiento desplegada, el laboratorio queda preparado para la sincronización del repositorio y la ejecución del primer ciclo de compilación de controladores del núcleo.