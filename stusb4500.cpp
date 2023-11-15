#include <Arduino.h>
#include "stusb4500.h"
#include <Wire.h>

STUSB4500::STUSB4500(/* args */)
{
}

STUSB4500::~STUSB4500()
{
}




//uint32_t STUSB4500::build_pdo(PDO_REG pdo_reg)
//{

//}


int STUSB4500::initialize(int volts)
{
    USB_PD_SNK_PDO_TypeDef usb_pd;
    Wire2.beginTransmission(0x28);
    Wire2.write(0x0D);;
    if (Wire2.endTransmission() != 0X00)
    {
        //I2C Device not found
        return -1;
    }
    else{
    Wire2.requestFrom(0x28,10);
        for (int x = 0x0D; x <= 0x16;x++);
        {
            //dummy read 
            Wire2.read();
        }
        Wire2.endTransmission();
        Wire2.beginTransmission(0x28);
        Wire2.write(0x0C);
        Wire2.write(0x00);
        Wire2.endTransmission();

        /*
        usb_pd.var.Max_Voltage = 1000;
        usb_pd.var.VariableSupply = 1;
        usb_pd.var.Min_Voltage = 600;
        usb_pd.var.Operating_Current = 300;*/
        usb_pd.fix.Voltage = volts * 20;
        usb_pd.fix.Operationnal_Current = 100;
        usb_pd.fix.Dual_Role_Data = 1;
        usb_pd.fix.Dual_Role_Power = 1;
        usb_pd.fix.Fixed_Supply = 0;
        usb_pd.fix.Higher_Capability = 1;
        Wire2.beginTransmission(0x28);
        Wire2.write(0x89);
        Serial.printf("%x\n",usb_pd.d32);
        Serial.printf("%x\n",usb_pd);
        Wire2.write(usb_pd.d32 & 0xFF);
        Wire2.write((usb_pd.d32 & 0xFF00) >> 8);
        Wire2.write((usb_pd.d32 & 0xFF0000) >> 16);
        Wire2.write((usb_pd.d32 & 0xFF000000 )>> 24);
        Wire2.endTransmission();
        Wire2.beginTransmission(0x28);
        Wire2.write(TX_HEADER_LOW);
        Wire2.write(Soft_Reset_Message_type);
        Wire2.endTransmission();
        Wire2.beginTransmission(0x28);
        Wire2.write(PD_COMMAND_CTRL);
        Wire2.write(Send_Message);
        Wire2.endTransmission();
        
        //soft reset
        sw_reset();
    }
    return 0;

}

void STUSB4500::sw_reset(void)
{
    Wire2.beginTransmission(0x28);
    Wire2.write(0x51);
    Wire2.write(0x0D);
    Wire2.endTransmission();
    
    Wire2.beginTransmission(0x28);
    Wire2.write(0x1A);
    Wire2.write(0x26);
    Wire2.endTransmission();
}