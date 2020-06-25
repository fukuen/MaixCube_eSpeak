#ifndef __MAIXCUBE_ESPEAK_H
#define __MAIXCUBE_ESPEAK_H

#include <espeak-ng/espeak_ng.h>
#include <espeak-ng/speak_lib.h>

/*
#include "Arduino.h"

#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
*/
#include "sysctl.h"
/*ß
#include "plic.h"
#include "uarths.h"
#include "util/g_def.h"
#include "i2s.h"

#include "util/VAD.h"
#include "util/MFCC.h"
#include "util/DTW.h"
#include "util/flash.h"
#include "util/ADC.h"
*/

class MaixCubeESpeak{
public:
    MaixCubeESpeak();
    ~MaixCubeESpeak();
    int begin();
    int speak(char * text);
    int end();
    
};

#endif