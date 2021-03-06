/*
 Implementation of BECKHOFF's ADS protocol. 
 ADS = Automation Device Specification
 Implemented according to specifications given in TwinCAT Information System Nov 2002.
 TwinCAT, ADS and maybe other terms used herein are registered trademarks of BECKHOFF 
 Company. www.beckhoff.de

 Copyright (C) Luis Matos (gass@otiliamatos.ath.cx) 2009, 2012.

 This is free software; you can redistribute it and/or modify
 it under the terms of the GNU Library General Public License as published by
 the Free Software Foundation; either version 2, or (at your option)
 any later version.

 This Software is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

 You should have received a copy of the GNU Library General Public License
 along with this; see the file COPYING.  If not, write to
 the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  
*/

#ifndef __ADSAPI_H__
#define __ADSAPI_H__

#define ADSAPIERR_NOERROR			0x0000
#include "AdsDEF.h"
int AdsPortOpen(void);

long AdsPortClose(void);

long AdsGetLocalAddress(PAmsAddr pAddr);

long AdsSyncWriteControlReq(PAmsAddr pAddr,
			    unsigned short nAdsState,
			    unsigned short nDeviceState,
			    unsigned long nLength, void *pData);

long AdsSyncWriteReq(PAmsAddr pAddr,
		     unsigned long nIndexGroup,
		     unsigned long nIndexOffset,
		     unsigned long nLength, void *pData);

long AdsSyncReadReq(PAmsAddr pAddr,
		    unsigned long nIndexGroup,
		    unsigned long nIndexOffset,
		    unsigned long nLength, void *pData);

long AdsSyncReadStateReq(PAmsAddr pAddr,
			 unsigned short *pAdsState,
			 unsigned short *pDeviceState);

long AdsSyncReadDeviceInfoReq(PAmsAddr pAddr,
			      char *pDevName, PAdsVersion pVersion);

long AdsSyncReadWriteReq(PAmsAddr pAddr,
			 unsigned long nIndexGroup,
			 unsigned long nIndexOffset,
			 unsigned long nReadLength,
			 void *pReadData,
			 unsigned long nWriteLength, void *pWriteData);

long AdsSyncAddDeviceNotificationReq(PAmsAddr pAddr,
				     unsigned long nIndexGroup,
				     unsigned long nIndexOffset,
				     PAdsNotificationAttrib pNoteAttrib,
				     PAdsNotificationFunc pNoteFunc,
				     unsigned long hUser,
				     unsigned long *pNotification);

#endif				/* __ADSAPI_H__ */
