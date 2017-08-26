#include "opus_test.h"

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include <assert.h>
#include <esp_types.h>
#include <stdio.h>
#include "rom/ets_sys.h"
#include "esp_heap_caps.h"
#include <stdlib.h>
#include <string.h>
#include "opus.h"
#include "opusenc.h"

#include <sys/time.h>

extern const uint8_t Sample16kHz_raw_start[] asm("_binary_Sample16kHz_raw_start");
extern const uint8_t Sample16kHz_raw_end[]   asm("_binary_Sample16kHz_raw_end");

#define READ_SIZE 256
//#define FRAME_SIZE 960
#define SAMPLE_RATE 16000
#define CHANNELS 2
//#define APPLICATION OPUS_APPLICATION_AUDIO
//#define BITRATE 64000
//#define MAX_FRAME_SIZE 6*960
//#define MAX_PACKET_SIZE (3*1276)

void opus_test()
{
      OggOpusEnc *enc;
      OggOpusComments *comments;
	  int error;
	  size_t free8start, free32start;
	  short int *pcm_samples, *pcm_samples_end;
	  int num_samples_encoded = 0, total=0, frames=0;
	  struct timeval tvalBefore, tvalFirstFrame, tvalAfter;
      unsigned char *page;
      int len; 

	  pcm_samples = (short int *)Sample16kHz_raw_start;
	  pcm_samples_end = (short int *)Sample16kHz_raw_end;

      comments = ope_comments_create();
      ope_comments_add(comments, "ARTIST", "Someone");
      ope_comments_add(comments, "TITLE", "Some track");


   //   enc = ope_encoder_create_file2(fout, comments, 16000, 2, 0, &error);
      enc = ope_encoder_create_pull(comments, 16000 , 2, 0, &error);
      if (!enc) {
           fprintf(stderr, "cannout open output file\n");
           return ; }

		gettimeofday (&tvalBefore, NULL);
 while ( pcm_samples_end - pcm_samples > 0)
		   //for (int j=0;j<1;j++)
		   {
//		  	     printf("\n=============== opus_encode================ \n");
		   /* encode samples. */
              if (ope_encoder_write(enc, pcm_samples, READ_SIZE) != 0) {printf("Encoding error\n");return;}
              num_samples_encoded = READ_SIZE;

              while ( ope_encoder_get_page(enc, &page, &len, 0) )
                {
		         //for(int i = 0; i < len; i++) printf("%02X", page[i]);
		         frames++;
                }

		  	  if (total==0) gettimeofday (&tvalFirstFrame, NULL);

		       /* check for value returned.*/
		       if(num_samples_encoded > 1) {
		  //       printf("It seems the conversion was successful.\n");
		      	 total+=num_samples_encoded;
		       } else {
		         printf("Error %d.\n",num_samples_encoded);
		         return ;
		       }


		      pcm_samples += (READ_SIZE*2);  // nsamples*2 ????

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


	      while (1) vTaskDelay(500 / portTICK_RATE_MS);

	      return;

}

