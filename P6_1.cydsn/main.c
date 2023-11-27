/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include "project.h"
uint16 valpot = 0;
uint8 tipounidad = 0;
uint32 angulo = 0;
uint8 tecla;
uint8 countpot = 0;
uint8 potband = 0;
uint8 tecladoband = 0;
uint8 pos = 0;
uint8 ms1 = 0;
uint8 ms2=0;
uint8 add = 0;
uint8 correcto = 0;
uint8 ohno = 0;
uint8 ESCORRECTO = 0;
uint8 salida = 0;
uint32 counterOut = 0;
uint8 comparado = 0;
uint8 ciclo_acabado;
uint16 senal_hume=0;
uint16 senal_temp=0;
uint32 milivolt_h=0;
uint32 milivolt_temp=0;
uint8 finishpass = 0;
uint8 puerta_cerrada=0;
uint8 ClaveIngresada[4];
uint8 ClaveOriginal[4]={1,2,2,3};
uint8 CompararClave(const uint8 *Ingresada, const uint8 *Original);
uint16 temp;
uint16 humedad;
uint8 ingresando_valores=0;
uint8 temperatura_anadida=0;
uint8 humedad_anadida=0;
uint8 tiempo_anadido=0;
uint32 temp_in=2;
uint32 humedad_in=0;
uint32 tiempo_in=2;
uint8 valores_confirmados=1;
uint16 min_crono;
uint16 segundos_crono;
uint16 miliseg_crono;
uint8 iniciar_conteo;
uint8 mostrar_EnCilolcd;
uint8 sacar_adc;
uint16 limite_temp=120;
uint16 limite_hum=80;
uint8 alarma_temPeligro=0;
uint8 alarma_humPeligro=0;
uint8 alarma_ambasPeligro=0;
uint8 alarma_yapasotiempo=0;
uint8 encender_alarma_ambas;
uint16 contador_muestras=0;
uint8 bot1;
uint16 SEGUNDOS=0;
uint16 humedad_medida;
uint16 temperatura_medida;
RTC_TIME_DATE Start;
uint8 apagador_alarmat=0;
uint8 apagador_alarmah=0;
uint8 bandera_alarm;
uint16 counter_buzz=0;
uint16 counter_buzz1=0;
uint8 puerta_puedeAbrirse=1;
int main(void)
{
    CyGlobalIntEnable; // Se inicializan los modulos necesarios
    
//    Start.Sec = 55;
//    Start.Min = 45;
//    Start.Hour = 23;
//    Start.DayOfMonth = 24;
//    Start.Year = 2015;
//    RTC_WriteTime(&Start);
//    
//    RTC_Start();
//    SEGUNDOS = RTC_ReadSecond();
    
    LCD_Start();
    Teclado_Start();
    PWM_Start();
    ADC_Start();
    Contaor_Start();
    AMux_1_Start();
    LED_Driver_1_Start();
    //LED_Driver_1_Write7SegNumberDec(0,0,4,LED_Driver_1_ZERO_PAD);
    LCD_LoadCustomFonts(LCD_customFonts); // Se cargan los custom fonts para el simbolo de grado °
    
    // Se inicializan interrupsiones ISR
    CY_ISR_PROTO(counter_ms);
    CY_ISR_PROTO(keyboard);
    CY_ISR_PROTO(exiit);
    CY_ISR_PROTO(boton1);
    // Mensaje Inicial
    
    LCD_Position(0,3);
    LCD_PrintString("INCUBADORA LISTA");
    LCD_Position(2,3);
    LCD_PrintString("C - CERRAR PUERTA");
    LCD_Position(3,3);
    LCD_PrintString("B - CONFIGURAR");
    
    for(;;){
//        if (SEGUNDOS!=RTC_ReadSecond()){
//            LCD_Position(1,6);
//            LCD_PrintNumber(RTC_ReadHour());
//            LCD_PutChar(':');
//            LCD_PrintNumber(RTC_ReadMinute());
//            LCD_PutChar(':');
//            LCD_PrintNumber(RTC_ReadSecond());
//        }
        ISR_Key_StartEx(keyboard);
        UanMS_StartEx(counter_ms);
        logoutisr_StartEx(exiit);
        isr_b1_StartEx(boton1);
        if (add == 1 && valores_confirmados==0){ // En caso de darle a alguna tecla en el menu de inicio
            tecla = Teclado_AsignarTecla();
            if (tecla=='C' && puerta_cerrada==0){ // SI SE PRESIONA PARA CERRAR
                PWM_WriteCompare((180*100)/9+400); 
                LCD_ClearDisplay();
                LCD_Position(2,3);
                LCD_PrintString("Puerta cerrada");
                CyDelay(1500);
                LCD_ClearDisplay();
                LCD_Position(0,2);
                LCD_PrintString("INCUBADORA LISTA");
                LCD_Position(2,3);
                LCD_PrintString("A - ABRIR PUERTA");
                LCD_Position(3,3);
                LCD_PrintString("B - CONFIGURAR");
                puerta_cerrada=1;
                bot1=0;
            }
            else if (tecla=='A' && puerta_cerrada==1 && puerta_puedeAbrirse==1){
                PWM_WriteCompare(1*100/9+400); 
                LCD_ClearDisplay();
                LCD_Position(2,3);
                LCD_PrintString("Puerta abierta");
                CyDelay(1500);
                LCD_ClearDisplay();
                LCD_Position(0,3);
                LCD_PrintString("INCUBADORA LISTA");
                LCD_Position(2,3);
                LCD_PrintString("C - CERRAR");
                LCD_Position(3,3);
                LCD_PrintString("B - CONFIGURAR");
                puerta_cerrada=0;
                
            }
            else if (tecla == 'B' && puerta_cerrada==1){
                LCD_ClearDisplay();
                LCD_Position(0,0);
                LCD_PrintString("Ingrese los valores:");
                LCD_Position(1,0);
                LCD_PrintString("TEMP: ");
                LCD_Position(2,0);
                LCD_PrintString("HUME: ");
                LCD_Position(3,0);
                LCD_PrintString("Time: ");
                CyDelay(2000);
                ingresando_valores=1;
                puerta_cerrada=0;
                
            }
            if (ingresando_valores==1){
                  
                if (tecla >= 0 && tecla < 10 && temperatura_anadida==0){
                    temp_in=temp_in*10+tecla;
                    LCD_Position(1,6);
                    LCD_PrintNumber(temp_in);
                    LCD_PutChar(LCD_CUSTOM_0); // Simbolo °
                    if (tecla=='#' && temp_in>0 && temp_in<=180){
                        temperatura_anadida=1;
                        
                        //tecla=0;
                        //add=0;
                    }
                    else if (tecla=='#'){
                        temp_in=0;
                    }
                }
                 else if (tecla >= 0 && tecla < 10 && humedad_anadida==0){
                    humedad_in=humedad_in*10+tecla;
                    LCD_Position(2,6);
                    LCD_PrintNumber(humedad_in);
                    LCD_PutChar('%'); // Simbolo %
                    if (tecla=='#' && humedad_in>0 && humedad_in<=180){
                        humedad_anadida=1;
                    }
                    else if (tecla=='#'){
                        humedad_in=0;
                    }
                }
                else if (tecla >= 0 && tecla < 10 && tiempo_anadido==0){
                    tiempo_in=tiempo_in*10+tecla;
                    LCD_Position(3,6);
                    LCD_PrintNumber(tiempo_in);
                    LCD_PutChar('m');
                    if (tecla=='#' && tiempo_in>0 && tiempo_in<=60){
                        tiempo_anadido=1;
                    }
                    else if (tecla=='#'){
                        tiempo_in=0;
                    }
                }
                else if (tecla=='D' && temperatura_anadida==1 && humedad_anadida==1 && tiempo_anadido==1){
                    valores_confirmados=1;
                    ingresando_valores=0;
                }
            }
            add=0;
        }
        if (valores_confirmados==1){
            //INICIA CONTENO, INICIAR AD
            iniciar_conteo=1;
            mostrar_EnCilolcd=1;
            sacar_adc=1;
            valores_confirmados=0;
        }
        if (mostrar_EnCilolcd==1){
            LCD_ClearDisplay();
            LCD_Position(1,0);
            LCD_PrintString("EN CICLO - NO ABRIR");
            mostrar_EnCilolcd=0;
        }
        if (iniciar_conteo==1 && ms1==1){
            
            ms1=0;
            miliseg_crono++;
            if (miliseg_crono==1000){
                
                miliseg_crono=0;
                
                segundos_crono++;
                if (segundos_crono==60){
                    segundos_crono=0;
                    min_crono++;
                }
            }
            LED_Driver_1_Write7SegDigitDec(min_crono/10,0);
            LED_Driver_1_Write7SegDigitDec(min_crono%10,1);
            LED_Driver_1_Write7SegDigitDec(segundos_crono/10,2);
            LED_Driver_1_Write7SegDigitDec(segundos_crono%10,3);
            // AQUI SE DEBE PONER EL CODIGO QUE PONGA LOS MINUTOS Y SEGUNDOS EN EL CONTADOR
            //lUEGUITO LO HAGO YA QUE NISIQUIERA HAY JUMPERS PARA ESO
            if (min_crono==tiempo_in){
                encender_alarma_ambas=1;
                iniciar_conteo=0;
                ciclo_acabado=0;
            }
            
        }
        if (ciclo_acabado==1){
            LCD_CLEAR_DISPLAY;
            LCD_Position(1,0);
            LCD_PrintString("RETIRE LAS MUESTRAS");
        }
        if (sacar_adc==1){
            if (ms2==1){// entra aqui cada ms
                ms2=0;
                contador_muestras++;
                if (contador_muestras%25 == 0){ // entra aqui cada 25 ms
                    
                    //MIDE LAS VARIABLES CON EL ADC
                    AMux_1_Select(1);//HUMEDAD
                    ADC_StartConvert();
                    while(!ADC_IsEndConversion(ADC_RETURN_STATUS)){}
                    senal_hume=ADC_GetResult16();
                    senal_hume=ADC_CountsTo_mVolts(senal_hume);
                    ADC_StopConvert();
                    milivolt_h=(milivolt_h+senal_hume);
                    
                    AMux_1_Select(0);//TEMPERATURA
                    ADC_StartConvert();
                    while(!ADC_IsEndConversion(ADC_RETURN_STATUS)){}
                    senal_temp=ADC_GetResult16();
                    senal_temp=ADC_CountsTo_mVolts(senal_temp);
                    ADC_StopConvert();
                    milivolt_temp=milivolt_temp+senal_temp;
                    
                    if (contador_muestras==500){// ENTRA ACA CADA 20 MUESTRAS, ES DECIR CADA 500 ms
                        contador_muestras=0; // se resetea la bandera
                        milivolt_h=milivolt_h/20; // se saca el promedio de las 20 muetras del peso
                        milivolt_temp=milivolt_temp/20;// se saca el promedio de las 20 muestras de la temp
                            
                        humedad_medida=milivolt_h/50;
                        temperatura_medida=milivolt_temp*0.036;
                             
                        LCD_Position(2,0);
                        LCD_PrintString("humedad= ");
                        LCD_PrintNumber(humedad_medida);
                        LCD_PrintString("%  ");
                        milivolt_h=0;
                        
                        LCD_Position(3,0);
                        LCD_PrintString("Temp= ");
                        LCD_PrintNumber(temperatura_medida);
                        LCD_PutChar(LCD_CUSTOM_0);
                        LCD_PrintString("F   ");
                        milivolt_temp=0;
                    }
                }
            }
            if (temperatura_medida>limite_temp){
                alarma_temPeligro=1;
            }
            else{
                alarma_temPeligro=0;
                apagador_alarmat=0;
            }
            if (humedad_medida>limite_hum){
                alarma_humPeligro=1;
            }
            else{
                alarma_humPeligro=0;
                apagador_alarmah=0;
            }
            if (humedad_medida>limite_hum && temperatura_medida>limite_temp){
                alarma_ambasPeligro=1;
            }
            else {
                alarma_ambasPeligro=0;
            }
            
        }
        
        //ESTADOS DE ADVERTENCIA
        if (alarma_temPeligro==1 && apagador_alarmat==0 && alarma_ambasPeligro==0){
            if (bandera_alarm==1){
                counter_buzz++;
                
                bandera_alarm=0;
                
                if (counter_buzz==500){
                    led_Write(!led_Read());
                    
                    counter_buzz=0;
                }
            }
            bandera_alarm=0;
        }
        if (alarma_humPeligro==0 && apagador_alarmah==0 && alarma_ambasPeligro==0){
            
            if (bandera_alarm==1){
                counter_buzz1++;
                bandera_alarm=0;
                if (counter_buzz1==1000/6){
                    led_Write(!led_Read());
                    counter_buzz1=0;
                }
                bandera_alarm=0;
            }
            
        }
        else if (alarma_ambasPeligro==1 && apagador_alarmah==0 && apagador_alarmat==0){
            led_Write(1);
        }
       if (alarma_ambasPeligro==1 || alarma_humPeligro==1 || alarma_temPeligro==1 || ciclo_acabado==0){
        puerta_puedeAbrirse=0;
        }
        
    }
}

CY_ISR_PROTO(keyboard){
    add = 1;
    
}

CY_ISR_PROTO(counter_ms){
    ms1 = 1;
    ms2=1;
    bandera_alarm=1;
}

CY_ISR_PROTO(exiit){ 
    bot1=1;
    
    
}
CY_ISR_PROTO(boton1){
    apagador_alarmah=1;
    apagador_alarmat=1;
}
uint8 CompararClave(const uint8 *Ingresada, const uint8 *Original){ // Función para comparar claves
    uint8 Aciertos=0;
    uint8 m=0;
    for(m=0;m<4;m++){
        if(*Ingresada==*Original){
            Aciertos++;
        }
    Ingresada++;
    Original++;
    }    
    if (Aciertos==4){ // Solo si la clave esta totalmente buena retorna 1
     return 1;
    }
    else{
    return 0;
    }
}
