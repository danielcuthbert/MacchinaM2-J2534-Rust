#ifndef J2534_MINI_H_
#define J2534_MINI_H_

// Just stores relivant J2534 values to channels and IOCTL commands

// Protocols
#define	J1850VPW	 0x01 // J1850 VPW protocol
#define	J1850PWM	 0x02 // K1850 PWM protocol
#define	ISO9141		 0x03 // IOS9141 protocol (Uses K-Line)
#define	ISO14230	 0x04 // ISO14230 protocol (Uses K-Line)
#define	CAN			 0x05 // CAN protocol (Uses CAN-D)
#define	ISO15765	 0x06 // ISO15765 protocol (Uses CAN-D)
#define	SCI_A_ENGINE 0x07 // SCI_A_ENGINE TODO - Not supported ATM
#define	SCI_A_TRANS	 0x08 // SCI_A_TRANS  TODO - Not supported ATM
#define	SCI_B_ENGINE 0x09 // SCI_B_ENGINE TODO - Not supported ATM
#define	SCI_B_TRANS	 0x0A // SCI_B_TRANS  TODO - Not supported ATM

// Error definitions
#define		STATUS_NOERROR			  0x00	// Function completed successfully.
#define		ERR_NOT_SUPPORTED		  0x01	// Function option is not supported.
#define		ERR_INVALID_CHANNEL_ID    0x02	// Channel Identifier or handle is not recognized.
#define		ERR_INVALID_PROTOCOL_ID	  0x03	// Protocol Identifier is not recognized.
#define		ERR_NULL_PARAMETER		  0x04	// NULL pointer presented as a function parameter, NULL is an invalid address.
#define		ERR_INVALID_IOCTL_VALUE	  0x05	// Ioctl GET_CONFIG/SET_CONFIG parameter value is not recognized.
#define		ERR_INVALID_FLAGS		  0x06	// Flags bit field(s) contain(s) an invalid value.
#define		ERR_FAILED			      0x07	// Unspecified error, use PassThruGetLastError for obtaining error text string.
#define		ERR_DEVICE_NOT_CONNECTED  0x08	// PassThru device is not connected to the PC.
#define		ERR_TIMEOUT			      0x09	// Timeout violation. PassThru device is unable to read specified number of messages from the vehicle network. The actual number of messages returned is in NumMsgs.
#define		ERR_INVALID_MSG			  0x0A	// Message contained a min/max length, ExtraData support or J1850PWM specific source address conflict violation.
#define		ERR_INVALID_TIME_INTERVAL 0x0B	// The time interval value is outside the specified range.
#define		ERR_EXCEEDED_LIMIT		  0x0C	// The limit(ten) of filter/periodic messages has been exceeded for the protocol associated the communications channel.
#define		ERR_INVALID_MSG_ID		  0x0D	// The message identifier or handle is not recognized.
#define		ERR_DEVICE_IN_USE		  0x0E	// The specified PassThru device is already in use.
#define		ERR_INVALID_IOCTL_ID	  0x0F	// Ioctl identifier is not recognized.
#define		ERR_BUFFER_EMPTY		  0x10	// PassThru device could not read any messages from the vehicle network.
#define		ERR_BUFFER_FULL			  0x11	// PassThru device could not queue any more transmit messages destined for the vehicle network.
#define		ERR_BUFFER_OVERFLOW		  0x12	// PassThru device experienced a buffer overflow and receive messages were lost.
#define		ERR_PIN_INVALID			  0x13	// Unknown pin number specified for the J1962 connector.
#define		ERR_CHANNEL_IN_USE		  0x14	// An existing communications channel is currently using the specified network protocol.
#define		ERR_MSG_PROTOCOL_ID		  0x15	// The specified protocol type within the message structure is different from the protocol associated with the communications channel when it was opened.
#define		ERR_INVALID_FILTER_ID	  0x16	// Filter identifier is not recognized.
#define		ERR_NO_FLOW_CONTROL		  0x17	// No ISO15765 flow control filter is set, or no filter matches the header of an outgoing message.
#define		ERR_NOT_UNIQUE			  0x18	// An existing filter already matches this header or node identifier.
#define		ERR_INVALID_BAUDRATE	  0x19	// Unable to honor requested Baud rate within required tolerances.
#define		ERR_INVALID_DEVICE_ID	  0x1A	// PassThru device identifier is not recognized.

// Some useful flags (Channel creation)
#define		CAN_29BIT_ID		0x00000100
#define		ISO9141_NO_CHECKSUM	0x00000200
#define		CAN_ID_BOTH		    0x00000800
#define		ISO9141_K_LINE_ONLY	0x00001000

// Filter type
#define PASS_FILTER         0x01
#define BLOCK_FILTER        0x02
#define FLOW_CONTROL_FILTER 0x03


// Tx flags
#define	SCI_TX_VOLTAGE		0x00800000	// SCI programming: 0 = do not apply voltage after transmitting message, 1 = apply voltage(20V) after transmitting message
#define	SCI_MODE		    0x00400000
#define	WAIT_P3_MIN_ONLY	0x00000200
#define	CAN_29BIT_ID		0x00000100	// CAN ID Type: 0 = 11-bit, 1 = 29-bit
#define	CAN_EXTENDED_ID		0x00000100
#define	ISO15765_ADDR_TYPE	0x00000080	// ISO15765-2 Addressing mode: 0 = No extended address, 1 = Extended address is first byte following the CAN ID
#define	ISO15765_EXT_ADDR	0x00000080
#define	ISO15765_FRAME_PAD	0x00000040	// ISO15765-2 Frame Pad mode: 0 = No frame padding, 1 = Zero pad FlowControl, Single and Last ConsecutiveFrame to full CAN frame size.
#define	TX_NORMAL_TRANSMIT	0x00000000

// Rx status flags:
#define	CAN_29BIT_ID		    0x00000100	// CAN ID Type: 0 = 11-bit, 1 = 29-bit
#define	ISO15765_ADDR_TYPE	    0x00000080
#define	ISO15765_PADDING_ERROR	0x00000010
#define	TX_DONE			        0x00000008
#define	RX_BREAK		        0x00000004	// Receive Break: 0 = No Break indication, 1 = Break indication present
#define	ISO15765_FIRST_FRAME	0x00000002	// ISO15765-2 only: 0 = No First Frame indication, 1 = First Frame indication
#define	START_OF_MESSAGE	    0x00000002	// ISO15765-2 only: 0 = No First Frame indication, 1 = First Frame indication
#define	TX_MSG_TYPE		        0x00000001	// Receive Indication/Transmit Confirmation: 0 = Rx Frame indication, 1 = Tx Frame confirmation


// Ioctl parameters for GET_CONFIG and SET_CONFIG
#define		DATA_RATE		     0x01	// 5 – 500000 	// Baud rate value used for vehicle network. No default value specified.
#define		LOOPBACK		     0x03	// 0(OFF)/1(ON)	// 0 = Do not echo transmitted messages to the Receive queue. 1 = Echo transmitted messages to the Receive queue.
								                        // Default value is 0(OFF).
#define		NODE_ADDRESS         0x04	// 0x00-0xFF	// J1850PWM specific, physical address for node of interest in the vehicle network. Default is no nodes are recognized by scan tool.
#define		NETWORK_LINE	     0x05	// 0(BUS_NORMAL)/1(BUS_PLUS)/2(BUS_MINUS)	// J1850PWM specific, network line(s) active during message transfers. Default value is 0(BUS_NORMAL).
#define		P1_MIN			     0x06	// 0x0-0xFFFF	// ISO-9141/14230 specific, min. ECU inter-byte time for responses [02.02-API: ms]. Default value is 0 ms. 04.04-API: NOT ADJUSTABLE, 0ms.
#define		P1_MAX			     0x07	// 0x0/0x1-0xFFFF // ISO-9141/14230 specific, max. ECU inter-byte time for responses [02.02-API: ms, 04.04-API: *0.5ms]. Default value is 20 ms.
#define		P2_MIN			     0x08	// 0x0-0xFFFF	// ISO-9141/14230 specific, min. ECU response time to a tester request or between ECU responses [02.02-API: ms, 04.04-API: *0.5ms]. 04.04-API: NOT ADJUSTABLE, 0ms. Default value is 25 ms.
#define		P2_MAX			     0x09	// 0x0-0xFFFF	// ISO-9141/14230 specific, max. ECU response time to a tester request or between ECU responses [02.02-API: ms, 04.04-API: *0.5ms]. 04.04-API: NOT ADJUSTABLE, all messages up to P3_MIN are receoved. Default value is 50 ms.
#define		P3_MIN			     0x0A	// 0x0-0xFFFF	// ISO-9141/14230 specific, min. ECU response time between end of ECU response and next tester request [02.02-API: ms, 04.04-API: *0.5ms]. Default value is 55 ms.
#define		P3_MAX			     0x0B	// 0x0-0xFFFF	// ISO-9141/14230 specific, max. ECU response time between end of ECU response and next tester request [02.02-API: ms, 04.04-API: *0.5ms]. 04.04-API: NOT ADJUSTABLE, messages can be sent at anytime after P3_MIN. Default value is 5000 ms.
#define		P4_MIN			     0x0C	// 0x0-0xFFFF	// ISO-9141/14230 specific, min. tester inter-byte time for a request [02.02-API: ms, 04.04-API: *0.5ms]. Default value is 5 ms.
#define		P4_MAX			     0x0D	// 0x0-0xFFFF	// ISO-9141/14230 specific, max. tester inter-byte time for a request [02.02-API: ms, 04.04-API: *0.5ms]. 04.04-API: NOT ADJUSTABLE, P4_MIN is always used. Default value is 20 ms.
#define		W1			         0x0E	// 0x0-0xFFFF	// ISO 9141 specific, max. time [ms] from the address byte end to synchronization pattern start. Default value is 300 ms.
#define		W2			         0x0F	// 0x0-0xFFFF	// ISO 9141 specific, max. time [ms] from the synchronization byte end to key byte 1 start. Default value is 20 ms.
#define		W3			         0x10	// 0x0-0xFFFF	// ISO 9141 specific, max. time [ms] between key byte 1 and key byte 2. Default value is 20 ms.
#define		W4			         0x11	// 0x0-0xFFFF	// ISO 9141 specific, 02.02-API: max. time [ms] between key byte 2 and its inversion from the tester. Default value is 50 ms.
								                        // ISO 9141 specific, 04.04-API: min. time [ms] between key byte 2 and its inversion from the tester. Default value is 50 ms.
#define		W5			        0x12	// 0x0-0xFFFF	// ISO 9141 specific, min. time [ms] before the tester begins retransmission of the address byte. Default value is 300 ms.
#define		TIDLE			    0x13	// 0x0-0xFFFF	// ISO 9141 specific, bus idle time required before starting a fast initialization sequence. Default value is W5 value.
#define		TINL			    0x14	// 0x0-0xFFFF	// ISO 9141 specific, the duration [ms] of the fast initialization low pulse. Default value is 25 ms.
#define		TWUP			    0x15	// 0x0-0xFFFF	// ISO 9141 specific, the duration [ms] of the fast initialization wake-up pulse. Default value is 50 ms.
#define		PARITY			    0x16	// 0(NO_PARITY)/1(ODD_PARITY)/2(EVEN_PARITY)	// ISO9141 specific, parity type for detecting bit errors.  Default value is 0(NO_PARITY).
#define		BIT_SAMPLE_POINT	0x17	// 0-100	// CAN specific, the desired bit sample point as a percentage of bit time. Default value is 80%.
#define		SYNCH_JUMP_WIDTH	0x18	// 0-100	// CAN specific, the desired synchronization jump width as a percentage of the bit time. Default value is 15%.
#define		W0			        0x19
#define		T1_MAX			    0x1A	// 0x0-0xFFFF	// SCI_X_XXXX specific, the max. interframe response delay. Default value is 20 ms.
#define		T2_MAX			    0x1B	// 0x0-0xFFFF	// SCI_X_XXXX specific, the max. interframe request delay.Default value is 100 ms.
#define		T4_MAX			    0x1C	// 0x0-0xFFFF	// SCI_X_XXXX specific, the max. intermessage response delay. Default value is 20 ms.
#define		T5_MAX			    0x1D	// 0x0-0xFFFF	// SCI_X_XXXX specific, the max. intermessage request delay. Default value is 100 ms.
#define		ISO15765_BS		    0x1E	// 0x0-0xFF	// ISO15765 specific, the block size for segmented transfers.
								                    // The scan tool may override this value to match the capabilities reported by the ECUs. Default value is 0. */
#define		ISO15765_STMIN		0x1F	// 0x0-0xFF	// ISO15765 specific, the separation time for segmented transfers.
								                    // The scan tool may override this value to match the capabilities reported by the ECUs. Default value is 0.
#define		DATA_BITS		    0x20	// 04.04-API only
#define		FIVE_BAUD_MOD		0x21
#define		BS_TX			    0x22
#define		STMIN_TX		    0x23
#define		T3_MAX			    0x24
#define		ISO15765_WFT_MAX	0x25

#endif