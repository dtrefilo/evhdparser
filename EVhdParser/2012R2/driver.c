#include "driver.h"
#include "Ioctl.h"
#include "Vstor.h"
#include <initguid.h>
#include "parser.h"

#if 0
// {860ECCBC-6E7D-4A17-B181-81D64AF02170}
DEFINE_GUID(GUID_EVHD_PARSER_ID,
	0x860eccbc, 0x6e7d, 0x4a17, 0xb1, 0x81, 0x81, 0xd6, 0x4a, 0xf0, 0x21, 0x70);
#else
// pretend to replace original vhdparser
// {f916c826-f0f5-4cd9-be68-4fd638cf9a53}
DEFINE_GUID(GUID_EVHD_PARSER_ID,
	0xf916c826, 0xf0f5, 0x4cd9, 0xbe, 0x68, 0x4f, 0xd6, 0x38, 0xcf, 0x9a, 0x53);
#endif

static PDEVICE_OBJECT pDeviceObject = NULL;

/** Driver unload routine */
void EVhdDriverUnload(PDRIVER_OBJECT pDriverObject)
{
	UNREFERENCED_PARAMETER(pDriverObject);
}

/** Default major function dispatcher */
static NTSTATUS DispatchPassThrough(PDEVICE_OBJECT pDeviceObject, PIRP pIrp);

/** Create major function dispatcher */
static NTSTATUS DispatchCreate(PDEVICE_OBJECT pDeviceObject, PIRP pIrp);

/** Close major function dispatcher */
static NTSTATUS DispatchClose(PDEVICE_OBJECT pDeviceObject, PIRP pIrp);

/** Device control major function dispatcher */
static NTSTATUS DispatchControl(PDEVICE_OBJECT pDeviceObject, PIRP pIrp);


NTSTATUS DriverEntry(PDRIVER_OBJECT pDriverObject, PUNICODE_STRING pRegistryPath)
{
	ULONG ulIndex;
	NTSTATUS status = STATUS_SUCCESS;
	VstorParserInfo ParserInfo = { 0 };
	RTL_OSVERSIONINFOW VersionInfo = { 0 };
	UNICODE_STRING DeviceName;
	VersionInfo.dwOSVersionInfoSize = sizeof(RTL_OSVERSIONINFOW);

	UNREFERENCED_PARAMETER(pRegistryPath);
	status = RtlGetVersion(&VersionInfo);
	if (!NT_SUCCESS(status))
	{
		DbgPrint("Failed to get windows version information: %X\n", status);
		return status;
	}

	// This version of driver is only supported by Windows Server 2012 R2
	if (VersionInfo.dwMajorVersion != 6 || VersionInfo.dwMinorVersion != 3)
	{
		DbgPrint("Running on an unsupported platform: %d.%d.%d\n", VersionInfo.dwMajorVersion,
			VersionInfo.dwMinorVersion, VersionInfo.dwBuildNumber);
		return status = STATUS_NOT_SUPPORTED;
	}

	RtlInitUnicodeString(&DeviceName, L"\\Device\\EVhdParser");

	status = IoCreateDevice(pDriverObject, 0, &DeviceName, FILE_DEVICE_UNKNOWN, 0, FALSE, &pDeviceObject);
	if (!NT_SUCCESS(status))
	{
		DbgPrint("Failed to create device: %X\n", status);
		return status;
	}

	for (ulIndex = 0; ulIndex < IRP_MJ_MAXIMUM_FUNCTION; ++ulIndex)
	{
		pDriverObject->MajorFunction[ulIndex] = DispatchPassThrough;
	}

	pDriverObject->MajorFunction[IRP_MJ_CREATE] = DispatchCreate;
	pDriverObject->MajorFunction[IRP_MJ_CLOSE] = DispatchClose;
	pDriverObject->MajorFunction[IRP_MJ_DEVICE_CONTROL] = DispatchControl;

	pDriverObject->DriverUnload = EVhdDriverUnload;

	ParserInfo.dwSize						= sizeof(VstorParserInfo);
	ParserInfo.dwVersion					= 1;
	ParserInfo.ParserId						= GUID_EVHD_PARSER_ID;
	ParserInfo.pDriverObject				= pDriverObject;
	ParserInfo.pfnOpenDisk					= EVhdOpenDisk;
	ParserInfo.pfnCloseDisk					= EVhdCloseDisk;
	ParserInfo.pfnMountDisk					= EVhdMountDisk;
	ParserInfo.pfnDismountDisk				= EVhdDismountDisk;
	ParserInfo.pfnQueryMountStatusDisk		= EVhdQueryMountStatusDisk;
	ParserInfo.pfnExecuteScsiRequestDisk	= EVhdExecuteScsiRequestDisk;
	ParserInfo.pfnQueryInformationDisk		= EVhdQueryInformationDisk;
	ParserInfo.pfnQuerySaveVersionDisk		= EVhdQuerySaveVersionDisk;
	ParserInfo.pfnSaveDisk					= EVhdSaveDisk;
	ParserInfo.pfnRestoreDisk				= EVhdRestoreDisk;
	ParserInfo.pfnSetBehaviourDisk			= EVhdSetBehaviourDisk;
	ParserInfo.pfnSetQosConfigurationDisk	= EVhdSetQosConfigurationDisk;
	ParserInfo.pfnGetQosInformationDisk		= EVhdGetQosInformationDisk;

	status = VstorRegisterParser(&ParserInfo);
	if (!NT_SUCCESS(status))
	{
		DbgPrint("VstorRegisterParser failed with error: %d\n", status);
		return status;
	}

	return status;
}

static NTSTATUS DispatchPassThrough(PDEVICE_OBJECT pDeviceObject, PIRP pIrp)
{
	UNREFERENCED_PARAMETER(pDeviceObject);

	//PDEVICE_EXTENSION pDevExt = (PDEVICE_EXTENSION)pDeviceObject->DeviceExtension;
	pIrp->IoStatus.Status = STATUS_SUCCESS;
	pIrp->IoStatus.Information = 0;
	IoCompleteRequest(pIrp, IO_NO_INCREMENT);
	return STATUS_SUCCESS;
}

static NTSTATUS DispatchCreate(PDEVICE_OBJECT pDeviceObject, PIRP pIrp)
{
	UNREFERENCED_PARAMETER(pDeviceObject);

	//PDEVICE_EXTENSION pDevExt = (PDEVICE_EXTENSION)pDeviceObject->DeviceExtension;
	DbgPrint("DispatchCreate called\n");

	pIrp->IoStatus.Status = STATUS_SUCCESS;
	pIrp->IoStatus.Information = 0;
	IoCompleteRequest(pIrp, IO_NO_INCREMENT);
	return STATUS_SUCCESS;
}

static NTSTATUS DispatchClose(PDEVICE_OBJECT pDeviceObject, PIRP pIrp)
{
	UNREFERENCED_PARAMETER(pDeviceObject);

	//PDEVICE_EXTENSION pDevExt = (PDEVICE_EXTENSION)pDeviceObject->DeviceExtension;
	DbgPrint("DispatchClose called\n");

	pIrp->IoStatus.Status = STATUS_SUCCESS;
	pIrp->IoStatus.Information = 0;
	IoCompleteRequest(pIrp, IO_NO_INCREMENT);
	return STATUS_SUCCESS;
}

static NTSTATUS DispatchControl(PDEVICE_OBJECT pDeviceObject, PIRP pIrp)
{
	UNREFERENCED_PARAMETER(pDeviceObject);

	//PDEVICE_EXTENSION pDevExt = (PDEVICE_EXTENSION)pDeviceObject->DeviceExtension;		
	DbgPrint("DispatchControl called\n");

	pIrp->IoStatus.Status = STATUS_SUCCESS;
	pIrp->IoStatus.Information = 0;
	IoCompleteRequest(pIrp, IO_NO_INCREMENT);
	return STATUS_SUCCESS;
}
