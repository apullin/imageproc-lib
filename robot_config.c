#include "robot_config.h"
#include "dfmem.h"
#include "string.h"
#include "stdlib.h"

robotConfig currentConfig;

#define ROBOTCONFIG_DFMEM_PAGE 0
#define ROBOTCONFIG_DFMEM_BYTE 0

void robotConfigSetup(){
    //TODO: add a check to make sure that dfmem page size > robotConfigStruct_t size

    currentConfig = malloc(sizeof(robotConfigStruct_t));

    //On startup, get config stored in flash
    if(currentConfig != NULL){
        robotConfigLoadFlash();
    }
}

//Loads bytes from dfmem into the robotConfig pointed to in this module
void robotConfigLoadFlash(){
    //Simple dfmem read of data
    dfmemRead(ROBOTCONFIG_DFMEM_PAGE, ROBOTCONFIG_DFMEM_BYTE,
            sizeof(robotConfigStruct_t), (unsigned char *)currentConfig);
}

//Saves current robot config to nonvolatile storage in dfmem
void robotConfigWriteFlash(){
    //Storage page much be erased first
    dfmemErasePage(ROBOTCONFIG_DFMEM_PAGE);
    //Write new page to buffer
    dfmemSave((unsigned char*) currentConfig, sizeof(robotConfigStruct_t));
    //Force write to actual flash chip immediately
    dfmemSync();
}

//Copies the current config to the destination pointer
void robotConfigGet(robotConfig cfg){
    if(currentConfig != NULL){
        memcpy(cfg, currentConfig, sizeof(currentConfig));
    }
}

//Copies a new config to the current config; does NOT save to flash!
void robotConfigUpdate(robotConfig cfg){
    if(currentConfig != NULL){
        memcpy(currentConfig, cfg, sizeof(currentConfig));
    }
}