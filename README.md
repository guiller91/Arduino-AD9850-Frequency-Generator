# Generador de Frecuencia con AD9850 y Arduino

Este proyecto utiliza un Arduino para controlar un módulo AD9850 DDS (Direct Digital Synthesis) y generar una señal de frecuencia variable. La frecuencia de la señal se ajusta mediante un potenciómetro y se indica mediante un LED que parpadea durante el ajuste.

## Cómo Funciona

El código lee el valor de un potenciómetro conectado al pin analógico A0 del Arduino. Este valor se mapea a un rango de frecuencia entre 800 kHz y 20 MHz, que es el rango de frecuencia que el AD9850 puede generar. Luego, se envía esta frecuencia al AD9850 utilizando una interfaz serial simplificada. Un LED conectado al pin 13 del Arduino parpadea para indicar que la frecuencia está siendo ajustada.

## Materiales Necesarios

- Arduino (cualquier modelo compatible con los pines utilizados en el código)
- Módulo generador de señales AD9850 DDS
- Potenciómetro (10kΩ recomendado)
- LED
- Resistencia (220Ω para el LED)
- Cables de conexión

## Esquema de Conexión

1. **AD9850 a Arduino**:
   - `W_CLK` a pin 8
   - `FQ_UD` a pin 9
   - `DATA` a pin 10
   - `RESET` a pin 11
2. **Potenciómetro**:
   - Una pata a 5V
   - La pata del medio a A0
   - La otra pata a GND
3. **LED**:
   - Anodo (lado largo) conectado a través de una resistencia de 220Ω al pin 13
   - Catodo (lado corto) a GND

## Cómo Usar

1. Conecta todos los componentes según el esquema de conexión.
2. Sube el código proporcionado a tu Arduino.
3. Gira el potenciómetro para ajustar la frecuencia de la señal generada por el AD9850.
4. Observa el LED parpadear al ajustar la frecuencia como indicador de actividad.

## Código

El código está estructurado en varias partes clave:

- **Definición de Pines**: Especifica los pines utilizados para conectar el Arduino al AD9850 y los componentes externos.
- **Función `setup()`**: Inicializa la comunicación serial y configura los pines como entrada o salida.
- **Función `loop()`**: Lee el valor del potenciómetro, mapea este valor a una frecuencia y ajusta el AD9850 para generar esta frecuencia. Además, parpadea un LED como indicador.
- **Función `setFrequency()`**: Calcula y envía la configuración de frecuencia al AD9850.
- **Función `pulseHigh()`**: Utilizada para generar pulsos en los pines de control del AD9850.

## Contribuciones

Las contribuciones a este proyecto son bienvenidas. Si tienes sugerencias para mejorar el código o la documentación, no dudes en crear un pull request o abrir un issue.

## Licencia

Este proyecto se publica bajo la licencia MIT. Consulta el archivo `LICENSE` para obtener más detalles.
