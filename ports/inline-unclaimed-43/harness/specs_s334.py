"""specs_s334.py - area 71 batch 334: 0x58b6a0, thiscall, no arguments, returns a byte (al). The object's first dword points to
an object whose slot 0x90 receives (this+4 value, &out) and writes a byte to out. The byte is drawn in gen."""
from pilot import S
import engine_stubs as E


def _gen(c):
    r = c.rng
    byte_out = r.getrandbits(8)
    arg = r.getrandbits(32)
    inner = E.zero_obj(c, 0x40)

    def m90(e, a):
        e.wbytes(a[1], bytes([byte_out]))

    slots = {}
    for i in range(0x90 // 4 + 1):
        off = 4 * i

        def h(e, rr, off=off):
            args = [e.arg32(0), e.arg32(1)] if off == 0x90 else []
            e.calllog.append(('ZBYTEOUT', off, e.reg('ecx'), tuple(_nostack(x) for x in args)))
            if off == 0x90:
                m90(e, args)
            e.ret(eax=0, argbytes=8 if off == 0x90 else 0)
        slots[off] = h
    c.emu.w32(inner, c.emu.fake_vtable('ZBYTEOUT', 0x90 // 4 + 1, slots))
    this = E.zero_obj(c, 0x40)
    c.emu.w32(this, inner)
    c.emu.w32(this + 4, arg)
    c.emu.mu.ctl_flush_tb()
    return [this]


def _nostack(x):
    import pe_emu
    return 'stack' if pe_emu.STACK_TOP - pe_emu.STACK_SIZE <= x < pe_emu.STACK_TOP else x


S(0x58b6a0, 'slot 0x90 byte out (unknown) thiscall', 'thiscall', None, ret='al', gen=_gen,
  note='area 71 batch 334 (leaf, residue 10)')
