/*====================================================================
* Project:  Board Support Package (BSP)
* Function: Interrupt Service Node IDs on TC39xB
*
* Copyright HighTec EDV-Systeme GmbH 1982-2019
*====================================================================*/

#ifndef __INTIDS_TC39XB_H__
#define __INTIDS_TC39XB_H__

/* Interrupt SRC IDs */
#define SRC_ID_CPU0SB			0	/* CPU 0 Software Breakpoint Service Request */
#define SRC_ID_CPU1SB			1	/* CPU 1 Software Breakpoint Service Request */
#define SRC_ID_CPU2SB			2	/* CPU 2 Software Breakpoint Service Request */
#define SRC_ID_CPU3SB			3	/* CPU 3 Software Breakpoint Service Request */
#define SRC_ID_CPU4SB			4	/* CPU 4 Software Breakpoint Service Request */
#define SRC_ID_CPU5SB			5	/* CPU 5 Software Breakpoint Service Request */

#define SRC_ID_BCUSPB			8	/* Bus Control Unit SPB Service Request */
#define SRC_ID_BCUBBB			9	/* Bus Control Unit BBB Service Request (ED only) */

#define SRC_ID_AGBT				11	/* AGBT Service Request (ED only) */

#define SRC_ID_XBAR0			12	/* Domain 0 XBAR_SRI Service Request */
#define SRC_ID_XBAR1			13	/* Domain 1 XBAR_SRI Service Request */
#define SRC_ID_XBAR2			14	/* ED Domain XBAR_SRI Service Request (ED only) */

#define SRC_ID_CERBERUS0		16	/* Cerberus Service Request 0 */
#define SRC_ID_CERBERUS1		17	/* Cerberus Service Request 1 */

#define SRC_ID_ASCLIN0TX		20	/* ASCLIN 0 Transmit Service Request */
#define SRC_ID_ASCLIN0RX		21	/* ASCLIN 0 Receive Service Request */
#define SRC_ID_ASCLIN0EX		22	/* ASCLIN 0 Error Service Request */
#define SRC_ID_ASCLIN1TX		23	/* ASCLIN 1 Transmit Service Request */
#define SRC_ID_ASCLIN1RX		24	/* ASCLIN 1 Receive Service Request */
#define SRC_ID_ASCLIN1EX		25	/* ASCLIN 1 Error Service Request */
#define SRC_ID_ASCLIN2TX		26	/* ASCLIN 2 Transmit Service Request */
#define SRC_ID_ASCLIN2RX		27	/* ASCLIN 2 Receive Service Request */
#define SRC_ID_ASCLIN2EX		28	/* ASCLIN 2 Error Service Request */
#define SRC_ID_ASCLIN3TX		29	/* ASCLIN 3 Transmit Service Request */
#define SRC_ID_ASCLIN3RX		30	/* ASCLIN 3 Receive Service Request */
#define SRC_ID_ASCLIN3EX		31	/* ASCLIN 3 Error Service Request */
#define SRC_ID_ASCLIN4TX		32	/* ASCLIN 4 Transmit Service Request */
#define SRC_ID_ASCLIN4RX		33	/* ASCLIN 4 Receive Service Request */
#define SRC_ID_ASCLIN4EX		34	/* ASCLIN 4 Error Service Request */
#define SRC_ID_ASCLIN5TX		35	/* ASCLIN 5 Transmit Service Request */
#define SRC_ID_ASCLIN5RX		36	/* ASCLIN 5 Receive Service Request */
#define SRC_ID_ASCLIN5EX		37	/* ASCLIN 5 Error Service Request */
#define SRC_ID_ASCLIN6TX		38	/* ASCLIN 6 Transmit Service Request */
#define SRC_ID_ASCLIN6RX		39	/* ASCLIN 6 Receive Service Request */
#define SRC_ID_ASCLIN6EX		40	/* ASCLIN 6 Error Service Request */
#define SRC_ID_ASCLIN7TX		41	/* ASCLIN 7 Transmit Service Request */
#define SRC_ID_ASCLIN7RX		42	/* ASCLIN 7 Receive Service Request */
#define SRC_ID_ASCLIN7EX		43	/* ASCLIN 7 Error Service Request */
#define SRC_ID_ASCLIN8TX		44	/* ASCLIN 8 Transmit Service Request */
#define SRC_ID_ASCLIN8RX		45	/* ASCLIN 8 Receive Service Request */
#define SRC_ID_ASCLIN8EX		46	/* ASCLIN 8 Error Service Request */
#define SRC_ID_ASCLIN9TX		47	/* ASCLIN 9 Transmit Service Request */
#define SRC_ID_ASCLIN9RX		48	/* ASCLIN 9 Receive Service Request */
#define SRC_ID_ASCLIN9EX		49	/* ASCLIN 9 Error Service Request */
#define SRC_ID_ASCLIN10TX		50	/* ASCLIN 10 Transmit Service Request */
#define SRC_ID_ASCLIN10RX		51	/* ASCLIN 10 Receive Service Request */
#define SRC_ID_ASCLIN10EX		52	/* ASCLIN 10 Error Service Request */
#define SRC_ID_ASCLIN11TX		53	/* ASCLIN 11 Transmit Service Request */
#define SRC_ID_ASCLIN11RX		54	/* ASCLIN 11 Receive Service Request */
#define SRC_ID_ASCLIN11EX		55	/* ASCLIN 11 Error Service Request */

#define SRC_ID_MTUDONE			59	/* MTU Done Service Request */

#define SRC_ID_QSPI0TX			60	/* QSPI 0 Transmit Service Request */
#define SRC_ID_QSPI0RX			61	/* QSPI 0 Receive Service Request */
#define SRC_ID_QSPI0ERR			62	/* QSPI 0 Error Service Request */
#define SRC_ID_QSPI0PT			63	/* QSPI 0 Phase Transition Service Request */
#define SRC_ID_QSPI0U			64	/* QSPI 0 User Defined Service Request */
#define SRC_ID_QSPI1TX			65	/* QSPI 1 Transmit Service Request */
#define SRC_ID_QSPI1RX			66	/* QSPI 1 Receive Service Request */
#define SRC_ID_QSPI1ERR			67	/* QSPI 1 Error Service Request */
#define SRC_ID_QSPI1PT			68	/* QSPI 1 Phase Transition Service Request */
#define SRC_ID_QSPI1U			69	/* QSPI 1 User Defined Service Request */
#define SRC_ID_QSPI2TX			70	/* QSPI 2 Transmit Service Request */
#define SRC_ID_QSPI2RX			71	/* QSPI 2 Receive Service Request */
#define SRC_ID_QSPI2ERR			72	/* QSPI 2 Error Service Request */
#define SRC_ID_QSPI2PT			73	/* QSPI 2 Phase Transition Service Request */
#define SRC_ID_QSPI2U			74	/* QSPI 2 User Defined Service Request */
#define SRC_ID_QSPI3TX			75	/* QSPI 3 Transmit Service Request */
#define SRC_ID_QSPI3RX			76	/* QSPI 3 Receive Service Request */
#define SRC_ID_QSPI3ERR			77	/* QSPI 3 Error Service Request */
#define SRC_ID_QSPI3PT			78	/* QSPI 3 Phase Transition Service Request */
#define SRC_ID_QSPI3U			79	/* QSPI 3 User Defined Service Request */
#define SRC_ID_QSPI4TX			80	/* QSPI 4 Transmit Service Request */
#define SRC_ID_QSPI4RX			81	/* QSPI 4 Receive Service Request */
#define SRC_ID_QSPI4ERR			82	/* QSPI 4 Error Service Request */
#define SRC_ID_QSPI4PT			83	/* QSPI 4 Phase Transition Service Request */
#define SRC_ID_QSPI4U			84	/* QSPI 4 User Defined Service Request */
#define SRC_ID_QSPI5TX			85	/* QSPI 5 Transmit Service Request */
#define SRC_ID_QSPI5RX			86	/* QSPI 5 Receive Service Request */
#define SRC_ID_QSPI5ERR			87	/* QSPI 5 Error Service Request */
#define SRC_ID_QSPI5PT			88	/* QSPI 5 Phase Transition Service Request */
#define SRC_ID_QSPI5U			89	/* QSPI 5 User Defined Service Request */

#define SRC_ID_QSPI2HC			92	/* QSPI 2 High Speed Capture Service Request */
#define SRC_ID_QSPI3HC			93	/* QSPI 3 High Speed Capture Service Request */

#define SRC_ID_HSCT0			94	/* HSCT0 Service Request */
#define SRC_ID_HSCT1			95	/* HSCT1 Service Request */

#define SRC_ID_HSSL0COK0		100	/* HSSL0 Channel 0 OK Service Request */
#define SRC_ID_HSSL0RDI0		101	/* HSSL0 Channel 0 Read Data Service Request */
#define SRC_ID_HSSL0ERR0		102	/* HSSL0 Channel 0 Error Service Request */
#define SRC_ID_HSSL0TRG0		103	/* HSSL0 Channel 0 Trigger Service Request */
#define SRC_ID_HSSL0COK1		104	/* HSSL0 Channel 1 OK Service Request */
#define SRC_ID_HSSL0RDI1		105	/* HSSL0 Channel 1 Read Data Service Request */
#define SRC_ID_HSSL0ERR1		106	/* HSSL0 Channel 1 Error Service Request */
#define SRC_ID_HSSL0TRG1		107	/* HSSL0 Channel 1 Trigger Service Request */
#define SRC_ID_HSSL0COK2		108	/* HSSL0 Channel 2 OK Service Request */
#define SRC_ID_HSSL0RDI2		109	/* HSSL0 Channel 2 Read Data Service Request */
#define SRC_ID_HSSL0ERR2		110	/* HSSL0 Channel 2 Error Service Request */
#define SRC_ID_HSSL0TRG2		111	/* HSSL0 Channel 2 Trigger Service Request */
#define SRC_ID_HSSL0COK3		112	/* HSSL0 Channel 3 OK Service Request */
#define SRC_ID_HSSL0RDI3		113	/* HSSL0 Channel 3 Read Data Service Request */
#define SRC_ID_HSSL0ERR3		114	/* HSSL0 Channel 3 Error Service Request */
#define SRC_ID_HSSL0TRG3		115	/* HSSL0 Channel 3 Trigger Service Request */
#define SRC_ID_HSSL0EXI			116	/* HSSL0 Exception Service Request */
#define SRC_ID_HSSL1COK0		117	/* HSSL1 Channel 0 OK Service Request */
#define SRC_ID_HSSL1RDI0		118	/* HSSL1 Channel 0 Read Data Service Request */
#define SRC_ID_HSSL1ERR0		119	/* HSSL1 Channel 0 Error Service Request */
#define SRC_ID_HSSL1TRG0		120	/* HSSL1 Channel 0 Trigger Service Request */
#define SRC_ID_HSSL1COK1		121	/* HSSL1 Channel 1 OK Service Request */
#define SRC_ID_HSSL1RDI1		122	/* HSSL1 Channel 1 Read Data Service Request */
#define SRC_ID_HSSL1ERR1		123	/* HSSL1 Channel 1 Error Service Request */
#define SRC_ID_HSSL1TRG1		124	/* HSSL1 Channel 1 Trigger Service Request */
#define SRC_ID_HSSL1COK2		125	/* HSSL1 Channel 2 OK Service Request */
#define SRC_ID_HSSL1RDI2		126	/* HSSL1 Channel 2 Read Data Service Request */
#define SRC_ID_HSSL1ERR2		127	/* HSSL1 Channel 2 Error Service Request */
#define SRC_ID_HSSL1TRG2		128	/* HSSL1 Channel 2 Trigger Service Request */
#define SRC_ID_HSSL1COK3		129	/* HSSL1 Channel 3 OK Service Request */
#define SRC_ID_HSSL1RDI3		130	/* HSSL1 Channel 3 Read Data Service Request */
#define SRC_ID_HSSL1ERR3		131	/* HSSL1 Channel 3 Error Service Request */
#define SRC_ID_HSSL1TRG3		132	/* HSSL1 Channel 3 Trigger Service Request */
#define SRC_ID_HSSL1EXI			133	/* HSSL1 Exception Service Request */

#define SRC_ID_I2C0DTR			136	/* I2C 0 Data Transfer Request */
#define SRC_ID_I2C0ERR			137	/* I2C 0 Error Service Request */
#define SRC_ID_I2C0P			138	/* I2C 0 Protocol Service Request */

#define SRC_ID_I2C1DTR			140	/* I2C 1 Data Transfer Request */
#define SRC_ID_I2C1ERR			141	/* I2C 1 Error Service Request */
#define SRC_ID_I2C1P			142	/* I2C 1 Protocol Service Request */

#define SRC_ID_SENT0			144	/* SENT TRIG0 Service Request */
#define SRC_ID_SENT1			145	/* SENT TRIG1 Service Request */
#define SRC_ID_SENT2			146	/* SENT TRIG2 Service Request */
#define SRC_ID_SENT3			147	/* SENT TRIG3 Service Request */
#define SRC_ID_SENT4			148	/* SENT TRIG4 Service Request */
#define SRC_ID_SENT5			149	/* SENT TRIG5 Service Request */
#define SRC_ID_SENT6			150	/* SENT TRIG6 Service Request */
#define SRC_ID_SENT7			151	/* SENT TRIG7 Service Request */
#define SRC_ID_SENT8			152	/* SENT TRIG8 Service Request */
#define SRC_ID_SENT9			153	/* SENT TRIG9 Service Request */

#define SRC_ID_MSC0SR0			156	/* MSC 0 Service Request 0 */
#define SRC_ID_MSC0SR1			157	/* MSC 0 Service Request 1 */
#define SRC_ID_MSC0SR2			158	/* MSC 0 Service Request 2 */
#define SRC_ID_MSC0SR3			159	/* MSC 0 Service Request 3 */
#define SRC_ID_MSC0SR4			160	/* MSC 0 Service Request 4 */
#define SRC_ID_MSC1SR0			161	/* MSC 1 Service Request 0 */
#define SRC_ID_MSC1SR1			162	/* MSC 1 Service Request 1 */
#define SRC_ID_MSC1SR2			163	/* MSC 1 Service Request 2 */
#define SRC_ID_MSC1SR3			164	/* MSC 1 Service Request 3 */
#define SRC_ID_MSC1SR4			165	/* MSC 1 Service Request 4 */
#define SRC_ID_MSC2SR0			166	/* MSC 2 Service Request 0 */
#define SRC_ID_MSC2SR1			167	/* MSC 2 Service Request 1 */
#define SRC_ID_MSC2SR2			168	/* MSC 2 Service Request 2 */
#define SRC_ID_MSC2SR3			169	/* MSC 2 Service Request 3 */
#define SRC_ID_MSC2SR4			170	/* MSC 2 Service Request 4 */
#define SRC_ID_MSC3SR0			171	/* MSC 3 Service Request 0 */
#define SRC_ID_MSC3SR1			172	/* MSC 3 Service Request 1 */
#define SRC_ID_MSC3SR2			173	/* MSC 3 Service Request 2 */
#define SRC_ID_MSC3SR3			174	/* MSC 3 Service Request 3 */
#define SRC_ID_MSC3SR4			175	/* MSC 3 Service Request 4 */

#define SRC_ID_CCU60SR0			176	/* CCU6 0 Service Request 0 */
#define SRC_ID_CCU60SR1			177	/* CCU6 0 Service Request 1 */
#define SRC_ID_CCU60SR2			178	/* CCU6 0 Service Request 2 */
#define SRC_ID_CCU60SR3			179	/* CCU6 0 Service Request 3 */
#define SRC_ID_CCU61SR0			180	/* CCU6 1 Service Request 0 */
#define SRC_ID_CCU61SR1			181	/* CCU6 1 Service Request 1 */
#define SRC_ID_CCU61SR2			182	/* CCU6 1 Service Request 2 */
#define SRC_ID_CCU61SR3			183	/* CCU6 1 Service Request 3 */

#define SRC_ID_GPT120CIRQ		184	/* GPT120 CAPREL Service Request */
#define SRC_ID_GPT120T2			185	/* GPT120 T2 Overflow/Underflow Service Request */
#define SRC_ID_GPT120T3			186	/* GPT120 T3 Overflow/Underflow Service Request */
#define SRC_ID_GPT120T4			187	/* GPT120 T4 Overflow/Underflow Service Request */
#define SRC_ID_GPT120T5			188	/* GPT120 T5 Overflow/Underflow Service Request */
#define SRC_ID_GPT120T6			189	/* GPT120 T6 Overflow/Underflow Service Request */

#define SRC_ID_STM0SR0			192	/* System Timer 0 Service Request 0 */
#define SRC_ID_STM0SR1			193	/* System Timer 0 Service Request 1 */
#define SRC_ID_STM1SR0			194	/* System Timer 1 Service Request 0 */
#define SRC_ID_STM1SR1			195	/* System Timer 1 Service Request 1 */
#define SRC_ID_STM2SR0			196	/* System Timer 2 Service Request 0 */
#define SRC_ID_STM2SR1			197	/* System Timer 2 Service Request 1 */
#define SRC_ID_STM3SR0			198	/* System Timer 3 Service Request 0 */
#define SRC_ID_STM3SR1			199	/* System Timer 3 Service Request 1 */
#define SRC_ID_STM4SR0			200	/* System Timer 4 Service Request 0 */
#define SRC_ID_STM4SR1			201	/* System Timer 4 Service Request 1 */
#define SRC_ID_STM5SR0			202	/* System Timer 5 Service Request 0 */
#define SRC_ID_STM5SR1			202	/* System Timer 5 Service Request 1 */

#define SRC_ID_FCE0				204	/* FCE0 Error Service Request */

#define SRC_ID_DMAERR0			208	/* DMA Error Service Request 0 */
#define SRC_ID_DMAERR1			209	/* DMA Error Service Request 1 */
#define SRC_ID_DMAERR2			210	/* DMA Error Service Request 2 */
#define SRC_ID_DMAERR3			211	/* DMA Error Service Request 3 */

#define SRC_ID_DMACH0			220	/* DMA Channel   0 Service Request */
#define SRC_ID_DMACH1			221	/* DMA Channel   1 Service Request */
#define SRC_ID_DMACH2			222	/* DMA Channel   2 Service Request */
#define SRC_ID_DMACH3			223	/* DMA Channel   3 Service Request */
#define SRC_ID_DMACH4			224	/* DMA Channel   4 Service Request */
#define SRC_ID_DMACH5			225	/* DMA Channel   5 Service Request */
#define SRC_ID_DMACH6			226	/* DMA Channel   6 Service Request */
#define SRC_ID_DMACH7			227	/* DMA Channel   7 Service Request */
#define SRC_ID_DMACH8			228	/* DMA Channel   8 Service Request */
#define SRC_ID_DMACH9			229	/* DMA Channel   9 Service Request */
#define SRC_ID_DMACH10			230	/* DMA Channel  10 Service Request */
#define SRC_ID_DMACH11			231	/* DMA Channel  11 Service Request */
#define SRC_ID_DMACH12			232	/* DMA Channel  12 Service Request */
#define SRC_ID_DMACH13			233	/* DMA Channel  13 Service Request */
#define SRC_ID_DMACH14			234	/* DMA Channel  14 Service Request */
#define SRC_ID_DMACH15			235	/* DMA Channel  15 Service Request */
#define SRC_ID_DMACH16			236	/* DMA Channel  16 Service Request */
#define SRC_ID_DMACH17			237	/* DMA Channel  17 Service Request */
#define SRC_ID_DMACH18			238	/* DMA Channel  18 Service Request */
#define SRC_ID_DMACH19			239	/* DMA Channel  19 Service Request */
#define SRC_ID_DMACH20			240	/* DMA Channel  20 Service Request */
#define SRC_ID_DMACH21			241	/* DMA Channel  21 Service Request */
#define SRC_ID_DMACH22			242	/* DMA Channel  22 Service Request */
#define SRC_ID_DMACH23			243	/* DMA Channel  23 Service Request */
#define SRC_ID_DMACH24			244	/* DMA Channel  24 Service Request */
#define SRC_ID_DMACH25			245	/* DMA Channel  25 Service Request */
#define SRC_ID_DMACH26			246	/* DMA Channel  26 Service Request */
#define SRC_ID_DMACH27			247	/* DMA Channel  27 Service Request */
#define SRC_ID_DMACH28			248	/* DMA Channel  28 Service Request */
#define SRC_ID_DMACH29			249	/* DMA Channel  29 Service Request */
#define SRC_ID_DMACH30			250	/* DMA Channel  30 Service Request */
#define SRC_ID_DMACH31			251	/* DMA Channel  31 Service Request */
#define SRC_ID_DMACH32			252	/* DMA Channel  32 Service Request */
#define SRC_ID_DMACH33			253	/* DMA Channel  33 Service Request */
#define SRC_ID_DMACH34			254	/* DMA Channel  34 Service Request */
#define SRC_ID_DMACH35			255	/* DMA Channel  35 Service Request */
#define SRC_ID_DMACH36			256	/* DMA Channel  36 Service Request */
#define SRC_ID_DMACH37			257	/* DMA Channel  37 Service Request */
#define SRC_ID_DMACH38			258	/* DMA Channel  38 Service Request */
#define SRC_ID_DMACH39			259	/* DMA Channel  39 Service Request */
#define SRC_ID_DMACH40			260	/* DMA Channel  40 Service Request */
#define SRC_ID_DMACH41			261	/* DMA Channel  41 Service Request */
#define SRC_ID_DMACH42			262	/* DMA Channel  42 Service Request */
#define SRC_ID_DMACH43			263	/* DMA Channel  43 Service Request */
#define SRC_ID_DMACH44			264	/* DMA Channel  44 Service Request */
#define SRC_ID_DMACH45			265	/* DMA Channel  45 Service Request */
#define SRC_ID_DMACH46			266	/* DMA Channel  46 Service Request */
#define SRC_ID_DMACH47			267	/* DMA Channel  47 Service Request */
#define SRC_ID_DMACH48			268	/* DMA Channel  48 Service Request */
#define SRC_ID_DMACH49			269	/* DMA Channel  49 Service Request */
#define SRC_ID_DMACH50			270	/* DMA Channel  50 Service Request */
#define SRC_ID_DMACH51			271	/* DMA Channel  51 Service Request */
#define SRC_ID_DMACH52			272	/* DMA Channel  52 Service Request */
#define SRC_ID_DMACH53			273	/* DMA Channel  53 Service Request */
#define SRC_ID_DMACH54			274	/* DMA Channel  54 Service Request */
#define SRC_ID_DMACH55			275	/* DMA Channel  55 Service Request */
#define SRC_ID_DMACH56			276	/* DMA Channel  56 Service Request */
#define SRC_ID_DMACH57			277	/* DMA Channel  57 Service Request */
#define SRC_ID_DMACH58			278	/* DMA Channel  58 Service Request */
#define SRC_ID_DMACH59			279	/* DMA Channel  59 Service Request */
#define SRC_ID_DMACH60			280	/* DMA Channel  60 Service Request */
#define SRC_ID_DMACH61			281	/* DMA Channel  61 Service Request */
#define SRC_ID_DMACH62			282	/* DMA Channel  62 Service Request */
#define SRC_ID_DMACH63			283	/* DMA Channel  63 Service Request */
#define SRC_ID_DMACH64			284	/* DMA Channel  64 Service Request */
#define SRC_ID_DMACH65			285	/* DMA Channel  65 Service Request */
#define SRC_ID_DMACH66			286	/* DMA Channel  66 Service Request */
#define SRC_ID_DMACH67			287	/* DMA Channel  67 Service Request */
#define SRC_ID_DMACH68			288	/* DMA Channel  68 Service Request */
#define SRC_ID_DMACH69			289	/* DMA Channel  69 Service Request */
#define SRC_ID_DMACH70			290	/* DMA Channel  70 Service Request */
#define SRC_ID_DMACH71			291	/* DMA Channel  71 Service Request */
#define SRC_ID_DMACH72			292	/* DMA Channel  72 Service Request */
#define SRC_ID_DMACH73			293	/* DMA Channel  73 Service Request */
#define SRC_ID_DMACH74			294	/* DMA Channel  74 Service Request */
#define SRC_ID_DMACH75			295	/* DMA Channel  75 Service Request */
#define SRC_ID_DMACH76			296	/* DMA Channel  76 Service Request */
#define SRC_ID_DMACH77			297	/* DMA Channel  77 Service Request */
#define SRC_ID_DMACH78			298	/* DMA Channel  78 Service Request */
#define SRC_ID_DMACH79			299	/* DMA Channel  79 Service Request */
#define SRC_ID_DMACH80			300	/* DMA Channel  80 Service Request */
#define SRC_ID_DMACH81			301	/* DMA Channel  81 Service Request */
#define SRC_ID_DMACH82			302	/* DMA Channel  82 Service Request */
#define SRC_ID_DMACH83			303	/* DMA Channel  83 Service Request */
#define SRC_ID_DMACH84			304	/* DMA Channel  84 Service Request */
#define SRC_ID_DMACH85			305	/* DMA Channel  85 Service Request */
#define SRC_ID_DMACH86			306	/* DMA Channel  86 Service Request */
#define SRC_ID_DMACH87			307	/* DMA Channel  87 Service Request */
#define SRC_ID_DMACH88			308	/* DMA Channel  88 Service Request */
#define SRC_ID_DMACH89			309	/* DMA Channel  89 Service Request */
#define SRC_ID_DMACH90			310	/* DMA Channel  90 Service Request */
#define SRC_ID_DMACH91			311	/* DMA Channel  91 Service Request */
#define SRC_ID_DMACH92			312	/* DMA Channel  92 Service Request */
#define SRC_ID_DMACH93			313	/* DMA Channel  93 Service Request */
#define SRC_ID_DMACH94			314	/* DMA Channel  94 Service Request */
#define SRC_ID_DMACH95			315	/* DMA Channel  95 Service Request */
#define SRC_ID_DMACH96			316	/* DMA Channel  96 Service Request */
#define SRC_ID_DMACH97			317	/* DMA Channel  97 Service Request */
#define SRC_ID_DMACH98			318	/* DMA Channel  98 Service Request */
#define SRC_ID_DMACH99			319	/* DMA Channel  99 Service Request */
#define SRC_ID_DMACH100			320	/* DMA Channel 100 Service Request */
#define SRC_ID_DMACH101			321	/* DMA Channel 101 Service Request */
#define SRC_ID_DMACH102			322	/* DMA Channel 102 Service Request */
#define SRC_ID_DMACH103			323	/* DMA Channel 103 Service Request */
#define SRC_ID_DMACH104			324	/* DMA Channel 104 Service Request */
#define SRC_ID_DMACH105			325	/* DMA Channel 105 Service Request */
#define SRC_ID_DMACH106			326	/* DMA Channel 106 Service Request */
#define SRC_ID_DMACH107			327	/* DMA Channel 107 Service Request */
#define SRC_ID_DMACH108			328	/* DMA Channel 108 Service Request */
#define SRC_ID_DMACH109			329	/* DMA Channel 109 Service Request */
#define SRC_ID_DMACH110			330	/* DMA Channel 110 Service Request */
#define SRC_ID_DMACH111			331	/* DMA Channel 111 Service Request */
#define SRC_ID_DMACH112			332	/* DMA Channel 112 Service Request */
#define SRC_ID_DMACH113			333	/* DMA Channel 113 Service Request */
#define SRC_ID_DMACH114			334	/* DMA Channel 114 Service Request */
#define SRC_ID_DMACH115			335	/* DMA Channel 115 Service Request */
#define SRC_ID_DMACH116			336	/* DMA Channel 116 Service Request */
#define SRC_ID_DMACH117			337	/* DMA Channel 117 Service Request */
#define SRC_ID_DMACH118			338	/* DMA Channel 118 Service Request */
#define SRC_ID_DMACH119			339	/* DMA Channel 119 Service Request */
#define SRC_ID_DMACH120			340	/* DMA Channel 120 Service Request */
#define SRC_ID_DMACH121			341	/* DMA Channel 121 Service Request */
#define SRC_ID_DMACH122			342	/* DMA Channel 122 Service Request */
#define SRC_ID_DMACH123			343	/* DMA Channel 123 Service Request */
#define SRC_ID_DMACH124			344	/* DMA Channel 124 Service Request */
#define SRC_ID_DMACH125			345	/* DMA Channel 125 Service Request */
#define SRC_ID_DMACH126			346	/* DMA Channel 126 Service Request */
#define SRC_ID_DMACH127			347	/* DMA Channel 127 Service Request */

#define SRC_ID_SDMMCERR			348	/* SDMMC Error Service Request */
#define SRC_ID_SDMMCDMA			349	/* SDMMC DMA Ready Service Request */

#define SRC_ID_GETH0			352	/* GETH Service Request 0 */
#define SRC_ID_GETH1			353	/* GETH Service Request 1 */
#define SRC_ID_GETH2			354	/* GETH Service Request 2 */
#define SRC_ID_GETH3			355	/* GETH Service Request 3 */
#define SRC_ID_GETH4			356	/* GETH Service Request 4 */
#define SRC_ID_GETH5			357	/* GETH Service Request 5 */
#define SRC_ID_GETH6			358	/* GETH Service Request 6 */
#define SRC_ID_GETH7			359	/* GETH Service Request 7 */
#define SRC_ID_GETH8			360	/* GETH Service Request 8 */
#define SRC_ID_GETH9			361	/* GETH Service Request 9 */

#define SRC_ID_CAN0INT0			364	/* CAN0 Service Request 0 */
#define SRC_ID_CAN0INT1			365	/* CAN0 Service Request 1 */
#define SRC_ID_CAN0INT2			366	/* CAN0 Service Request 2 */
#define SRC_ID_CAN0INT3			367	/* CAN0 Service Request 3 */
#define SRC_ID_CAN0INT4			368	/* CAN0 Service Request 4 */
#define SRC_ID_CAN0INT5			369	/* CAN0 Service Request 5 */
#define SRC_ID_CAN0INT6			370	/* CAN0 Service Request 6 */
#define SRC_ID_CAN0INT7			371	/* CAN0 Service Request 7 */
#define SRC_ID_CAN0INT8			372	/* CAN0 Service Request 8 */
#define SRC_ID_CAN0INT9			373	/* CAN0 Service Request 9 */
#define SRC_ID_CAN0INT10		374	/* CAN0 Service Request 10 */
#define SRC_ID_CAN0INT11		375	/* CAN0 Service Request 11 */
#define SRC_ID_CAN0INT12		376	/* CAN0 Service Request 12 */
#define SRC_ID_CAN0INT13		377	/* CAN0 Service Request 13 */
#define SRC_ID_CAN0INT14		378	/* CAN0 Service Request 14 */
#define SRC_ID_CAN0INT15		379	/* CAN0 Service Request 15 */
#define SRC_ID_CAN1INT0			380	/* CAN1 Service Request 0 */
#define SRC_ID_CAN1INT1			381	/* CAN1 Service Request 1 */
#define SRC_ID_CAN1INT2			382	/* CAN1 Service Request 2 */
#define SRC_ID_CAN1INT3			383	/* CAN1 Service Request 3 */
#define SRC_ID_CAN1INT4			384	/* CAN1 Service Request 4 */
#define SRC_ID_CAN1INT5			385	/* CAN1 Service Request 5 */
#define SRC_ID_CAN1INT6			386	/* CAN1 Service Request 6 */
#define SRC_ID_CAN1INT7			387	/* CAN1 Service Request 7 */
#define SRC_ID_CAN1INT8			388	/* CAN1 Service Request 8 */
#define SRC_ID_CAN1INT9			389	/* CAN1 Service Request 9 */
#define SRC_ID_CAN1INT10		390	/* CAN1 Service Request 10 */
#define SRC_ID_CAN1INT11		391	/* CAN1 Service Request 11 */
#define SRC_ID_CAN1INT12		392	/* CAN1 Service Request 12 */
#define SRC_ID_CAN1INT13		393	/* CAN1 Service Request 13 */
#define SRC_ID_CAN1INT14		394	/* CAN1 Service Request 14 */
#define SRC_ID_CAN1INT15		395	/* CAN1 Service Request 15 */
#define SRC_ID_CAN2INT0			396	/* CAN2 Service Request 0 */
#define SRC_ID_CAN2INT1			397	/* CAN2 Service Request 1 */
#define SRC_ID_CAN2INT2			398	/* CAN2 Service Request 2 */
#define SRC_ID_CAN2INT3			399	/* CAN2 Service Request 3 */
#define SRC_ID_CAN2INT4			401	/* CAN2 Service Request 4 */
#define SRC_ID_CAN2INT5			401	/* CAN2 Service Request 5 */
#define SRC_ID_CAN2INT6			402	/* CAN2 Service Request 6 */
#define SRC_ID_CAN2INT7			403	/* CAN2 Service Request 7 */
#define SRC_ID_CAN2INT8			404	/* CAN2 Service Request 8 */
#define SRC_ID_CAN2INT9			405	/* CAN2 Service Request 9 */
#define SRC_ID_CAN2INT10		406	/* CAN2 Service Request 10 */
#define SRC_ID_CAN2INT11		407	/* CAN2 Service Request 11 */
#define SRC_ID_CAN2INT12		408	/* CAN2 Service Request 12 */
#define SRC_ID_CAN2INT13		409	/* CAN2 Service Request 13 */
#define SRC_ID_CAN2INT14		410	/* CAN2 Service Request 14 */
#define SRC_ID_CAN2INT15		411	/* CAN2 Service Request 15 */

#define SRC_ID_VADCG0SR0		412	/* EVADC Group  0 Service Request 0 */
#define SRC_ID_VADCG0SR1		413	/* EVADC Group  0 Service Request 1 */
#define SRC_ID_VADCG0SR2		414	/* EVADC Group  0 Service Request 2 */
#define SRC_ID_VADCG0SR3		415	/* EVADC Group  0 Service Request 3 */
#define SRC_ID_VADCG1SR0		416	/* EVADC Group  1 Service Request 0 */
#define SRC_ID_VADCG1SR1		417	/* EVADC Group  1 Service Request 1 */
#define SRC_ID_VADCG1SR2		418	/* EVADC Group  1 Service Request 2 */
#define SRC_ID_VADCG1SR3		419	/* EVADC Group  1 Service Request 3 */
#define SRC_ID_VADCG2SR0		420	/* EVADC Group  2 Service Request 0 */
#define SRC_ID_VADCG2SR1		421	/* EVADC Group  2 Service Request 1 */
#define SRC_ID_VADCG2SR2		422	/* EVADC Group  2 Service Request 2 */
#define SRC_ID_VADCG2SR3		423	/* EVADC Group  2 Service Request 3 */
#define SRC_ID_VADCG3SR0		424	/* EVADC Group  3 Service Request 0 */
#define SRC_ID_VADCG3SR1		425	/* EVADC Group  3 Service Request 1 */
#define SRC_ID_VADCG3SR2		426	/* EVADC Group  3 Service Request 2 */
#define SRC_ID_VADCG3SR3		427	/* EVADC Group  3 Service Request 3 */
#define SRC_ID_VADCG4SR0		428	/* EVADC Group  4 Service Request 0 */
#define SRC_ID_VADCG4SR1		429	/* EVADC Group  4 Service Request 1 */
#define SRC_ID_VADCG4SR2		430	/* EVADC Group  4 Service Request 2 */
#define SRC_ID_VADCG4SR3		431	/* EVADC Group  4 Service Request 3 */
#define SRC_ID_VADCG5SR0		432	/* EVADC Group  5 Service Request 0 */
#define SRC_ID_VADCG5SR1		433	/* EVADC Group  5 Service Request 1 */
#define SRC_ID_VADCG5SR2		434	/* EVADC Group  5 Service Request 2 */
#define SRC_ID_VADCG5SR3		435	/* EVADC Group  5 Service Request 3 */
#define SRC_ID_VADCG6SR0		436	/* EVADC Group  6 Service Request 0 */
#define SRC_ID_VADCG6SR1		437	/* EVADC Group  6 Service Request 1 */
#define SRC_ID_VADCG6SR2		438	/* EVADC Group  6 Service Request 2 */
#define SRC_ID_VADCG6SR3		439	/* EVADC Group  6 Service Request 3 */
#define SRC_ID_VADCG7SR0		440	/* EVADC Group  7 Service Request 0 */
#define SRC_ID_VADCG7SR1		441	/* EVADC Group  7 Service Request 1 */
#define SRC_ID_VADCG7SR2		442	/* EVADC Group  7 Service Request 2 */
#define SRC_ID_VADCG7SR3		443	/* EVADC Group  7 Service Request 3 */
#define SRC_ID_VADCG8SR0		444	/* EVADC Group  8 Service Request 0 */
#define SRC_ID_VADCG8SR1		445	/* EVADC Group  8 Service Request 1 */
#define SRC_ID_VADCG8SR2		446	/* EVADC Group  8 Service Request 2 */
#define SRC_ID_VADCG8SR3		447	/* EVADC Group  8 Service Request 3 */
#define SRC_ID_VADCG9SR0		448	/* EVADC Group  9 Service Request 0 */
#define SRC_ID_VADCG9SR1		449	/* EVADC Group  9 Service Request 1 */
#define SRC_ID_VADCG9SR2		450	/* EVADC Group  9 Service Request 2 */
#define SRC_ID_VADCG9SR3		451	/* EVADC Group  9 Service Request 3 */
#define SRC_ID_VADCG10SR0		452	/* EVADC Group 10 Service Request 0 */
#define SRC_ID_VADCG10SR1		453	/* EVADC Group 10 Service Request 1 */
#define SRC_ID_VADCG10SR2		454	/* EVADC Group 10 Service Request 2 */
#define SRC_ID_VADCG10SR3		455	/* EVADC Group 10 Service Request 3 */
#define SRC_ID_VADCG11SR0		456	/* EVADC Group 11 Service Request 0 */
#define SRC_ID_VADCG11SR1		457	/* EVADC Group 11 Service Request 1 */
#define SRC_ID_VADCG11SR2		458	/* EVADC Group 11 Service Request 2 */
#define SRC_ID_VADCG11SR3		459	/* EVADC Group 11 Service Request 3 */
#define SRC_ID_VADCFC0SR0		460	/* EVADC Fast Compare 0 Service Request 0 */
#define SRC_ID_VADCFC1SR0		461	/* EVADC Fast Compare 1 Service Request 0 */
#define SRC_ID_VADCFC2SR0		462	/* EVADC Fast Compare 2 Service Request 0 */
#define SRC_ID_VADCFC3SR0		463	/* EVADC Fast Compare 3 Service Request 0 */
#define SRC_ID_VADCFC4SR0		464	/* EVADC Fast Compare 4 Service Request 0 */
#define SRC_ID_VADCFC5SR0		465	/* EVADC Fast Compare 5 Service Request 0 */
#define SRC_ID_VADCFC6SR0		466	/* EVADC Fast Compare 6 Service Request 0 */
#define SRC_ID_VADCFC7SR0		467	/* EVADC Fast Compare 7 Service Request 0 */

#define SRC_ID_VADCCG0SR0		468	/* EVADC Common Group 0 Service Request 0 */
#define SRC_ID_VADCCG0SR1		469	/* EVADC Common Group 0 Service Request 1 */
#define SRC_ID_VADCCG0SR2		470	/* EVADC Common Group 0 Service Request 2 */
#define SRC_ID_VADCCG0SR3		471	/* EVADC Common Group 0 Service Request 3 */
#define SRC_ID_VADCCG1SR0		472	/* EVADC Common Group 1 Service Request 0 */
#define SRC_ID_VADCCG1SR1		473	/* EVADC Common Group 1 Service Request 1 */
#define SRC_ID_VADCCG1SR2		474	/* EVADC Common Group 1 Service Request 2 */
#define SRC_ID_VADCCG1SR3		475	/* EVADC Common Group 1 Service Request 3 */

#define SRC_ID_DSADCSRM0		476	/* DSADC SRM0 Service Request */
#define SRC_ID_DSADCSRA0		477	/* DSADC SRA0 Service Request */
#define SRC_ID_DSADCSRM1		478	/* DSADC SRM1 Service Request */
#define SRC_ID_DSADCSRA1		479	/* DSADC SRA1 Service Request */
#define SRC_ID_DSADCSRM2		480	/* DSADC SRM2 Service Request */
#define SRC_ID_DSADCSRA2		481	/* DSADC SRA2 Service Request */
#define SRC_ID_DSADCSRM3		482	/* DSADC SRM3 Service Request */
#define SRC_ID_DSADCSRA3		483	/* DSADC SRA3 Service Request */
#define SRC_ID_DSADCSRM4		484	/* DSADC SRM4 Service Request */
#define SRC_ID_DSADCSRA4		485	/* DSADC SRA4 Service Request */
#define SRC_ID_DSADCSRM5		486	/* DSADC SRM5 Service Request */
#define SRC_ID_DSADCSRA5		487	/* DSADC SRA5 Service Request */
#define SRC_ID_DSADCSRM6		488	/* DSADC SRM6 Service Request */
#define SRC_ID_DSADCSRA6		489	/* DSADC SRA6 Service Request */
#define SRC_ID_DSADCSRM7		490	/* DSADC SRM7 Service Request */
#define SRC_ID_DSADCSRA7		491	/* DSADC SRA7 Service Request */
#define SRC_ID_DSADCSRM8		492	/* DSADC SRM8 Service Request */
#define SRC_ID_DSADCSRA8		493	/* DSADC SRA8 Service Request */
#define SRC_ID_DSADCSRM9		494	/* DSADC SRM9 Service Request */
#define SRC_ID_DSADCSRA9		495	/* DSADC SRA9 Service Request */
#define SRC_ID_DSADCSRM10		496	/* DSADC SRM10 Service Request */
#define SRC_ID_DSADCSRA10		497	/* DSADC SRA10 Service Request */
#define SRC_ID_DSADCSRM11		498	/* DSADC SRM11 Service Request */
#define SRC_ID_DSADCSRA11		499	/* DSADC SRA11 Service Request */
#define SRC_ID_DSADCSRM12		500	/* DSADC SRM12 Service Request */
#define SRC_ID_DSADCSRA12		501	/* DSADC SRA12 Service Request */
#define SRC_ID_DSADCSRM13		502	/* DSADC SRM13 Service Request */
#define SRC_ID_DSADCSRA13		503	/* DSADC SRA13 Service Request */

#define SRC_ID_ERAY0INT0		512	/* E-RAY 0 Service Request 0 */
#define SRC_ID_ERAY0INT1		513	/* E-RAY 0 Service Request 1 */
#define SRC_ID_ERAY0TINT0		514	/* E-RAY 0 Timer Interrupt 0 Service Request */
#define SRC_ID_ERAY0TINT1		515	/* E-RAY 0 Timer Interrupt 1 Service Request */
#define SRC_ID_ERAY0NDAT0		516	/* E-RAY 0 New Data 0 Service Request */
#define SRC_ID_ERAY0NDAT1		517	/* E-RAY 0 New Data 1 Service Request */
#define SRC_ID_ERAY0MBSC0		518	/* E-RAY 0 Message Buffer Status Changed 0 Service Request */
#define SRC_ID_ERAY0MBSC1		519	/* E-RAY 0 Message Buffer Status Changed 1 Service Request */
#define SRC_ID_ERAY0OBUSY		520	/* E-RAY 0 Output Buffer Busy Service Request */
#define SRC_ID_ERAY0IBUSY		521	/* E-RAY 0 Input Buffer Busy Service Request */
#define SRC_ID_ERAY1INT0		524	/* E-RAY 1 Service Request 0 */
#define SRC_ID_ERAY1INT1		525	/* E-RAY 1 Service Request 1 */
#define SRC_ID_ERAY1TINT0		526	/* E-RAY 1 Timer Interrupt 0 Service Request */
#define SRC_ID_ERAY1TINT1		527	/* E-RAY 1 Timer Interrupt 1 Service Request */
#define SRC_ID_ERAY1NDAT0		528	/* E-RAY 1 New Data 0 Service Request */
#define SRC_ID_ERAY1NDAT1		529	/* E-RAY 1 New Data 1 Service Request */
#define SRC_ID_ERAY1MBSC0		530	/* E-RAY 1 Message Buffer Status Changed 0 Service Request */
#define SRC_ID_ERAY1MBSC1		531	/* E-RAY 1 Message Buffer Status Changed 1 Service Request */
#define SRC_ID_ERAY1OBUSY		532	/* E-RAY 1 Output Buffer Busy Service Request */
#define SRC_ID_ERAY1IBUSY		533	/* E-RAY 1 Input Buffer Busy Service Request */

#define SRC_ID_DMUHOST			536	/* DMU Host Service Request */
#define SRC_ID_DMUFSI			537	/* DMU FSI Service Request */

#define SRC_ID_HSM0				540	/* HSM Service Request 0 */
#define SRC_ID_HSM1				541	/* HSM Service Request 1 */

#define SRC_ID_SCUERU0			544	/* SCU ERU Service Request 0 */
#define SRC_ID_SCUERU1			545	/* SCU ERU Service Request 1 */
#define SRC_ID_SCUERU2			546	/* SCU ERU Service Request 2 */
#define SRC_ID_SCUERU3			547	/* SCU ERU Service Request 3 */

#define SRC_ID_PMSDTS			555	/* PMS DTS Service Request */
#define SRC_ID_PMS0				556	/* PMS Service Request 0 */
#define SRC_ID_PMS1				557	/* PMS Service Request 1 */
#define SRC_ID_PMS2				558	/* PMS Service Request 2 */
#define SRC_ID_PMS3				559	/* PMS Service Request 3 */
#define SRC_ID_SCR				560	/* Standby Controller (SCR) Service Request */

#define SRC_ID_SMU0				564	/* SMU Service Request 0 */
#define SRC_ID_SMU1				565	/* SMU Service Request 1 */
#define SRC_ID_SMU2				566	/* SMU Service Request 2 */

#define SRC_ID_PSI50			568	/* PSI5 Service Request 0 */
#define SRC_ID_PSI51			569	/* PSI5 Service Request 1 */
#define SRC_ID_PSI52			570	/* PSI5 Service Request 2 */
#define SRC_ID_PSI53			571	/* PSI5 Service Request 3 */
#define SRC_ID_PSI54			572	/* PSI5 Service Request 4 */
#define SRC_ID_PSI55			573	/* PSI5 Service Request 5 */
#define SRC_ID_PSI56			574	/* PSI5 Service Request 6 */
#define SRC_ID_PSI57			575	/* PSI5 Service Request 7 */

#define SRC_ID_HSPDM0BFR		576	/* HSPDM0 Buffer Service Request */
#define SRC_ID_HSPDM0RAMP		577	/* HSPDM0 RAMP Events Service Request */
#define SRC_ID_HSPDM0ERR		578	/* HSPDM0 Error / RAM Overflow Service Request */

#define SRC_ID_DAM0LI0			580	/* DAM0 Limit 0 Service Request */
#define SRC_ID_DAM0RI0			581	/* DAM0 Ready 0 Service Request */
#define SRC_ID_DAM0LI1			582	/* DAM0 Limit 1 Service Request */
#define SRC_ID_DAM0RI1			583	/* DAM0 Ready 1 Service Request */
#define SRC_ID_DAM0DR			584	/* DAM0 DMA Ready Service Request */
#define SRC_ID_DAM0ERR			585	/* DAM0 Error Service Request */
#define SRC_ID_DAM1LI0			586	/* DAM1 Limit 0 Service Request */
#define SRC_ID_DAM1RI0			587	/* DAM1 Ready 0 Service Request */
#define SRC_ID_DAM1LI1			588	/* DAM1 Limit 1 Service Request */
#define SRC_ID_DAM1RI1			589	/* DAM1 Ready 1 Service Request */
#define SRC_ID_DAM1DR			590	/* DAM1 DMA Ready Service Request */
#define SRC_ID_DAM1ERR			591	/* DAM1 Error Service Request */

#define SRC_ID_PSI5S0			596	/* PSI5-S Service Request 0 */
#define SRC_ID_PSI5S1			597	/* PSI5-S Service Request 1 */
#define SRC_ID_PSI5S2			598	/* PSI5-S Service Request 2 */
#define SRC_ID_PSI5S3			599	/* PSI5-S Service Request 3 */
#define SRC_ID_PSI5S4			600	/* PSI5-S Service Request 4 */
#define SRC_ID_PSI5S5			601	/* PSI5-S Service Request 5 */
#define SRC_ID_PSI5S6			602	/* PSI5-S Service Request 6 */
#define SRC_ID_PSI5S7			603	/* PSI5-S Service Request 7 */

#define SRC_ID_RIF0ERR			604	/* RIF 0 Error Service Request */
#define SRC_ID_RIF0INT			605	/* RIF 0 Service Request */
#define SRC_ID_RIF1ERR			606	/* RIF 1 Error Service Request */
#define SRC_ID_RIF1INT			607	/* RIF 1 Service Request */

#define SRC_ID_SPU0ERR			608	/* SPU 0 Error Service Request */
#define SRC_ID_SPU0INT			609	/* SPU 0 Service Request */
#define SRC_ID_SPU1ERR			610	/* SPU 1 Error Service Request */
#define SRC_ID_SPU1INT			611	/* SPU 1 Service Request */

#define SRC_ID_GPSR00			612	/* General Purpose Service Request 0 0 */
#define SRC_ID_GPSR01			613	/* General Purpose Service Request 0 1 */
#define SRC_ID_GPSR02			614	/* General Purpose Service Request 0 2 */
#define SRC_ID_GPSR03			615	/* General Purpose Service Request 0 3 */
#define SRC_ID_GPSR04			616	/* General Purpose Service Request 0 4 */
#define SRC_ID_GPSR05			617	/* General Purpose Service Request 0 5 */
#define SRC_ID_GPSR06			618	/* General Purpose Service Request 0 6 */
#define SRC_ID_GPSR07			619	/* General Purpose Service Request 0 7 */

#define SRC_ID_GPSR10			620	/* General Purpose Service Request 1 0 */
#define SRC_ID_GPSR11			621	/* General Purpose Service Request 1 1 */
#define SRC_ID_GPSR12			622	/* General Purpose Service Request 1 2 */
#define SRC_ID_GPSR13			623	/* General Purpose Service Request 1 3 */
#define SRC_ID_GPSR14			624	/* General Purpose Service Request 1 4 */
#define SRC_ID_GPSR15			625	/* General Purpose Service Request 1 5 */
#define SRC_ID_GPSR16			626	/* General Purpose Service Request 1 6 */
#define SRC_ID_GPSR17			627	/* General Purpose Service Request 1 7 */

#define SRC_ID_GPSR20			628	/* General Purpose Service Request 2 0 */
#define SRC_ID_GPSR21			629	/* General Purpose Service Request 2 1 */
#define SRC_ID_GPSR22			630	/* General Purpose Service Request 2 2 */
#define SRC_ID_GPSR23			631	/* General Purpose Service Request 2 3 */
#define SRC_ID_GPSR24			632	/* General Purpose Service Request 2 4 */
#define SRC_ID_GPSR25			633	/* General Purpose Service Request 2 5 */
#define SRC_ID_GPSR26			634	/* General Purpose Service Request 2 6 */
#define SRC_ID_GPSR27			635	/* General Purpose Service Request 2 7 */

#define SRC_ID_GPSR30			636	/* General Purpose Service Request 3 0 */
#define SRC_ID_GPSR31			637	/* General Purpose Service Request 3 1 */
#define SRC_ID_GPSR32			638	/* General Purpose Service Request 3 2 */
#define SRC_ID_GPSR33			639	/* General Purpose Service Request 3 3 */
#define SRC_ID_GPSR34			640	/* General Purpose Service Request 3 4 */
#define SRC_ID_GPSR35			641	/* General Purpose Service Request 3 5 */
#define SRC_ID_GPSR36			642	/* General Purpose Service Request 3 6 */
#define SRC_ID_GPSR37			643	/* General Purpose Service Request 3 7 */

#define SRC_ID_GPSR40			644	/* General Purpose Service Request 4 0 */
#define SRC_ID_GPSR41			645	/* General Purpose Service Request 4 1 */
#define SRC_ID_GPSR42			646	/* General Purpose Service Request 4 2 */
#define SRC_ID_GPSR43			647	/* General Purpose Service Request 4 3 */
#define SRC_ID_GPSR44			648	/* General Purpose Service Request 4 4 */
#define SRC_ID_GPSR45			649	/* General Purpose Service Request 4 5 */
#define SRC_ID_GPSR46			650	/* General Purpose Service Request 4 6 */
#define SRC_ID_GPSR47			651	/* General Purpose Service Request 4 7 */

#define SRC_ID_GPSR50			652	/* General Purpose Service Request 5 0 */
#define SRC_ID_GPSR51			653	/* General Purpose Service Request 5 1 */
#define SRC_ID_GPSR52			654	/* General Purpose Service Request 5 2 */
#define SRC_ID_GPSR53			655	/* General Purpose Service Request 5 3 */
#define SRC_ID_GPSR54			656	/* General Purpose Service Request 5 4 */
#define SRC_ID_GPSR55			657	/* General Purpose Service Request 5 5 */
#define SRC_ID_GPSR56			658	/* General Purpose Service Request 5 6 */
#define SRC_ID_GPSR57			659	/* General Purpose Service Request 5 7 */

#define SRC_ID_GTMAEIIRQ		668	/* GTM AEI Shared Service Request */
#define SRC_ID_GTMARUIRQ0		669	/* GTM ARU Shared Service Request 0 */
#define SRC_ID_GTMARUIRQ1		670	/* GTM ARU Shared Service Request 1 */
#define SRC_ID_GTMARUIRQ2		671	/* GTM ARU Shared Service Request 2 */

#define SRC_ID_GTMBRCIRQ		672	/* GTM BRC Shared Service Request */
#define SRC_ID_GTMCMPIRQ		673	/* GTM CMP Shared Service Request */
#define SRC_ID_GTMSPE0IRQ		674	/* GTM SPE0 Shared Service Request */
#define SRC_ID_GTMSPE1IRQ		675	/* GTM SPE1 Shared Service Request */
#define SRC_ID_GTMSPE2IRQ		676	/* GTM SPE2 Shared Service Request */
#define SRC_ID_GTMSPE3IRQ		677	/* GTM SPE3 Shared Service Request */
#define SRC_ID_GTMSPE4IRQ		678	/* GTM SPE4 Shared Service Request */
#define SRC_ID_GTMSPE5IRQ		679	/* GTM SPE5 Shared Service Request */

#define SRC_ID_GTMPSM00			680	/* GTM PSM0 Shared Service Request 0 */
#define SRC_ID_GTMPSM01			681	/* GTM PSM0 Shared Service Request 1 */
#define SRC_ID_GTMPSM02			682	/* GTM PSM0 Shared Service Request 2 */
#define SRC_ID_GTMPSM03			683	/* GTM PSM0 Shared Service Request 3 */
#define SRC_ID_GTMPSM04			684	/* GTM PSM0 Shared Service Request 4 */
#define SRC_ID_GTMPSM05			685	/* GTM PSM0 Shared Service Request 5 */
#define SRC_ID_GTMPSM06			686	/* GTM PSM0 Shared Service Request 6 */
#define SRC_ID_GTMPSM07			687	/* GTM PSM0 Shared Service Request 7 */

#define SRC_ID_GTMPSM10			688	/* GTM PSM1 Shared Service Request 0 */
#define SRC_ID_GTMPSM11			689	/* GTM PSM1 Shared Service Request 1 */
#define SRC_ID_GTMPSM12			690	/* GTM PSM1 Shared Service Request 2 */
#define SRC_ID_GTMPSM13			691	/* GTM PSM1 Shared Service Request 3 */
#define SRC_ID_GTMPSM14			692	/* GTM PSM1 Shared Service Request 4 */
#define SRC_ID_GTMPSM15			693	/* GTM PSM1 Shared Service Request 5 */
#define SRC_ID_GTMPSM16			694	/* GTM PSM1 Shared Service Request 6 */
#define SRC_ID_GTMPSM17			695	/* GTM PSM1 Shared Service Request 7 */

#define SRC_ID_GTMPSM20			696	/* GTM PSM2 Shared Service Request 0 */
#define SRC_ID_GTMPSM21			697	/* GTM PSM2 Shared Service Request 1 */
#define SRC_ID_GTMPSM22			698	/* GTM PSM2 Shared Service Request 2 */
#define SRC_ID_GTMPSM23			699	/* GTM PSM2 Shared Service Request 3 */
#define SRC_ID_GTMPSM24			700	/* GTM PSM2 Shared Service Request 4 */
#define SRC_ID_GTMPSM25			701	/* GTM PSM2 Shared Service Request 5 */
#define SRC_ID_GTMPSM26			702	/* GTM PSM2 Shared Service Request 6 */
#define SRC_ID_GTMPSM27			703	/* GTM PSM2 Shared Service Request 7 */

#define SRC_ID_GTMDPLL0			704	/* GTM DPLL Service Request 0 */
#define SRC_ID_GTMDPLL1			705	/* GTM DPLL Service Request 1 */
#define SRC_ID_GTMDPLL2			706	/* GTM DPLL Service Request 2 */
#define SRC_ID_GTMDPLL3			707	/* GTM DPLL Service Request 3 */
#define SRC_ID_GTMDPLL4			708	/* GTM DPLL Service Request 4 */
#define SRC_ID_GTMDPLL5			709	/* GTM DPLL Service Request 5 */
#define SRC_ID_GTMDPLL6			710	/* GTM DPLL Service Request 6 */
#define SRC_ID_GTMDPLL7			711	/* GTM DPLL Service Request 7 */
#define SRC_ID_GTMDPLL8			712	/* GTM DPLL Service Request 8 */
#define SRC_ID_GTMDPLL9			713	/* GTM DPLL Service Request 9 */
#define SRC_ID_GTMDPLL10		714	/* GTM DPLL Service Request 10 */
#define SRC_ID_GTMDPLL11		715	/* GTM DPLL Service Request 11 */
#define SRC_ID_GTMDPLL12		716	/* GTM DPLL Service Request 12 */
#define SRC_ID_GTMDPLL13		717	/* GTM DPLL Service Request 13 */
#define SRC_ID_GTMDPLL14		718	/* GTM DPLL Service Request 14 */
#define SRC_ID_GTMDPLL15		719	/* GTM DPLL Service Request 15 */
#define SRC_ID_GTMDPLL16		720	/* GTM DPLL Service Request 16 */
#define SRC_ID_GTMDPLL17		721	/* GTM DPLL Service Request 17 */
#define SRC_ID_GTMDPLL18		722	/* GTM DPLL Service Request 18 */
#define SRC_ID_GTMDPLL19		723	/* GTM DPLL Service Request 19 */
#define SRC_ID_GTMDPLL20		724	/* GTM DPLL Service Request 20 */
#define SRC_ID_GTMDPLL21		725	/* GTM DPLL Service Request 21 */
#define SRC_ID_GTMDPLL22		726	/* GTM DPLL Service Request 22 */
#define SRC_ID_GTMDPLL23		727	/* GTM DPLL Service Request 23 */
#define SRC_ID_GTMDPLL24		728	/* GTM DPLL Service Request 24 */
#define SRC_ID_GTMDPLL25		729	/* GTM DPLL Service Request 25 */
#define SRC_ID_GTMDPLL26		730	/* GTM DPLL Service Request 26 */

#define SRC_ID_GTMERR			732	/* GTM Error Service Request */

#define SRC_ID_GTMTIM00			740	/* GTM TIM0 Shared Service Request 0 */
#define SRC_ID_GTMTIM01			741	/* GTM TIM0 Shared Service Request 1 */
#define SRC_ID_GTMTIM02			742	/* GTM TIM0 Shared Service Request 2 */
#define SRC_ID_GTMTIM03			743	/* GTM TIM0 Shared Service Request 3 */
#define SRC_ID_GTMTIM04			744	/* GTM TIM0 Shared Service Request 4 */
#define SRC_ID_GTMTIM05			745	/* GTM TIM0 Shared Service Request 5 */
#define SRC_ID_GTMTIM06			746	/* GTM TIM0 Shared Service Request 6 */
#define SRC_ID_GTMTIM07			747	/* GTM TIM0 Shared Service Request 7 */
#define SRC_ID_GTMTIM10			748	/* GTM TIM1 Shared Service Request 0 */
#define SRC_ID_GTMTIM11			749	/* GTM TIM1 Shared Service Request 1 */
#define SRC_ID_GTMTIM12			750	/* GTM TIM1 Shared Service Request 2 */
#define SRC_ID_GTMTIM13			751	/* GTM TIM1 Shared Service Request 3 */
#define SRC_ID_GTMTIM14			752	/* GTM TIM1 Shared Service Request 4 */
#define SRC_ID_GTMTIM15			753	/* GTM TIM1 Shared Service Request 5 */
#define SRC_ID_GTMTIM16			754	/* GTM TIM1 Shared Service Request 6 */
#define SRC_ID_GTMTIM17			755	/* GTM TIM1 Shared Service Request 7 */
#define SRC_ID_GTMTIM20			756	/* GTM TIM2 Shared Service Request 0 */
#define SRC_ID_GTMTIM21			757	/* GTM TIM2 Shared Service Request 1 */
#define SRC_ID_GTMTIM22			758	/* GTM TIM2 Shared Service Request 2 */
#define SRC_ID_GTMTIM23			759	/* GTM TIM2 Shared Service Request 3 */
#define SRC_ID_GTMTIM24			760	/* GTM TIM2 Shared Service Request 4 */
#define SRC_ID_GTMTIM25			761	/* GTM TIM2 Shared Service Request 5 */
#define SRC_ID_GTMTIM26			762	/* GTM TIM2 Shared Service Request 6 */
#define SRC_ID_GTMTIM27			763	/* GTM TIM2 Shared Service Request 7 */
#define SRC_ID_GTMTIM30			764	/* GTM TIM3 Shared Service Request 0 */
#define SRC_ID_GTMTIM31			765	/* GTM TIM3 Shared Service Request 1 */
#define SRC_ID_GTMTIM32			766	/* GTM TIM3 Shared Service Request 2 */
#define SRC_ID_GTMTIM33			767	/* GTM TIM3 Shared Service Request 3 */
#define SRC_ID_GTMTIM34			768	/* GTM TIM3 Shared Service Request 4 */
#define SRC_ID_GTMTIM35			769	/* GTM TIM3 Shared Service Request 5 */
#define SRC_ID_GTMTIM36			770	/* GTM TIM3 Shared Service Request 6 */
#define SRC_ID_GTMTIM37			771	/* GTM TIM3 Shared Service Request 7 */
#define SRC_ID_GTMTIM40			772	/* GTM TIM4 Shared Service Request 0 */
#define SRC_ID_GTMTIM41			773	/* GTM TIM4 Shared Service Request 1 */
#define SRC_ID_GTMTIM42			774	/* GTM TIM4 Shared Service Request 2 */
#define SRC_ID_GTMTIM43			775	/* GTM TIM4 Shared Service Request 3 */
#define SRC_ID_GTMTIM44			776	/* GTM TIM4 Shared Service Request 4 */
#define SRC_ID_GTMTIM45			777	/* GTM TIM4 Shared Service Request 5 */
#define SRC_ID_GTMTIM46			778	/* GTM TIM4 Shared Service Request 6 */
#define SRC_ID_GTMTIM47			779	/* GTM TIM4 Shared Service Request 7 */
#define SRC_ID_GTMTIM50			780	/* GTM TIM5 Shared Service Request 0 */
#define SRC_ID_GTMTIM51			781	/* GTM TIM5 Shared Service Request 1 */
#define SRC_ID_GTMTIM52			782	/* GTM TIM5 Shared Service Request 2 */
#define SRC_ID_GTMTIM53			783	/* GTM TIM5 Shared Service Request 3 */
#define SRC_ID_GTMTIM54			784	/* GTM TIM5 Shared Service Request 4 */
#define SRC_ID_GTMTIM55			785	/* GTM TIM5 Shared Service Request 5 */
#define SRC_ID_GTMTIM56			786	/* GTM TIM5 Shared Service Request 6 */
#define SRC_ID_GTMTIM57			787	/* GTM TIM5 Shared Service Request 7 */
#define SRC_ID_GTMTIM60			788	/* GTM TIM6 Shared Service Request 0 */
#define SRC_ID_GTMTIM61			789	/* GTM TIM6 Shared Service Request 1 */
#define SRC_ID_GTMTIM62			790	/* GTM TIM6 Shared Service Request 2 */
#define SRC_ID_GTMTIM63			791	/* GTM TIM6 Shared Service Request 3 */
#define SRC_ID_GTMTIM64			792	/* GTM TIM6 Shared Service Request 4 */
#define SRC_ID_GTMTIM65			793	/* GTM TIM6 Shared Service Request 5 */
#define SRC_ID_GTMTIM66			794	/* GTM TIM6 Shared Service Request 6 */
#define SRC_ID_GTMTIM67			795	/* GTM TIM6 Shared Service Request 7 */
#define SRC_ID_GTMTIM70			796	/* GTM TIM7 Shared Service Request 0 */
#define SRC_ID_GTMTIM71			797	/* GTM TIM7 Shared Service Request 1 */
#define SRC_ID_GTMTIM72			798	/* GTM TIM7 Shared Service Request 2 */
#define SRC_ID_GTMTIM73			799	/* GTM TIM7 Shared Service Request 3 */
#define SRC_ID_GTMTIM74			800	/* GTM TIM7 Shared Service Request 4 */
#define SRC_ID_GTMTIM75			801	/* GTM TIM7 Shared Service Request 5 */
#define SRC_ID_GTMTIM76			802	/* GTM TIM7 Shared Service Request 6 */
#define SRC_ID_GTMTIM77			803	/* GTM TIM7 Shared Service Request 7 */

#define SRC_ID_GTMMSC00			812	/* GTM MCS0 Shared Service Request 0 */
#define SRC_ID_GTMMSC01			813	/* GTM MCS0 Shared Service Request 1 */
#define SRC_ID_GTMMSC02			814	/* GTM MCS0 Shared Service Request 2 */
#define SRC_ID_GTMMSC03			815	/* GTM MCS0 Shared Service Request 3 */
#define SRC_ID_GTMMSC04			816	/* GTM MCS0 Shared Service Request 4 */
#define SRC_ID_GTMMSC05			817	/* GTM MCS0 Shared Service Request 5 */
#define SRC_ID_GTMMSC06			818	/* GTM MCS0 Shared Service Request 6 */
#define SRC_ID_GTMMSC07			819	/* GTM MCS0 Shared Service Request 7 */
#define SRC_ID_GTMMSC10			820	/* GTM MCS1 Shared Service Request 0 */
#define SRC_ID_GTMMSC11			821	/* GTM MCS1 Shared Service Request 1 */
#define SRC_ID_GTMMSC12			822	/* GTM MCS1 Shared Service Request 2 */
#define SRC_ID_GTMMSC13			823	/* GTM MCS1 Shared Service Request 3 */
#define SRC_ID_GTMMSC14			824	/* GTM MCS1 Shared Service Request 4 */
#define SRC_ID_GTMMSC15			825	/* GTM MCS1 Shared Service Request 5 */
#define SRC_ID_GTMMSC16			826	/* GTM MCS1 Shared Service Request 6 */
#define SRC_ID_GTMMSC17			827	/* GTM MCS1 Shared Service Request 7 */
#define SRC_ID_GTMMSC20			828	/* GTM MCS2 Shared Service Request 0 */
#define SRC_ID_GTMMSC21			829	/* GTM MCS2 Shared Service Request 1 */
#define SRC_ID_GTMMSC22			830	/* GTM MCS2 Shared Service Request 2 */
#define SRC_ID_GTMMSC23			831	/* GTM MCS2 Shared Service Request 3 */
#define SRC_ID_GTMMSC24			832	/* GTM MCS2 Shared Service Request 4 */
#define SRC_ID_GTMMSC25			833	/* GTM MCS2 Shared Service Request 5 */
#define SRC_ID_GTMMSC26			834	/* GTM MCS2 Shared Service Request 6 */
#define SRC_ID_GTMMSC27			835	/* GTM MCS2 Shared Service Request 7 */
#define SRC_ID_GTMMSC30			836	/* GTM MCS3 Shared Service Request 0 */
#define SRC_ID_GTMMSC31			837	/* GTM MCS3 Shared Service Request 1 */
#define SRC_ID_GTMMSC32			838	/* GTM MCS3 Shared Service Request 2 */
#define SRC_ID_GTMMSC33			839	/* GTM MCS3 Shared Service Request 3 */
#define SRC_ID_GTMMSC34			840	/* GTM MCS3 Shared Service Request 4 */
#define SRC_ID_GTMMSC35			841	/* GTM MCS3 Shared Service Request 5 */
#define SRC_ID_GTMMSC36			842	/* GTM MCS3 Shared Service Request 6 */
#define SRC_ID_GTMMSC37			843	/* GTM MCS3 Shared Service Request 7 */
#define SRC_ID_GTMMSC40			844	/* GTM MCS4 Shared Service Request 0 */
#define SRC_ID_GTMMSC41			845	/* GTM MCS4 Shared Service Request 1 */
#define SRC_ID_GTMMSC42			846	/* GTM MCS4 Shared Service Request 2 */
#define SRC_ID_GTMMSC43			847	/* GTM MCS4 Shared Service Request 3 */
#define SRC_ID_GTMMSC44			848	/* GTM MCS4 Shared Service Request 4 */
#define SRC_ID_GTMMSC45			849	/* GTM MCS4 Shared Service Request 5 */
#define SRC_ID_GTMMSC46			850	/* GTM MCS4 Shared Service Request 6 */
#define SRC_ID_GTMMSC47			851	/* GTM MCS4 Shared Service Request 7 */
#define SRC_ID_GTMMSC50			852	/* GTM MCS5 Shared Service Request 0 */
#define SRC_ID_GTMMSC51			853	/* GTM MCS5 Shared Service Request 1 */
#define SRC_ID_GTMMSC52			854	/* GTM MCS5 Shared Service Request 2 */
#define SRC_ID_GTMMSC53			855	/* GTM MCS5 Shared Service Request 3 */
#define SRC_ID_GTMMSC54			856	/* GTM MCS5 Shared Service Request 4 */
#define SRC_ID_GTMMSC55			857	/* GTM MCS5 Shared Service Request 5 */
#define SRC_ID_GTMMSC56			858	/* GTM MCS5 Shared Service Request 6 */
#define SRC_ID_GTMMSC57			859	/* GTM MCS5 Shared Service Request 7 */
#define SRC_ID_GTMMSC60			860	/* GTM MCS6 Shared Service Request 0 */
#define SRC_ID_GTMMSC61			861	/* GTM MCS6 Shared Service Request 1 */
#define SRC_ID_GTMMSC62			862	/* GTM MCS6 Shared Service Request 2 */
#define SRC_ID_GTMMSC63			863	/* GTM MCS6 Shared Service Request 3 */
#define SRC_ID_GTMMSC64			864	/* GTM MCS6 Shared Service Request 4 */
#define SRC_ID_GTMMSC65			865	/* GTM MCS6 Shared Service Request 5 */
#define SRC_ID_GTMMSC66			866	/* GTM MCS6 Shared Service Request 6 */
#define SRC_ID_GTMMSC67			867	/* GTM MCS6 Shared Service Request 7 */
#define SRC_ID_GTMMSC70			868	/* GTM MCS7 Shared Service Request 0 */
#define SRC_ID_GTMMSC71			869	/* GTM MCS7 Shared Service Request 1 */
#define SRC_ID_GTMMSC72			870	/* GTM MCS7 Shared Service Request 2 */
#define SRC_ID_GTMMSC73			871	/* GTM MCS7 Shared Service Request 3 */
#define SRC_ID_GTMMSC74			872	/* GTM MCS7 Shared Service Request 4 */
#define SRC_ID_GTMMSC75			873	/* GTM MCS7 Shared Service Request 5 */
#define SRC_ID_GTMMSC76			874	/* GTM MCS7 Shared Service Request 6 */
#define SRC_ID_GTMMSC77			875	/* GTM MCS7 Shared Service Request 7 */
#define SRC_ID_GTMMSC80			876	/* GTM MCS8 Shared Service Request 0 */
#define SRC_ID_GTMMSC81			877	/* GTM MCS8 Shared Service Request 1 */
#define SRC_ID_GTMMSC82			878	/* GTM MCS8 Shared Service Request 2 */
#define SRC_ID_GTMMSC83			879	/* GTM MCS8 Shared Service Request 3 */
#define SRC_ID_GTMMSC84			880	/* GTM MCS8 Shared Service Request 4 */
#define SRC_ID_GTMMSC85			881	/* GTM MCS8 Shared Service Request 5 */
#define SRC_ID_GTMMSC86			882	/* GTM MCS8 Shared Service Request 6 */
#define SRC_ID_GTMMSC87			883	/* GTM MCS8 Shared Service Request 7 */
#define SRC_ID_GTMMSC90			884	/* GTM MCS9 Shared Service Request 0 */
#define SRC_ID_GTMMSC91			885	/* GTM MCS9 Shared Service Request 1 */
#define SRC_ID_GTMMSC92			886	/* GTM MCS9 Shared Service Request 2 */
#define SRC_ID_GTMMSC93			887	/* GTM MCS9 Shared Service Request 3 */
#define SRC_ID_GTMMSC94			888	/* GTM MCS9 Shared Service Request 4 */
#define SRC_ID_GTMMSC95			889	/* GTM MCS9 Shared Service Request 5 */
#define SRC_ID_GTMMSC96			890	/* GTM MCS9 Shared Service Request 6 */
#define SRC_ID_GTMMSC97			891	/* GTM MCS9 Shared Service Request 7 */

#define SRC_ID_GTMTOM00			900	/* GTM TOM0 Shared Service Request 0 */
#define SRC_ID_GTMTOM01			901	/* GTM TOM0 Shared Service Request 1 */
#define SRC_ID_GTMTOM02			902	/* GTM TOM0 Shared Service Request 2 */
#define SRC_ID_GTMTOM03			903	/* GTM TOM0 Shared Service Request 3 */
#define SRC_ID_GTMTOM04			904	/* GTM TOM0 Shared Service Request 4 */
#define SRC_ID_GTMTOM05			905	/* GTM TOM0 Shared Service Request 5 */
#define SRC_ID_GTMTOM06			906	/* GTM TOM0 Shared Service Request 6 */
#define SRC_ID_GTMTOM07			907	/* GTM TOM0 Shared Service Request 7 */
#define SRC_ID_GTMTOM10			908	/* GTM TOM1 Shared Service Request 0 */
#define SRC_ID_GTMTOM11			909	/* GTM TOM1 Shared Service Request 1 */
#define SRC_ID_GTMTOM12			910	/* GTM TOM1 Shared Service Request 2 */
#define SRC_ID_GTMTOM13			911	/* GTM TOM1 Shared Service Request 3 */
#define SRC_ID_GTMTOM14			912	/* GTM TOM1 Shared Service Request 4 */
#define SRC_ID_GTMTOM15			913	/* GTM TOM1 Shared Service Request 5 */
#define SRC_ID_GTMTOM16			914	/* GTM TOM1 Shared Service Request 6 */
#define SRC_ID_GTMTOM17			915	/* GTM TOM1 Shared Service Request 7 */
#define SRC_ID_GTMTOM20			916	/* GTM TOM2 Shared Service Request 0 */
#define SRC_ID_GTMTOM21			917	/* GTM TOM2 Shared Service Request 1 */
#define SRC_ID_GTMTOM22			918	/* GTM TOM2 Shared Service Request 2 */
#define SRC_ID_GTMTOM23			919	/* GTM TOM2 Shared Service Request 3 */
#define SRC_ID_GTMTOM24			920	/* GTM TOM2 Shared Service Request 4 */
#define SRC_ID_GTMTOM25			921	/* GTM TOM2 Shared Service Request 5 */
#define SRC_ID_GTMTOM26			922	/* GTM TOM2 Shared Service Request 6 */
#define SRC_ID_GTMTOM27			923	/* GTM TOM2 Shared Service Request 7 */
#define SRC_ID_GTMTOM30			924	/* GTM TOM3 Shared Service Request 0 */
#define SRC_ID_GTMTOM31			925	/* GTM TOM3 Shared Service Request 1 */
#define SRC_ID_GTMTOM32			926	/* GTM TOM3 Shared Service Request 2 */
#define SRC_ID_GTMTOM33			927	/* GTM TOM3 Shared Service Request 3 */
#define SRC_ID_GTMTOM34			928	/* GTM TOM3 Shared Service Request 4 */
#define SRC_ID_GTMTOM35			929	/* GTM TOM3 Shared Service Request 5 */
#define SRC_ID_GTMTOM36			930	/* GTM TOM3 Shared Service Request 6 */
#define SRC_ID_GTMTOM37			931	/* GTM TOM3 Shared Service Request 7 */
#define SRC_ID_GTMTOM40			932	/* GTM TOM4 Shared Service Request 0 */
#define SRC_ID_GTMTOM41			933	/* GTM TOM4 Shared Service Request 1 */
#define SRC_ID_GTMTOM42			934	/* GTM TOM4 Shared Service Request 2 */
#define SRC_ID_GTMTOM43			935	/* GTM TOM4 Shared Service Request 3 */
#define SRC_ID_GTMTOM44			936	/* GTM TOM4 Shared Service Request 4 */
#define SRC_ID_GTMTOM45			937	/* GTM TOM4 Shared Service Request 5 */
#define SRC_ID_GTMTOM46			938	/* GTM TOM4 Shared Service Request 6 */
#define SRC_ID_GTMTOM47			939	/* GTM TOM4 Shared Service Request 7 */
#define SRC_ID_GTMTOM50			940	/* GTM TOM5 Shared Service Request 0 */
#define SRC_ID_GTMTOM51			941	/* GTM TOM5 Shared Service Request 1 */
#define SRC_ID_GTMTOM52			942	/* GTM TOM5 Shared Service Request 2 */
#define SRC_ID_GTMTOM53			943	/* GTM TOM5 Shared Service Request 3 */
#define SRC_ID_GTMTOM54			944	/* GTM TOM5 Shared Service Request 4 */
#define SRC_ID_GTMTOM55			945	/* GTM TOM5 Shared Service Request 5 */
#define SRC_ID_GTMTOM56			946	/* GTM TOM5 Shared Service Request 6 */
#define SRC_ID_GTMTOM57			947	/* GTM TOM5 Shared Service Request 7 */

#define SRC_ID_GTMATOM00		956	/* GTM ATOM0 Shared Service Request 0 */
#define SRC_ID_GTMATOM01		957	/* GTM ATOM0 Shared Service Request 1 */
#define SRC_ID_GTMATOM02		958	/* GTM ATOM0 Shared Service Request 2 */
#define SRC_ID_GTMATOM03		959	/* GTM ATOM0 Shared Service Request 3 */
#define SRC_ID_GTMATOM10		960	/* GTM ATOM1 Shared Service Request 0 */
#define SRC_ID_GTMATOM11		961	/* GTM ATOM1 Shared Service Request 1 */
#define SRC_ID_GTMATOM12		962	/* GTM ATOM1 Shared Service Request 2 */
#define SRC_ID_GTMATOM13		963	/* GTM ATOM1 Shared Service Request 3 */
#define SRC_ID_GTMATOM20		964	/* GTM ATOM2 Shared Service Request 0 */
#define SRC_ID_GTMATOM21		965	/* GTM ATOM2 Shared Service Request 1 */
#define SRC_ID_GTMATOM22		966	/* GTM ATOM2 Shared Service Request 2 */
#define SRC_ID_GTMATOM23		967	/* GTM ATOM2 Shared Service Request 3 */
#define SRC_ID_GTMATOM30		968	/* GTM ATOM3 Shared Service Request 0 */
#define SRC_ID_GTMATOM31		969	/* GTM ATOM3 Shared Service Request 1 */
#define SRC_ID_GTMATOM32		970	/* GTM ATOM3 Shared Service Request 2 */
#define SRC_ID_GTMATOM33		971	/* GTM ATOM3 Shared Service Request 3 */
#define SRC_ID_GTMATOM40		972	/* GTM ATOM4 Shared Service Request 0 */
#define SRC_ID_GTMATOM41		973	/* GTM ATOM4 Shared Service Request 1 */
#define SRC_ID_GTMATOM42		974	/* GTM ATOM4 Shared Service Request 2 */
#define SRC_ID_GTMATOM43		975	/* GTM ATOM4 Shared Service Request 3 */
#define SRC_ID_GTMATOM50		976	/* GTM ATOM5 Shared Service Request 0 */
#define SRC_ID_GTMATOM51		977	/* GTM ATOM5 Shared Service Request 1 */
#define SRC_ID_GTMATOM52		978	/* GTM ATOM5 Shared Service Request 2 */
#define SRC_ID_GTMATOM53		979	/* GTM ATOM5 Shared Service Request 3 */
#define SRC_ID_GTMATOM60		980	/* GTM ATOM6 Shared Service Request 0 */
#define SRC_ID_GTMATOM61		981	/* GTM ATOM6 Shared Service Request 1 */
#define SRC_ID_GTMATOM62		982	/* GTM ATOM6 Shared Service Request 2 */
#define SRC_ID_GTMATOM63		983	/* GTM ATOM6 Shared Service Request 3 */
#define SRC_ID_GTMATOM70		984	/* GTM ATOM7 Shared Service Request 0 */
#define SRC_ID_GTMATOM71		985	/* GTM ATOM7 Shared Service Request 1 */
#define SRC_ID_GTMATOM72		986	/* GTM ATOM7 Shared Service Request 2 */
#define SRC_ID_GTMATOM73		987	/* GTM ATOM7 Shared Service Request 3 */
#define SRC_ID_GTMATOM80		988	/* GTM ATOM8 Shared Service Request 0 */
#define SRC_ID_GTMATOM81		989	/* GTM ATOM8 Shared Service Request 1 */
#define SRC_ID_GTMATOM82		990	/* GTM ATOM8 Shared Service Request 2 */
#define SRC_ID_GTMATOM83		991	/* GTM ATOM8 Shared Service Request 3 */
#define SRC_ID_GTMATOM90		992	/* GTM ATOM9 Shared Service Request 0 */
#define SRC_ID_GTMATOM91		993	/* GTM ATOM9 Shared Service Request 1 */
#define SRC_ID_GTMATOM92		994	/* GTM ATOM9 Shared Service Request 2 */
#define SRC_ID_GTMATOM93		995	/* GTM ATOM9 Shared Service Request 3 */
#define SRC_ID_GTMATOM100		996	/* GTM ATOM10 Shared Service Request 0 */
#define SRC_ID_GTMATOM101		997	/* GTM ATOM10 Shared Service Request 1 */
#define SRC_ID_GTMATOM102		998	/* GTM ATOM10 Shared Service Request 2 */
#define SRC_ID_GTMATOM103		999	/* GTM ATOM10 Shared Service Request 3 */
#define SRC_ID_GTMATOM110		1000	/* GTM ATOM11 Shared Service Request 0 */
#define SRC_ID_GTMATOM111		1001	/* GTM ATOM11 Shared Service Request 1 */
#define SRC_ID_GTMATOM112		1002	/* GTM ATOM11 Shared Service Request 2 */
#define SRC_ID_GTMATOM113		1003	/* GTM ATOM11 Shared Service Request 3 */

#define SRC_ID_GTMMCSW0			1012	/* GTM Multi Channel Sequencer Service Request 0 */
#define SRC_ID_GTMMCSW1			1013	/* GTM Multi Channel Sequencer Service Request 1 */
#define SRC_ID_GTMMCSW2			1014	/* GTM Multi Channel Sequencer Service Request 2 */
#define SRC_ID_GTMMCSW3			1015	/* GTM Multi Channel Sequencer Service Request 3 */
#define SRC_ID_GTMMCSW4			1016	/* GTM Multi Channel Sequencer Service Request 4 */
#define SRC_ID_GTMMCSW5			1017	/* GTM Multi Channel Sequencer Service Request 5 */
#define SRC_ID_GTMMCSW6			1018	/* GTM Multi Channel Sequencer Service Request 6 */
#define SRC_ID_GTMMCSW7			1019	/* GTM Multi Channel Sequencer Service Request 7 */
#define SRC_ID_GTMMCSW8			1020	/* GTM Multi Channel Sequencer Service Request 8 */
#define SRC_ID_GTMMCSW9			1021	/* GTM Multi Channel Sequencer Service Request 9 */

#define IRQ_ID_MAX_NUM			1022


#endif /* __INTIDS_TC39XB_H__ */
