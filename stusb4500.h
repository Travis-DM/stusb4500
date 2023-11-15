#ifndef _STUSB4500_H_
#define _STUSB500_H_
#include <Arduino.h>

//Standard Voltages

#define V20     0x190
#define V15     0x12C
#define V12     0x0F0
#define V09     0x0B4
#define V05     0x064

//Standard Currents

#define A0_5    0x032
#define A1_0    0x064     
#define A1_5    0x096
#define A2_0    0x0C8
#define A2_5    0x0FA
#define A3_0    0x12C
#define A3_5    0x15E
#define A4_0    0x190
#define A4_5    0x1C2
#define A5_0    0x1F4



enum FIXEDSUPPLY
{
    PDO_1 =  1,
    PDO_2 =  2,
    PD0_3 =  3
};

enum FRoleSwap
{
    FS_NOT      =   0,
    DEF_USB     =   1,
    A1_5at5V    =   2,
    A3_0at5V    =   3
};

enum setCurretn
{
  _flex_  = 0,
  __50    = 1,
  __75    = 2,
  _1_00    = 3,
  _1_25    = 4,
  _1_50   = 5,
  _1_75   = 6,
  _2_00   = 7,
  _2_25   = 8,
  _2_50   = 9,
  _2_75   = 10,
  _3_00   = 11,
  _3_50   = 12,
  _4_00   = 13,
  _4_50   = 14,
  _5_00   = 15

};


#define BCD_TYPEC_REV_LOW           0x06 
#define BCD_TYPEC_REV_HIGH          0x07
#define BCD_USBPD_REV_LOW           0x08 
#define BCD_USBPD_REV_HIGH          0x09
#define DEVICE_CAPAB_HIGH           0x0A 
#define ALERT_STATUS_1              0x0B 
#define ALERT_STATUS_1_MASK         0x0C 
#define PORT_STATUS_0               0x0D 
#define PORT_STATUS_1               0x0E 
#define TYPEC_MONITORING_STATUS_0   0x0F 
#define TYPEC_MONITORING_STATUS_1   0x10
#define CC_STATUS                   0x11
#define CC_HW_FAULT_STATUS_0        0x12
#define CC_HW_FAULT_STATUS_1        0x13
#define PD_TYPEC_STATUS             0x14
#define TYPEC_STATUS                0x15
#define PRT_STATUS                  0x16
#define PD_COMMAND_CTRL             0x1A
#define MONITORING_CTRL_0           0x20
#define MONITORING_CTRL_1           0x22
#define RESET_CTRL                  0x23
#define VBUS_DISCHARGE_TIME_CTRL    0x25
#define VBUS_DISCHARGE_CTRL         0x26
#define VBUS_CTRL                   0x27
#define PE_FSM                      0x29
#define GPIO_SW_GPIO                0x2D
#define DEVICE_ID                   0x2F
#define RX_HEADER_LOW               0x31
#define RX_HEADER_HIGH              0x32
#define RX_DATA_OBJ1_0              0x33
#define RX_DATA_OBJ1_1              0x34
#define RX_DATA_OBJ1_2              0x35
#define RX_DATA_OBJ1_3              0x36
#define RX_DATA_OBJ2_0              0x37
#define RX_DATA_OBJ2_1              0x38
#define RX_DATA_OBJ2_2              0x39
#define RX_DATA_OBJ2_3              0x3A
#define RX_DATA_OBJ3_0              0x3B
#define RX_DATA_OBJ3_1              0x3C
#define RX_DATA_OBJ3_2              0x3D
#define RX_DATA_OBJ3_3              0x3E
#define RX_DATA_OBJ4_0              0x3F
#define RX_DATA_OBJ4_1              0x40
#define RX_DATA_OBJ4_2              0x41
#define RX_DATA_OBJ4_3              0x42
#define RX_DATA_OBJ5_0              0x43
#define RX_DATA_OBJ5_1              0x44
#define RX_DATA_OBJ5_2              0x45
#define RX_DATA_OBJ5_3              0x46
#define RX_DATA_OBJ6_0              0x47
#define RX_DATA_OBJ6_1              0x48
#define RX_DATA_OBJ6_2              0x49
#define RX_DATA_OBJ6_3              0x4A
#define RX_DATA_OBJ7_0              0x4B
#define RX_DATA_OBJ7_1              0x4C
#define RX_DATA_OBJ7_2              0x4D
#define RX_DATA_OBJ7_3              0x4E
#define TX_HEADER_LOW               0x51
#define TX_HEADER_HIGH              0x52
#define DPM_PDO_NUMB                0x70
#define DPM_SNK_PDO1_0              0x85 
#define DPM_SNK_PDO1_1              0x86
#define DPM_SNK_PDO1_2              0x87
#define DPM_SNK_PDO1_3              0x88
#define DPM_SNK_PDO2_0              0x89
#define DPM_SNK_PDO2_1              0x8A
#define DPM_SNK_PDO2_2              0x8B
#define DPM_SNK_PDO2_3              0x8C
#define DPM_SNK_PDO3_0              0x8D
#define DPM_SNK_PDO3_1              0x8E
#define DPM_SNK_PDO3_2              0x8F
#define DPM_SNK_PDO3_3              0x90 
#define RDO_REG_STATUS_0            0x91 
#define RDO_REG_STATUS_1            0x92 
#define RDO_REG_STATUS_2            0x93 
#define RDO_REG_STATUS_3            0x94


#define Send_Message 0x26
#define Soft_Reset_Message_type  0x0D
#define STUSB_GEN1S_CMD_CTRL 0x1A

typedef union
  {
    uint32_t d32;
    struct
      {
        uint32_t Operationnal_Current :10;
        uint32_t Voltage :10;
        uint8_t Reserved_22_20  :3;
        uint8_t Fast_Role_Req_cur : 2;  /* must be set to 0 in 2.0*/
        uint8_t Dual_Role_Data    :1;
        uint8_t USB_Communications_Capable :1;
        uint8_t Unconstrained_Power :1;
        uint8_t Higher_Capability :1;
        uint8_t Dual_Role_Power :1;
        uint8_t Fixed_Supply :2;            //0
        
      }fix;
    struct
      {
        uint32_t Operating_Current :10;
        uint32_t Min_Voltage:10;
        uint32_t Max_Voltage:10;
        uint8_t VariableSupply:2;           //1
      }var;
    struct
      {
        uint32_t Operating_Power :10;
        uint32_t Min_Voltage:10;
        uint32_t Max_Voltage:10;
        uint8_t Battery:2;                  //2
      }bat;     
    
  }USB_PD_SNK_PDO_TypeDef;

typedef union
{
  uint32_t d32;
  struct
  {     
        uint32_t MaxCurrent                     :       10;
        uint32_t OperatingCurrent               :       10;
        uint8_t reserved_22_20                  :       3;
        uint8_t UnchunkedMess_sup               :       1;
        uint8_t UsbSuspend                      :       1;
        uint8_t UsbComCap                       :       1;
        uint8_t CapaMismatch                    :       1;
        uint8_t GiveBack                        :       1;
        uint8_t Object_Pos                      :       3;
        uint8_t reserved_31		        :	1;
        
  } b;
} STUSB_GEN1S_RDO_REG_STATUS_RegTypeDef;

class STUSB4500
{
private:
    /* data */
public:
    STUSB4500(/* args */);
    ~STUSB4500();
    int initialize(int volts);
    void sw_reset(void);
    int write_pdo(uint32_t pdo_reg, uint8_t reg);
    uint32_t read_pdo(uint8_t pdo);
    int write_rdo(uint32_t rdo_reg);
    uint32_t read_rdo(uint32_t rdo);
};



#endif