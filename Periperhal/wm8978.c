#include "wm8978.h"
#include "bsp_myiic.h"


uint8_t ucVolue = 50;

//WM8978寄存器值缓存区(总共58个寄存器,0~57),占用116字节内存
//因为WM8978的IIC操作不支持读操作,所以在本地保存所有寄存器值
//写WM8978寄存器时,同步更新到本地寄存器值,读寄存器时,直接返回本地保存的寄存器值.
//注意:WM8978的寄存器值是9位的,所以要用uint16_t来存储. 
 uint16_t wm8978_RegCash[] = {
	0x000, 0x000, 0x000, 0x000, 0x050, 0x000, 0x140, 0x000,
	0x000, 0x000, 0x000, 0x0FF, 0x0FF, 0x000, 0x100, 0x0FF,
	0x0FF, 0x000, 0x12C, 0x02C, 0x02C, 0x02C, 0x02C, 0x000,
	0x032, 0x000, 0x000, 0x000, 0x000, 0x000, 0x000, 0x000,
	0x038, 0x00B, 0x032, 0x000, 0x008, 0x00C, 0x093, 0x0E9,
	0x000, 0x000, 0x000, 0x000, 0x003, 0x010, 0x010, 0x100,
	0x100, 0x002, 0x001, 0x001, 0x039, 0x039, 0x039, 0x039,
	0x001, 0x001
};

//WM8978写寄存器
//reg:寄存器地址
//val:要写入寄存器的值 
//返回值:0,成功;
//    其他,错误代码
uint8_t wm8978_WriteReg(uint8_t reg,uint16_t Value)
{ 
	IIC_Start(); 
	IIC_Send_Byte((WM8978_ADDR<<1)|0);//发送器件地址+写命令	 
	if(IIC_Wait_Ack())return 1;	//等待应答(成功?/失败?) 
		IIC_Send_Byte((reg<<1)|((Value>>8)&0X01));//写寄存器地址+数据的最高位
	if(IIC_Wait_Ack())return 2;	//等待应答(成功?/失败?) 
		IIC_Send_Byte(Value&0XFF);	//发送数据
	if(IIC_Wait_Ack())return 3;	//等待应答(成功?/失败?) 
		IIC_Stop();
	
	wm8978_RegCash[reg] = Value;	//保存寄存器值到本地

	return 0;	
}  

uint16_t wm8978_ReadReg(uint8_t _ucRegAddr)
{
	return wm8978_RegCash[_ucRegAddr];
}



//WM8978初始化
//返回值:0,初始化正常
//    其他,错误代码
uint8_t wm8978_Init(void)
{
	uint8_t res;
	IIC_Init();
	res = wm8978_Reset();			/* 硬件复位WM8978所有寄存器到缺省状态 */
	return res;
} 


/**
	* @brief  修改输出通道1音量
	* @param  _ucVolume ：音量值, 0-63
	* @retval 无
	*/
void wm8978_SetOUT1Volume(uint8_t _ucVolume)
{
	uint16_t regL;
	uint16_t regR;

	if (_ucVolume > VOLUME_MAX)
	{
		_ucVolume = VOLUME_MAX;
	}
	else if (_ucVolume == 0)
	{
		regL = 1<<6;
		regR = 1<<6;
	}
	else
	{
		regL = _ucVolume;
		regR = _ucVolume;
	}
	/*
		R52	LOUT1 Volume control
		R53	ROUT1 Volume control
	*/
	/* 先更新左声道缓存值 */
	wm8978_WriteReg(52, regL | 0x00);

	/* 再同步更新左右声道的音量 */
	wm8978_WriteReg(53, regR | 0x100);	/* 0x180表示 在音量为0时再更新，避免调节音量出现的“嘎哒”声 */
}


/**
	* @brief  修改输出通道2音量
	* @param  _ucVolume ：音量值, 0-63
	* @retval 无
	*/
void wm8978_SetOUT2Volume(uint8_t _ucVolume)
{
	uint16_t regL;
	uint16_t regR;

	if (_ucVolume > VOLUME_MAX)
	{
		_ucVolume = VOLUME_MAX;
	}
	else if (_ucVolume == 0)
	{
		regL = 1<<6;
		regR = 1<<6;
	}
	else
	{
		regL = _ucVolume;
		regR = _ucVolume;
	}
	/*
		R54	LOUT2 (SPK) Volume control
		R55	ROUT2 (SPK) Volume control
	*/
	/* 先更新左声道缓存值 */
	wm8978_WriteReg(54, regL | 0x00);

	/* 再同步更新左右声道的音量 */
	
	wm8978_WriteReg(55, regR | 0x100);	/* 在音量为0时再更新，避免调节音量出现的“嘎哒”声 */
}


/**
	* @brief  读取输出通道1音量
	* @param  无
	* @retval 当前音量值
	*/
uint8_t wm8978_ReadOUT1Volume(void)
{
	return (uint8_t)(wm8978_ReadReg(52) & 0x3F );
}

/**
	* @brief  读取输出通道2音量
	* @param  无
	* @retval 当前音量值
	*/
uint8_t wm8978_ReadOUT2Volume(void)
{
	return (uint8_t)(wm8978_ReadReg(54) & 0x3F );
}


/**
	* @brief  输出静音.
	* @param  _ucMute：模式选择
	*         @arg 1：静音
	*         @arg 0：取消静音
	* @retval 无
	*/
void wm8978_OutMute(uint8_t _ucMute)
{
	uint16_t usRegValue;

	if (_ucMute == 1) /* 静音 */
	{
		usRegValue = wm8978_ReadReg(52); /* Left Mixer Control */
		usRegValue |= (1u << 6);
		wm8978_WriteReg(52, usRegValue);

		usRegValue = wm8978_ReadReg(53); /* Left Mixer Control */
		usRegValue |= (1u << 6);
		wm8978_WriteReg(53, usRegValue);

		usRegValue = wm8978_ReadReg(54); /* Right Mixer Control */
		usRegValue |= (1u << 6);
		wm8978_WriteReg(54, usRegValue);

		usRegValue = wm8978_ReadReg(55); /* Right Mixer Control */
		usRegValue |= (1u << 6);
		wm8978_WriteReg(55, usRegValue);
	}
	else	/* 取消静音 */
	{
		usRegValue = wm8978_ReadReg(52);
		usRegValue &= ~(1u << 6);
		wm8978_WriteReg(52, usRegValue);

		usRegValue = wm8978_ReadReg(53); /* Left Mixer Control */
		usRegValue &= ~(1u << 6);
		wm8978_WriteReg(53, usRegValue);

		usRegValue = wm8978_ReadReg(54);
		usRegValue &= ~(1u << 6);
		wm8978_WriteReg(54, usRegValue);

		usRegValue = wm8978_ReadReg(55); /* Left Mixer Control */
		usRegValue &= ~(1u << 6);
		wm8978_WriteReg(55, usRegValue);
	}
}

/**
	* @brief  设置增益
	* @param  _ucGain ：增益值, 0-63
	* @retval 无
	*/
void wm8978_SetMicGain(uint8_t _ucGain)
{
	if (_ucGain > GAIN_MAX)
	{
		_ucGain = GAIN_MAX;
	}

	/* PGA 音量控制  R45， R46 
		Bit8	INPPGAUPDATE
		Bit7	INPPGAZCL		过零再更改
		Bit6	INPPGAMUTEL		PGA静音
		Bit5:0	增益值，010000是0dB
	*/
	wm8978_WriteReg(45, _ucGain);
	wm8978_WriteReg(46, _ucGain | (1 << 8));
}


/**
	* @brief  设置Line输入通道的增益
	* @param  _ucGain ：音量值, 0-7. 7最大，0最小。 可衰减可放大。
	* @param 	_ucGain ：音量值, 0-63. 63最大，0最小。 可衰减可放大。 -12dB~35.25dB   16=0dB
	* @retval 无
	*/
void wm8978_SetLineGain(uint16_t In_path,uint8_t _ucGain)
{
	uint16_t usRegValue;

	/*
		Mic 输入信道的增益由 PGABOOSTL 和 PGABOOSTR 控制
		Aux 输入信道的输入增益由 AUXL2BOOSTVO[2:0] 和 AUXR2BOOSTVO[2:0] 控制
		Line 输入信道的增益由 LIP2BOOSTVOL[2:0] 和 RIP2BOOSTVOL[2:0] 控制
	*/
	if(In_path & LINE_BOOST_EN)
	{
		if (_ucGain > 63)
		{
			_ucGain = 63;
		}
		wm8978_WriteReg(45, _ucGain);
		wm8978_WriteReg(46, _ucGain | (1 << 8));
	}
	else
	{
		/*	R47（左声道），R48（右声道）, MIC 增益控制寄存器
			R47 (R48定义与此相同)
			B8		PGABOOSTL	= 1,   0表示MIC信号直通无增益，1表示MIC信号+20dB增益（通过自举电路）
			B7		= 0， 保留
			B6:4	L2_2BOOSTVOL = x， 0表示禁止，1-7表示增益-12dB ~ +6dB  （可以衰减也可以放大）
			B3		= 0， 保留
			B2:0`	AUXL2BOOSTVOL = x，0表示禁止，1-7表示增益-12dB ~ +6dB  （可以衰减也可以放大）
		*/
		if (_ucGain > 7)
		{
			_ucGain = 7;
		}
		usRegValue = wm8978_ReadReg(47);
		usRegValue &= 0x8F;/* 将Bit6:4清0   1000 1111*/
		usRegValue |= (_ucGain << 4);
		wm8978_WriteReg(47, usRegValue);	/* 写左声道输入增益控制寄存器 */

		usRegValue = wm8978_ReadReg(48);
		usRegValue &= 0x8F;/* 将Bit6:4清0   1000 1111*/
		usRegValue |= (_ucGain << 4);
		wm8978_WriteReg(48, usRegValue);	/* 写右声道输入增益控制寄存器 */
	}
	
}

/**
	* @brief  设置AUX输入通道的增益
	* @param  _ucGain ：音量值, 0-7. 7最大，0最小。 可衰减可放大。
	* @retval 无
	*/
void wm8978_SetAUXGain(uint8_t _ucGain)
{
	uint16_t usRegValue;

	if (_ucGain > 7)
	{
		_ucGain = 7;
	}

	/*
		Mic 输入信道的增益由 PGABOOSTL 和 PGABOOSTR 控制
		Aux 输入信道的输入增益由 AUXL2BOOSTVO[2:0] 和 AUXR2BOOSTVO[2:0] 控制
		Line 输入信道的增益由 LIP2BOOSTVOL[2:0] 和 RIP2BOOSTVOL[2:0] 控制
	*/
	/*	R47（左声道），R48（右声道）, MIC 增益控制寄存器
		R47 (R48定义与此相同)
		B8		PGABOOSTL	= 1,   0表示MIC信号直通无增益，1表示MIC信号+20dB增益（通过自举电路）
		B7		= 0， 保留
		B6:4	L2_2BOOSTVOL = x， 0表示禁止，1-7表示增益-12dB ~ +6dB  （可以衰减也可以放大）
		B3		= 0， 保留
		B2:0`	AUXL2BOOSTVOL = x，0表示禁止，1-7表示增益-12dB ~ +6dB  （可以衰减也可以放大）
	*/

	usRegValue = wm8978_ReadReg(47);
	usRegValue &= 0xF8;/* 将Bit6:4清0   1111 1000*/
	usRegValue |= (_ucGain << 0);
	wm8978_WriteReg(47, usRegValue);	/* 写左声道输入增益控制寄存器 */

	usRegValue = wm8978_ReadReg(48);
	usRegValue &= 0xF8;/* 将Bit6:4清0   1111 1000*/
	usRegValue |= (_ucGain << 0);
	wm8978_WriteReg(48, usRegValue);	/* 写右声道输入增益控制寄存器 */
}

/**
	* @brief  关闭wm8978，进入低功耗模式
	* @param  无
	* @retval 无
	*/
void wm8978_PowerDown(void)
{
	wm8978_Reset();			/* 硬件复位WM8978所有寄存器到缺省状态 */
}

/**
	* @brief  配置WM8978的音频接口(I2S)
	* @param  _usStandard : 接口标准，I2S_Standard_Phillips, I2S_Standard_MSB 或 I2S_Standard_LSB
	* @param  _ucWordLen : 字长，16、24、32  （丢弃不常用的20bit格式）
	* @retval 无
	*/
void wm8978_CfgAudioIF(uint16_t _usStandard, uint8_t _ucWordLen,uint16_t _ucSample)
{
	uint16_t usReg;

	/* WM8978(V4.5_2011).pdf 73页，寄存器列表 */

	/*	REG R4, 音频接口控制寄存器
		B8		BCP	 = X, BCLK极性，0表示正常，1表示反相
		B7		LRCP = x, LRC时钟极性，0表示正常，1表示反相
		B6:5	WL = x， 字长，00=16bit，01=20bit，10=24bit，11=32bit （右对齐模式只能操作在最大24bit)
		B4:3	FMT = x，音频数据格式，00=右对齐，01=左对齐，10=I2S格式，11=PCM
		B2		DACLRSWAP = x, 控制DAC数据出现在LRC时钟的左边还是右边
		B1 		ADCLRSWAP = x，控制ADC数据出现在LRC时钟的左边还是右边
		B0		MONO	= 0，0表示立体声，1表示单声道，仅左声道有效
	*/
	usReg = 0;
	if (_usStandard == I2S_Standard_Phillips)	/* I2S飞利浦标准 */
	{
		usReg |= (2 << 3);
	}
	else if (_usStandard == I2S_Standard_MSB)	/* MSB对齐标准(左对齐) */
	{
		usReg |= (1 << 3);
	}
	else if (_usStandard == I2S_Standard_LSB)	/* LSB对齐标准(右对齐) */
	{
		usReg |= (0 << 3);
	}
	else	/* PCM标准(16位通道帧上带长或短帧同步或者16位数据帧扩展为32位通道帧) */
	{
		usReg |= (3 << 3);;
	}

	if (_ucWordLen == 24)
	{
		usReg |= (2 << 5);
	}
	else if (_ucWordLen == 32)
	{
		usReg |= (3 << 5);
	}
	else
	{
		usReg |= (0 << 5);		/* 16bit */
	}
	wm8978_WriteReg(4, usReg);


	/*
		R6，时钟产生控制寄存器
		MS = 0,  WM8978被动时钟，由MCU提供MCLK时钟
	*/
	wm8978_WriteReg(6, 0x000);
	
	/*
		R7 [3:1]，采样率设置
	*/	
	usReg = wm8978_ReadReg(7);
	usReg &= (0x01);
	if (_ucSample == SAMPLE_8K)
	{
		usReg |= (5 << 1);
	}
	else if (_ucSample == SAMPLE_16K)
	{
		usReg |= (3 << 1);
	}
	else if (_ucSample == SAMPLE_24K)
	{
		usReg |= (2 << 1);
	}
	else if (_ucSample == SAMPLE_32K)
	{
		usReg |= (1 << 1);
	}

	wm8978_WriteReg(7, usReg);
	
}




/**
	* @brief  配置wm8978音频通道
	* @param  _InPath : 音频输入通道配置
	* @param  _OutPath : 音频输出通道配置
	* @retval 无
	*/
void wm8978_CfgAudioPath(uint16_t _InPath, uint16_t _OutPath)
{
	uint16_t usReg;

	/* 查看WM8978数据手册的 REGISTER MAP 章节， 第89页 */

	if ((_InPath == IN_PATH_OFF) && (_OutPath == OUT_PATH_OFF))
	{
		wm8978_PowerDown();
		return;
	}

	/*
		R1 寄存器 Power manage 1
		Bit8    BUFDCOPEN,  Output stage 1.5xAVDD/2 driver enable
 		Bit7    OUT4MIXEN, OUT4 mixer enable
		Bit6    OUT3MIXEN, OUT3 mixer enable
		Bit5    PLLEN	.不用
		Bit4    MICBEN	,Microphone Bias Enable (MIC偏置电路使能)
		Bit3    BIASEN	,Analogue amplifier bias control 必须设置为1模拟放大器才工作
		Bit2    BUFIOEN , Unused input/output tie off buffer enable
		Bit1:0  VMIDSEL, 必须设置为非00值模拟放大器才工作
	*/
	usReg = (1 << 3) | (3 << 0);/* BIASEN = 1; VMIDSEL = 5KΩ */
	if (_OutPath & OUT3_ON) 	/* OUT3和OUT4使能输出 */
	{
		usReg |= (1 << 6);
	}

	if (_OutPath & OUT4_ON) 	/* OUT3和OUT4使能输出 */
	{
		usReg |= (1 << 7);
	}
	
	if ((_InPath & MIC_LEFT_ON) || (_InPath & MIC_RIGHT_ON))
	{
		usReg |= (1 << 4);
	}
	
	wm8978_WriteReg(1, usReg);	/* 写寄存器 */

	/*
		R2 寄存器 Power manage 2
		Bit8	ROUT1EN,	ROUT1 output enable 耳机右声道输出使能
		Bit7	LOUT1EN,	LOUT1 output enable 耳机左声道输出使能
		Bit6	SLEEP, 		0 = Normal device operation   1 = Residual current reduced in device standby mode
		Bit5	BOOSTENR,	Right channel Input BOOST enable 输入通道自举电路使能. 用到PGA放大功能时必须使能
		Bit4	BOOSTENL,	Left channel Input BOOST enable
		Bit3	INPGAENR,	Right channel input PGA enable 右声道输入PGA使能
		Bit2	INPGAENL,	Left channel input PGA enable
		Bit1	ADCENR,		Enable ADC right channel
		Bit0	ADCENL,		Enable ADC left channel
	*/
	usReg = 0;
	if (_OutPath & EAR_LEFT_ON)
	{
		usReg |= (1 << 7);
	}
	
	if (_OutPath & EAR_RIGHT_ON)
	{
		usReg |= (1 << 8);
	}
	
	if (_InPath & MIC_LEFT_ON)
	{
		usReg |= ((1 << 4) | (1 << 2));
	}
	
	if (_InPath & MIC_RIGHT_ON)
	{
		usReg |= ((1 << 5) | (1 << 3));
	}
	
	/* Line 是否需要进行放大 */
	if (_InPath & LINE_ON)
	{
		if(_InPath & LINE_BOOST_EN)
		{
			if(_InPath & LINE_L2_EN)
			{
				usReg |= ((1 << 4) | (1 << 2));
			}
			else if(_InPath & LINE_R2_EN)
			{
				usReg |= ((1 << 5) | (1 << 3));
			}
			else
			{
				usReg |= ((1 << 4) | (1 << 2));
				usReg |= ((1 << 5) | (1 << 3));
			}
		}
		else
		{	
			usReg |= ((1 << 4) | (1 << 5));
		}
	}
	
	if (_InPath & ADC_ON)
	{
		usReg |= ((1 << 1) | (1 << 0));
	}
	wm8978_WriteReg(2, usReg);	/* 写寄存器 */

	/*
		R3 寄存器 Power manage 3
		Bit8	OUT4EN,		OUT4 enable
		Bit7	OUT3EN,		OUT3 enable
		Bit6	LOUT2EN,	LOUT2 output enable
		Bit5	ROUT2EN,	ROUT2 output enable
		Bit4	0,
		Bit3	RMIXEN,		Right mixer enable
		Bit2	LMIXEN,		Left mixer enable
		Bit1	DACENR,		Right channel DAC enable
		Bit0	DACENL,		Left channel DAC enable
	*/
	usReg = 0;
	if (_OutPath & OUT3_ON)
	{
		usReg |= (1 << 7);
	}
	
	if (_OutPath & OUT4_ON)
	{
		usReg |= (1 << 8);
	}
	
	if (_OutPath & SPK_ON)
	{
		usReg |= ((1 << 6) | (1 << 5));
	}
	
	if (_OutPath != OUT_PATH_OFF)	/* 开启左右声道的混合器 */
	{
		usReg |= ((1 << 3) | (1 << 2));
	}

	if (_InPath & DAC_ON)	/* 启动左右声道的输出DAC */
	{
		usReg |= ((1 << 1) | (1 << 0));
	}
	
	wm8978_WriteReg(3, usReg);	/* 写寄存器 */

	/*
		R44 寄存器 Input ctrl
		Bit8	MBVSEL, 		Microphone Bias Voltage Control   0 = 0.9 * AVDD   1 = 0.6 * AVDD
		Bit7	0
		Bit6	R2_2INPPGA,		Connect R2 pin to right channel input PGA positive terminal
		Bit5	RIN2INPPGA,		Connect RIN pin to right channel input PGA negative terminal
		Bit4	RIP2INPPGA,		Connect RIP pin to right channel input PGA amplifier positive terminal
		Bit3	0
		Bit2	L2_2INPPGA,		Connect L2 pin to left channel input PGA positive terminal
		Bit1	LIN2INPPGA,		Connect LIN pin to left channel input PGA negative terminal
		Bit0	LIP2INPPGA,		Connect LIP pin to left channel input PGA amplifier positive terminal
	*/
	usReg = 0 << 8;
	if (_InPath & LINE_ON)
	{
		if(_InPath & LINE_BOOST_EN)
		{
			if(_InPath & LINE_L2_EN)
			{
				usReg |= (1 << 2);
			}
			else if(_InPath & LINE_R2_EN)
			{
				usReg |= (1 << 6);
			}
			else
			{
				usReg |= (1 << 2);
				usReg |= (1 << 6);
			}
		}
	}
	
	if (_InPath & MIC_RIGHT_ON)
	{
		usReg |= ((1 << 5) | (1 << 4));
	}
	
	if (_InPath & MIC_LEFT_ON)
	{
		usReg |= ((1 << 1) | (1 << 0));
	}
	
	wm8978_WriteReg(44, usReg);	/* 写寄存器 */


	/*
		R14 寄存器 ADC Control
		设置高通滤波器（可选的） WM8978(V4.5_2011).pdf 31 32页,
		Bit8 	HPFEN,	High Pass Filter Enable高通滤波器使能，0表示禁止，1表示使能
		BIt7 	HPFAPP,	Select audio mode or application mode 选择音频模式或应用模式，0表示音频模式，
		Bit6:4	HPFCUT，Application mode cut-off frequency  000-111选择应用模式的截止频率
		Bit3 	ADCOSR,	ADC oversample rate select: 0=64x (lower power) 1=128x (best performance)
		Bit2   	0
		Bit1 	ADC right channel polarity adjust:  0=normal  1=inverted
		Bit0 	ADC left channel polarity adjust:  0=normal 1=inverted
	*/
	if (_InPath & ADC_ON)
	{
		usReg =   (1 << 8) | (1 << 7) | (6 << 4) | (1 << 3);		/* 使能高通滤波器, 设置截至频率327 */
	}
	else
	{
		usReg = 0;
	}
	wm8978_WriteReg(14, usReg);	/* 写寄存器 */

	/* 设置陷波滤波器（notch filter），主要用于抑制话筒声波正反馈，避免啸叫.  暂时关闭
		R27，R28，R29，R30 用于控制限波滤波器，WM8978(V4.5_2011).pdf 33页
		R7的 Bit7 NFEN = 0 表示禁止，1表示使能
	*/
	if (_InPath & ADC_ON)
	{
		usReg = (0 << 7);
		wm8978_WriteReg(27, usReg);	/* 写寄存器 */
		usReg = 0;
		wm8978_WriteReg(28, usReg);	/* 写寄存器,填0，因为已经禁止，所以也可不做 */
		wm8978_WriteReg(29, usReg);	/* 写寄存器,填0，因为已经禁止，所以也可不做 */
		wm8978_WriteReg(30, usReg);	/* 写寄存器,填0，因为已经禁止，所以也可不做 */
	}

	/* 自动增益控制 ALC, R32  - 34  WM8978(V4.5_2011).pdf 36页 */

	{
		usReg = 0;		/* 禁止自动增益控制 */
		wm8978_WriteReg(32, usReg);
		wm8978_WriteReg(33, usReg);
		wm8978_WriteReg(34, usReg);
	}

	/*  R35  ALC Noise Gate Control
		Bit3	NGATEN, Noise gate function enable
		Bit2:0	Noise gate threshold:
	*/
	usReg = ((0 << 3) | (7 << 0));		/* 禁止自动增益控制 */
	wm8978_WriteReg(35, usReg);

	/*
		Mic 输入信道的增益由 PGABOOSTL 和 PGABOOSTR 控制
		Aux 输入信道的输入增益由 AUXL2BOOSTVO[2:0] 和 AUXR2BOOSTVO[2:0] 控制
		Line 输入信道的增益由 LIP2BOOSTVOL[2:0] 和 RIP2BOOSTVOL[2:0] 控制
	*/
	/*	WM8978(V4.5_2011).pdf 29页，R47（左声道），R48（右声道）, MIC 增益控制寄存器
		R47 (R48定义与此相同)
		B8		PGABOOSTL	= 1,   0表示MIC信号直通无增益，1表示MIC信号+20dB增益（通过自举电路）
		B7		= 0， 保留
		B6:4	L2_2BOOSTVOL = x， 0表示禁止，1-7表示增益-12dB ~ +6dB  （可以衰减也可以放大）
		B3		= 0， 保留
		B2:0`	AUXL2BOOSTVOL = x，0表示禁止，1-7表示增益-12dB ~ +6dB  （可以衰减也可以放大）
	*/
	usReg = 0;
	if ((_InPath & MIC_LEFT_ON) || (_InPath & MIC_RIGHT_ON))
	{
		usReg |= (1 << 8);	/* MIC增益取+20dB */
	}
	
	if (_InPath & AUX_ON)
	{
		usReg |= (5 << 0);	/* Aux增益固定取5，用户可以自行调整 */
	}
	
	if (_InPath & LINE_ON)
	{
		if(_InPath & LINE_BOOST_EN)
		{
//			usReg |= (1 << 8);	/* MIC增益取+20dB  会自激 */
		}
		else
		{
			usReg |= (5 << 4);	/* Line增益固定取5，用户可以自行调整 */
		}
	}
	
	wm8978_WriteReg(47, usReg);	/* 写左声道输入增益控制寄存器 */
	wm8978_WriteReg(48, usReg);	/* 写右声道输入增益控制寄存器 */

	
	/*  Line 输入是否需要通过 PGA然后通过boost放大语音 */
	usReg = 0;
	if (_InPath & LINE_ON)
	{
		if(_InPath & LINE_BOOST_EN)
		{
				usReg = 0x0;	//left PGA = 0db
				wm8978_WriteReg(45, usReg);
				wm8978_WriteReg(46, usReg | (1 << 8));
		}
	}
	
	/* 数字ADC音量控制，pdf 35页
		R15 控制左声道ADC音量，R16控制右声道ADC音量
		Bit8 	ADCVU  = 1 时才更新，用于同步更新左右声道的ADC音量
		Bit7:0 	增益选择； 0000 0000 = 静音
						   0000 0001 = -127dB
						   0000 0010 = -126.5dB  （0.5dB 步长）
						   1111 1111 = 0dB  （不衰减）
	*/
	usReg = 0xFF;
	wm8978_WriteReg(15, usReg);	/* 选择0dB，先缓存左声道 */
	usReg = 0x1FF;
	wm8978_WriteReg(16, usReg);	/* 同步更新左右声道 */

	/* 通过 wm8978_SetMicGain 函数设置mic PGA增益 */

	/*	R43 寄存器  AUXR – ROUT2 BEEP Mixer Function
		B8:6 = 0
		B5	 MUTERPGA2INV,	Mute input to INVROUT2 mixer
		B4	 INVROUT2,  Invert ROUT2 output 用于扬声器推挽输出
		B3:1 BEEPVOL = 7;	AUXR input to ROUT2 inverter gain
		B0	 BEEPEN = 1;	Enable AUXR beep input

	*/
	usReg = 0;
	if (_OutPath & SPK_ON)
	{
		usReg |= (1 << 4);	/* ROUT2 反相,Lout2 构成差分 驱动扬声器  */
	}
	
	if((_InPath & AUX_ON)&&(_OutPath & BYPASS_ON))
	{
		usReg |= ((7 << 1) | (1 << 0));
	}
	
	wm8978_WriteReg(43, usReg);

	/* R49  Output ctrl
		B8:7	0
		B6		DACL2RMIX,	Left DAC output to right output mixer
		B5		DACR2LMIX,	Right DAC output to left output
		B4		OUT4BOOST,	0 = OUT4 output gain = -1; DC = AVDD / 2；1 = OUT4 output gain = +1.5；DC = 1.5 x AVDD / 2
		B3		OUT3BOOST,	0 = OUT3 output gain = -1; DC = AVDD / 2；1 = OUT3 output gain = +1.5；DC = 1.5 x AVDD / 2
		B2		SPKBOOST,	0 = Speaker gain = -1;  DC = AVDD / 2 ; 1 = Speaker gain = +1.5; DC = 1.5 x AVDD / 2
		B1		TSDEN,   Thermal Shutdown Enable  扬声器热保护使能（缺省1）
		B0		VROI,	Disabled Outputs to VREF Resistance
	*/
	usReg = (1 << 1);		/* 热保护 */
	if (_InPath & DAC_ON)
	{
		usReg |= ((0 << 6) | (0 << 5)); /*  将左DAC输出混到右 将右DAC混到左 */
	}
	
	if (_OutPath & SPK_ON)
	{
		usReg |=  (0 << 2);	/* SPK 1.5x增益,  热保护使能 */
	}
	
	if (_OutPath & OUT3_ON)
	{
		usReg |=  (0 << 3) ;	/* BOOT3  1.5x增益 */
	}
	
	if (_OutPath & OUT4_ON)
	{
		usReg |=  (0 << 4);	/*   BOOT4  1.5x增益 */
	}
	
	wm8978_WriteReg(49, usReg);

	/*	REG 50    (50是左声道，51是右声道，配置寄存器功能一致) WM8978(V4.5_2011).pdf 56页
		B8:6	AUXLMIXVOL = 111	AUX用于FM收音机信号输入
		B5		AUXL2LMIX = 1		Left Auxilliary input to left channel
		B4:2	BYPLMIXVOL			音量
		B1		BYPL2LMIX = 0;		Left bypass path (from the left channel input boost output) to left output mixer
		B0		DACL2LMIX = 1;		Left DAC output to left output mixer
	*/
	usReg = 0;
	if((_InPath & AUX_ON) && (_OutPath & AUR_BYPASS_ON))
	{
		usReg |= ((7 << 6) | (1 << 5));
		usReg |= (5 << 3);			/* AUXLMIXVOL = 101 = 0db */
	}
	
	if(_OutPath & BYPASS_ON) /* 启动旁路输入什么输出什么 */
	{
		usReg |= ((1 << 1)|(7 << 2));
		usReg |= (5 << 2);			/* BYPLMIXVOL = 101 = 0db */
	}
	
	if (_InPath & DAC_ON)
	{
		usReg |= (1 << 0);
	}
	
	wm8978_WriteReg(50, usReg);
	wm8978_WriteReg(51, usReg);

	/*
		R52	LOUT1 Volume control
		R53	ROUT1 Volume control
	*/
	/* 先更新左声道缓存值 MUTE OUT1*/
	wm8978_WriteReg(52, 1 << 6);

	/* 再同步更新左右声道的音量 MUTE OUT1 */
	wm8978_WriteReg(53, 1 << 6 | 0x100);	/* 0x180表示 在音量为0时再更新，避免调节音量出现的“嘎哒”声 */

	/*
		R54	LOUT2 Volume control
		R55	ROUT2 Volume control
	*/
	/* 先更新左声道缓存值 MUTE OUT2*/
	wm8978_WriteReg(54, 1 << 6);

	/* 再同步更新左右声道的音量 MUTE OUT2*/
	wm8978_WriteReg(55, 1 << 6 | 0x100);	/* 0x180表示 在音量为0时再更新，避免调节音量出现的“嘎哒”声 */
	
	
	/*	R56 寄存器   OUT3 mixer ctrl
		B8:7	0
		B6		OUT3MUTE,  	0 = Output stage outputs OUT3 mixer;  1 = Output stage muted – drives out VMID.
		B5:4	0
		B3		OUT4_2OUT3,	OUT4 mixer output to OUT3 
		B2		BYPL2OUT3,	Left ADC input to OUT3
		B1		LMIX2OUT3,	Left DAC mixer to OUT3
		B0		LDAC2OUT3,	Left DAC output to OUT3
	*/
	usReg = 1 << 6; /* 静止OUT3输出 */
	if (_OutPath & OUT3_ON)
	{
		usReg = 0 << 6;
		if(_OutPath & DAC_OUT_ON)
		{
			usReg |= (1 << 0);
		}		
		if(_InPath & AUX_ON)
		{
			usReg |= (1 << 1);
		}
		if(BYPASS_ON & BYPASS_ON)
		{
			usReg |= (1 << 2);
		}
		if (_OutPath & OUT4_ON)
		{
			usReg |= (1 << 3);
		}
	}
	wm8978_WriteReg(56, usReg);

	/* R57 寄存器		OUT4 (MONO) mixer ctrl
		B8:7	0
		B6		OUT4MUTE,	0 = Output stage outputs OUT4 mixer  1 = Output stage muted – drives outVMID.
		B5		HALFSIG,	0 = OUT4 normal output	1 = OUT4 attenuated by 6dB
		B4		LMIX2OUT4,	Left DAC mixer to OUT4
		B3		LDAC2UT4,		Left DAC to OUT4
		B2		BYPR2OUT4,	Right ADC input to OUT4
		B1		RMIX2OUT4,	Right DAC mixer to OUT4
		B0		RDAC2OUT4,	Right DAC output to OUT4
	*/
	usReg = 1 << 6;
	if (_OutPath & OUT4_ON)
	{
		usReg = 0 << 6;
		
		if(_OutPath & DAC_OUT_ON)
		{
			usReg |= ((1 << 3)|(1 << 0));
		}	
		
		if((_InPath & AUX_ON)||(_InPath & MIXER_OUT_ON))
		{
			usReg |= ((1 << 1)|(1 << 4));
		}
		
		if(_OutPath & BYPASS_ON)
		{
			usReg |= (1 << 2);
		}
		
	}
	wm8978_WriteReg(57, usReg);


	/* 
		R11,  12 寄存器 DAC数字音量
		R11		Left DAC Digital Volume
		R12		Right DAC Digital Volume
	*/
	if (_InPath & DAC_ON)
	{
		wm8978_WriteReg(11, 255);
		wm8978_WriteReg(12, 255 | 0x100);
	}
	else
	{
		wm8978_WriteReg(11, 0);
		wm8978_WriteReg(12, 0 | 0x100);
	}

	/*	R10 寄存器 DAC Control
		B8	0
		B7	0
		B6	SOFTMUTE,	Softmute enable:
		B5	0
		B4	0
		B3	DACOSR128,	DAC oversampling rate: 0=64x (lowest power) 1=128x (best performance)
		B2	AMUTE,		Automute enable
		B1	DACPOLR,	Right DAC output polarity
		B0	DACPOLL,	Left DAC output polarity:
	*/
	if (_InPath & DAC_ON)
	{
		wm8978_WriteReg(10, 1<<3);
	}
}

/**
	* @brief  设置陷波滤波器（notch filter），主要用于抑制话筒声波正反馈，避免啸叫
	* @param  NFA0[13:0] and NFA1[13:0]
	* @retval 无
	*/
void wm8978_NotchFilter(uint16_t _NFA0, uint16_t _NFA1)
{
	uint16_t usReg;

	/*  page 26
		A programmable notch filter is provided. This filter has a variable centre frequency and bandwidth,
		programmable via two coefficients, a0 and a1. a0 and a1 are represented by the register bits
		NFA0[13:0] and NFA1[13:0]. Because these coefficient values require four register writes to setup
		there is an NFU (Notch Filter Update) flag which should be set only when all four registers are setup.
	*/
	usReg = (1 << 7) | (_NFA0 & 0x3F);
	wm8978_WriteReg(27, usReg);	/* 写寄存器 */

	usReg = ((_NFA0 >> 7) & 0x3F);
	wm8978_WriteReg(28, usReg);	/* 写寄存器 */

	usReg = (_NFA1 & 0x3F);
	wm8978_WriteReg(29, usReg);	/* 写寄存器 */

	usReg = (1 << 8) | ((_NFA1 >> 7) & 0x3F);
	wm8978_WriteReg(30, usReg);	/* 写寄存器 */
}


/**
	* @brief  控制WM8978的GPIO1引脚输出0或1
	* @param  _ucValue ：GPIO1输出值，0或1
	* @retval 无
	*/
void wm8978_CtrlGPIO1(uint8_t _ucValue)
{
	uint16_t usRegValue;

	/* R8， pdf 62页 */
	if (_ucValue == 0) /* 输出0 */
	{
		usRegValue = 6; /* B2:0 = 110 */
	}
	else
	{
		usRegValue = 3<<0; /* B2:0 = 111 */
	}
	wm8978_WriteReg(8, usRegValue);
}


/**
	* @brief  复位wm8978，所有的寄存器值恢复到缺省值
	* @param  无
	* @retval 1: 复位成功
	* 				0：复位失败
	*/
uint8_t wm8978_Reset(void)
{
	/* wm8978寄存器缺省值 */
	const uint16_t reg_default[] = {
	0x000, 0x000, 0x000, 0x000, 0x050, 0x000, 0x140, 0x000,
	0x000, 0x000, 0x000, 0x0FF, 0x0FF, 0x000, 0x100, 0x0FF,
	0x0FF, 0x000, 0x12C, 0x02C, 0x02C, 0x02C, 0x02C, 0x000,
	0x032, 0x000, 0x000, 0x000, 0x000, 0x000, 0x000, 0x000,
	0x038, 0x00B, 0x032, 0x000, 0x008, 0x00C, 0x093, 0x0E9,
	0x000, 0x000, 0x000, 0x000, 0x003, 0x010, 0x010, 0x100,
	0x100, 0x002, 0x001, 0x001, 0x039, 0x039, 0x039, 0x039,
	0x001, 0x001
	};
	uint8_t res;
	uint8_t i;

	res=wm8978_WriteReg(0x00, 0);

	for (i = 0; i < sizeof(reg_default) / 2; i++)
	{
		wm8978_RegCash[i] = reg_default[i];
	}
	return res;
}



//void wm8978_ALC_Set()
//{
//	uint16_t value;

//	value = wm8978_ReadReg(2);
//	value &= ~(1<<3|1<<2);
//	wm8978_WriteReg(2, value);
//	
//	/* Set ALC Enable */
//	value = (7 << 0)|(7 << 3)|(3 << 7);
//	wm8978_WriteReg(0x20, value);

//	/* Set ALC Enable */
//	value = (15 << 0)|(8 << 4);
//	wm8978_WriteReg(0x21, value);
//	
//	value = 0x0000;
//	wm8978_WriteReg(0x22, value);	
//	
//	HAL_Delay_Us(1000);

//	value = (0 << 8)|(10 << 0)|(10 << 4);
//	wm8978_WriteReg(0x22, value);	

//	value = wm8978_ReadReg(2);
//	value |= (1<<3|1<<2);
//	wm8978_WriteReg(2, value);
//	
////	value = (1 << 3)|(3 << 0);
////	wm8978_WriteReg(0x23, value);	
//	/* ADC 开启Highpass 解决降低风噪 */
//	
//}
