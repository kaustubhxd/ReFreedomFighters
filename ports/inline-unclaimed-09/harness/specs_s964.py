"""specs_s964.py - area 56 band, claims A27-A28 (0x533b50, 0x533bf0).

this (0x100 random bytes). a (0x100 random bytes): its first dword is a fake vtable whose slot 0xc (A27) or slot 0x8 (A28) is a GUESS
recording stub (thiscall, one argument; returns a random dword). 0x537ed0 and 0x539730 are hooked (recording, thiscall, one argument).
ret='al' (both return 1)."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _make(slot, log):
    def _gen(c):
        e = c.emu
        rng = c.rng

        def hv(e2, r):
            e2.calllog.append((log + 'vt', e2.reg('ecx'), e2.arg32(0)))
            e2.ret(eax=rv, argbytes=4)

        def hh(e2, r):
            e2.calllog.append((log + 'help', e2.reg('ecx'), e2.arg32(0)))
            e2.ret(argbytes=4)

        rv = rng.getrandbits(32)
        vt = e.fake_vtable('vt' + log, 0x40, {slot: hv})
        a = _rnd(c, 0x100)
        e.w32(a, vt)
        this = _rnd(c, 0x100)
        e.hook(0x537ed0 if log == 'A27' else 0x539730, hh)
        return [this, a]
    return _gen


S(0x533b50, 'unnamed 0x533b50 (unknown) thiscall', 'thiscall', None, ret='al', gen=_make(0xc, 'A27'),
  note='unclaimed-56 A27; 0x537ed0 hooked; vt slot 0xc is a GUESS recording stub')
S(0x533bf0, 'unnamed 0x533bf0 (unknown) thiscall', 'thiscall', None, ret='al', gen=_make(0x8, 'A28'),
  note='unclaimed-56 A28; 0x539730 hooked; vt slot 0x8 is a GUESS recording stub')
