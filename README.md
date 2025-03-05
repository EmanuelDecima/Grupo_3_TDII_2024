# Repositorio del Grupo 3 - Tecnicas Digitales II
Aqui se subiran las Actividades de Formacion Practica (AFP) para la asignatura de Tecnicas Digitales II

## Proyecto Final - Radar Ultrasonico
El proyecto consiste en el desarrollo de un Radar Ultrasónico, diseñado para detectar objetos dentro de un rango de distancia determinado y alertar al usuario mediante mensajes a través de una pantalla LCD y un dispositivo conectado vía Bluetooth. Este sistema se basa en la medición de distancias utilizando un sensor ultrasónico HC-SR04, montado sobre un servomotor, que le permite escanear su entorno en un rango de 180°.

### Software Utilizado:
Entorno de desarrollo: STM32CubeIDE
Lenguaje: C (estándar GNU11)
Bibliotecas HAL: STM32F4xx HAL Driver

### Hardware Utilizado:
* STM32F401CCU6.
* Sensor de Proximidad HCSR04.
* Servomotor SG90.
* Modulo Bluetooth HC-05.
* Pantalla LCD 16x02 con Modulo PCF85774 para la comunicacion I2C.
* Buzzer.
* 3 LEDs
* Fuente de Alimentacion 5VDC 1A

### Creamos una serie de Drivers que fueron implementados en el proyecto, Estos se encuentran en "./Drivers/API".
* **API_Delay**: Contiene las funciones para implementar delays no bloqueantes.
* **API_HC05**: Contiene las funciones para controlar el modulo Bluetooth, cuenta con funciones para enviar texto y datos numericos.
* **API_HCSR04**:Contiene las funciones para obetener los datos de proximidad medidos con el modulo HCSR04, utiliza el TIM1 CH1 en modo Input Capture para calcular el pulso que devuelve el modulo al realizar la medicion. Posee funciones adicionales para filtrar los datos y obtener mediciones estables.
* **API_LCD**:  Utilizada para controlar la pantalla LCD mediante el modulo I2C PCF8574. La librería cuenta con funciones para Inicializar el modulo con su combinacion de comandos especifica, y para enviar tanto cadenas de caracteres como datos. Tambien cuenta con las funciones adicionales necesarias para manejar la pantalla LCD como mover el cursos o limpiar la pantalla. 
* **API_MEF**: Implementacion de la maquina de estados.
* **API_Secuencias**:  Posee dos funciones, la secuencia de inicio y la secuencia que sigue el dispositivo cuando la alarma esta activada.
* **API_Servo**: Contiene la inicializacion del TIM3 CH1 para el uso de señales PWM que permiten controlar el servomotor y otra funcion que realiza el calculo del ancho de pulso necesario para establecer un angulo determinado en el servomotor.


