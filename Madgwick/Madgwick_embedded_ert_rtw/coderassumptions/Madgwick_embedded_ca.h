/*
 * File: Madgwick_embedded_ca.h
 *
 * Abstract: Tests assumptions in the generated code.
 */

#ifndef MADGWICK_EMBEDDED_CA_H
#define MADGWICK_EMBEDDED_CA_H

/* preprocessor validation checks */
#include "Madgwick_embedded_ca_preproc.h"
#include "coder_assumptions_hwimpl.h"

/* variables holding test results */
extern CA_HWImpl_TestResults CA_Madgwick_embedded_HWRes;
extern CA_PWS_TestResults CA_Madgwick_embedded_PWSRes;

/* variables holding "expected" and "actual" hardware implementation */
extern const CA_HWImpl CA_Madgwick_embedded_ExpHW;
extern CA_HWImpl CA_Madgwick_embedded_ActHW;

/* entry point function to run tests */
void Madgwick_embedded_caRunTests(void);

#endif                                 /* MADGWICK_EMBEDDED_CA_H */
