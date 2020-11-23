/*
 * File: coder_assumptions.h
 *
 * Abstract: Coder assumptions header file
 */

#ifndef CODER_ASSUMPTIONS_H
#define CODER_ASSUMPTIONS_H

/* include model specific checks */
#include "Madgwick_embedded_ca.h"

/* global results variable mapping for static code */
#define CA_Expected_HWImpl             CA_Madgwick_embedded_ExpHW
#define CA_Actual_HWImpl               CA_Madgwick_embedded_ActHW
#define CA_HWImpl_Results              CA_Madgwick_embedded_HWRes
#define CA_PortableWordSizes_Results   CA_Madgwick_embedded_PWSRes

/* entry point function mapping for static code */
#define CA_Run_Tests                   Madgwick_embedded_caRunTests
#endif                                 /* CODER_ASSUMPTIONS_H */
