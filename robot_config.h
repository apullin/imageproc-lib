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

    //Encoders
    unsigned char ams_enc_offset_0;
    unsigned char ams_enc_offset_1;

} robotConfigStruct_t;

typedef robotConfigStruct_t* robotConfig;

void robotConfigLoadFlash();
void robotConfigWriteFlash();
void robotConfigGet(robotConfig cfg);
void robotConfigUpdate(robotConfig cfg);


void robotConfigSetup();

#endif	/* ROBOT_CONFIG_H */

