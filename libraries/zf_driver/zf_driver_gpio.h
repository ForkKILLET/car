/*********************************************************************************************************************
* TC264 Opensourec Library 即（TC264 开源库）是一个基于官方 SDK 接口的第三方开源库
* Copyright (c) 2022 SEEKFREE 逐飞科技
*
* 本文件是 TC264 开源库的一部分
*
* TC264 开源库 是免费软件
* 您可以根据自由软件基金会发布的 GPL（GNU General Public License，即 GNU通用公共许可证）的条款
* 即 GPL 的第3版（即 GPL3.0）或（您选择的）任何后来的版本，重新发布和/或修改它
*
* 本开源库的发布是希望它能发挥作用，但并未对其作任何的保证
* 甚至没有隐含的适销性或适合特定用途的保证
* 更多细节请参见 GPL
*
* 您应该在收到本开源库的同时收到一份 GPL 的副本
* 如果没有，请参阅<https://www.gnu.org/licenses/>
*
* 额外注明：
* 本开源库使用 GPL3.0 开源许可证协议 以上许可申明为译文版本
* 许可申明英文版在 libraries/doc 文件夹下的 GPL3_permission_statement.txt 文件中
* 许可证副本在 libraries 文件夹下 即该文件夹下的 LICENSE 文件
* 欢迎各位使用并传播本程序 但修改内容时必须保留逐飞科技的版权声明（即本声明）
*
* 文件名称          zf_driver_gpio
* 公司名称          成都逐飞科技有限公司
* 版本信息          查看 libraries/doc 文件夹内 version 文件 版本说明
* 开发环境          ADS v1.9.20
* 适用平台          TC264D
* 店铺链接          https://seekfree.taobao.com/
*
* 修改记录
* 日期              作者                备注
* 2022-09-15       pudding            first version
********************************************************************************************************************/

#ifndef _zf_driver_gpio_h_
#define _zf_driver_gpio_h_

#include "IFXPORT.h"
#include "zf_common_typedef.h"

typedef enum // 枚举端口 此枚举定义不允许用户修改
{
    // 在设置IO时请自行根据硬件确认当前芯片是否具有此IO

    // 需要特别注意P20_2是不能用于输出的，仅仅只有输入的功能   TC264DA芯片的21.6无法正常使用
    // 需要特别注意P20_2是不能用于输出的，仅仅只有输入的功能   TC264DA芯片的21.6无法正常使用
    // 需要特别注意P20_2是不能用于输出的，仅仅只有输入的功能   TC264DA芯片的21.6无法正常使用

    P00_0 = 0*32,  P00_1, P00_2,  P00_3,  P00_4,  P00_5,  P00_6,  P00_7,
    P00_8,         P00_9, P00_10, P00_11, P00_12, P00_13, P00_14, P00_15,

    P02_0 = 2*32,  P02_1, P02_2,  P02_3,  P02_4,  P02_5,  P02_6,  P02_7,
    P02_8,         P02_9, P02_10, P02_11, P02_12, P02_13, P02_14, P02_15,

    P10_0 = 10*32, P10_1, P10_2,  P10_3,  P10_4,  P10_5,  P10_6,  P10_7,
    P10_8,         P10_9, P10_10, P10_11, P10_12, P10_13, P10_14, P10_15,

    P11_0 = 11*32, P11_1, P11_2,  P11_3,  P11_4,  P11_5,  P11_6,  P11_7,
    P11_8,         P11_9, P11_10, P11_11, P11_12, P11_13, P11_14, P11_15,

    P13_0 = 13*32, P13_1, P13_2,  P13_3,  P13_4,  P13_5,  P13_6,  P13_7,
    P13_8,         P13_9, P13_10, P13_11, P13_12, P13_13, P13_14, P13_15,

    P14_0 = 14*32, P14_1, P14_2,  P14_3,  P14_4,  P14_5,  P14_6,  P14_7,
    P14_8,         P14_9, P14_10, P14_11, P14_12, P14_13, P14_14, P14_15,

    P15_0 = 15*32, P15_1, P15_2,  P15_3,  P15_4,  P15_5,  P15_6,  P15_7,
    P15_8,         P15_9, P15_10, P15_11, P15_12, P15_13, P15_14, P15_15,

    P20_0 = 20*32, P20_1, P20_2,  P20_3,  P20_4,  P20_5,  P20_6,  P20_7,
    P20_8,         P20_9, P20_10, P20_11, P20_12, P20_13, P20_14, P20_15,

    P21_0 = 21*32, P21_1, P21_2,  P21_3,  P21_4,  P21_5,  P21_6,  P21_7,
    P21_8,         P21_9, P21_10, P21_11, P21_12, P21_13, P21_14, P21_15,

    P22_0 = 22*32, P22_1, P22_2,  P22_3,  P22_4,  P22_5,  P22_6,  P22_7,
    P22_8,         P22_9, P22_10, P22_11, P22_12, P22_13, P22_14, P22_15,

    P23_0 = 23*32, P23_1, P23_2,  P23_3,  P23_4,  P23_5,  P23_6,  P23_7,
    P23_8,         P23_9, P23_10, P23_11, P23_12, P23_13, P23_14, P23_15,

    P32_0 = 32*32, P32_1, P32_2,  P32_3,  P32_4,  P32_5,  P32_6,  P32_7,
    P32_8,         P32_9, P32_10, P32_11, P32_12, P32_13, P32_14, P32_15,

    P33_0 = 33*32, P33_1, P33_2,  P33_3,  P33_4,  P33_5,  P33_6,  P33_7,
    P33_8,         P33_9, P33_10, P33_11, P33_12, P33_13, P33_14, P33_15,

}gpio_pin_enum;

typedef enum               // 枚举端口方向    此枚举定义不允许用户修改
{
    GPI = 0,               // 定义管脚输入方向
    GPO = 1,               // 定义管脚输出方向
}gpio_dir_enum;

typedef enum               // 枚举端口电平    此枚举定义不允许用户修改
{
    GPIO_LOW =  0,         // 定义低电平
    GPIO_HIGH = 1,         // 定义高电平
}gpio_level_enum;

typedef enum               // 枚举端口模式   此枚举定义不允许用户修改
{
    GPI_FLOATING_IN,       // 定义管脚浮空输入
    GPI_PULL_UP    ,       // 定义管脚上拉输入
    GPI_PULL_DOWN  ,       // 定义管脚下拉输入

    GPO_PUSH_PULL  ,       // 定义管脚推挽输出
    GPO_OPEN_DTAIN ,       // 定义管脚开漏输出
}gpio_mode_enum;

//====================================================GPIO 快捷函数====================================================
Ifx_P*      get_port                    (gpio_pin_enum pin);
#define     get_port_in_addr(pin)       (uint8 *)(&IfxPort_getAddress((IfxPort_Index)(pin/32))->IN + pin%32/8)
#define     get_port_out_addr(port)     (((Ifx_P *)IfxPort_cfg_indexMap[port].module)->OUT.U)

//------------------------------------------------------------------------------------------------------------------
// 函数简介     对应 IO 置位为高电平
// 参数说明     x           选择的引脚 (可选择范围由 zf_driver_gpio.h 内 gpio_pin_enum 枚举值确定)
// 返回参数     void
// 使用示例     gpio_high(P00_0);// P00_0 输出高电平
// 备注信息
//------------------------------------------------------------------------------------------------------------------
#define     gpio_high(x)                (get_port(x))->OMR.U = 1 << ((x)&0x1f)       // GPIO置位 (get_port(x))->OMR.U = 1 << ((x)&0x1f)

//------------------------------------------------------------------------------------------------------------------
// 函数简介     对应 IO 置位为低电平
// 参数说明     x           选择的引脚 (可选择范围由 zf_driver_gpio.h 内 gpio_pin_enum 枚举值确定)
// 返回参数     void
// 使用示例     gpio_low(P00_0);// P00_0 输出低电平
// 备注信息
//------------------------------------------------------------------------------------------------------------------
#define     gpio_low(x)                 (get_port(x))->OMR.U = 65536 << ((x)&0x1f)   // GPIO复位 (get_port(x))->OMR.U = 65536 << ((x)&0x1f)

//====================================================GPIO 快捷函数====================================================

//====================================================GPIO 基础函数====================================================
void  gpio_set_level    (gpio_pin_enum pin, uint8 dat);
uint8 gpio_get_level    (gpio_pin_enum pin);
void  gpio_toggle_level (gpio_pin_enum pin);
void  gpio_set_dir      (gpio_pin_enum pin, gpio_dir_enum dir, gpio_mode_enum pinconf);
void  gpio_init         (gpio_pin_enum pin, gpio_dir_enum dir, uint8 dat, gpio_mode_enum pinconf);
//====================================================GPIO 基础函数====================================================

//==================================================兼容旧版本开源库接口名称=================================================
#ifdef COMPATIBLE_WITH_OLDER_VERSIONS
#define     gpio_set(pin, dat)          (gpio_set_level((pin), (dat)))
#define     gpio_get(pin)               (gpio_get_level((pin)))
#define     gpio_dir(pin, dir, mode)    (gpio_set_dir((pin), (dir), (mode)))
#define     gpio_toggle(pin)            (gpio_toggle_level((pin)))
#endif
//==================================================兼容旧版本开源库接口名称=================================================

#endif
