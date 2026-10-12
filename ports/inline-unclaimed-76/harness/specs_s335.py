"""specs_s335.py - gap band, batch 335: 0x602c50 (bool match, one argument) and 0x608e30 (two arguments).
602c50: the init 0x602bc0 is hooked by address (recorded, returns; it runs SEH code the flat model does not reproduce). The object's first
byte picks whether the init runs; the four dwords at +0xa match the argument half the time.
608e30: the object's +0x1377 is an object whose vtable slot 0x90 is a thiscall stub with seven arguments (recorded, returns a per-run value);
the flag byte at +0x13ee is random."""
from pilot import S


def _rec_init(em, r):
    # 0x602bc0 (thiscall, no arguments; SEH frame not reproduced): recorded by address
    em.calllog.append(('h602bc0', 0, em.reg('ecx'), ()))
    em.ret(eax=0, argbytes=0)


def _gen602c50(c):
    e = c.emu
    rng = c.rng
    e.hook(0x602bc0, _rec_init)
    self_ = e.alloc(0x40, 4)
    e.wbytes(self_, rng.randbytes(0x40))
    e.wbytes(self_, bytes([rng.choice([0, 1])]))
    arg = e.alloc(0x10, 4)
    r = rng.random()
    if r < 0.4:
        e.wbytes(arg, e.rbytes(self_ + 0xa, 16))
    elif r < 0.7:
        # only the last dword differs: the fourth comparison decides
        e.wbytes(arg, e.rbytes(self_ + 0xa, 12) + bytes((rng.getrandbits(8) | 1) if False else (e.rbytes(self_ + 0xa + 12, 1)[0] ^ 0x5a,)) + bytes(3))
    else:
        e.wbytes(arg, rng.randbytes(16))
    return [self_, arg]


def _gen608e30(c):
    e = c.emu
    rng = c.rng
    rv = rng.getrandbits(32)

    def slot90(em, r):
        a = [em.arg32(k) for k in range(7)]
        em.calllog.append(('slot90', 0x90, em.reg('ecx'), tuple(a)))
        em.ret(eax=rv, argbytes=28)

    vt = e.fake_vtable('obj335', 0x100, {0x90: slot90})
    obj = e.alloc(0x40, 4)
    e.w32(obj, vt)
    self_ = e.alloc(0x1400, 4)
    e.wbytes(self_, rng.randbytes(0x1400))
    e.w32(self_ + 0x1377, obj)
    e.wbytes(self_ + 0x13ee, bytes([rng.choice([0, 1])]))
    return [self_, rng.getrandbits(32), rng.getrandbits(32)]


S(0x602c50, 'match602c50 (GUESS)', 'thiscall', None, ret='al', gen=_gen602c50, note='batch335; ret 4; init 0x602bc0 hooked')
S(0x608e30, 'call608e30 (GUESS)', 'thiscall', None, ret='eax', gen=_gen608e30, note='batch335; ret 8; slot 0x90 stubbed')
