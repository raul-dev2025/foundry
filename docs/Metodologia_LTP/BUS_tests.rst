=================================================
Interrupciones y Comunicación con Bus PCI - Tests
=================================================

.. contents:: Pruebas Evaluadas
   :depth: 2
   :local:

Análisis del Caso de Prueba: Identificación del Bus y Espacio de Configuración
==============================================================================

* **Subsistema**: ``drivers/pci`` / ``sysfs``
* **Objetivo**: Verificar la correcta detección, enumeración y lectura del Espacio de Configuración de los dispositivos PCI en la topología del sistema.
* **Fundamento Teórico**: Consulte :doc:`BUS_teorica` para revisar la estructura de la jerarquía BDF, los registros BAR y la exposición en ``sysfs``.

Análisis de Ejecución
---------------------

1. **Configuración del Entorno** (``setup``):
   Se comprueba la existencia de la jerarquía de dispositivos PCI en ``/sys/bus/pci/devices/`` y la disponibilidad de permisos para la lectura de los recursos del bus.

2. **Invocación y Lectura** (``run``):
   Acceso a los atributos de los dispositivos (identificadores ``vendor``, ``device`` y archivo de configuración ``config``) para validar la consistencia de la lectura de cabeceras PCI.

3. **Verificación**:
   Comprobación de que las direcciones de memoria mapeada (MMIO) declaradas en los registros BAR corresponden a rangos válidos del mapa de memoria del sistema.

Resultados en Entorno ``buildlab``
----------------------------------

.. note::

   Sección reservada para documentar las salidas de ejecución y registros en ``buildlab``
   clasificando los resultados según la metodología LTP (``TPASS``, ``TFAIL``, ``TCONF``).

.. code-block:: text

   tst_test.c:1900: TINFO: LTP version: 20250130
   tst_test.c:1904: TINFO: Tested kernel: 6.12.0-124.8.1.el10_1.x86_64 #1 SMP PREEMPT_DYNAMIC Tue Nov 11 22:54:28 UTC 2025 x86_64
   tst_kconfig.c:88: TINFO: Parsing kernel config '/lib/modules/6.12.0-124.8.1.el10_1.x86_64/build/.config'
   tst_test.c:1722: TINFO: Overall timeout per run is 0h 00m 30s
   pci_config_test.c:30: TINFO: Escaneando dispositivos en /sys/bus/pci/devices...
   pci_config_test.c:48: TINFO: BDF: 0000:03:00.0 -> VendorID: 0x1af4 | DeviceID: 0x1043
   pci_config_test.c:48: TINFO: BDF: 0000:00:1f.2 -> VendorID: 0x8086 | DeviceID: 0x2922
   pci_config_test.c:48: TINFO: BDF: 0000:0a:01.0 -> VendorID: 0x1234 | DeviceID: 0x1111
   pci_config_test.c:48: TINFO: BDF: 0000:09:00.0 -> VendorID: 0x1b36 | DeviceID: 0x000e
   pci_config_test.c:48: TINFO: BDF: 0000:00:01.2 -> VendorID: 0x1b36 | DeviceID: 0x000c
   pci_config_test.c:65: TPASS: Se leyo correctamente el Espacio de Configuracion PCI de 5 dispositivos

   Summary:
   passed   1
   failed   0
   broken   0
   skipped  0
   warnings 0


Análisis del Caso de Prueba: Asignación y Control de Interrupciones (MSI/MSI-X)
================================================================================

* **Subsistema**: ``kernel/irq`` / ``drivers/pci``
* **Objetivo**: Validar el registro y la entrega de vectores de interrupción en dispositivos PCI, verificando la transición a mecanismos MSI/MSI-X.
* **Fundamento Teórico**: Consulte :doc:`BUS_teorica` para revisar el ciclo de vida de las interrupciones, las diferencias entre líneas INTx y vectores MSI-X, y la gestión mediante *Top Half* / *Bottom Half*.

Análisis de Ejecución
---------------------

1. **Configuración del Entorno** (``setup``):
   Inspección de las líneas de interrupción asignadas al dispositivo en prueba a través de la interfaz ``/proc/interrupts``.

2. **Invocación y Eventos** (``run``):
   Generación de eventos de E/S sobre el dispositivo seleccionado para provocar el disparo de interrupciones y verificar la respuesta del manejador (*Interrupt Service Routine* - ISR).

3. **Verificación**:
   Confirmación del incremento en los contadores de vectores de interrupción en la CPU correspondiente y ausencia de anomalías o desbalanceo de líneas compartidas.

Resultados en Entorno ``buildlab``
----------------------------------

.. note::

   Sección reservada para documentar las salidas de ejecución y registros en ``buildlab``
   clasificando los resultados según la metodología LTP (``TPASS``, ``TFAIL``, ``TCONF``).

.. code-block:: text

   # Pendiente de ejecución en el entorno Lab/Caja Negra.