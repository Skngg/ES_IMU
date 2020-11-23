/*
 * File: Madgwick_embedded_ca.c
 *
 * Abstract: Tests assumptions in the generated code.
 */

#include "Madgwick_embedded_ca.h"

CA_HWImpl_TestResults CA_Madgwick_embedded_HWRes;
CA_PWS_TestResults CA_Madgwick_embedded_PWSRes;
const CA_HWImpl CA_Madgwick_embedded_ExpHW = {
  8,                                   /* BitPerChar */
  16,                                  /* BitPerShort */
  32,                                  /* BitPerInt */
  32,                                  /* BitPerLong */
  64,                                  /* BitPerLongLong */
  32,                                  /* BitPerFloat */
  64,                                  /* BitPerDouble */
  64,                                  /* BitPerPointer */
  64,                                  /* BitPerSizeT */
  64,                                  /* BitPerPtrDiffT */
  CA_LITTLE_ENDIAN,                    /* Endianess */
  CA_ZERO,                             /* IntDivRoundTo */
  1,                                   /* ShiftRightIntArith */
  1,                                   /* LongLongMode */
  0,                                   /* PortableWordSizes */
  "Intel->x86-64 (Windows64)",         /* HWDeviceType */
  0,                                   /* MemoryAtStartup */
  0,                                   /* DenormalFlushToZero */
  0                                    /* DenormalAsZero */
};

CA_HWImpl CA_Madgwick_embedded_ActHW;
void Madgwick_embedded_caRunTests(void)
{
  /* verify hardware implementation */
  caVerifyPortableWordSizes(&CA_Madgwick_embedded_ActHW,
    &CA_Madgwick_embedded_ExpHW, &CA_Madgwick_embedded_PWSRes);
  caVerifyHWImpl(&CA_Madgwick_embedded_ActHW, &CA_Madgwick_embedded_ExpHW,
                 &CA_Madgwick_embedded_HWRes);
}
