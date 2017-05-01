#include "opus_test.h"

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include <assert.h>
#include <esp_types.h>
#include <stdio.h>
#include "rom/ets_sys.h"
#include "esp_heap_alloc_caps.h"
#include <stdlib.h>
#include <string.h>
#include "opus.h"
#include "ogg/ogg.h"


#include <sys/time.h>

extern const uint8_t Sample16kHz_raw_start[] asm("_binary_Sample16kHz_raw_start");
extern const uint8_t Sample16kHz_raw_end[]   asm("_binary_Sample16kHz_raw_end");

#define FRAME_SIZE 960
#define SAMPLE_RATE 16000
#define CHANNELS 2
#define APPLICATION OPUS_APPLICATION_AUDIO
#define BITRATE 64000
#define MAX_FRAME_SIZE 6*960
#define MAX_PACKET_SIZE (3*1276)

void opus_test()
{

	//   opus_int16 in[FRAME_SIZE*CHANNELS];
	   opus_int16 out[MAX_FRAME_SIZE*CHANNELS];
	   unsigned char cbits[MAX_PACKET_SIZE];
	   int nbBytes;
	   /*Holds the state of the encoder and decoder */
	   OpusEncoder *encoder;
	   int err;
	   size_t free8start, free32start;
	   short int *pcm_samples, *pcm_samples_end;
	   int num_samples_encoded = 0, total=0, frames=0;
	   struct timeval tvalBefore, tvalFirstFrame, tvalAfter;

	  free8start=xPortGetFreeHeapSizeCaps(MALLOC_CAP_8BIT);
	  free32start=xPortGetFreeHeapSizeCaps(MALLOC_CAP_32BIT);
	  printf("pre  opus_encoder_create free mem8bit: %d mem32bit: %d\n",free8start,free32start);


	   /*Create a new encoder state */
	      encoder = opus_encoder_create(SAMPLE_RATE, CHANNELS, APPLICATION, &err);
	      if (err<0)
	      {
	         printf("failed to create an encoder: %s\n", opus_strerror(err));
	         return ;
	      }
	      /* Set the desired bit-rate. You can also set other parameters if needed.
	         The Opus library is designed to have good defaults, so only set
	         parameters you know you need. Doing otherwise is likely to result
	         in worse quality, but better. */


//	       opus_encoder_ctl(encoder, OPUS_SET_COMPLEXITY(complexity));

	      err = opus_encoder_ctl(encoder, OPUS_SET_VBR(1));

	      err = opus_encoder_ctl(encoder, OPUS_SET_BITRATE(BITRATE));
	      if (err<0)
	      {
	         printf("failed to set bitrate: %s\n", opus_strerror(err));
	         return ;
	      }

		  free8start=xPortGetFreeHeapSizeCaps(MALLOC_CAP_8BIT);
		  free32start=xPortGetFreeHeapSizeCaps(MALLOC_CAP_32BIT);
		  printf("post  opus_encoder_create free mem8bit: %d mem32bit: %d\n",free8start,free32start);


		pcm_samples = (short int *)Sample16kHz_raw_start;
		pcm_samples_end = (short int *)Sample16kHz_raw_end;


		gettimeofday (&tvalBefore, NULL);
 while ( pcm_samples_end - pcm_samples > 0)
		   //for (int j=0;j<1;j++)
		   {
		  //	     printf("\n=============== opus_encode================ \n");
		   /* encode samples. */
		  	   num_samples_encoded = opus_encode(encoder, pcm_samples, FRAME_SIZE, cbits, MAX_PACKET_SIZE);

	//	       printf("number of samples encoded = %d pcm_samples %p \n", num_samples_encoded, pcm_samples);

		  	  if (total==0) gettimeofday (&tvalFirstFrame, NULL);

		       /* check for value returned.*/
		       if(num_samples_encoded > 1) {
		  //       printf("It seems the conversion was successful.\n");
		      	 total+=num_samples_encoded;
		       } else {
		         printf("Error %d.\n",num_samples_encoded);
		         return ;
		       }


		      // printf("Contents of mp3buffer = ");
		    /*   for(int i = 0; i < num_samples_encoded; i++) {
		      	 printf("%02X", mp3buf[i]);
		       }
		  */
		      pcm_samples += (FRAME_SIZE*2);  // nsamples*2 ????
		      frames++;

		  #if 0
		      // to test infinite loop
		      if ( pcm_samples_end - pcm_samples <= 0){
		      	pcm_samples = (short int *)Sample16kHz_raw_start;
		      	free8start=xPortGetFreeHeapSizeCaps(MALLOC_CAP_8BIT);
		      	free32start=xPortGetFreeHeapSizeCaps(MALLOC_CAP_32BIT);
		      	printf("LOOP: free mem8bit: %d mem32bit: %d frames encoded: %d bytes:%d\n",free8start,free32start,frames,total);
		      }
		  #endif
		   }

		   gettimeofday (&tvalAfter, NULL);

		   printf("Fist Frame time in microseconds: %ld microseconds\n",
		               ((tvalFirstFrame.tv_sec - tvalBefore.tv_sec)*1000000L
		              +tvalFirstFrame.tv_usec) - tvalBefore.tv_usec
		             );


		   printf("Total time in microseconds: %ld microseconds\n",
		               ((tvalAfter.tv_sec - tvalBefore.tv_sec)*1000000L
		              +tvalAfter.tv_usec) - tvalBefore.tv_usec
		             );

		   printf ("Total frames: %d TotalBytes: %d\n", frames, total);

		  opus_encoder_destroy(encoder);

	      while (1) vTaskDelay(500 / portTICK_RATE_MS);

	      return;

}

