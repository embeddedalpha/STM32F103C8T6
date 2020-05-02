#ifndef _GNSS_MSG_FILE_H_
#define _GNSS_MSG_FILE_H_




/*******************************************************************************************/
/*******************************  CDB-ID 201 - CDB-ID 228 fields description****************/
/*******************************************************************************************/

#define $GPGNS               0x1
#define $GPGGA               0x2
#define $GPGSA               0x4
#define $GPGST               0x8
#define $GPVTG               0x10
#define $PSTMNOISE           0x20
#define $GPRMC               0x40
#define $PSTMRF              0x80
#define $PSTMTG              0x100
#define $PSTMTS              0x200
#define $PSTMPA              0x400
#define $PSTMSAT             0x800
#define $PSTMRES             0x1000
#define $PSTMTIM             0x2000
#define $PSTMWAAS            0x4000
#define $PSTMDIFF            0x8000
#define $PSTMCORR            0x10000
#define $PSTMSBAS            0x20000
#define $PSTMTESTRF          0x40000
#define $GPGSV               0x80000
#define $GPGLL               0x100000
#define $PSTMPPSDATA         0x200000
#define $PSTMCPU             0x800000
#define $GPZDA               0x1000000
#define $PSTMTRAIMSTATUS     0x2000000
#define $PSTMPOSHOLD         0x4000000
#define $PSTMKFCOV           0x8000000
#define $PSTMAGPS            0x10000000
#define $PSTMLOWPOWERDATA    0x20000000
#define $PSTMNOTCHSTATUS     0x40000000
#define $PSTMTM              0x80000000















#endif

