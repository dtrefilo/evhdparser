#pragma once
#include <ntifs.h>
#include <srb.h>
#include <scsi.h>
#include <ntddscsi.h>

typedef enum _SCSI_OP_CODE {
	SCSI_OP_CODE_TEST_UNIT_READY = 0x00,
	SCSI_OP_CODE_REWIND = 0x01,
	SCSI_OP_CODE_REQUEST_SENSE = 0x03,
	SCSI_OP_CODE_FORMAT = 0x04,
	SCSI_OP_CODE_READ_BLOCK_LIMITS = 0x05,
	SCSI_OP_CODE_REASSIGN_BLOCKS = 0x07,
	SCSI_OP_CODE_INITIALIZE_ELEMENT_STATUS = 0x07,
	SCSI_OP_CODE_READ_6 = 0x08,
	SCSI_OP_CODE_WRITE_6 = 0x0A,
	SCSI_OP_CODE_SEEK_6 = 0x0B,
	SCSI_OP_CODE_READ_REVERSE_6 = 0x0F,
	SCSI_OP_CODE_WRITE_FILEMARKS_6 = 0x10,
	SCSI_OP_CODE_SPACE_6 = 0x11,
	SCSI_OP_CODE_INQUIRY = 0x12,
	SCSI_OP_CODE_VERIFY_6 = 0x13,
	SCSI_OP_CODE_RECOVER_BUFFERED_DATA = 0x14,
	SCSI_OP_CODE_MODE_SELECT_6 = 0x15,
	SCSI_OP_CODE_RESERVE_6 = 0x16,
	SCSI_OP_CODE_RELEASE_6 = 0x17,
	SCSI_OP_CODE_COPY = 0x18,
	SCSI_OP_CODE_ERASE_6 = 0x19,
	SCSI_OP_CODE_MODE_SENSE_6 = 0x1A,
	SCSI_OP_CODE_START_STOP_UNIT = 0x1B,
	SCSI_OP_CODE_LOAD_UNLOAD = 0x1B,
	SCSI_OP_CODE_RECEIVE_DIAGNOSTIC_RESULTS = 0x1C,
	SCSI_OP_CODE_SEND_DIAGNOSTIC = 0x1D,
	SCSI_OP_CODE_PREVENT_ALLOW_MEDIUM_REMOVAL = 0x1E,
	SCSI_OP_CODE_READ_FORMAT_CAPACITIES = 0x23,
	SCSI_OP_CODE_READ_CAPACITY_10 = 0x25,
	SCSI_OP_CODE_READ_10 = 0x28,
	SCSI_OP_CODE_READ_GENERATION = 0x29,
	SCSI_OP_CODE_WRITE_10 = 0x2A,
	SCSI_OP_CODE_SEEK_10 = 0x2B,
	SCSI_OP_CODE_LOCATE_10 = 0x2B,
	SCSI_OP_CODE_ERASE_10 = 0x2C,
	SCSI_OP_CODE_READ_UPDATED_BLOCK = 0x2D,
	SCSI_OP_CODE_WRITE_AND_VERIFY_10 = 0x2E,
	SCSI_OP_CODE_VERIFY_10 = 0x2F,
	SCSI_OP_CODE_SET_LIMITS_10 = 0x33,
	SCSI_OP_CODE_PREFETCH_10 = 0x34,
	SCSI_OP_CODE_READ_POSITION = 0x34,
	SCSI_OP_CODE_SYNCHRONIZE_CACHE_10 = 0x35,
	SCSI_OP_CODE_LOCK_UNLOCK_CACHE_10 = 0x36,
	SCSI_OP_CODE_READ_DEFECT_DATA_10 = 0x37,
	SCSI_OP_CODE_INITIALIZE_ELEMENT_STATUS_WITH_RANGE = 0x37,
	SCSI_OP_CODE_MEDIUM_SCAN = 0x38,
	SCSI_OP_CODE_COMPARE = 0x39,
	SCSI_OP_CODE_COPY_AND_VERIFY = 0x3A,
	SCSI_OP_CODE_WRITE_BUFFER = 0x3B,
	SCSI_OP_CODE_READ_BUFFER = 0x3C,
	SCSI_OP_CODE_UPDATE_BLOCK = 0x3D,
	SCSI_OP_CODE_READ_LONG_10 = 0x3E,
	SCSI_OP_CODE_WRITE_LONG_10 = 0x3F,
	SCSI_OP_CODE_CHANGE_DEFINITION = 0x40,
	SCSI_OP_CODE_WRITE_SAME_10 = 0x41,
	SCSI_OP_CODE_READ_TOC_PMA_ATIP = 0x43,
	SCSI_OP_CODE_REPORT_DENSITY_SUPPORT = 0x44,
	SCSI_OP_CODE_PLAY_AUDIO_10 = 0x45,
	SCSI_OP_CODE_GET_CONFIGURATION = 0x46,
	SCSI_OP_CODE_PLAY_AUDIO_MSF = 0x47,
	SCSI_OP_CODE_SANITIZE = 0x48,
	SCSI_OP_CODE_GET_EVENT_STATUS_NOTIFICATION = 0x4A,
	SCSI_OP_CODE_PAUSE_RESUME = 0x4B,
	SCSI_OP_CODE_LOG_SELECT = 0x4C,
	SCSI_OP_CODE_LOG_SENSE = 0x4D,
	SCSI_OP_CODE_XDWRITE_10 = 0x50,
	SCSI_OP_CODE_XPWRITE_10 = 0x51,
	SCSI_OP_CODE_READ_DISC_INFORMATION = 0x51,
	SCSI_OP_CODE_XDREAD_10 = 0x52,
	SCSI_OP_CODE_XDWRITEREAD_10 = 0x53,
	SCSI_OP_CODE_SEND_OPC_INFORMATION = 0x54,
	SCSI_OP_CODE_MODE_SELECT_10 = 0x55,
	SCSI_OP_CODE_RESERVE_10 = 0x56,
	SCSI_OP_CODE_RELEASE_10 = 0x57,
	SCSI_OP_CODE_REPAIR_TRACK = 0x58,
	SCSI_OP_CODE_MODE_SENSE_10 = 0x5A,
	SCSI_OP_CODE_CLOSE_TRACK_OR_SESSION = 0x5B,
	SCSI_OP_CODE_READ_BUFFER_CAPACITY = 0x5C,
	SCSI_OP_CODE_SEND_CUE_SHEET = 0x5D,
	SCSI_OP_CODE_PERSISTENT_RESERVE_IN = 0x5E,
	SCSI_OP_CODE_PERSISTENT_RESERVE_OUT = 0x5F,
	SCSI_OP_CODE_EXTENDED_CDB = 0x7E,
	SCSI_OP_CODE_VARIABLE_LENGTH_CDB = 0x7F,
	SCSI_OP_CODE_XDWRITE_EXTENDED_16 = 0x80,
	SCSI_OP_CODE_WRITE_FILEMARKS_16 = 0x80,
	SCSI_OP_CODE_READ_REVERSE_16 = 0x81,
	SCSI_OP_CODE_THIRD_PARTY_COPY_OUT = 0x83,
	SCSI_OP_CODE_THIRD_PARTY_COPY_IN = 0x84,
	SCSI_OP_CODE_ATA_PASS_THROUGH_16 = 0x85,
	SCSI_OP_CODE_ACCESS_CONTROL_IN = 0x86,
	SCSI_OP_CODE_ACCESS_CONTROL_OUT = 0x87,
	SCSI_OP_CODE_READ_16 = 0x88,
	SCSI_OP_CODE_COMPARE_AND_WRITE = 0x89,
	SCSI_OP_CODE_WRITE_16 = 0x8A,
	SCSI_OP_CODE_ORWRITE = 0x8B,
	SCSI_OP_CODE_READ_ATTRIBUTE = 0x8C,
	SCSI_OP_CODE_WRITE_ATTRIBUTE = 0x8D,
	SCSI_OP_CODE_WRITE_AND_VERIFY_16 = 0x8E,
	SCSI_OP_CODE_VERIFY_16 = 0x8F,
	SCSI_OP_CODE_PREFETCH_16 = 0x90,
	SCSI_OP_CODE_SYNCHRONIZE_CACHE_16 = 0x91,
	SCSI_OP_CODE_SPACE_16 = 0x91,
	SCSI_OP_CODE_LOCK_UNLOCK_CACHE_16 = 0x92,
	SCSI_OP_CODE_LOCATE_16 = 0x92,
	SCSI_OP_CODE_WRITE_SAME_16 = 0x93,
	SCSI_OP_CODE_ERASE_16 = 0x93,
	SCSI_OP_CODE_SERVICE_ACTION_BIDIRECTIONAL = 0x9D,
	SCSI_OP_CODE_READ_CAPACITY_16 = 0x9E,
	SCSI_OP_CODE_WRITE_LONG_16 = 0x9F,
	SCSI_OP_CODE_REPORT_LUNS = 0xA0,
	SCSI_OP_CODE_ATA_PASS_THROUGH_12 = 0xA1,
	SCSI_OP_CODE_SECURITY_PROTOCOL_IN = 0xA2,
	SCSI_OP_CODE_MAINTENANCE_IN = 0xA3,
	SCSI_OP_CODE_MAINTENANCE_OUT = 0xA4,
	SCSI_OP_CODE_REPORT_KEY = 0xA4,
	SCSI_OP_CODE_MOVE_MEDIUM = 0xA5,
	SCSI_OP_CODE_PLAY_AUDIO_12 = 0xA5,
	SCSI_OP_CODE_EXCHANGE_MEDIUM = 0xA6,
	SCSI_OP_CODE_MOVE_MEDIUM_ATTACHED = 0xA7,
	SCSI_OP_CODE_READ_12 = 0xA8,
	SCSI_OP_CODE_SERVICE_ACTION_OUT_12 = 0xA9,
	SCSI_OP_CODE_WRITE_12 = 0xAA,
	SCSI_OP_CODE_SERVICE_ACTION_IN_12 = 0xAB,
	SCSI_OP_CODE_ERASE_12 = 0xAC,
	SCSI_OP_CODE_READ_DVD_STRUCTURE = 0xAD,
	SCSI_OP_CODE_WRITE_AND_VERIFY_12 = 0xAE,
	SCSI_OP_CODE_VERIFY_12 = 0xAF,
	SCSI_OP_CODE_SEARCH_DATA_HIGH_12 = 0xB0,
	SCSI_OP_CODE_SEARCH_DATA_EQUAL_12 = 0xB1,
	SCSI_OP_CODE_SEARCH_DATA_LOW_12 = 0xB2,
	SCSI_OP_CODE_SET_LIMITS_12 = 0xB3,
	SCSI_OP_CODE_READ_ELEMENT_STATUS_ATTACHED = 0xB4,
	SCSI_OP_CODE_SECURITY_PROTOCOL_OUT = 0xB5,
	SCSI_OP_CODE_SEND_VOLUME_TAG = 0xB6,
	SCSI_OP_CODE_READ_DEFECT_DATA_12 = 0xB7,
	SCSI_OP_CODE_READ_ELEMENT_STATUS = 0xB8,
	SCSI_OP_CODE_READ_CD_MSF = 0xB9,
	SCSI_OP_CODE_REDUNDANCY_GROUP_IN = 0xBA,
	SCSI_OP_CODE_REDUNDANCY_GROUP_OUT = 0xBB,
	SCSI_OP_CODE_SPARE_IN = 0xBC,
	SCSI_OP_CODE_SPARE_OUT = 0xBD,
	SCSI_OP_CODE_VOLUME_SET_IN = 0xBE,
	SCSI_OP_CODE_VOLUME_SET_OUT = 0xBF
} SCSI_OP_CODE;

#pragma warning(push)													
#pragma warning(disable : 4214) // nonstandard extension: bitfield types other than int
#pragma warning(disable : 4201) // nonstandard extension: nameless struct/union

typedef struct _SCSI_CDB_6 {
	SCSI_OP_CODE	OpCode : 8;
	UCHAR			LogicalBlock3 : 5;	 // MSB
	UCHAR			RdProtect : 3;
	UCHAR			LogicalBlock2;
	UCHAR			LogicalBlock1;		 // LSB
	UCHAR			TransferLength;
	UCHAR			Control;
} SCSI_CDB_6;

typedef struct _SCSI_CDB_10 {
	SCSI_OP_CODE	OpCode : 8;
	UCHAR			ServiceAction : 5;
	UCHAR			RdProtect : 3;
	ULONG32			LogicalBlock;		// MSB comes first	
	UCHAR			GroupNumber : 5;
	UCHAR			Reserved : 3;
	USHORT			TransferLength;		// MSB comes first
	UCHAR			Control;
} SCSI_CDB_10;

typedef struct _SCSI_CDB_12 {
	SCSI_OP_CODE	OpCode : 8;
	UCHAR			ServiceAction : 5;
	UCHAR			RdProtect : 3;
	ULONG32			LogicalBlock;		// MSB comes first	
	UCHAR			GroupNumber : 5;
	UCHAR			Reserved : 3;
	ULONG32			TransferLength;		// MSB comes first
	UCHAR			Control;
} SCSI_CDB_12;

typedef struct _SCSI_CDB_16 {
	SCSI_OP_CODE	OpCode : 8;
	UCHAR			ServiceAction : 5;
	UCHAR			RdProtect : 3;
	ULONG64			LogicalBlock;		// MSB comes first
	ULONG32			TransferLength;		// MSB comes first
	UCHAR			Misc;
	UCHAR			Control;
} SCSI_CDB_16;

typedef struct _SCSI_CDB_24 {
	UCHAR _[24];
} SCSI_CDB_24;

#pragma warning(pop)
