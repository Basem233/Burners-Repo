#ifndef EEPROM_H
#define EEPROM_H

void EEPROM_Init(void);

u8 EEPROM_ReadByte(u16 addr, u32 *data);
u8 EEPROM_WriteByte(u16 addr, u32 data);
#endif
