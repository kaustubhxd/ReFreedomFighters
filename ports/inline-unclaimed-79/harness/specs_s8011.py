"""specs_s8011.py - unclaimed-79 gap-band group (docs/20-unclaimed-79.md). Each function gets its own random object."""
from pilot import S

def _obj(c, size):
    a = c.emu.alloc(size, 4)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(size)))
    return a

def _vt(c, slot, nargs):
    # this: first dword is its vtable; the slot logs its ecx and stack arguments and pops 4*nargs bytes
    def h(e, r):
        args = [e.arg32(k) for k in range(nargs)]
        e.calllog.append(("slot %x" % slot, e.reg("ecx"), tuple(args)))
        e.ret(eax=0, argbytes=4 * nargs)
    o = _obj(c, 0x40)
    vt = c.emu.fake_vtable("VtS11", 0x40, {slot: h})
    c.emu.w32(o, vt)
    return [o, c.rng.getrandbits(32)]

S(0x499a00, '(GUESS) 0x499a00 vtable forwarder slot 0x24', 'thiscall', None, ret='eax', gen=lambda c: _vt(c, 0x24, 1),
  note='unclaimed-79 gap-band: calls slot +0x24 of this with its argument, returns this')

S(0x499b50, '(GUESS) 0x499b50 vtable forwarder slot 0x1c', 'thiscall', None, ret='eax', gen=lambda c: _vt(c, 0x1c, 1),
  note='unclaimed-79 gap-band: calls slot +0x1c of this with its argument, returns this')

S(0x499b70, '(GUESS) 0x499b70 vtable forwarder slot 0x18', 'thiscall', None, ret='eax', gen=lambda c: _vt(c, 0x18, 1),
  note='unclaimed-79 gap-band: calls slot +0x18 of this with its argument, returns this')

S(0x499b90, '(GUESS) 0x499b90 vtable forwarder slot 0x14', 'thiscall', None, ret='eax', gen=lambda c: _vt(c, 0x14, 1),
  note='unclaimed-79 gap-band: calls slot +0x14 of this with its argument, returns this')

S(0x499bb0, '(GUESS) 0x499bb0 vtable forwarder slot 0x20', 'thiscall', None, ret='eax', gen=lambda c: _vt(c, 0x20, 1),
  note='unclaimed-79 gap-band: calls slot +0x20 of this with its argument, returns this')

S(0x4999c0, '(GUESS) 0x4999c0 vtable forwarder slot 0x18', 'thiscall', None, ret='eax', gen=lambda c: _vt(c, 0x18, 2),
  note='unclaimed-79 gap-band: calls slot +0x18 of this with (argument, 2), returns this')

S(0x4999e0, '(GUESS) 0x4999e0 vtable forwarder slot 0x18', 'thiscall', None, ret='eax', gen=lambda c: _vt(c, 0x18, 2),
  note='unclaimed-79 gap-band: calls slot +0x18 of this with (argument, 4), returns this')

S(0x499a40, '(GUESS) 0x499a40 vtable forwarder slot 0x18', 'thiscall', None, ret='eax', gen=lambda c: _vt(c, 0x18, 2),
  note='unclaimed-79 gap-band: calls slot +0x18 of this with (argument, 0xc), returns this')

S(0x499a60, '(GUESS) 0x499a60 vtable forwarder slot 0x18', 'thiscall', None, ret='eax', gen=lambda c: _vt(c, 0x18, 2),
  note='unclaimed-79 gap-band: calls slot +0x18 of this with (argument, 0x24), returns this')

S(0x499a80, '(GUESS) 0x499a80 vtable forwarder slot 0x18', 'thiscall', None, ret='eax', gen=lambda c: _vt(c, 0x18, 2),
  note='unclaimed-79 gap-band: calls slot +0x18 of this with (argument, 8), returns this')

S(0x499aa0, '(GUESS) 0x499aa0 vtable forwarder slot 0x18', 'thiscall', None, ret='eax', gen=lambda c: _vt(c, 0x18, 2),
  note='unclaimed-79 gap-band: calls slot +0x18 of this with (argument, 1), returns this')

S(0x499bd0, '(GUESS) 0x499bd0 vtable forwarder slot 0x10', 'thiscall', None, ret='eax', gen=lambda c: _vt(c, 0x10, 2),
  note='unclaimed-79 gap-band: calls slot +0x10 of this with (argument, 0xc), returns this')

