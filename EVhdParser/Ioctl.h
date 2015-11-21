#include <ntddk.h>
#ifndef _WINKRNL
#include <winioctl.h>
#else
#include <sddl.h>
#include <devioctl.h>
#endif

// 90350

// 2D1A14 - SetQoSPolicy 
// 2D1A18 - GetQoSStatus  
// 2D1A1C
// 2D1A20
// 2D1A24
// 2D1A28

// 2D1A48 - StartMetaOperation v0
// 2D1950 - StartMetaOperation v1
// 2D1A5C - StartMetaOperation v2
// 2D1A60 - StartMetaOpeartion v3


//0x2D191C 
#define IOCTL_STORAGE_REGISTER_IO		 					CTL_CODE(FILE_DEVICE_MASS_STORAGE, 0x0647, METHOD_BUFFERED, FILE_ANY_ACCESS)	
//0x2D1920
#define IOCTL_STORAGE_REMOVE_VIRTUAL_DISK					CTL_CODE(FILE_DEVICE_MASS_STORAGE, 0x0648, METHOD_BUFFERED, FILE_ANY_ACCESS)
//0x2D1924
#define IOCTL_STORAGE_VHD_CREATE							CTL_CODE(FILE_DEVICE_MASS_STORAGE, 0x0649, METHOD_BUFFERED, FILE_ANY_ACCESS) // New-Vhd, async	  
//0x2D1930 
#define IOCTL_STORAGE_VHD_GET_ASYNC_OPERATION_PROGRESS		CTL_CODE(FILE_DEVICE_MASS_STORAGE, 0x064C, METHOD_BUFFERED, FILE_ANY_ACCESS)
//0x2D1934 
#define IOCTL_STORAGE_VHD_GET_PHYSICAL_PATH					CTL_CODE(FILE_DEVICE_MASS_STORAGE, 0x064D, METHOD_BUFFERED, FILE_ANY_ACCESS) 
//0x2D9938 - vdrvroot
#define IOCTL_STORAGE_NET_STOP								CTL_CODE(FILE_DEVICE_MASS_STORAGE, 0x064E, METHOD_BUFFERED, FILE_WRITE_ACCESS) 
//0x2D1940
#define IOCTL_STORAGE_VHD_GET_INFORMATION 					CTL_CODE(FILE_DEVICE_MASS_STORAGE, 0x0650, METHOD_BUFFERED, FILE_ANY_ACCESS)	
//0x2D1944 
#define IOCTL_STORAGE_VHD_SET_INFORMATION 					CTL_CODE(FILE_DEVICE_MASS_STORAGE, 0x0651, METHOD_BUFFERED, FILE_ANY_ACCESS)	  
//0x2D1948 
#define IOCTL_STORAGE_VHD_COMPACT		 					CTL_CODE(FILE_DEVICE_MASS_STORAGE, 0x0652, METHOD_BUFFERED, FILE_ANY_ACCESS) // Optimize-Vhd, async	
//0x2D194C 
#define IOCTL_STORAGE_VHD_MERGE		 						CTL_CODE(FILE_DEVICE_MASS_STORAGE, 0x0653, METHOD_BUFFERED, FILE_ANY_ACCESS) // Merge-Vhd, async	 
//0x2D1950 
#define IOCTL_STORAGE_VHD_RESIZE		 					CTL_CODE(FILE_DEVICE_MASS_STORAGE, 0x0654, METHOD_BUFFERED, FILE_ANY_ACCESS) // Resize-Vhd, async	   
//0x2D1954 
#define IOCTL_STORAGE_VHD_FORK			 					CTL_CODE(FILE_DEVICE_MASS_STORAGE, 0x0655, METHOD_BUFFERED, FILE_ANY_ACCESS) // async	 		 
//0x2D1958 
#define IOCTL_STORAGE_VHD_MIRROR			 				CTL_CODE(FILE_DEVICE_MASS_STORAGE, 0x0656, METHOD_BUFFERED, FILE_ANY_ACCESS) // async	 
//0x2D195C 
#define IOCTL_STORAGE_COMPLETE_OPERATION2	 				CTL_CODE(FILE_DEVICE_MASS_STORAGE, 0x0657, METHOD_BUFFERED, FILE_ANY_ACCESS) // async	 
//0x2D1960 EnableSingleStepAsyncOp
#define IOCTL_STORAGE_ENABLE_SS_ASYNC_OP	 				CTL_CODE(FILE_DEVICE_MASS_STORAGE, 0x0658, METHOD_BUFFERED, FILE_ANY_ACCESS) // async	 
//0x2D1964 DisableSingleStepAsyncOp
#define IOCTL_STORAGE_DISABLE_SS_ASYNC_OP	 				CTL_CODE(FILE_DEVICE_MASS_STORAGE, 0x0659, METHOD_BUFFERED, FILE_ANY_ACCESS) // async	 
//0x2D1968 SingleStepAsyncOp
#define IOCTL_STORAGE_SS_ASYNC_OP	 						CTL_CODE(FILE_DEVICE_MASS_STORAGE, 0x065A, METHOD_BUFFERED, FILE_ANY_ACCESS) // async	 
//0x2D196C GetSingleStepAsyncOpParameters
#define IOCTL_STORAGE_GET_SS_ASYNC_OP_PARAMETERS			CTL_CODE(FILE_DEVICE_MASS_STORAGE, 0x065B, METHOD_BUFFERED, FILE_ANY_ACCESS) // async	 
//0x2D1970
#define IOCTL_STORAGE_LOCK_VHD_TOPOLOGY						CTL_CODE(FILE_DEVICE_MASS_STORAGE, 0x065C, METHOD_BUFFERED, FILE_ANY_ACCESS) // async	 
//0x2D1974
#define IOCTL_STORAGE_UNLOCK_VHD_TOPOLOGY					CTL_CODE(FILE_DEVICE_MASS_STORAGE, 0x065D, METHOD_BUFFERED, FILE_ANY_ACCESS) // async	 
//0x2D1978
#define IOCTL_STORAGE_COMPLETE_OPERATION1					CTL_CODE(FILE_DEVICE_MASS_STORAGE, 0x065E, METHOD_BUFFERED, FILE_ANY_ACCESS)	
//0x2D197C
#define IOCTL_STORAGE_VHD_ENABLE_TRACKING					CTL_CODE(FILE_DEVICE_MASS_STORAGE, 0x065F, METHOD_BUFFERED, FILE_ANY_ACCESS)
//0x2D1980
#define IOCTL_STORAGE_VHD_DISABLE_TRACKING					CTL_CODE(FILE_DEVICE_MASS_STORAGE, 0x0660, METHOD_BUFFERED, FILE_ANY_ACCESS)
//0x2D1984
#define IOCTL_STORAGE_CHANGE_CTLOG_FILE						CTL_CODE(FILE_DEVICE_MASS_STORAGE, 0x0661, METHOD_BUFFERED, FILE_ANY_ACCESS)
//0x2D1988
#define IOCTL_STORAGE_GET_CTLOG_INFO						CTL_CODE(FILE_DEVICE_MASS_STORAGE, 0x0662, METHOD_BUFFERED, FILE_ANY_ACCESS)
//0x2D198C
#define IOCTL_STORAGE_CTLOG_SET_VHD_PARAMETERS				CTL_CODE(FILE_DEVICE_MASS_STORAGE, 0x0663, METHOD_BUFFERED, FILE_ANY_ACCESS)
//0x2D1990
#define IOCTL_STORAGE_MULTISTAGE_SWITCH_LOG_FILE			CTL_CODE(FILE_DEVICE_MASS_STORAGE, 0x0664, METHOD_BUFFERED, FILE_ANY_ACCESS)
//0x2D19C2 
#define IOCTL_STORAGE_VHD_ENUM_METADATA 					CTL_CODE(FILE_DEVICE_MASS_STORAGE, 0x0670, METHOD_OUT_DIRECT, FILE_ANY_ACCESS)	
//0x2D19C6 
#define IOCTL_STORAGE_VHD_GET_METADATA 						CTL_CODE(FILE_DEVICE_MASS_STORAGE, 0x0671, METHOD_OUT_DIRECT, FILE_ANY_ACCESS)   
//0x2D19C9 
#define IOCTL_STORAGE_VHD_SET_METADATA 						CTL_CODE(FILE_DEVICE_MASS_STORAGE, 0x0672, METHOD_IN_DIRECT, FILE_ANY_ACCESS)	// async    
//0x2D19CC 
#define IOCTL_STORAGE_VHD_DELETE_METADATA 					CTL_CODE(FILE_DEVICE_MASS_STORAGE, 0x0673, METHOD_BUFFERED, FILE_ANY_ACCESS)	   
//0x2D19D2 
#define IOCTL_STORAGE_VHD_READ_RAW 							CTL_CODE(FILE_DEVICE_MASS_STORAGE, 0x0674, METHOD_OUT_DIRECT, FILE_ANY_ACCESS)   
//0x2D19D4 
#define IOCTL_STORAGE_VHD_ADD_PARENT 						CTL_CODE(FILE_DEVICE_MASS_STORAGE, 0x0675, METHOD_BUFFERED, FILE_ANY_ACCESS)	   
//0x2D19D8 
#define IOCTL_STORAGE_SET_WRITE_CACHE 						CTL_CODE(FILE_DEVICE_MASS_STORAGE, 0x0676, METHOD_BUFFERED, FILE_ANY_ACCESS)	   
//0x2D19DC 
#define IOCTL_STORAGE_VHD_GET_ATTACHED_PHYSICAL_PATHS 		CTL_CODE(FILE_DEVICE_MASS_STORAGE, 0x0677, METHOD_BUFFERED, FILE_ANY_ACCESS)	  
//0x2D19E0 
#define IOCTL_STORAGE_VHD_ISO_EJECT_MEDIA			 		CTL_CODE(FILE_DEVICE_MASS_STORAGE, 0x0678, METHOD_BUFFERED, FILE_ANY_ACCESS)	
//0x2D19E4 
#define IOCTL_STORAGE_VHD_ISO_INSERT_MEDIA			 		CTL_CODE(FILE_DEVICE_MASS_STORAGE, 0x0679, METHOD_BUFFERED, FILE_ANY_ACCESS)	
//0x2D19E8 
#define IOCTL_STORAGE_QUERY_CHANGES					 		CTL_CODE(FILE_DEVICE_MASS_STORAGE, 0x067A, METHOD_BUFFERED, FILE_ANY_ACCESS)	
//0x2D1A00 
#define IOCTL_STORAGE_VALIDATE_VHD					 		CTL_CODE(FILE_DEVICE_MASS_STORAGE, 0x0680, METHOD_BUFFERED, FILE_ANY_ACCESS)	
//0x2D1A04 
#define IOCTL_STORAGE_VALIDATE_METADATA_ACCESS		 		CTL_CODE(FILE_DEVICE_MASS_STORAGE, 0x0681, METHOD_BUFFERED, FILE_ANY_ACCESS)	
//0x2D5928 - miniport
#define IOCTL_STORAGE_QUERY_VHD_FILENAME			 		CTL_CODE(FILE_DEVICE_MASS_STORAGE, 0x064A, METHOD_BUFFERED, FILE_READ_ACCESS)
//0x2D592C - vdrvroot 
#define IOCTL_STORAGE_VHD_FIND_SHIM					 		CTL_CODE(FILE_DEVICE_MASS_STORAGE, 0x064B, METHOD_BUFFERED, FILE_READ_ACCESS)
//0x2D593C - miniport
#define IOCTL_STORAGE_QUERY_INSTANCE_ID				 		CTL_CODE(FILE_DEVICE_MASS_STORAGE, 0x064F, METHOD_BUFFERED, FILE_READ_ACCESS)

//0x2D5A0C - another preload disk metadata?

//0x2D5980 - vhdmp
#define IOCTL_STORAGE_REGISTER_BALANCER						CTL_CODE(FILE_DEVICE_MASS_STORAGE, 0x0660, METHOD_BUFFERED, FILE_READ_ACCESS)	
//0x2D5984
#define IOCTL_STORAGE_REGISTER_QOS_INTERFACE				CTL_CODE(FILE_DEVICE_MASS_STORAGE, 0x0661, METHOD_BUFFERED, FILE_READ_ACCESS)	
//0x2D5988
#define IOCTL_STORAGE_UNREGISTER_QOS_INTERFACE				CTL_CODE(FILE_DEVICE_MASS_STORAGE, 0x0662, METHOD_BUFFERED, FILE_READ_ACCESS)	
//0x2D598C 
#define IOCTL_STORAGE_PRELOAD_DISK_METADATA			 		CTL_CODE(FILE_DEVICE_MASS_STORAGE, 0x0663, METHOD_BUFFERED, FILE_READ_ACCESS)	
//0x2D118C - miniport
#define IOCTL_STORAGE_QUERY_DEPENDENT_DISK					CTL_CODE(FILE_DEVICE_MASS_STORAGE, 0x0463, METHOD_BUFFERED, FILE_ANY_ACCESS)	
//0x2D518C - miniport
#define IOCTL_STORAGE_QUERY_DEPENDENT_DISK2					CTL_CODE(FILE_DEVICE_MASS_STORAGE, 0x0463, METHOD_BUFFERED, FILE_READ_ACCESS)	
//0x2D1190 - miniport
#define IOCTL_STORAGE_QUERY_DEPENDENT_DISK_QOS		 		CTL_CODE(FILE_DEVICE_MASS_STORAGE, 0x0464, METHOD_BUFFERED, FILE_ANY_ACCESS)	
//0x2D5190 - miniport
#define IOCTL_STORAGE_QUERY_DEPENDENT_DISK_QOS2				CTL_CODE(FILE_DEVICE_MASS_STORAGE, 0x0464, METHOD_BUFFERED, FILE_READ_ACCESS)	
//0x2D9194 - miniport
#define IOCTL_STORAGE_DEPENDENCY_REMOVAL					CTL_CODE(FILE_DEVICE_MASS_STORAGE, 0x0465, METHOD_BUFFERED, FILE_WRITE_ACCESS)	
//0x2D9198 - miniport
#define IOCTL_STORAGE_DEPENDENCY_UPDATE						CTL_CODE(FILE_DEVICE_MASS_STORAGE, 0x0466, METHOD_BUFFERED, FILE_WRITE_ACCESS)	
//0x2D1400 - miniport
#define IOCTL_STORAGE_QUERY_PROPERTY				 		CTL_CODE(FILE_DEVICE_MASS_STORAGE, 0x0500, METHOD_BUFFERED, FILE_ANY_ACCESS)	

//0x248004
#define IOCTL_VIRTUAL_DISK_MOUNT							CTL_CODE(FILE_DEVICE_VIRTUAL_DISK, 0x0001, METHOD_BUFFERED, FILE_WRITE_ACCESS)
//0x248008
#define IOCTL_VIRTUAL_DISK_PAUSE							CTL_CODE(FILE_DEVICE_VIRTUAL_DISK, 0x0002, METHOD_BUFFERED, FILE_WRITE_ACCESS)
//0x24800C
#define IOCTL_VIRTUAL_DISK_RESUME							CTL_CODE(FILE_DEVICE_VIRTUAL_DISK, 0x0003, METHOD_BUFFERED, FILE_WRITE_ACCESS)	 
//0x248010
#define IOCTL_VIRTUAL_DISK_UNK_0004							CTL_CODE(FILE_DEVICE_VIRTUAL_DISK, 0x0004, METHOD_BUFFERED, FILE_WRITE_ACCESS) 
//0x248014
#define IOCTL_VIRTUAL_DISK_UNK_0005							CTL_CODE(FILE_DEVICE_VIRTUAL_DISK, 0x0005, METHOD_BUFFERED, FILE_WRITE_ACCESS)
//0x248018
#define IOCTL_VIRTUAL_DISK_GET_ADAPTER_SAVE_STATE_DATA		CTL_CODE(FILE_DEVICE_VIRTUAL_DISK, 0x0006, METHOD_BUFFERED, FILE_WRITE_ACCESS)
//0x24801C
#define IOCTL_VIRTUAL_DISK_UNK_0007							CTL_CODE(FILE_DEVICE_VIRTUAL_DISK, 0x0007, METHOD_BUFFERED, FILE_WRITE_ACCESS)
//0x248020
#define IOCTL_VIRTUAL_DISK_UNK_0008							CTL_CODE(FILE_DEVICE_VIRTUAL_DISK, 0x0008, METHOD_BUFFERED, FILE_WRITE_ACCESS)	 
//0x248024
#define IOCTL_VIRTUAL_DISK_UNK_0009							CTL_CODE(FILE_DEVICE_VIRTUAL_DISK, 0x0009, METHOD_BUFFERED, FILE_WRITE_ACCESS)	  
//0x248028
#define IOCTL_VIRTUAL_DISK_UNK_000A							CTL_CODE(FILE_DEVICE_VIRTUAL_DISK, 0x000A, METHOD_BUFFERED, FILE_WRITE_ACCESS)	  
//0x24802C
#define IOCTL_VIRTUAL_DISK_UNK_000B							CTL_CODE(FILE_DEVICE_VIRTUAL_DISK, 0x000B, METHOD_BUFFERED, FILE_WRITE_ACCESS)	  
//0x248030
#define IOCTL_VIRTUAL_DISK_POWERON_POWEROFF					CTL_CODE(FILE_DEVICE_VIRTUAL_DISK, 0x000C, METHOD_BUFFERED, FILE_WRITE_ACCESS)	 
//0x248034
#define IOCTL_VIRTUAL_DISK_UNK_000D							CTL_CODE(FILE_DEVICE_VIRTUAL_DISK, 0x000D, METHOD_BUFFERED, FILE_WRITE_ACCESS)	  
//0x248038
#define IOCTL_VIRTUAL_DISK_RESET							CTL_CODE(FILE_DEVICE_VIRTUAL_DISK, 0x000E, METHOD_BUFFERED, FILE_WRITE_ACCESS)	  
//0x248198 - set LUN address
#define IOCTL_VIRTUAL_DISK_SET_LUN							CTL_CODE(FILE_DEVICE_VIRTUAL_DISK, 0x0066, METHOD_BUFFERED, FILE_WRITE_ACCESS)		  
//0x24819E
#define IOCTL_VIRTUAL_DISK_SCSI_REQUEST 					CTL_CODE(FILE_DEVICE_VIRTUAL_DISK, 0x0067, METHOD_OUT_DIRECT, FILE_WRITE_ACCESS) 
//0x2401A0
#define IOCTL_VIRTUAL_DISK_GET_DEVICE_INFORMATION			CTL_CODE(FILE_DEVICE_VIRTUAL_DISK, 0x0068, METHOD_BUFFERED, FILE_ANY_ACCESS)	  
//0x2481A4
#define IOCTL_VIRTUAL_DISK_SET_QOS_CONFIGURATION			CTL_CODE(FILE_DEVICE_VIRTUAL_DISK, 0x0069, METHOD_BUFFERED, FILE_WRITE_ACCESS)		  
//0x2481A8
#define IOCTL_VIRTUAL_DISK_GET_QOS_CONFIGURATION			CTL_CODE(FILE_DEVICE_VIRTUAL_DISK, 0x006A, METHOD_BUFFERED, FILE_WRITE_ACCESS)		  
//0x2481AC
#define IOCTL_VIRTUAL_DISK_QUERY_SAVE_VERSION				CTL_CODE(FILE_DEVICE_VIRTUAL_DISK, 0x006B, METHOD_BUFFERED, FILE_WRITE_ACCESS)		  
//0x2481B0
#define IOCTL_VIRTUAL_DISK_SAVE								CTL_CODE(FILE_DEVICE_VIRTUAL_DISK, 0x006C, METHOD_BUFFERED, FILE_WRITE_ACCESS)		  
//0x2481B4
#define IOCTL_VIRTUAL_DISK_UNK_006D							CTL_CODE(FILE_DEVICE_VIRTUAL_DISK, 0x006D, METHOD_BUFFERED, FILE_WRITE_ACCESS)		  
//0x2481B8
#define IOCTL_VIRTUAL_DISK_SET_SAVE_VERSION					CTL_CODE(FILE_DEVICE_VIRTUAL_DISK, 0x006E, METHOD_BUFFERED, FILE_WRITE_ACCESS)		  
//0x2481BC
#define IOCTL_VIRTUAL_DISK_RESTORE							CTL_CODE(FILE_DEVICE_VIRTUAL_DISK, 0x006F, METHOD_BUFFERED, FILE_WRITE_ACCESS)
//0x2481C0
#define IOCTL_VIRTUAL_DISK_UNK_0070							CTL_CODE(FILE_DEVICE_VIRTUAL_DISK, 0x0070, METHOD_BUFFERED, FILE_WRITE_ACCESS)
//0x2481C4
#define IOCTL_VIRTUAL_DISK_SET_FEATURES						CTL_CODE(FILE_DEVICE_VIRTUAL_DISK, 0x0071, METHOD_BUFFERED, FILE_WRITE_ACCESS) 	  
//0x2481C8
#define IOCTL_VIRTUAL_DISK_UNK_0072							CTL_CODE(FILE_DEVICE_VIRTUAL_DISK, 0x0072, METHOD_BUFFERED, FILE_WRITE_ACCESS)	  
//0x2481CC
#define IOCTL_VIRTUAL_DISK_QUERY_MOUNT_STATUS				CTL_CODE(FILE_DEVICE_VIRTUAL_DISK, 0x0073, METHOD_BUFFERED, FILE_WRITE_ACCESS)	  
//0x2481D0
#define IOCTL_VIRTUAL_DISK_NOTIFY_QOS_STATUS				CTL_CODE(FILE_DEVICE_VIRTUAL_DISK, 0x0074, METHOD_BUFFERED, FILE_WRITE_ACCESS) 
//0x2481D4
#define IOCTL_VIRTUAL_DISK_UNK_0075							CTL_CODE(FILE_DEVICE_VIRTUAL_DISK, 0x0075, METHOD_BUFFERED, FILE_WRITE_ACCESS)	  	

//0x7C220 - vhdmp disk
#define IOCTL_DISK_VOLUMES_READY							CTL_CODE(FILE_DEVICE_DISK, 0x0088, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)

#pragma warning(push)
#pragma warning(disable : 4201) // nonstandard extension: nameless struct/union
typedef enum
{
	EDiskInfoType_Geometry					= 0x0,
	EDiskInfoType_LinkageId					= 0x1,
	EDiskInfoType_ParentNameList				= 0x2,
	EDiskInfoType_ParentLinkageId			= 0x3,
	EDiskInfoType_ParentTimestamp			= 0x4,
	EDiskInfoType_ParserInfo					= 0x6,
	EDiskInfoType_Type						= 0x7,
	EDiskInfoType_IsFullyAllocated			= 0x8,
	EDiskInfoType_Unk9						= 0x9,
	EDiskInfoType_NumSectors					= 0xA,
	EDiskInfoType_FragmentationPercentage	= 0xA,	// 2012
	EDiskInfoType_FragmentationPercentageR2	= 0xC,
	EDiskInfoType_InUseFlag					= 0xD,
	EDiskInfoType_Page83Data					= 0xE,
	EDiskInfoType_InstanceId					= 0x3E8,
} EDiskInfoType;

#pragma pack (push, 1)
typedef union {
	struct {
		INT dwLow;
		INT dwHigh;
	};
	ULONG64 qword;
} uVal;
typedef struct {
	EDiskInfoType dwRequestCode;
	INT dwUnk;
	union {
		GUID guid;
		uVal vals[3];
	};
} MetaInfoResponse;
#pragma pack(pop)	 	

#pragma warning(pop)