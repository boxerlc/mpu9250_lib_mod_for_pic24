/* 
 * File:   inv_mpl_porting.h
 * Author: larry
 *
 * Created on October 21, 2015, 5:33 PM
 */

#ifndef INV_MPL_PORTING_H
#define	INV_MPL_PORTING_H

#ifdef	__cplusplus
extern "C" {
#endif

#define ACCEL_ON        (0x01)
#define GYRO_ON         (0x02)
#define COMPASS_ON      (0x04)

#define MOTION          (0)
#define NO_MOTION       (1)
	/* Starting sampling rate. */
#define DEFAULT_MPU_HZ  (20)

#define FLASH_SIZE      (512)
#define FLASH_MEM_START ((void*)0x1800)

#define PEDO_READ_MS    (1000)
#define TEMP_READ_MS    (500)
#define COMPASS_READ_MS (100)
struct rx_s {
    uint8_t header[3];
    uint8_t cmd;
};
struct hal_s {
    uint8_t lp_accel_mode;
    uint8_t sensors;
    uint8_t dmp_on;
    uint8_t wait_for_tap;
    volatile uint8_t new_gyro;
    uint8_t motion_int_mode;
    uint32_t no_dmp_hz;
    uint32_t next_pedo_ms;
    uint32_t next_temp_ms;
    uint32_t next_compass_ms;
    uint16_t report;
    uint16_t dmp_features;
    struct rx_s rx;
};
struct platform_data_s {
    int8_t orientation[9];
};

#ifdef	__cplusplus
}
#endif

#endif	/* INV_MPL_PORTING_H */

