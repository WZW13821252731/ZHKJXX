
u8 pu8Data[9];
u32Temperature = (((u32)pu8Data[0])<<4)|(((u32)pu8Data[1]&0xf0)>>4);
u32AccX = (((u32)pu8Data[1]&0x0f)<<16)|((u32)pu8Data[2]<<8)|(u32)pu8Data[3];
u32AccY = ((u32)pu8Data[4]<<12)|((u32)pu8Data[5]<<4)|(((u32)pu8Data[6]&0xf0)>>4);
u32AccZ = (((u32)pu8Data[6]&0x0f)<<16)|((u32)pu8Data[7]<<8)|(u32)pu8Data[8];

0   1   2   3   4   5   6   7   8
00  00  00  00  00  00  00  00  00
73  5f  7b  d8  12  aa  33  e5  67
if (0 != (u32AccY&0x080000))
                {
                    d64RefAccX = (s32)((u32AccY&0xfffff)-0x100000)*3.90625e-3;
                }
                else
                {
                    d64RefAccX = (s32)(u32AccY&0xfffff)*3.90625e-3;
                }
                
                if (0 != (u32AccZ&0x080000))
                {
                    d64RefAccY = (s32)((u32AccZ&0xfffff)-0x100000)*3.90625e-3;
                }
                else
                {
                    d64RefAccY = (s32)(u32AccZ&0xfffff)*3.90625e-3;
                }

                if (0 != (u32AccX&0x080000))
                {
                    d64RefAccZ = (s32)((u32AccX&0xfffff)-0x100000)*3.90625e-3;
                }
                else
                {
                    d64RefAccZ = (s32)(u32AccX&0xfffff)*3.90625e-3;
                }

                d64Temperature = 25.0 - (1852.0 - (s32)u32Temperature) / (-9.05)+g_struOmSysConfig.struSWSensorCfg[u16SensorIndex].fTempOffset;