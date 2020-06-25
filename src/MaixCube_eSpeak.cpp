#include "MaixCube_eSpeak.h"
#include "audio_speaker.h"

MaixCubeESpeak::MaixCubeESpeak(){

}

MaixCubeESpeak::~MaixCubeESpeak(){
    
}

int SynthCallback(short *wav, int numsamples, espeak_EVENT *events) {
    if (wav == NULL) {
        return 1; // NULL means done.
    }

	while (audio_speaker_get_state() == PLAY_STATE_PLAYING) {}
	audio_speaker_set_buffer(wav, numsamples);
	audio_speaker_play();

    return 0; // 0 continues synthesis, 1 aborts 
}

int
MaixCubeESpeak::begin()
{
    audio_speaker_init();
//    sysctl_pll_set_freq(SYSCTL_PLL2, 361267200UL);
    sysctl_pll_set_freq(SYSCTL_PLL2, 352800000UL);
    audio_speaker_set_sample_rate(22050);

	int sample_rate = espeak_Initialize(AUDIO_OUTPUT_RETRIEVAL, 0, NULL, 0);
	espeak_SetSynthCallback(&SynthCallback);

    return 0;
}

int
MaixCubeESpeak::speak(char * text)
{
	espeak_Synth(text, strlen(text)+1, 0, POS_CHARACTER, 0, espeakCHARS_AUTO, NULL, NULL);

	espeak_Synchronize();

    return 0;
}

int
MaixCubeESpeak::end()
{
	espeak_Terminate();

    return 0;
}
