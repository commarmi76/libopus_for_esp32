# libopus_for_esp32
Experiments to port libopus encode/decoder to esp32

Original sources by the authors of Opus: http://opus-codec.org

Use opus-1.2.1 and libopusenc-0.1

=================================================================================

13200580 microseconds To encode Sample16kHz.raw (little-endian) data, 16 bit, stereo 16000 Hz 10 seconds

=================================================================================

TODO:

- Encode something infinite to check memory leaks
- Profile to find the heaviest parts
- Investigate esp32 dsp features: Vectra LX DSP Engine, MAC16
- Streaming over tcp and http

=================================================================================
