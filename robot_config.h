/* 
 * File:   robot_config.h
 * Author: pullin
 *
 * Created on March 12, 2015, 11:46 PM
 */

#ifndef ROBOT_CONFIG_H
#define	ROBOT_CONFIG_H

typedef struct {
    //Radio setup
    unsigned char radio_channel;
    unsigned char radio_pan_addr;
    unsigned char radio_src_addr;

    //Leg setup
    unsigned char left_legs_pid_num;
    unsigned char left_legs_enc_num;
    unsigned char left_legs_enc_flip;
    unsigned char left_legs_pwm_flip;
    unsigned char left_legs_tih_chan;
    //right legs
    unsigned char right_legs_pid_num;
    unsigned char right_legs_enc_num;
    unsigned char right_legs_flip;
    unsigned char right_legs_pwm_flip;
    unsigned char right_legs_tih_chan;

    //PID controllers
    int Kp1, Ki1, Kd1, Kaw1, Kff1;
    int Kp2, Ki2, Kd2, Kaw2, Kff2;

    //Encoders
    unsigned char ams_enc_offset_0;
    unsigned char ams_enc_offset_1;
    unsigned char ams_enc_offset_2;
    unsigned char ams_enc_offset_3;

    //IMU calibrations
    //TODO: this needs to be reviewed and content decided on
    //int xlOffsetX, xlOffsetY, xlOffsetZ;
    //int xlScaleX, xlScaleY, xlScaleZ; //MPU6000 should have factory calibrated scales

} robotConfigStruct_t;

typedef robotConfigStruct_t* robotConfig;

void robotConfigLoadFlash();
void robotConfigWriteFlash();
void robotConfigGet(robotConfig cfg);
void robotConfigUpdate(robotConfig cfg);


void robotConfigSetup();

#endif	/* ROBOT_CONFIG_H */

