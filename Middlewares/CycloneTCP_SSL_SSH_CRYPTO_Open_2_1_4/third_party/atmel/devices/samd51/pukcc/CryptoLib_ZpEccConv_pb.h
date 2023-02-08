/**
 * \file
 *
 * \brief Structure definition for PUKCL 'ZpEccConv' service
 *
 * Copyright (c) 2017-2018 Microchip Technology Inc. and its subsidiaries.
 *
 * \asf_license_start
 *
 * \page License
 *
 * Subject to your compliance with these terms, you may use Microchip
 * software and any derivatives exclusively with Microchip products.
 * It is your responsibility to comply with third party license terms applicable
 * to your use of third party software (including open source software) that
 * may accompany Microchip software.
 *
 * THIS SOFTWARE IS SUPPLIED FOR DEMONSTRATION PURPOSES AS AN EXAMPLE.
 *
 * THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". THERE IS NO
 * SECURITY BUILT INTO THIS SOFTWARE. NO WARRANTIES,WHETHER
 * EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE,
 * INCLUDING ANY IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY,
 * AND FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT WILL MICROCHIP BE
 * LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, INCIDENTAL OR CONSEQUENTIAL
 * LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND WHATSOEVER RELATED TO THE
 * SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS BEEN ADVISED OF THE
 * POSSIBILITY OR THE DAMAGES ARE FORESEEABLE.  TO THE FULLEST EXTENT
 * ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN ANY WAY
 * RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
 * THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
 *
 * \asf_license_stop
 *
 */

#ifndef _CRYPTOLIBZPECCCONV_INCLUDED
#define _CRYPTOLIBZPECCCONV_INCLUDED

// Structure definition
typedef struct _PUKCL_ZpEcConvProjToAffine {
	nu1 nu1ModBase;
	nu1 nu1CnsBase;
	u2  u2ModLength;

	nu1 nu1PointABase;
	nu1 __Padding0;
	nu1 nu1Workspace;
} _PUKCL_ZPECCONVPROJTOAFFINE, *_PPUKCL_ZPECCONVPROJTOAFFINE;

typedef struct _PUKCL_ZpEcConvAffineToProjective {
	nu1 nu1ModBase;
	nu1 nu1CnsBase;
	u2  u2ModLength;

	nu1 nu1PointABase;
	nu1 __Padding0;
	nu1 nu1Workspace;
	nu1 __Padding1;
	nu1 __Padding2;
	nu1 __Padding3;
	nu1 __Padding4;
} _PUKCL_ZPECCONVAFFINETOPROJECTIVE, *_PPUKCL_ZPECCONVAFFINETOPROJECTIVE;

typedef struct _PUKCL_ZpEcPointIsOnCurve {
	nu1 nu1ModBase;
	nu1 nu1CnsBase;
	u2  u2ModLength;

	nu1 nu1AParam;
	nu1 nu1BParam;
	nu1 nu1PointBase;
	nu1 nu1Workspace;
	u2  __Padding0;
	u2  __Padding1;
} _PUKCL_ZPECPOINTISONCURVE, *_PPUKCL_ZPECPOINTISONCURVE;

typedef struct _PUKCL_ZpEcRandomiseCoordinate {
	nu1 nu1ModBase;
	nu1 nu1CnsBase;
	u2  u2ModLength;

	nu1 nu1PointBase;
	nu1 nu1RandomBase;
	nu1 nu1Workspace;
	nu1 __Padding0;
	nu1 __Padding1;
	nu1 __Padding2;
	nu1 __Padding3;
} _PUKCL_ZPECRANDOMIZECOORDINATE, *_PPUKCL_ZPECRANDOMIZECOORDINATE;

#endif // _CRYPTOLIBZPECCCONV_INCLUDED
