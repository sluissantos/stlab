#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include "esp_log.h"
#include "esp_err.h"
#include "driver/i2c.h"
#include "freertos/portmacro.h"
#include "AXP2101Constants.h"
#include "utilities.h"

#define TAG_XPOWER                              "XPOWER"

#define XPOWERSLIB_I2C_MASTER_TX_BUF_DISABLE   0                          /*!< I2C master doesn't need buffer */
#define XPOWERSLIB_I2C_MASTER_RX_BUF_DISABLE   0                          /*!< I2C master doesn't need buffer */
#define XPOWERSLIB_I2C_MASTER_TIMEOUT_MS       1000

#define XPOWERSLIB_I2C_MASTER_SEEED            400000

#ifdef _BV
#undef _BV
#endif
#define _BV(b)                          (1ULL << (uint64_t)(b))

#ifndef constrain
#define constrain(amt,low,high) ((amt)<(low)?(low):((amt)>(high)?(high):(amt)))
#endif

#define XPOWERS_ATTR_NOT_IMPLEMENTED    __attribute__((error("Not implemented")))
#define IS_BIT_SET(val,mask)            (((val)&(mask)) == (mask))

#define LOW                 0x0
#define HIGH                0x1

//GPIO FUNCTIONS
#define INPUT               0x01
#define OUTPUT              0x03
#define PULLUP              0x04
#define INPUT_PULLUP        0x05
#define PULLDOWN            0x08
#define INPUT_PULLDOWN      0x09

#define RISING              0x01
#define FALLING             0x02

typedef int (*iic_fptr_t)(uint8_t devAddr, uint8_t regAddr, uint8_t *data, uint8_t len);

bool initImplXPower();
bool setInterruptImpl(uint32_t opts, bool enable);

bool enableIRQ(uint64_t opt);
bool disableIRQ(uint64_t opt);

bool getProtectedChannel(uint8_t channel);

bool clrRegisterBit(uint8_t registers, uint8_t bit);

void xpowerInit(void);

void xpowerDeinit(void);

/**
 * @brief PMU PEKEY Press off time parameters.
 */
typedef enum __xpowers_press_off_time {
    XPOWERS_POWEROFF_4S,
    XPOWERS_POWEROFF_6S,
    XPOWERS_POWEROFF_8S,
    XPOWERS_POWEROFF_10S,
} xpowers_press_off_time_t;

/**
 * @brief PMU PEKEY Press on time parameters.
 */
typedef enum __xpowers_press_on_time {
    XPOWERS_POWERON_128MS,
    XPOWERS_POWERON_512MS,
    XPOWERS_POWERON_1S,
    XPOWERS_POWERON_2S,
} xpowers_press_on_time_t;

/**
 * @brief Charging led mode parameters.
 */
typedef enum __xpowers_chg_led_mode {
    XPOWERS_CHG_LED_OFF,
    XPOWERS_CHG_LED_BLINK_1HZ,
    XPOWERS_CHG_LED_BLINK_4HZ,
    XPOWERS_CHG_LED_ON,
    XPOWERS_CHG_LED_CTRL_CHG,    // The charging indicator is controlled by the charger
} xpowers_chg_led_mode_t;

/**
 * @brief axp2101 charge target voltage parameters.
 */
typedef enum __xpowers_axp2101_chg_vol {
    XPOWERS_AXP2101_CHG_VOL_4V = 1,
    XPOWERS_AXP2101_CHG_VOL_4V1,
    XPOWERS_AXP2101_CHG_VOL_4V2,
    XPOWERS_AXP2101_CHG_VOL_4V35,
    XPOWERS_AXP2101_CHG_VOL_4V4,
    XPOWERS_AXP2101_CHG_VOL_MAX
} xpowers_axp2101_chg_vol_t;

/**
 * @brief axp2101 charge currnet voltage parameters.
 */
typedef enum __xpowers_axp2101_chg_curr {
    XPOWERS_AXP2101_CHG_CUR_0MA,
    XPOWERS_AXP2101_CHG_CUR_100MA = 4,
    XPOWERS_AXP2101_CHG_CUR_125MA,
    XPOWERS_AXP2101_CHG_CUR_150MA,
    XPOWERS_AXP2101_CHG_CUR_175MA,
    XPOWERS_AXP2101_CHG_CUR_200MA,
    XPOWERS_AXP2101_CHG_CUR_300MA,
    XPOWERS_AXP2101_CHG_CUR_400MA,
    XPOWERS_AXP2101_CHG_CUR_500MA,
    XPOWERS_AXP2101_CHG_CUR_600MA,
    XPOWERS_AXP2101_CHG_CUR_700MA,
    XPOWERS_AXP2101_CHG_CUR_800MA,
    XPOWERS_AXP2101_CHG_CUR_900MA,
    XPOWERS_AXP2101_CHG_CUR_1000MA,
} xpowers_axp2101_chg_curr_t;

/**
 * @brief axp2101 vbus currnet limit parameters.
 */
typedef enum {
    XPOWERS_AXP2101_VBUS_CUR_LIM_100MA,
    XPOWERS_AXP2101_VBUS_CUR_LIM_500MA,
    XPOWERS_AXP2101_VBUS_CUR_LIM_900MA,
    XPOWERS_AXP2101_VBUS_CUR_LIM_1000MA,
    XPOWERS_AXP2101_VBUS_CUR_LIM_1500MA,
    XPOWERS_AXP2101_VBUS_CUR_LIM_2000MA,
} xpowers_axp2101_vbus_cur_limit_t;

/**
 * @brief XPowersLibInterface interrupt control mask parameters.
 *          Common interrupt interfaces
 * @Example: enableInterrupt(XPOWERS_USB_INSERT_INT|XPOWERS_USB_REMOVE_INT);
 *           disableInterrupt(XPOWERS_CHARGE_START_INT|XPOWERS_PWR_BTN_CLICK_INT);
 */
typedef enum __xpowers_interrupt_enum {
    XPOWERS_USB_INSERT_INT          = _BV(0),
    XPOWERS_USB_REMOVE_INT          = _BV(1),
    XPOWERS_BATTERY_INSERT_INT      = _BV(2),
    XPOWERS_BATTERY_REMOVE_INT      = _BV(3),
    XPOWERS_CHARGE_START_INT        = _BV(4),
    XPOWERS_CHARGE_DONE_INT         = _BV(5),
    XPOWERS_PWR_BTN_CLICK_INT       = _BV(6),
    XPOWERS_PWR_BTN_LONGPRESSED_INT = _BV(7),
    XPOWERS_ALL_INT                 = _BV(8),
} xpowers_interrupt_enum_t;

/**
 * @brief axp2101 interrupt control mask parameters.
 */
typedef enum __xpowers_axp2101_irq {
    //! IRQ1 REG 40H
    XPOWERS_AXP2101_BAT_NOR_UNDER_TEMP_IRQ   = _BV(0),   // Battery Under Temperature in Work
    XPOWERS_AXP2101_BAT_NOR_OVER_TEMP_IRQ    = _BV(1),   // Battery Over Temperature in Work mode
    XPOWERS_AXP2101_BAT_CHG_UNDER_TEMP_IRQ   = _BV(2),   // Battery Under Temperature in Charge mode IRQ(bcut_irq)
    XPOWERS_AXP2101_BAT_CHG_OVER_TEMP_IRQ    = _BV(3),   // Battery Over Temperature in Charge mode IRQ(bcot_irq) enable
    XPOWERS_AXP2101_GAUGE_NEW_SOC_IRQ        = _BV(4),   // Gauge New SOC IRQ(lowsoc_irq) enable ???
    XPOWERS_AXP2101_WDT_TIMEOUT_IRQ          = _BV(5),   // Gauge Watchdog Timeout IRQ(gwdt_irq) enable
    XPOWERS_AXP2101_WARNING_LEVEL1_IRQ       = _BV(6),   // SOC drop to Warning Level1 IRQ(socwl1_irq) enable
    XPOWERS_AXP2101_WARNING_LEVEL2_IRQ       = _BV(7),   // SOC drop to Warning Level2 IRQ(socwl2_irq) enable

    //! IRQ2 REG 41H
    XPOWERS_AXP2101_PKEY_POSITIVE_IRQ        = _BV(8),   // POWERON Positive Edge IRQ(ponpe_irq_en) enable
    XPOWERS_AXP2101_PKEY_NEGATIVE_IRQ        = _BV(9),   // POWERON Negative Edge IRQ(ponne_irq_en) enable
    XPOWERS_AXP2101_PKEY_LONG_IRQ            = _BV(10),  // POWERON Long PRESS IRQ(ponlp_irq) enable
    XPOWERS_AXP2101_PKEY_SHORT_IRQ           = _BV(11),  // POWERON Short PRESS IRQ(ponsp_irq_en) enable
    XPOWERS_AXP2101_BAT_REMOVE_IRQ           = _BV(12),  // Battery Remove IRQ(bremove_irq) enable
    XPOWERS_AXP2101_BAT_INSERT_IRQ           = _BV(13),  // Battery Insert IRQ(binsert_irq) enabl
    XPOWERS_AXP2101_VBUS_REMOVE_IRQ          = _BV(14),  // VBUS Remove IRQ(vremove_irq) enabl
    XPOWERS_AXP2101_VBUS_INSERT_IRQ          = _BV(15),  // VBUS Insert IRQ(vinsert_irq) enable

    //! IRQ3 REG 42H
    XPOWERS_AXP2101_BAT_OVER_VOL_IRQ         = _BV(16),  // Battery Over Voltage Protection IRQ(bovp_irq) enable
    XPOWERS_AXP2101_CHAGER_TIMER_IRQ         = _BV(17),  // Charger Safety Timer1/2 expire IRQ(chgte_irq) enable
    XPOWERS_AXP2101_DIE_OVER_TEMP_IRQ        = _BV(18),  // DIE Over Temperature level1 IRQ(dotl1_irq) enable
    XPOWERS_AXP2101_BAT_CHG_START_IRQ        = _BV(19),  // Charger start IRQ(chgst_irq) enable
    XPOWERS_AXP2101_BAT_CHG_DONE_IRQ         = _BV(20),  // Battery charge done IRQ(chgdn_irq) enable
    XPOWERS_AXP2101_BATFET_OVER_CURR_IRQ     = _BV(21),  // BATFET Over Current Protection IRQ(bocp_irq) enable
    XPOWERS_AXP2101_LDO_OVER_CURR_IRQ        = _BV(22),  // LDO Over Current IRQ(ldooc_irq) enable
    XPOWERS_AXP2101_WDT_EXPIRE_IRQ           = _BV(23),  // Watchdog Expire IRQ(wdexp_irq) enable

    XPOWERS_AXP2101_ALL_IRQ                  = (0xFFFFFFFFUL)
} xpowers_axp2101_irq_t;

// @brief Each chip resource is different,please refer to the table above
typedef enum __XPowersPowerChannel {

    XPOWERS_DCDC1,
    XPOWERS_DCDC2,
    XPOWERS_DCDC3,
    XPOWERS_DCDC4,
    XPOWERS_DCDC5,

    XPOWERS_LDO1,
    XPOWERS_LDO2,
    XPOWERS_LDO3,
    XPOWERS_LDO4,
    XPOWERS_LDO5,

    XPOWERS_LDOIO,

    XPOWERS_ALDO1,
    XPOWERS_ALDO2,
    XPOWERS_ALDO3,
    XPOWERS_ALDO4,

    XPOWERS_BLDO1,
    XPOWERS_BLDO2,

    XPOWERS_DLDO1,
    XPOWERS_DLDO2,

    XPOWERS_VBACKUP,

    XPOWERS_CPULDO,

} XPowersPowerChannel_t;

// @brief Chip type
typedef enum __XPowersChipModel {
    XPOWERS_AXP173,
    XPOWERS_AXP192,
    XPOWERS_AXP202,
    XPOWERS_AXP216,
    XPOWERS_AXP2101,
    XPOWERS_UNDEFINED,
} XPowersChipModel_t;


typedef enum {
    XPOWERS_AXP2101_IRQ_TIME_1S,
    XPOWERS_AXP2101_IRQ_TIME_1S5,
    XPOWERS_AXP2101_IRQ_TIME_2S,
    XPOWERS_AXP2101_PRESSOFF_2S5,
} xpowers_irq_time_t;



typedef enum {
    XPOWERS_AXP2101_PRECHARGE_0MA,
    XPOWERS_AXP2101_PRECHARGE_25MA,
    XPOWERS_AXP2101_PRECHARGE_50MA,
    XPOWERS_AXP2101_PRECHARGE_75MA,
    XPOWERS_AXP2101_PRECHARGE_100MA,
    XPOWERS_AXP2101_PRECHARGE_125MA,
    XPOWERS_AXP2101_PRECHARGE_150MA,
    XPOWERS_AXP2101_PRECHARGE_175MA,
    XPOWERS_AXP2101_PRECHARGE_200MA,
} xpowers_prechg_t;

typedef enum {
    XPOWERS_AXP2101_CHG_ITERM_0MA,
    XPOWERS_AXP2101_CHG_ITERM_25MA,
    XPOWERS_AXP2101_CHG_ITERM_50MA,
    XPOWERS_AXP2101_CHG_ITERM_75MA,
    XPOWERS_AXP2101_CHG_ITERM_100MA,
    XPOWERS_AXP2101_CHG_ITERM_125MA,
    XPOWERS_AXP2101_CHG_ITERM_150MA,
    XPOWERS_AXP2101_CHG_ITERM_175MA,
    XPOWERS_AXP2101_CHG_ITERM_200MA,
} xpowers_axp2101_chg_iterm_t;


typedef enum {
    XPOWERS_AXP2101_THREMAL_60DEG,
    XPOWERS_AXP2101_THREMAL_80DEG,
    XPOWERS_AXP2101_THREMAL_100DEG,
    XPOWERS_AXP2101_THREMAL_120DEG,
} xpowers_thermal_t;

typedef enum {
    XPOWERS_AXP2101_CHG_TRI_STATE,   //tri_charge
    XPOWERS_AXP2101_CHG_PRE_STATE,   //pre_charge
    XPOWERS_AXP2101_CHG_CC_STATE,    //constant charge
    XPOWERS_AXP2101_CHG_CV_STATE,    //constant voltage
    XPOWERS_AXP2101_CHG_DONE_STATE,  //charge done
    XPOWERS_AXP2101_CHG_STOP_STATE,  //not chargin
} xpowers_chg_status_t;

typedef enum {
    XPOWERS_AXP2101_WAKEUP_IRQ_PIN_TO_LOW = _BV(4),
    XPOWERS_AXP2101_WAKEUP_PWROK_TO_LOW   = _BV(3),
    XPOWERS_AXP2101_WAKEUP_DC_DLO_SELECT  = _BV(2),
} xpowers_wakeup_t;

typedef enum {
    XPOWERS_AXP2101_FAST_DCDC1,
    XPOWERS_AXP2101_FAST_DCDC2,
    XPOWERS_AXP2101_FAST_DCDC3,
    XPOWERS_AXP2101_FAST_DCDC4,
    XPOWERS_AXP2101_FAST_DCDC5,
    XPOWERS_AXP2101_FAST_ALDO1,
    XPOWERS_AXP2101_FAST_ALDO2,
    XPOWERS_AXP2101_FAST_ALDO3,
    XPOWERS_AXP2101_FAST_ALDO4,
    XPOWERS_AXP2101_FAST_BLDO1,
    XPOWERS_AXP2101_FAST_BLDO2,
    XPOWERS_AXP2101_FAST_CPUSLDO,
    XPOWERS_AXP2101_FAST_DLDO1,
    XPOWERS_AXP2101_FAST_DLDO2,
} xpowers_fast_on_opt_t;


typedef enum {
    XPOWERS_AXP2101_SEQUENCE_LEVEL_0,
    XPOWERS_AXP2101_SEQUENCE_LEVEL_1,
    XPOWERS_AXP2101_SEQUENCE_LEVEL_2,
    XPOWERS_AXP2101_SEQUENCE_DISABLE,
} xpower_start_sequence_t;

typedef enum {
    XPOWERS_AXP2101_WDT_IRQ_TO_PIN,             //Just interrupt to pin
    XPOWERS_AXP2101_WDT_IRQ_AND_RSET,           //IRQ to pin and reset pmu system
    XPOWERS_AXP2101_WDT_IRQ_AND_RSET_PD_PWROK,  //IRQ to pin and reset pmu system,pull down pwrok
    XPOWERS_AXP2101_WDT_IRQ_AND_RSET_ALL_OFF,   //IRQ to pin and reset pmu system,turn off dcdc & ldo ,pull down pwrok
} xpowers_wdt_config_t;

typedef enum {
    XPOWERS_AXP2101_WDT_TIMEOUT_1S,
    XPOWERS_AXP2101_WDT_TIMEOUT_2S,
    XPOWERS_AXP2101_WDT_TIMEOUT_4S,
    XPOWERS_AXP2101_WDT_TIMEOUT_8S,
    XPOWERS_AXP2101_WDT_TIMEOUT_16S,
    XPOWERS_AXP2101_WDT_TIMEOUT_32S,
    XPOWERS_AXP2101_WDT_TIMEOUT_64S,
    XPOWERS_AXP2101_WDT_TIMEOUT_128S,
} xpowers_wdt_timeout_t;



typedef enum {
    XPOWERS_AXP2101_VBUS_VOL_LIM_3V88,
    XPOWERS_AXP2101_VBUS_VOL_LIM_3V96,
    XPOWERS_AXP2101_VBUS_VOL_LIM_4V04,
    XPOWERS_AXP2101_VBUS_VOL_LIM_4V12,
    XPOWERS_AXP2101_VBUS_VOL_LIM_4V20,
    XPOWERS_AXP2101_VBUS_VOL_LIM_4V28,
    XPOWERS_AXP2101_VBUS_VOL_LIM_4V36,
    XPOWERS_AXP2101_VBUS_VOL_LIM_4V44,
    XPOWERS_AXP2101_VBUS_VOL_LIM_4V52,
    XPOWERS_AXP2101_VBUS_VOL_LIM_4V60,
    XPOWERS_AXP2101_VBUS_VOL_LIM_4V68,
    XPOWERS_AXP2101_VBUS_VOL_LIM_4V76,
    XPOWERS_AXP2101_VBUS_VOL_LIM_4V84,
    XPOWERS_AXP2101_VBUS_VOL_LIM_4V92,
    XPOWERS_AXP2101_VBUS_VOL_LIM_5V,
    XPOWERS_AXP2101_VBUS_VOL_LIM_5V08,
} xpower_vbus_vol_limit_t;

typedef enum {
    XPOWERS_AXP2101_VSYS_VOL_4V1,
    XPOWERS_AXP2101_VSYS_VOL_4V2,
    XPOWERS_AXP2101_VSYS_VOL_4V3,
    XPOWERS_AXP2101_VSYS_VOL_4V4,
    XPOWERS_AXP2101_VSYS_VOL_4V5,
    XPOWERS_AXP2101_VSYS_VOL_4V6,
    XPOWERS_AXP2101_VSYS_VOL_4V7,
    XPOWERS_AXP2101_VSYS_VOL_4V8,
} xpower_chg_dpm_t;

typedef enum {
    XPOWER_POWERON_SRC_POWERON_LOW,                     //POWERON low for on level when POWERON Mode as POWERON Source
    XPOWER_POWERON_SRC_IRQ_LOW,                         //IRQ PIN Pull-down as POWERON Source
    XPOWER_POWERON_SRC_VBUS_INSERT,                     //Vbus Insert and Good as POWERON Source
    XPOWER_POWERON_SRC_BAT_CHARGE,                      //Vbus Insert and Good as POWERON Source
    XPOWER_POWERON_SRC_BAT_INSERT,                      //Battery Insert and Good as POWERON Source
    XPOWER_POWERON_SRC_ENMODE,                          //POWERON always high when EN Mode as POWERON Source
    XPOWER_POWERON_SRC_UNKONW,                          //Unkonw
} xpower_power_on_source_t;

typedef enum {
    XPOWER_POWEROFF_SRC_PWEKEY_PULLDOWN,            //POWERON Pull down for off level when POWERON Mode as POWEROFF Source
    XPOWER_POWEROFF_SRC_SOFT_OFF,                   //Software configuration as POWEROFF Source
    XPOWER_POWEROFF_SRC_PWEKEY_LOW,                 //POWERON always low when EN Mode as POWEROFF Source
    XPOWER_POWEROFF_SRC_UNDER_VSYS,                 //Vsys Under Voltage as POWEROFF Source
    XPOWER_POWEROFF_SRC_OVER_VBUS,                  //VBUS Over Voltage as POWEROFF Source
    XPOWER_POWEROFF_SRC_UNDER_VOL,                  //DCDC Under Voltage as POWEROFF Source
    XPOWER_POWEROFF_SRC_OVER_VOL,                   //DCDC Over Voltage as POWEROFF Source
    XPOWER_POWEROFF_SRC_OVER_TEMP,                  //Die Over Temperature as POWEROFF Source
    XPOWER_POWEROFF_SRC_UNKONW,                     //Unkonw
} xpower_power_off_source_t;

typedef enum {
    XPOWER_PWROK_DELAY_8MS,
    XPOWER_PWROK_DELAY_16MS,
    XPOWER_PWROK_DELAY_32MS,
    XPOWER_PWROK_DELAY_64MS,
} xpower_pwrok_delay_t;

