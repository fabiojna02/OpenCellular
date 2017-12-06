/* Copyright 2017 The Chromium OS Authors. All rights reserved.
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

/* Zoombini board configuration */

#ifndef __CROS_EC_BOARD_H
#define __CROS_EC_BOARD_H

/* Optional features */
#define CONFIG_HIBERNATE_PSL
#define CONFIG_SYSTEM_UNLOCKED /* Allow dangerous commands. */
#define CONFIG_CMD_PPC_DUMP

/* NPCX7 config */
#define NPCX_UART_MODULE2 1  /* GPIO64/65 are used as UART pins. */
#define NPCX_TACH_SEL2    0  /* No tach. */
#define NPCX7_PWM1_SEL    0  /* GPIO C2 is not used as PWM1. */

/* Internal SPI flash on NPCX7 */
#define CONFIG_FLASH_SIZE (512 * 1024) /* It's really 1MB. */
#define CONFIG_SPI_FLASH_REGS
#define CONFIG_SPI_FLASH_W25Q80 /* Internal SPI flash type. */

/* EC Modules */
#define CONFIG_ADC
#define CONFIG_ESPI
/* TODO(aaboagye): Uncomment when Si arrives. */
/* #define CONFIG_ESPI_VW_SIGNALS */
#define CONFIG_I2C
#define CONFIG_LPC
#define CONFIG_PWM

#define CONFIG_BATTERY_SMART
#define CONFIG_BATTERY_PRESENT_GPIO GPIO_BAT_PRESENT_L

#define CONFIG_BOARD_VERSION

#ifdef BOARD_ZOOMBINI
#define CONFIG_BC12_DETECT_BQ24392
#endif /* defined(BOARD_ZOOMBINI) */
#define CONFIG_CHARGER
#define CONFIG_CHARGER_V2
#define CONFIG_CHARGE_MANAGER
#define CONFIG_CHARGER_INPUT_CURRENT 128
#define CONFIG_CHARGER_ISL9238
#define CONFIG_CHARGER_MIN_BAT_PCT_FOR_POWER_ON 1
#define CONFIG_CHARGER_SENSE_RESISTOR 10
#define CONFIG_CHARGER_SENSE_RESISTOR_AC 20
#ifdef BOARD_ZOOMBINI
#define CONFIG_CHARGE_RAMP_HW
#define CONFIG_USB_CHARGER
#endif /* defined(BOARD_ZOOMBINI) */

#define CONFIG_CHIPSET_CANNONLAKE
#define CONFIG_CHIPSET_RESET_HOOK
#define CONFIG_EXTPOWER_GPIO
#define CONFIG_POWER_COMMON
#define CONFIG_POWER_BUTTON
#define CONFIG_POWER_BUTTON_X86
#define CONFIG_POWER_PP5000_CONTROL
#define CONFIG_POWER_S0IX
#define CONFIG_POWER_TRACK_HOST_SLEEP_STATE
#define CONFIG_UART_HOST 0

#define CONFIG_I2C_MASTER

#ifdef BOARD_ZOOMBINI
#define CONFIG_KEYBOARD_BOARD_CONFIG
#define CONFIG_KEYBOARD_COL2_INVERTED
#define CONFIG_KEYBOARD_PROTOCOL_8042
#define CONFIG_PWM_KBLIGHT
#define CONFIG_SWITCH
#endif /* defined(BOARD_ZOOMBINI) */

/* TODO(aaboagye): Eventually, enable MKBP for zoombini as well. */
#ifdef BOARD_MEOWTH
#define CONFIG_MKBP_EVENT
#define CONFIG_MKBP_USE_HOST_EVENT
#define CONFIG_KEYBOARD_PROTOCOL_MKBP
#endif /* defined(BOARD_MEOWTH) */

#define CONFIG_USB_POWER_DELIVERY
#define CONFIG_USB_PD_ALT_MODE
#define CONFIG_USB_PD_ALT_MODE_DFP
#ifdef BOARD_ZOOMBINI
#define CONFIG_USB_PD_PORT_COUNT 3
#else
#define CONFIG_USB_PD_PORT_COUNT 2
#endif /* defined(BOARD_ZOOMBINI) */
#define CONFIG_USB_PD_DUAL_ROLE
#define CONFIG_USB_PD_LOGGING
/* TODO(aaboagye): What about CONFIG_USB_PD_MAX_SINGLE_SOURCE_CURRENT? */
#define CONFIG_USB_PD_VBUS_DETECT_TCPC
#define CONFIG_USB_PD_TCPM_PS8805
#define CONFIG_USB_PD_TCPM_TCPCI
#define CONFIG_USB_PD_TCPM_MUX
#define CONFIG_USBC_PPC_SN5S330
#define CONFIG_USBC_SS_MUX
#define CONFIG_USBC_VCONN
#define CONFIG_USBC_VCONN_SWAP

#define CONFIG_VBOOT_HASH
#define CONFIG_VOLUME_BUTTONS

#ifdef BOARD_ZOOMBINI
/* USB Type-A Port BC1.2 support */
#define CONFIG_USB_PORT_POWER_SMART
#undef CONFIG_USB_PORT_POWER_SMART_PORT_COUNT
#define CONFIG_USB_PORT_POWER_SMART_PORT_COUNT 1
#define CONFIG_USB_PORT_POWER_SMART_CDP_SDP_ONLY
#define GPIO_USB1_ILIM_SEL GPIO_USB_A_HIGH_POWER_EN
#endif /* defined(BOARD_ZOOMBINI) */

/* Define typical operating power and max power. */
#define PD_MAX_VOLTAGE_MV 20000
#define PD_MAX_CURRENT_MA 3000
#define PD_MAX_POWER_MW 60000
#define PD_OPERATING_POWER_MW 15000
#define PD_VCONN_SWAP_DELAY 5000 /* us */

/* TODO(aaboagye): Verify these timings... */
/*
 * delay to turn on the power supply max is ~16ms.
 * delay to turn off the power supply max is about ~180ms.
 */
#define PD_POWER_SUPPLY_TURN_ON_DELAY	30000  /* us */
#define PD_POWER_SUPPLY_TURN_OFF_DELAY	250000 /* us */

/* I2C Ports */
/* Zoombini I2C config */
#ifdef BOARD_ZOOMBINI
#define I2C_PORT_BATTERY I2C_PORT_POWER
#define I2C_PORT_CHARGER I2C_PORT_POWER
#define I2C_PORT_POWER   NPCX_I2C_PORT0_0
#define I2C_PORT_PMIC    NPCX_I2C_PORT3_0
#define I2C_PORT_SENSOR  NPCX_I2C_PORT7_0
#define I2C_PORT_TCPC0   NPCX_I2C_PORT1_0
#define I2C_PORT_TCPC1   NPCX_I2C_PORT2_0
#define I2C_PORT_TCPC2   NPCX_I2C_PORT5_0

#define GPIO_TCPC0_SCL GPIO_I2C1_SCL
#define GPIO_TCPC0_SDA GPIO_I2C1_SDA
#define GPIO_TCPC1_SCL GPIO_I2C2_SCL
#define GPIO_TCPC1_SDA GPIO_I2C2_SDA
#define GPIO_TCPC2_SCL GPIO_I2C5_SCL
#define GPIO_TCPC2_SDA GPIO_I2C5_SDA

#else /* Meowth I2C config */
#define I2C_PORT_CHARGER NPCX_I2C_PORT4_1
#define I2C_PORT_BATTERY NPCX_I2C_PORT0_0
#define I2C_PORT_PMIC    NPCX_I2C_PORT3_0
#define I2C_PORT_SENSOR  NPCX_I2C_PORT7_0
#define I2C_PORT_TCPC0   NPCX_I2C_PORT5_0
#define I2C_PORT_TCPC1   NPCX_I2C_PORT1_0

#define GPIO_TCPC0_SCL GPIO_I2C5_SCL
#define GPIO_TCPC0_SDA GPIO_I2C5_SDA
#define GPIO_TCPC1_SCL GPIO_I2C1_SCL
#define GPIO_TCPC1_SDA GPIO_I2C1_SDA
#endif /* defined(BOARD_ZOOMBINI) */

#define PMIC_I2C_ADDR TPS650X30_I2C_ADDR1

#ifdef BOARD_MEOWTH
#define PP5000_PGOOD_POWER_SIGNAL_MASK 0
#else
#define PP5000_PGOOD_POWER_SIGNAL_MASK \
POWER_SIGNAL_MASK(PP5000_PGOOD)
#endif /* defined(BOARD_MEOWTH) */

#ifndef __ASSEMBLER__

#include "gpio_signal.h"
#include "registers.h"

/* ADC signal */
enum adc_channel {
	ADC_VBUS = -1,
	ADC_TEMP_SENSOR_SOC,
	ADC_TEMP_SENSOR_CHARGER,
#ifdef BOARD_MEOWTH
	ADC_TEMP_SENSOR_WIFI,
#endif /* defined(BOARD_MEOWTH) */
	ADC_CH_COUNT
};

enum pwm_channel {
	PWM_CH_LED_GREEN = 0,
	PWM_CH_LED_RED,
	PWM_CH_KBLIGHT,
	PWM_CH_COUNT
};

enum power_signal {
	X86_SLP_S0_DEASSERTED,
	X86_SLP_S3_DEASSERTED,
	X86_SLP_S4_DEASSERTED,
	X86_SLP_SUS_DEASSERTED,
	X86_RSMRST_L_PGOOD,
	X86_PMIC_DPWROK,
#ifdef BOARD_ZOOMBINI
	PP5000_PGOOD,
#endif /* defined(BOARD_ZOOMBINI) */
	POWER_SIGNAL_COUNT
};

/* Reset all TCPCs. */
void board_reset_pd_mcu(void);

#endif /* !defined(__ASSEMBLER__) */

#endif /* __CROS_EC_BOARD_H */
