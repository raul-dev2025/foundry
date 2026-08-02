======================================================
Entrada/Salida y Gestión de Memoria (E/S & MM) - Tests
======================================================

.. contents:: Pruebas Evaluadas
   :depth: 2
   :local:

Análisis del Caso de Prueba: ``mmap01``
=======================================

* **Subsistema**: ``syscalls/mmap``
* **Objetivo**: Verificar que la asignación de memoria compartida (``MAP_SHARED``) mediante ``mmap()`` proyecte correctamente un descriptor de archivo en la memoria del proceso.
* **Fundamento Teórico**: Consulte :doc:`IO_teorica` para revisar el funcionamiento de la estructura ``struct file_operations`` y el mapeo de memoria virtual.

Análisis de Ejecución
---------------------

1. **Configuración del Entorno** (``setup``):
   Se utiliza la macro ``SAFE_OPEN`` de LTP para crear un fichero temporal en un directorio aislado (``needs_tmpdir = 1``) y se ajusta su tamaño al de una página mediante ``ftruncate``.

2. **Invocación de Syscall** (``run``):
   Se invoca ``mmap()`` con los flags ``PROT_READ | PROT_WRITE`` y ``MAP_SHARED``.

3. **Verificación**:
   Se realiza una escritura directa en la dirección devuelta por el kernel (``addr[0] = 'A'``) comprobando la persistencia en el buffer.

Resultados en Entorno ``buildlab``
----------------------------------

.. code-block:: text

   tst_test.c:1690: TINFO: LTP version: 20240129
   tst_test.c:1578: TINFO: Timeout per test is 0h 05m 00s
   mmap01.c:58: TPASS: mmap() funcionó y la memoria es accesible

   Summary:
   passed   1
   failed   0
   broken   0
   skipped  0
   warnings 0