// license:BSD-3-Clause
// copyright-holders:MetalliC
/*********************************************************************

	SIXWORD Swift Disc Interface

*********************************************************************/
#ifndef MAME_BUS_SPECTRUM_SIXWORD_H
#define MAME_BUS_SPECTRUM_SIXWORD_H

#include "exp.h"
#include "softlist.h"
#include "imagedev/floppy.h"
#include "machine/wd_fdc.h"
#include "formats/swd_dsk.h"

//**************************************************************************
//  TYPE DEFINITIONS
//**************************************************************************

class spectrum_swiftdisc_device :
	public device_t,
	public device_spectrum_expansion_interface

{
public:
	// construction/destruction
	spectrum_swiftdisc_device(const machine_config &mconfig, const char *tag, device_t *owner, uint32_t clock);

	DECLARE_FLOPPY_FORMATS(floppy_formats);
	DECLARE_INPUT_CHANGED_MEMBER(nmi_button) { m_rombank |= newval << 12; m_slot->nmi_w(newval ? ASSERT_LINE : CLEAR_LINE); };

protected:
	spectrum_swiftdisc_device(const machine_config &mconfig, device_type type, const char *tag, device_t *owner, uint32_t clock);

	// device-level overrides
	virtual void device_start() override;
	virtual void device_reset() override;

	// optional information overrides
	virtual ioport_constructor device_input_ports() const override;

	virtual void device_add_mconfig(machine_config &config) override;
	virtual const tiny_rom_entry *device_rom_region() const override;

	virtual void post_opcode_fetch(offs_t offset) override;
	virtual uint8_t mreq_r(offs_t offset) override;
	virtual void mreq_w(offs_t offset, uint8_t data) override;
	virtual uint8_t iorq_r(offs_t offset) override;
	virtual DECLARE_READ_LINE_MEMBER(romcs) override;

	required_memory_region m_rom;
	required_device<wd_fdc_device_base> m_fdc;
	required_device_array<floppy_connector, 4> m_floppy;
	required_device<spectrum_expansion_slot_device> m_exp;
	required_ioport m_joy;

	int m_romcs;
	u8 m_ram[0x2000];
	u16 m_rombank;
	u8 m_control;
};

class spectrum_swiftdisc2_device :
	public spectrum_swiftdisc_device
{
public:
	// construction/destruction
	spectrum_swiftdisc2_device(const machine_config &mconfig, const char *tag, device_t *owner, uint32_t clock);

protected:
	// device-level overrides
	virtual void device_start() override;
	virtual void device_reset() override;

	virtual const tiny_rom_entry *device_rom_region() const override;

	virtual void post_opcode_fetch(offs_t offset) override;
	virtual uint8_t mreq_r(offs_t offset) override;
	virtual void mreq_w(offs_t offset, uint8_t data) override;
	virtual uint8_t iorq_r(offs_t offset) override;
	virtual void iorq_w(offs_t offset, uint8_t data) override;

	void control_w(uint8_t data);

	int m_rambank;
};



// device type definition
DECLARE_DEVICE_TYPE(SPECTRUM_SWIFTDISC, spectrum_swiftdisc_device)
DECLARE_DEVICE_TYPE(SPECTRUM_SWIFTDISC2, spectrum_swiftdisc2_device)


#endif // MAME_BUS_SPECTRUM_SIXWORD_H
