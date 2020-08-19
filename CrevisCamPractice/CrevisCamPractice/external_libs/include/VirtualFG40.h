#ifndef _VIRTUAL_FRAME_GRABBER_DEF_H
#define _VIRTUAL_FRAME_GRABBER_DEF_H

typedef __int32 (* GrabCallback)(__int32 eventID, void* pImage, void* pUserDefine);

//Hook Function Event
#define	EVENT_NEW_IMAGE				0
#define	EVENT_GRAB_ERROR			1

// GC_ERROR redefine
#define	MCAM_ERR_SUCCESS					0
#define	MCAM_ERR_ERROR               		-1001
#define	MCAM_ERR_NOT_INITIALIZED     		-1002
#define	MCAM_ERR_NOT_IMPLEMENTED     		-1003
#define	MCAM_ERR_RESOURCE_IN_USE     		-1004
#define	MCAM_ERR_ACCESS_DENIED       		-1005
#define	MCAM_ERR_INVALID_HANDLE      		-1006
#define	MCAM_ERR_INVALID_ID          		-1007
#define	MCAM_ERR_NO_DATA             		-1008
#define	MCAM_ERR_INVALID_PARAMETER   		-1009
#define	MCAM_ERR_IO                  		-1010
#define	MCAM_ERR_TIMEOUT             		-1011
#define	MCAM_ERR_ABORT               		-1012
#define	MCAM_ERR_INVALID_BUFFER      		-1013
#define	MCAM_ERR_NOT_AVAILABLE       		-1014

// Add Error type
#define	MCAM_ERR_NOT_OPEN_DEVICE			-10000
#define	MCAM_ERR_NO_DEVICE					-10001
#define	MCAM_ERR_RESOURCE_USED				-10002
#define	MCAM_ERR_NO_SYSTEM					-10003
#define	MCAM_ERR_NOT_OPEN_SYSTEM			-10004
#define	MCAM_ERR_INVALID_BUFFER_SIZE		-10005
#define MCAM_ERR_XML_PARSE					-10006
#define MCAM_ERR_EXTERNAL_LOAD_LIBRARY		-10007

//DeviceInfo
#define	MCAM_DEVICEINFO_USER_ID				10000
#define	MCAM_DEVICEINFO_MODEL_NAME			10001
#define	MCAM_DEVICEINFO_SERIAL_NUMBER		10002
#define	MCAM_DEVICEINFO_DEVICE_VERSION		10003
#define	MCAM_DEVICEINFO_MAC_ADDRESS			10004
#define	MCAM_DEVICEINFO_IP_ADDRESS			10005

//Continuous Grabbing Mode
#define	MCAMU_CONTINUOUS_GRABBING_DISAABLE	0
#define	MCAMU_CONTINUOUS_GRABBING_ENABLE	1

// Feature Name
#define	MCAM_DEVICE_ID															(char*)"DeviceID"
#define	MCAM_DEVICE_VENDOR_NAME													(char*)"DeviceVendorName"						// String
#define	MCAM_DEVICE_MODEL_NAME													(char*)"DeviceModelName"						// String
#define	MCAM_DEVICE_MANUFACTURER_INFO											(char*)"DeviceManufacturerInfo"					// String
#define	MCAM_DEVICE_VERSION														(char*)"DeviceVersion"							// String
#define	MCAM_DEVICE_USER_ID														(char*)"DeviceUserID"							// String
#define	MCAM_DEVICE_SCANTYPE													(char*)"DeviceScanType"							// Enumeration
#define	MCAM_WIDTH																(char*)"Width"									// Integer
#define	MCAM_HEIGHT																(char*)"Height"									// Integer
#define	MCAM_PIXEL_FORMAT														(char*)"PixelFormat"							// Enumeration
#define	MCAM_WIDTH_MAX															(char*)"WidthMax"								// Integer
#define	MCAM_HEIGHT_MAX															(char*)"HeightMax"								// Integer
#define	MCAM_OFFSET_X															(char*)"OffsetX"								// Integer
#define	MCAM_OFFSET_Y															(char*)"OffsetY"								// Integer
#define	MCAM_BINNING_HORIZONTAL													(char*)"BinningHorizontal"						// Integer
#define	MCAM_BINNING_VERTICAL													(char*)"BinningVertical"						// Integer
#define	MCAM_TEST_PATTERN														(char*)"TestPattern"							// Enumeration
#define	MCAM_ACQUISITION_START													(char*)"AcquisitionStart"						// Command
#define	MCAM_ACQUISITION_STOP													(char*)"AcquisitionStop"						// Command
#define	MCAM_ACQUISITION_MODE													(char*)"AcquisitionMode"						// Enumeration
#define	MCAM_ACQUISITION_FRAME_COUNT											(char*)"AcquisitionFrameCount"					// Integer
#define	MCAM_TRIGGER_SELECTOR													(char*)"TriggerSelector"						// Enumeration
#define	MCAM_TRIGGER_MODE														(char*)"TriggerMode"							// Enumeration
#define	MCAM_TRIGGER_SOURCE														(char*)"TriggerSource"							// Enumeration
#define	MCAM_TRIGGER_ACTIVATION													(char*)"TriggerActivation"						// Enumeration
#define	MCAM_TRIGGER_SOFTWARE													(char*)"TriggerSoftware"						// Command
#define	MCAM_TRIGGER_DELAY														(char*)"TriggerDelay"							// Float
#define	MCAM_EXPOSURE_MODE														(char*)"ExposureMode"							// Enumeration
#define	MCAM_EXPOSURE_AUTO														(char*)"ExposureAuto"							// Enumeration
#define	MCAM_EXPOSURE_TIME														(char*)"ExposureTime"							// Float
#define	MCAM_TRANSFER_DELAY														(char*)"TransferDelay"							// Integer
#define	MCAM_ACQUISITION_FRAMERATE_ENABLE										(char*)"AcquisitionFrameRateEnable"				// Enumeration
#define	MCAM_ACQUISITIONF_RAMERATE												(char*)"AcquisitionFrameRate"					// Float
#define	MCAM_AUTO_EXPOSURE_TARGET												(char*)"AutoExposureTarget"						// Integer
#define	MCAM_LINE_SELECTOR														(char*)"LineSelector"							// Enumeration
#define	MCAM_LINE_MODE															(char*)"LineMode"								// Enumeration
#define	MCAM_LINE_INVERTER														(char*)"LineInverter"							// Boolean
#define	MCAM_LINE_STATUS														(char*)"LineStatus"								// Boolean
#define	MCAM_LINE_SOURCE														(char*)"LineSource"								// Enumeration
#define	MCAM_USER_OUTPUT_SELECTOR												(char*)"UserOutputSelector"						// Enumeration
#define	MCAM_USER_OUTPUT_VALUE													(char*)"UserOutputValue"						// Boolean
#define	MCAM_TIMER_SELECTOR														(char*)"TimerSelector"							// Enumeration
#define	MCAM_TIMER_DURATION														(char*)"TimerDuration"							// Float
#define	MCAM_TIMER_DELAY														(char*)"TimerDelay"								// Float
#define	MCAM_GAIN_SELECTOR        												(char*)"GainSelector"							// Enumeration
#define	MCAM_GAIN_RAW             												(char*)"GainRaw"								// Integer
#define	MCAM_GAIN_AUTO            												(char*)"GainAuto"								// Enumeration
#define	MCAM_BLACK_LEVEL_SELECTOR  												(char*)"BlackLevelSelector"						// Enumeration
#define	MCAM_BLACK_LEVEL_RAW       												(char*)"BlackLevelRaw"							// Integer
#define	MCAM_BALANCE_RATIO_SELECTOR												(char*)"BalanceRatioSelector"					// Enumeration
#define	MCAM_BALANCE_RATIO        												(char*)"BalanceRatio"							// Float
#define	MCAM_BALANCE_WHITE_AUTO													(char*)"BalanceWhiteAuto"						// Enumeration
#define	MCAM_LUT_ENABLE															(char*)"LUTEnable"								// Boolean
#define	MCAM_LUT_INDEX															(char*)"LUTIndex"								// Integer
#define	MCAM_LUT_VALUE															(char*)"LUTValue"								// Integer
#define	MCAM_PAYLOAD_SIZE														(char*)"PayloadSize"							// Integer
#define	GEV_VERSION_MAJOR                        								(char*)"GevVersionMajor"						// Integer
#define	GEV_VERSION_MINOR                        								(char*)"GevVersionMinor"						// Integer
#define	GEV_DEVICE_MODE_IS_BIGENDIAN               								(char*)"GevDeviceModeIsBigEndian"				// Boolean
#define	GEV_DEVICE_MODE_CHARACTER_SET              								(char*)"GevDeviceModeCharacterSet"				// Enumeration
#define	GEV_INTERFACE_SELECTOR                   								(char*)"GevInterfaceSelector"					// Integer
#define	GEV_MAC_ADDRESS                          								(char*)"GevMACAddress"							// Integer
#define	GEV_SUPPORTED_OPTION_SELECTOR             								(char*)"GevSupportedOptionSelector"				// Enumeration
#define	GEV_SUPPORTED_OPTION                     								(char*)"GevSupportedOption"						// Integer
#define	GEV_CURRENT_IP_CONFIGURATION_LLA           								(char*)"GevCurrentIPConfigurationLLA"			// Boolean
#define	GEV_CURRENT_IP_CONFIGURATION_DHCP          								(char*)"GevCurrentIPConfigurationDHCP"			// Boolean
#define	GEV_CURRENT_IP_CONFIGURATION_PERSISTENT_IP								(char*)"GevCurrentIPConfigurationPersistentIP"	// Boolean
#define	GEV_CURRENT_IP_ADDRESS                    								(char*)"GevCurrentIPAddress"					// Integer
#define	GEV_CURRENT_SUBNETMASK                   								(char*)"GevCurrentSubnetMask"					// Integer
#define	GEV_CURRENT_DEFAULT_GATEWAY               								(char*)"GevCurrentDefaultGateway"				// Integer
#define	GEV_FIRST_URL                            								(char*)"GevFirstURL"							// String
#define	GEV_SECOND_URL                           								(char*)"GevSecondURL"							// String
#define	GEV_NUMBER_OF_INTERFACES                  								(char*)"GevNumberOfInterfaces"					// Integer
#define	GEV_PERSISTENT_IP_ADDRESS                 								(char*)"GevPersistentIPAddress"					// Integer
#define	GEV_PERSISTENT_SUBNETMASK                								(char*)"GevPersistentSubnetMask"				// Integer
#define	GEV_PERSISTENT_DEFAULT_GATEWAY            								(char*)"GevPersistentDefaultGateway"			// Integer
#define	GEV_MESSAGE_CHANNEL_COUNT                 								(char*)"GevMessageChannelCount"					// Integer
#define	GEV_STREAM_CHANNEL_COUNT                  								(char*)"GevStreamChannelCount"					// Integer
#define	GEV_TIME_STAMP_TICK_FREQUENCY              								(char*)"GevTimestampTickFrequency"				// Integer
#define	GEV_TIME_STAMP_CONTROL_LATCH               								(char*)"GevTimestampControlLatch"				// Command
#define	GEV_TIME_STAMP_CONTROL_RESET               								(char*)"GevTimestampControlReset"				// Command
#define	GEV_TIME_STAMP_VALUE                      								(char*)"GevTimestampValue"						// Integer
#define	GEV_HEARTBEAT_TIMEOUT                    								(char*)"GevHeartbeatTimeout"					// Integer
#define	GEV_GVCP_HEARTBEAT_DISABLE                								(char*)"GevGVCPHeartbeatDisable"				// Boolean
#define	GEV_CCP                                 								(char*)"GevCCP"									// Enumeration
#define	GEV_MCP_HOST_PORT                         								(char*)"GevMCPHostPort"							// Integer
#define	GEV_MCTT                                								(char*)"GevMCTT"								// Integer
#define	GEV_MCRC                                								(char*)"GevMCRC"								// Integer
#define	GEV_STREAM_CHANNEL_SELECTOR               								(char*)"GevStreamChannelSelector"				// Integer
#define	GEV_SCP_INTERFACE_INDEX                   								(char*)"GevSCPInterfaceIndex"					// Integer
#define	GEV_SCP_HOST_PORT                         								(char*)"GevSCPHostPort"							// Integer
#define	GEV_SCPS_FIRE_TEST_PACKET                  								(char*)"GevSCPSFireTestPacket"					// Boolean
#define	GEV_SCPS_DO_NOT_FRAGMENT                   								(char*)"GevSCPSDoNotFragment"					// Boolean
#define	GEV_SCPS_BIG_ENDIAN                       								(char*)"GevSCPSBigEndian"						// Boolean
#define	GEV_SCPS_PACKETSIZE                      								(char*)"GevSCPSPacketSize"						// Integer
#define	GEV_SCPD                                								(char*)"GevSCPD"								// Integer
#define	GEV_SCDA																(char*)"GevSCDA"								// Integer
#define	USER_SET_SELECTOR														(char*)"UserSetSelector"						// Enumeration
#define	USER_SET_LOAD															(char*)"UserSetLoad"							// Command
#define	USER_SET_SAVE															(char*)"UserSetSave"							// Command
#define	MCAM_COLOR_TRANS_FORMATION_ENABLE										(char*)"ColorTransformationEnable"				// Boolean
#define	MCAM_COLOR_TRANS_FORMATION_VALUE_SELECTOR								(char*)"ColorTransformationValueSelector"		// Enumeration
#define	MCAM_COLOR_TRANS_FORMATION_VALUE										(char*)"ColorTransformationValue"				// Float
#define	MCAM_DEVICE_FILTER_DRIVER_MODE											(char*)"DeviceFilterDriverMode"					// Enumeration
#define	MCAM_DEVICE_COMMAND_TIMEOUT												(char*)"DeviceCommandTimeout"					// Integer
#define	MCAM_DEVICE_COMMAND_RETRY_NUMBER										(char*)"DeviceCommandRetryNumber"				// Integer
#define	MCAM_DEVICE_STREAM_TIMEOUT												(char*)"DeviceStreamTimeout"					// Integer
#define	MCAM_DEVICE_MISSING_PACKET_RECEIVE										(char*)"DeviceMissingPacketReceive"				// Enumeration
#define	MCAM_DEVICE_PACKET_RESEND												(char*)"DevicePacketResend"						// Boolean
#define	MCAM_DEVICE_MAX_PACKET_RESEND_COUNT										(char*)"DeviceMaxPacketResendCount"				// Integer
#define	MCAM_DEVICE_FIND_MAX_PACKET_SIZE										(char*)"DeviceFindMaxPacketSize"				// Command
#define	MCAM_DEVICE_MAX_PACKET_SIZE												(char*)"DeviceMaxPacketSize"					// Integer

// Enumeration Feature Entry
#define	PIXEL_FORMAT_MONO8														(char*)"Mono8"
#define	PIXEL_FORMAT_MONO10														(char*)"Mono10"
#define	PIXEL_FORMAT_MONO12														(char*)"Mono12"
#define	PIXEL_FORMAT_MONO14														(char*)"Mono14"
#define	PIXEL_FORMAT_MONO10PACKED												(char*)"Mono10Packed"
#define	PIXEL_FORMAT_MONO12PACKED												(char*)"Mono12Packed"
#define	PIXEL_FORMAT_BAYERBG8													(char*)"BayerBG8"
#define	PIXEL_FORMAT_BAYERBG10													(char*)"BayerBG10"
#define	PIXEL_FORMAT_BAYERBG12													(char*)"BayerBG12"
#define	PIXEL_FORMAT_BAYERBG10PACKED											(char*)"BayerBG10Packed"
#define	PIXEL_FORMAT_BAYERBG12PACKED											(char*)"BayerBG12Packed"
#define	PIXEL_FORMAT_BAYERRG8													(char*)"BayerRG8"
#define	PIXEL_FORMAT_BAYERRG10													(char*)"BayerRG10"
#define	PIXEL_FORMAT_BAYERRG12													(char*)"BayerRG12"
#define	PIXEL_FORMAT_BAYERRG10PACKED											(char*)"BayerRG10Packed"
#define	PIXEL_FORMAT_BAYERRG12PACKED											(char*)"BayerRG12Packed"
#define	PIXEL_FORMAT_BAYERGR8													(char*)"BayerGR8"
#define	PIXEL_FORMAT_BAYERGR10													(char*)"BayerGR10"
#define	PIXEL_FORMAT_BAYERGR12													(char*)"BayerGR12"
#define	PIXEL_FORMAT_BAYERGR10PACKED											(char*)"BayerGR10Packed"
#define	PIXEL_FORMAT_BAYERGR12PACKED											(char*)"BayerGR12Packed"
#define	PIXEL_FORMAT_BAYERGB8													(char*)"BayerGB8"
#define	PIXEL_FORMAT_BAYERGB10													(char*)"BayerGB10"
#define	PIXEL_FORMAT_BAYERGB12													(char*)"BayerGB12"
#define	PIXEL_FORMAT_BAYERGB10PACKED											(char*)"BayerGB10Packed"
#define	PIXEL_FORMAT_BAYERGB12PACKED											(char*)"BayerGB12Packed"
#define	PIXEL_FORMAT_YUV422PACKED												(char*)"YUV422Packed"
#define	PIXEL_FORMAT_RGB8PACKED													(char*)"RGB8Packed"
#define	PIXEL_FORMAT_BGR8PACKED													(char*)"BGR8Packed"
#define	TEST_PATTERN_OFF														(char*)"Off"
#define	TEST_PATTERN_GREY_HORIZONTAL_RAMP										(char*)"GreyHorizontalRamp"
#define	TEST_PATTERN_GREY_VERTICAL_RAMP											(char*)"GreyVerticalRamp"
#define	ACQUISITION_MODE_CONTINUOUS												(char*)"Continuous"
#define	ACQUISITION_MODE_SINGLE_FRAME											(char*)"SingleFrame"
#define	ACQUISITION_MODE_MULTI_FRAME											(char*)"MultiFrame"
#define	TRIGGER_SELECTOR_FRAME_START											(char*)"FrameStart"
#define	TRIGGER_MODE_OFF														(char*)"Off"
#define	TRIGGER_MODE_ON															(char*)"On"
#define	TRIGGER_SOURCE_LINE1 													(char*)"Line1"
#define	TRIGGER_SOURCE_SOFTWARE 												(char*)"Software"
#define	TRIGGER_ACTIVATION_RISING_EDGE    										(char*)"RisingEdge"
#define	TRIGGER_ACTIVATION_FALLING_EDGE    										(char*)"FallingEdge"
#define	TRIGGER_ACTIVATION_LEVEL_LOW    										(char*)"LevelLow"
#define	TRIGGER_ACTIVATION_LEVEL_HIGH    										(char*)"LevelHigh"
#define	EXPOSURE_MODE_TIMED    													(char*)"Timed"
#define	EXPOSURE_MODE_TRIGGER_WIDTH 											(char*)"TriggerWidth"
#define	EXPOSURE_AUTO_OFF														(char*)"Off"
#define	EXPOSURE_AUTO_ONCE														(char*)"Once"
#define	EXPOSURE_AUTO_CONTINUOUS												(char*)"Continuous"
#define	ACQUISITION_FRAMERATE_ENABLE_OFF										(char*)"Off"
#define	ACQUISITION_FRAMERATE_ENABLE_ON											(char*)"On"
#define	LINE_SELECTOR_LINE1														(char*)"Line1"
#define	LINE_SELECTOR_LINE2														(char*)"Line2"
#define	LINE_MODE_INPUT															(char*)"Input"
#define	LINE_MODE_OUTPUT														(char*)"Output"
#define	LINE_SOURCE_OFF															(char*)"Off"
#define	LINE_SOURCE_EXPOSURE_ACTIVE												(char*)"ExposureActive"
#define	LINE_SOURCE_TIMER_ACTIVE												(char*)"TimerActive"
#define	LINE_SOURCE_USER_OUTPUT_1												(char*)"UserOutput1"
#define	USER_OUTPUT_SELECTOR_USER_OUTPUT_1										(char*)"UserOutput1"
#define	TIMER_SELECTOR_TIMER_1													(char*)"Timer1"
#define	GAIN_SELECTOR_ALL														(char*)"All"
#define	GAIN_AUTO_OFF															(char*)"Off"
#define	GAIN_AUTO_ONCE															(char*)"Once"
#define	GAIN_AUTO_CONTINUOUS													(char*)"Continuous"
#define	BLACK_LEVEL_SELECTOR_ALL												(char*)"All"
#define	BALANCE_RATIO_SELECTOR_RED												(char*)"Red"
#define	BALANCE_RATIO_SELECTOR_GREEN											(char*)"Green"
#define	BALANCE_RATIO_SELECTOR_BLUE												(char*)"Blue"
#define	BALANCE_WHITE_AUTO_OFF													(char*)"Off"
#define	BALANCE_WHITE_AUTO_ONCE													(char*)"Once"
#define	BALANCE_WHITE_AUTO_CONTINUOUS											(char*)"Continuous"
#define	GEV_DEVICE_MODE_CHARACTER_SET_UTF8										(char*)"UTF8"
#define	GEV_SUPPORTED_OPTION_SELECTOR_USER_DEFINED_NAME							(char*)"UserDefinedName"
#define	GEV_SUPPORTED_OPTION_SELECTOR_SERIAL_NUMBER								(char*)"SerialNumber"
#define	GEV_SUPPORTED_OPTION_SELECTOR_HEART_BEAT_DISABLE						(char*)"HeartbeatDisable"
#define	GEV_SUPPORTED_OPTION_SELECTOR_LINK_SPEED								(char*)"LinkSpeed"
#define	GEV_SUPPORTED_OPTION_SELECTOR_CCP_APPLICATION_SOCKET					(char*)"CCPApplicationSocket"
#define	GEV_SUPPORTED_OPTION_SELECTOR_MANIFEST_TABLE							(char*)"ManifestTable"
#define	GEV_SUPPORTED_OPTION_SELECTOR_TEST_DATA									(char*)"TestData"
#define	GEV_SUPPORTED_OPTION_SELECTOR_DISCOVERY_ACK_DELAY						(char*)"DiscoveryAckDelay"
#define	GEV_SUPPORTED_OPTION_SELECTOR_DISCOVERY_ACK_DELAY_WRITABLE				(char*)"DiscoveryAckDelayWritable"
#define	GEV_SUPPORTED_OPTION_SELECTOR_EXTENDED_STATUS_CODES						(char*)"ExtendedStatusCodes"
#define	GEV_SUPPORTED_OPTION_SELECTOR_PRIMARY_APPLICATION_SWITCH_OVER			(char*)"PrimaryApplicationSwitchover"
#define	GEV_SUPPORTED_OPTION_SELECTOR_ACTION									(char*)"Action"
#define	GEV_SUPPORTED_OPTION_SELECTOR_PENDING_ACK								(char*)"PendingAck"
#define	GEV_SUPPORTED_OPTION_SELECTOR_EVENT_DATA								(char*)"EventData"
#define	GEV_SUPPORTED_OPTION_SELECTOR_EVENT										(char*)"Event"
#define	GEV_SUPPORTED_OPTION_SELECTOR_PACKET_RESEND								(char*)"PacketResend"
#define	GEV_SUPPORTED_OPTION_SELECTOR_WRITE_MEM									(char*)"WriteMem"
#define	GEV_SUPPORTED_OPTION_SELECTOR_COMMANDS_CONCATENATION					(char*)"CommandsConcatenation"
#define	GEV_SUPPORTED_OPTION_SELECTOR_IP_CONFIGURATION_LLA						(char*)"IPConfigurationLLA"
#define	GEV_SUPPORTED_OPTION_SELECTOR_IP_CONFIGURATION_DHCP						(char*)"IPConfigurationDHCP"
#define	GEV_SUPPORTED_OPTION_SELECTOR_IP_CONFIGURATION_PERSISTENT_IP			(char*)"IPConfigurationPersistentIP"
#define	GEV_SUPPORTED_OPTION_SELECTOR_STREAM_CHANNEL_SOURCE_SOCKET				(char*)"StreamChannelSourceSocket"
#define	GEV_SUPPORTED_OPTION_SELECTOR_MESSAGE_CHANNEL_SOURCE_SOCKET				(char*)"MessageChannelSourceSocket"
#define	GEV_SUPPORTED_OPTION_SELECTOR_STREAM_CHANNEL_0_BIG_AND_LITTLE_ENDIAN	(char*)"StreamChannel0BigAndLittleEndian"
#define	GEV_SUPPORTED_OPTION_SELECTOR_STREAM_CHANNEL_0_IP_REASSEMBLY			(char*)"StreamChannel0IPReassembly"
#define	GEV_SUPPORTED_OPTION_SELECTOR_STREAM_CHANNEL_0_UNCONDITIONAL_STREAMING	(char*)"StreamChannel0UnconditionalStreaming"
#define	GEV_SUPPORTED_OPTION_SELECTOR_STREAM_CHANNEL_0_EXTENDED_CHUNK_DATA		(char*)"StreamChannel0ExtendedChunkData"
#define	GEV_CCP_OPEN_ACCESS														(char*)"OpenAccess"
#define	GEV_CCP_EXCLUSIVE_ACCESS												(char*)"ExclusiveAccess"
#define	GEV_CCP_CONTROL_ACCESS													(char*)"ControlAccess"
#define	USER_SET_SELECTOR_DEFAULT												(char*)"Default"
#define	USER_SET_SELECTOR_USER_SET_1											(char*)"UserSet1"
#define	USER_SET_SELECTOR_USER_SET_2											(char*)"UserSet2"
#define	USER_SET_SELECTOR_USER_SET_3											(char*)"UserSet3"
#define	COLOR_TRANSFORMATION_VALUE_SELECTOR_HUEBYGP								(char*)"HUEBYGP"
#define	COLOR_TRANSFORMATION_VALUE_SELECTOR_HUEBYGN								(char*)"HUEBYGN"
#define	COLOR_TRANSFORMATION_VALUE_SELECTOR_HUEBYHP								(char*)"HUEBYHP"
#define	COLOR_TRANSFORMATION_VALUE_SELECTOR_HUEBYHN								(char*)"HUEBYHN"
#define	COLOR_TRANSFORMATION_VALUE_SELECTOR_HUERYGP								(char*)"HUERYGP"
#define	COLOR_TRANSFORMATION_VALUE_SELECTOR_HUERYGN								(char*)"HUERYGN"
#define	COLOR_TRANSFORMATION_VALUE_SELECTOR_HUERYHP								(char*)"HUERYHP"
#define	COLOR_TRANSFORMATION_VALUE_SELECTOR_HUERYHN								(char*)"HUERYHN"
#define	COLOR_TRANSFORMATION_VALUE_SELECTOR_HUECG								(char*)"HUECG"
#define	DEVICE_FILTER_DRIVER_MODE_OFF											(char*)"Off"
#define	DEVICE_FILTER_DRIVER_MODE_ON											(char*)"On"
#define	DEVICE_MISSING_PACKET_RECEIVE_OFF										(char*)"Off"
#define	DEVICE_MISSING_PACKET_RECEIVE_ON										(char*)"On"

enum ConvertColor
{	
	CVP_BGR2RGB			= 4,
	CVP_RGB2BGR			= CVP_BGR2RGB,
	CVP_BayerBG2RGB		= 48,
	CVP_BayerGB2RGB		= 49,
	CVP_BayerRG2RGB		= 46,
	CVP_BayerGR2RGB		= 47,
	CVP_YUV2RGB_UYVY	= 107,
	CVP_YUV2BGR_UYVY	= 108,
	CVP_YUV2RGB_YVYU	= 117,
	CVP_YUV2BGR_YVYU	= 118,
	CVP_YUV2RGB_YUYV	= 115,
	CVP_YUV2BGR_YUYV	= 116,
};

extern "C"  {

__int32	__stdcall		ST_InitSystem();	
__int32	__stdcall		ST_FreeSystem();
__int32	__stdcall		ST_IsInitSystem(bool* pFlag);
__int32	__stdcall		ST_GetAvailableCameraNum(unsigned __int32* pNum);
__int32 __stdcall		ST_UpdateDevice();
__int32	__stdcall		ST_GetEnumDeviceID(unsigned __int32 EnumNum, char* pDeviceID, unsigned __int32* pSize);
__int32	__stdcall		ST_GetEnumDeviceInfo(unsigned __int32 EnumNum, __int32 DeviceInfoCmd, char* pDeviceInfo, unsigned __int32* pSize);
//////////////////////////////////////////////////////////////////////////////////////////////////////
__int32	__stdcall		ST_OpenDevice(unsigned __int32 EnumNum, __int32* hDevice, bool isDetailedLog = FALSE);
__int32	__stdcall		ST_IsOpenDevice(__int32 hDevice, bool* pFlag);					
__int32	__stdcall		ST_CloseDevice(__int32 hDevice);
__int32	__stdcall		ST_AcqStart(__int32 hDevice);
__int32	__stdcall		ST_AcqStop(__int32 hDevice);
__int32	__stdcall		ST_DoAbortGrab(__int32 hDevice);
__int32	__stdcall		ST_SetAcqInvalidTime(__int32 hDevice, unsigned __int32 Time);	
__int32	__stdcall		ST_GetAcqInvalidTime(__int32 hDevice, unsigned __int32* pTime);
__int32	__stdcall		ST_SetContinuousGrabbing(__int32 hDevice, unsigned __int32 Flag);
__int32	__stdcall		ST_GetContinuousGrabbing(__int32 hDevice, unsigned __int32* pFlag);
__int32	__stdcall		ST_SetGrabTimeout(__int32 hDevice, unsigned __int32 Timeout);
__int32	__stdcall		ST_GetGrabTimeout(__int32 hDevice, unsigned __int32* pTimeout);
__int32	__stdcall		ST_GrabStartAsync(__int32 hDevice, unsigned __int32 MaxDelay);
__int32	__stdcall		ST_GrabImage(__int32 hDevice, void* pDest, unsigned __int32 Buffsize);
__int32	__stdcall		ST_GrabImageAsync(__int32 hDevice, void* pDest, unsigned __int32 Buffsize, unsigned __int32 MaxDelay);
__int32	__stdcall		ST_GetImageAvailable(__int32 hDevice, unsigned __int32* pFlag);	
//////////////////////////////////////////////////////////////////////////////////////////////////////
__int32	__stdcall		ST_GetTotalPacketCount(__int32 hDevice, unsigned __int64* TotalPacketCount, unsigned __int64* TotalLostPacketCount);
__int32	__stdcall		ST_GetLastError(__int32 hDevice, const char* szError);
__int32	__stdcall		ST_GetLastErrorDescription(__int32 errCode, const char* szDescription);
__int32 __stdcall		ST_SetDetailedLog(__int32 hDevice, bool Flag);
__int32 __stdcall		ST_GetDetailedLog(__int32 hDevice, bool* pFlag);
//////////////////////////////////////////////////////////////////////////////////////////////////////
__int32	__stdcall		ST_SetIntReg	(__int32 hDevice, const char* NodeName, __int32 val);
__int32	__stdcall		ST_GetIntReg	(__int32 hDevice, const char* NodeName, __int32 *pVal);
__int32	__stdcall		ST_SetFloatReg	(__int32 hDevice, const char* NodeName, double fVal);
__int32	__stdcall		ST_GetFloatReg	(__int32 hDevice, const char* NodeName, double *pFval);
__int32	__stdcall		ST_SetBoolReg	(__int32 hDevice, const char* NodeName, bool bVal);	
__int32	__stdcall		ST_GetBoolReg	(__int32 hDevice, const char* NodeName, bool *pBval);
__int32	__stdcall		ST_SetEnumReg	(__int32 hDevice, const char* NodeName, char* val);
__int32	__stdcall		ST_GetEnumReg	(__int32 hDevice, const char* NodeName, char* pInfo, unsigned __int32* pSize);
__int32 __stdcall		ST_SetStrReg	(__int32 hDevice, const char* NodeName, char* val);
__int32	__stdcall		ST_GetStrReg	(__int32 hDevice, const char* NodeName, char* pInfo, unsigned __int32* pSize);
__int32 __stdcall		ST_SetCmdReg	(__int32 hDevice, const char* NodeName);
//////////////////////////////////////////////////////////////////////////////////////////////////////
__int32 __stdcall		ST_GetIntRegRange(__int32 hDevice, const char* NodeName, __int32 *pMin, __int32 *pMax, __int32 *pInc);
__int32 __stdcall		ST_GetFloatRegRange(__int32 hDevice, const char* NodeName, double *pMin, double *pMax);
__int32 __stdcall		ST_GetEnumEntrySize(__int32 hDevice, const char* NodeName, __int32 *pVal);
__int32 __stdcall		ST_GetEnumEntryIntValue(__int32 hDevice, const char* NodeName, __int32 EntryIdx, __int32 *pVal);
__int32 __stdcall		ST_GetEnumEntryValue(__int32 hDevice, const char* NodeName, __int32 EntryIdx, char* pInfo, unsigned __int32 *pSize);	

// color interpolation
__int32 __stdcall		ST_CvtColor(void* pSrc, void* pDest, __int32 width, __int32 height, __int32 code);			

//for Callback Function
__int32	__stdcall		ST_SetCallbackFunction(__int32 hDevice, __int32 Event, GrabCallback grabCallback, void* UserData);

//for Debug
__int32 __stdcall		ST_ReadParam(__int32 hDevice, void *pBuffer, __int64 Address, __int64 Length);
__int32 __stdcall		ST_WriteParam(__int32 hDevice, const void *pBuffer, __int64 Address, __int64 Length);
}

#endif	//_VIRTUAL_FRAME_GRABBER_DEF_H